#include "pch.h"
#include "encode.h"

namespace
{
	constexpr std::array<std::pair<char, char>, 5> ENCODE_TABLE {
		std::make_pair('a', '1'),
		std::make_pair('e', '2'),
		std::make_pair('i', '3'),
		std::make_pair('o', '4'),
		std::make_pair('u', '5'),
	};

	class Encoder
	{
	public:
		char operator()(char ch)
		{
			const auto entry_it = std::find_if(ENCODE_TABLE.cbegin(), ENCODE_TABLE.cend(),
				[ch](const auto& entry) { return entry.first == ch; });

			if (entry_it == ENCODE_TABLE.cend())
				return ch;
			else
				return entry_it->second;
		}
	};

	class Decoder
	{
	public:
		char operator()(char ch)
		{
			const auto entry_it = std::find_if(ENCODE_TABLE.cbegin(), ENCODE_TABLE.cend(),
				[ch](const auto& entry) { return entry.second == ch; });

			if (entry_it == ENCODE_TABLE.cend())
				return ch;
			else
				return entry_it->first;
		}
	};
}

namespace CodewarsKatas
{
namespace VowelCodeLib
{
	std::string encode(const std::string& str)
	{
		std::string encoded{};
		Encoder encoder;
		std::transform(str.cbegin(), str.cend(), std::back_inserter(encoded), encoder);
		return encoded;
	}

	std::string decode(const std::string& str)
	{
		std::string decoded{};
		Decoder decoder;
		std::transform(str.cbegin(), str.cend(), std::back_inserter(decoded), decoder);
		return decoded;
	}
}
}
