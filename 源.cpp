#include "StudentManager.h"

int main()
{
    int x = 0, id = 0;
    char stu_name[100], stu_class[100];
    while (1)
    {
        stu_name[100];
        stu_class[100];
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
                gets_s(stu_name, 40);
                printf("请输入学生的班级：\n");
                gets_s(stu_class, 40);
                printf("请输入学生的学号：\n");
                scanf_s("%d", &id);
                Student stu{ id,stu_name,stu_class };
                StudentManager::GetInstance()->insert_student(stu);
                printf("录入成功！\n");
                break;
            /*case 2:
                printf("请输入学生的学号：\n");
                scanf_s("%d", &id);
                printf("请输入学生的姓名：\n");
                gets_s(stu_name, 40);
                printf("请输入学生的班级：\n");
                gets_s(stu_class, 40);
                Student stu{ id,stu_name,stu_class };
                StudentManager::GetInstance()->update_student(stu);
                printf("修改成功！\n");
                break;
            case 3:
                printf("请输入学生的学号：\n");
                scanf_s("%d", &id);
                Student stu{ id,stu_name,stu_class };
                StudentManager::GetInstance()->delete_student(stu);
                printf("删除成功！\n");
                break;
            case 4:
                printf("请输入学生的信息：\n");
                StudentManager::GetInstance()->get_student(stu);
                printf("录入成功！\n");
                break;*/
        }
       
    }

}