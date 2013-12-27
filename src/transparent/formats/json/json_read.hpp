#ifndef TRANSPARENT_TOOLS_JSON_READ_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_TOOLS_JSON_READ_HPP_2347diq282837a78273467shj29dfhvghs
#include <ostream>
#include <sstream>
#include "../../transparent.hpp"

/*
 *
 *
 *  Right now it is a copy of a json
 *
 */
namespace transparent
{
namespace formats
{
namespace json
{
struct json_reader_visitor
{
	mutable int c;
	mutable bool is_last_element;
	mutable std::string spaces;

	std::ostream* to;

	json_reader_visitor(std::ostream* to) :
			c(0), is_last_element(false), to(to)
	{
	}

//////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename T>
	void container_start(T& a, const char* name) const
	{
		if (name != 0)
		{
			(*to) << spaces << "\"" << name << "\" : ";
		}
		*to << "[" << std::endl;
		spaces.append("   ");

	}

	template<typename T>
	void container_end(T& a, const char* name) const
	{
		spaces.erase(spaces.size() - 3, 3);
		(*to) << spaces << "]";
		if (!is_last_element)
		{
			(*to) << ",";
		}

		(*to) << std::endl;
	}

	template<typename T>
	void complex_start(T& a, const char* name) const
	{
		c++;
		(*to) << spaces;
		if (name != 0)
		{
			(*to) << "\"" << name << "\" : ";
		}
		(*to) << "{" << std::endl;

		spaces.append("   ");
	}

	template<typename T>
	void complex_end(T& a, const char* name) const
	{
		spaces.erase(spaces.size() - 3, 3);
		(*to) << spaces << "}";
		if (!is_last_element)
		{
			(*to) << ",";
		}
		(*to) << std::endl;
	}

	template<typename T>
	void value(T& a, const char* name = 0) const
	{
		c++;
		if (name != 0)
		{
			(*to) << spaces << "\"" << name << "\" : \"" << a << "\"";
		}
		else
		{
			(*to) << spaces << "\"" << a << "\"";
		}
		if (!is_last_element)
		{
			(*to) << ",";
		}
		(*to) << std::endl;
	}

};

template<typename T>
void read(const T& src, std::ostream* dst)
{
	transparent::formats::json::json_reader_visitor v(dst);
	transparent::utils::iterate(src, v);
}

template<typename T>
std::string read(const T& src)
{
	std::stringstream dst;
	transparent::formats::json::json_reader_visitor v(dst);
	transparent::utils::iterate(src, v);
	return dst.str();
}

template<typename T>
void read(const T& src, std::string* dst)
{
	std::stringstream dst_;
	transparent::formats::json::json_reader_visitor v(&dst_);
	transparent::utils::iterate(src, v);

	*dst = dst_.str();
}

}
}
}
#endif
