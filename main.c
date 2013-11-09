#include <stdio.h>
#include <stdlib.h>
struct tree                                 //�������ṹ��
{
 char data;
 struct tree *left;
 struct tree *right;
};


struct tree *creat(void)                      //�������Ķ�����
 {
     char ch;
     struct tree *p;
     printf("�������ַ���\n");
     scanf("%c",&ch);
     getchar();
     if(ch=='!')
        p=NULL;
     else
     {
         p=(struct tree *)malloc(sizeof(struct tree));
         if (!p)exit (0);
         p->data=ch;
         p->left=creat();//����������ֵ
         p->right=creat();//����������ֵ
     }
     return p;
 }

void Levelordertraverse(struct tree *h)                             //�������������
{
 if(h!=NULL)
 {
  printf("%c ",h->data);
  Levelordertraverse(h->left);
  Levelordertraverse(h->right);
 }
}

void Inordertraverse(struct tree *h)                             //�������������
{
 if(h!=NULL)
 {
  Inordertraverse(h->left);
  printf("%c ",h->data);
  Inordertraverse(h->right);
 }
}


void Postordertraverse(struct tree *h)                             //�������������
{
 if(h!=NULL)
 {
  Postordertraverse(h->left);
  Postordertraverse(h->right);
  printf("%c ",h->data);
 }
}



int main()                                     //������
{
    struct tree *a=creat();
    printf("�������Ϊ:\n");
    Levelordertraverse(a);
    printf("�������Ϊ:\n");
    Inordertraverse(a);
    printf("�������Ϊ:\n");
    Postordertraverse(a);

}
