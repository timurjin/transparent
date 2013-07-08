#ifndef TRANSPARENT_DB_SQL_SQLITE_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_DB_SQL_SQLITE_HPP_2347diq282837a78273467shj29dfhvghs
#include "../db_base.hpp"
namespace transparent
{
namespace db
{

namespace sql
{

struct sqlite: public db_base
{
	explicit sqlite(const std::string& connection_url) :
			connection_url(connection_url)
	{
	}

protected:
	std::string connection_url;

};

}
}
}

#endif
