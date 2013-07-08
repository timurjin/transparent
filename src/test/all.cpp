#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

#include "../transparent/transparent.hpp"
#include "../transparent/tools/json.hpp"
#include "../transparent/utils/path.hpp"

#include "../transparent/db.hpp"
#include "../transparent/db/sql/sqlite.hpp"

#include "classes_a.hpp"
#include "classes_db.hpp"

using namespace transparent;

void json()
{
	test::Demo3 demo3;
	std::string str;
	transparent::tools::json_write(demo3, &str);

	std::cout << str << std::endl;
}

struct demo_write_visitor
{
	template<typename T>
	void container_start(T& a, const char* name) const
	{
	}

	template<typename T>
	void container_end(T& a, const char* name) const
	{
	}

	template<typename T>
	void complex_start(T& a, const char* name) const
	{
	}

	template<typename T>
	void complex_end(T& a, const char* name) const
	{
	}

	template<typename T>
	void value(T& a, const char* name = 0) const
	{
	}

	void value(int& a, const char* name = 0) const
	{
		a = 24;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////

};

void iterate_and_write()
{
	test::Demo3 demo3;
	demo_write_visitor v;
	transparent::utils::iterate(demo3, v);
	if (demo3.foo() != 24)
		std::cout << __FILE__ << ":" << __LINE__ << " is BAD!!!";

	if (demo3.foo_holder.value != 24)
		std::cout << __FILE__ << ":" << __LINE__ << " is BAD!!!";

}

void path_check()
{
	test::Demo3 demo3;
	std::cout << demo3.demo2().long_value() << "  " << (transparent::utils::path(demo3) / "demo2" / "long_value").value<long>() << std::endl;
	transparent::utils::path(demo3) / "demo2" / "long_value" = 42;
	std::cout << demo3.demo2().long_value() << "  " << (transparent::utils::path(demo3) / "demo2" / "long_value").value<long>() << std::endl;

	std::cout << demo3.bar() << "  " << (transparent::utils::path(demo3) / "bar").value<std::string>() << std::endl;
	transparent::utils::path(demo3) / "bar" = std::string("42 is new value");
	std::cout << demo3.bar() << "  " << (transparent::utils::path(demo3) / "bar").value<std::string>() << std::endl;

	std::cout << demo3.demo2().demo1().int_value() << "  " << (transparent::utils::path(demo3) / "demo2" / "demo1" / "int_value").value<int>() << std::endl;
	transparent::utils::path(demo3) / "demo2" / "demo1" / "int_value" = 30; //
	std::cout << demo3.demo2().demo1().int_value() << "  " << (transparent::utils::path(demo3) / "demo2" / "demo1" / "int_value").value<int>() << std::endl;

	std::cout << demo3.demo2s().at(2).demo1().int_value() << "  " << (transparent::utils::path(demo3) / "demo2s" / 2 / "demo1" / "int_value").value<int>() << std::endl;
	transparent::utils::path(demo3) / "demo2s" / 2 / "demo1" / "int_value" = 30; //
	std::cout << demo3.demo2s().at(2).demo1().int_value() << "  " << (transparent::utils::path(demo3) / "demo2s" / 2 / "demo1" / "int_value").value<int>() << std::endl;

}

struct sql_field_info
{
	const char* name;
	void* value;
	int type;
};

void dao_element(transparent::db::db_base& db)
{
	transparent::db::proxy<test::db::Demo1db> demo1(db);

	demo1->long_value(12);

	demo1.create();

	//	d1->demo0()->long_value();
	demo1.load();
	demo1.update();
	demo1.del();
}

void db_check()
{
//	transparent::db::sql::sqlite db("sqlite://user:password@127.0.0.1:5433/dbname1");
	transparent::db::sql::sqlite db("sqlite://user:password@file://./dbname1.db");
	dao_element(db);
}

int main()
{

//	json();
//	iterate_and_write();
//	path_check();

	db_check();

	std::cout << "Finished!\n";
	return 0;
}
