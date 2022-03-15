#include "pch.h"
#include "DB.h"
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

DB::DB() {
	this->conectionString = "datasource=localhost; username=root; password='daniela11'; database=login;";
	this->conn = gcnew MySqlConnection(this->conectionString);
}

bool DB::exist(String^ user, String^ pass) {
	String^ query = "select * from persona where username='" + user + "' and pass='" + pass + "'";
	MySqlCommand^ cursor = gcnew MySqlCommand(query, this->conn);
	MySqlDataReader^ dataReader;
	try {
		this->conn->Open();
		dataReader = cursor->ExecuteReader();
		return(dataReader->Read()) ? true : false;
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message);
	}
	return false;
}

void DB::insert(String^ user, String^ pass) {
	String^ query = "insert into persona(username, pass) values('" + user + "', '" + pass + "')";
	this->conn->Open();
	MySqlCommand^ cursor = gcnew MySqlCommand(query, this->conn);
	try
	{
		cursor->ExecuteNonQuery();
		MessageBox::Show("Usuario registrado correctamente :D");
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message);
	}
}