#include "StudentManager.h"

StudentManager::StudentManager()
{
	con = mysql_init(NULL);
	mysql_options(con, MYSQL_SET_CHARSET_NAME,"utf8mb4");

	if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
	{
		std::cout << "Failed to conncet" << std::endl;
		exit(1);
	}
}

StudentManager::~StudentManager()
{
	mysql_close(con);
}

bool StudentManager::user_enter(Sysuser& user1)
{
    char sql[1024];
    sprintf_s(sql, "SELECT * FROM user WHERE user_name='%s' AND user_password='%s'", user1.user_name.c_str(), user1.user_password.c_str());

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "failed:%s\n", mysql_error(con));
        return false;
    }
    MYSQL_RES* result = mysql_store_result(con);
    int num_rows = mysql_num_rows(result);
    mysql_free_result(result);

    if (num_rows == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool StudentManager::insert_student(Student& stu)
{
	char sql[1024];
	sprintf_s(sql, "Insert into student (student_id,student_name,class_id) values(%d,'%s','%s')",
		stu.student_id, stu.student_name.c_str(), stu.class_id.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "failed:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

bool StudentManager::update_student(Student& stu)
{
	char sql[1024];
	sprintf_s(sql, "Update student SET student_name = '%s',class_id = '%s'"
		"where student_id = %d",stu.student_name.c_str(), stu.class_id.c_str(),
		stu.student_id);
	if (mysql_query(con, sql))
	{
		fprintf(stderr, "failed:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

bool StudentManager::delete_student(int student_id)
{

	char sql[1024];
	sprintf_s(sql, "Delete from student where student_id =%d", student_id);

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "failed:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

vector<Student> StudentManager::get_student(string condition)
{
    vector<Student> stulist;
    char sql[1024];
    if (condition.empty())
    {
        sprintf_s(sql, "SELECT * FROM student");
    }
	else
	{
		sprintf_s(sql, "SELECT * FROM student WHERE student_id LIKE '%%%s%%' OR student_name LIKE '%%%s%%' OR class_id LIKE '%%%s%%'",
		condition.c_str(), condition.c_str(), condition.c_str());// 使用模糊匹配来查找包含输入条件的学生信息
    }

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "failed: %s\n", mysql_error(con));
        return stulist;
    }
    MYSQL_RES* res = mysql_store_result(con);
    if (!res)
    {
        fprintf(stderr, "failed to store result\n");
        return stulist; 
    }
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res)))
    {
        Student stu;
        stu.student_id = atoi(row[0]);
        stu.student_name = row[1];
        stu.class_id = row[2];
        stulist.push_back(stu);
    }
    mysql_free_result(res);

    return stulist;
}