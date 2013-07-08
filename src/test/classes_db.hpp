#ifndef TRANSPARENT_TEST_CLASSES_DB_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_TEST_CLASSES_DB_HPP_2347diq282837a78273467shj29dfhvghs

#include "../transparent/transparent.hpp"
#include "../transparent/db.hpp"

namespace test
{
namespace db
{
T_CLASS_TR_B(Demo0db,transparent::db::traits)
	Demo0db ()
	{
		double_value(5.1);
		int_value(10);
		long_value(20);
	}

	T_FIELDS_B
		T_F(transparent::db::pkey<long int>, idx)
		T_F(double, double_value)
		T_F(int, int_value)
		T_F(long, long_value)
	T_FIELDS_E
T_CLASS_E

///////////////////////////////////////////////////////////////////
T_CLASS_TR_B(Demo1db,transparent::db::traits)
	Demo1db ()
	{
		double_value(5.1);
		int_value(10);
		long_value(20);
	}

	T_FIELDS_B
		T_F(transparent::db::pkey<long int>, idx)
		T_F(double, double_value)
		T_F(int, int_value)
		T_F(long, long_value)
		T_F(long int, demo0idx)
		T_F(std::string, demo_str)
		T_L(transparent::db::rel::one_2_one , Demo1db::demo0idx, Demo0db::idx, demo0)
	T_FIELDS_E
T_CLASS_E

}

}

#endif
