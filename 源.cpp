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
                gets_s(stu_name, 40);
                printf("������ѧ���İ༶��\n");
                gets_s(stu_class, 40);
                printf("������ѧ����ѧ�ţ�\n");
                scanf_s("%d", &id);
                Student stu{ id,stu_name,stu_class };
                StudentManager::GetInstance()->insert_student(stu);
                printf("¼��ɹ���\n");
                break;
            /*case 2:
                printf("������ѧ����ѧ�ţ�\n");
                scanf_s("%d", &id);
                printf("������ѧ����������\n");
                gets_s(stu_name, 40);
                printf("������ѧ���İ༶��\n");
                gets_s(stu_class, 40);
                Student stu{ id,stu_name,stu_class };
                StudentManager::GetInstance()->update_student(stu);
                printf("�޸ĳɹ���\n");
                break;
            case 3:
                printf("������ѧ����ѧ�ţ�\n");
                scanf_s("%d", &id);
                Student stu{ id,stu_name,stu_class };
                StudentManager::GetInstance()->delete_student(stu);
                printf("ɾ���ɹ���\n");
                break;
            case 4:
                printf("������ѧ������Ϣ��\n");
                StudentManager::GetInstance()->get_student(stu);
                printf("¼��ɹ���\n");
                break;*/
        }
       
    }

}