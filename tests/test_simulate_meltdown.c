#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void simulate_meltdown(void);

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

#define MARKER "{The stone isn't in the pocket anymore ...}"

Test(simulate_meltdown, no_marker) {
    redirect_all_stdio();
    simulate_meltdown();
    char *out = get_stdout_content();
    cr_assert(strstr(out, MARKER) == NULL,
        "La sortie contient le marqueur : %s", MARKER);
}