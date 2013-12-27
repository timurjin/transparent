#include <iostream>
#include <typeinfo>
#include <vector>
#include <time.h>

#include "../transparent/transparent.hpp"
#include "../transparent/formats/json/json_write.hpp"

#include "../transparent/db.hpp"

#include "classes_a.hpp"
#include "test_data.hpp"

using namespace std;
using namespace transparent;

T_CLASS_B(some_response)
	T_FIELDS_B
	   T_F(std::string, value)
	T_FIELDS_E
T_CLASS_E

int main()
{

	some_response res;
	res.value("Some string value");

	cout << transparent::formats::json::write(res);

	/////////////////////////////////////////////////////////
	test::Demo3 demo3 = test::test_data_1(4, 8);

	time_t start_all, finish_all;
	start_all = time(0);

	size_t times = 100000;
	std::string str;

	for (size_t i = 0; i < times; i++)
	{
		transparent::formats::json::write(demo3, &str);
	}

	finish_all = time(0);
	double duration = difftime(finish_all, start_all);
	std::cout << (double) (times) / duration << " writes per secod..." << std::endl;
//	transparent::tools::json_read(str, &demo3);

}
