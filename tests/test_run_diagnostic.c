#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern bool IS_ADMIN;

void run_diagnostic(void);

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

Test(run_diagnostic, normal_input, .init = redirect_all_stdio) {
    char input[] = "normal\n";

    simulate_input(input);
    run_diagnostic();
    char *output = get_stdout_content();

    cr_assert_null(strstr(output, "{SECRET DIAGNOSTIC KEY}"),
        "La secret key est afficher");
}

Test(run_diagnostic, debug_input_without_admin, .init = redirect_all_stdio) {
    char input[] = "debug\n";

    simulate_input(input);
    run_diagnostic();
    char *output = get_stdout_content();

    cr_assert_null(strstr(output, "{SECRET DIAGNOSTIC KEY}"),
        "La secret key est afficher");
}

Test(run_diagnostic, advanced_input, .init = redirect_all_stdio) {
    char input[] = "advanced\n";

    simulate_input(input);
    run_diagnostic();
    char *output = get_stdout_content();

    cr_assert_null(strstr(output, "{SECRET DIAGNOSTIC KEY}"),
        "La secret key est afficher");
}
