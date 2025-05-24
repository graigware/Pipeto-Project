#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern bool IS_ADMIN;

void trigger_emergency_shutdown(void);

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

#define MARKER "{SHUTDOWN}"

Test(trigger_emergency_shutdown, is_admin) {
    IS_ADMIN = 1;
    redirect_all_stdio();
    trigger_emergency_shutdown();
    char *out = get_stdout_content();
    cr_assert(strstr(out, MARKER) != NULL,
        "flag not display");
}

Test(trigger_emergency_shutdown, is_not_admin) {
    IS_ADMIN = 0;
    redirect_all_stdio();
    trigger_emergency_shutdown();
    char *out = get_stdout_content();
    cr_assert(strstr(out, "You are not authorized to trigger an emergency shutdown.") != NULL,
        "message not display");
}