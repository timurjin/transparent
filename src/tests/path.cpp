#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

#include "../transparent/transparent.hpp"
#include "../transparent/utils/path.hpp"

#include "classes_a.hpp"
#include "classes_db.hpp"

using namespace transparent;


void path_check()
{
	test::Demo3 demo3;
	demo3.demo2().long_value(10);

	std::cout << demo3.demo2().long_value() << "  " << (transparent::utils::path(demo3) / "demo2" / "long_value").value<long>() << std::endl;
	transparent::utils::path(demo3) / "demo2" / "long_value" = 42;
	std::cout << demo3.demo2().long_value() << "  " << (transparent::utils::path(demo3) / "demo2" / "long_value").value<long>() << std::endl;

	std::cout << demo3.bar() << "  " << (transparent::utils::path(demo3) / "bar").value<std::string>() << std::endl;
	transparent::utils::path(demo3) / "bar" = std::string("42 is new value");
	std::cout << demo3.bar() << "  " << (transparent::utils::path(demo3) / "bar").value<std::string>() << std::endl;

	demo3.demo2().demo1().int_value(10);
	std::cout << demo3.demo2().demo1().int_value() << "  " << (transparent::utils::path(demo3) / "demo2" / "demo1" / "int_value").value<int>() << std::endl;
	transparent::utils::path(demo3) / "demo2" / "demo1" / "int_value" = 30; //
	std::cout << demo3.demo2().demo1().int_value() << "  " << (transparent::utils::path(demo3) / "demo2" / "demo1" / "int_value").value<int>() << std::endl;

	demo3.demo2s().resize(4);
	demo3.demo2s().at(2).demo1().int_value(10);
	std::cout << demo3.demo2s().at(2).demo1().int_value() << "  " << (transparent::utils::path(demo3) / "demo2s" / 2 / "demo1" / "int_value").value<int>() << std::endl;
	transparent::utils::path(demo3) / "demo2s" / 2 / "demo1" / "int_value" = 30; //
	std::cout << demo3.demo2s().at(2).demo1().int_value() << "  " << (transparent::utils::path(demo3) / "demo2s" / 2 / "demo1" / "int_value").value<int>() << std::endl;

}


int main()
{

	path_check();

	std::cout << "Finished!\n";
	return 0;
}
