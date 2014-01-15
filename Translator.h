const int MAX_NUM_WORDS=2000;
const int MAX_WORD_LEN=50;

class Dictionary
{

 public:
  // Constructor 
  Dictionary(const char dictFileName[]);
  // Translate member function
  void translate(char out_s[], const char s[]); // s represents a word & out_s, the translated word
  //void translate_rev(char out_s[], const char s[]); // s represents a word & out_s, the translated word
 private:
  char englishWord[MAX_NUM_WORDS][MAX_WORD_LEN];
  char elvishWord[MAX_NUM_WORDS][MAX_WORD_LEN];
  int numEntries;
};

class Dictionary2
{

 public:
  // Constructor 
  Dictionary2(const char dictFileName[]);
  // Translate member function
  void translate(char out_s[], const char s[]); // s represents a word & out_s, the translated word
  //void translate_rev(char out_s[], const char s[]); // s represents a word & out_s, the translated word
 private:
  char englishWord[MAX_NUM_WORDS][MAX_WORD_LEN];
  char elvishWord[MAX_NUM_WORDS][MAX_WORD_LEN];
  int numEntries;
};

class Translator
{
 public:
  // Constructor
  Translator(const char s[]);
  void toElvish(char out_s[], const char s[]);
  void toEnglish(char out_s[], const char s[]);

 private:
  // Dictionary Data Structure 
  Dictionary dict;
  Dictionary2 dict2;
};
