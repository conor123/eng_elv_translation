/*
	Important: this file has been editied with comments only.
	The code has not been changed
	However, use the original file before submitting!!!

*/

#include <iostream>
#include <fstream>
#include "Translator.h"

using namespace std;

// maximum number of characters in a line of the text
const int MAXLINE=1000;
int main(int argc, char *argv[])
{
	if (argc<2)
	{
		cout << "No story file specified." << endl;
		return -1;
	}

	fstream infile;
	
	infile.open(argv[1], ios::in);

	if (infile.fail())
	{
		cout << "Could not open the story file." << endl;
		return -1;
	}
	// The constructor passes the disctionary to the translator object
	Translator translator("englishtoelvish.txt");
	
	fstream outfile;
	
	outfile.open("story_in_elvish.txt", ios::out);
	
	if (outfile.fail())
	{
		cout << "Could not open the output file." << endl;
		return -1;
	}
	// Two arrays for the translation lines
	char english_line[MAXLINE], elvish_line[MAXLINE];

	// Translate the story into Elvish
	while (!infile.fail())
	{
		// Get a line
		infile.getline(english_line, MAXLINE, '\n');
		if (!infile.fail())
		{
			// translate a line
			translator.toElvish(elvish_line, english_line);
			// write the line to file
			outfile << elvish_line << endl;
		}
	}
	// Close the files
	outfile.close();
	infile.close();

	// Read in the translated story and re-translate into English
	infile.open("story_in_elvish.txt", ios::in);
	outfile.open("story_backto_english.txt", ios::out);
	
	while (!infile.eof())
	{
		// As before get a line
		infile.getline(elvish_line, MAXLINE, '\n');
		if (!infile.fail())
		{
			// Translate
			translator.toEnglish(english_line, elvish_line);
			// Write to file
			outfile << english_line << endl;
		}
	}
	// Close files
	infile.close();
	outfile.close();
}