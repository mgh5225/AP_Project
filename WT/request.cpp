#include "request.h"
request::request(Json::Object req){
	socket=new tcp::socket(io_service);
	socket->connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
	boost::system::error_code error;
	boost::asio::write(*socket, boost::asio::buffer(Json::serialize(req)), error);
}

request::~request(){
	delete socket;
}

Json::Object request::answer(){
	boost::system::error_code error;
	boost::asio::streambuf receive_buffer;
	boost::asio::read_until(*socket, receive_buffer, "}\n", error);
	if (error && error != boost::asio::error::eof) {
		Json::Object failed;
		failed["code"] = "receive failed";
		return failed;
	}
	else {
		string data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
		Json::Object ans;
		Json::parse(data,ans);
		return ans;
	}
}
