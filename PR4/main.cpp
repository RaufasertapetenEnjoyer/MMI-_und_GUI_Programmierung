#include <iostream>
#include "Player.h"
#include "PlayerDatabase.h"
#include "PlayerDataBaseWithPointers.h"

// (MMI_und_GUI PR4/Player.cpp PR4/main.cpp PR4/PlayerDatabase.cpp PR4/PlayerDatabase.h PR4/PlayerDataBaseWithPointers.cpp PR4/PlayerDataBaseWithPointers.h)
// in cmakelist eintragen um auszuführen

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

    cout << endl << endl << "Task 4.2"<< endl << endl;

    Player* player1 = new Player("Olaf", 1);
    Player* player2 = new Player("Albrecht", 2, "unfriendly");
    Player* player3 = new Player("Hans", 3, "unlucky, friendly");
    Player* player4 = new Player("Simon", 4, "lucky");

    auto* playerDatabase = new PlayerDatabase();
    //auto* playerDatabase = new PlayerDataBaseWithPointers();

//    playerDatabase->addPlayer(player1);
//    playerDatabase->addPlayer(player2);
//    playerDatabase->addPlayer(player3);

    playerDatabase->addPlayer(*player1);
    playerDatabase->addPlayer(*player2);
    playerDatabase->addPlayer(*player3);

    cout << endl <<  "The following players are in the List: {" << endl;
    cout << *playerDatabase << "}" << endl;

    cout << endl << "There are " << playerDatabase->countPlayersInDatabase() << " players saved in the Database." << endl;
    playerDatabase->clearDatabase();
    cout << "There are " << playerDatabase->countPlayersInDatabase() << " players saved in the Database after cleaning." << endl << endl;

//    playerDatabase->addPlayer(player4);

    playerDatabase->addPlayer(*player4);

    cout << "Player on position 0 is: " << endl;
    cout << playerDatabase[0] << endl;
//    playerDatabase->addPlayer(player1);

    playerDatabase->addPlayer(*player1);

    delete playerDatabase;
//    delete player1;
//    delete player2;
//    delete player3;
//    delete player4;

    const PlayerDatabase playerDatabase2;
    playerDatabase2.addPlayer(*player1);
    playerDatabase2.addPlayer(*player2);
    playerDatabase2.addPlayer(*player3);
    playerDatabase2.addPlayer(*player4);

    cout << "There are " << playerDatabase2.countPlayersInDatabase() << " in the const database." << endl;

    cout << playerDatabase2 << endl;

    cout << "Player on position 2: " << endl << playerDatabase2[2] << endl;

    playerDatabase2.clearDatabase();

    cout << "There are " << playerDatabase2.countPlayersInDatabase() << " in the const database." << endl;

    return 0;
}
