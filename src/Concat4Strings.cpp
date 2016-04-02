/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings. 
In Case of Multiple strings with smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : �abcdefghijkl� (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string. 
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order 
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4);

Note : You can use String.h functions .

Constraints : 
Length of each String will be less than 100 .

Difficulty : Hard
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	//Return the new string created.
	int i;
	char *s;
	s = (char *)malloc(sizeof(char));
		if (strstr(s1, s2))
		{
			if (strlen(s1) > strlen(s2))
			{
				s = (char *)realloc(s, strlen(s1)*sizeof(char));
				strcpy(s, s1);
			}
			else
			{
				s = (char *)realloc(s, strlen(s2)*sizeof(char));
				strcpy(s, s2);
			}
		}
		if (strstr(s1, s3))
		{
			if (strlen(s1) > strlen(s3));
			else
			{
				s = (char *)realloc(s, strlen(s3)*sizeof(char));
				strcpy(s, s3);
			}
		}
		if (strstr(s1, s4))
		{
			if (strlen(s1) > strlen(s4));
			else
			{
				s = (char *)realloc(s, strlen(s4)*sizeof(char));
				strcpy(s, s4);
			}
		}
		return s;
}