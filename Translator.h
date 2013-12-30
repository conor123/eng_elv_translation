//
const int DICTOMAX =1750;
const int WORDMAX =20;
const int vsize = 100;
const int initialValue = 0;
// Class Declaration
class Translator{

public:
	// Constructor
	Translator(const char filename[]);
	// Translator to Elvish
	void toElvish(char translatedLine[], const char lineToTranslate[]);
	// Translator to Elvish
	void toEnglish(char translatedLine[], const char lineToTranslate[]);
	// Load Dictionary
	void loadDictionary(const char filename[]);

private:
	// Multigrid array
	vector<string> eng_dict;
	vector<string> elv_dict;
};