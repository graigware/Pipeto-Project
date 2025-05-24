#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern bool IS_ADMIN;

// Déclaration de la fonction testée
void activate_emergency_protocols(void);

// Configure stdout et stderr non bufferisés, redirige pour capture
static void redirect_all_stdio(void) {
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static int simulate_input(const char *input) {
    int pipefd[2];

    pipe(pipefd);
    write(pipefd[1], "input", strlen(input));
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    return 0;
}

static char *get_stdout_content(void)
{
    static char buffer[1024];
    FILE *fp = cr_get_redirected_stdout();

    memset(buffer, 0, sizeof(buffer));
    rewind(fp);
    fread(buffer, sizeof(char), sizeof(buffer) - 1, fp);
    fflush(stdout);
    return buffer;
}

Test(activate_emergency_protocols, random_input, .init = redirect_all_stdio) {
    char input[] = "randompass\n";

    simulate_input(input);
    activate_emergency_protocols();

    char *output = get_stdout_content();
    // Vérifie la présence de l'invite
    cr_assert_not_null(strstr(output, "Enter emergency password:"),
        "L'invite n'a pas été affichée pour mot de passe incorrect");
    // Vérifie que le protocole ne s'active pas
    cr_assert_null(strstr(output, "Emergency protocols activated"),
        "Le protocole ne doit pas s'activer pour un mot de passe incorrect");
}

Test(activate_emergency_protocols, correct_admin, .init = redirect_all_stdio) {
    char input[] = "admin123\n";
    IS_ADMIN = 1;
    simulate_input(input);
    activate_emergency_protocols();

    char *output = get_stdout_content();
    // Vérifie l'invite
    cr_assert_not_null(strstr(output, "Enter emergency password:"),
        "L'invite n'a pas été affichée pour bon mot de passe");
    // Vérifie le message d'activation pour admin
    cr_assert_null(strstr(output, "{Emergency protocols activated, you are now admin !}"),
        "Le message d'activation n'a pas été affiché pour le mot de passe admin");
}