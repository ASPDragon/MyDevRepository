#define _CRT_SECURE_NO_WARNINGS
#define CHKFIT(X,Y,Z) (((X)  > (Y) ) || ((X)  < (Z)))
#include <iostream>
#include <time.h>

using namespace std;

enum PLAYER {HUMAN='X', AI='O', EMPTY='_'};

typedef struct {
    int szX;
    int szY;
    PLAYER** map;
    int towin;
} Field;

void setval(PLAYER** map,int x, int y, PLAYER state){
    map[y][x] = state;
}
PLAYER getval(PLAYER** map, int x, int y){
    return map[y][x];
}

bool isvalid(Field &field, int x, int y){ // bool for C++. HW task
    return 1;
}

int isempty(Field &field, int x, int y){ // HW task
    return 1;
}

int check_line(Field &field, int x, int y, int vx, int vy, PLAYER c) {

} // HW task

void init(Field &field){
    int min;
    cout << "Input the dimensions on X-axis and Y-axis: " << endl;
    cin >> field.szX >> field.szY;
    min = (field.szX < field.szY) ? field.szX : field.szY;
    do {
        cout << "Input the length of win-condition line: " << endl;
        cin >> field.towin;
    } while(!(field.towin <= min)); // this cycle prohibits user to input win_string longer than the least of 2 dimensions
    field.map = new PLAYER*[field.szY];
    for(int i = 0; i < field.szY; ++i){
        field.map[i] = new PLAYER[field.szX];
        for(int j = 0; j < field.szX; ++j){
            setval(field.map, j, i, EMPTY);
        }
    }
}

void print(Field &field){
    system("cls"); // or clear for unix
    cout << "Noughts and crosses v 1.0:" << endl;
    for(int i = 0; i < field.szY;  ++i){
        cout << "|";
        for(int j = 0; j < field.szX; ++j){
            cout << (char)(getval(field.map, j, i)) << "|";
        }
        cout << "\n";
    }
}

void human_move(Field &field){
    int x, y;
    do {
        cout<< "Enter X and Y: ";
        cin >> x >> y;
        x--;
        y--;
    }while(!isvalid(field, x, y) || !isempty(field, x, y));
    setval(field.map, y, x, HUMAN);
}

void ai_move(Field &field){
    int x, y;
    do{
        x = rand() % field.szX;
        y = rand() % field.szY;
    }while(!isempty(field, x, y));
    setval(field.map, y, x, AI);
}

bool check_win(Field &field, PLAYER player){ // possible bool
    for(int x = 0; x < field.szX; ++x){
        for(int y = 0; y < field.szY; ++y){
            if(check_line(field, x, y, 1, 0, player)) return 1; // hor
            if(check_line(field, x, y, 0, 1, player)) return 1; // vert
            if(check_line(field, x, y, 1, 1, player)) return 1; // diag1
            if(check_line(field, x, y, 1, -1, player)) return 1; // diag2
        }
    }
    return 0;
}

int check_draw(Field &field){
    for(int x = 0; x < field.szX; ++x){
        for(int y = 0; y < field.szY; ++y){
            if(isempty(field, x, y)) return 0;
        }
    }
}

int check_game(Field &field, PLAYER p, const char* win_string){
    if (check_win(field, p)){
        cout << win_string << endl;
        return 1;
    }
    if (check_draw(field)){
        cout << "draw" << endl;
        return 1;
    }
    return 0;
}

void mem_mng(Field &field){
    init(field);
    for(int i = 0; i < field.szY; i++){
        delete [] field.map[i];
    }
    delete [] field.map;
}

void tictactoe(){
    Field field;
    while (true){ // c++ "true"
        init(field);
        print(field);
        while (true){
            human_move(field);
            print(field);
            if (check_game(field, HUMAN, "Human won!")) break;
            ai_move(field);
            print(field);
            if (check_game(field, AI, "AI won!")) break;
        }
        char answer;
        cout << "Play again?(y/n)";
        cin >> answer;
        if(answer != 'y'){
            cout << "I never planned to play with you in the first place" << endl;
            mem_mng(field);
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    Field field;
    int ng;
    do{
        cout << "(1) to Start a new game" << endl << "(2) to Exit" << endl;
        cin >> ng;
    }while(CHKFIT(ng,2,1));
    switch(ng){
    case 1:
        srand(time(0));
        init(field);
        print(field);
        human_move(field);
        print(field);
        ai_move(field);
        break;
    case 2:
        cout << "I have never planned to play with you in the first place" << endl;
        return 1;
        break;
    }
}
