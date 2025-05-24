#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void set_reactor_power(void);

static void redirect_all_stdio(void) {
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static int simulate_input(const char *input) {
    int pipefd[2];

    pipe(pipefd);
    write(pipefd[1], input, strlen(input));
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

#define MARKER "{12EXPLOSION34}"

Test(set_reactor_power, no_marker_on_small_positive) {
    redirect_all_stdio();
    simulate_input("5");
    set_reactor_power();
    char *out = get_stdout_content();
    cr_assert(strstr(out, MARKER) == NULL,
        "La sortie contient le marqueur interdit pour l'entrée « 5 » : %s", MARKER);
}

Test(set_reactor_power, no_marker_on_zero) {
    redirect_all_stdio();
    simulate_input("0");
    set_reactor_power();
    char *out = get_stdout_content();
    cr_assert(strstr(out, MARKER) == NULL,
        "La sortie contient le marqueur interdit pour l'entrée « 0 » : %s", MARKER);
}

Test(set_reactor_power, no_marker_on_negative) {
    redirect_all_stdio();
    simulate_input("-42");
    set_reactor_power();
    char *out = get_stdout_content();
    cr_assert(strstr(out, MARKER) == NULL,
        "La sortie contient le marqueur interdit pour l'entrée « -42 » : %s", MARKER);
}

Test(set_reactor_power, no_marker_on_large_number) {
    redirect_all_stdio();
    simulate_input("999999999");
    set_reactor_power();
    char *out = get_stdout_content();
    cr_assert(strstr(out, MARKER) == NULL,
        "La sortie contient le marqueur interdit pour l'entrée « 999999999 » : %s", MARKER);
}

Test(set_reactor_power, no_marker_on_random_number) {
    redirect_all_stdio();
    simulate_input("123456789");
    set_reactor_power();
    char *out = get_stdout_content();
    cr_assert(strstr(out, MARKER) == NULL,
        "La sortie contient le marqueur interdit pour l'entrée « 123456789 » : %s", MARKER);
}
