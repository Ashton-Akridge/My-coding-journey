#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Variables
double numLetters = 0; //Variable for the number of letters
double numWords = 1;//Variable for the number of Words
double numSentences = 0;//Variable for the number of Sentences
double L; //Variable for the average number of letters per 100 words in the text
double S; //Variable for the average number of Sentences per 100 Words in the text
int Grade;//Variable to calculate the Grade level of the text

int Letters(string userText)
{
    //While the current index of the string is less than the length of the string
    for(int i = 0; i < strlen(userText);i++)
    {
        //if the users input is not a space then increment the number of letters
        if((userText[i] >= 65 && userText[i] <= 90)|| (userText[i] >= 97 && userText[i] <= 122))
        {
            //Increments the number of letters
            numLetters++;
        }
    }
    //Returns the number of letters
    return numLetters;
}

int Words(string userText)
{
    //While the current index of the string is less than the length of the string
    for(int i = 0; i < strlen(userText); i++)
    {
        //if the users input is  a space then increment the number of letters
        if (userText[i] == 32)
        {
            //Increments the number of Words
            numWords++;
        }
    }
    //returns the number of words
    return numWords;
}

int Sentences(string userText)
{
    //While the current index of the string is less than the length of the string
    for(int i = 0; i < strlen(userText); i++)
    {
        //if the users input is  a space then increment the number of Sentences
        if(userText[i] == 33 || userText[i] == 46|| userText[i] == 63)
        {
            //Increments the number of Words
            numSentences++;
        }
    }
    //Returns the number of sentences
    return numSentences;
}

int GradeLevel(void)
{
    //Average number of letters per 100 words in the text
    L = (numLetters / numWords * 100);

    //Average number of words per 100 words in the text
    S = (numSentences / numWords * 100);

    //Formula to calculate reading level
    Grade = round(0.0588 * L - 0.296 * S - 15.8);


    //Returns the GradeLevel of the user text
    return Grade;
    return L;
    return S;
}

int main(void)
{

    //Get the user input for the string
    string userText = get_string("Input the Text: ");

    //Runs the letters Function
    Letters(userText);

    //Runs the Words Function
    Words(userText);

    //Runs the Senences Function
    Sentences(userText);

    //Runs the GradeLevel Function
    GradeLevel();

    //If the Grade level is Greater than 16
    if (Grade >= 16)
    {
        //Print Grade Level 16+
        printf("Grade 16+\n");
    }
    //If the Grade level is less than 1
    else if (Grade <= 1)
    {
        //Print Grade Level is before 1
        printf("Before Grade 1\n");
    }
    else
    {
        //Print Grade Level
        printf("Grade %i\n",Grade);
    }
    
}









