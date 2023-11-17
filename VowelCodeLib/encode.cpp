#include "pch.h"
#include "encode.h"

namespace
{
	class EncodeTable
	{
	public:
		static char encode_char(char ch) noexcept
		{
			const auto entry_it = std::find_if(encode_table.cbegin(), encode_table.cend(),
						[ch](const auto& entry) { return entry.first == ch; });

			if (entry_it == encode_table.cend())
				return ch;
			else
				return entry_it->second;
		}

		static char decode_char(char ch) noexcept
		{
			const auto entry_it = std::find_if(encode_table.cbegin(), encode_table.cend(),
				[ch](const auto& entry) { return entry.second == ch; });

			if (entry_it == encode_table.cend())
				return ch;
			else
				return entry_it->first;
		}
	private:
		static constexpr std::array<std::pair<char, char>, 5> encode_table {
				std::make_pair('a', '1'),
				std::make_pair('e', '2'),
				std::make_pair('i', '3'),
				std::make_pair('o', '4'),
				std::make_pair('u', '5'),
			};
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
