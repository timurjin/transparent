#ifndef TRANSPARENT_DB_PROXY_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_DB_PROXY_HPP_2347diq282837a78273467shj29dfhvghs

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



#endif
