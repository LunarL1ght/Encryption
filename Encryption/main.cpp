//
//  main.cpp
//  Encryption
//
//  Encyrpting words given by the user (Caesar Cipher)
//  Created by Josh Nelson on 9/18/23.
//

#include <iostream>

using namespace std;

string encrypt(string word, int key)
{
    string str;
    
    //for loop that uses the ASCII codes of the lowercase alphabet shifted to get the desired and shifted result. We go one character at a time and add it to our new string which will be our return statement.
    
    for (int i = 0; i < word.length(); i++)
    {
        str += char(int(word[i] + key - 97) % 26 + 97);
    }
    
    return str;
}

int main() {
    //initalizing variables
    int shift;
    string text;
    int numWords;
//asking user for key and words to encrypt
    cout << "By how many would you like to shift the letters in the alphabet over by to create your encryption? ";
    cin >> shift;
    
    cout << "How many words would you like to input?: ";
    cin >> numWords;
    string list[numWords];
    
    //getting each word from the user and placing them into an array. I could use a vector but want to get better at both. I understand vectors are better :)
    for (int i = 0; i < numWords; i++)
    {
        string word;
        cout << "Enter word #" << i+1 << ": ";
        cin >> word;
        list[i] = word;
        word = "";
    }
    
    cout << endl;
    
    //creating a new array that will store encrypted words
    string newList[numWords];
    
    //encrypting each word
    for (int i = 0; i < numWords; i++)
    {
        string str_new = encrypt(list[i], shift);
        newList[i] = str_new;
    }
    
    //displaying original and encrypted words
    cout << "Original Word  |  Encrypted Word" << endl;
    cout << "________________________________" << endl;
    
    for (int j = 0; j < numWords; j++)
    {
        cout << list[j];
        
        for (int k = 0; k < (18 - list[j].length()); k++)
        {
            cout << " ";
        }
        
        cout << newList[j] << endl;
        
    }
    cout << endl;
    
    return 0;
}
