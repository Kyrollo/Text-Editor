#include <iostream>
#include <fstream>
#include<cstring>

using namespace std;
fstream file;
char name[100];


void open_create_file()
{
    file.open(name, ios::in);
    if (file.fail())
    {
        ofstream file(name);
        cout << "This is a new file. I created it for you \n";
    }
    else
    {
        cout << "File opened successful.\n";
        cout << "This File Already exists. \n";
        while (!file.eof())
        {
            cout << (char)file.get();
            file.close();
        }

        cout << "Done.\n";
    }


}

//Add the contents of the second file in the end of the first
void merge_another_file() {
    //Declare the second file
    fstream file_2;
    //Name of the second file
    char name_2[81];
    cout << "Pls input another existing file name: ";
    //The user write the name of the second file
    cin >> name_2;
    //Add the type of file to the name
    strcat(name_2, ".txt");
    //Open the file
    file_2.open(name_2, ios::app);
    //When the file is not exist or error in open it
    if (file_2.fail())
    {
        ofstream
            //Create a new file with the name the user entered
            file_2(name_2);
        cout << "This is a new file. I created it for you";
    }
    //When the file opened
    else {
        cout << "File opened successful.";
        cout << " This File Already exists";
        //close the file
        file_2.close();
    }
    //Open the second file
    file_2.open(name_2);
    //Open the first file
    file.open(name, ios::app);
    //Add the contents of the second file in the first
    file << file_2.rdbuf();
    //Close the two files
    file.close();
    file_2.close();
}

//Count the number of words
void count_words() {
    //Read the content of the file
    string word;
    //Number of the words
    int letter = 0;
    //Open the file
    file.open(name, ios::in);
    //Read all contents of the file
    while (!file.eof())
    {
        //Know the words from the file
        file >> word;
        //Increase the number of words
        letter++;
    }
    //Print the number of words
    cout << "Number of words in the file are: " << letter;
    //Close the file
    file.close();
}

//Count the number of characters
void count_characters() {
    //Read characters of file
    char character_of_file;
    //Number of characters
    int characters = 0;
    //Open the file
    file.open(name, ios::in);
    //Read all contents of the file
    while (!file.eof())
    {
        //Read file char by char
        file.get(character_of_file);
        //If the character of files is space or tab or new line
        if (character_of_file == '\n' || character_of_file == ' ') {
            continue;
        }
        //If the character of files is not space or tab or new line
        else {
            //Increase the number of characters
            characters++;
        }
    }
    //Print the number of characters
    cout << "Number of characters in the file are: " << characters - 1;
    //Close the file
    file.close();
}

//Count the number of lines
void count_lines() {
    //Read characters of file
    char character_of_file;
    //Number of lines
    int lines = 0;
    //Open the file
    file.open(name, ios::in);
    //Read all contents of the file
    while (!file.eof())
    {
        //Read file char by char
        file.get(character_of_file);
        //If the character of files is new line
        if (character_of_file == '\n') {
            //Increase the number of new lines
            lines++;
        }
    }
    //Print the number of lines
    cout << "Number of lines in the file are: " << lines + 1;
    //Close the file
    file.close();
}

//SearchSearch for a word in the file
void search_word() {
    //The first to the word wanted to search and the second to store the char of files in it
    string word, word_2;
    //Read characters of file
    char character_of_file;
    //To check if word is found or not
    int check;
    cout << "Please write a word you want to search for: ";
    //The user write the word he want to search
    cin >> word;
    //Open the file
    file.open(name, ios::in);
    //Read all contents of the file
    while (!file.eof())
    {
        //Read file char by char
        file.get(character_of_file);
        //If the character of files is space or tab or new line
        if (character_of_file == '\n' || character_of_file == ' ') {
            //The word end so clear the string
            word_2.clear();
        }
        else {
            //Store the word read by char in string
            word_2.push_back(character_of_file);
        }
        //Check the word read by char equal the word the user want search
        if (strcasecmp(word_2.c_str(), word.c_str()) == 0) {
            //Found the word
            check = 1;
            //Stop the loop
            break;
        }
        else {
            //Did not find the word
            check = 0;
        }
    }
    //If the word was find
    if (check == 1) {
        cout << "\n" << "Word was found in the file";
    }
    //If the word was not find
    else if (check == 0) {
        cout << "\n" << "Word was not found in the file";
    }
    //Close the file
    file.close();
}


//Count the number of times a word exists in the file
void repeat_words()
{
    string word, word2;
    int num = 0;
    char character_of_file;

    //take the word from user
    cout << "please enter the word : ";
    cin >> word;
    //open file
    file.open(name, ios::in);
    //Read all contents of the file
    while (!file.eof())
    {
        //read characters in file.
        file.get(character_of_file);
        //If the character of files is space or tab or new line
        if (character_of_file == '\n' || character_of_file == ' ') {
            word2.clear();
        }
        else
        {
            //Store the word read by char in string
            word2.push_back(character_of_file);
        }
        //Check the word read by char equal the word the user want search
        if (strcasecmp(word2.c_str(), word.c_str()) == 0) {
            //Found the word
            num++;
        }
        else {
            //Did not find the word
            continue;
        }
    }
    cout << "Number of times is  : " << num;
}

void upper_case()
{
    char character;
    string word;
    file.open(name, ios::in);
    while (!file.eof())
    {
        file.get(character);
        if (character == '32')
        {
            continue;
        }
        word += toupper(character);
    }
    word.pop_back();
    file.close();
    file.open(name, ios::out);
    file << word;
    file.close();
}

void lower_case()
{

    char character;
    string word;
    file.open(name, ios::in);
    while (!file.eof())
    {

        file.get(character);

        if (character == '32')
        {
            continue;
        }
        word += tolower(character);


    }
    word.pop_back();
    file.close();
    file.open(name, ios::out);
    file << word;
    file.close();

}


void first_char()
{

    char character;
    string word;
    bool check = true;
    file.open(name, ios::in);
    while (!file.eof())
    {

        file.get(character);
        if (check == true)
        {
            character = toupper(character);
            check = false;

        }

        if (character == ' ')
        {

            check = true;

        }
        word += character;

    }
    word.pop_back();
    file.close();
    file.open(name, ios::out);
    file << word;
    file.close();

}

void save()
{
    fstream new_file;
    char new_name[100];
    string text;
    int order;
    cout << "would you want to save at the same file or another file?" << "\n" << "1-at the same file" << "\n" << "2-at another file" << "\n";
    cin >> order;
    if (order == 1)
    {
        cout << "saved";
    }
    else
    {
        cout << "please enter the new file name: ";
        cin >> new_name;
        strcat(new_name, ".txt");
        file.open(name);
        new_file.open(new_name, ios::app);
        while (getline(file, text))
        {
            new_file << text << "\n";
        }
    }
}

// Add new text to the end of the file
void append_to_file()
{
    //declare a string as the text that the user wants to add
    string new_text;
    //open the file in the mode app
    file.open(name, ios::app);
    //tell the user to input the text
    cout << "please enter the text you want to add it: ";
    //take the new text
    cin.ignore();
    getline(cin, new_text);
    //if the file is opened successfully
    if (file.is_open())
    {
        //add space to add the new text
        file << " ";
        //append the new text
        file << new_text;
        //close the file
        file.close();
    }
}

// Display the content of the file
void display_file()
{
    //declare char as the characters of the file
    char character_of_file;
    //open the file in mode read and write
    file.open(name, ios::in | ios::out);
    //if the file is open successfully
    if (file.is_open())
    {
        //while there are characters in the file
        while (!file.eof())
        {
            //read every character in the file
            file.get(character_of_file);
            //print the characters on the screen
            cout << character_of_file;
        }
        cout << "\n";
        //close the file
        file.close();
    }
}

//Empty the file
void clear_file()
{
    //open the file in mode write
    file.open(name, ios::out);
    //if the file opens succesfully
    if (file.is_open()) {
        //write nothing in the file
        file << "";
        //close the file
        file.close();
    }
}

// Definition of encryption function
void encrypt() {
    char character;
    string word;
    //open file and read it to the end.
    file.open(name, ios::in);
    while (!file.eof())
    {
        //read the file char by char
        file.get(character);
        //encrypt the char and store it in string word
        word += character + 1;
    }
    //pop back word
    word.pop_back();
    //close the file
    file.close();
    //open the file in out mode
    file.open(name, ios::out);
    //save the word in file.
    file << word;
    //close the file
    file.close();
}

// Definition of decryption function
void decrypt()
{
    char character;
    string word;
    //open file and read it to the end.
    file.open(name, ios::in);
    while (!file.eof())
    {
        //read the file char by char
        file.get(character);
        //decrypt the char and store it in string word
        word += character - 1;
    }
    //pop back word
    word.pop_back();
    //close the file
    file.close();
    //open the file in out mode
    file.open(name, ios::out);
    //save the word in file.
    file << word;
    //close the file
    file.close();
}
void choose()
{
    int order;
    cout << "now tell me what you want to do.\n";
    cout << "1-Add new text to the end of the file. " << "\n" << "2. Display the content of the file." << "\n" << "3. Empty the file." << "\n" << "4. Encrypt the file content" << "\n" << "5. Decrypt the file content" << "\n" << "6. Merge another file" << "\n" << "7. Count the number of words in the file." << "\n" << "8. Count the number of characters in the file" << "\n" << "9. Count the number of lines in the file" << "\n" << "10. Search for a word in the file" << "\n" << "11. Count the number of times a word exists in the file" << "\n" << "12. Turn the file content to upper case." << "\n" << "13. Turn the file content to lower case." << "\n" << "14. Turn file content to 1st caps (1st char of each word is capital)" << "\n" << "15. Save" << "\n" << "16. Exit" << "\n";
    cin >> order;
    while (order < 1 || order >16)
    {
        cout << "Error: please enter a true input.\n";
        choose();
    }

    if (order == 1) {
        append_to_file();
        choose();
    }
    else if (order == 2) {
        display_file();
        choose();
    }
    else if (order == 3) {
        clear_file();
        choose();
    }
    else if (order == 4) {
        encrypt();
        choose();
    }
    else if (order == 5) {
        decrypt();
        choose();
    }
    else if (order == 6) {
        merge_another_file();
        choose();

    }
    else if (order == 7) {
        count_words();
        choose();

    }
    else if (order == 8) {
        count_characters();
        choose();
    }
    else if (order == 9) {
        count_lines();
        choose();

    }
    else if (order == 10) {
        search_word();
        choose();
    }
    else if (order == 11)
    {
        repeat_words();
        choose();
    }
    else if (order == 12)
    {
        upper_case();
        choose();
    }
    else if (order == 13)
    {
        lower_case();
        choose();
    }
    else if (order == 14)
    {
        first_char();
        choose();

    }
    else if (order == 15)
    {
        save();
        choose();
    }
    else if (order == 16)
    {
        cout << "End.\n";
    }

}


int main()
{
    cout << "Pls input an existing file name: ";
    cin.getline(name, 100);
    strcat(name, ".txt");
    open_create_file();
    choose();

}

