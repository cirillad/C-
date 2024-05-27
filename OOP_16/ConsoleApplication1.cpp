#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

//class Train
//{
//    int number;
//    string departureTime;
//    string destinationStation;
//
//public:
//    Train(int num, string time, string station)
//        : number(num), departureTime(time), destinationStation(station) {}
//
//    int getNumber() const { return number; }
//    string getDepartureTime() const { return departureTime; }
//    string getDestinationStation() const { return destinationStation; }
//
//    void setDepartureTime(const string& time) { departureTime = time; }
//
//    void printInfo() const
//    {
//        cout << "Train Number: " << number << endl;
//        cout << "Departure Time: " << departureTime << endl;
//        cout << "Destination Station: " << destinationStation << endl;
//    }
//
//    void saveToFile(ofstream& outFile) const
//    {
//        outFile << number << endl;
//        outFile << departureTime << endl;
//        outFile << destinationStation << endl;
//    }
//
//    static Train loadFromFile(ifstream& inFile)
//    {
//        int number;
//        string departureTime, destinationStation;
//        inFile >> number;
//        inFile.ignore();
//        getline(inFile, departureTime);
//        getline(inFile, destinationStation);
//        return Train(number, departureTime, destinationStation);
//    }
//};
//
//class TrainManager
//{
//    vector<Train> trains;
//
//public:
//    void addTrain(const Train& train)
//    {
//        trains.push_back(train);
//    }
//
//    void printAll() const
//    {
//        for (const auto& train : trains)
//        {
//            train.printInfo();
//            cout << "-----------------------" << endl;
//        }
//    }
//
//    void searchByNumber(int number) const
//    {
//        for (const auto& train : trains)
//        {
//            if (train.getNumber() == number)
//            {
//                train.printInfo();
//                return;
//            }
//        }
//        cout << "No results found for train number: " << number << endl;
//    }
//
//    void editDepartureTime(int number, const string& newTime)
//    {
//        for (auto& train : trains)
//        {
//            if (train.getNumber() == number)
//            {
//                train.setDepartureTime(newTime);
//                cout << "Departure time updated successfully." << endl;
//                return;
//            }
//        }
//        cout << "No results found for train number: " << number << endl;
//    }
//
//    void sortByDepartureTime()
//    {
//        sort(trains.begin(), trains.end(), [](const Train& a, const Train& b) {
//            return a.getDepartureTime() < b.getDepartureTime();
//            });
//        cout << "Trains sorted by departure time." << endl;
//    }
//
//    void showByDestinationStation(const string& station) const
//    {
//        bool found = false;
//        for (const auto& train : trains)
//        {
//            if (train.getDestinationStation() == station)
//            {
//                train.printInfo();
//                cout << "-----------------------" << endl;
//                found = true;
//            }
//        }
//        if (!found)
//        {
//            cout << "No trains found for destination station: " << station << endl;
//        }
//    }
//
//    void saveAllToFile(const string& filename) const
//    {
//        ofstream outFile(filename);
//        if (outFile.is_open())
//        {
//            for (const auto& train : trains)
//            {
//                train.saveToFile(outFile);
//                outFile << "----" << endl; // Роздільник між записами
//            }
//            outFile.close();
//        }
//        else
//        {
//            cout << "Unable to open file for writing." << endl;
//        }
//    }
//
//    void loadAllFromFile(const string& filename)
//    {
//        ifstream inFile(filename);
//        if (inFile.is_open())
//        {
//            trains.clear();
//            while (inFile.peek() != EOF)
//            {
//                Train train = Train::loadFromFile(inFile);
//                trains.push_back(train);
//                inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Пропустити роздільник
//            }
//            inFile.close();
//        }
//        else
//        {
//            cout << "Unable to open file for reading." << endl;
//        }
//    }
//};
//
//void printMenu()
//{
//    cout << "\nMenu:\n";
//    cout << "1. Add Train\n";
//    cout << "2. Print All Trains\n";
//    cout << "3. Search Train by Number\n";
//    cout << "4. Edit Departure Time by Number\n";
//    cout << "5. Sort Trains by Departure Time\n";
//    cout << "6. Show Trains by Destination Station\n";
//    cout << "7. Save Trains to File\n";
//    cout << "8. Load Trains from File\n";
//    cout << "9. Exit\n";
//    cout << "Enter your choice: ";
//}

int main()
{
    //TrainManager manager;
    //int choice;

    //do
    //{
    //    printMenu();
    //    cin >> choice;

    //    switch (choice)
    //    {
    //    case 1:
    //    {
    //        int number;
    //        string departureTime, destinationStation;

    //        cout << "Enter train number: ";
    //        cin >> number;
    //        cin.ignore(); // Ignore the newline character left in the buffer
    //        cout << "Enter departure time (HH:MM): ";
    //        getline(cin, departureTime);
    //        cout << "Enter destination station: ";
    //        getline(cin, destinationStation);

    //        manager.addTrain(Train(number, departureTime, destinationStation));
    //        break;
    //    }
    //    case 2:
    //        manager.printAll();
    //        break;
    //    case 3:
    //    {
    //        int number;
    //        cout << "Enter train number: ";
    //        cin >> number;
    //        manager.searchByNumber(number);
    //        break;
    //    }
    //    case 4:
    //    {
    //        int number;
    //        string newTime;
    //        cout << "Enter train number: ";
    //        cin >> number;
    //        cin.ignore(); // Ignore the newline character left in the buffer
    //        cout << "Enter new departure time (HH:MM): ";
    //        getline(cin, newTime);
    //        manager.editDepartureTime(number, newTime);
    //        break;
    //    }
    //    case 5:
    //        manager.sortByDepartureTime();
    //        manager.printAll();
    //        break;
    //    case 6:
    //    {
    //        string station;
    //        cout << "Enter destination station: ";
    //        cin.ignore(); // Ignore the newline character left in the buffer
    //        getline(cin, station);
    //        manager.showByDestinationStation(station);
    //        break;
    //    }
    //    case 7:
    //        manager.saveAllToFile("trains.txt");
    //        break;
    //    case 8:
    //        manager.loadAllFromFile("trains.txt");
    //        break;
    //    case 9:
    //        cout << "Exiting..." << endl;
    //        break;
    //    default:
    //        cout << "Invalid choice. Please try again." << endl;
    //    }
    //} while (choice != 9);

    //return 0;

    ifstream inFile("trains.txt");
    string asd;
    inFile >> asd;
    cout << asd;
    return 0;
}
