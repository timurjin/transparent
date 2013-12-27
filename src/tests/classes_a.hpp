#ifndef TRANSPARENT_TEST_CLASSES_A_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_TEST_CLASSES_A_HPP_2347diq282837a78273467shj29dfhvghs

#include "../transparent/transparent.hpp"

namespace test
{

///////////////////////////////////////////////////////////////////
T_CLASS_B(Demo1)
	Demo1 ()
	{
	}


	T_FIELDS_B
		T_F(double, double_value)
		T_F(int, int_value)
		T_F(long, long_value)
	T_FIELDS_E
T_CLASS_E


/////////////////////////////////////////////////////////////////////////////
T_CLASS_B(Demo2)
	Demo2()
	{
	}

	T_FIELDS_B
		T_F(Demo1, demo1)
		T_F(long, long_value)
	T_FIELDS_E
T_CLASS_E

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
T_CLASS_B(Demo3)
	typedef std::vector<int> ints_t;
	Demo3()
	{
	}

	T_FIELDS_B
		T_F(Demo2, demo2)
		T_F(int,foo)
		T_F(std::string,bar)
		T_F(std::vector<Demo2>, demo2s)
		T_F(std::vector<Demo1>, demo1s)
		T_F(ints_t,ints)
	T_FIELDS_E
T_CLASS_E

}

#endif
