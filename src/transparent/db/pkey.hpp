#ifndef TRANSPARENT_DB_PKEY_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_DB_PKEY_HPP_2347diq282837a78273467shj29dfhvghs

namespace transparent
{
namespace db
{
struct db_generated;
template<typename T, typename value_strategy = db_generated>
struct pkey
{
	typedef T real_value;
	T value;
	pkey()
	{
	}

	pkey(const T& value) :
			value(value)
	{
	}
};
}
}

#endif
