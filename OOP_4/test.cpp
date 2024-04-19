#include <iostream>
#include <string>

using namespace std;

struct Carriege {
    int number;
    int places;
    int passengers;
};

class Train {
private:
    int maxCarriege;
    string model;
    int carriegeCount;
    Carriege* carriege;
public:
    Train() : model("No model"), carriegeCount(0), carriege(nullptr), maxCarriege(0) {}

    Train(string mod, int maxCar) : model(mod), maxCarriege(maxCar), carriegeCount(0), carriege(new Carriege[maxCarriege]) {}

    Train(const Train& other) : model(other.model), maxCarriege(other.maxCarriege), carriegeCount(other.carriegeCount) {
        carriege = new Carriege[maxCarriege];
        for (int i = 0; i < other.carriegeCount; ++i) {
            carriege[i] = other.carriege[i];
        }
    }

    ~Train() {
        delete[] carriege;
    }

    Train& operator=(const Train& other) {
        if (this != &other) {
            delete[] carriege;
            model = other.model;
            maxCarriege = other.maxCarriege;
            carriegeCount = other.carriegeCount;
            carriege = new Carriege[maxCarriege];

            for (int i = 0; i < other.carriegeCount; ++i) {
                carriege[i] = other.carriege[i];
            }
        }
        return *this;
    }

    void ShowCarrigies() {
        cout << "Train : " << model << endl;
        cout << "Carrieges : " << carriegeCount << endl;

        for (int i = 0; i < carriegeCount; i++)
        {
            cout << "Number of : " << carriege[i].number << endl;
            cout << "Places in carriage : " << carriege[i].places << endl;
            cout << "Count of passengers : " << carriege[i].passengers << endl;
        }
    }

    void AddCariege(int number, int places, int passengers) {
        if (carriegeCount < maxCarriege)
        {
            carriege[carriegeCount].number = number;
            carriege[carriegeCount].places = places;
            carriege[carriegeCount].passengers = passengers;
            carriegeCount++;
            cout << "Carriage added successfully." << endl;
        }
        else
        {
            cout << "Cannot add more carriages. Maximum limit reached." << endl;
        }
    }

    void AddPassenger(int carriageNumber, int count) {
        if (carriageNumber >= 1 && carriageNumber <= carriegeCount) {
            int index = carriageNumber - 1;
            if (carriege[index].passengers + count <= carriege[index].places) {
                carriege[index].passengers += count;
                cout << count << " passengers added to carriage " << carriageNumber << "." << endl;
            }
            else {
                cout << "Cannot add passengers. Carriage is full." << endl;
            }
        }
        else {
            cout << "Invalid carriage number." << endl;
        }
    }

    void SetModel(string mod) {
        model = mod;
    }
};

int main()
{
    Train train1("t202", 5);
    train1.AddCariege(1, 50, 0);
    train1.AddCariege(2, 40, 0);

    Train train2 = train1;

    cout << "First train:" << endl;
    train1.ShowCarrigies();

    cout << "\nSecond train (copied from first):" << endl;
    train2.ShowCarrigies();

    return 0;
}
