#ifndef TRANSPARENT_AUX_LIST_ITEM_HOLDER_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_AUX_LIST_ITEM_HOLDER_HPP_2347diq282837a78273467shj29dfhvghs

#include "types_n_tags.hpp"

namespace transparent
{
namespace aux
{

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


template<typename PrevT, typename ClassType, typename T>
struct list_item_holder
{
	T value;
	typedef T value_type;
	typedef ClassType class_type;

	void set(const T& v)
	{
		value = v;
	}

	template<typename VisitorT>
	void call_visitor_first(const ClassType& ct, const VisitorT& vt)
	{
		ct.call_visitor<VisitorT>(vt, static_cast<PrevT*>(0));
	}

//	template<typename VisitorT>
//	void call_visitor(ClassType& ct, const VisitorT& vt, const char* name)
//	{
//		ct.call_visitor<VisitorT>(vt, static_cast<PrevT*>(0));
//		vt.visit(hold, name);
//	}

	template<typename VisitorT>
	void call_visitor(const ClassType& ct, const VisitorT& vt, const char* name)
	{
		ct.call_visitor<VisitorT>(vt, static_cast<PrevT*>(0));
		vt.visit(value, name);
	}

};

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
}
}

#endif
