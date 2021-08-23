#include "unity.h"
#include "header.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_start(void)
{
  TEST_ASSERT_EQUAL(0, start());
}

void test_checkid(void)
{
  TEST_ASSERT_EQUAL(1, checkid(1));
}

int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_checkid);
    RUN_TEST(test_checkid);
    
    
    
    /* Close the Unity Test Framework */
    return UNITY_END();
}

