/*
Program : Spell Checker
Description : It is a spell checker program. It checks if the spelling of entered word is right or wrong.
if spelling is wrong then it gives the suggestions of correct spellings.

Author : Akshat Jain
Roll Number : 1918006
Email : akshat.kodia@gmail.com
github : github.com/akshatprogrammer
*/
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <conio.h>

using namespace std;

//lower case alphabets.
char lower_alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

//function to show the correct spelling if arrangement of word is incorrect.
int incorrectArrangement(string input)
{
    string line;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while(getline(words,line))
        {
            string Xinput = input, Ninput, permutations, Tinput, Tline, Nline, Xline = line;
            int len = Xinput.size(), flen = line.size();
            if (len == flen)
            {
                for (int i=1; i<Xinput.length(); i++)
                    Ninput.push_back(input[i]);
                for (int i = 1; i < flen; i++)
                    Nline.push_back(Xline[i]);
                Xinput.resize(1);
                Xline.resize(1);
                sort(Nline.begin(),Nline.end());
                sort(Ninput.begin(), Ninput.end());
                Tinput = Xinput + Ninput;
                Tline = Xline + Nline;
                if (Tinput == Tline)
                {
                    found = 1;
                    cout<<line<<endl;
                    break;
                }
            }
        }
        words.close();
    }
    else
    {
        cout<<endl<<"Unexpected error occurred......."<<endl;
    }
    return found;
}

//function to show correct spelling if exchanged character is present in the given word
int exchangedCharacters (string input)
{
    string line, Xinput;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = len-1; i >= 0 ; i--)
                {
                    Xinput = input;
                    Xinput[i] = lower_alpha[0];
                    for (int j=0; j<26; j++)
                    {
                        if (Xinput == line)
                        {
                            found = 1;
                            cout<<line<<endl;
                            break;
                        }
                        Xinput[i] = lower_alpha[j];
                    }
                    if (found == 1 ) break;
                    else continue;
                }
            }
        }
        words.close();
    }
    else cout<<"\nUnexpected error occurred"<<endl;
    return found;
}

//function to show correct spelling when there is a missing character in the given word.
int missingCharacter (string input)
{
    string Xinput, line, Tinput, Tline, Xline;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            for (int i = 0; i < 26; i++)
            {
                int len = input.size(), flen = line.size();
                Xinput = input;
                Xline = line;
                Xinput.resize(len+1,'a');
                Xinput[len] = lower_alpha[i];
                len = Xinput.size();
                string Ninput, Nline;
                if (len == flen)
                {
                    for (int j = 1; j <=len; j++)
                        Ninput.push_back(Xinput[j]);
                    for (int j = 1; j <= flen; j++)
                        Nline.push_back(Xline[j]);
                    Xinput.resize(1);
                    Xline.resize(1);
                    sort(Nline.begin(),Nline.end());
                    sort(Ninput.begin(),Ninput.end());
					Tinput = Xinput + Ninput;
                    Tline = Xline + Nline;
                    if (Tinput == Tline)
                    {
                        found = 1;
                        cout<<line<<endl;
                        break;
                    }
                }
                if (found == 1) break;
            }
            if (found == 1) break;
        }
        words.close();
    }
    else
    {
        cout<<"\nUnexpected error occurred\n";
    }
    return found;
}

//function to show correct spelling of there is an extra character in given word.
int extraCharacter (string input)
{
    string Xinput, line, Ninput, Tinput;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
             int len = input.size(), flen = line.size();
             if ((len-1) == flen)
             {
                 for (int i = 1; i < len; i++)
                 {
                     Xinput = input;
                     Xinput.erase(Xinput.begin()+i);
                     if (Xinput == line)
                     {
                         found = 1;
                         cout<<line<<endl;
                         break;
                     }

                 }
             }
        }
        words.close();
    }
    else
    {
        cout<<"\nUnexpected error occurred\n";
    }
    return found;
}

//function to show right spelling when given word has wrong extra character and right one is missing.
int mixedExtraMissing (string input)
{
    string Xinput, line, Xline;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = 1; i < len; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        Xinput = input; Xline = line;
                        Xinput.erase(Xinput.begin()+i);
                        Xinput.resize(len, 'a');
                        Xinput[len-1] = lower_alpha[j];
                        sort(Xinput.begin()+1,Xinput.end());
                        sort(Xline.begin()+1,Xline.end());
                        if (Xinput == Xline)
                        {
                            found = 1;
                            cout<<line<<endl;
                            break;
                        }
                    }
                    if (found == 1) break;
                }
                if (found == 1) break;
            }
        }
        words.close();
    }
    return found;
}

int main()
{
	cout << "\t\t\t\tWelcome to Spell Checker by Akshat"<< endl;
	cout << "Press 1 to start -> ";
	int choice,ch=1;
	cin >> choice;
	system("cls");
	cout << "\t\t\t\tD E S C R I P T I O N\n";
	cout << "\n\n\nIt is a spell checker program.\nIt checks if the spelling of entered word is right or wrong.\nif spelling is wrong then it gives the suggestions of correct spellings."<<endl;
	cout << "\n\n\n\t\t\t\tAuthor : Akshat Jain\n\t\t\t\tRoll Number -> 1918006"<<endl;
	cout << "\nPress 1 to start -> ";
	cin >> choice;
	system("cls");
	getchar();
	//cout << "We are ready for spell checking :)\n\n\n";
	//system("cls");
    while (ch) {
        string input,line;
        int len,flen,correct=0;
        cout<<"Enter the word: ";
		getchar();
		getline(cin,input);
        len = input.length();
        for (int i=0; i < len; i++)
            input[i] = tolower(input[i]);
        ifstream words ("words.txt");
        if(words)
        {
            while (getline(words,line))
            {
                flen = line.length();
                if (len==flen)
                {
                    if (line==input)
                    {
                        correct=1;
                    }
                    else continue;
                }
                else continue;
            }
            words.close();
            if (correct==1)
            {
                cout<<endl<<"Spelling is correct"<<endl;
            }
            if (correct==0)
            {
                int missing = 0, extra = 0, mixed = 0, incorrect = 0, exchanged = 0;
                cout<<endl<<"Spelling is wrong. Possible right spellings are given below:- "<<endl<<endl;
                missing = missingCharacter(input);
                extra = extraCharacter(input);
                mixed = mixedExtraMissing(input);
                incorrect = incorrectArrangement(input);
                exchanged = exchangedCharacters(input);
                if (missing == 0 && extra == 0 && mixed == 0 && incorrect == 0 && exchanged == 0)
{
                    cout<<endl<<"No such word exist"<<endl;
                }
            }
        }
        else
        {
            cout<<"Not able to open words.txt"<<endl;
        }
        cout<<endl<<"Press any key(number) to continue...and 0 to exit"<<endl<<endl;
        cin >> ch;
        system("cls");
        //_getch();
    }
    cout << "\t\t\t\tT H A N K Y O U"<<endl;
    cout << "\t\t\t\tCode by : Akshat Jain( Graphic Era University)";
    return 0;

}
