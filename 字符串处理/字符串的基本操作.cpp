#include<stdio.h>
#include<string.h>

/*插入字符操作*/
void Char_Insert(char str[],char ch,long pos){
	for(long i=strlen(str)+1;i>pos;i--){
		str[i]=str[i-1];
	}
	str[pos]=ch;
	
}

/*插入字符串操作*/
void Str_Insert(char str[],char strIn[],long pos){
	long lenOr=strlen(str);
	long lenIn=strlen(strIn);
	for(long i=lenOr+lenIn;i>=pos+lenIn;i--){
		str[i]=str[i-lenIn];
	}
	for(long i=pos;i<pos+lenIn;i++){
		str[i]=strIn[i-pos];
	}
}

/*删除字符操作*/
void Char_Delete_Pos(char str[],long pos){
	long len=strlen(str);
	for(long i=pos;i<len;i++){
		str[i]=str[i+1];
	}
}

/*删除字符串操作*/
void Str_Delete_Pos(char str[],long pos,long length){
	long len=strlen(str);
	for(long i=pos;i<=len-length+1;i++){
		str[i]=str[i+length];
	}
}

/*取字符串操作*/
void Mid(char to[],char from[],long pos,long length){
	for(long i=0;i<length;i++){
		to[i]=from[pos+i];
	}
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
