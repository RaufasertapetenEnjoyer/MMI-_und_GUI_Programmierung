#include "WizardThrong.h"

WizardThrong::WizardThrong() {
    m_group = new vector<Wizard*>;
}

void WizardThrong::addWizard(Wizard* wizard) {
    m_group->push_back(wizard);
}

WizardThrong::~WizardThrong() {
    delete m_group;
}

ostream &operator<<(ostream &os, const WizardThrong& group) {
    os << "Wizard Throng: " << endl;
    for (Wizard* wizard : *group.m_group){
        os << *wizard;
    }
    return os;
}

Wizard WizardThrong::operator|(WizardThrong& wizardThrong) {
    int sumMana = 0;
    int sumEnergy = 0;

    for (Wizard* wizard : *this->m_group) {
        sumEnergy += wizard->getEnergy();
        sumMana += wizard->getMana();
        wizard->setEnergy(0);
    }

    for (Wizard* wizard : *wizardThrong.getGroup()) {
        sumEnergy += wizard->getEnergy();
        sumMana += wizard->getMana();
        wizard->setEnergy(0);
    }

    Wizard strongestWizard("The Wizard of Porttob", sumEnergy, sumMana);

    return strongestWizard;
}

vector<Wizard *> *WizardThrong::getGroup() const {
    return m_group;
}
