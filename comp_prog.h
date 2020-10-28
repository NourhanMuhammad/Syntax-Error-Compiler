#ifndef     _COMP_PROGRAME_H
#define     _COMP_PROGRAME_H
 
 
                 // 0        1      2     3       4      5         6        7      8         9       10         11
char* Words_C[] = {"#include", "void","int","char", "float","double","while", "for", "break", "case", "continue", "switch",
	                          "return", "if", "do", "else", "struct","union", "enum",
	                          "typedef", "goto", "default", "sizeof", "long", "const", "register", "static","short",
	                          "signed", "unsigned", "volatile", "extern", "auto"};
							  
 char *commentOperator[] = {"//", "/*", "*/"};  //   // 
 char arrNumber[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  char arrchar[] = {'*','(',')','-','=','+','&','^','%','$','#','@','!','?','/','\\','\"',';','\'','[',']'};
 char commentFlag1 = 0 , commentFlag2 = 0;
 

void removeEmptyLines(FILE * fp_source, FILE * fp_temp)
{
	char buffer[bufsize];
	while((fgets(buffer , bufsize, fp_source)) != NULL)
	{
		if( !isEmpty(buffer) )
		{
			fputs(buffer , fp_temp);
		}
	}
}


int isEmpty (char *str)
{
	char ch;
	do
	{
		ch = *(str++);
		if(ch != ' ' && ch != '\t' && ch != '\n'&& ch != '\r' && ch != '\0')
		{ return 0; }
	
	} while(ch !='\0');

	return 1;
}

void FirstWord(char *str)           // #include
{
	char space_str [] = {' '};
	
	char i;
	str = trim_space (str);
	 
    for ( i = 0; *(str+i) != space_str[0]; i++) //int employee
	{arr[i] = str[i]; }
	
	arr[i]= '\0'; 
	str = trim_space (str);
}


char * trim_space(char* str)
{
	char *end;
	while(isspace(*str))
	{
		str = str +1;
	}
	end = str +(strlen(str)-1);
	while((end> str)&&(isspace(*end)))
	{
		end = end -1;
	}
	*(end +1)= '\0';
	

	return str;
}

int discoverWord(void)  // int--> 3   // int float char
{     
    
     char i ;
	 int ret ;                    // 0 != 0                // i<3
	if (strcmp (arr, curly_braket1[0])==0)  // {
		 
	 {
	     // curly_braket1_flag ++ ; 
		 // printf ("curly_braket1_flag is = %d \n ", curly_braket1_flag);
					
	  	 ret = 510  ; 
		 return ret ; 
	 }
	 
	 else if(strcmp (arr, curly_braket2[0])==0)    // }
	 { 
					
		   // curly_braket2_flag ++ ;
           // printf ("curly_braket1_flag is = %d \n ", curly_braket1_flag);
		
		  ret = 520 ; 
		 return ret  ; 
	 }
	 else if(strcmp (arr, commentOperator[0])==0)
	 {
		 // printf ("single comment");
		 ret = 501;  // single comment
	 }
	  else if(strcmp (arr, commentOperator[1])==0)
	 {
		 commentFlag1++;
		 // printf ("multiline comment");
		 ret = 502;  //multLine comment	 }
     }
	  else if(strcmp (arr, commentOperator[2])==0)
	 {
	     commentFlag2++;
		 // printf ("multiline comment");
		 ret = 502;  //multLine comment	 } 
	 }
	 else
	 {
	   for(i=0; ((i < 33)&&( strcmp(arr, Words_C[i] ) != 0)) ; i++) 
       {
		// printf("i = %d ",i);
	   }
     	// printf("hello \n",i);
	  if (i< 33)   // 
	  {
		// printf("all is ok\n");
		int k=(int)i;
		return k;
		
    	}
      else
	  {
		// printf("Error syntax\n");
		ret =  111;
		return ret;
	  }
	}
	     
}

void isFor(char *str, char NumLine) 
{ 
   // /*   
    // semicolon, bracket1, bracket2 are used  
        // to count frequencies of 
    // ';', '(', and ')' respectively 
    // flag is set to 1 when an error is found, else no error 
    int semicolon = 0, bracket1 = 0, bracket2 = 0, flag = 0, i=0;
	
   str = trim_space (str);
    // Proper usage of "for" keyword checked 
    while(i != strlen(str)) 
    { 
        char ch = str[i++]; 
        if(ch == '(') 
        { 
            // opening parenthesis count 
            bracket1 ++; 
        } 
        else if(ch == ')') 
        { 
            // closing parenthesis count 
            bracket2 ++; 
              
        } 
        else if(ch == ';') 
        { 
            // semicolon count 
            semicolon ++; 
        } 
        else continue; 
          
    } 
      
    // check number of semicolons 
    if(semicolon != 2) 
    {  
		printf ("line %d: ",NumLine) ; 
        printf("Semicolon Error\n"); 
        flag++; 
    } 
      
    // check closing Parenthesis 
    if(str[strlen(str) - 1] != ')') 
    {  
		printf ("line %d: ",NumLine) ; 
        printf("Closing parenthesis absent at end\n"); 
        flag++; 
    } 
      
    // check opening parenthesis 
     if(str[3] == ' ' && str[4] != '(' ) 
    { 
		printf ("line %d: ",NumLine) ;
        printf("Opening parenthesis absent after for keyword\n"); 
        flag++; 
    } 
      
    // check parentheses count 
    if(bracket1 != 1 || bracket2 != 1 || bracket1 != bracket2) 
    {  
		printf ("line %d: ",NumLine) ;
        printf("Parentheses Count Error\n"); 
        flag++; 
    } 
      
    // no error  
    if(flag == 0) 
	{ 
		printf ("line %d: ",NumLine) ;
		printf("No error\n");
	} 
              
} 


void isInclude(char *str, char NumLine)
{
	int bracketL = 0, bracketR = 0, Dquote = 0, flag = 0, i=9;
	str = trim_space (str);  /// #include     <fdfxdcfvxc>>
	
	 while(i != strlen(str)) 
    { 
        char ch = str[i]; 
        if(ch == '<') 
        { 
			bracketL ++; 
        }
		 else if(ch == '>') 
        { 
           
            bracketR ++; 
        } 
        else if(ch == '\"') 
        { 
            Dquote ++; 
        } 
    
	
		i++;
	}
	
	 
	 if((str[strlen(str) - 1] != '>') && (str[strlen(str) - 1] != '\"'))
    {  
		printf ("line %d: ",NumLine) ;
        printf("ERROR: Closing parenthesis or Dquote absent at end\n"); 
        flag++; 
    } 
      
    // check opening parenthesis    <  "
    else if(str[8] == ' ' ) 
    {  //&& (str[10] != '<'||str[10] != '\"')
        
		str =str+8;
	
		while(isspace(*str))
		{
			str = str+1;
		}
		if((*str != '<')&&(*str != '\"'))
		{
			printf ("line %d: ",NumLine) ;
			printf("ERROR: Opening parenthesis or Dquote absent after include keyword\n"); 
			flag++; 
		}
    }                                             /// <ujyfhf>fg>
	
      
    // no error  
    if(((bracketL == 1 && bracketR == 1 && Dquote == 0) ||(bracketL == 0 && bracketR == 0 && Dquote == 2))&&(flag ==0))
	{
		// printf ("line %d: ",NumLine) ;
		// printf("No error\n");
	} 

     else
	 {
		 printf ("line %d: ",NumLine) ;
		 printf("ERROR\n");
	 } 
}


void isVoid(char *str, char NumLine) /// void fgcg(){    // void cfgc()  ;  
{
	int semicolon = 0, bracket1 = 0, bracket2 = 0, flag = 0, i=5;
	
   str = trim_space (str);
    // Proper usage of "for" keyword checked 
    while(i != strlen(str)) 
    { 
        char ch = str[i]; 
        if(ch == '(') 
        { 
			bracket1 ++; 
        }
		else if(ch == ')') 
        { 
			bracket2 ++; 
        }
		   else if(ch == ';') 
        { 
            semicolon ++; 
        }
       	
        
		i++;
	}
    
    // no error  
    if(bracket1 == 1 && bracket2 == 1 && semicolon <= 1)
	{/*  printf("\nNo error");*/} 

     else
	 {
		 printf ("line %d: ",NumLine) ;
		 printf("ERROR\n");
	 } 
}

                                                                                                
void isInt_Ch_Fl_D (char *str, char index, char NumLine)   // int hfg; // int jhfhgf(); /// int hgng(){  /// int hgh,ygh ; /// int jgj      jgjh ;
{
	char semicolon = 0, bracket1 = 0, bracket2 = 0, carelyBracket = 0, 
	comma = 0, space = 0, flag = 0, i, k=0;
	int res;
	
	switch(index)
	{
		case 2: i=4 ;    //int
                break;
				
		case 3: i=5 ;  ///char
                break;
				
		case 4: i=6 ;  //float
                break;
				
		case 5: i=7 ; //double     jgjh
		        break;
	}
  
      str += i; // ahmed hgj;
	   FirstWord(str);
        	   
     res= discoverWord();  
    	 i=0;
	  if (res==111)           /// auto int ghjfhg;
	  {
		 if(arr[0]== '*')
		 {
			 // printf("IT is pointer\n");
			i=1;
		 }
			 
			 while(k<10)
			 {
				if(arr[0] == arrNumber[k])
				{
					printf ("line %d: ",NumLine) ;
					printf("ERROR: in naming convension 1\n");
				}
               k++;				
			  }
			  
		  for(i=1 ; i<strlen(arr); i++)  // *8j*%&gj hgjh_hvgfv
		  {
			  k=0;
			  while(k<21)
			 {
			    if(arr[i] == arrchar[k] )
				{
					printf ("line %d: ",NumLine) ;
					printf("ERROR: in naming convension 2\n");
				}
				k++;
			  }
		  }
		 
	  }
	  else
	  {
		  printf ("line %d: ",NumLine) ;
		  printf("ERROR: two C keyword \n");
		  // AllFunctions(str ,res, NumLine);
	  }
    while(i != strlen(str)) 
    { 
        char ch = str[i]; 
        if(ch == '(') 
        { 
			bracket1 ++; 
        }
		else if(ch == ')') 
        { 
			bracket2 ++; 
        }
		   else if(ch == ';') 
        { 
            semicolon ++; 
        }
        else if(ch == '{') 
        { 
            carelyBracket ++; 
        }	
        else if(ch == ',') 
        { 
            comma ++; 
        }
		else if((str[i] == ' ')&&(str[i+1] != '(')&&(str[i+1] != ')')&&(str[i+1] != '{')&&(str[i+1] != '}')&&(str[i+1] != '[')
			    &&(str[i+1] != ']')&&(str[i+1] != ';')&&(str[i+1] != '#')&&(str[i+1] != ' '))
        { 
            space ++; 
        }		
        
		i++;
	}
	

	 if(
		 (bracket1==1 && bracket2==1 && semicolon==1 && carelyBracket==0 )||
		 (bracket1==1 && bracket2==1 && semicolon==0 && carelyBracket==1 )||
		 (bracket1==0 && bracket2==0 && semicolon==1 && carelyBracket==0 && (space <1)))
	 {/* printf("No error\n");*/} 

     else
	 {
		 printf ("line %d: ",NumLine) ;
		 printf("ERROR\n");
	 }
	
}


void isWh_Sw_If_sizeof (char *str, char index, char NumLine) // while ()   while(gjg,;<"")  //switch() ; 
{
	int bracket1 = 0, bracket2 = 0, i;
	
   str = trim_space (str);
   	switch(index)
	{
		case 6: i=6 ;    //while
                break;
				
		case 11: i=7 ;  ///switch
                break;
				
		case 13: i=3 ;  //if
                break;
				
		case 22: i=7 ;  //sizeof
                break;

	}
	  while(i != strlen(str)) 
    { 
        char ch = str[i]; 
        if(ch == '(') 
        { 
            // opening parenthesis count 
            bracket1 ++; 
        } 
        else if(ch == ')') 
        { 
            // closing parenthesis count 
            bracket2 ++; 
              
        } 
        i++;
    } 
	
	if(bracket1 ==  bracket2  )      
	{ 
		// printf("\nNo error");
	} 
    else
	{
		printf ("line %d: ",NumLine) ;
		printf("ERROR\n");
	} 
}

void isBr_Con_Re (char *str, char index, char NumLine) // break ;   //continue; // return jkhjh;
{
   int semicolon = 0, i=5;
	
   str = trim_space (str);
   	switch(index)
	{
		case 8: i=6 ;    //break
                break;
				
		case 10: i=9 ;  ///continue
                break;
				
		case 12: i=7 ;  //return
                break;
	}
	  while(i != strlen(str)) 
    { 
        char ch = str[i]; 
        if(ch == ';') 
        { 
            // opening parenthesis count 
            semicolon ++; 
        } 
        i++;
    } 
	
	if(semicolon == 1)
	{ 
		// printf("\nNo error");
	} 
    else
	{
		printf ("line %d: ",NumLine) ;
		printf("ERROR\n");
	} 
	
}


void isCase (char *str, char NumLine) ///   case       7 : ugjyghg;   // case 'y' : {jghfgf; break; }
{
   int semicolon = 0, colon = 0, flag = 0, i = 4;
	
   str = trim_space (str);
   
	  while(i != strlen(str)) 
    { 
		
        char ch = str[i]; 
        if(ch == ';') 
        { 
            // opening parenthesis count 
            semicolon ++; 
        } 
		else if(ch == ':') 
        { 
            // opening parenthesis count 
            colon ++; 
        }
		else if(ch == ' ') 
        { 
			while(isspace(str[i]))
			{
				str = str+1;
			}
			if(*str != ':')
			{
				flag++;
			}
		}
		else if(str[strlen(str) - 1] != ';' && str[strlen(str) - 1] != ':') 
		{  
			flag++; 
		}
     
        i++;
    } 
	
	if(semicolon == 1 && colon == 1 && flag==0)
	{ 
		// printf("\nNo error");
	} 
    else
	{
		printf ("line %d: ",NumLine) ;
		printf("ERROR\n");
	} 	
}

void isTypedef (char *str, char NumLine) // typedef hfg ;
{
   
	int res;
   str = trim_space (str);
   str += 7;
	   FirstWord(str);
        	   
      res= discoverWord();
	  if (res==500)
	  {
		  printf ("line %d: ",NumLine) ;
		  printf("ERROR\n");
	  }
	  else
	  {
		  // printf("NO Error\n");
	  }

}


void is_sub_words(char *str, char index, char NumLine) ///auto ahmed hkjh;
{
    
	       int i, res ;
	
	switch(index)
	{
		case 32: i=4 ;    //auto
                break;
				
		case 31: i=6 ;  ///extern
                break;
				
		case 30: i=8 ;  //volatile
                break;
				
		case 29: i=8 ; //unsigned
		        break;
		
		case 28: i=6 ;  //signed
		        break;
				
		case 27: i=5 ;  //short
		        break;
				
		case 26: i=6 ;  //static
		        break;
				
		case 25: i=8 ;  //register
		        break;
				
		case 24: i=5 ;   //const
		        break;
				
		case 23: i=4 ;  //long
		        break;
				
		
	}
	
	   str += i; // ahmed hgj;
	   FirstWord(str);
        	   
     res= discoverWord();  
    	 
	  if (res==111)           /// auto int ghjfhg;
	  {
		 printf ("line %d: ",NumLine) ; 
		 printf("ERROR\n");
	  }
	  else
	  {
		  AllFunctions(str ,res, NumLine);
	  }
}


void AllFunctions(char *line , char index, char NumLine)
{
    switch (index)
	{
		case  0: isInclude(line,NumLine); 
		         break;
				
		case  1: isVoid(line,NumLine);  
		         break;
				 
		case  2: isInt_Ch_Fl_D(line,2,NumLine); 
		         break;
				 
		case  3: isInt_Ch_Fl_D(line,3,NumLine); 
		         break;
				 
		case  4: isInt_Ch_Fl_D(line,4,NumLine); 
		         break;
		  
		case  5: isInt_Ch_Fl_D(line,5,NumLine); 
		         break;
				 
		case  6: isWh_Sw_If_sizeof(line,6,NumLine); 
		         break;
				 
		case  7: isFor(line,NumLine);
		          break;
				  
	    case  8: isBr_Con_Re(line,8,NumLine); 
				 break;

		case  9: isCase(line,NumLine);  
				 break;
				 
		case 10: isBr_Con_Re(line,10,NumLine);  
				 break;
				 
		case 11: isWh_Sw_If_sizeof(line,11,NumLine);  
				 break;
				 
		case 12: isBr_Con_Re(line,12,NumLine); 
				 break;

		case 13: isWh_Sw_If_sizeof(line,13,NumLine); 
				 break;
				 
		case 14: isDo_else(line, 14,NumLine); 
				 break;
				 
		case 15: isDo_else(line, 15,NumLine); 
				 break;
				 
		case 16: isst_un_enu(line, 16,NumLine); 
				 break;
				 
		case 17: isst_un_enu(line, 17,NumLine); 
				 break;
				 
		case 18: isst_un_enu(line, 18,NumLine); 
				 break;
				 
		case 19: isTypedef(line,NumLine); 
			     break;
				 
		case 20: isGoto_default(line, 20,NumLine); 
				 break;
				 
		case 21: isGoto_default(line, 21,NumLine); 
				 break;

		case 22: isWh_Sw_If_sizeof (line, 22,NumLine); 
		         break;
				 
		case 23:is_sub_words(line,23,NumLine); 
		         break;
				 
		 case 24:is_sub_words(line,24,NumLine); 
		         break;
				 
		 case 25:is_sub_words(line,25,NumLine); 
		         break;
				 
		 case 26:is_sub_words(line,26,NumLine); 
		         break;
				 
		 case 27:is_sub_words(line,27,NumLine);  
		         break;
				 
		 case 28:is_sub_words(line,28,NumLine);  
		         break;
				 
		 case 29:is_sub_words(line,29,NumLine);  
		         break;
				 
		 case 30:is_sub_words(line,30,NumLine);  
		         break;
				 
		 case 31:is_sub_words(line,31,NumLine);  
		         break;
				 
		 case 32:is_sub_words(line,32,NumLine);   
		         break;
	}
}


void isDo_else(char *str, char index, char NumLine)
{
	char i;
	 str = trim_space (str);//do
	 switch(index)
	{
		case 14: i=2 ;    //do
                break;
				
		case 15: i=4 ;  ///else
                break;
	}
   
	if(str[i]!='\0')
	{
		printf ("line %d: ",NumLine) ;
		printf("ERROR\n");
	}
	else
	{
		// printf("NO error\n");		
	}
}


void isst_un_enu(char *str, char index, char NumLine)

{
	char i;
	int res=0;
	 str = trim_space (str);
	 
	 switch(index)
	{
		case 16: i=6 ;    //struct
                break;
				
		case 17: i=5 ;  ///union
                break;
			
		case 18: i=4 ;  ///enum 
                break;
	}
	if(str[i]==' ')  // struct
	{
		FirstWord(str);
		res= discoverWord();
		printf("res %d",res);
	}
   
	if((str[i]=='\0' )|| (res == 111))  //struct    //struct jgjhg
	{
		// printf("No error\n");
	}
	else
	{
		printf ("line %d: ",NumLine) ;
		printf("ERROR\n");		
	}
}


void isGoto_default(char *str, char index, char NumLine)
{
	int i ;
	
	str = trim_space (str);
	                     //int ghjg
	
	switch(index)
	{
		case 20: i=5 ;    //goto
                break;
				
		case 21: i=8 ;  ///default
                break;
	}
	str = str+i ; 
	
		while(isspace(*str))
		{
			str = str+1  ;
		}
	
        if(*str == ':') 
        { 
			// printf("No error\n");
        }
		else
		{
			printf ("line %d: ",NumLine) ;
			printf("ERROR\n");		
		}
}

#endif