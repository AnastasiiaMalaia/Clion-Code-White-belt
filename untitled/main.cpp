#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Person {
public:
    set<int> all_years_NAME;
    set<int> all_years_SURNAME;
    //изменения имени на first_name в год year
    void ChangeFirstName(int year, const string& first_name) {
        all_years_NAME.insert(year);
        body[year].first = first_name;
    }

    //изменения фамилии на last_name в год year
    void ChangeLastName(int year, const string& last_name) {
        all_years_SURNAME.insert(year);
        body[year].first = last_name;
    }

    string GetFullName(int year) {




        if (body.count(year) == 0) { // no date with such year
            if (all_years_NAME.count(all_years_NAME.size()) == 0 && all_years_SURNAME.count(all_years_SURNAME.size()) == 0) {
                return "Incognito";
            } else if (all_years_NAME.count(all_years_NAME.size()) == 0)

        } else if (body.at(year).second == "0" && body.at(year).first != "0") {
            return (body.at(year).first + " with unknown last name");
        } else if (body.at(year).second != "0" && body.at(year).first == "0") {
            return body.at(year).second + " with unknown first name";
        } else {
            return body[year].first + body[year].second;
        }
    }
private:// приватные поля
    struct inform {
        string first;
        string second;
    };
    int k;
    map <int, inform, greater<>> body;
    map <int, inform, greater<>> ::iterator low;
};




int main() {
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

    return 0;
}
