#ifndef MMI_UND_GUI_WIZARDTHRONG_H
#define MMI_UND_GUI_WIZARDTHRONG_H

#include <vector>
#include "Wizard.h"

class WizardThrong {
private:
    vector<Wizard*>* m_group;

public:
    WizardThrong();
    ~WizardThrong();

    void addWizard(Wizard* wizard);

    friend ostream& operator<<(ostream& os, const WizardThrong& group);
};

ostream& operator<<(ostream& os, const WizardThrong& group);

#endif //MMI_UND_GUI_WIZARDTHRONG_H
