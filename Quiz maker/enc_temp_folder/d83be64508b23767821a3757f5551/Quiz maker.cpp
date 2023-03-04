// Quiz maker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // c output and c input
#include <string> // string to work with strings
#include <vector> // for our vectors
#include <algorithm>// for our transform method
#include <windows.h>
using namespace std;
void programWelcomeMessage();
void userWelcome();
string printUserWelcomeMessage (string userWelcomeMessageInfo);
string changeUserWelcomeMessage(string inputUserWelcomeMessage);
int checkAnswer(string userAnswer, string programAnswer);
void clearConsole();
int characterOutput(string sentence);
int characterOutput(string sentence, vector <string> variable, string nextSentence, int nextVariable);
int main()
{
    vector <string> userMakeQuestionArray = {};
    vector <string> userMakeAnswerArray = {};
    bool typeRightCommand = true;
    string pickedCommand; // our picked Commnad
    string pickedTestCommandIfIsEmpty;
    string userWelcomeMessageInfo;
    string pickedMessageMethod= "text";
    string questionCommand;
    string userMakeQuestion;
    string userMakeAnswer;
    string changedQuestion;
    string changedAnswer;
    int deleteElement;
    int counterOfQuestions = 0;
    int deleteElementInfoForUser;
    int questionNumber;
    int numberOfQuestion=1;
    bool questionCircleMaker = true;
    int answerBox;
    int correctAnswers = 0;
    string userAnswer;
    programWelcomeMessage();

        while (typeRightCommand)
        {
                getline(cin, pickedCommand);
                transform(pickedCommand.begin(), pickedCommand.end(), pickedCommand.begin(), ::tolower);
            if (pickedCommand == "#wiadomosc")
            {
                wiadomosc:
                userWelcome();
                if (userWelcomeMessageInfo == "") {
                    cout << "Teraz juz mozesz napisac" << endl;
                    getline(cin, userWelcomeMessageInfo);
                    printUserWelcomeMessage(userWelcomeMessageInfo);
                    system("cls");
                    cout << "/************************************************************/" << endl;
                    cout << "To jest twoje terazniejsze pozdrowienie:" << endl;
                    cout << printUserWelcomeMessage(userWelcomeMessageInfo) << endl;
                    cout << endl;
                    cout << "Mozesz zmienic to `#zmien` commanda" << endl;
                    cout << "Albo skozystaj z innych  `#pytanie`, `#programa`" << endl;
                    cout << endl;
                    cout << "/************************************************************/" << endl;
                    getline(cin, pickedMessageMethod);
                    transform(pickedMessageMethod.begin(), pickedMessageMethod.end(), pickedMessageMethod.begin(), ::tolower);
                    if (pickedMessageMethod == "#zmien")
                    {
                        system("cls");
                        cout << "/************************************************************/" << endl;
                        cout << "Okay, wiec zdecydowales zmienic pozdrowienie" << endl;
                        cout << "To jest twoje zeszle" << endl;
                        cout << printUserWelcomeMessage(userWelcomeMessageInfo) << endl;
                        cout << endl;
                        cout << "A zaraz terazniejrze: " << endl;
                        getline(cin, userWelcomeMessageInfo);
                        cout << "Fajne, kontynuujemy. Co dalej robimy?" << endl;
                        cout << endl;
                        cout << "/************************************************************/" << endl;
                    }
                    else {
                        if (pickedMessageMethod=="#pytanie")
                        {
                            goto pytanie;
                        }
                        else if (pickedMessageMethod == "#test")
                        {
                            goto test;
                        } 
                        else if (pickedMessageMethod == "#programa") {
                            goto programa;
                        }
                        else if (pickedMessageMethod == "#wiadomosc") {
                            goto wiadomosc;
                        }
                        else {
                            cout << "Chyba pomyliwes sie. Sprobuj ponownie" << endl;
                        }
                    }
                }
                else {
                    cout << "To jest twoje terazniejrze pozdrowienie:"<< endl;
                    cout << printUserWelcomeMessage(userWelcomeMessageInfo) << endl;
                    cout << "Mozesz zmienic to `#zmien` commanda" << endl;
                    cout << "Albo skozystaj z innych  `#pytanie`, `#programa`" << endl;
                    cout << endl;
                    cout << "/************************************************************/" << endl;
                    getline(cin, pickedMessageMethod);
                    transform(pickedMessageMethod.begin(), pickedMessageMethod.end(), pickedMessageMethod.begin(), ::tolower);
                    if (pickedMessageMethod == "#zmien")
                    {
                        system("cls");
                        cout << "Okay, wiec zdecydowales zmienic pozdrowienie" << endl;
                        cout << "To jest twoje zeszle:" << endl;
                        cout << printUserWelcomeMessage(userWelcomeMessageInfo) << endl;
                        cout << "A zaraz terazniejrze" << endl;
                      //  cin.ignore();
                        getline(cin, userWelcomeMessageInfo);
                        cout << "Fajne, kontynuujemy." << endl;
                         cout << endl;
                        cout << "/************************************************************/" << endl;
                    }
                    else {
                        if (pickedMessageMethod == "#pytanie")
                        {
                            goto pytanie;
                        }
                        else if (pickedMessageMethod == "#test")
                        {
                            goto test;
                        }
                        else if (pickedMessageMethod == "#programa") {
                            goto programa;
                        }
                        else if (pickedMessageMethod == "#wiadomosc") {
                            goto wiadomosc;
                        }
                        else {
                            cout << "Chyba pomyliwes sie. Sprobuj ponownie" << endl;
                        }
                    }
                }
                
            }
            else if (pickedCommand == "#pytanie") {
                pytanie:
                system("cls");
                cout << "/**************************************************************************************/" << endl;
                cout << endl;
                cout << "Witam w `#pytanie` czesc!!!" << endl;
                cout << "1. Napisz `#stwozyc` zeby wymysliasz swoje pytanka i odpowidzi." << endl;
                cout << "2. Napisz `#zmien` zeby zmienic pytanka i odpowidzi." << endl;
                cout << "3. Napisz `#usuwac` zeby usunoc pytanka i odpowidzi." << endl;
                cout << "4. Napisz `#zobaczycPytanka` zeby zobaczycPytanka, ile masz"<< endl;
                cout << endl;
                cout << "/**************************************************************************************/" << endl;
                questionCircleMaker = true;

                while (questionCircleMaker) {
                   
                    getline(cin, questionCommand);
                    if (questionCommand == "#stwozyc") {
                        system("cls");
                        cout << "/**************************************************************************************/" << endl;
                        cout << "Witam, estes w  pytanka i odpowidzi czesc." << endl;
                        cout << endl;
                        cout << "Napisz pytanko: ";
                        getline(cin, userMakeQuestion);
                        userMakeQuestionArray.push_back(userMakeQuestion);
                        cout << endl;
                        cout << "Napisz odpowiedz: ";
                        getline(cin, userMakeAnswer);
                        userMakeAnswerArray.push_back(userMakeAnswer);
                        counterOfQuestions++;
                        cout << endl;
                        cout << "Przepieknie stwozyles swoje pytanko i odopwiedz! Co dalej robimy?" << endl;
                        cout << endl;
                        cout << "/************************************************************/" << endl;
                       }
                    else if (questionCommand == "#zmien") {
                        system("cls");
                        cout << "/************************************************************/" << endl;
                        cout << endl;
                        cout << "Witam, estes w `#zmien` czesc." << endl;
                        cout << "Wybiez pytanko z w liscie `#zobaczycPytanka` i zmien to!" << endl;
                        cout << "Numer pytanka: ";
                        cin >> questionNumber;
                        questionNumber--;
                        if (cin.rdbuf()->in_avail()>0)
                        {
                            cin.ignore();
                        }
                        if (questionNumber < userMakeQuestionArray.size() && !userMakeQuestionArray.empty() && !userMakeAnswerArray.empty()) {
                            cout << "To jest twoje zeszle pytanko i odpowiedz" << endl;
                            cout << userMakeQuestionArray[questionNumber] << " : " << userMakeAnswerArray[questionNumber] << endl;
                            cout << "Ale zaraz bedziesz pizal terazniejsze" << endl;
                            cout << "Pytanko: ";
                           
                            getline(cin, changedQuestion);
                            userMakeQuestionArray[questionNumber] = changedQuestion;
                            cout << "Odpowiedz : ";
                            if (cin.rdbuf()->in_avail()>0)
                            {
                                cin.ignore();
                            }
                            getline(cin, changedAnswer);
                            userMakeAnswerArray[questionNumber] = changedAnswer;
                            cout << "Pacz, dobrze?" << endl;
                            cout << userMakeQuestionArray[questionNumber] << endl;
                            cout << userMakeAnswerArray[questionNumber] << endl;
                            cout << endl;
                            cout << "/************************************************************/" << endl;
                        }
                        else { cout << "Przepraszam nie znalazlem tego pytania" << endl; }
                                                
                    }


                    else if (questionCommand == "#usuwac"){
                        system("cls");
                        cout << "/************************************************************/" << endl;
                        cout << endl;
                        cout << "Witam w `#usuwac` czesc" << endl;
                        cout << "Wybierz pytanko z list  `#zobaczycPytanka` i usun go!" << endl;
                        cout << "Podaj number kolejnosci: ";
                        cin >> deleteElement;
                        deleteElement--;
                        deleteElementInfoForUser = deleteElement;
                        if (deleteElement < userMakeQuestionArray.size() && !userMakeQuestionArray.empty() && !userMakeAnswerArray.empty()) {
                            cout << userMakeQuestionArray[deleteElement]<<": " << userMakeAnswerArray[deleteElement] << endl;
                                userMakeQuestionArray.erase(userMakeQuestionArray.begin() + deleteElement);
                                userMakeAnswerArray.erase(userMakeAnswerArray.begin() + deleteElement);
                                counterOfQuestions--;
                                cout << "Przepieknie usuneles swoje pytanko i odopwiedz! Co dalej robimy?" << endl;
                                cout << endl;
                                cout << "/************************************************************/" << endl;
                        }
                        else {
                            deleteElementInfoForUser++;
                            cout << "Masz ogolnie tylko " << counterOfQuestions << " pytanek, a chcesz usuwac po kolei " << deleteElementInfoForUser << ". Pomysl!" << endl;
                            cout << endl;
                            cout << "/************************************************************/" << endl;
                        }
                        if (cin.rdbuf()->in_avail()>0) {
                            cin.ignore();
                        }
                    }
                    else if (questionCommand == "#zobaczycPytanka") {
                        int counter =1;
                        system("cls");
                        if (counterOfQuestions == 0)
                        {
                            cout << "/************************************************************/" << endl;
                            cout << endl;
                            cout << "Wierz co. Jeszcze nie wymysliales pytanek i odpowiedzi. Zrob to teraz!" << endl;
                            cout << endl;
                            cout << "/************************************************************/" << endl;
                        }
                        else {
                            cout << "/************************************************************/" << endl;
                            cout << endl;
                            for (int ques = 0; ques < userMakeQuestionArray.size(); ques++) {
                                cout << counter << ". " << userMakeQuestionArray[ques] << ": " << userMakeAnswerArray[ques] << endl;
                                counter++;
                            }
                            cout << endl;
                            cout << "/************************************************************/" << endl;
                        }
                            
                    } 
                    else if (questionCommand == "#pytanie")
                    {
                        goto pytanie;
                    }
                    else if (questionCommand == "#test")
                    {
                        goto test;
                    }
                    else if (questionCommand == "#programa") {
                        goto programa;
                    }
                    else if (pickedMessageMethod == "#wiadomosc") {
                        goto wiadomosc;
                    }
                    
                    else {cout << "Sprobuj ponownie. Gdzies tam zrobiles bled" << endl;}
                }
            }
            else if (pickedCommand == "#test") {
                 test:
                 system("cls");
                 cout << "/************************************************************/" << endl;
                 if (printUserWelcomeMessage(userWelcomeMessageInfo) == "")
                 {
                     cout << "Witam serdecznie na kwise!!! Protestuj swoja wiedze." << endl;
                 }
                 else {
                     cout << printUserWelcomeMessage(userWelcomeMessageInfo) << endl;
                 }
                 cout << "Dobrze zaczynamy..." << endl;
                 if (userMakeQuestionArray.size() != 0) {
                     for (int numQue = 0; numQue < userMakeQuestionArray.size(); numQue++) {
                         cout << "Numer pytanka: " << numberOfQuestion << endl;
                         cout << userMakeQuestionArray[numQue] << endl;
                         getline(cin, userAnswer);
                         answerBox = checkAnswer(userAnswer, userMakeAnswerArray[numQue]);
                         if (answerBox) {
                             correctAnswers++;
                         }
                         else {
                             correctAnswers += 0;
                         }
                         numberOfQuestion++;
                     }
                     cout << "/************************************************************/" << endl;
                     characterOutput("Alej jestes szybki. Widzialem jak tylko zaczynales, a juz teraz skonczyles");
                     characterOutput("Prosze zobaczyc swoje wyniki");
                     characterOutput("/**************************/");
                     characterOutput("Z ", userMakeAnswerArray," pytanek, odpowiedziales poprawnie ", correctAnswers);
                     cout << endl;
                     cout << "/************************************************************/" << endl;
                 }
                 else {
                     cout << "/***************************************************************************/" << endl;
                     cout << endl;
                     cout << "Przepraszam, ale nie masz stwozonych pytanek i odpowiedzi. Stwoz ich teraz!" << endl;
                     cout << endl;
                     cout << "/***************************************************************************/" << endl;
                     getline(cin, pickedTestCommandIfIsEmpty);
                     if (pickedTestCommandIfIsEmpty == "#pytanie")
                     {
                         goto pytanie;
                     }
                     else if (pickedTestCommandIfIsEmpty == "#test")
                     {
                         goto test;
                     }
                     else if (pickedTestCommandIfIsEmpty == "#programa") {
                         goto programa;
                     }
                     else if (pickedTestCommandIfIsEmpty == "#wiadomosc") {
                         goto wiadomosc;
                     }
                     else { cout << "Sprobuj ponownie. Gdzies tam zrobiles bled" << endl; }
                 }
                 correctAnswers = 0;
            }
            else if (pickedCommand == "#programa") {
                programa:
                system("cls");
                programWelcomeMessage();
            }
            else {
            cout << "Sprobuj ponownie. Gdzies tam zrobiles bled" << endl;

            }
        }
    

    return 0;
}
void programWelcomeMessage() {
    cout << "/**************************************************************************************/" << endl;
    cout << endl;
    cout << "Dzien dobry, panstwu!";
    cout << "Chce proinformowac ze teraz mozecie zrobic swoje wlasny kwiz."<<endl;
    cout<<"Checiliscie by sprubowac to ? ..." << endl;
    cout << "Tutaj macie fajna mapka ktora pokaze wam to zrobic" << endl;
    cout << "/**************************************************************************************/" << endl;
    cout << endl;
    cout << "1. Napisz `#wiadomosc` zeby stwozyc pozdrowienie dla twojego jusera." << endl;
    cout << "2. Napisz `#pytanie` zeby stwozyc pytanie i odpowidz" << endl;
    cout << "3. Napisz `#test` zeby protestowac twoj kwiz" << endl;
    cout << "4. Napisz `#programa` zeby otwozyc swoja mapke" << endl;
    cout << endl;
    cout << "/**************************************************************************************/" << endl;
}
void userWelcome() {
    system("cls");
    cout << "/**************************************************************************************/" << endl;
    cout << endl;
    cout << "Siema. To jest kwiz pozdrowienie. (To jest to co juser bede widzial po raz pirzy pzy prochodziniu kwiza)" << endl;
    cout << "/**************************************************************************************/" << endl;
    cout << endl;
}
// this function stores our userWelcomeMessageInfo, so the user if messed up can copy and add sth else, 
//instead of coming up with the completely new message;
string printUserWelcomeMessage(string userWelcomeMessageInfo) {
    string welcomeMessage = userWelcomeMessageInfo;
    return welcomeMessage;
}
string changeUserWelcomeMessage(string inputUserWelcomeMessage) {
    getline(cin, inputUserWelcomeMessage);
    return inputUserWelcomeMessage;
}
int checkAnswer(string userAnswer, string programAnswer) {
    transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);
    transform(programAnswer.begin(), programAnswer.end(), programAnswer.begin(), ::tolower);
    size_t searchedWord= userAnswer.find(programAnswer);
    if (searchedWord != string::npos) {
        cout << "Dobrze, brawo ty!" << endl;
        cout << "Odpowiedz byla " << programAnswer << endl;
        clearConsole();
        return true;
    } 
    else {
        cout << "/****************************************************************************" << endl;
        cout << "Wiem ze jestes madry, ale ucz sie wiecej, bo nauka to potegi klucz" << endl;
        cout << "Odpowiedz byla " << programAnswer << endl;
        clearConsole();
        return false;
    }
}
void clearConsole() {
    Sleep(2400);
    system("cls");
}
int characterOutput(string sentence) {
    for (int g = 0; g < sentence.length(); g++) {
        Sleep(80);
       cout<< sentence[g];
    }
    cout << endl;
    return true;
}

int characterOutput(string sentence, vector <string> variable, string nextSentence, int nextVariable) {
    for (int k = 0; k < sentence.length(); k++) {
        Sleep(80);
        cout << sentence[k];
    }
    cout << " " << variable.size() << " ";
    for (int n = 0; n< nextSentence.length(); n++) {
        Sleep(80);
        cout << nextSentence[n];
    }
    cout << " " << nextVariable << " ";
    cout << endl;
    return true;
}