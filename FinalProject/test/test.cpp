#include <iostream>
#include <fstream>

using namespace std;

struct book
{
    int id;
    char title[50];
    char author[50];
    int year;
    float rating;
};

void Show(const book& bk) {
    cout << "Title : " << bk.title << endl;
    cout << "Author : " << bk.author << endl;
    cout << "Year : " << bk.year << endl;
    cout << "Rating : " << bk.rating << endl;
}

void SearchByAuthor(const book books[], int size, const char* author) {
    bool found = false;

    cout << "Books written by " << author << ":" << endl;

    for (int i = 0; i < size; i++) {
        if (strcmp(books[i].author, author) == 0) {
            Show(books[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "No books written by " << author << endl;
    }
}

void SearchByYear(const book books[], int size, int year) {
    bool found = false;

    cout << "Books published in " << year << ":" << endl;

    for (int i = 0; i < size; i++) {
        if (books[i].year == year) {
            Show(books[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "No books published in " << year << endl;
    }
}

void SearchByTitle(const book books[], int size, const char* title) {
    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i].title, title) == 0)
        {
            Show(books[i]);
            found = true;
        }
    }

    if (!found)
    {
        cout << "Book not found";
    }
}

void TheHighestRated(const book books[], int size)
{
    int index = -1;
    float maxRating = books[0].rating;

    for (size_t i = 0; i < size; i++)
    {
        if (books[i].rating > maxRating)
        {
            maxRating = books[i].rating;
            index = i;
        }
    }

    if (index != -1)
    {
        Show(books[index]);
    }
    else
    {
        cout << "No book with the highest rating" << endl;
    }
}

void ShowAll(const book books[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << "Book " << i + 1 << ":" << endl;
        Show(books[i]);
        cout << endl;
    }
}

void ModifyData(book books[], int size, int id) {
    bool found = false;
    int choice;

    for (int i = 0; i < size; i++) {
        if (books[i].id == id) {
            Show(books[i]);

            cout << "[1] - Change title\n[2] - Change author\n[3] - Change year\n[4] - Change rating" << endl;
            cin >> choice;
            cin.ignore();

            switch (choice) {
            case 1:
                cout << "Enter title: ";
                cin.getline(books[i].title, 50);
                break;
            case 2:
                cout << "Enter author: ";
                cin.getline(books[i].author, 50);
                break;
            case 3:
                cout << "Enter year: ";
                cin >> books[i].year;
                break;
            case 4:
                cout << "Enter rating: ";
                cin >> books[i].rating;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
            }

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book with ID " << id << " not found" << endl;
    }
}

void SaveToFile(const book books[], int size, const char* filename) {
    ofstream file(filename);

    if (file.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            file << books[i].id << endl;
            file << books[i].title << endl;
            file << books[i].author << endl;
            file << books[i].year << endl;
            file << books[i].rating << endl;
        }
    }
    else
    {
        cerr << "ERROR opening file" << endl;
        return;
    }

    file.close();
}

void LoadFromFile(book books[], int& size, const char* filename, const int SIZE) {
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "ERROR opening file" << endl;
        return;
    }
    else
    {
        size = 0;

        while (size < SIZE && !file.eof())
        {
            file >> books[size].id;
            file.ignore();
            file.getline(books[size].title, 50);
            file.getline(books[size].author, 50);
            file >> books[size].year;
            file >> books[size].rating;
            file.ignore();

            size++;
        }
        
        size--;

        file.close();
    }
}

void AddBook(book books[], int& size) {
    cout << "Enter details of the new book:" << endl;

    cout << "Enter ID: ";
    cin >> books[size].id;
    cin.ignore();

    cout << "Enter title: ";
    cin.getline(books[size].title, 50);

    cout << "Enter author: ";
    cin.getline(books[size].author, 50);

    cout << "Enter year: ";
    cin >> books[size].year;

    cout << "Enter rating: ";
    cin >> books[size].rating;

    size++;
}

int main() {
    const int SIZE = 100;
    int choice;
    int size = 0;

    book books[SIZE] = {

    };

    char filename[50];

    do {
        cout << endl;
        cout << "----- MENU -----" << endl;
        cout << "[1] - Open file " << endl;
        cout << "[2] - Save file " << endl;
        cout << "[3] - Add a book " << endl;
        cout << "[4] - Modify data " << endl;
        cout << "[5] - Show all " << endl;
        cout << "[6] - Search by title " << endl;
        cout << "[7] - Search by author " << endl;
        cout << "[8] - Search by year " << endl;
        cout << "[9] - The highest rated " << endl;
        cout << "[0] - Exit " << endl;
        cout << "----------------" << endl;

        cout << endl;

        cin >> choice;
        cin.ignore();

        switch (choice) {


        case 1: {
            cout << "[1] - Fantasy.txt\n[2] - Horror.txt\n[3] - Romance.txt\n[4] - ScienceFiction.txt\n[5] - Drama.txt\n";

            int fileChoice;
            cout << "Enter the number of the file: ";
            cin >> fileChoice;

            switch (fileChoice) {
            case 1:
                strcpy_s(filename, sizeof(filename), "Fantasy.txt");
                break;
            case 2:
                strcpy_s(filename, sizeof(filename), "Horror.txt");
                break;
            case 3:
                strcpy_s(filename, sizeof(filename), "Romance.txt");
                break;
            case 4:
                strcpy_s(filename, sizeof(filename), "ScienceFiction.txt");
                break;
            case 5:
                strcpy_s(filename, sizeof(filename), "Drama.txt");
                break;
            default:
                cerr << "Invalid file choice" << endl;
                return 0;
            }

            LoadFromFile(books, size, filename, SIZE);
            break;
        }

        case 2: {
            SaveToFile(books, size, filename);
            break;
        }

        case 3: {
            AddBook(books, size);
            break;
        }

        case 4: {
            int id;

            cout << "Enter ID: " << endl;
            cin >> id;
            cin.ignore();

            ModifyData(books, size, id);

            break;
        }

        case 5: {
            ShowAll(books, size);
            break;
        }

        case 6: {
            char title[50];

            cout << "Enter title of book: " << endl;
            cin.getline(title, 50);

            SearchByTitle(books, size, title);

            break;
        }

        case 7: {
            char author[50];

            cout << "Enter author's name: " << endl;
            cin.getline(author, 50);

            SearchByAuthor(books, size, author);

            break;
        }

        case 8: {
            int year;

            cout << "Enter the year: " << endl;
            cin >> year;

            SearchByYear(books, size, year);

            break;
        }

        case 9: {
            TheHighestRated(books, size);
            break;
        }

        case 0: {
            cout << "Exiting..." << endl;
            break;
        }

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
