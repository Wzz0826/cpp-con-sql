#include "StudentManager.h"

int main()
{
    int x = 0, id = 0;
    char stu_name[100], stu_class[100], user_name[100], user_password[100];
    Student stu; 
    Sysuser user1;
    printf("----------------\n");
    printf("登录\n");
    printf("请输入用户名：\n");
    fgets(user_name, sizeof(user_name), stdin);
    user_name[strcspn(user_name, "\n")] = '\0'; 
    printf("请输入密码：\n");
    fgets(user_password, sizeof(user_password), stdin);
    user_password[strcspn(user_password, "\n")] = '\0'; 

    user1 = { user_name, user_password };
    bool login_success = StudentManager::GetInstance()->user_enter(user1);
    if (login_success) {
        printf("登录成功！\n");
        printf("----------------\n");
       while (1)
        {
            printf("----------------\n");
            printf("1.添加数据\n");
            printf("2.更新数据\n");
            printf("3.删除数据\n");
            printf("4.查询数据\n");
            printf("----------------\n");
            printf("请输入（1-4）\n");
            scanf_s("%d", &x);
            getchar();

            switch (x)
            {
            case 1:
                printf("请输入学生的姓名：\n");
                fgets(stu_name, sizeof(stu_name), stdin);
                printf("请输入学生的班级：\n");
                fgets(stu_class, sizeof(stu_class), stdin);
                printf("请输入学生的学号：\n");
                scanf_s("%d", &id);
                getchar();
                stu = { id, stu_name, stu_class }; // 赋值给 stu
                StudentManager::GetInstance()->insert_student(stu);
                printf("录入成功！\n");
                break;
            case 2:
                printf("请输入学生的学号：\n");
                scanf_s("%d", &id);
                getchar();
                printf("请输入学生的姓名：\n");
                fgets(stu_name, sizeof(stu_name), stdin);
                printf("请输入学生的班级：\n");
                fgets(stu_class, sizeof(stu_class), stdin);
                stu = { id, stu_name, stu_class }; // 赋值给 stu
                StudentManager::GetInstance()->update_student(stu);
                printf("修改成功！\n");
                break;
            case 3:
                printf("请输入学生的学号：\n");
                scanf_s("%d", &id);
                getchar();
                StudentManager::GetInstance()->delete_student(id);
                printf("删除成功！\n");
                break;
            case 4:
                printf("请输入查询条件：\n");
                fgets(stu_name, sizeof(stu_name), stdin);
                stu_name[strcspn(stu_name, "\n")] = '\0';
                vector<Student> students = StudentManager::GetInstance()->get_student(stu_name);
                if (students.empty())
                {
                    printf("未找到符合条件的学生。\n");
                }
                else
                {
                    printf("查询结果：\n");
                    for (const auto& student : students)
                    {
                        printf("学生ID：%d，姓名：%s，班级：%s \n", student.student_id, student.student_name.c_str(), student.class_id.c_str());
                    }
                }
                break;
            }
        }
        return 0;
    }
    else {
        printf("登录失败！\n");
        return 1; // 退出程序，返回一个错误码
    }
   
}
