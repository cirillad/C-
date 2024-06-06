#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <conio.h> // Для _kbhit() і _getch()

using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    int year;
    float rating;

public:
    Book(int _id, const string& _title, const string& _author, int _year, float _rating)
        : id(_id), title(_title), author(_author), year(_year), rating(_rating) {}

    int getId() const { return id; }
    const string& getTitle() const { return title; }
    const string& getAuthor() const { return author; }
    int getYear() const { return year; }
    float getRating() const { return rating; }

    void setTitle(const string& _title) { title = _title; }
    void setAuthor(const string& _author) { author = _author; }
    void setYear(int _year) { year = _year; }
    void setRating(float _rating) { rating = _rating; }

    void show() const {
        cout << "ID : " << id << endl;
        cout << "Title : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Year : " << year << endl;
        cout << "Rating : " << rating << endl;
    }
};

class BookLibrary {
private:
    vector<Book> books;
    string filename;

public:
    BookLibrary(const string& _filename) : filename(_filename) {}

    void addBook(const Book& book) {
        books.push_back(book);
    }

    void showAllBooks() const {
        for (const auto& book : books) {
            book.show();
            cout << endl;
        }
    }

    void searchByTitle(const string& title) const {
        bool found = false;
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                book.show();
                found = true;
            }
        }
        if (!found) {
            cout << "Book not found" << endl;
        }
    }

    void searchByAuthor(const string& author) const {
        bool found = false;
        for (const auto& book : books) {
            if (book.getAuthor() == author) {
                book.show();
                found = true;
            }
        }
        if (!found) {
            cout << "No books written by " << author << endl;
        }
    }

    void searchByYear(int year) const {
        bool found = false;
        for (const auto& book : books) {
            if (book.getYear() == year) {
                book.show();
                found = true;
            }
        }
        if (!found) {
            cout << "No books published in " << year << endl;
        }
    }

    void showHighestRated() const {
        float maxRating = -1;
        const Book* highestRatedBook = nullptr;
        for (const auto& book : books) {
            if (book.getRating() > maxRating) {
                maxRating = book.getRating();
                highestRatedBook = &book;
            }
        }
        if (highestRatedBook) {
            highestRatedBook->show();
        }
        else {
            cout << "No book with the highest rating" << endl;
        }
    }

    void saveToFile() const {
        const string menuItems[] = {
            "1 - fantasy",
            "2 - horror",
            "3 - science",
            "4 - thriller"
        };
        const int numItems = 4;

        int selected = 0;
        while (true) {
            system("cls");
            cout << "Select the file to save to:" << endl;
            for (int i = 0; i < numItems; i++) {
                if (i == selected) {
                    cout << "> " << menuItems[i] << " <" << endl;
                }
                else {
                    cout << menuItems[i] << endl;
                }
            }

            int key = _getch();
            if (key == 224) { // Спеціальна клавіша
                key = _getch();
                switch (key) {
                case 72: // Стрілка вгору
                    selected = (selected - 1 + numItems) % numItems;
                    break;
                case 80: // Стрілка вниз
                    selected = (selected + 1) % numItems;
                    break;
                }
            }
            else if (key == 13) { // Enter
                break;
            }
        }

        string fileName;
        switch (selected) {
        case 0:
            fileName = "fantasy.txt";
            break;
        case 1:
            fileName = "horror.txt";
            break;
        case 2:
            fileName = "science.txt";
            break;
        case 3:
            fileName = "thriller.txt";
            break;
        default:
            cout << "Invalid choice. Data not saved." << endl;
            return;
        }

        ofstream file(fileName);
        if (file.is_open()) {
            for (const auto& book : books) {
                file << book.getId() << endl;
                file << book.getTitle() << endl;
                file << book.getAuthor() << endl;
                file << book.getYear() << endl;
                file << book.getRating() << endl;
                file << endl; // Пустий рядок після кожної книги
            }
            cout << "Data saved to file: " << fileName << endl;
        }
        else {
            cerr << "Unable to open file: " << fileName << endl;
        }
    }

    void loadFromFile() {
        const string menuItems[] = {
            "1 - fantasy",
            "2 - horror",
            "3 - science",
            "4 - thriller"
        };
        const int numItems = 4;

        int selected = 0;
        while (true) {
            system("cls");
            cout << "Select the file to load from:" << endl;
            for (int i = 0; i < numItems; i++) {
                if (i == selected) {
                    cout << "> " << menuItems[i] << " <" << endl;
                }
                else {
                    cout << menuItems[i] << endl;
                }
            }

            int key = _getch();
            if (key == 224) { // Спеціальна клавіша
                key = _getch();
                switch (key) {
                case 72: // Стрілка вгору
                    selected = (selected - 1 + numItems) % numItems;
                    break;
                case 80: // Стрілка вниз
                    selected = (selected + 1) % numItems;
                    break;
                }
            }
            else if (key == 13) { // Enter
                break;
            }
        }

        string fileName;
        switch (selected) {
        case 0:
            fileName = "fantasy.txt";
            break;
        case 1:
            fileName = "horror.txt";
            break;
        case 2:
            fileName = "science.txt";
            break;
        case 3:
            fileName = "thriller.txt";
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            return;
        }

        ifstream file(fileName);
        if (file.is_open()) {
            int id, year;
            float rating;
            string title, author;
            while (file >> id) {
                file.ignore();
                getline(file, title);
                getline(file, author);
                file >> year;
                file >> rating;
                books.emplace_back(id, title, author, year, rating);
            }
            cout << "Data loaded from file: " << fileName << endl;
        }
        else {
            cerr << "Unable to open file: " << fileName << endl;
        }
    }

    void deleteBook(int id) {
        auto it = std::find_if(books.begin(), books.end(), [id](const Book& book) {
            return book.getId() == id;
            });

        if (it != books.end()) {
            books.erase(it);
            cout << "Book with ID " << id << " deleted successfully." << endl;
        }
        else {
            cout << "Book with ID " << id << " not found." << endl;
        }
    }
};

void displayMenu(int selected) {
    system("cls"); // Очистити екран, на UNIX системах використовуйте "clear"
    string menuItems[] = {
        "1. Add a book",
        "2. Show all books",
        "3. Search by title",
        "4. Search by author",
        "5. Search by year",
        "6. Show the highest rated book",
        "7. Save to file",
        "8. Load from file",
        "9. Delete a book",
        "0. Exit"
    };

    for (int i = 0; i < 10; i++) {
        if (i == selected) {
            cout << "> " << menuItems[i] << " <" << endl;
        }
        else {
            cout << menuItems[i] << endl;
        }
    }
}

int main() {
    string filename = "library.txt";
    BookLibrary library(filename);

    int selected = 0;

    do {
        displayMenu(selected);

        int key = _getch();
        if (key == 224) { // Спеціальна клавіша
            key = _getch();
            switch (key) {
            case 72: // Стрілка вгору
                selected = (selected - 1 + 10) % 10;
                break;
            case 80: // Стрілка вниз
                selected = (selected + 1) % 10;
                break;
            }
        }
        else if (key == 13) { // Enter
            switch (selected) {
            case 0: {
                int id, year;
                float rating;
                string title, author;

                cout << "Enter book details:" << endl;
                cout << "ID: ";
                while (!(cin >> id)) {
                    cout << "Invalid input. Please enter a valid ID (numeric value): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(); // Clear input buffer

                cout << "Title: ";
                getline(cin, title);
                while (title.empty()) {
                    cout << "Title cannot be empty. Please enter a valid title: ";
                    getline(cin, title);
                }

                cout << "Author: ";
                getline(cin, author);
                while (author.empty()) {
                    cout << "Author cannot be empty. Please enter a valid author: ";
                    getline(cin, author);
                }

                cout << "Year: ";
                while (!(cin >> year)) {
                    cout << "Invalid input. Please enter a valid year (numeric value): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Rating: ";
                while (!(cin >> rating)) {
                    cout << "Invalid input. Please enter a valid rating (numeric value): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                library.addBook(Book(id, title, author, year, rating));
                break;
            }
            case 1:
                library.showAllBooks();
                break;
            case 2: {
                string title;
                cout << "Enter title to search: ";
                getline(cin, title);
                library.searchByTitle(title);
                break;
            }
            case 3: {
                string author;
                cout << "Enter author to search: ";
                getline(cin, author);
                library.searchByAuthor(author);
                break;
            }
            case 4: {
                int year;
                cout << "Enter year to search: ";
                cin >> year;
                library.searchByYear(year);
                break;
            }
            case 5:
                library.showHighestRated();
                break;
            case 6:
                library.saveToFile();
                break;
            case 7:
                library.loadFromFile();
                break;
            case 8: {
                int id;
                cout << "Enter the ID of the book you want to delete: ";
                cin >> id;
                library.deleteBook(id);
                break;
            }
            case 9:
                cout << "Exiting..." << endl;
                return 0;
            }
            cout << "Press any key to return to menu...";
            _getch();
        }
    } while (true);

    return 0;
}
