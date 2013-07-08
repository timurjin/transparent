#ifndef TRANSPARENT_UTILS_FIND_VISITOR_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_UTILS_FIND_VISITOR_HPP_2347diq282837a78273467shj29dfhvghs
#include <string.h>

namespace transparent
{
namespace utils
{
template<typename TT>
struct find_visitor
{
	const TT* who;
	const char* what;

	find_visitor(const TT* who_, const char* what) :
			who(who_), what(what)
	{

	}
	//////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename T>
	void container_start(T& a, const char* name) const
	{
		if (got(name))
		{
			who->found(a, name);
		}
	}

	template<typename T>
	void container_end(T& a, const char* name) const
	{
	}

	template<typename T>
	void complex_start(T& a, const char* name) const
	{

		if (got(name))
		{
			who->found(a, name);
		}
	}

	template<typename T>
	void complex_end(T& a, const char* name) const
	{
	}

	template<typename T>
	void value(T& a, const char* name = 0) const
	{
		if (got(name))
		{
			who->found(a, name);
		}
	}
protected:
	bool got(const char* name) const
	{
		if (name == 0)
			return false;
		return strcmp(what, name) == 0;
	}
};

}
}

#endif

