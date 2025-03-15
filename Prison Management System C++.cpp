#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_GUARDS = 10;
const int MAX_BLOCKS = 5;
const int MAX_WINGS = 3;
const int MAX_CELLS = 20;
const int MAX_PRISONERS = 50;
const int MAX_LOGS = 30;
const int MAX_INVENTORY_ITEMS = 20;
const int MAX_MEALS = 10;
const int MAX_ACTIVITIES = 10;

class Person 
{
protected:
string name;
int age;
public:
Person(string name = "", int age = 0) : name(name), age(age) {}
virtual void input() 
{
cout << "Enter Name: ";
cin.ignore();
getline(cin, name);
cout << "Enter Age: ";
cin >> age;
}
virtual void display() const {
cout << "Name: " << name << ", Age: " << age << endl;
}
virtual void save(ofstream& file) const 
{
file << name << endl;
file << age << endl;
}
virtual void load(ifstream& file) 
{
getline(file, name);
file >> age;
file.ignore();
}
virtual ~Person() {}
};
class Warden : public Person {
private:
int wardenID;
string experience;
public:
Warden() : Person(), wardenID(0), experience("") {}
void input() override {
Person::input();
cout << "Enter Warden ID: ";
cin >> wardenID;
cout << "Enter Experience (years): ";
cin.ignore();
getline(cin, experience);
}
void display() const override {
cout << "Warden ID: " << wardenID << ", ";
Person::display();
cout << "Experience: " << experience << " years" << endl;
}
void save(ofstream& file) const override {
Person::save(file);
file << wardenID << endl;
file << experience << endl;
}
void load(ifstream& file) override {
Person::load(file);
file >> wardenID;
file.ignore();
getline(file, experience);
}
};
class Guard : public Person {
private:
int guardID;
string shift;
public:
Guard() : Person(), guardID(0), shift("") {}
void input() override {
Person::input();
cout << "Enter Guard ID: ";
cin >> guardID;
cout << "Enter Shift (Day/Night): ";
cin.ignore();
getline(cin, shift);
}
void display() const override {
cout << "Guard ID: " << guardID << ", ";
Person::display();
cout << "Shift: " << shift << endl;
}
void save(ofstream& file) const override {
Person::save(file);
file << guardID << endl;
file << shift << endl;
}
void load(ifstream& file) override {
Person::load(file);
file >> guardID;
file.ignore();
getline(file, shift);
}
};

class Prisoner : public Person {
private:
int prisonerID;
string crime;
int sentenceYears;
public:
Prisoner() : Person(), prisonerID(0), crime(""), sentenceYears(0) {}
void input() override {
Person::input();
cout << "Enter Prisoner ID: ";
cin >> prisonerID;
cout << "Enter Crime: ";
cin.ignore();
getline(cin, crime);
cout << "Enter Sentence Years: ";
cin >> sentenceYears;
}
void display() const override {
cout << "Prisoner ID: " << prisonerID << ", ";
Person::display();
cout << "Crime: " << crime << ", Sentence: " << sentenceYears << " years" << endl;
}
void save(ofstream& file) const override
{
cout << "Saving prisoner ID: " << prisonerID << endl;
Person::save(file);
file << prisonerID << endl;
file << crime << endl;
file << sentenceYears << endl;
}

void load(ifstream& file) override {
Person::load(file);
file >> prisonerID;
file.ignore();
getline(file, crime);
file >> sentenceYears;
file.ignore();
cout << "Loaded prisoner ID: " << prisonerID << endl;
}

};

class Cell {
private:
int cellNumber;
Prisoner prisoners[MAX_PRISONERS];
int prisonerCount;
public:
Cell(int cellNumber = 0) : cellNumber(cellNumber), prisonerCount(0) {}
void input() {
cout << "Enter Cell Number: ";
cin >> cellNumber;
cout << "Enter number of prisoners in the cell: ";
cin >> prisonerCount;
for (int i = 0; i < prisonerCount; ++i) {
cout << "Enter details for prisoner " << i + 1 << ":" << endl;
prisoners[i].input();
}
}
void display() const {
cout << "Cell Number: " << cellNumber << endl;
for (int i = 0; i < prisonerCount; ++i) {
prisoners[i].display();
}
}
void save(ofstream& file) const {
file << cellNumber << endl;
file << prisonerCount << endl;
for (int i = 0; i < prisonerCount; ++i) {
prisoners[i].save(file);
}
}
void load(ifstream& file) {
file >> cellNumber;
file >> prisonerCount;
file.ignore();
for (int i = 0; i < prisonerCount; ++i) {
prisoners[i].load(file);
}
}
};

class Wing {
private:
int wingNumber;
Cell cells[MAX_CELLS];
int cellCount;
public:
Wing(int wingNumber = 0) : wingNumber(wingNumber), cellCount(0) {}
void input() {
cout << "Enter Wing Number: ";
cin >> wingNumber;
cout << "Enter number of cells in the wing: ";
cin >> cellCount;
for (int i = 0; i < cellCount; ++i) {
cout << "Enter details for cell " << i + 1 << ":" << endl;
cells[i].input();
}
}
void display() const {
cout << "Wing Number: " << wingNumber << endl;
for (int i = 0; i < cellCount; ++i) {
cells[i].display();
}
}
void save(ofstream& file) const {
file << wingNumber << endl;
file << cellCount << endl;
for (int i = 0; i < cellCount; ++i) {
cells[i].save(file);
}
}
void load(ifstream& file) {
file >> wingNumber;
file >> cellCount;
file.ignore();
for (int i = 0; i < cellCount; ++i) {
cells[i].load(file);
}
}
};

class Inventory {
private:
string items[MAX_INVENTORY_ITEMS];
int itemCount;
public:
Inventory() : itemCount(0) {}
void input() {
cout << "Enter number of inventory items: ";
cin >> itemCount;
for (int i = 0; i < itemCount; ++i) {
cout << "Enter inventory item " << i + 1 << ": ";
cin.ignore();
getline(cin, items[i]);
}
}
void display() const {
cout << "Inventory Items: " << endl;
for (int i = 0; i < itemCount; ++i) {
cout << i + 1 << ". " << items[i] << endl;
}
}
void save(ofstream& file) const {
file << itemCount << endl;
for (int i = 0; i < itemCount; ++i) {
file << items[i] << endl;
}
}
void load(ifstream& file) {
file >> itemCount;
file.ignore();
for (int i = 0; i < itemCount; ++i) {
getline(file, items[i]);
}
}
};

class Meal {
private:
string meals[MAX_MEALS];
int mealCount;
public:
Meal() : mealCount(0) {}
void input() {
cout << "Enter number of meals: ";
cin >> mealCount;
for (int i = 0; i < mealCount; ++i) {
cout << "Enter meal " << i + 1 << ": ";
cin.ignore();
getline(cin, meals[i]);
}
}
void display() const {
cout << "Meals: " << endl;
for (int i = 0; i < mealCount; ++i) {
cout << i + 1 << ". " << meals[i] << endl;
}
}
void save(ofstream& file) const {
file << mealCount << endl;
for (int i = 0; i < mealCount; ++i) {
file << meals[i] << endl;
}
}
void load(ifstream& file) {
file >> mealCount;
file.ignore();
for (int i = 0; i < mealCount; ++i) {
getline(file, meals[i]);
}
}
};

class Log {
private:
string entries[MAX_LOGS];
int logCount;
public:
Log() : logCount(0) {}
void input() {
cout << "Enter number of log entries: ";
cin >> logCount;
cin.ignore();
for (int i = 0; i < logCount; ++i) {
cout << "Enter log entry " << i + 1 << ": ";
getline(cin, entries[i]);
}
}
void display() const {
cout << "Log Entries: " << endl;
for (int i = 0; i < logCount; ++i) {
cout << i + 1 << ". " << entries[i] << endl;
}
}
void save(ofstream& file) const {
file << logCount << endl;
for (int i = 0; i < logCount; ++i) {
file << entries[i] << endl;
}
}
void load(ifstream& file) {
file >> logCount;
file.ignore();
for (int i = 0; i < logCount; ++i) {
getline(file, entries[i]);
}
}
};

class Activity {
private:
string activities[MAX_ACTIVITIES];
int activityCount;
public:
Activity() : activityCount(0) {}
void input() {
cout << "Enter number of activities: ";
cin >> activityCount;
cin.ignore();
for (int i = 0; i < activityCount; ++i) {
cout << "Enter activity " << i + 1 << ": ";
getline(cin, activities[i]);
}
}
void display() const {
cout << "Activities: " << endl;
for (int i = 0; i < activityCount; ++i) {
cout << i + 1 << ". " << activities[i] << endl;
}
}
void save(ofstream& file) const {
file << activityCount << endl;
for (int i = 0; i < activityCount; ++i) {
file << activities[i] << endl;
}
}
void load(ifstream& file) {
file >> activityCount;
file.ignore();
for (int i = 0; i < activityCount; ++i) {
getline(file, activities[i]);
}
}
};
class Block {
private:
int blockNumber;
Wing wings[MAX_WINGS];
int wingCount;
public:
Block(int blockNumber = 0) : blockNumber(blockNumber), wingCount(0) {}
void input() {
cout << "Enter Block Number: ";
cin >> blockNumber;
cout << "Enter number of wings in the block: ";
cin >> wingCount;
for (int i = 0; i < wingCount; ++i) {
cout << "Enter details for wing " << i + 1 << ":" << endl;
wings[i].input();
}
}
void display() const {
cout << "Block Number: " << blockNumber << endl;
for (int i = 0; i < wingCount; ++i) {
wings[i].display();
}
}
void save(ofstream& file) const {
file << blockNumber << endl;
file << wingCount << endl;
for (int i = 0; i < wingCount; ++i) {
wings[i].save(file);
}
}
void load(ifstream& file) {
file >> blockNumber;
file >> wingCount;
file.ignore();
for (int i = 0; i < wingCount; ++i) {
wings[i].load(file);
}
}
};
class PrisonManagementSystem {
private:
Warden warden;
Guard guards[MAX_GUARDS];
int guardCount;
Block blocks[MAX_BLOCKS];
int blockCount;
Log systemLog;
Inventory prisonInventory;
Meal mealSchedule;
Activity prisonerActivities;
string adminID;
string adminPassword;
public:
PrisonManagementSystem() : guardCount(0), blockCount(0), adminID("admin"), adminPassword("password123") {}

void inputWarden() {
cout << "Enter Warden details:" << endl;
warden.input();
}

void inputGuards() {
cout << "Enter number of guards: ";
cin >> guardCount;
for (int i = 0; i < guardCount; ++i) {
cout << "Enter details for guard " << i + 1 << ":" << endl;
guards[i].input();
}
}

void inputWings() {
cout << "Enter number of blocks: ";
cin >> blockCount;
for (int i = 0; i < blockCount; ++i) {
cout << "Enter details for block " << i + 1 << ":" << endl;
blocks[i].input();
}
}

void inputInventory() {
prisonInventory.input();
}

void inputMeals() {
mealSchedule.input();
}

void inputLogs() {
systemLog.input();
}

void inputActivities() {
prisonerActivities.input();
}

void saveData() {
ofstream file("prison_data.txt");

if (!file) {
cout << "Error opening file for saving." << endl;
return;
}

warden.save(file);

file << guardCount << endl;
for (int i = 0; i < guardCount; ++i) {
guards[i].save(file);
}

file << blockCount << endl;
for (int i = 0; i < blockCount; ++i) {
blocks[i].save(file);
}

prisonInventory.save(file);
mealSchedule.save(file);
systemLog.save(file);
prisonerActivities.save(file);

file.close();

cout << "Data successfully saved to prison_data.txt" << endl;
}

void loadData() {
ifstream file("prison_data.txt");

if (!file) {
cout << "Error opening file for loading." << endl;
return;
}

warden.load(file);

file >> guardCount;
file.ignore();
for (int i = 0; i < guardCount; ++i) {
guards[i].load(file);
}

file >> blockCount;
file.ignore();
for (int i = 0; i < blockCount; ++i) {
blocks[i].load(file);
}

prisonInventory.load(file);
mealSchedule.load(file);
systemLog.load(file);
prisonerActivities.load(file);

file.close();

cout << "Data successfully loaded from prison_data.txt" << endl;
}

void display() const {
cout << "\nWarden Information:" << endl;
warden.display();
cout << "\nGuards Information:" << endl;
for (int i = 0; i < guardCount; ++i) {
guards[i].display();
}
cout << "\nBlocks Information:" << endl;
for (int i = 0; i < blockCount; ++i) {
blocks[i].display();
}
prisonInventory.display();
mealSchedule.display();
systemLog.display();
prisonerActivities.display();
}

bool adminLogin() {
string enteredID, enteredPassword;
cout << "Enter Admin ID: ";
cin >> enteredID;
cout << "Enter Admin Password: ";
cin >> enteredPassword;

return (enteredID == adminID && enteredPassword == adminPassword);
}
};
int main() {
PrisonManagementSystem system;
if (!system.adminLogin()) {
cout << "Invalid credentials. Exiting..." << endl;
return 0;
}
cout << "Loading saved data..." << endl;
system.loadData();

int choice;
do {
cout << "\nPrison Management System" << endl;
cout << "1. Enter Warden Information" << endl;
cout << "2. Enter Guards Information" << endl;
cout << "3. Enter Wings Information" << endl;
cout << "4. Enter Inventory Information" << endl;
cout << "5. Enter Meals Information" << endl;
cout << "6. Enter Logs Information" << endl;
cout << "7. Enter Activities Information" << endl;
cout << "8. Save Data" << endl;
cout << "9. Load Data" << endl;
cout << "10. Display All Information" << endl;
cout << "11. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice;

switch (choice) {
case 1: system.inputWarden(); break;
case 2: system.inputGuards(); break;
case 3: system.inputWings(); break;
case 4: system.inputInventory(); break;
case 5: system.inputMeals(); break;
case 6: system.inputLogs(); break;
case 7: system.inputActivities(); break;
case 8: system.saveData(); break;
case 9: system.loadData(); break;
case 10: system.display(); break;
case 11: cout << "Exiting..." << endl; break;
default: cout << "Invalid choice. Try again." << endl; break;
}

} while (choice != 11);

return 0;
}
