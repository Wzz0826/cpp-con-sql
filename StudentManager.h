#pragma once
#include<mysql.h>
#include<iostream>
#include<string>
#include <vector>;

using namespace std;

typedef struct Student
{
	int student_id;
	string student_name;
	string class_id;

}Student;

typedef struct Sysuser
{
	string user_name;
	string user_password; 
} Sysuser;

class StudentManager
{
	StudentManager();
	~StudentManager();

public:
	static StudentManager* GetInstance() //µ¥ÀıÄ£Ê½
	{
		static StudentManager instance;
		return &instance;
	}
public:
	bool user_enter(Sysuser& t);
	bool insert_student(Student & t);
	bool update_student(Student& t);
	bool delete_student(int student_id);
	vector<Student> get_student(string condition = "");
private:
	MYSQL* con;
	const char* host = "localhost";
	const char* user = "root";
	const char* pw = "123456";
	const char* database_name = "student_manager";
	const int port = 3306;
};

