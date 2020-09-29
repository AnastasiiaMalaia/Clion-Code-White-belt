#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Person {
public:

    //изменения имени на first_name в год year
    void ChangeFirstName(int year, const string& first_name) {
        body[year].first = first_name;
    }

    //изменения фамилии на last_name в год year
    void ChangeLastName(int year, const string& last_name) {
        body[year].second = last_name;
    }

    string GetFullName(int year) {
        string prev_first_name;
        string prev_last_name;
        string first_name;
        string last_name;
        for (const auto &man : body) {
            if (man.first == year) {    // date with such year exists
                if (!man.second.first.empty()) {
                    first_name = man.second.first;
                }
                if (!man.second.second.empty()) {
                    last_name = man.second.second;
                }
                break;
            } else if (man.first < year) {     // year key is less than the asking one
                if (!man.second.first.empty()) {
                    prev_first_name = man.second.first;
                }
                if (!man.second.second.empty()) {
                    prev_last_name = man.second.second;
                }
            } else if (man.first > year) {
                first_name = prev_first_name;
                last_name = prev_last_name;
                break;
            }
        }

        if (!prev_first_name.empty() && first_name.empty()) {
            first_name = prev_first_name;
        }
        if (!prev_last_name.empty() && last_name.empty()) {
            last_name = prev_last_name;
        }

        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
        } else if (first_name.empty()) {   // нет имени
            return last_name + " with unknown first name";
        } else {
            return first_name + " " + last_name;
        }
    }

private:     // приватные поля
    struct inform {
        string first;
        string second;
    };
    map <int, inform> body;
};




/*int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    cout << "=============================================\n\n";
    person.ChangeFirstName(1900, "Solnishko");
    for (int year : {1941, 1965, 1967, 1969, 1970, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    cout << "=============================================\n\n";
    person.ChangeLastName(1900, "Lesnoe");
    for (int year : {1941, 1965, 1967, 1969, 1970, 1990}) {
        cout << person.GetFullName(year) << endl;
    }


    return 0;
}
 */