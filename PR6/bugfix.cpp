#include <memory>
#include "string"
#include "iostream"

using namespace std;

/**
 * a) Die Attribute werden als const angegeben. Sie können also nicht mit dem "="-Operator gesetzt werden.
 * Man initialisiert diese mit ":" vor dem eigentlichen Körper des Konstruktors (Initialisierungsliste).
 * Zudem können einige Zeilen eingespart werden.
 */
class MyFruit {
public:
    MyFruit(string name, float calories) : m_name(name), m_calories(calories){};

private:
    const string m_name;
    const float m_calories;
};


/**
 * b) Um Objekte in einem Konstruktor zu initialisieren muss man wieder eine Initalisierungsliste nutzen.
 * Dafür ruft man darin dann den Konstruktor der anderen Klasse auf und weist sie dem passenden Member zu.
 */
class City {
public:
    City(std::string city, std::string zipCode)
            : m_city(city), m_zipCode(zipCode) {}
private:
    std::string m_city;
    std::string m_zipCode;
};
class Address {
public:
    Address(std::string street, int houseNumber,
            std::string city, std::string zipCode);
private:
    std::string m_street;
    int m_houseNumber;
    City m_city;
};
Address::Address(std::string street, int houseNumber,
                 std::string city, std::string zipCode)
        : m_street(street), m_houseNumber(houseNumber),
        m_city(City(city, zipCode)){}


/**
 * c) getNumberOfEars ist keine konstante Methode. Nur konstante Methoden können auf konstante Objekte aufgerufen werden,
 * um zu verhindern, dass die Konstanz verletzt wird.
 */
class Bunny {
public:
    Bunny(int numberOfEars) : m_numberOfEars(numberOfEars) {
    }
    void setNumberOfEars(int numberOfEars) {
        m_numberOfEars = numberOfEars;
    }
    int getNumberOfEars() const{
        return m_numberOfEars;
    }
private:
    int m_numberOfEars;
};
int main1(int argc, const char * argv[]) {
    const Bunny bunny(2);
    cout << "Bunny: Ears " << bunny.getNumberOfEars();
    return 0;
}

/**
* d) Auch hier wird die Konstanz gebrochen. Der Operator "[]" sowie dessen Rückgabewert müssen konstant sein.
*/
class ArrayVector {
public:
    ArrayVector() {}
    const double& operator[](const int& index) const{
        return v[index];
    }
private:
    double v[3];
};
int main2(int argc, const char * argv[]) {
    const ArrayVector v;
    const double& x = v[1];
    return 0;
}

/**
* e) "setName" darf nicht konstant sein, da hier ein Wert verändert wird.
*/
class Person {
public:
    Person(std::string name) : m_name(name) {}
    std::string getName() const {
        return m_name;
    }
    void setName(std::string name) {
        m_name = name;
    }
private:
    std::string m_name;
};
int main3(int argc, const char * argv[]) {
    Person p("Malte");
    p.setName("Bob");
    return 0;
}

/**
 * f) "p" darf auf keinen wert mehr zeigen, da dieser Zeiger jetzt von "p2" repräsentiert wird.
 * Es sind Shared Pointer statt Unique Pointer nötig.
 */
int main(int argc, const char * argv[]) {
    std::shared_ptr<int> p(new int);
    std::shared_ptr<int> p2 = std::move(p);
    std::cout << *p << std::endl;
    std::cout << *p2 << std::endl;
    return 0;
}