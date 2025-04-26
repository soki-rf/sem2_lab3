#include <iostream>
#include <string>

using namespace std;


class School {
protected:
    int studentCount;

private:
    string name;

public:
    School(const string& schoolName, int count) : name(schoolName), studentCount(count) {}
    virtual void printInfo() const {
        cout << "School " << name << endl;
        cout << "Count of students " << studentCount << endl;
    }
    virtual ~School() {}
};


class SpecializedSchool : public School {
private:
    string specialization;

public:
    SpecializedSchool(const string& schoolName, int count, const string& spec)
        : School(schoolName, count), specialization(spec) {}

    void printInfo() const override {
        School::printInfo();
        cout << "Profile " << specialization << endl;
    }
};

int main() {
    cout << "Static polymorphism" << endl;
    School regularSchool("Base school 5", 750);
    SpecializedSchool mathSchool("Fizmat licey 1580", 300, "Matan and Fizika");
    
    regularSchool.printInfo();
    cout << endl;
    mathSchool.printInfo();
    cout << endl;
    cout << "Dynamic polymorphism" << endl;
    School* schoolPtr;
    schoolPtr = &regularSchool;
    schoolPtr->printInfo();
    cout << endl;
    schoolPtr = &mathSchool;
    schoolPtr->printInfo();
    
    return 0;
}
