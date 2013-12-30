#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "Translator.h"

using namespace std;

// Constructor
// Takes dictionary filename
Translator::Translator(const char filename[])
{
	loadDictionary(filename);
}

// Translator to Elvish
void Translator::toElvish(char translatedLine[], const char lineToTranslate[])
{

}

// Translator to English
void Translator::toEnglish(char translatedLine[], const char lineToTranslate[])
{

}

// Load Dictionary
void Translator::loadDictionary(const char filename[])
{
	// Load Dictionary
	fstream dictofile;
	string eng_word, elv_word;
	
	dictofile.open(filename, ios::in);

	if (dictofile.fail())
	{
		cout << "Could not open the dictionary file." << endl;
		exit;
	}
	// Write words to data structure for search
	
	int i=0;
	while (!dictofile.fail())
	{
		// Input
		dictofile >> end_dict.push_back(eng_word) >> elv_dict.push_back(elv_word);
		
		i++;
	}
	// Output dictionary
	for(i=0;i<DICTOMAX;i++){
		cout << eng_dict[i] << "\t" << elv_dict[i];
	}
	
	// Test input
	//dictofile >> eng_word >> elv_word;
	
	// Test
	cout << eng_word << elv_word;
	
	
	// Close file
	dictofile.close();
}
