#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

[STAThread]
int main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Project6::MyForm form;
	Application::Run(% form);
}

System::Void Project6::MyForm::button_download_Click_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	
	dbConnection->Open();
	String^ query = "SELECT * FROM [test]";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();

	if (dbReader->HasRows == false) {
		MessageBox::Show("Ошибка считывания данных!", "Ошибка!");
	}
	else {
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["id"], dbReader["Имя"], dbReader["Фамилия"], dbReader["Оценка"], dbReader["Тест"]);
		}
	}

	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void Project6::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите одну строку для добавления!", "Внимание!");
		return;
	}

	
	int index = dataGridView1->SelectedRows[0]->Index;

	//Проверяем данные
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ Имя = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Фамилия = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ Тест = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ Оценка = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

	
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";//Строка подключения
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	
	dbConnection->Open();
	String^ query = "INSERT INTO [test] VALUES (" + id + ", '" + Имя + "', '" + Фамилия + "','" + Тест + "','" + Оценка + "')";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	else
		MessageBox::Show("Данные добавлены!", "Готово!");

	dbConnection->Close();

	return System::Void();
}

System::Void Project6::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите одну строку для добавления!", "Внимание!");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ Имя = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Фамилия = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ Тест = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ Оценка = dataGridView1->Rows[index]->Cells[3]->Value->ToString();

	
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";//Строка подключения
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);


	dbConnection->Open();
	String^ query = "UPDATE [test] SET Имя='" + Имя + "', Фамилия = '" + Фамилия + "',Тест ='" + Тест + "', Оценка = '" + Оценка + "' WHERE id = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	//Выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	else
		MessageBox::Show("Данные изменены!", "Готово!");

	
	dbConnection->Close();

	return System::Void();
}

System::Void Project6::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите одну строку для добавления!", "Внимание!");
		return;
	}


	int index = dataGridView1->SelectedRows[0]->Index;


	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	
	dbConnection->Open();
	String^ query = "DELETE FROM [test] WHERE id = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	else {
		MessageBox::Show("Данные удалены!", "Готово!");
		dataGridView1->Rows->RemoveAt(index);
	}

	
	dbConnection->Close();

	return System::Void();
}
