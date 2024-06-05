#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

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
        int choice;
        string fileName;

        cout << "Select the file to save to:" << endl;
        cout << "1 - fantasy" << endl;
        cout << "2 - horror" << endl;
        cout << "3 - science" << endl;
        cout << "4 - thriller" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            fileName = "fantasy.txt";
            break;
        case 2:
            fileName = "horror.txt";
            break;
        case 3:
            fileName = "science.txt";
            break;
        case 4:
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
                file << endl;
            }
            cout << "Data saved to file: " << fileName << endl;
        }
        else {
            cerr << "Unable to open file: " << fileName << endl;
        }
    }

    void loadFromFile() {
        int choice;
        string fileName;

        cout << "Select the file to load from:" << endl;
        cout << "1 - fantasy" << endl;
        cout << "2 - horror" << endl;
        cout << "3 - science" << endl;
        cout << "4 - thriller" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            fileName = "fantasy.txt";
            break;
        case 2:
            fileName = "horror.txt";
            break;
        case 3:
            fileName = "science.txt";
            break;
        case 4:
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

int main() {
    string filename = "library.txt";
    BookLibrary library(filename);

    int choice;
    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Show all books" << endl;
        cout << "3. Search by title" << endl;
        cout << "4. Search by author" << endl;
        cout << "5. Search by year" << endl;
        cout << "6. Show the highest rated book" << endl;
        cout << "7. Save to file" << endl;
        cout << "8. Load from file" << endl;
        cout << "9. Delete a book" << endl;
        cout << "0. Exit" << endl;
        cout << "----------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
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
            cin.ignore();

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
        case 2:
            library.showAllBooks();
            break;
        case 3: {
            string title;
            cout << "Enter title to search: ";
            getline(cin, title);
            library.searchByTitle(title);
            break;
        }
        case 4: {
            string author;
            cout << "Enter author to search: ";
            getline(cin, author);
            library.searchByAuthor(author);
            break;
        }
        case 5: {
            int year;
            cout << "Enter year to search: ";
            cin >> year;
            library.searchByYear(year);
            break;
        }
        case 6:
            library.showHighestRated();
            break;
        case 7:
            library.saveToFile();
            break;
        case 8:
            library.loadFromFile();
            break;
        case 9: {
            int id;
            cout << "Enter the ID of the book you want to delete: ";
            cin >> id;
            library.deleteBook(id);
            break;
        }
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}