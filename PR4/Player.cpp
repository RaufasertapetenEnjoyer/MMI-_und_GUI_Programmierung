#include "Player.h"

Player::Player(std::string name, int level, string optionalNotice) {
    m_name = name;
    m_level = level;
    m_optionalNotice = optionalNotice;
    cout << "Player " << m_name << " was created." << endl;
}

Player::~Player() {
    cout << "Player " << m_name << " was destroyed." << endl;
}

void Player::setName(const string& name) {
    m_name = name;
}

std::string Player::getName() const{
    return m_name;
}

void Player::setLevel(int level) {
    if(level <= 50 && level > 0){
        m_level = level;
    }else{
        cerr << "Level " << level << " for player " << m_name << " cant be sat because its over 50 or below 0." << endl;
    }
}

int Player::getLevel() const{
    return m_level;
}

void Player::setOptionalNotice(const std::string& optionalNotice) {
    if(m_optionalNotice.empty()){
        m_optionalNotice = optionalNotice;
    }else{
        m_optionalNotice += ", " + optionalNotice;
    }

}

std::string Player::getOptionalNotice() const{
    return m_optionalNotice;
}

Player* Player::makeNewbie(string name) {
    return new Player(name, 1);
}

std::ostream& operator<<(std::ostream& os, const Player& player){
    os << player.m_name << endl;
    os << "Level: " << player.m_level << endl;
    os << "optional notice: " << (player.m_optionalNotice.empty() ? "none" : player.m_optionalNotice) << endl;
    return os;
}