#include "pch.h"

#include "string_list.h"

namespace SimpleContainers
{
	class StringListPrivate
	{
	public:
		StringListPrivate();
		StringListPrivate(StringListPrivate&& other);
		StringListPrivate(const StringListPrivate& other) = delete;

		StringListPrivate& operator=(StringListPrivate&& other);
		StringListPrivate& operator=(const StringListPrivate& other) = delete;

		int copy_front(const char* cstr);
		int copy_back(const char* cstr);
		int insert(const char*, unsigned idx);
		int remove(unsigned idx);

		const char* get(unsigned idx) const;
		const char* front() const;
		const char* back() const;

		unsigned size() const;
		unsigned max_length() const;
	private:
	};
	
}
