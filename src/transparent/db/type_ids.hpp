#ifndef TRANSPARENT_DB_TYPE_IDS_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_DB_TYPE_IDS_HPP_2347diq282837a78273467shj29dfhvghs

namespace transparent
{
namespace db
{

struct type_ids
{
	typedef enum
	{
		UNKNOWN = 0, INT4 = 1, INT8 = 2, REAL = 3, VARCHAR = 4, TEXT = 5
	} value;
};

template<typename T>
struct type_id
{
	const static int value = type_ids::UNKNOWN;
};

template<>
struct type_id<int>
{
	const static int value = type_ids::INT4;
};

template<>
struct type_id<long int>
{
	const static int value = type_ids::INT8;
};

template<>
struct type_id<float>
{
	const static int value = type_ids::REAL;
};

template<>
struct type_id<std::string>
{
	const static int value = type_ids::VARCHAR;
};

template<>
struct type_id<std::vector<char> >
{
	const static int value = type_ids::TEXT;
};

}
}

#endif
