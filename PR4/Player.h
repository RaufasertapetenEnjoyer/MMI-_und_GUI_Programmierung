//
// Created by jena- on 26.10.2023.
//

#ifndef MMI_UND_GUI_PLAYER_H
#define MMI_UND_GUI_PLAYER_H
#include <iostream>
using namespace std;

class Player {
private:
    string m_name;
    int m_level;
    std::string m_optionalNotice;

public:
    Player(string name, int level, string optionalNotice = "");
    ~Player();

    void setName(string name);
    string getName();

    void setLevel(int level);
    int getLevel();

    void setOptionalNotice(string optionalNotice);
    std::string getOptionalNotice();

    static Player* makeNewbie(string name);

    friend ostream& operator<<(ostream& os, Player& player);
};

ostream& operator<<(ostream& os, Player& player);


#endif //MMI_UND_GUI_PLAYER_H
