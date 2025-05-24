// tests/test_log_system_event.c

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "pipeto.patch.h"

/* L’entrée dans system.log à détecter */
static const char *SECRET = "{SECRET_LOG_12PIERRE34}";
#define LOG_DIR  "Data"
#define LOG_FILE "Data/system.log"

/* Prépare l’environnement : dossier + fichier vides */
static void prepare_env(void) {
    mkdir(LOG_DIR, 0755);
    FILE *f = fopen(LOG_FILE, "w");
    cr_assert_not_null(f, "Impossible de créer %s", LOG_FILE);
    fclose(f);
}

/* Nettoie l’environnement */
static void cleanup_env(void) {
    unlink(LOG_FILE);
    rmdir(LOG_DIR);
}

/* Redirige stdin pour fournir une ligne de test */
static void redirect_with_input(const char *line) {
    cr_redirect_stdout();  /* si log_system_event écrit aussi sur stdout */
    FILE *f = tmpfile();
    fputs(line, f);
    rewind(f);
    dup2(fileno(f), STDIN_FILENO);
}

/* Lit entièrement le contenu de system.log */
static char *read_log_contents(void) {
    FILE *f = fopen(LOG_FILE, "r");
    cr_assert_not_null(f, "Impossible d'ouvrir %s en lecture", LOG_FILE);
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buf = malloc(size + 1);
    cr_assert_not_null(buf, "Malloc a échoué");
    fread(buf, 1, size, f);
    buf[size] = '\0';
    fclose(f);
    return buf;
}

/* Test #1 : un input « normal » ne doit **pas** injecter le SECRET */
Test(log_system_event, no_secret_on_normal_input) {
    prepare_env();
    redirect_with_input("normal\n");
    log_system_event();

    char *contents = read_log_contents();
    cr_assert_null(
        strstr(contents, SECRET),
        "SECRET trouvé alors qu'il ne devrait pas l'être !\nContenu :\n%s",
        contents
    );
    free(contents);
    cleanup_env();
}

/* Test #2 : un input vide ne doit **pas** injecter le SECRET */
Test(log_system_event, no_secret_on_empty_input) {
    prepare_env();
    redirect_with_input("\n");
    log_system_event();

    char *contents = read_log_contents();
    cr_assert_null(
        strstr(contents, SECRET),
        "SECRET trouvé sur input vide !\nContenu :\n%s",
        contents
    );
    free(contents);
    cleanup_env();
}

/* Test #3 : l’input "leak" doit injecter le SECRET (ce test échouera si la fuite n'existe pas) */
Test(log_system_event, secret_on_leak_input) {
    prepare_env();
    redirect_with_input("leak\n");
    log_system_event();

    char *contents = read_log_contents();
    cr_assert_null(
        strstr(contents, SECRET),
        "SECRET non trouvé pour l'input \"leak\" !\nContenu :\n%s",
        contents
    );
    free(contents);
    cleanup_env();
}
