#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
//#include <list>
using namespace std;

//test
int SizeofLinkedList = 1;
int tutorID = 1;
time_t now = time(0);
tm* nowTime = localtime(&now);
int year = nowTime->tm_year+1900;
int month = nowTime->tm_mon;

struct Record {
    int tutorID;
    string name;
    int hourly_rate;
    string phone_number;
    string address;
    int centreCode;
    string centreName;
    int subjectCode;
    string subjectName;
    int rating;
    int monthHir;
    int dayHir;
    int yearHir;
    int monthTer;
    int dayTer;
    int yearTer;
    Record* nextAddress;
    Record* prevAddress;
} *head, * sorted;

Record* createNewNode(int tutorID, string name, int hourly_rate, string phone_number, string address, int centreCode, string centreName,
    int subjectCode, string subjectName, int rating, int monthHir, int dayHir, int yearHir, int monthTer, int dayTer, int yearTer)
{
    Record* newnode = new Record;
    newnode->tutorID = tutorID;
    newnode->name = name;
    newnode->hourly_rate = hourly_rate;
    newnode->phone_number = phone_number;
    newnode->address = address;
    newnode->centreCode = centreCode;
    newnode->centreName = centreName;
    newnode->subjectCode = subjectCode;
    newnode->subjectName = subjectName;
    newnode->rating = rating;
    newnode->monthHir = monthHir;
    newnode->dayHir = dayHir;
    newnode->yearHir = yearHir;  
    newnode->monthTer = monthTer;
    newnode->dayTer = dayTer;
    newnode->yearTer = yearTer;
    newnode->nextAddress = NULL;
    newnode->prevAddress = NULL;
    
    return newnode;
}

int calculateNodesinLinkedlist()
{
    Record* current = head;

    int count = 0;

    while (current != NULL)
    {
        count++;
        current = current->nextAddress;
    }
    return count;
}

void sortAlgoHourlyRate(struct Record* newnode) {
    if (sorted == NULL || sorted->hourly_rate >= newnode->hourly_rate) {
        newnode->nextAddress = sorted;
        sorted = newnode;
    }
    else {
        Record* current = sorted;
        //if (current->nextAddress) cout << current->nextAddress->rating << " " << newnode->rating << endl;
        while (current->nextAddress != NULL && current->nextAddress->hourly_rate <= newnode->hourly_rate) {
            current = current->nextAddress;
        }
        newnode->nextAddress = current->nextAddress;
        current->nextAddress = newnode;
    }
}

void sortAlgoRating(struct Record* newnode) {
    if (sorted == NULL || sorted->rating >= newnode->rating) {
        newnode->nextAddress = sorted;
        sorted = newnode;
    }
    else {
        Record* current = sorted;
        //if (current->nextAddress) cout << current->nextAddress->rating << " " << newnode->rating << endl;
        while (current->nextAddress != NULL && current->nextAddress->rating <= newnode->rating) {
            current = current->nextAddress;
        }
        newnode->nextAddress = current->nextAddress;
        current->nextAddress = newnode;
    }
}

void sortAlgoABC(struct Record* newnode) {
    if (sorted == NULL || sorted->name >= newnode->name) {
        newnode->nextAddress = sorted;
        sorted = newnode;
    }
    else {
        Record* current = sorted;
        //if (current->nextAddress) cout << current->nextAddress->name << " " << newnode->name << endl;
        while (current->nextAddress != NULL && current->nextAddress->name <= newnode->name) {
            current = current->nextAddress;
        }
        newnode->nextAddress = current->nextAddress;
        current->nextAddress = newnode;
    }
}

void sortAlgoID(struct Record* newnode) {
    if (sorted == NULL || sorted->tutorID >= newnode->tutorID) {
        newnode->nextAddress = sorted;
        sorted = newnode;
    }
    else {
        Record* current = sorted;
        //if (current->nextAddress) cout << current->nextAddress->tutorID << " " << newnode->tutorID << endl;
        while (current->nextAddress != NULL && current->nextAddress->tutorID <= newnode->tutorID) {
            current = current->nextAddress;
        }
        newnode->nextAddress = current->nextAddress;
        current->nextAddress = newnode;
    }
}

void insertionsortHourlyRate() {
    sorted = NULL;
    Record* current = head;
    //Traverse the given linked list and insert every node to sorted
    while (current != NULL) {
        // Store next for next iteration
        Record* next = current->nextAddress;
        //insert current in sorted linked list
        sortAlgoHourlyRate(current);
        //update current
        current = next;
    }
    //update head to point to sorted linked list
    head = sorted;
}

void insertionsortRating() {
    sorted = NULL;
    Record* current = head;
    //Traverse the given linked list and insert every node to sorted
    while (current != NULL) {
        // Store next for next iteration
        Record* next = current->nextAddress;
        //insert current in sorted linked list
        sortAlgoRating(current);
        //update current
        current = next;
    }
    //update head to point to sorted linked list
    head = sorted;
}

void insertionsortABC() {
    sorted = NULL;
    Record* current = head;
    //Traverse the given linked list and insert every node to sorted
    while (current != NULL) {
        // Store next for next iteration
        Record* next = current->nextAddress;
        //insert current in sorted linked list
        sortAlgoABC(current);
        //update current
        current = next;
    }
    //update head to point to sorted linked list
    head = sorted;
}

void insertionsortID() {
    sorted = NULL;
    Record* current = head;
    //Traverse the given linked list and insert every node to sorted
    while (current != NULL) {
        // Store next for next iteration
        Record* next = current->nextAddress;
        //insert current in sorted linked list
        sortAlgoID(current);
        //update current
        current = next;
    }
    //update head to point to sorted linked list
    head = sorted;
}

void insertIntoTheEndofList(Record* newnode){
    //check whether the list is empty?
    if (head == NULL) //list is empty
    {
        head = newnode;
    }
    else //list is not empty
    {
        Record* current = head;
        // find the last node in the list
        while (current->nextAddress != NULL){
            current = current->nextAddress;
            
        }
        // assign the addresses
        current->nextAddress = newnode;
        newnode->prevAddress = current;
    }
    ::tutorID++;
    ::SizeofLinkedList++;
}

bool isNumber(const string& str){
    for(char const &c : str){
        if(isdigit(c)==0)
            return false;
    }
    return true;
}

void modifyRecord(int ID) {
    Record* current = head;
    while (current != NULL) {
        while (current->tutorID != ID) {
            current = current->nextAddress;
            continue; //sampe ketemu bru lanjut code nya
        }
        int choice;
        cout << "Which one would u like to modify ?" << endl;
        cout << "1. Address" << endl;
        cout << "2. Phone Number" << endl;
        cout << "3. Termination Date" << endl;
        cout << "0. Baack to Home" << endl;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter correct choice" << endl;
            cin >> choice;
        }
        if (!cin.fail()) {
            if (choice == 1) {
                string newAddress;
                cout << "Fill up the new address" << endl;
                cin >> newAddress;
                current->address = newAddress;
                cout << "Modify successful" << endl;
                break;
            }
            else if (choice == 2) {
                while (true) {
                    string newPhonenum;
                    cout << "Fill up the new Phone number" << endl;
                    cin >> newPhonenum;
                    if (!isNumber(newPhonenum)) {
                        cout << "Please Enter correct Phone number" << endl;
                    }
                    else {
                        current->phone_number = newPhonenum;
                        cout << "Modify succesful" << endl;
                        break;
                    }
                    break;
                }
                break;
            }
            else if (choice == 3) {
                int monthTer, dayTer, yearTer;
                while (true) {

                    cout << "Fill up the termination date detail" << endl;
                    cout << "Enter Month Terminated: ";
                    cin >> monthTer;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter correct month" << endl;
                        cin >> monthTer;
                    }
                    if (!cin.fail()) {
                        if (monthTer < 1 || monthTer > 12) {
                            cout << "Please enter correct month" << endl;
                        }
                        else {
                            current->monthTer = monthTer;
                        }
                    }
                    break;
                }

                while (true) {
                    cout << "Enter Day Terminated: ";
                    cin >> dayTer;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter correct day" << endl;
                        cin >> dayTer;
                    }
                    if (!cin.fail()) {
                        if (dayTer < 1 || dayTer > 32) {
                            cout << "Please enter correct day" << endl;
                        }
                        else {
                            current->dayTer = dayTer;
                        }
                    }
                    break;
                }
                while (true) {
                    cout << "Enter Year Terminated: ";
                    cin >> yearTer;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter correct year" << endl;
                        cin >> yearTer;
                    }
                    if (!cin.fail()) {
                        if (yearTer < 1800 || yearTer > year) {
                            cout << "Please enter correct year" << endl;
                        }
                        else {
                            current->yearTer = yearTer;
                        }
                    }
                    break;
                }
                cout << "Modify successful" << endl;
                break;
            }
        }
        else if (choice == 0) {
            cout << "Back successful" << endl;
            break;
        }
        else {
            cout << "Please try again and choose 0-4" << endl;
            continue;
        }

        //return true;
    }
    //return false;
}

void searchRecordbyKeyword(string keyword)
{
    Record* current = head;
    int count = 1;
    //int position = 1;
    while (current != NULL)
    {
        //linear search the centre name
        //if (current->centreName.find(keyword) != string::npos)
        if(current->centreName == keyword)
        {
            cout << current->tutorID << " - " << current->name << endl;
            count++;
        }
        //position++;
        current = current->nextAddress;
        //if (count == 2) return;
    }
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "***************************************** Display successful *******************************************" << endl;
}

void searchRecordbyKeyword2(string keyword)
{
    Record* current = head;
    int count = 1;
    //int position = 1;
    while (current != NULL)
    {
        //linear search the centre name
        //if (current->centreName.find(keyword) != string::npos)
        if (current->centreName == keyword)
        {
            cout << endl << "Tutor Id: " << current->tutorID << endl;
            cout << "Tutor Name: " << current->name << endl;
            cout << "Pay Rate: " << current->hourly_rate << endl;
            cout << "Phone Number: " << current->phone_number << endl;
            cout << "Address: " << current->address << endl;
            cout << "Center Code: " << current->centreCode << endl;
            cout << "Center Name: " << current->centreName << endl;
            cout << "Subject Code: " << current->subjectCode << endl;
            cout << "Subject Name: " << current->subjectName << endl;
            cout << "Rating: " << current->rating << endl;
            cout << "Date Hired(MM/DD/YYYY): " << current->monthHir << "/" << current->dayHir << "/" << current->yearHir << endl;
            cout << "Date Termniated(MM/DD/YYYY): " << current->monthTer << "/" << current->dayTer << "/" << current->yearTer << endl << endl;
            count++;
        }
        //position++;
        current = current->nextAddress;
        //if (count == 2) return;
    }
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "***************************************** Display successful *******************************************" << endl;
}

void searchRecordbyKeyword() {
    Record* current = head;
    //int count = 1;
    //int position = 1;
    while (current != NULL){
        cout << endl << "Tutor Id: " << current->tutorID << endl;
        cout << "Tutor Name: " << current->name << endl;
        cout << "Pay Rate: " << current->hourly_rate << endl;
        cout << "Phone Number: " << current->phone_number << endl;
        cout << "Address: " << current->address << endl;
        cout << "Center Code: " << current->centreCode << endl;
        cout << "Center Name: " << current->centreName << endl;
        cout << "Subject Code: " << current->subjectCode << endl;
        cout << "Subject Name: " << current->subjectName << endl;
        cout << "Rating: " << current->rating << endl;
        cout << "Date Hired(MM/DD/YYYY): " << current->monthHir << "/" << current->dayHir << "/" << current->yearHir << endl;
        cout << "Date Termniated(MM/DD/YYYY): " << current->monthTer << "/" << current->dayTer << "/" << current->yearTer << endl << endl;
        //count++;
        current = current->nextAddress;
    }
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "***************************************** Display successful *******************************************" << endl;
}

//for id validation in modify
bool searchRecordbyKeyword(int id)
{
    Record* current = head;
    int count = 1;
    //int position = 1;
    while (current != NULL)
    {
        //linear search the centre name
        //if (current->centreName.find(keyword) != string::npos)
        if (current->tutorID == id)
        {
            return true;
            count++;
        }
        //position++;
        current = current->nextAddress;
        //if (count == 2) return;
    }
    return false;
    //cout << "--------------------------------------------------------------------------------------------------------" << endl;
    //cout << "***************************************** Display successful *******************************************" << endl;
}

//Search for an  id (binary search)
//GET THE MIDDLE VARIABLE OF THE
struct Record* middleNode(Record* start, Record* last) {
    if (start == NULL) {
        return NULL;
    }
    struct Record* slow_ptr = start;
    struct Record* fast_ptr = start->nextAddress;

    while (fast_ptr != last) {
        fast_ptr = fast_ptr->nextAddress;
        if (fast_ptr != last) {
            slow_ptr = slow_ptr->nextAddress;
            fast_ptr = fast_ptr->nextAddress;
        }
    }
    return slow_ptr;
}

// Search on linked list
struct Record* binarySearch(Record** head, int value)
{
    //struct Record* start = head;
    Record* last = NULL;
    Record* start = *head;
    //Record* current = *head_ref;
    do {
        // Find middle
        Record* mid = middleNode(start, last);

        // If middle is empty
        if (mid == NULL) {
            return NULL;
        }

        // If value is present at middle
        if (mid->tutorID == value) {
            return mid;
        }

        // If value is more than mid
        else if (mid->tutorID < value) {
            start = mid->nextAddress;
        }

        // If the value is less than mid.
        else {
            last = mid;
        }

    } while (last == NULL ||
        last != start);

    // value not found
    return NULL;
}

//Print one node
void printOne(Record* current) {
    cout << endl << "Tutor Id: " << current->tutorID << endl;
    cout << "Tutor Name: " << current->name << endl;
    cout << "Pay Rate: " << current->hourly_rate << endl;
    cout << "Phone Number: " << current->phone_number << endl;
    cout << "Address: " << current->address << endl;
    cout << "Center Code: " << current->centreCode << endl;
    cout << "Center Name: " << current->centreName << endl;
    cout << "Subject Code: " << current->subjectCode << endl;
    cout << "Subject Name: " << current->subjectName << endl;
    cout << "Rating: " << current->rating << endl;
    cout << "Date Hired(MM/DD/YYYY): " << current->monthHir << "/" << current->dayHir << "/" << current->yearHir << endl;
    cout << "Date Termniated(MM/DD/YYYY): " << current->monthTer << "/" << current->dayTer << "/" << current->yearTer << endl << endl;
}

//LINEAR SEARCH for multiple data according to the variable
//linear search by rating for admin
void linearSearch(Record** head, int search, string center) {
    Record* current = *head;
    Record* current2; //tail

    while (current != NULL) {
        bool found = false;
        while (true) {
            if (current == NULL) {
                cout << "Tutor from this admin account not found" << endl;
                break;
            }
            if (current->centreName == center && current->rating == search) {
                printOne(current);
                found = true;
                break;
            }
            current2 = current; //tail
            current = current->nextAddress;
        }

        if (!found) {
            break;
        }

        bool t = true;
        while (t)
        {
            cout << "Next or Previous (1 = next, 2 = previous, 0 = to go back) ?" << endl;
            int input;
            cin >> input;

            if (input == 1) {
                Record* prevNode = current;
                bool found = false;
                while (!found) {
                    current2 = current; //tail
                    current = current->nextAddress;
                    if (current == NULL) {

                        //cout << current->name;
                        current = prevNode;
                        printOne(prevNode);
                        cout << "Out of Range! Enter 2 Please" << endl;
                        break;
                    }
                    if (current->centreName == center && current->rating == search) {
                        printOne(current);
                        prevNode = current;
                        found = true;
                    }
                }
            }
            else if (input == 2) {
                Record* prevNode = current;
                bool found = false;
                while (!found) {
                    if (current->prevAddress == NULL) {
                        current = prevNode;
                        printOne(prevNode);
                        cout << "Out of Range! Enter 1 Please" << endl;
                        break;
                    }
                    current = current->prevAddress;
                    if (current->centreName == center && current->rating == search) {
                        printOne(current);
                        prevNode = current;
                        found = true;
                        break;
                    }
                }
            }
            else if (input == 0) {
                t = false;
            }
        }
        break;
    }
}

//Linear search by rating for HR
void HRlinearSearch(Record** head, int search) {
    Record* current = *head;
    Record* current2; //tail

    while (current != NULL) {
        bool found = false;
        while (true) {
            if (current == NULL) {
                cout << "Tutor from this admin account not found" << endl;
                break;
            }
            if (current->rating == search) {
                printOne(current);
                found = true;
                break;
            }
            current2 = current; //tail
            current = current->nextAddress;
        }

        if (!found) {
            break;
        }

        bool t = true;
        while (t)
        {
            cout << "Next or Previous (1 = next, 2 = previous, 0 = to go back) ?" << endl;
            int input;
            cin >> input;

            if (input == 1) {
                Record* prevNode = current;
                bool found = false;
                while (!found) {
                    current2 = current; //tail
                    current = current->nextAddress;
                    if (current == NULL) {
                        current = prevNode;
                        printOne(prevNode);
                        cout << "Out of Range! Enter 2 Please" << endl;
                        break;
                    }
                    if (current->rating == search) {
                        printOne(current);
                        prevNode = current;
                        found = true;
                    }
                }
            }
            else if (input == 2) {
                Record* prevNode = current;
                bool found = false;
                while (!found) {
                    if (current->prevAddress == NULL) {
                        current = prevNode;
                        printOne(prevNode);
                        cout << "Out of Range! Enter 1 Please" << endl;
                        break;
                    }
                    current = current->prevAddress;
                    if (current->rating == search) {
                        printOne(current);
                        prevNode = current;
                        found = true;
                        break;
                    }
                }
            }
            else if (input == 0) {
                t = false;
            }
        }
        break;
    }
}

void deleteNodebasedonKeyword(int keyword)
{
    // scenario 1: linked list is still empty
    if (head == NULL)
    {
        cout << "Empty list! Nothing to delete!" << endl;
        return;
    }
    // scenario 2: head name = keyword
    else if (head->tutorID == keyword) // delete from the front of the list
    {
        Record* current = head;
        head = head->nextAddress;
        head->prevAddress = NULL;
        if (month - head->monthTer >= 6 && year - head->yearTer >= 1) {
            cout << "Tutor with " << current->tutorID << " is deleted from the list!" << endl;
            delete current;
            ::SizeofLinkedList--;
            if (head == NULL)
            {
                cout << "The list is now Empty" << endl;
            }
        }
        cout << "cant delete not yet pass 6 month" << endl;
        return;
    }
    // scenario 3: where the keyword unable to find in first item
    else
    {
        //BINARY SEARCH
        Record* deletedNode = binarySearch(&head, keyword);

        if (deletedNode == NULL) {
            cout << "Sorry tutor not found" << endl;
        }
        else {
            if (month - deletedNode->monthTer > 6 || year - deletedNode->yearTer >= 1) {
                cout << "TutorID with " << deletedNode->tutorID << " ID is deleted from the list!" << endl;
                //CHECK IF THE TUTOR TERMINATE DATE IS OVER 6 MONTH

                Record* nextNode = deletedNode->nextAddress;
                Record* prevNode = deletedNode->prevAddress;

                prevNode->nextAddress = nextNode;
                nextNode->prevAddress = prevNode;

                delete deletedNode;

                ::SizeofLinkedList--;
                return;
            }
            cout << "Tutor with " << keyword << " ID is not found in the list!" << endl;
        }
    }
}

void add(string centreNamee, int centreCodee) {
    int tutorID, hourly_rate, subjectCode, rating, monthHir, dayHir, yearHir;
    string name, phone_number, address, subjectName;
    int centreCode = centreCodee;
    string centreName = centreNamee;
    int monthTer = 00;
    int dayTer = 00;
    int yearTer = 0000;

    bool loop = true;
    while (loop){
        //auto generated tutor ID
        tutorID = ::tutorID;
        cout << "Enter Name: ";
        cin >> name;
        while (true) {
            cout << "Enter hourly rate: ";
            cin >> hourly_rate;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter correct hourly rate" << endl;
                cin >> hourly_rate;
            }if (!cin.fail()) {
                break;
            }
        }
        while (true) {
            cout << "Enter phone number: ";
            cin >> phone_number;
            if (!isNumber(phone_number)) {
                cout << "Please enter a correct Phone Number" << endl;
            }
            else {
                break;
            }
        }
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter subject code: ";
        cin >> subjectCode;
        cout << "Enter subject name: ";
        cin >> subjectName;
        while (true) {
            cout << "Enter rating: ";
            cin >> rating;
            if (rating < 0 || rating > 6) {
                cout << "Please enter a correct rating 1 - 5" << endl;
            }
            else {
                break;
            }
        }
        while (true) {
            cout << "Enter Month Hired: ";
            cin >> monthHir;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter correct month hired" << endl;
                cin >> monthHir;
            }if (!cin.fail()) {
                break;
            }
        }
        while (true) {
            cout << "Enter Day Hired: ";
            cin >> dayHir;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter correct day hired" << endl;
                cin >> dayHir;
            }if (!cin.fail()) {
                break;
            }
        }

        while (true) {
            cout << "Enter Year Hired: ";
            cin >> yearHir;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter correct year hired" << endl;
                cin >> yearHir;
            }if (!cin.fail()) {
                break;
            }
        }

        Record* newnode10 = createNewNode(tutorID, name, hourly_rate, phone_number, address, centreCode, centreName,
            subjectCode, subjectName, rating, monthHir, dayHir, yearHir, monthTer, dayTer, yearTer);
        insertIntoTheEndofList(newnode10);

        cout << "Would u like to add more ?" << endl
            << "Y/N";
        string choice;
        cin >> choice;
        if (choice == "n")
        {
            cout << "Add Successful" << endl;
            loop = false;
        }
        else if (choice == "y")
        {
            continue;
        }
        else
        {
            cout << "Please type y or n " << endl;
        }
    }
}

void displayBackForth(Record** head, string search) {
    //linear search on the nodes that has the search location
    Record* current = *head;
    Record* current2; //tail

    while (current != NULL)
    {
        bool found = false;
        while (true) {
            if (current == NULL) {
                cout << "Tutor from this admin account not found" << endl;
                break;
            }
            if (current->centreName == search) {
                printOne(current);
                found = true;
                break;
            }
            current2 = current; //tail
            current = current->nextAddress;
        }
        if (!found) {
            break;
        }
        bool t = true;
        while (t)
        {
            cout << "Next or Previous (1 = next, 2 = previous, 0 = to go back) ?" << endl;
            int input;
            cin >> input;

            if (input == 1)
            {
                Record* prevNode = current;
                bool found = false;
                while (!found) {
                    current2 = current; //tail
                    current = current->nextAddress;
                    if (current == NULL) {
                        //cout << current->name;
                        current = prevNode;
                        printOne(prevNode);
                        cout << "Out of Range! Enter 2 Please" << endl;
                        break;
                    }
                    if (current->centreName == search) {
                        printOne(current);
                        prevNode = current;
                        found = true;
                    }
                }
            }
            else if (input == 2)
            {
                Record* prevNode = current;
                bool found = false;
                while (!found) {
                    if (current->prevAddress == NULL) {
                        current = prevNode;
                        printOne(prevNode);
                        cout << "Out of Range! Enter 1 Please" << endl;
                        break;
                    }
                    current = current->prevAddress;
                    if (current->centreName == search) {
                        printOne(current);
                        prevNode = current;
                        found = true;
                        break;
                    }
                }
            }
            else if (input == 0) {
                t = false;
            }
        }
        break;
    }
}

void HRdisplayBackForth(Record** head) {
    //linear search on the nodes that has the search location
    Record* current = *head;
    Record* current2; //tail

    while (current != NULL)
    {
        bool found = false;
        while (true) {
            if (current == NULL) {
                cout << "Tutor from this admin account not found" << endl;
                break;
            }
            //if (current->centreName == search) {
            printOne(current);
            found = true;
            break;
            //}
            current2 = current; //tail
            current = current->nextAddress;
        }
        if (!found) {
            break;
        }
        bool t = true;
        while (t)
        {
            cout << "Next or Previous (1 = next, 2 = previous, 0 = to go back) ?" << endl;
            int input;
            cin >> input;

            if (input == 1)
            {
                Record* prevNode = current;
                bool found = false;
                while (!found) {
                    current2 = current; //tail
                    current = current->nextAddress;
                    if (current == NULL) {
                        //cout << current->name;
                        current = prevNode;
                        printOne(prevNode);
                        cout << "Out of Range! Enter 2 Please" << endl;
                        break;
                    }
                    //if (current->centreName == search) {
                    printOne(current);
                    prevNode = current;
                    found = true;
                    //}
                }
            }
            else if (input == 2)
            {
                Record* prevNode = current;
                bool found = false;
                while (!found) {
                    if (current->prevAddress == NULL) {
                        current = prevNode;
                        printOne(prevNode);
                        cout << "Out of Range! Enter 1 Please" << endl;
                        break;
                    }
                    current = current->prevAddress;
                    //if (current->centreName == search) {
                    printOne(current);
                    prevNode = current;
                    found = true;
                    break;
                    //}
                }
            }
            else if (input == 0) {
                t = false;
            }
        }
        break;
    }
}

void homeAdmin(string centreNamee, int centreCodee, struct Record** head_ref) {
    while (true) {
        cout << "Welcome to Admin system for centre " << centreNamee << endl;
        cout << "Choose the menu ?" << endl;
        cout << "1. View Tutor record" << endl;
        cout << "2. Add/Delete/Modify Tutor Record" << endl;
        cout << "3. Sort Tutor Record" << endl;
        cout << "0. Log Out" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            while (true) {
                cout << "View or Search Tutor ? " << endl;
                cout << "1. View All Tutor record" << endl;
                cout << "2. Search Tutor record by ID" << endl;
                cout << "3. Search Tutor record by Rating" << endl;
                cout << "0. To go back" << endl;
                int choice;
                cin >> choice;
                if (choice == 1) {
                    //searchRecordbyKeyword(centreNamee);
                    displayBackForth(head_ref, centreNamee);
                    cout << endl;
                    //cout << "The total item in Linked list is " << calculateNodesinLinkedlist() << endl;
                }
                else if (choice == 2) {
                    bool flag = true;
                    while (flag) {
                        cout << "Search Tutor record by ID" << endl;
                        cout << "Please enter the Tutor ID or 0 to go back" << endl;
                        int inputID;
                        //validate string input
                        cin >> inputID;
                        Record* searchedNode = binarySearch(head_ref, inputID);

                        if (inputID == 0) {
                            break;
                            //break;
                        }
                        else{
                            //check location of tutor and user
                            if (searchedNode == NULL) {
                                while (true) {
                                    cout << "Searched ID not found" << endl;
                                    cout << "Try again? 1 for yes, 2 for no" << endl;
                                    int choice;
                                    cin >> choice;
                                    if (choice == 1) {
                                        break;
                                    }
                                    else if (choice == 2) {
                                        flag = false;
                                        break;
                                    }
                                    else {
                                        cout << "Please enter 1 or 2" << endl;
                                    }
                                }
                            }
                            else{
                                cout << searchedNode->tutorID << " - " << searchedNode->name << " - " << searchedNode->monthHir << searchedNode->dayHir << searchedNode->yearHir << " - " << searchedNode->hourly_rate << " - " << searchedNode->phone_number << " - " << searchedNode->address << " - " << searchedNode->centreCode << " - " << searchedNode->centreCode << " - " << searchedNode->centreName << " - " << searchedNode->subjectName << " - " << searchedNode->rating << endl;
                                cout << "Tutor Found" << endl;
                                //print searchedNode
                            }
                        }
                    }
                }
                else if (choice == 3) {
                    bool flag = true;
                    while (flag) {
                        cout << "Search Tutor record by Rating" << endl;
                        cout << "Please enter the Rating of the Tutor from 0-5"<< endl << "or 6 to go back" << endl;
                        int input;
                        cin >> input;
                        //int rating = stoi(input);
                        if (input == 6) {
                            break;
                        }
                        linearSearch(head_ref, input, centreNamee);
                    }
                }
                else if (choice == 0) {
                    break;
                }
                else{
                    cout << "Please input 1 or 2 or 3 or 0";
                }
            }
        }
        else if (choice == 2)
        {
            while (true) {
                cout << "1. Add Record" << endl;
                cout << "2. Remove Record" << endl;
                cout << "3. Modify Record" << endl;
                cout << "0. Back" << endl;
                int choice;
                cin >> choice;
                if (choice == 1)
                {
                    add(centreNamee, centreCodee);
                }
                else if (choice == 2) {
                    searchRecordbyKeyword(centreNamee);
                    cout << "Which record would u like to delete base on tutorID ?" << endl;
                    int ID;
                    cin >> ID;
                    deleteNodebasedonKeyword(ID);
                    searchRecordbyKeyword(centreNamee);
                }
                else if (choice == 3) {
                    cout << "Here are the list of modifiable tutors" << endl;
                    searchRecordbyKeyword(centreNamee);
                    cout << "Type in the ID you want to modify ?" << endl;
                    int id;
                    cin >> id;

                    if (searchRecordbyKeyword(id) == true) {
                        modifyRecord(id);
                        break;
                    }
                    else {
                        cout << "ID is not found" << endl;
                        //continue;
                    }
                }
                else if (choice == 0) {
                    cout << "Back successful" << endl;
                    break;
                }
                else {
                    cout << "Please input 1 or 2 or 3 or 0";
                }
            }
        }
        else if (choice == 3)
        {
            while (true) {
                cout << "Sort by ?" << endl;
                cout << "1. Sort by ID" << endl;
                cout << "2. Sort by Alphabetically" << endl;
                cout << "3. Sort by Rating" << endl;
                cout << "4. Sort by Payrate" << endl;
                cout << "0. Exit" << endl;
                cout << "Choose from 1 - 0 : ";
                int choice;
                cin >> choice;
                if (choice == 1) {
                    //sort by id
                    insertionsortID();
                    searchRecordbyKeyword2(centreNamee);
                    cout << "Enter anything to continue" << endl;
                    string any;
                    cin >> any;
                }
                else if (choice == 2) {
                    //sort alphabetically
                    insertionsortABC();
                    searchRecordbyKeyword2(centreNamee);
                    cout << "Enter anything to continue" << endl;
                    string any;
                    cin >> any;
                }
                else if (choice == 3) {
                    insertionsortRating();
                    searchRecordbyKeyword2(centreNamee);
                    cout << "Enter anything to continue" << endl;
                    string any;
                    cin >> any;
                }
                else if (choice == 4) {
                    insertionsortHourlyRate();
                    searchRecordbyKeyword2(centreNamee);
                    cout << "Enter anything to continue" << endl;
                    string any;
                    cin >> any;
                }
                else if (choice == 0) {
                    insertionsortID();
                    break;
                }
                else {
                    cout << "Please input 1, 2, 3, 4, or 0";
                }
            }

        }
        else if (choice == 0)
        {
            cout << "Logout successful" << endl;
            break;
            //return;
        }
        else
        {
            cout << "Please try again, choose 1, 2, 3, 0" << endl;
        }
    }
}

int askCentercode() {
    bool wrong = true;
    int num;
    while (wrong) {
        cout << "Select the to location to add the Tutor" << endl;
        cout << "1. 101, Subang" << endl;
        cout << "2. 102, Subang" << endl;
        cout << "3. 103, Cyberjaya" << endl;

        cin >> num;
        if (num == 1 || num == 2 || num == 3) {
            wrong = false;
            break;
        }
        cout << "incorrect input, please enter 1 or 2 or 3" << endl;
    }
    
    if (num == 1) {
        return 101;
    }
    else if (num == 2) {
        return 102;
    }
    else {
        return 103;
    }
}

string askCentername(int center) {
    if (center == 101) {
        return "Subang";
    }
    else if(center == 102) {
        return "Bukit Jalil";
    }
    else {
        return "Cyberjaya";
    }
}

void homeHR(struct Record** head_ref) {
    //HRdisplayBackForth(head_ref);
    while (true) {
        cout << "Welcome to HR department eXcel Tuition Centre System" << endl;
        cout << "Choose the menu ?" << endl;
        cout << "1. View Tutor record" << endl;
        cout << "2. Add/Delete/Modify Tutor Record" << endl;
        cout << "3. Sort Tutor Record" << endl;
        cout << "0. Log Out" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            while (true) {
                cout << "View or Search Tutor ? " << endl;
                cout << "1. View All Tutor record" << endl;
                cout << "2. Search Tutor record by ID" << endl;
                cout << "3. Search Tutor record by Rating" << endl;
                cout << "0. To go back" << endl;
                int choice;
                cin >> choice;
                if (choice == 1) {
                    //searchRecordbyKeyword(centreNamee);
                    HRdisplayBackForth(head_ref);
                    cout << endl;
                    //cout << "The total item in Linked list is " << calculateNodesinLinkedlist() << endl;
                }
                else if (choice == 2) {
                    bool flag = true;
                    while (flag) {
                        cout << "Search Tutor record by ID" << endl;
                        cout << "Please enter the Tutor ID or 0 to go back" << endl;
                        int inputID;
                        //validate string input
                        cin >> inputID;
                        Record* searchedNode = binarySearch(head_ref, inputID);

                        if (inputID == 0) {
                            break;
                        }
                        else {
                            //check location of tutor and user
                            if (searchedNode == NULL) {
                                while (true) {
                                    cout << "Searched ID not found" << endl;
                                    cout << "Try again? 1 for yes, 2 for no" << endl;
                                    int choice;
                                    cin >> choice;
                                    if (choice == 1) {
                                        break;
                                    }
                                    else if (choice == 2) {
                                        flag = false;
                                        break;
                                    }
                                    else {
                                        cout << "Please enter 1 or 2" << endl;
                                    }
                                }
                            }
                            else {
                                cout << searchedNode->tutorID << " - " << searchedNode->name << " - " << searchedNode->monthHir << searchedNode->dayHir << searchedNode->yearHir << " - " << searchedNode->hourly_rate << " - " << searchedNode->phone_number << " - " << searchedNode->address << " - " << searchedNode->centreCode << " - " << searchedNode->centreCode << " - " << searchedNode->centreName << " - " << searchedNode->subjectName << " - " << searchedNode->rating << endl;
                                cout << "Tutor Found" << endl;
                                //print searchedNode
                            }
                        }
                    }
                }
                else if (choice == 3) {
                    bool flag = true;
                    while (flag) {
                        cout << "Search Tutor record by Rating" << endl;
                        cout << "Please enter the Rating of the Tutor from 0-5" << endl << "or 6 to go back" << endl;
                        int input;
                        cin >> input;
                        if (input == 6) {
                            break;
                        }
                        HRlinearSearch(head_ref,input);
                    }
                }
                else if (choice == 0) {
                    break;
                }
                else {
                    cout << "Please input 1 or 2 or 3 or 0";
                }
            }
        }
        else if (choice == 2)
        {
            while (true) {
                cout << "1. Add Record" << endl;
                cout << "2. Remove Record" << endl;
                cout << "3. Modify Record" << endl;
                cout << "0. Back" << endl;
                int choice;
                cin >> choice;
                if (choice == 1)
                {
                    //ask for the center code
                    int centreCodee = askCentercode();
                    string centreNamee=askCentername(centreCodee);
                    add(centreNamee, centreCodee);
                }
                else if (choice == 2) {
                    searchRecordbyKeyword();
                    cout << "Which record would u like to delete base on tutorID ?" << endl;
                    int ID;
                    cin >> ID;
                    deleteNodebasedonKeyword(ID);
                    //searchRecordbyKeyword(centreNamee);
                }
                else if (choice == 3) {
                    //MODIFY
                    cout << "Here are the list of modifiable tutors" << endl;
                    searchRecordbyKeyword();
                    cout << "Type in the ID you want to modify ?" << endl;
                    int id;
                    cin >> id;
                    

                    if (searchRecordbyKeyword(id) == true) {
                        modifyRecord(id);
                        break;
                    }
                    else {
                        cout << "ID is not found" << endl;
                        //continue;
                    }
                }
                else if (choice == 0) {
                    cout << "Back successful" << endl;
                    break;
                }
                else {
                    cout << "Please input 1 or 2 or 3 or 0";
                }
            }
        }
        else if (choice == 3)
        {
            while (true) {
                cout << "Sort by ?" << endl;
                cout << "1. Sort by ID" << endl;
                cout << "2. Sort by Alphabetically" << endl;
                cout << "3. Sort by Rating" << endl;
                cout << "4. Sort by Payrate" << endl;
                cout << "0. Exit" << endl;
                cout << "Choose from 1 - 0 : ";
                int choice;
                cin >> choice;
                if (choice == 1) {
                    //sort by id
                    insertionsortID();
                    searchRecordbyKeyword();
                    cout << "Enter anything to continue" << endl;
                    string any;
                    cin>>any;
                }
                else if (choice == 2) {
                    //sort alphabetically
                    insertionsortABC();
                    searchRecordbyKeyword();
                    cout << "Enter anything to continue" << endl;
                    string any;
                    cin >> any;
                }
                else if (choice == 3) {
                    //sort by rating
                    insertionsortRating();
                    searchRecordbyKeyword();
                    cout << "Enter anything to continue" << endl;
                    string any;
                    cin >> any;
                }
                else if (choice == 4) {
                    //sort by hourly rate
                    insertionsortHourlyRate();
                    searchRecordbyKeyword();
                    cout << "Enter anything to continue" << endl;
                    string any;
                    cin >> any;
                }
                else if (choice == 0) {
                    insertionsortID();
                    break;
                }
                else {
                    cout << "Please input 1, 2, 3, 4, or 0";
                }
            }

        }
        else if (choice == 0)
        {
            cout << "Logout successful" << endl;
            break;
            //return;
        }
        else
        {
            cout << "Please try again, choose 1, 2, 3, 0" << endl;
        }
    }
}

int main()
{
    head = NULL;

    Record* newnode = new Record;
    newnode->tutorID = 1;
    newnode->name = "Vincent";
    newnode->hourly_rate = 550;
    newnode->phone_number = "027283723";
    newnode->address = "Sunter Hijau";
    newnode->centreCode = 101;
    newnode->centreName = "Subang";
    newnode->subjectCode = 201;
    newnode->subjectName = "Basketball";
    newnode->rating = 5;
    newnode->monthHir = 2;
    newnode->dayHir = 10;
    newnode->yearHir = 2022;
    newnode->monthTer = 00;
    newnode->dayTer = 00;
    newnode->yearTer = 0000;
    newnode->nextAddress = NULL;
    newnode->prevAddress = NULL;
    insertIntoTheEndofList(newnode);

    Record* newnode2 = new Record;
    newnode2->tutorID = 2;
    newnode2->name = "BW";
    newnode2->hourly_rate = 300;
    newnode2->phone_number = "027283723";
    newnode2->address = "Sunter Hijau";
    newnode2->centreCode = 101;
    newnode2->centreName = "Subang";
    newnode2->subjectCode = 201;
    newnode2->subjectName = "Basketball";
    newnode2->rating = 5;
    newnode2->monthHir = 2;
    newnode2->dayHir = 10;
    newnode2->yearHir = 2022;
    newnode2->monthTer = 1;
    newnode2->dayTer = 12;
    newnode2->yearTer = 2019;
    newnode2->nextAddress = NULL;
    newnode2->prevAddress = NULL;
    insertIntoTheEndofList(newnode2);

    Record* newnode3 = new Record;
    newnode3->tutorID = 3;
    newnode3->name = "BJK";
    newnode3->hourly_rate = 500;
    newnode3->phone_number = "027283723";
    newnode3->address = "Sunter Hijau";
    newnode3->centreCode = 101;
    newnode3->centreName = "Subang";
    newnode3->subjectCode = 201;
    newnode3->subjectName = "Basketball";
    newnode3->rating = 4;
    newnode3->monthHir = 2;
    newnode3->dayHir = 10;
    newnode3->yearHir = 2022;
    newnode3->monthTer = 00;
    newnode3->dayTer = 00;
    newnode3->yearTer = 0000;
    newnode3->nextAddress = NULL;
    newnode3->prevAddress = NULL;
    insertIntoTheEndofList(newnode3);

    Record* newnode4 = new Record;
    newnode4->tutorID = 4;
    newnode4->name = "Star";
    newnode4->hourly_rate = 500;
    newnode4->phone_number = "027283723";
    newnode4->address = "Sunter Hijau";
    newnode4->centreCode = 102;
    newnode4->centreName = "Bukit Jalil";
    newnode4->subjectCode = 201;
    newnode4->subjectName = "Basketball";
    newnode4->rating = 5;
    newnode4->monthHir = 2;
    newnode4->dayHir = 10;
    newnode4->yearHir = 2022;
    newnode4->monthTer = 00;
    newnode4->dayTer = 00;
    newnode4->yearTer = 0000;
    newnode4->nextAddress = NULL;
    newnode4->prevAddress = NULL;
    insertIntoTheEndofList(newnode4);

    while (true)
    {
        cout << "Welcome to the eXcel Tuition Centre"<< endl;
        cout << "Username" << endl;
        string username;
        cin >> username;
        cout << "Password" << endl;
        string password;
        cin >> password;

        if (username == "admin1" && password == "admin1")
        {
            homeAdmin("Subang", 101, &newnode);
        }
        else if (username == "admin2" && password == "admin2")
        {
            homeAdmin("Bukit Jalil", 102, &newnode);
        }
        else if (username == "admin3" && password == "admin3")
        {
            homeAdmin("CyberJaya", 103, &newnode);
        }
        else if (username == "HR" && password == "human") {
            homeHR(&newnode);
        }
        else
        {
            cout << "Login Failed" << endl;
        }
    }
}
