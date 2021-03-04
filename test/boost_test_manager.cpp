#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

// initialization function:
bool init_unit_test() {
    return true;
}

// entry point:
int main(int argc, char *argv[]) {
    return boost::unit_test::unit_test_main(&init_unit_test, argc, argv);
}