#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern bool IS_ADMIN;

void unlock_secret_mode(void);

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

#define MARKER "{ADMIN4242}"

Test(unlock_secret_mode, is_admin) {
    IS_ADMIN = 1;
    redirect_all_stdio();
    unlock_secret_mode();
    char *out = get_stdout_content();
    cr_assert(strstr(out, MARKER) != NULL,
        "flag not display");
}

Test(unlock_secret_mode, is_not_admin) {
    IS_ADMIN = 0;
    redirect_all_stdio();
    unlock_secret_mode();
    char *out = get_stdout_content();
    cr_assert(strstr(out, "Access denied. You do not have the required privileges.") != NULL,
        "message not display");
}