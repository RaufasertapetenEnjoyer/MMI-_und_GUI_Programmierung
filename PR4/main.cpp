#include <iostream>
#include "Player.h"
#include "PlayerDatabase.h"

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

    cout << endl;
    cout << endl;
    cout << "Tak 2.2"<<endl;
    cout << endl;

    Player player1 = *new Player("Michael", 1);
    Player player2 = *new Player("Thomas", 2, "unfriendly");
    Player player3 = *new Player("Jan", 3, "unlucky, friendly");
    Player player4 = *new Player("Simon", 4, "lucky");

    auto* playerDatabase = new PlayerDatabase();
    /*
    playerDatabase->addPlayer(player1);
    playerDatabase->addPlayer(player2);
    playerDatabase->addPlayer(player3);

    cout << "The following players are in the List: {" << endl;
    cout << *playerDatabase << "}" << endl;

    cout << "There are " << playerDatabase->countPlayersInDatabase() << " players saved in the Database." << endl;
    playerDatabase->clearDatabase();
    cout << "There are " << playerDatabase->countPlayersInDatabase() << " players saved in the Database after cleaning." << endl;

    playerDatabase->addPlayer(player4);

    cout << "Player on position 0 is: " << endl;
    cout << playerDatabase[0] << endl;*/
    playerDatabase->addPlayer(player1);

    delete playerDatabase;

    return 0;
}
