#pragma once

#include <memory>

#ifdef SIMPLECONTAINERSLIB_EXPORTS
#define SIMPLECONTAINERSLIB_API __declspec(dllexport)
#else
#define SIMPLECONTAINERSLIB_API __declspec(dllimport)
#endif

namespace SimpleContainers
{
	class StringListPrivate;

	class SIMPLECONTAINERSLIB_API StringList
	{
	public:
		StringList();
		StringList(StringList&& other);
		StringList(const StringList& other) = delete;

		StringList& operator=(StringList&& other);
		StringList& operator=(const StringList& other) = delete;

		int copy_front(const char* cstr);
		int copy_back(const char* cstr);
		int insert(const char*, unsigned idx);
		int remove(unsigned idx);

		const char* get(unsigned idx) const;
		const char* front() const;
		const char* back() const;

		unsigned size() const;
		unsigned max_length() const;

		virtual ~StringList() {}
	private:
		std::unique_ptr<StringListPrivate> _impl;
	};
}

