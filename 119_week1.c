#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>


int answer_menu=0, deposit_money, answer_acc, member_num[5], answer_edit, i, deposit_sum=0, year, month, day;
char name[4], address[100], phone_num[20], birth[6], citizenship[20], answer_acc_correct[4], numb[5]="0";

char transaction[2];
int withdrawal_account, withdrawal_money, deposit_account;



int main()
{
   menu();

   if(answer_menu==1) new_acc();
   if(answer_menu==2) view_list();
   if(answer_menu==3) edit();
   if(answer_menu==4) transact();
   if(answer_menu==5) erase();
   if(answer_menu==6) see();
   if(answer_menu==7) modify();
   if(answer_menu==8)

   return 0;

}


int menu()
{
   int i=0;
   for(;i<20;i++)   printf(" ");
   printf("CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM \n");

   for(i=0;i<19;i++)   printf(" ");
   printf("#########  WELCOME TO THE MAIN MENU  ######## \n \n");

   printf("1. Create new accout \n");
   printf("2. Update information of existing account \n");
   printf("3. For transactions \n");
   printf("4. Check the details of existing account \n");
   printf("5. Removing existing account \n");
   printf("6. View customer's list \n");
   printf("7. Modify member number \n");
   printf("8. Exit \n \n \n \n");

   printf("Enter your choice : ");
   scanf("%d",&answer_menu);
}

int new_acc()
{
   printf("\n�̸� : ");
   scanf("%s",name);

   printf("\n�������\n");
   printf("Year : ");
   scanf("%d",&year);
   printf("Month : ");
    scanf("%d",&month);
    printf("Day : ");
    scanf("%d",&day);

   printf("\n�ùα� ��ȣ : ");
   scanf("%s",citizenship);

   fflush(stdin);
   printf("\n�ּ� : ");
   scanf("%[^\n]s", address);

   fflush(stdin);
   printf("\n��ȭ��ȣ :");
   scanf("%[^\n]s",phone_num);

   printf("\n�Աݾ� : ");
   scanf("%d",&deposit_money);

   printf("\n1. Saving account \n");
   printf("2. Current account \n");
   printf("3. Fixed for 1 year \n");
   printf("4. Fixed for 2 year \n");
   printf("5. Fixed for 3 year \n");
   printf("\n���� ���� : ");
   scanf("%d",&answer_acc);

   printf("\n�̸� : %s \n", name);
   printf("������� : %d�� %d�� %d��\n", year, month, day);
   printf("�ùα� ��ȣ : %s\n", citizenship);
   printf("�ּ� : %s\n", address);
   printf("��ȭ��ȣ : %s\n", phone_num);
   printf("�Աݾ� : %d\n", deposit_money);
      switch(answer_acc)
   {
      case 1:printf("���� ���� : Saving account\n"); break;
      case 2:printf("���� ���� : Current account\n"); break;
      case 3:printf("���� ���� : Fixed for 1 year\n"); break;
      case 4:printf("���� ���� : Fixed for 2 year\n"); break;
      case 5:printf("���� ���� : Fixed for 3 year\n"); break;
   }

   printf("\nyes / no : ");
   scanf("%s", answer_acc_correct);

   if(strcmp(answer_acc_correct, "no")==0)
     new_acc();
   if(strcmp(answer_acc_correct, "yes")==0)
   {
      set_num_ran();
      printf("\nȸ����ȣ�� ");
      set_num();
     printf(" �Դϴ�.\n\n");

      main();
   }
}

int set_num_ran()
{
   srand(time(NULL));
   for (i=0; i<4; i++)
   {
      member_num[i]=rand()%9;
   }
}

int set_num()
{

   for (i = 0; i < 4; i++)
   {
      numb[i]=member_num[i]+48;
      printf("%c", numb[i]);
   }
}

int view_list()
{
   printf("\nȸ����ȣ :");
   set_num();
   printf("\n�̸� : %s",name);
   printf("\n�ּ� : %s",address);
   printf("\n��ȭ��ȣ : %s \n\n", phone_num);
   main();
}

int edit()
{
   printf("\n1. �ּ� ���� 2. ��ȭ��ȣ ���� : ");
   scanf("%d", &answer_edit);

   if(answer_edit==1)
   {
      printf("\n���� �ּ� : %s\n", address);

      fflush(stdin);
      printf("\n������ �ּ� : ");
      scanf("%[^\n]s", address);

      main();
   }
   else if(answer_edit==2)
   {
      printf("\n���� ��ȭ��ȣ : %s\n", phone_num);
      fflush(stdin);
      printf("\n������ ��ȭ��ȣ : ");
      scanf("%[^\n]s", phone_num);

      main();
   }

}

int transact()
{

   printf("\n�Ա�/��� �� �ŷ��� ������ �����Ͻÿ�: ");
   scanf("%s",&transaction);
   if(strcmp(transaction, "�Ա�")==0)
   {
      printf("\n�Ա��� �ݾ��� �Է��Ͻÿ�: ");
      scanf("%d",&deposit_money);
      printf("\n�Ա��� ���¸� �Է��Ͻÿ�: ");
      scanf("%d",&deposit_account);

      if(deposit_money==190000)
        printf("\n�ڼ��󿡼� ���� ���� ���� �Աݡ�\n");
      else
        printf("\n�ԱݵǾ����ϴ� \n");
      deposit_sum+=deposit_money;
      if(deposit_account==withdrawal_account)
         deposit_sum-=withdrawal_money;
      printf("\n�ܾ� : %d ��\n\n",deposit_sum);
      main();

   }
   else if(strcmp(transaction, "���")==0)
   {
      printf("\n����� �ݾ��� �Է��Ͻÿ�: ");
      scanf("%d",&withdrawal_money);
      deposit_sum=deposit_sum-withdrawal_money;
      printf("\n����� ���¸� �Է��Ͻÿ�: ");
      scanf("%d",&withdrawal_account);
      printf("\n��ݵǾ����ϴ�");
      if(deposit_account==withdrawal_account)
         withdrawal_money=deposit_sum-withdrawal_money;
      printf("\n\n�ܾ� : %d ��\n\n",deposit_sum);
      main();
   }
}

int erase()
{
   char ch[4];
   char account[5]="0";

   printf("\n������ ���� �����Ͻðڽ��ϱ�? (yes/no) :");
    scanf("%s",ch);

   int r=0;
    if(strcmp(ch,"yes")==0)
    {

       printf("\n������ ������ ȸ����ȣ�� �Է��Ͻÿ� : ");

       scanf("%s",account);
       for(i=0 ; i<4 ; i++)
       {
          if(strcmp(numb,account)==0)
           r++;
      }
      if(r==4)
      {
         printf("\n\n�����Ǿ����ϴ�.\n\n");
         for (i = 0; i < 4; i++) member_num[i]=0;
         main();
      }
       else
      {
         printf("\n�������� �ʴ� ȸ����ȣ�Դϴ�.\n \n");
          main();
      }
   }
    else if(strcmp(ch,"no")==0)
    {
        printf("\nó�� ȭ������ ���ư��� \n\n");
       main();
      }
}

int see()
{
   printf("���¹�ȣ : %d \n", deposit_account);
   printf("\n�̸� : %s \n", name);
   printf("������� : %d�� %d�� %d�� \n",year, month, day);
   printf("�ùα� ��ȣ : %s\n", citizenship);
   printf("���� : %d��\n", 2020-year+1);
   printf("�ּ� : %s\n", address);
   printf("��ȭ��ȣ : %s\n", phone_num);
   switch(answer_acc)
   {
      case 1:printf("���� ���� : Saving account\n"); break;
      case 2:printf("���� ���� : Current account\n"); break;
      case 3:printf("���� ���� : Fixed for 1 year\n"); break;
      case 4:printf("���� ���� : Fixed for 2 year\n"); break;
      case 5:printf("���� ���� : Fixed for 3 year\n"); break;
   }

   printf("�Աݾ� : %d\n", deposit_money);
   //�Աݳ�¥
   switch(answer_acc)
   {
      case 1:printf("���࿹�� ������ : ��0.1%(1�⿡ 4�� ����)\n"); break;
      case 2:printf("���¿��� ������ : 0%(���ھ���)\n"); break;
      case 3:printf("1�� ���⿹���� �ݸ��� 2�ۼ�Ʈ�� �� ���� : %.0f��\n",(float)deposit_money*0.02); break;
      case 4:printf("2�� ���⿹���� �ݸ��� 2�ۼ�Ʈ�� �� ���� : %.0f��\n",(float)deposit_money*0.02*2); break;
      case 5:printf("3�� ���⿹���� �ݸ��� 2�ۼ�Ʈ�� �� ���� : %.0f��\n",(float)deposit_money*0.02*3); break;
   }

   menu();

}

int modify()
{
   if(strcmp("0",numb)==0)
   {
      printf("\nȸ�������� ���ּ���.\n");
      main();
   }
   else
   {
      printf("\n���� ȸ����ȣ : %s", numb);
      printf("\n���ο� ȸ����ȣ :");
      set_num_ran();
      set_num();
      main();
   }
}

