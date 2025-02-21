/* 
-------------------------------------------------------------------------
Name:     		
Date: 			
Project #:		Exam 3 Project
Status: 		WIP
Class:			COSC 1337

-------------------------------------------------------------------------
Projct Objectives:


-------------------------------------------------------------------------
*/

// Compiler directives Header
#include "header.h"
using namespace std;

class Dictionary
{
	private:
		string english;
		string spanish;
		
		string toLower(string input)
		{
			string lowerCase;
			
			for (int index = 0; index < input.length(); index++)
			{
				lowerCase += tolower(input[index]);
			}
			
			return lowerCase;
		}
	public:
		//initialize
		Dictionary()
		{
			english = "";
			spanish = "";
		}
		
		// setters
		void setDictionary(string newEnglish, string newSpanish)
		{
			
			english = toLower(newEnglish);
			spanish = toLower(newSpanish);
		}
		
		// getteres
		string getEnglish()
		{
			return english;
		}
		
		string getSpanish()
		{
			return spanish;
		}
		
		bool checkAnswer(string answer)
		{
			string lowerAnswer;
			lowerAnswer = toLower(answer);
			if (lowerAnswer == spanish)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
};

// Decleration of prototype 
int loadDictionary(Dictionary*);
void menuLoop(Dictionary*, int);
bool quizLoop(Dictionary*, int, int&, int&, string, ofstream&, float&);
int createRandomNumbers(int);
bool askQuestion(Dictionary*, int, ofstream&);

int main()
{
	srand(time(0));
	// Displays start of project 
	projectStart();
	
	
	int wordCount;
	
	Dictionary *myDictionary; // pointer of a struct
	// wasn't sure if we needed to account for 100 words total (50 pairs of words), or 100 vocab words (100 pairs of words)
	// went with higher value
	myDictionary = new Dictionary[100]; 
	
	wordCount = loadDictionary(myDictionary);
	cout << wordCount << endl;
	
	menuLoop(myDictionary, wordCount);
	
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main


int loadDictionary(Dictionary* myDictionary)
{
	int wordCounter = 0;
	int lineCounter = 0;
	string english;
	string spanish;
	
	ifstream fileRead;
    fileRead.open("dictionary.txt");
    
    if (!(fileRead)) // invalid file
    {
    	cout << "CRITICAL ERROR: Failure Reading dictionary.txt in loadDictionary()" << endl;
        return 0;
    } // end of invalid file
    else // valid file
    {
    	cout << endl;
		cout << "Reading dictionary.txt" << endl;
		cout << endl;
		
		while (!(fileRead.eof())) // read to end of file
		{
			if (wordCounter == 100) // max words
			{
				break;
			}
			
			getline(fileRead, english);
			if (fileRead.eof())
            {
                break;
            }
            lineCounter++;
			getline(fileRead, spanish);
			lineCounter++;
			
			myDictionary -> setDictionary(english, spanish);
			wordCounter++;
			myDictionary++;
		}
		return wordCounter;
	}
}

void menuLoop(Dictionary* myDictionary, int wordCount)
{
	bool continueLoop = true;
	string name;
	int totalQuestions = 0;
	int totalCorrect = 0;
	int attempted = 0;
	float highestPercent = 0;
	ofstream quizSummary;
	quizSummary.open("quizSummary.txt"); //opens report file to write
	
	cout << "Welcome to the Ally Baba English-Spanish Class." << endl;
	cout << endl;
	name = getStringData("Please enter your name: ");
	quizSummary << "Quiz Summary for " << name << endl;
	quizSummary << dashes << endl;
	cout << endl;
	while (continueLoop)
	{
		continueLoop = quizLoop(myDictionary, wordCount, totalQuestions, totalCorrect, name, quizSummary, highestPercent);
	}
	
	cout << dashes << endl;
	cout << "FINAL QUIZ SUMMARY" << endl;
	cout << dashes << endl;
	attempted = totalQuestions + totalCorrect;
	cout << "\tQuizzes Attempted: " << attempted << endl;
	cout << "\tQuizzes Passed: " << totalCorrect << endl;
	cout << "\tQuizzes Failed: " << totalQuestions << endl;
	
	// final summary here
}

bool quizLoop(Dictionary* myDictionary, int wordCount, int& totalQuestions, int& totalCorrect, string name, ofstream& quizSummary, float& highestPercent)
{
	int questionCount;
	int randomQuestion;
	bool questionCorrect;
	int correctCounter = 0;
	bool questionAsked[wordCount];
	float percent;
	int incorrect;
	char retake;
	
	for (int ctr = 0; ctr < wordCount; ctr++)
	{
		questionAsked[ctr] = false;
	}
	
	cout << "Maximum available questions in the Quiz: " << wordCount << " words." << endl;
	questionCount = getIntegerData("How many questions would you like to be quizzed on? ");
	
	while (questionCount < 1 || questionCount > wordCount)
	{
		cout << "Please enter a valid number of questions between 1 and " << wordCount << endl;
		questionCount = getIntegerData("How many questions would you like to be quizzed on? ");
	}
	
	cout << dashes << endl;
	cout << "Quiz" << endl;
	cout << dashes << endl;
	
	cout << questionCount << endl;
	
	for (int questionCounter = 1; questionCounter <= questionCount; questionCounter++)
	{
		 
		randomQuestion = createRandomNumbers(wordCount);
		while (questionAsked[randomQuestion])
		{
			randomQuestion = createRandomNumbers(wordCount);
		}
		cout << "Question " << questionCounter << endl;
		quizSummary << "Question " << questionCounter << endl;
		
		
		questionCorrect = askQuestion(myDictionary, randomQuestion, quizSummary);
		questionAsked[randomQuestion] = true;
		
		if (questionCorrect)
		{
			cout << "\tResult: CORRECT!" << endl;
			quizSummary << "\tResult: CORRECT!" << endl;
			quizSummary << dashes << endl;
			cout << dashes << endl;
			correctCounter++;
		}
		else
		{
			cout << "\tResult: Incorrect." << endl;
			cout << dashes << endl;
			quizSummary << "\tResult: Incorrect." << endl;
			quizSummary << dashes << endl;
		}
		
	}
	
	percent = 100 * correctCounter / questionCount;
	incorrect = questionCount - correctCounter;
	cout << endl;
	cout << "Name: " << name << endl;
	cout << "\tNumber of questions in the quiz: " << questionCount << endl;
	cout << "\tNumber of questions correct: " << correctCounter << endl;
	cout << "\tYour percent grade: " << percent << "%" << endl;
	
	quizSummary << endl;
	quizSummary << "Name: " << name << endl;
	quizSummary << "\tNumber of questions in the quiz: " << questionCount << endl;
	quizSummary << "\tNumber of questions correct: " << correctCounter << endl;
	quizSummary << "\tYour percent grade: " << percent << "%" << endl;
	if (percent >= 80)
	{
		cout << "Decision: PASSED! The passing score is 80%." << endl;
		quizSummary << "Decision: PASSED! The passing score is 80%." << endl;
		cout << endl;
		totalCorrect++;
	}
	else 
	{
		cout << "Decision: Failed. The passing score is 80%." << endl;
		quizSummary << "Decision: Failed. The passing score is 80%." << endl;
		cout << endl;
		totalQuestions++;
	}
	
	if (percent > highestPercent)
	{
		highestPercent = percent;
	}
	
	retake = getCharData("Do you want to take the quiz again (Y/N): ");
	cout << dashes << endl;
	
	if (retake == 'Y')
	{
		return true;
	}
	else 
	{
		return false;
	}
	
}

int createRandomNumbers(int wordCount)
{ 
	int random;
	
	random = rand() % wordCount + 1; 
	random -= 1;
	return random;
}

bool askQuestion(Dictionary* myDictionary, int questionIndex, ofstream& quizSummary)
{
	string answer;
	bool correct = false;
	
	myDictionary += questionIndex;
	cout << "\tEnglish word: " << myDictionary -> getEnglish() << endl;
	quizSummary << "\tEnglish word: " << myDictionary -> getEnglish() << endl;
	answer = getStringData("\tYour answer in Spanish: ");
	quizSummary << "\tYour answer in Spanish: " << answer << endl;
	
	correct = myDictionary -> checkAnswer(answer);
	
	return correct;
}                                          