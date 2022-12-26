#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date() {
        time_t now = time(0);
        tm* eachTime = localtime(&now);

        year = eachTime->tm_year + 1900;
        month = eachTime->tm_mon + 1;
        day = eachTime->tm_mday;
    }

    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }

    bool validateDate(int day, int month, int year) {
        if (day < 1 || day > 31) {
            return false;
        }
        else if (year > 2022) {
            return false;
        }
        else if (month < 1 || month > 13) {
            return false;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 31) {
                return false;
            }
        }
        else if (month == 2 && year % 4 == 0 && day > 29) {
            return false;
        }
        else if (month == 2 && year % 4 != 0 && day > 30) {
            return false;
        }
        return true;
    }

    bool checkDate(Date terminatedDate) {
        if (year - terminatedDate.getYear() > 1) {
            return true;
        }
        else if (year - terminatedDate.getYear() > 1) {
            return true;
        }
        else if (month - terminatedDate.getMonth() < 6) {
            return false;
        }
        else if (month - terminatedDate.getMonth() == 6 && day < terminatedDate.getDay()) {
            return false;
        }
        return true;
        //        }else if((month - terminatedDate.getMonth()) == 6 && )
    }

};

class Subject
{
private:
    int subjectID;
    string subjectName;
public:

    Subject() {
        subjectID = 0;
        subjectName = "NULL";
    }

    Subject(int subjectID, string subjectName)
    {
        this->subjectID = subjectID;
        this->subjectName = subjectName;
    }

    int getSubjectID()
    {
        return subjectID;
    }

    string getSubjectName()
    {
        return subjectName;
    }


    Subject setSubject(int id)
    {
        if (id == 1001) {
            return Subject(1001, "English");
        }
        else if (id == 1002) {
            return Subject(1002, "Maths");
        }
        else if (id == 1003) {
            return Subject(1003, "Science");
        }
        return Subject(0000, "fhjhjhhihu");
    }

};

class Center {

private:
    int centerID;
    string centerName;

public:

    Center() {
        centerID = 0;
        centerName = "NULL";
    }

    Center(int centerID, string centerName)
    {
        this->centerID = centerID;
        this->centerName = centerName;
    }

    int getCenterID()
    {
        return centerID;
    }

    string getCenterName()
    {
        return centerName;
    }

    Center setCenter(int id) {
        if (id == 101) {
            return Center(101, "Bukit Jalil");
        }
        else if (id == 102) {
            return Center(102, "Subang");
        }
        else if (id == 103) {
            return Center(103, "Petaling Jaya");
        }
        return Center(000, "papa");
    }
};




class Records {
    int tutorID;
    string name;
    Date dateHired;
    Date dateTerminated;
    int rating;
    string phone_number;
    string address;
    Center center;
    Subject subject;
    int payrate;
    string terminated;
    int month;
    int day;
    int year;

public:

    Records(int tutorID, string name, Date dateHired, Date dateTerminated, int rating, string phone_number, string address, Center center, Subject subject, int payrate) {
        this->tutorID = tutorID;
        this->name = name;
        this->dateHired = dateHired;
        this->dateTerminated = dateTerminated;
        this->rating = rating;
        this->phone_number = phone_number;
        this->address = address;
        this->center = center;
        this->subject = subject;
        this->payrate = payrate;

    }

    int getTutorID() {
        return tutorID;
    }

    string getName() {
        return name;
    }

    Date getDateHired() {
        return dateHired;
    }

    Date getDateTerminated() {
        return dateTerminated;
    }

    int getRating() {
        return rating;
    }

    string getPhoneNumber() {
        return phone_number;
    }

    string getAddress() {
        return address;
    }

    Center getCenter() {
        return center;
    }

    Subject getSubject() {
        return subject;
    }

    int getPayrate() {
        return payrate;
    }

    void setDateTerminated(int day, int month, int year) {
        dateTerminated = Date(day, month, year);
    }

    void setPhone(string phone_num) {
        this->phone_number = phone_num;
    }

    void setAddress(string address) {
        this->address = address;
    }
};

template <typename Record> 
class RecordArr {
    Record* record;
    int size;

public:
    int count;

    RecordArr() {
        record = new Record[1];
        size = 1;
        count = 0;
    }

    void insertToArray(Record newArr) {
        if (count == size) {
            Record* tempArr = new Record[size + 1];

            for (int i = 0; i < size; i++) {
                tempArr[i] = record[i];
            }

            delete[] record;
            size++;
            record = tempArr;
        }
        record[count] = newArr;
        count++;
    }
    void printRecord(int index)
    {
        cout << "Tutor ID: " << record[index]->getTutorID() << endl;
        cout << "Name: " << record[index]->getName() << endl;
        cout << "Date Hired:" << record[index]->getDateHired().getDay() << "/" << record[index]->getDateHired().getMonth() << "/" << record[index]->getDateHired().getYear() << endl;
        cout << "Date Terminated: " << record[index]->getDateTerminated().getDay() << "/" << record[index]->getDateTerminated().getMonth() << "/" << record[index]->getDateTerminated().getYear() << endl;
        cout << "Rating: " << record[index]->getRating() << endl;
        cout << "Phone Number: " << record[index]->getPhoneNumber() << endl;
        cout << "Address: " << record[index]->getAddress() << endl;
        cout << "Center: " << record[index]->getCenter().getCenterName() << endl;
        cout << "Subject: " << record[index]->getSubject().getSubjectName() << endl;
        cout << "Payrate: " << record[index]->getPayrate() << endl;
        cout << "******************************************************************" << endl;
        cout << "******************************************************************" << endl;


    }
    int binarySearch(int low, int high, int TutorID) {
        if (high >= low) {
            int mid = low + (high - low) / 2;

            // If the element is present at the middle
            // itself
            if (record[mid]->getTutorID() == TutorID)
                return mid;

            // If element is smaller than mid, then
            // it can only be present in left subarray
            if (record[mid]->getTutorID() > TutorID)
                return binarySearch(low, mid - 1, TutorID);

            // Else the element can only be present
            // in right subarray
            return binarySearch(mid + 1, high, TutorID);
        }
        // We reach here when element is not
        // present in array
        return -1;
    }
    int linearSearch(string search, int choice, int max) {
        // 1 = rating, 2 = location
        //int max = sizeof(arr) / sizeof(arr[0]);
        //int found = -1;
        int i;
        if (choice == 1) {
            //linear search on the nodes that has the search
            for (i = 0; i < max; i++) {
                if (to_string(record[i]->getRating()) == search) {
                    return i;//WHEN FOUND PRINT
                }
            }
            return -1;

        }
        else if (choice == 2) {
            //linear search on the nodes that has the search location
            for (i = 0; i < max; i++) {
                if ((record[i]->getCenter().getCenterID()) == search) {
                    return i;//PRINT
                }
            }
            return -1;
        }

        return -1;
    }
    int linearSearchRatingByLocation(int sized, int rating, int centerID) {
        int counter = 0;
        for (int i = 0; i < sized; i++) {
            if (rating != 0) {
                if (record[i]->getRating() == rating) {
                    if (record[i]->getCenter().getCenterID() == centerID) {
                        printRecord(i);
                        counter = i;
                    }
                }
            }

        }
        return counter;

        if (count == NULL) {
            return -1;
        }
        return -1;
    }
    void deleteRecord(int id, Date date) {
        int found = binarySearch(0, count--, id);

        if (found == -1) {
            cout << "TutorID doesn't exist" << endl;
            return;
        }
        else {
            if (date.checkDate(record[found]->getDateTerminated())) {
                if (found == count) {
                    count--;
                }
                else {
                    for (; found < count; found++) {
                        record[found] = record[found + 1];
                    }
                }
            }
            else {
                cout << "Must 6 months after termination the delete is available" << endl;
                return;
            }

            cout << "Delete is successful" << endl << endl;
            count--;
        }
    }
    void modify() {
        int flag, id;
        string phone, address;
        int dayTerminated, monthTerminated, yearTerminated;
        char v, b;

        cout << "Please Enter the Tutor ID of the person you want to edit: ";
        cin >> id;

        //search algorithm untuk dpt index number nya
        int index = binarySearch(0, size, id);

        cout << "Which data you want to edit?" <<endl <<
            "1 = Address" << endl << "2 = Phone Number" << endl <<
            "3 = Termination Date" << endl;
        cin >> flag;

        if (flag == 1)
        {
            cout << "Enter New Address" << endl;
            cin >> address;
            record[index]->setAddress(address);
        }
        else if (flag == 2)
        {
            cout << "Enter New Phone Number" << endl;
            cin >> phone;
            record[index]->setPhone(phone);
        }
        else if (flag == 3) {
            cout << "Enter termination date (dd/MM/YYYY)" << endl;
            cin >> dayTerminated >> v >> monthTerminated >> b >> yearTerminated;
            record[index]->setDateTerminated(dayTerminated, monthTerminated, yearTerminated);
        }
        cout << "Modified Successful" << endl;
    }
    void viewTutorAdmin(int center) {
        if (record == NULL) {
            cout << "Data empty" << endl;
        }

        int index = 0;
        int input = 0;
        bool loop = true;
        while (loop) {
            bool found = false;
            bool stop = false;
            while (!found) {
                if (index >= size) {
                    found = true;
                    loop = false;
                    stop = true;
                    break;
                }
                if (record[index]->getCenter().getCenterID() == center) {
                    printRecord(index);
                    found = true;
                    break;
                }
                index++;
            }

            if (stop) {
                cout << "No tutor in the location" << endl;
            }
            else {
                bool t = true;
                int prevIndex = index;
                while (t) {
                    cout << "Next or Previous (1 = next, 2 = previous, 3 = Back to home) ? " << endl;
                    cin >> input;
                    if (input == 1) {
                        bool found = false;
                        while (!found) {
                            //prevIndex=index;
                            index++;
                            if (index >= size) { //size global var???
                                cout << "Out of Range !!" << endl;
                                printRecord(prevIndex);
                                //index--;
                                found = true;
                                break;
                            }
                            else if (record[index]->getCenter().getCenterID() == center) {
                                printRecord(index);
                                prevIndex = index;
                                found = true;
                                break;
                            }
                        }
                    }
                    else if (input == 2) {
                        bool found = false;
                        while (!found) {
                            //prevIndex=index;
                            index--;
                            if (index < 0) {
                                cout << "Out of Range !!" << endl;
                                index++;
                                printRecord(prevIndex);
                                break;
                            }if (record[index]->getCenter().getCenterID() == center) {
                                prevIndex = index;
                                printRecord(index);
                                found = true;
                            }
                        }
                    }
                    //other input then 1 or 2
                    else {
                        t = false;
                    }
                }
                loop = false;
            }
        }
    }
    void viewTutorHR() {
        int index = 0;
        int input = 0;

        while (true) {
            printRecord(index);
            bool t = true;
            while (t) {
                cout << "Next or Previous (1 = next, 2 = previous, 3 = Back to home) ? " << endl;
                cin >> input;
                if (input == 1) {
                    bool found = false;
                    while (!found) {
                        index++;
                        if (index >= size) {
                            cout << "Out of Range !!" << endl;
                            index--;
                            printRecord(index);
                            break;
                        }
                        else {
                            printRecord(index);
                            found = true;
                        }
                    }
                }
                else if (input == 2) {
                    bool found = false;
                    while (!found) {
                        index--;
                        if (index < 0) {
                            cout << "out of Range !!" << endl;
                            index++;
                            printRecord(index);
                            break;
                        }
                        else {
                            printRecord(index);
                            found = true;
                        }
                    }
                }
                else {
                    t = false;
                }
            }
            break;
        }
    }
    void viewAllTutorAdmin(int center) {
        for (int i = 0; i < size; i++) {
            if (record[i]->getCenter().getCenterID() == center) {
                printRecord(i);
            }
        }
    }
    void viewAllTutorHr() {
        for (int i = 0; i < size; i++) {
            printRecord(i);
        }
    }
    void sortTutorAdmin(int center) {
        int choice;
        cout << "What would u like to sort ?" << endl;
        cout << "1. Sort TutorID" << endl;
        cout << "2. Sort Rating" << endl;
        cout << "3. Sort Tutor Name" << endl;
        cout << "4. Sort Hourly Payrate" << endl;
        cout << "5. Back" << endl;
        cout << "Please choose from 1 - 5" << endl;
        cin >> choice;
        if (choice == 1) {
            for (int i = 0; i < size; i++) {
                Record temp = record[i];
                int j = i;
                while (j > 0 && record[j - 1]->getTutorID() > temp->getTutorID())
                {
                    record[j] = record[j - 1];
                    j--;
                }

                record[j] = temp;
            }
            viewAllTutorAdmin(center);
        }
        else if (choice == 2) {
            for (int i = 0; i < size; i++) {
                Record temp = record[i];
                int j = i;
                while (j > 0 && record[j - 1]->getRating() > temp->getRating())
                {
                    record[j] = record[j - 1];
                    j--;
                }

                record[j] = temp;
            }
            viewAllTutorAdmin(center);
        }
        else if (choice == 3) {
            for (int i = 0; i < size; i++) {
                Record temp = record[i];
                int j = i;
                while (j > 0 && record[j - 1]->getName() > temp->getName())
                {
                    record[j] = record[j - 1];
                    j--;
                }

                record[j] = temp;
            }
            viewAllTutorAdmin(center);
        }
        else if (choice == 4) {
            for (int i = 0; i < size; i++) {
                Record temp = record[i];
                int j = i;
                while (j > 0 && record[j - 1]->getPayrate() > temp->getPayrate())
                {
                    record[j] = record[j - 1];
                    j--;
                }

                record[j] = temp;
            }
            viewAllTutorAdmin(center);
        }
        else if (choice == 5) {
            return;
        }
    }
    void sortTutorHR() {
        int choice;
        cout << "What would u like to sort ?" << endl;
        cout << "1. Sort TutorID" << endl;
        cout << "2. Sort Rating" << endl;
        cout << "3. Sort Tutor Name" << endl;
        cout << "4. Sort Hourly Payrate" << endl;
        cout << "5. Back" << endl;
        cout << "Please choose from 1 - 5" << endl;
        cin >> choice;
        if (choice == 1) {
            for (int i = 0; i < size; i++) {
                Record temp = record[i];
                int j = i;
                while (j > 0 && record[j - 1]->getTutorID() > temp->getTutorID())
                {
                    record[j] = record[j - 1];
                    j--;
                }

                record[j] = temp;
            }
            viewAllTutorHr();
        }
        else if (choice == 2) {
            for (int i = 0; i < size; i++) {
                Record temp = record[i];
                int j = i;
                while (j > 0 && record[j - 1]->getRating() > temp->getRating())
                {
                    record[j] = record[j - 1];
                    j--;
                }

                record[j] = temp;
            }
            viewAllTutorHr();
        }
        else if (choice == 3) {
            for (int i = 0; i < size; i++) {
                Record temp = record[i];
                int j = i;
                while (j > 0 && record[j - 1]->getName() > temp->getName())
                {
                    record[j] = record[j - 1];
                    j--;
                }

                record[j] = temp;
            }
            viewAllTutorHr();
        }
        else if (choice == 4) {
            for (int i = 0; i < size; i++) {
                Record temp = record[i];
                int j = i;
                while (j > 0 && record[j - 1]->getPayrate() > temp->getPayrate())
                {
                    record[j] = record[j - 1];
                    j--;
                }

                record[j] = temp;
            }
            viewAllTutorHr();
        }
        else if (choice == 5) {
            return;
        }
    }
    bool isNumber(const string& str) {
        for (char const& c : str) {
            if (isdigit(c) == 0)
                return false;
        }
        return true;
    }
    void addRecord(Center centered, Subject subjected, Date date) {
        int tutorID = count + 1;
        string name;
        int dayHired;
        int monthHired;
        int yearHired;
        int dayTerminated;
        int monthTerminated;
        int yearTerminated;
        Date dateHired;
        Date dateTerminated;
        int rating;
        string phone_number;
        string address;
        int center;
        int subject;
        int payrate;
        string choice;
        char v, b;
        while (true) {
            cout << "Please enter the new tutor" << endl;
            cout << "Enter name: ";
            cin >> name;
            while (true) {
                cout << "Enter date hired (dd/MM/YYYY): ";
                cin >> dayHired >> v >> monthHired >> b >> yearHired;
                if (!date.validateDate(dayHired, monthHired, yearHired)) {
                    cout << "Enter valid date" << endl;
                }
                else {
                    break;
                }
            }
            while (true) {
                cout << "Is Tutor terminated (y/n): ";
                cin >> choice;
                if (choice == "y") {
                    while (true) {
                        cout << "Enter date terminated (dd/MM/YYYY): ";
                        cin >> dayTerminated >> v >> monthTerminated >> b >> yearTerminated;
                        if (!date.validateDate(dayTerminated, monthTerminated, yearTerminated)) {
                            cout << "Enter valid date" << endl;
                        }
                        break;
                    }
                    break;
                }
                else if (choice == "n") {
                    dayTerminated = 0;
                    monthTerminated = 00;
                    yearTerminated = 0000;
                    break;
                }
                else {
                    cout << "please try again" << endl;
                }
            }
            while (true) {
                cout << "Enter rating(1-5): ";
                cin >> rating;
                if (rating < 0 || rating > 5) {
                    cout << "Enter a valid Rating" << endl;
                }
                else {
                    break;
                }
            }

            while (true) {
                cout << "Enter phone number: ";
                cin >> phone_number;
                if (!isNumber(phone_number)) {
                    cout << "Please enter a valid phone number" << endl;
                }
                else {
                    break;
                }
            }

            cout << "Enter address of tutor: ";
            cin >> address;

            while (true) {
                int choice2;
                cout << "Choose center" << endl;
                cout << "1. Bukit Jalil" << endl;
                cout << "2. Subang" << endl;
                cout << "3. Petaling Jaya" << endl;
                cout << "choose from (1-3): ";
                cin >> choice2;
                if (choice2 == 1) {
                    center = 101;
                    break;
                }
                else if (choice2 == 2) {
                    center = 102;
                    break;
                }
                else if (choice2 == 3) {
                    center = 103;
                    break;
                }
                else {
                    cout << "Please type a correct choice" << endl;
                }
            }

            while (true) {
                int choice2;
                cout << "Choose subject" << endl;
                cout << "1. English" << endl;
                cout << "2. Maths" << endl;
                cout << "3. Science" << endl;
                cout << "choose from (1-3): ";
                cin >> choice2;
                if (choice2 == 1) {
                    subject = 1001;
                    break;
                }
                else if (choice2 == 2) {
                    subject = 1002;
                    break;
                }
                else if (choice2 == 3) {
                    subject = 1003;
                    break;
                }
                else {
                    cout << "Please type a correct choice" << endl;
                }
            }

            while (true) {
                cout << "Enter payrate" << endl;
                cin >> payrate;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please enter correct payrate" << endl;
                    cin >> payrate;
                }
                if (!cin.fail()) {
                    break;
                }

            }
            dateHired = Date(dayHired, monthHired, yearHired);
            dateTerminated = Date(dayTerminated, monthTerminated, yearTerminated);
            Records* newData = new Records(tutorID, name, dateHired, dateTerminated, rating, phone_number, 
                address, centered.setCenter(center), subjected.setSubject(subject), payrate);
            insertToArray(newData);
            string choice3;
            cout << "Would u like to continue (y/n)" << endl;
            cin >> choice3;
            if (choice3 == "y") {
                continue;
            }
            else if (choice3 == "n") {
                break;
            }
            else {
                cout << "Invalid" << endl;
                break;
            }
        }
    }
    void deletePage(Date date) {
        int pepek;
        while (true) {
            cout << "Enter the tutorID to be deleted" << endl;
            cin >> pepek;
            deleteRecord(pepek, date);
            break;
        }
    }
    void searchTutorAdmin(int centerID) {
        int choice, id, rating;
        while (true) {
            cout << "What would u like to search" << endl;
            cout << "1. TutorID" << endl;
            cout << "2. Rating" << endl;
            cout << "3. Back" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Enter tutor to be search" << endl;
                cin >> id;
                int index = binarySearch(0, size, id);
                if (index == -1) {
                    cout << "TutorID not found" << endl;
                }
                else {
                    printRecord(index);
                }
            }
            else if (choice == 2) {
                cout << "Enter rating to be search" << endl;
                cin >> rating;
                int index = linearSearchRatingByLocation(size, rating, centerID);
                if (index == -1) {
                    cout << "Rating not found" << endl;
                }
            }
            else if (choice == 3) {
                break;
            }
            else {
                cout << "Please input a correct choice" << endl;
            }
        }

    }
    void searchTutorHR() {
        int choice, id, rating, center;
        while (true) {
            cout << "What would u like to search" << endl;
            cout << "1. TutorID" << endl;
            cout << "2. Rating" << endl;
            cout << "3. Location" << endl;
            cout << "4. Back" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Enter tutor to be search" << endl;
                cin >> id;
                int index = binarySearch(0, size, id);
                if (index == -1) {
                    cout << "TutorID not found" << endl;
                }
                else {
                    printRecord(index);
                }
            }
            else if (choice == 2) {
                cout << "Enter rating to be search" << endl;
                cin >> rating;
                bool found = false;
                if (rating >= 1 && rating <= 5) {
                    for (int i = 0; i < size; i++) {
                        if (record[i]->getRating() == rating) {
                            printRecord(i);
                            found = true;
                        }
                    }
                }
                else {
                    cout << "enter a valid rating 1-5";
                }

                if (!found) {
                    cout << "Not found" << endl;
                }
            }
            else if (choice == 3) {
                cout << "Enter center to be search" << endl;
                cout << "101 = Bukit Jalil" << endl;
                cout << "102 = Subang" << endl;
                cout << "103 = Petaling Jaya" << endl;
                cin >> center;
                if (center == 101 || center == 102 || center == 103) {
                    for (int i = 0; i < size; i++) {
                        if (record[i]->getCenter().getCenterID() == center) {
                            printRecord(i);
                        }
                    }
                }
                else {
                    cout << "enter a valid rating 101-103";
                }
            }
            else if (choice == 4) {
                break;
            }
            else {
                cout << "Please input a correct choice" << endl;
            }
        }
    }
    void adminSystem(Subject subject, Center center, Date date, int id) {
        int choice;

        cout << "Welcome to the Admin System" << endl;
        cout << "1.View Records of Tutor" << endl;
        cout << "2.Sort Tutor" << endl;
        cout << "3.Add Tutor" << endl;
        cout << "4.Search Tutor" << endl;
        cout << "5.Delete Tutor" << endl;
        cout << "6.Modify Tutor" << endl;
        cout << "7.Log Out" << endl;
        cout << "Choose from 1-5" << endl;
        cin >> choice;
        if (choice == 1) {
            viewTutorAdmin(id);
            adminSystem(subject, center, date, id);
        }
        else if (choice == 2) {
            sortTutorAdmin(id);
            adminSystem(subject, center, date, id);
        }
        else if (choice == 3) {
            addRecord(center, subject, date);
            adminSystem(subject, center, date, id);
        }
        else if (choice == 4) {
            searchTutorAdmin(id);
            adminSystem(subject, center, date, id);
        }
        else if (choice == 5) {
            deletePage(date);
            adminSystem(subject, center, date, id);
        }
        else if (choice == 6) {
            modify();
            adminSystem(subject, center, date, id);
        }
        else if (choice == 7) {
            cout << "log out success" << endl;
        }
        else {
            cout << "Please try again" << endl;
            adminSystem(subject, center, date, id);
        }
    }
    void HRSystem(Subject subject, Center center, Date date) {
        int choice;

        cout << "Welcome to the Admin System" << endl;
        cout << "1.View Records of Tutor" << endl;
        cout << "2.Sort Tutor" << endl;
        cout << "3.Add Tutor" << endl;
        cout << "4.Search Tutor" << endl;
        cout << "5.Delete Tutor" << endl;
        cout << "6.Modify Tutor" << endl;
        cout << "7.Log Out" << endl;
        cout << "Choose from 1-5" << endl;
        cin >> choice;
        if (choice == 1) {
            viewTutorHR();
            HRSystem(subject, center, date);
        }
        else if (choice == 2) {
            sortTutorHR();
            HRSystem(subject, center, date);
        }
        else if (choice == 3) {
            addRecord(center, subject, date);
            HRSystem(subject, center, date);
        }
        else if (choice == 4) {
            searchTutorHR();
            HRSystem(subject, center, date);
        }
        else if (choice == 5) {
            deletePage(date);
            HRSystem(subject, center, date);
        }
        else if (choice == 6) {
            modify();
            HRSystem(subject, center, date);
        }
        else if (choice == 7) {
            cout << "log out success" << endl;
        }
        else {
            cout << "Please input a valid number" << endl;
            HRSystem(subject, center, date);
        }
    }
    void Login(Subject subject, Center center, Date date) {
        string username, password;
        while (true) {
            cout << "WELCOME TO TUTOR SYSTEM" << endl;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            if (username == "admin1" && password == "admin1") {
                adminSystem(subject, center, date, 101);

            }
            else if (username == "admin2" && password == "admin2") {
                adminSystem(subject, center, date, 102);

            }
            else if (username == "admin3" && password == "admin3") {
                adminSystem(subject, center, date, 103);

            }
            else if (username == "HR" || password == "human") {
                HRSystem(subject, center, date);
            }
            else {
                cout << "Credentials Invalid" << endl;
                break;
            }
        }

    }
};

int main() {
    RecordArr <Records*> rSystem;
    Center center;
    Subject subject;
    Date date;

    rSystem.insertToArray(new Records(rSystem.count + 1, "Vincent", Date(4, 5, 2021), Date(00, 00, 0000), 4, "01893824829", " Sunter Hijau Viii", center.setCenter(101), subject.setSubject(1001), 300));
    rSystem.insertToArray(new Records(rSystem.count + 1, "Daniel", Date(28, 7, 2021), Date(00, 00, 0000), 4, "0893818492", "Parkhill residence pepek", center.setCenter(102), subject.setSubject(1002), 200));
    rSystem.insertToArray(new Records(rSystem.count + 1, "Bejeka", Date(20, 8, 2022), Date(00, 00, 0000), 4, "0833475823", "Endah is the best", center.setCenter(101), subject.setSubject(1001), 400));


    rSystem.Login(subject, center, date);
    return 0;
}