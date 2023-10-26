#include <iostream>
#include "Player.h"
using namespace std;

int main(){
    Player* p1 = Player::makeNewbie("Michael");
    auto* p2 = new Player("Jan", 1, "friendly");
    cout << endl;

    cout << "Player1: " << *p1 << endl;
    cout << "Player2: " << *p2 << endl;

    p1->setName("Thomas");
    p1->setLevel(25);
    p1->setOptionalNotice("unfriendly");

    p2->setLevel(51);
    p2->setLevel(48);
    p2->setOptionalNotice("unlucky");

    cout << "Player1: " << *p1 << endl;
    cout << "Player2: " << *p2 << endl;

    delete p1;
    delete p2;
}
