#include <iostream>
#include <string>

using namespace std;

class Pet{
protected:
    string name;
    int feed;
    int sleep;
    int happy;
public:
    Pet(){
        name = "Unknown";
        feed = 1;
        sleep = 1;
        happy = 1;
    }
    Pet(string _name, int _feed, int _sleep, int _happy){
        name = _name;
        feed = _feed;
        sleep = _sleep;
        happy = _happy;
    }
    void SetName(string _n){
        name = _n;
    }
    string GetName(){
        return name;
    }
    void Feed(){
        cout << "Being feed!" << endl;
        feed += 50;
        cout << "Your pet is full now "<< endl;
    }
    void Sleep(){
        cout << "Your pet is sleeping." << endl;
        sleep += 50;
        cout << "....." << endl;
        cout << "Your pet just awakes :))" << endl;
    }
    void Happy(){
        cout << "Your pet is happy now." << endl;
    }
    void PetState(){
        cout << endl;
        cout << "Feed level: " << feed << endl;
        cout << "Sleep level: " << sleep << endl;
        cout << "Happy level: " << happy << endl;
        cout << endl;
        if (feed < 20){
            cout << name << " is hungry" << endl;
            cout << "Press f to feed your pet." << endl;
            cout << endl;
        }
        if(sleep < 20){
            cout << name << " needs to go to sleep."<< endl;
            cout << "Press s to let your pet sleep." << endl;
            cout << endl;
        }
        if(happy < 20){
            cout << name << " is not happy" << endl;
            cout << "Make your pet happy." << endl;
            cout << endl;
        }
    }

};

class Dog : public Pet{
public:
    void playingBall(){
        happy += 20;
        sleep -= 20;
    }
    void sick(){
        sleep -= 20;
        happy -= 20;
    }
    void Next2hrs(){
        feed -= 50;
        sleep -= 50;
        happy -= 50;

    }
};

class Cat : public Pet{
public:
    void Rubbing(){
        happy += 20;
    }
    void HairCut(){
        happy += 20;
    }
    void Next30mins(){
        feed -= 50;
        sleep -= 50;
        happy -= 50;
    }
};

class Hamster : public Pet{
public:
    void Running(){
        happy += 20;
        feed -= 20;
        sleep -= 20;
    }
    void
    void NextHour(){
        feed -= 50;
        sleep -= 50;
        happy -= 50;
    }
};
void printMenu(){
    cout << "MENU" << endl;
    cout << "Choose your option!!!" << endl;
    cout << "a: see your pet's state" << endl;
    cout << "f: feed your pet" << endl;
    cout << "s: let your pet sleep" << endl;
    cout << "h: make your pet happy" << endl;
    cout << "q: quit the game!" << endl;
}

void PlayGame(Pet myPet){
    printMenu();
    char option;
    cin >> option;
    while (true){
        if(option != 'a' && option != 's' && option != 'h' && option != 'q' && option != 'f'){
            cout << "Your option is not valid." << endl;
            printMenu();
            cout << "Choose another option" << endl;
            cin >> option;
        }
        else if (option == 'a'){
            myPet.PetState();
            cout << endl;
            cout << "Choose another option" << endl;
            cin >> option;
        }
        else if (option == 'f'){
            myPet.Feed();
            cout << "Choose another option" << endl;
            cin >> option;
        }
        else if (option == 's'){
            myPet.Sleep();
            cout << "Choose another option" << endl;
            cin >> option;
        }
        else if (option == 'h'){
            myPet.Happy();
            cout << "Choose another option" << endl;
            cin >> option;
        }
        else if (option == 'q'){
            cout << "Are you sure to exit the game? Y or N" << endl;
            char choice;
            cin >> choice;
            if(choice == 'Y') {
                cout << "GOOD BYE!!!" << endl;
                break;
            }
            else{
                cout << "Choose your option" << endl;
                cin >> option;
            }
        }

    }
}

int main() {
    cout << "Tamagotchi Pet Game" << endl;
    cout << "Start Game" << endl;
    cout << "Choose your pet's type!!!" << endl;
    cout << "Dog???" << endl;
    cout << "Cat???" << endl;
    cout << "or Hamster???" << endl;
    string pet_type;
    cin >> pet_type;
    while (pet_type != "Dog" && pet_type != "Cat" && pet_type != "Hamster"){
        cout << "The pet's type you choose not exit in this game" << endl;
        cout << "Choose your pet's type!!!" << endl;
        cin >> pet_type;
    }
    cout << "What's your " << pet_type << "'s name>" << endl;
    string petname;
    cin >> petname;
    cout << "Your" << pet_type << "'s name is " << petname << endl;
    cout << endl;
    if (pet_type == "Dog"){
        Dog dog;
        Pet *myPet = &dog;
        dog.SetName(petname);
        PlayGame(dog);
    }
    else if (pet_type == "Cat"){
        Cat cat;
        Pet *myPet = &cat;
        cat.SetName(petname);
        PlayGame(cat);
    }
    else if (pet_type == "Hamster"){
        Hamster hamster;
        Pet *myPet = &hamster;
        hamster.SetName(petname);
        PlayGame(hamster);
    }





    return 0;
}
