#include<stdio.h>
#define max 25

void main()
{
  int frag[max],bs[max],fs[max],i,j,nb,nf,temp,bn[max],fn[max],highest=0;
  printf("WORST FIT MEMORY ALLOCATION\n");
  printf("\nEnter the no.of files: ");
  scanf("%d",&nf);
  printf("\nEnter the no.of blocks: ");
  scanf("%d",&nb);
  printf("\nEnter the sizes of blocks:\n");
  for(i=1;i<=nb;i++)
   scanf("%d",&bs[i]);
  printf("\nEnter the sizes of files:\n");
  for(i=1;i<=nf;i++)
   scanf("%d",&fs[i]);

  for(i = 0; i < nf; i++)
    {
        bn[fn[i]] = -1;
    }
  
  for(i=1;i<=nf;i++)
  {
    for(j=1;j<=nb;j++)
    {
      if(bn[j]!=1)  //block not allocated
      {
        temp=bs[j] - fs[i];
        if(temp>=0)  //block-size is greater or adequate
        {
          if(highest<temp)
           {
           fn[i]=j;
           highest=temp;
           }
        }
        
      }
    }
    frag[i]=highest;
    
    if(highest>0)
      bn[fn[i]]=1;
    
    highest=0;
  }
  printf("\nFile No:\tFile Size:\tBlock No:\tBlock Size:\tFragment");
  for(i=1;i<=nf;i++)
    {
     printf("\n%d\t\t",i);
     printf("%d\t\t",fs[i]);
     if(bn[fn[i]]==1)
      printf("%d\t\t",fn[i]);
     else
      printf("Not Allocated\t");
     if(bn[fn[i]]==1)
      printf("%d\t\t",bs[fn[i]]);
     else
      printf("Nil\t\t");
     if(bn[fn[i]]==1)
       printf("%d",frag[i]);
     else
       printf("Nil\t");
     
    }
 }