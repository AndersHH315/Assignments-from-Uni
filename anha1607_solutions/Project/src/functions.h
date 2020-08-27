#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "constants.h"

using namespace std;

// Instansierar alla metoder från functions.cpp för att kunna använda de i main.cpp
void ShowMenu();
int MenuChoice();
void InvalidChoice();
void InvalidSortChoice();
void addPerson(Person p, vector<Person> &person);
void WriteList(vector<Person> &person);
bool FindPersonById(string k, vector<Person> &person);
void FindPerson(vector<Person> &person);
void DelPerson(vector<Person> &person);
void SortList(int s, vector<Person> &person);
bool CompareName(Person a, Person b);
bool CompareSign(const Person &a, const Person &b);
bool CompareHeight(const Person &a, const Person &b);
void RandList(vector<Person> &person);
void SaveFile(vector<Person> &person);
void ReadFile(Person &p, vector<Person> &person);


#endif