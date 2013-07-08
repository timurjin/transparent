#ifndef TRANSPARENT_VISITOR_WORKER_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_VISITOR_WORKER_HPP_2347diq282837a78273467shj29dfhvghs

#include "dispatcher.hpp"

namespace transparent
{
namespace utils
{
struct stop_visit_exception
{

};

template<typename VisitorT>
struct visitor_worker
{
	const VisitorT* visitor_real;
	mutable int deep;
	int max_deep;

	explicit visitor_worker(const VisitorT& visitor_real, int max_deep = -1) :
			visitor_real(&visitor_real), deep(0), max_deep(max_deep)
	{
	}

	template<typename T>
	void visit(T& a, const char* name = 0) const
	{
//		if (name != 0)
//			std::cout << name << max_deep << " " << deep << std::endl;
		if (deep >= max_deep && max_deep != -1)
		{
			return;
		}
		if (name != 0)
			deep++;

		typedef typename dispatcher::if_<dispatcher::is_transparent<T>::value, dispatcher::handle_complex<T>, dispatcher::handle_scalar<T> >::type handle_1;
		typedef typename dispatcher::if_<dispatcher::is_container<T>::value, dispatcher::handle_container<T>, handle_1>::type handle_2;
		handle_2::call_visitor(*this, a, name);
		if (name != 0)
			deep--;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////

	template<typename T>
	void container(T& a, const char* name) const
	{
		visitor_real->container_start(a, name);
		for (typename T::iterator i = a.begin(); i != a.end(); i++)
		{
			visit(*i);
		}
		visitor_real->container_end(a, name);
	}

	template<typename T>
	void complex(T& a, const char* name) const
	{
		visitor_real->complex_start(a, name);
		a.call_visitor(*this);
		visitor_real->complex_end(a, name);

	}

	template<typename T>
	void value(T& a, const char* name = 0) const
	{
		visitor_real->value(a, name);
	}

};

template<typename T, typename VisitorT>
void iterate(const T& src, const VisitorT& vt, int max_deep = -1)
{
	try
	{
		visitor_worker<VisitorT> v(vt, max_deep);
		v.visit(const_cast<T&>(src));
	}
	catch (stop_visit_exception&)
	{

	}
}
}
}

#endif

