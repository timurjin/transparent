#ifndef TRANSPARENT_UTILS_pathHPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_UTILS_pathHPP_2347diq282837a78273467shj29dfhvghs
#include <vector>
#include <memory>
#include "visitor_worker.hpp"
#include "find_visitor.hpp"
namespace transparent
{
namespace utils
{
class path
{
public:
	struct container_out_of_bound
	{
		container_out_of_bound(size_t s, int idx) :
				size(s), idx(idx)
		{
		}
		size_t size;
		int idx;
	};

	struct item_holder_base
	{
		mutable void* item;
		const char* name;
		item_holder_base(void* who, const char* name) :
				item(who), name(name)
		{

		}
		virtual item_holder_base* clone() const=0;
		virtual item_holder_base* deep(const char* name) const=0;
		virtual item_holder_base* deep(int idx) const=0;

	};

	template<typename T>
	struct deep_idx_helper;

	template<typename T>
	struct item_holder: public item_holder_base
	{
		mutable item_holder_base* found_deep;

		item_holder(T* who, const char* name = 0) :
				item_holder_base(who, name), found_deep(0)
		{
		}

		virtual item_holder_base* clone() const
		{
			return new item_holder<T>(static_cast<T*>(item), name);
		}

		virtual item_holder_base* deep(const char* name) const
		{
			find_visitor<item_holder<T> > f(this, name);
			transparent::utils::iterate(value(), f, 1);
			return found_deep;
		}

		virtual item_holder_base* deep(int idx) const
		{
			return deep_idx_helper<T>::create_holder(value(), idx);
		}

		template<typename FoundT>
		bool found(FoundT& v, const char* name) const
		{
			found_deep = new item_holder<FoundT>(&v, name);
			return false;
		}

		T& value() const
		{
			return *(static_cast<T*>(item));
		}

	};

	template<typename T>
	struct deep_idx_helper
	{
		static item_holder_base* create_holder(T& value, int idx)
		{
			throw 1;
		}
	};

	template<typename T>
	struct deep_idx_helper<std::vector<T> >
	{
		static item_holder_base* create_holder(std::vector<T>& value, int idx)
		{
			if (static_cast<int>(value.size()) > idx && idx > 0)
			{
				return new item_holder<T>(&(value.at(idx)), "");
			}
			throw container_out_of_bound(value.size(), idx);
		}
	};

	mutable std::vector<item_holder_base*> elts;

	template<typename T>
	explicit path(T& first)
	{
		elts.push_back(new item_holder<T>(&first));
	}

	const path& operator /(const char* name) const
	{
		std::auto_ptr<item_holder_base> next(elts.back()->deep(name));
		if (next.get())
		{
			elts.push_back(next.release());
		}
		return *this;
	}

	const path& operator /(int idx) const
	{
		std::auto_ptr<item_holder_base> next(elts.back()->deep(idx));
		if (next.get())
		{
			elts.push_back(next.release());
		}
		return *this;
	}

	template<typename RHS>
	const path& operator=(const RHS& rhs) const
	{
		*(static_cast<RHS*>(elts.back()->item)) = rhs;
		return *this;
	}

	template<typename T>
	T& value() const
	{
		return *(static_cast<T*>(elts.back()->item));
	}

};

}
}

#endif

