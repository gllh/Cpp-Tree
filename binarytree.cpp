#include<iostream.h>
#define maxsize 100
typedef char elemtype;
typedef struct binode
{
	elemtype data;
	binode *lchild,*rchild;
}bitree; 
 void createbtree(bitree *&bt,char *str)
 {
	 bitree *stack[maxsize],*p;
	bt=NULL;
	 int top=-1,k,j=0;
	 char ch;
	 ch=str[j];
	 while(ch!='#')
	 {
		 switch(ch)
		 {case '(':
              top++;
			  stack[top]=p;
			  k=1;
			  break;
         case ')':
              top--;
			  break;
         case ',':
              k=2;
			  break;
		 default:
			 p=new binode;
			 p->data=ch;
			 p->lchild=p->rchild=NULL;
			 if(bt==NULL)
               bt=p;
			 else
		      switch(k)
			 {case 1: stack[top]->lchild=p;break;
		      case 2: stack[top]->rchild=p;break;}
		 }
	 
	 j++;
	 ch=str[j];}
  }
 void Predigui(bitree *b)
{    
    if(b==NULL)    
        return ;    
    cout<<b->data<<" ";     
    Predigui(b->lchild);     
    Predigui(b->rchild);   
}
void Middigui(bitree *b)  
{    
    if(b==NULL)  
        return ;  
    Middigui(b->lchild);     
    cout<<b->data<<" ";    
    Middigui(b->rchild);    
}
void Lastdigui(bitree *b) 
{  
    if(b==NULL)  
        return ;  
    Lastdigui(b->lchild);          
    Lastdigui(b->rchild);          
    cout<<b->data<<" ";        
}
void printree(bitree *boot)
{
	bitree *b=boot;
	if(b!=NULL)
	{
		cout<<b->data;
		if((b->lchild!=NULL)||(b->rchild!=NULL))
		{
			cout<<"(";
			printree(b->lchild);
			if (b->rchild!=NULL) cout<<",";
            printree(b->rchild);
			cout<<")";
		}
	}
}
void pretree(bitree *boot)
{
	int top=-1;
	bitree *s[maxsize],*bt=boot;
	while((bt!=NULL)||(top!=-1))
	{
		while(bt!=NULL)
		{
			cout<<bt->data<<" ";
			s[++top]=bt;
			bt=bt->lchild;
		}
		if(top!=-1)
		{
			bt=s[top--];bt=bt->rchild;
		}
	}
}
void midtree(bitree *boot)
{
	int top=-1;
	bitree *s[maxsize],*bt=boot;
	while((bt!=NULL)||(top!=-1))
	{
		while(bt!=NULL)
		{		
			s[++top]=bt;
			bt=bt->lchild;
		}
		if(top>-1)
		{
			bt=s[top--];
			cout<<bt->data<<" ";
			bt=bt->rchild;
		}
	}
}
void backtree(bitree *boot)
{
	bitree *s[maxsize],*pre=NULL,*bt=boot;
	int top=-1;
	while((bt!=NULL)||(top!=-1))
	{
		while(bt!=NULL)
		{
			s[++top]=bt;
			bt=bt->lchild;
		}
		if(top>-1)
		{
			bt=s[top];
			if(bt->rchild!=NULL&&bt->rchild!=pre)
			{
				bt=bt->rchild;
			}
			else
			{
				cout<<bt->data<<" ";
			pre=bt;
			bt=NULL;
			top--;
			}
		}
	}
}
void leveltree(bitree *boot)
{
	bitree *s[maxsize],*bt=boot;
	int rear=0,front=0;
	s[rear++]=bt;
	while(rear!=front)
	{
		bt=s[front];
		front=(front+1)%maxsize;
		cout<<bt->data<<" ";
		if(bt->lchild!=NULL)
		{
			s[rear]=bt->lchild;
			rear=(rear+1)%maxsize;
		}
		if(bt->rchild!=NULL)
		{
			s[rear]=bt->rchild;
			rear=(rear+1)%maxsize;
		}
	}
}
//a(b(,c(d)))
void main()
{
	bitree *bt;
    createbtree(bt,"6(3(5(3(,0)),0(,0)),1(7(,1(1)),0))#");
	cout<<"嵌套表示法"<<endl;
	printree(bt);
	cout<<endl;
	cout<<"递归："<<endl;
	cout<<"前序遍历：";
	  Predigui(bt);
	  cout<<endl;
	  cout<<"中序遍历：";
	  Middigui(bt);
	  cout<<endl;
	  cout<<"后序遍历：";
	  Lastdigui(bt);
	  cout<<endl;
	  cout<<"非递归："<<endl;
	cout<<"前序："<<endl;
	pretree(bt);
	cout<<endl;
	cout<<"中序："<<endl;
	midtree(bt);
	cout<<endl;  
	cout<<"后序："<<endl;
	backtree(bt);
	cout<<endl; 
	cout<<"层次："<<endl;
	leveltree(bt);
	cout<<endl; 
}

