#include "StudentManager.h"

int main()
{
    int x = 0, id = 0;
    char stu_name[100], stu_class[100], user_name[100], user_password[100];
    Student stu; 
    Sysuser user1;
    printf("----------------\n");
    printf("��¼\n");
    printf("�������û�����\n");
    fgets(user_name, sizeof(user_name), stdin);
    user_name[strcspn(user_name, "\n")] = '\0'; 
    printf("���������룺\n");
    fgets(user_password, sizeof(user_password), stdin);
    user_password[strcspn(user_password, "\n")] = '\0'; 

    user1 = { user_name, user_password };
    bool login_success = StudentManager::GetInstance()->user_enter(user1);
    if (login_success) {
        printf("��¼�ɹ���\n");
        printf("----------------\n");
       while (1)
        {
            printf("----------------\n");
            printf("1.�������\n");
            printf("2.��������\n");
            printf("3.ɾ������\n");
            printf("4.��ѯ����\n");
            printf("----------------\n");
            printf("�����루1-4��\n");
            scanf_s("%d", &x);
            getchar();

            switch (x)
            {
            case 1:
                printf("������ѧ����������\n");
                fgets(stu_name, sizeof(stu_name), stdin);
                printf("������ѧ���İ༶��\n");
                fgets(stu_class, sizeof(stu_class), stdin);
                printf("������ѧ����ѧ�ţ�\n");
                scanf_s("%d", &id);
                getchar();
                stu = { id, stu_name, stu_class }; // ��ֵ�� stu
                StudentManager::GetInstance()->insert_student(stu);
                printf("¼��ɹ���\n");
                break;
            case 2:
                printf("������ѧ����ѧ�ţ�\n");
                scanf_s("%d", &id);
                getchar();
                printf("������ѧ����������\n");
                fgets(stu_name, sizeof(stu_name), stdin);
                printf("������ѧ���İ༶��\n");
                fgets(stu_class, sizeof(stu_class), stdin);
                stu = { id, stu_name, stu_class }; // ��ֵ�� stu
                StudentManager::GetInstance()->update_student(stu);
                printf("�޸ĳɹ���\n");
                break;
            case 3:
                printf("������ѧ����ѧ�ţ�\n");
                scanf_s("%d", &id);
                getchar();
                StudentManager::GetInstance()->delete_student(id);
                printf("ɾ���ɹ���\n");
                break;
            case 4:
                printf("�������ѯ������\n");
                fgets(stu_name, sizeof(stu_name), stdin);
                stu_name[strcspn(stu_name, "\n")] = '\0';
                vector<Student> students = StudentManager::GetInstance()->get_student(stu_name);
                if (students.empty())
                {
                    printf("δ�ҵ�����������ѧ����\n");
                }
                else
                {
                    printf("��ѯ�����\n");
                    for (const auto& student : students)
                    {
                        printf("ѧ��ID��%d��������%s���༶��%s \n", student.student_id, student.student_name.c_str(), student.class_id.c_str());
                    }
                }
                break;
            }
        }
        return 0;
    }
    else {
        printf("��¼ʧ�ܣ�\n");
        return 1; // �˳����򣬷���һ��������
    }
   
}
