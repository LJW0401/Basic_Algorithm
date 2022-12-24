#include<stdio.h>
#include<string.h>

/*插入字符操作*/
void Char_Insert(char str[],char ch,long pos){
	char tmp[10001];
	strcpy(tmp,str+pos);
	str[pos]=ch;
	strcpy(str+pos+1,tmp);
}

/*插入字符串操作*/
void Str_Insert(char str[],char str_[],long pos){
	char tmp[10001];
	strcpy(tmp,str+pos);
	strcpy(str+pos,str_);
	strcpy(str+pos+strlen(str_),tmp);
}

/*删除字符操作*/
void Char_Delete_Pos(char str[],long pos){
	strcpy(str+pos,str+pos+1);
}

/*删除字符串操作*/
void Str_Delete_Pos(char str[],long pos,long length){
	strcpy(str+pos,str+pos+length);
}

/*取字符串操作*/
void Mid(char to[],char from[],long pos,long length){
	strcpy(to,from+pos);
	to[length]='\0';
}

int main(){
	char s[]="123456789";
	puts(s);
	Char_Insert(s,'v',3);puts(s);
	char instr[]="-xyz-";
	Str_Insert(s,instr,5);puts(s);
	Str_Delete_Pos(s,5,5);puts(s);
	char copied[100];
	Mid(copied,s,2,3);puts(copied);
	
	return 0;
}
