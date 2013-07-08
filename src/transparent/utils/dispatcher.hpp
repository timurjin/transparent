#ifndef TRANSPARENT_UTILS_DISPATCHER_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_UTILS_DISPATCHER_HPP_2347diq282837a78273467shj29dfhvghs


namespace transparent
{
namespace utils
{
namespace dispatcher
{

template<class T>
struct is_transparent
{
private:
	template<class U> static ::transparent::aux::no_tag check_it(...);
	template<class U> static ::transparent::aux::yes_tag check_it(typename U::object_is_transparent* = 0);
public:
	static const bool value = sizeof(check_it<T>(0)) == sizeof(::transparent::aux::yes_tag);
};

template<class T>
struct scalar_with_iterator
{
	static const bool value = false;
};

template<>
struct scalar_with_iterator<std::string>
{
	static const bool value = true;
};

template<class T>
struct is_container
{
private:
	// Checks what T has some const_iterator and must be treated as a container object,
	// std::string also has const_iterator but we do not wont to iterate throught it.
	// So where is an specialisation of scalar_with_iterator<std::string> which helps as to
	// avoid treating std::string as an iterable container

	// One can create specialization for any other type with const_iterator in it no thread it as
	// a scalar type

	template<class U> static ::transparent::aux::no_tag check_it(...);
	template<class U> static ::transparent::aux::yes_tag check_it(typename U::const_iterator* = 0);
public:
	static const bool value = sizeof(check_it<T>(0)) == sizeof(::transparent::aux::yes_tag) && !scalar_with_iterator<T>::value;
};

template<class T>
struct is_type_holder
{
private:
	template<class U> static ::transparent::aux::no_tag check_it(...);
	template<class U> static ::transparent::aux::yes_tag check_it(typename U::type_holder_tag* = 0);
public:
	static const bool value = sizeof(check_it<T>(0)) == sizeof(::transparent::aux::yes_tag);
};

template<bool T, typename TrueT, typename FalseT>
struct if_
{
	typedef FalseT type;
};

template<typename TrueT, typename FalseT>
struct if_<true, TrueT, FalseT>
{
	typedef TrueT type;
};

template<typename HolderT>
struct handle_complex_holder
{
	template<typename VT>
	static void call_visitor(const VT& vt, HolderT& hold, const char* name)
	{
		vt.complex_holder(hold, name);
	}
};

template<typename HolderT>
struct handle_container_holder
{
	template<typename VT>
	static void call_visitor(const VT& vt, HolderT& hold, const char* name)
	{
		vt.container_holder(hold, name);
	}

};

template<typename HolderT>
struct handle_scalar_holder
{
	template<typename VT>
	static void call_visitor(const VT& vt, HolderT& hold, const char* name)
	{
		vt.value_holder(hold, name);
	}
};

template<typename T>
struct handle_complex
{
	template<typename VT>
	static void call_visitor(const VT& vt, T& element, const char* name)
	{
		vt.complex(element, name);
	}
};

template<typename T>
struct handle_container
{
	template<typename VT>
	static void call_visitor(const VT& vt, T& element, const char* name)
	{
		vt.container(element, name);
	}

};

template<typename T>
struct handle_scalar
{
	template<typename VT>
	static void call_visitor(const VT& vt, T& element, const char* name)
	{
		vt.value(element, name);
	}
};

template<typename HolderT>
struct handle_type_holder
{
	template<typename VT>
	static void call_visitor(const VT& vt, HolderT& holder, const char* name)
	{
		vt.visit_holder(holder, name);
	}
};

template<typename T>
struct handle_non_type_holder
{
	template<typename VT>
	static void call_visitor(const VT& vt, T& element, const char* name)
	{
		vt.visit_element(element, name);
	}
};

}

}
}

#endif

