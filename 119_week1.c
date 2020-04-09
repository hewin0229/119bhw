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
   menu();  // 메뉴

   if(answer_menu==1) new_acc();    // 새로운 계정 생성
   if(answer_menu==2) view_list();  // 입력된 정보 나열
   if(answer_menu==3) edit();       // 주소, 전화번호 변경
   if(answer_menu==4) transact();   // 입/출금
   if(answer_menu==5) erase();      // 계정 삭제
   if(answer_menu==6) see();        // 참고 내용
   if(answer_menu==7) modify();     // 회원번호 변경(이스터에그)
   if(answer_menu==8) return 0;     // 종료

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
   printf("\n이름 : ");
   scanf("%s",name);

   printf("\n생년월일\n");
   printf("Year : ");
   scanf("%d",&year);
   printf("Month : ");
    scanf("%d",&month);
    printf("Day : ");
    scanf("%d",&day);

   printf("\n시민권 번호 : ");
   scanf("%s",citizenship);

   fflush(stdin);
   printf("\n주소 : ");
   scanf("%[^\n]s", address);

   fflush(stdin);
   printf("\n전화번호 :");
   scanf("%[^\n]s",phone_num);

   printf("\n입금액 : ");
   scanf("%d",&deposit_money);

   printf("\n1. Saving account \n");
   printf("2. Current account \n");
   printf("3. Fixed for 1 year \n");
   printf("4. Fixed for 2 year \n");
   printf("5. Fixed for 3 year \n");
   printf("\n예금 유형 : ");
   scanf("%d",&answer_acc);

   printf("\n이름 : %s \n", name);
   printf("생년월일 : %d년 %d월 %d일\n", year, month, day);
   printf("시민권 번호 : %s\n", citizenship);
   printf("주소 : %s\n", address);
   printf("전화번호 : %s\n", phone_num);
   printf("입금액 : %d\n", deposit_money);
      switch(answer_acc)
   {
      case 1:printf("예금 유형 : Saving account\n"); break;
      case 2:printf("예금 유형 : Current account\n"); break;
      case 3:printf("예금 유형 : Fixed for 1 year\n"); break;
      case 4:printf("예금 유형 : Fixed for 2 year\n"); break;
      case 5:printf("예금 유형 : Fixed for 3 year\n"); break;
   }

   printf("\nyes / no : ");
   scanf("%s", answer_acc_correct);

   if(strcmp(answer_acc_correct, "no")==0)
     new_acc();
   if(strcmp(answer_acc_correct, "yes")==0)
   {
      set_num_ran();
      printf("\n회원번호는 ");
      set_num();
     printf(" 입니다.\n\n");

      main();
   }
}

int set_num_ran()
{
   srand(time(NULL));
   for (i=0; i<4; i++)
   {
      member_num[i]=rand()%10;
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
   printf("\n회원번호 :");
   set_num();
   printf("\n이름 : %s",name);
   printf("\n주소 : %s",address);
   printf("\n전화번호 : %s \n\n", phone_num);
   main();
}

int edit()
{
   printf("\n1. 주소 변경 2. 전화번호 변경 : ");
   scanf("%d", &answer_edit);

   if(answer_edit==1)
   {
      printf("\n현재 주소 : %s\n", address);

      fflush(stdin);
      printf("\n변경할 주소 : ");
      scanf("%[^\n]s", address);

      main();
   }
   else if(answer_edit==2)
   {
      printf("\n현재 전화번호 : %s\n", phone_num);
      fflush(stdin);
      printf("\n변경할 전화번호 : ");
      scanf("%[^\n]s", phone_num);

      main();
   }

}

int transact()
{

   printf("\n입금/출금 중 거래할 내용을 선택하시오: ");
   scanf("%s",&transaction);
   if(strcmp(transaction, "입금")==0)
   {
      printf("\n입금할 금액을 입력하시오: ");
      scanf("%d",&deposit_money);
      printf("\n입금할 계좌를 입력하시오: ");
      scanf("%d",&deposit_account);

      if(deposit_money==190000)
        printf("\n★세상에서 가장 쉬운 숫자 입금★\n");
      else
        printf("\n입금되었습니다 \n");
      deposit_sum+=deposit_money;
      if(deposit_account==withdrawal_account)
         deposit_sum-=withdrawal_money;
      printf("\n잔액 : %d 원\n\n",deposit_sum);
      main();

   }
   else if(strcmp(transaction, "출금")==0)
   {
      printf("\n출금할 금액을 입력하시오: ");
      scanf("%d",&withdrawal_money);
      deposit_sum=deposit_sum-withdrawal_money;
      printf("\n출금할 계좌를 입력하시오: ");
      scanf("%d",&withdrawal_account);
      printf("\n출금되었습니다");
      if(deposit_account==withdrawal_account)
         withdrawal_money=deposit_sum-withdrawal_money;
      printf("\n\n잔액 : %d 원\n\n",deposit_sum);
      main();
   }
}

int erase()
{
   char ch[4];
   char account[5]="0";

   printf("\n계정을 정말 삭제하시겠습니까? (yes/no) :");
    scanf("%s",ch);

   int r=0;
    if(strcmp(ch,"yes")==0)
    {

       printf("\n삭제할 계정의 회원번호를 입력하시오 : ");

       scanf("%s",account);
       for(i=0 ; i<4 ; i++)
       {
          if(strcmp(numb,account)==0)
           r++;
      }
      if(r==4)
      {
         printf("\n\n삭제되었습니다.\n\n");
         for (i = 0; i < 4; i++) member_num[i]=0;
         main();
      }
       else
      {
         printf("\n존재하지 않는 회원번호입니다.\n \n");
          main();
      }
   }
    else if(strcmp(ch,"no")==0)
    {
        printf("\n처음 화면으로 돌아가기 \n\n");
       main();
      }
}

int see()
{
   printf("계좌번호 : %d \n", deposit_account);
   printf("\n이름 : %s \n", name);
   printf("생년월일 : %d년 %d월 %d일 \n",year, month, day);
   printf("시민권 번호 : %s\n", citizenship);
   printf("나이 : %d세\n", 2020-year+1);
   printf("주소 : %s\n", address);
   printf("전화번호 : %s\n", phone_num);
   switch(answer_acc)
   {
      case 1:printf("예금 유형 : Saving account\n"); break;
      case 2:printf("예금 유형 : Current account\n"); break;
      case 3:printf("예금 유형 : Fixed for 1 year\n"); break;
      case 4:printf("예금 유형 : Fixed for 2 year\n"); break;
      case 5:printf("예금 유형 : Fixed for 3 year\n"); break;
   }

   printf("입금액 : %d\n", deposit_money);
   //입금날짜
   switch(answer_acc)
   {
      case 1:printf("저축예금 이자율 : 약0.1%(1년에 4번 지급)\n"); break;
      case 2:printf("당좌예금 이자율 : 0%(이자없음)\n"); break;
      case 3:printf("1년 정기예금의 금리가 2퍼센트일 때 이자 : %.0f원\n",(float)deposit_money*0.02); break;
      case 4:printf("2년 정기예금의 금리가 2퍼센트일 때 이자 : %.0f원\n",(float)deposit_money*0.02*2); break;
      case 5:printf("3년 정기예금의 금리가 2퍼센트일 때 이자 : %.0f원\n",(float)deposit_money*0.02*3); break;
   }

   menu();

}

int modify()
{
   if(strcmp("0",numb)==0)
   {
      printf("\n회원가입을 해주세요.\n");
      main();
   }
   else
   {
      printf("\n현재 회원번호 : %s", numb);
      printf("\n새로운 회원번호 :");
      set_num_ran();
      set_num();
      main();
   }
}

