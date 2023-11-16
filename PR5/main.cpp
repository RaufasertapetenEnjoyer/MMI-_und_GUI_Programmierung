#include "WizardThrong.h"
#include "Plant.h"
#include "Stone.h"
#include "WarriorWizard.h"

int main() {
    Stone stone("Alphastone");
    Plant plant("Planty", 100);

    Warrior warrior1("Harry Pottroper", 100, 50);
    Warrior warrior2("Boeser Mann", 20, 120);

    Wizard wizard1("The magical man", 100, 20);
    Wizard wizard2("The mystical man", 1, 1000);
    Wizard wizard3("The intermediate man", 120, 89);
    Wizard wizard4("The weak one", 56, 1);

    auto* warriorWizard1 = new WarriorWizard("The double agent", 100, 20, 20);

    LivingThing livingThing1("Lon live", 100);


    cout << "Taking 27 energy from livingThing1" << endl;
    livingThing1 -= 27;
    cout << livingThing1 << endl;

    cout << endl << "Battle 1: " << endl << "Warrior1 attacking a stone: " << endl;
    warrior1 >> stone;
    cout << warrior1 << endl;
    cout << stone << endl;

    cout << endl << "Battle 2: " << endl << "Warrior2 attacking warrior1: " << endl;
    warrior2 >> warrior1;
    cout << warrior1 << endl;
    cout << warrior2 << endl;

    cout << endl << "Battle 3: " << endl << "Warrior2 attacking warrior1 again: " << endl;
    warrior2 >> warrior1;
    cout << warrior1 << endl;
    cout << warrior2 << endl;

    cout << endl << "Battle 4: " << endl << "Warrior2 attacking a plant: " << endl;
    warrior2 >> plant;
    cout << warrior2 << endl;
    cout << plant << endl;

    cout << endl << "Battle 5: " << endl << "Wizard2 transferring mana to wizard1: " << endl;
    wizard2 >> wizard1;
    cout << wizard1 << endl;
    cout << wizard2 << endl;

    cout << endl << "Battle 6: " << endl << "Wizard2 attacking warrior2: " << endl;
    wizard2 >> warrior2;
    cout << wizard2 << endl;
    cout << warrior2 << endl;

    cout << endl << "Battle 7: " << endl << "Wizard2 attacking warriorwizard1: " << endl;
    auto* warriorWizardAsWizard = dynamic_cast<Wizard*>(warriorWizard1);
    wizard2 >> *warriorWizardAsWizard;
    cout << wizard2 << endl;
    cout << *warriorWizard1 << endl;

    cout << endl << "Battle 8: " << endl << "Warrior1 attacking warriorwizard1: " << endl;
    auto* warriorWizardAsWarrior = dynamic_cast<Warrior*>(warriorWizard1);
    warrior1.setEnergy(100);
    warrior1 >> *warriorWizardAsWarrior;
    cout << warrior1 << endl;
    cout << *warriorWizard1 << endl;


    WizardThrong wizardThrong1;
    wizardThrong1.addWizard(&wizard1);
    wizardThrong1.addWizard(&wizard2);

    WizardThrong wizardThrong2;
    wizardThrong1.addWizard(&wizard3);
    wizardThrong1.addWizard(&wizard4);

    cout << "Merging throngs: " << endl;

    Wizard ultimateWizard = wizardThrong1 | wizardThrong2;
    cout << wizard1;
    cout << wizard2;
    cout << wizard3;
    cout << wizard4;
    cout << ultimateWizard << endl;
}