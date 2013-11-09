#include <stdio.h>
#include <stdlib.h>
struct tree                                 //二叉树结构体
{
 char data;
 struct tree *left;
 struct tree *right;
};


struct tree *creat(void)                      //创建树的二叉树
 {
     char ch;
     struct tree *p;
     printf("请输入字符：\n");
     scanf("%c",&ch);
     getchar();
     if(ch=='!')
        p=NULL;
     else
     {
         p=(struct tree *)malloc(sizeof(struct tree));
         if (!p)exit (0);
         p->data=ch;
         p->left=creat();//给左子树赋值
         p->right=creat();//给右子树赋值
     }
     return p;
 }

void Levelordertraverse(struct tree *h)                             //二叉树先序输出
{
 if(h!=NULL)
 {
  printf("%c ",h->data);
  Levelordertraverse(h->left);
  Levelordertraverse(h->right);
 }
}

void Inordertraverse(struct tree *h)                             //二叉树中序输出
{
 if(h!=NULL)
 {
  Inordertraverse(h->left);
  printf("%c ",h->data);
  Inordertraverse(h->right);
 }
}


void Postordertraverse(struct tree *h)                             //二叉树后序输出
{
 if(h!=NULL)
 {
  Postordertraverse(h->left);
  Postordertraverse(h->right);
  printf("%c ",h->data);
 }
}



int main()                                     //主函数
{
    struct tree *a=creat();
    printf("先序输出为:\n");
    Levelordertraverse(a);
    printf("中序输出为:\n");
    Inordertraverse(a);
    printf("后序输出为:\n");
    Postordertraverse(a);

}
