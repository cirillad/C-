#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Directory
{
    string companyName;
    string owner;
    string phoneNumber;
    string address;
    string occupation;

public:
    Directory(string cName, string own, string phone, string addr, string occup)
        : companyName(cName), owner(own), phoneNumber(phone), address(addr), occupation(occup) {}

    string getCompanyName() const { return companyName; }
    string getOwner() const { return owner; }
    string getPhoneNumber() const { return phoneNumber; }
    string getAddress() const { return address; }
    string getOccupation() const { return occupation; }

    void printInfo() const
    {
        cout << "Company Name: " << companyName << endl;
        cout << "Owner: " << owner << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
        cout << "Occupation: " << occupation << endl;
    }

    void saveToFile(ofstream& outFile) const
    {
        outFile << companyName << endl;
        outFile << owner << endl;
        outFile << phoneNumber << endl;
        outFile << address << endl;
        outFile << occupation << endl;
    }

    static Directory loadFromFile(ifstream& inFile)
    {
        string companyName, owner, phoneNumber, address, occupation;
        getline(inFile, companyName);
        getline(inFile, owner);
        getline(inFile, phoneNumber);
        getline(inFile, address);
        getline(inFile, occupation);
        return Directory(companyName, owner, phoneNumber, address, occupation);
    }
};

class DirectoryManager
{
    vector<Directory> directories;

public:
    void addDirectory(const Directory& directory)
    {
        directories.push_back(directory);
    }

    void saveAllToFile(const string& filename) const
    {
        ofstream outFile(filename);
        if (outFile.is_open())
        {
            for (const auto& directory : directories)
            {
                directory.saveToFile(outFile);
                outFile << "----" << endl;
            }
            outFile.close();
        }
        else
        {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void loadAllFromFile(const string& filename)
    {
        ifstream inFile(filename);
        if (inFile.is_open())
        {
            directories.clear();
            while (inFile.peek() != EOF)
            {
                Directory directory = Directory::loadFromFile(inFile);
                directories.push_back(directory);
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            inFile.close();
        }
        else
        {
            cout << "Unable to open file for reading." << endl;
        }
    }

    void printAll() const
    {
        for (const auto& directory : directories)
        {
            directory.printInfo();
            cout << "-----------------------" << endl;
        }
    }

    void searchByCompanyName(const string& companyName) const
    {
        for (const auto& directory : directories)
        {
            if (directory.getCompanyName() == companyName)
            {
                directory.printInfo();
                return;
            }
        }
        cout << "No results found for company name: " << companyName << endl;
    }

    void searchByOwner(const string& owner) const
    {
        for (const auto& directory : directories)
        {
            if (directory.getOwner() == owner)
            {
                directory.printInfo();
                return;
            }
        }
        cout << "No results found for owner: " << owner << endl;
    }

    void searchByPhoneNumber(const string& phoneNumber) const
    {
        for (const auto& directory : directories)
        {
            if (directory.getPhoneNumber() == phoneNumber)
            {
                directory.printInfo();
                return;
            }
        }
        cout << "No results found for phone number: " << phoneNumber << endl;
    }

    void searchByOccupation(const string& occupation) const
    {
        for (const auto& directory : directories)
        {
            if (directory.getOccupation() == occupation)
            {
                directory.printInfo();
                return;
            }
        }
        cout << "No results found for occupation: " << occupation << endl;
    }
};

int main()
{
    DirectoryManager manager;

    manager.loadAllFromFile("directories.txt");

    manager.addDirectory(Directory("TechCorp", "John Doe", "123-456-7890", "123 Tech St.", "Software Development"));
    manager.addDirectory(Directory("BizConsult", "Jane Smith", "987-654-3210", "456 Biz Ave.", "Business Consulting"));

    manager.saveAllToFile("directories.txt");

    cout << "All directories:" << endl;
    manager.printAll();

    cout << "\nSearch by company name 'TechCorp':" << endl;
    manager.searchByCompanyName("TechCorp");

    cout << "\nSearch by owner 'Jane Smith':" << endl;
    manager.searchByOwner("Jane Smith");

    cout << "\nSearch by phone number '123-456-7890':" << endl;
    manager.searchByPhoneNumber("123-456-7890");

    cout << "\nSearch by occupation 'Business Consulting':" << endl;
    manager.searchByOccupation("Business Consulting");
}
