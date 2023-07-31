#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
int main ( )
{
int fd,fd2;
char buffer[20] =" ";
fd=open ("file2.txt",ORDWR) ;
char data[]= "This i s a message";
if(fd!=-1)
{
p r i n t f ("File1 Opened");
write(fd,data,sizeof(data));
printf("\nData added to filel:%s\n",data);
close(fd);
}
fd2=open("file3.txt",ORDWR);
if(fd2!=-1)
{
printf("\n File2 Opened");
read(fd,buffer,sizeof(data));
printf("\nData from file:%s\n",buffer);
close(fd);
}
return 0;
}
