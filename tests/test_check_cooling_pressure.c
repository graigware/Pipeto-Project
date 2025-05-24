// tests/test_check_cooling_pressure.c
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "pipeto.patch.h"  // prototype de check_cooling_pressure()

static void redirect_all_stdio(void) {
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    cr_redirect_stdout();
    cr_redirect_stderr();
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

Test(check_cooling_pressure, does_not_disclose_sensitive_data) {
    redirect_all_stdio();
    check_cooling_pressure();
    char *output = get_stdout_content();
    cr_assert(strstr(output, "{Sensitive Data}") == NULL,
              "La sortie contient des données sensibles : %s", output);
}
