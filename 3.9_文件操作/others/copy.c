/*************************************************************************
    > File Name: copy.c
    > Author: 小金
    > Mail: flyphp@outlook.com
    > Created Time: 2018/6/20 9:19:07
 ************************************************************************/


/*
编写一个程序，实现将一个目录的所有内容复制到另一个目录的功能。要求：
源文件（目录）和目标文件（目录）的属主、权限等信息保持一致；
每复制一个文件（目录），在屏幕提示相应信息；
当遇到符号链接文件时，显示该文件为链接文件
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
char paths[1000],patht[1000],temp_paths[1000],temp_patht[1000];
void Copy(char *spathname,char *tpathname);//文件复制函数
void d_copy(char *spathname,char *tpathname);//目录复制函数

int main(int argc, char** argv)//主函数
{
	struct dirent *sp,*tp;
	char spath[1000],tpath[1000],temp_spath[1000],temp_tpath[1000];
	struct stat sbuf,tbuf,temp_sbuf,temp_tbuf;
	char judge;
	DIR *dir_s,*dir_t;

	dir_s=opendir(argv[1]);
	if(dir_s==NULL)//不存在退出
	{
		printf("This directory don't exist !\n");
		return 0;
	}
	if(stat(argv[1],&sbuf)!=0)
	{
		printf("Get status error !/\n");
		return 0;
	}

	dir_t=opendir(argv[2]);
	if(dir_t==NULL)//不存在则创建
	{
		mkdir(argv[2],sbuf.st_mode);
		chown(argv[2],sbuf.st_uid,sbuf.st_gid);
		dir_t=opendir(argv[2]);
	}
	else
	{
		chmod(argv[2],sbuf.st_mode);
		chown(argv[2],sbuf.st_uid,sbuf.st_gid);
	}
	strcpy(spath,argv[1]);
	strcpy(tpath,argv[2]);
	strcpy(temp_spath,argv[1]);
	strcpy(temp_tpath,argv[2]);
	printf("Begin copy ........\n");
	while((sp=readdir(dir_s))!=NULL)
	{
		if(strcmp(sp->d_name,".")!=0&&strcmp(sp->d_name,"..")!=0)
	{
	strcat(temp_spath,"/");
	strcat(temp_spath,sp->d_name);
	strcat(temp_tpath,"/");
	strcat(temp_tpath,sp->d_name);
	lstat(temp_spath,&sbuf);
	temp_sbuf.st_mode=sbuf.st_mode;
	if(S_ISLNK(temp_sbuf.st_mode))//判断是否为符号链接
	{
		printf("%s is a symbolic link file\n",temp_spath);
	}
	else if((S_IFMT&temp_sbuf.st_mode)==S_IFREG)//文件判断
	{
		printf("Copy file %s ......\n",temp_spath);
		Copy(temp_spath,temp_tpath);
		strcpy(temp_tpath,tpath);
		strcpy(temp_spath,spath);
	}
	else if((S_IFMT&temp_sbuf.st_mode)==S_IFDIR)//目录判断
	{
		printf("Copy directory %s ......\n",temp_spath);
		d_copy(temp_spath,temp_tpath);
		strcpy(temp_tpath,tpath);
		strcpy(temp_spath,spath);
	}
	}
	}
	printf("Copy end !\n");
	closedir(dir_t);
	closedir(dir_s);
	return 1;
}


void Copy(char *spathname,char *tpathname)//文件复制函数
{
	int sfd,tfd;
	struct stat s,t;
	char c;
	sfd=open(spathname,O_RDONLY);//只读方式打开文件
	tfd=open(tpathname,O_RDWR|O_CREAT);//
	while(read(sfd,&c,1)>0)//复制文件内容
	write(tfd,&c,1);
	fstat(sfd,&s);
	chown(tpathname,s.st_uid,s.st_gid);
	chmod(tpathname,s.st_mode); //关闭文件
	close(sfd);
	close(tfd);
}
void d_copy(char *spathname,char *tpathname)//目录复制函数
{
	struct stat s,t,temp_s,temp_t;
	struct dirent *s_p;
	DIR *dirs,*dirt;
	stat(spathname,&s);
	mkdir(tpathname,s.st_mode);
	chown(tpathname,s.st_uid,s.st_gid);
	dirt=opendir(tpathname);
	dirs=opendir(spathname);
	strcpy(temp_paths,spathname);
	strcpy(temp_patht,tpathname);
	while((s_p=readdir(dirs))!=NULL)
	{
		if(strcmp(s_p->d_name,".")!=0&&strcmp(s_p->d_name,"..")!=0)
		{
			strcat(temp_paths,"/");
			strcat(temp_paths,s_p->d_name);
			strcat(temp_patht,"/");
			strcat(temp_patht,s_p->d_name);
			lstat(temp_paths,&s);
			temp_s.st_mode=s.st_mode;
			if(S_ISLNK(temp_s.st_mode))//判断是否为符号链接文件
			{
				printf("%s is a symbol link file\n",temp_paths);
			}
			else if(S_ISREG(temp_s.st_mode))//文件判断
			{
				printf("Copy file %s ......\n",temp_paths);
				Copy(temp_paths,temp_patht);
				strcpy(temp_paths,spathname);
				strcpy(temp_patht,tpathname);
			}
			else if(S_ISDIR(temp_s.st_mode)) //目录判断
			{
				printf("Copy directory %s ......\n",temp_paths);
				d_copy(temp_paths,temp_patht);
				strcpy(temp_paths,spathname);
				strcpy(temp_patht,tpathname);
			}
		}
	}
}


