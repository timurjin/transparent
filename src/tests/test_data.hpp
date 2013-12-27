#ifndef TRANSPARENT_TEST_DATA_A_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_TEST_DATA_A_HPP_2347diq282837a78273467shj29dfhvghs

#include "../transparent/transparent.hpp"
#include "./classes_a.hpp"

namespace test
{
inline Demo3 test_data_1(int size_of_2, int size_of_3)
{
	Demo3 ret;
	ret.foo(42);
	ret.bar("Forty too is a good value to test");

	ret.demo2s().resize(size_of_2);

	for (size_t i = 0; i < ret.demo2s().size(); i++)
	{
		ret.demo2s()[i].long_value(4242424242);
		ret.demo2s()[i].demo1().double_value(0.42);
		ret.demo2s()[i].demo1().int_value(42);
		ret.demo2s()[i].demo1().long_value(4242424242);

	}
	ret.demo1s().resize(size_of_3);

	for (size_t i = 0; i < ret.demo1s().size(); i++)
	{
		ret.demo1s()[i].double_value(0.42);
		ret.demo1s()[i].int_value(42);
		ret.demo1s()[i].long_value(4242424242);
	}

	ret.ints().resize(123);
	for (size_t i = 0; i < ret.ints().size(); ++i)
	{
		ret.ints()[i] = i;
	}
	return ret;
}

}
#endif
