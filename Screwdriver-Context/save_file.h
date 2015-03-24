#ifndef SAVE_FILE_HPP
#define SAVE_FILE_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <vector>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

namespace screwdriver
{
	typedef boost::shared_ptr<std::vector<uint8_t>> tm_data_ptr;

	class __declspec(dllexport) save_file
		:private boost::noncopyable
	{
	public:
		save_file(const std::string& folder, const std::string& prefix);
		~save_file(void);
		void start();
		void stop();
		void receive(const tm_data_ptr& data);
	private:
		void split_file();
		std::string get_time_file_name();
		void open_file();
		void close_file();
		void save2file(const tm_data_ptr& data);
	private:
		struct save_file_imp_t;
		boost::shared_ptr<save_file_imp_t> imp_;
	};
}
#endif // SAVE_FILE_HPP

