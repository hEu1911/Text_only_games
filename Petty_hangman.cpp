#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

string get_random_word(vector<string> &words);
void play();

vector<string> words = {"programming", "hangman", "games", "ship", "dodge", "die", "new vegas", "gender", "war", "never", "changes", "fallout", "brotherhood", "steel", "railroad", "fighter", "destruction", "hallow", "aileron", "book" };

string hangman_art[7] = {
				" +---+\n"
				" |   |\n"
				"     |\n"
				"     |\n"
				"     |\n"
				"     |\n"
				"==========",
				" +---+\n"
				" |   |\n"
				" O   |\n"
				"     |\n"
				"     |\n"
				"     |\n"
				"==========",
				" +---+\n"
				" |   |\n"
				" O   |\n"
				" |   |\n"
				"     |\n"
				"     |\n"
				"==========",
				" +---+\n"
				" |   |\n"
				" O   |\n"
				"/|   |\n"
				"     |\n"
				"     |\n"
				"==========",
				" +---+\n"
				" |   |\n"
				" O   |\n"
				"/|\\  |\n"
				"     |\n"
				"     |\n"
				"==========",
				" +---+\n"
				" |   |\n"
				" O   |\n"
				"/|\\  |\n"
				"/    |\n"
				"     |\n"
				"==========",
				" +---+\n"
				" |   |\n"
				" O   |\n"
				"/|\\  |\n"
				"/ \\  |\n"
				"     |\n"
				"=========="};

int main()
{
	srand(time(0));
	cout << "Welcome to Hangman!\n";
	play();

	return 0;
}
void play()
{	
	string secret_word = get_random_word(words);
	string guess_word = secret_word;
	for (int i = 0; i < secret_word.length(); ++i)
	{
		guess_word[i] = '_';
	}
	int try_no = 0;
	char guess;

	while (true)
	{
		cout << hangman_art[try_no] << endl;
		cout << guess_word << endl
			 << endl;
        //added tips line:
		cout << "Hint: The word has " << secret_word.length() << " letters!" << endl;
		//-------
		cout << "Enter your guess:" << endl;
		cin >> guess;

		if (secret_word.find(guess) != string::npos)
		{
			for (int i = 0; i < guess_word.length(); ++i)
			{
				if (secret_word[i] == guess)
				{
					guess_word[i] = guess;
				}
			}
			if (secret_word == guess_word)
			{
				cout << hangman_art[try_no] << endl;
				cout << guess_word << endl;
				cout << "You win! The word was " << secret_word << endl;
				break;
			}
		}
		else
		{
			++try_no;
		}
		if (try_no >= 6)
		{
			cout << hangman_art[try_no] << endl;
			cout << guess_word << endl;
			cout << "You lost! The word was: " << secret_word << endl;
			break;
		}
	}
}

string get_random_word(vector<string> &words)
{
	return words[rand() % words.size()];
}
