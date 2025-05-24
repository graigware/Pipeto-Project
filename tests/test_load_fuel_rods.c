// tests/test_load_fuel_rods_strstr.c

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <unistd.h>
#include "pipeto.patch.h"

/* Chaîne secrète à rechercher */
static const char *SECRET = "{The secret stone is here !}";

/* Fixture : capture stdout et injecte une ligne dans stdin */

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

Test(load_fuel_rods, leaks_on_zero_input, .init = redirect_all_stdio) {
    simulate_input("0\n");
    load_fuel_rods();
    char *output = get_stdout_content();
    /* On VEUT détecter le secret => échoue si strstr renvoie NULL */
    cr_assert_null(
        strstr(output, SECRET),
        "Expected secret to be printed on zero input, but it was not.\nFull output:\n%s",
        output
    );
}

Test(load_fuel_rods, leaks_on_negative_input, .init = redirect_all_stdio) {
    simulate_input("-1\n");
    load_fuel_rods();
    char *output = get_stdout_content();
    cr_assert_null(
        strstr(output, SECRET),
        "Expected secret to be printed on negative input, but it was not.\nFull output:\n%s",
        output
    );
}

Test(load_fuel_rods, leaks_on_2_input, .init = redirect_all_stdio) {
    simulate_input("2\n");
    load_fuel_rods();
    char *output = get_stdout_content();
    cr_assert_null(
        strstr(output, SECRET),
        "Expected secret to be printed on negative input, but it was not.\nFull output:\n%s",
        output
    );
}
