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
		MessageBox::Show("������ ���������� ������!", "������!");
	}
	else {
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["id"], dbReader["���"], dbReader["�������"], dbReader["������"], dbReader["����"]);
		}
	}

	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void Project6::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� ���� ������ ��� ����������!", "��������!");
		return;
	}

	
	int index = dataGridView1->SelectedRows[0]->Index;

	//��������� ������
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr) {
		MessageBox::Show("�� ��� ������ �������!", "��������!");
		return;
	}

	
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ ��� = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ ������� = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ ���� = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ ������ = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

	
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";//������ �����������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	
	dbConnection->Open();
	String^ query = "INSERT INTO [test] VALUES (" + id + ", '" + ��� + "', '" + ������� + "','" + ���� + "','" + ������ + "')";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("������ ���������� �������!", "������!");
	else
		MessageBox::Show("������ ���������!", "������!");

	dbConnection->Close();

	return System::Void();
}

System::Void Project6::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� ���� ������ ��� ����������!", "��������!");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr) {
		MessageBox::Show("�� ��� ������ �������!", "��������!");
		return;
	}

	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ ��� = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ ������� = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ ���� = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ ������ = dataGridView1->Rows[index]->Cells[3]->Value->ToString();

	
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";//������ �����������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);


	dbConnection->Open();
	String^ query = "UPDATE [test] SET ���='" + ��� + "', ������� = '" + ������� + "',���� ='" + ���� + "', ������ = '" + ������ + "' WHERE id = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	//��������� ������
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("������ ���������� �������!", "������!");
	else
		MessageBox::Show("������ ��������!", "������!");

	
	dbConnection->Close();

	return System::Void();
}

System::Void Project6::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� ���� ������ ��� ����������!", "��������!");
		return;
	}


	int index = dataGridView1->SelectedRows[0]->Index;


	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr)
	{
		MessageBox::Show("�� ��� ������ �������!", "��������!");
		return;
	}

	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	
	dbConnection->Open();
	String^ query = "DELETE FROM [test] WHERE id = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("������ ���������� �������!", "������!");
	else {
		MessageBox::Show("������ �������!", "������!");
		dataGridView1->Rows->RemoveAt(index);
	}

	
	dbConnection->Close();

	return System::Void();
}
