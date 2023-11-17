#include "pch.h"
#include "encode.h"

namespace
{
	class EncodeTable
	{
	public:
		using Entry = std::pair<char, char>;

		static char encode_char(char ch) noexcept
		{
			const auto entry = find_entry(ch);
			if (entry == empty_entry)
				return ch;
			else
				return entry.second;
		}

		static char decode_char(char ch) noexcept
		{
			const auto entry = find_entry(ch);
			if (entry == empty_entry)
				return ch;
			else
				return entry.first;
		}
	private:
		static Entry find_entry(char ch) noexcept
		{
			const auto entry_it = std::find_if(encode_table.cbegin(), encode_table.cend(),
				[ch](const auto& entry) { return entry.first == ch or entry.second == ch; });

			if (entry_it == encode_table.cend())
				return empty_entry;
			else
				return *entry_it;
		}

	private:
		static constexpr std::array<Entry, 5> encode_table {
			std::make_pair('a', '1'),
			std::make_pair('e', '2'),
			std::make_pair('i', '3'),
			std::make_pair('o', '4'),
			std::make_pair('u', '5'),
		};

		static constexpr Entry empty_entry{ '\0', '\0' };
	};
}

namespace CodewarsKatas
{
namespace VowelCodeLib
{
	std::string encode(const std::string& str)
	{
		std::string encoded{};
		std::transform(str.cbegin(), str.cend(), std::back_inserter(encoded), &EncodeTable::encode_char);
		return encoded;
	}

	std::string decode(const std::string& str)
	{
		std::string decoded{};
		std::transform(str.cbegin(), str.cend(), std::back_inserter(decoded), &EncodeTable::decode_char);
		return decoded;
	}
}
}
