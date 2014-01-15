#include <iostream>
#include <fstream>
//#include <string>
#include <cstring>
#include <cstdlib>
//#include <vector>
#include <cctype>
#include "Translator.h"
// maximum number of characters in a line of the text
const int MAXLINE=1000;
using namespace std;

// Load Dictionary 1
Dictionary::Dictionary(const char dictFileName[])
{
  fstream str;
  str.open(dictFileName, ios::in);

  int i=0;
  
  str >> englishWord[i];
  str >> elvishWord[i];
  
  while (!str.eof())
    {
      str >> englishWord[i];
      str >> elvishWord[i];
      i++;
    }
   numEntries=i;
    // Bubble Sort Algorithm
	string temp;
	// Loop through array
	for(int i=0; i<numEntries-1; i++)
	{
		// The inner loop compares the item held in the outer array, with all other suceeding elements
		for(int j=i+1; j<numEntries; j++)
		{
			// If it is lesser...
			if(strcmp(englishWord[i], englishWord[j])>0) // comparison between two adjacent array elements
			{
				// ... swap English Word
				temp=englishWord[i]; // holder holds the value temporarily
				strcpy(englishWord[i], englishWord[j]);
				strcpy(englishWord[j], temp.c_str());
				// ... swap Elvish Word
				temp=elvishWord[i]; // holder holds the value temporarily
				strcpy(elvishWord[i], elvishWord[j]);
				strcpy(elvishWord[j], temp.c_str());
			
			}
		}
	}
	  
	
 
  cout << "\nDictionary 1 Loaded Ok!!!\n";
  // testing Dictionary - Remove after done!!!
  /*
  for(i=0;i<numEntries;i++)
  {
	cout << englishWord[i] << " ";
	cout << elvishWord[i] << endl;
  }
  */
  // ? close Disctionary
  str.close();
}
// Load Dictionary 2
Dictionary2::Dictionary2(const char dictFileName[])
{
  fstream str;
  str.open(dictFileName, ios::in);

  int i=0;
  
  str >> englishWord[i];
  str >> elvishWord[i];
  while (!str.eof())
    {
      str >> englishWord[i];
      str >> elvishWord[i];
      i++;
    }
    numEntries=i;
    // Bubble Sort Algorithm
	string temp;
	// Loop through array
	for(int i=0; i<numEntries-1; i++)
	{
		// The inner loop compares the item held in the outer array, with all other suceeding elements
		for(int j=i+1; j<numEntries; j++)
		{
			// If it is lesser...
			if(strcmp(elvishWord[i], elvishWord[j])>0) // comparison between two adjacent array elements
			{
				// ... swap English Word
				temp=elvishWord[i]; // holder holds the value temporarily
				strcpy(elvishWord[i], elvishWord[j]);
				strcpy(elvishWord[j], temp.c_str());
				// ... swap Elvish Word
				temp=englishWord[i]; // holder holds the value temporarily
				strcpy(englishWord[i], englishWord[j]);
				strcpy(englishWord[j], temp.c_str());
			
			}
		}
	}
	  
	
 
  cout << "\nDictionary 2 Loaded Ok!!!\n";
  // testing Dictionary - Remove after done!!!
  /*
  for(i=0;i<numEntries;i++)
  {
	cout << englishWord[i] << " ";
	cout << elvishWord[i] << endl;
  }
  */
  // ? close Disctionary
  str.close();
}

// Translator Constructor
Translator::Translator(const char dictFileName[]) : dict(dictFileName), dict2(dictFileName)
{

}

// Dictionary translation from English to Elvish member function
void Dictionary::translate(char out_s[], const char s[])
{
  
	// Implement binary search below
	int bottom=0, middle, top=numEntries-1, index;
	bool found = false;

	// Binary Search
	while(bottom <= top && !found)
	{
		middle = bottom+(top-bottom)/2;
		if(strcmp(englishWord[middle], s)==0)
			found = true;
		else 
		if(strcmp(englishWord[middle], s)>0)
				top = middle-1;
		else
			bottom = middle+1;		
	}
	if(found)
		index=middle;
	else index=-1;

	// Result
	if(index>=0)
	{
		strcpy(out_s, elvishWord[index]);
	}
	else
	{
		out_s[0] = '\0';
		strcat(out_s, "*");
		strcat(out_s, s);
		strcat(out_s, "*");
	}



  // Linear search dictionary translate
  /*
  int i;
  for (i=0;i<numEntries;i++)
    {
      if (strcmp(englishWord[i], s)==0)
	break;
    }
  if (i<numEntries)
    strcpy(out_s, elvishWord[i]);
  */	
  // what do I do if I didn't find the word?
  // might want another parameter or return value what
  // indicates that the word wasn't found
}

// Dictionary translation from Elvish back to English member function
void Dictionary2::translate(char out_s[], const char s[])
{
  
  // Implement binary search below
  int bottom=0, middle, top=numEntries-1, index;
			bool found = false;
			
			// Binary Search
			while(bottom <= top && !found)
			{
				middle = bottom+(top-bottom)/2;
				if(strcmp(elvishWord[middle], s)==0)
					found = true;
				else 
				if(strcmp(elvishWord[middle], s)>0)
						top = middle-1;
				else
					bottom = middle+1;		
			}
			if(found)
				index=middle;
			else index=-1;
			
			// Result
			if(index>=0)
			{
				strcpy(out_s, englishWord[index]);
			}
			else
			{

				//strcpy(out_s, s);
				int i=0;
				for(i=0;i<strlen(s);i++)
				{
					out_s[i]=s[i+1];
					
				}
				out_s[i-2]='\0';

			}
			
}


// NOTE!!! Translator ENGLISH to ELVISH Member Function
void Translator::toElvish(char translatedLine[], const char lineToTranslate[])
{
	/*
	static int line=0;
	cout << "\nBeginning Translation: Line: " << line++ << endl;
	*/
	// The words we send into and get out of the dictionary
	char word_in[MAX_WORD_LEN]="";
	char word_out[MAX_WORD_LEN]="";
	// Stores the translated line during construction
	char temp_line[MAXLINE]="";
	// Word counter
	int i=0;
	// Line counter
	int j=0;

	for(j=0;j<=((strlen(lineToTranslate)));j++)
	{
		
		// Pull out a word if until space or end of line
		if(lineToTranslate[j]!=' ' && lineToTranslate[j]!='\0' && lineToTranslate[j]!='\?' && lineToTranslate[j]!='!' && lineToTranslate[j]!=',' && lineToTranslate[j]!='.' && lineToTranslate[j]!='\'' && lineToTranslate[j]!='\"')
		{
			
			//
			if(lineToTranslate[j]>='A' && lineToTranslate[j]<='z' || lineToTranslate[j]=='-' || lineToTranslate[j]=='*' && lineToTranslate[j]!=' ')
			{
				word_in[i]=lineToTranslate[j];
				i++;
			}
			
		}
		// Translate word and concat to temp line
		else
		{
			// Write end of string char
			
				word_in[i]='\0';
			
			// Note !!!! This creates the extra space, so watch it
			//if(strlen(word_in)<1)
			//	break;
			
			// Check !!!
			//cout << "Word In: " << word_in << endl;
					
			// Translate word
			
			
			if(isupper(word_in[0]))
			{
				word_in[0] = tolower(word_in[0]);
				dict.translate(word_out, word_in);
				// !!! check
				//cout << "\n Word out: " << word_out;
				if(word_out[0]=='*')
				{
					word_out[1] = toupper(word_out[1]);
				}
				else word_out[0] = toupper(word_out[0]);
			}
			
			/*
			if(isupper(word_in[0]))
			{
				word_in[0] = tolower(word_in[0]);
				dict.translate(word_out, word_in);
				word_out[0] = toupper(word_out[0]);
			}
			*/
			else
			{
				dict.translate(word_out, word_in);
			}
			
			// concat translated word to line
			strcat(temp_line, word_out);
			// reset word counter
			i=0;
			
		}
		// Handles spaces
		if(lineToTranslate[j]==' ')
		{
			strcat(temp_line, " ");
		}
		// Handles ?
		if(lineToTranslate[j]=='\?')
		{
			strcat(temp_line, "?");
		}
		// Handles !
		if(lineToTranslate[j]=='!')
		{
			strcat(temp_line, "!");
		}
		// Handles ,
		if(lineToTranslate[j]==',')
		{
			strcat(temp_line, ",");
		}
		// Handles .
		if(lineToTranslate[j]=='.')
		{
			strcat(temp_line, ".");
		}
		// Handles '
		if(lineToTranslate[j]=='\'')
		{
			strcat(temp_line, "\'");
		}
		// Handles "
		if(lineToTranslate[j]=='\"')
		{
			strcat(temp_line, "\"");
		}
		
		
	}
	// Copy the temp line to the translated line for return and output
	strcpy(translatedLine, temp_line);
}

// Translator BACK TO ENGLISH !!!
void Translator::toEnglish(char translatedLine[], const char lineToTranslate[])
{
	char word_in[MAX_WORD_LEN]="";
	char word_out[MAX_WORD_LEN]="";
	// Stores the translated line during construction
	char temp_line[MAXLINE]="";
	// Word counter
	int i=0;
	// Line counter
	int j=0;

	for(j=0;j<=((strlen(lineToTranslate)));j++)
	{
		
		// Pull out a word if until space or end of line
		if(lineToTranslate[j]!=' ' && lineToTranslate[j]!='\0' && lineToTranslate[j]!='\?' && lineToTranslate[j]!='!' && lineToTranslate[j]!=',' && lineToTranslate[j]!='.' && lineToTranslate[j]!='\'' && lineToTranslate[j]!='\"')
		{
			
			//
			if(lineToTranslate[j]>='A' && lineToTranslate[j]<='z' || lineToTranslate[j]=='-' || lineToTranslate[j]=='*' && lineToTranslate[j]!=' ')
			{
				word_in[i]=lineToTranslate[j];
				i++;
			}
			
		}
		// Translate word and concat to temp line
		else
		{
			// Write end of string char
			
				word_in[i]='\0';
			
			// Note !!!! This creates the extra space, so watch it
			//if(strlen(word_in)<1)
			//	break;
			
			// Check !!!
			//cout << "Word In: " << word_in << endl;
					
			// Translate word
			
			
			if(isupper(word_in[0]))
			{
				word_in[0] = tolower(word_in[0]);
				dict2.translate(word_out, word_in);
				// !!! check
				//cout << "\n Word out: " << word_out;
				if(word_out[0]=='*')
				{
					word_out[1] = toupper(word_out[1]);
				}
				else word_out[0] = toupper(word_out[0]);
			}
			
			/*
			if(isupper(word_in[0]))
			{
				word_in[0] = tolower(word_in[0]);
				dict.translate(word_out, word_in);
				word_out[0] = toupper(word_out[0]);
			}
			*/
			else
			{
				dict2.translate(word_out, word_in);
			}
			
			// concat translated word to line
			strcat(temp_line, word_out);
			// reset word counter
			i=0;
			
		}
		// Handles spaces
		if(lineToTranslate[j]==' ')
		{
			strcat(temp_line, " ");
		}
		// Handles ?
		if(lineToTranslate[j]=='\?')
		{
			strcat(temp_line, "?");
		}
		// Handles !
		if(lineToTranslate[j]=='!')
		{
			strcat(temp_line, "!");
		}
		// Handles ,
		if(lineToTranslate[j]==',')
		{
			strcat(temp_line, ",");
		}
		// Handles .
		if(lineToTranslate[j]=='.')
		{
			strcat(temp_line, ".");
		}
		// Handles '
		if(lineToTranslate[j]=='\'')
		{
			strcat(temp_line, "\'");
		}
		// Handles "
		if(lineToTranslate[j]=='\"')
		{
			strcat(temp_line, "\"");
		}
		
		
	}
	// Copy the temp line to the translated line for return and output
	strcpy(translatedLine, temp_line);
}