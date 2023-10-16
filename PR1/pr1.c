#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Aufgabe 1 a)
void printStringStatistic(const char* string){
    int i = 0, spaceCounter = 0, vocalCounter = 0, consonantCounter = 0,
    digitCounter = 0, otherCharactersCounter = 0;

    while(string[i] != '\0'){

        if(isspace(string[i])){
            spaceCounter++;
        }else if(isalpha(string[i])){
            if(tolower(string[i]) == 'a' || tolower(string[i]) == 'e' ||
               tolower(string[i]) == 'i' || tolower(string[i]) == 'o' ||
               tolower(string[i]) == 'u'){
                vocalCounter++;
            }else{
                consonantCounter++;
            }
        }else if(isdigit(string[i])){
            digitCounter++;
        }else{
            otherCharactersCounter++;
        }
        i++;
    }
    printf("The given string: %s has: \n", string);
    printf("Spaces: %d\n", spaceCounter);
    printf("Vocals: %d\n", vocalCounter);
    printf("Consonants: %d\n", consonantCounter);
    printf("Digits: %d\n", digitCounter);
    printf("Other Characters: %d\n\n", otherCharactersCounter);
}

//Aufgabe 1 b)
int calculateValue(int n){
    if(n > 0){
        if(n == 1){
            return 2;
        }
        return 2 * calculateValue(n-1) * calculateValue(n-1) - 1;
    }else{
        printf("The given number is negative or null!");
        return -1;
    }
}

//Aufgabe 1 c)
struct Person{
    char* name;
    int age;
};

//Aufgabe 1 d)
double getAverageAge(struct Person* persons, int length){
    double sumAges = 0;
    if(persons != NULL){
        for (int i = 0; i < length; i++) {
            if(persons[i].name != NULL && persons[i].age >= 0){
                sumAges += persons[i].age;
            }else{
                printf("The data of the persons are invalid!");
            }
        }
        return sumAges / length;
    }else{
        printf("The person list is null!");
        return 0;
    }
}

//Aufgabe 1 e)
void writePersonListToFile(struct Person* person, int length, char* fileName){
    if(person != NULL){
        FILE* file = fopen(fileName, "a+");
        if(file == NULL){
            printf("File can't be opened!");
            return;
        }

        for (int i = 0; i < length; i++) {
            if(person[i].name != NULL && person[i].age >= 0){
                fprintf(file, "%s : %d;\n", person[i].name, person[i].age);
            }else{
                printf("Person can't be printed, because the data is incorrect."
                       "This person will be skipped.");
            }
        }

        fclose(file);
    }else{
        printf("The list of persons is null!");
    }
}

int main() {
    //Aufgabe 1 a)
    char* string = "Hal1lo ich bin e2in Str7ing der ana12lyziert werden so4ll!F   .";
    printStringStatistic(string);

    //Aufgabe 1 b)
    printf("For value -1: %d\n", calculateValue(-1));
    printf("For value 0: %d\n", calculateValue(0));
    printf("For value 1: %d\n", calculateValue(1));
    printf("For value 4: %d\n\n", calculateValue(4));

    //Aufgabe 1 c) - e)
    int length = 10;
    int ageArray[] = {4,55,32,98,1,2,4,5,21, 36};
    char* names[10] = {"Karl", "Lukas", "Peter", "Michael", "Jan", "Simon", "Paul", "Thomas", "Sofia", "Sarah"};
    struct Person* personArray = calloc(length, sizeof(struct Person));

    for (int i = 0; i < length; i++) {
        struct Person person;
        person.name = names[i];
        person.age = ageArray[i];
        personArray[i] = person;
    }

    //Aufgabe 1 d)
    printf("The average age of the persons is %.2f", getAverageAge(personArray, length));

    //Aufgabe 1 e)
    writePersonListToFile(personArray, length, "Personenliste.txt");
}