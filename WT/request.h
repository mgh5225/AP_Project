#pragma once
#include <iostream>
#include <boost/asio.hpp>
#include <Wt/Json/Object.h>
#include <Wt/Json/Parser.h>
#include <Wt/Json/Serializer.h>
#include <string>
using namespace boost::asio;
using namespace std;
using namespace Wt;
using ip::tcp;
class request{
	boost::asio::io_service io_service;
	tcp::socket* socket;
public:
	request(Json::Object req);
	~request();
	Json::Object answer();
};

