#ifndef MMI_UND_GUI_PLAYER_H
#define MMI_UND_GUI_PLAYER_H
#include <iostream>
using namespace std;

class Player {
private:
    string m_name;
    int m_level;
    string m_optionalNotice;

public:
    Player(string name, int level, string optionalNotice = "");
    ~Player();

    void setName(const string& name);
    string getName() const;

    void setLevel(int level);
    int getLevel() const;

    void setOptionalNotice(const string& optionalNotice);
    string getOptionalNotice() const;

    static Player* makeNewbie(string name);

    friend ostream& operator<<(ostream& os, const Player& player);
};

ostream& operator<<(ostream& os, const Player& player);


#endif //MMI_UND_GUI_PLAYER_H
