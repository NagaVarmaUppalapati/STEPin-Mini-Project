#include "unity.h"
#include "voting.h"


/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_display(void)
{
    TEST_ASSERT_EQUAL(0,display());
}
void test_forvoting(void)
{
    TEST_ASSERT_EQUAL(0,forvoting());
}
void test_addcandidates(void)
{
    TEST_ASSERT_EQUAL(0,addcandidates());
}
void test_listofvoters(void)
{
    TEST_ASSERT_EQUAL(0,listofvoters());
}
void test_listofcandidates(void)
{
    TEST_ASSERT_EQUAL(0,listofcandidates());
}
void test_livecount(void)
{
    TEST_ASSERT_EQUAL(0,livecount());
}



int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_display);
    RUN_TEST(test_forvoting);
    RUN_TEST(test_addcandidates);
    RUN_TEST(test_listofvoters);
    RUN_TEST(test_listofcandidates);
    RUN_TEST(test_livecount);
    
    

    

    /* Close the Unity Test Framework */
    return UNITY_END();
}

