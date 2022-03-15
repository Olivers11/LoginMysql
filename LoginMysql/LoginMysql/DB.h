#pragma once
using namespace System;
using namespace System::Data;
using namespace std;
using namespace MySql::Data::MySqlClient;

ref class DB
{
private:
	String^ conectionString;
	MySqlConnection^ conn;
public:
	DB();
	bool exist(String^, String^);
	void insert(String^, String^);
};

