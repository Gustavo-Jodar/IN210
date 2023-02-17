#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"
#include <string.h>
#include "ratp.h"

/* A test case that does nothing and succeeds. */


static int setup(void **state) {
    (void) state;
    printf("setUp: preparer le test\n");
 return 0;
}

static int teardown(void **state) {
    (void) state;
    printf("tearDown: nettoyer le test\n");
    return 0;
}

static void null_test_success(void **state) {
    (void) state;
}

void recupAge(int *ageLimit){
    function_called();
    *ageLimit = (int)mock();
}

static void test_inf_12(void **state) {
    //will_return empilha os valores a serem colocados em limit_age
    will_return(recupAge, 12);
    will_return(recupAge, 11);
    
    //expect_function_calls testa quantas vezes reculAge devem ser chamados
    expect_function_calls(recupAge, 2);

    //teste 1
    float price = computePrice(12);
    assert_float_equal(0.75, price, 0.00001);
    //teste 2
    price = computePrice(11);
    assert_float_equal(0.75, price, 0.00001);

}

int main(void) {
    
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test_setup_teardown(test_inf_12, setup, teardown)
    };
    
    
    cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests_name("toto", tests, NULL, NULL);
}
