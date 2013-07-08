#ifndef TRANSPARENT_DB_PROXY_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_DB_PROXY_HPP_2347diq282837a78273467shj29dfhvghs
#include "db_base.hpp"

namespace transparent
{
namespace db
{

struct proxy_flags
{
	typedef enum
	{
		create_implicit = 0, create_explicit = 1
	} value;
};
template<typename T>
struct proxy
{
	mutable db_base* db_;
	mutable T* value;
	mutable bool dirty;
	mutable int flags;

	explicit proxy(db_base& db) :
			db_(&db), value(0), dirty(true), flags(proxy_flags::create_explicit)
	{
	}
	explicit proxy(db_base& db, const T& v) :
			db_(&db), value(new T(v)), dirty(true)
	{

	}
	~proxy()
	{
		delete value;
	}

	T* operator->() const
	{
		return &get_();
	}

	void load() const
	{

	}

	void create() const
	{

		//db_->create(*value);
	}

	void del() const
	{

	}

	void update() const
	{

	}

protected:
	T& get_() const
	{
		if (value == 0)
		{
			value = new T();
		}
		return *value;
	}
};

}
}

#endif
