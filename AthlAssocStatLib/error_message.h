#pragma once

namespace athl_assoc
{
	class ErrorMessage
	{
	public:
		static void init() noexcept
		{
			_instance.reset(new ErrorMessage{});
		}

		static ErrorMessage* instance() noexcept
		{
			if (!_instance)
			{
				init();
			}

			return _instance.get();
		}

		void store_msg(std::string_view msg)
		{
			_error_msg = msg;
		}

		const char* get_msg() const noexcept
		{
			return _error_msg.c_str();
		}

		~ErrorMessage() {}

	private:
		ErrorMessage() = default;

		inline static std::unique_ptr<ErrorMessage> _instance;

		std::string _error_msg;
	};
}

