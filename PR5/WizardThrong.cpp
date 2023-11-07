#include "WizardThrong.h"

WizardThrong::WizardThrong() {
    m_group = new vector<Wizard>;
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
        os << *wizard << endl;
    }
    os << endl;
    return os;
}
