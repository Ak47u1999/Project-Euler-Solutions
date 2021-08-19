#include <stdio.h>
#include <gmp.h>

int main(int argc, char** argv) {
    mpz_t n;

    mpz_init_set_str(n, "1234567890", 0);

    gmp_printf("%Zd\n", n);

    mpz_clear(n);

    return 0;
}
