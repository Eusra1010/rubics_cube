#include <iostream>
#include <string>
using namespace std;

char Color[]= { 'W', 'Y', 'R', 'G', 'B', 'O' };
char cube[7][2][2];

void initializeCube() {
    int x=0;
    for (int f = 1; f <= 6; f++)
    {
       for (int i = 0; i < 2; i++)
       {
          for (int j = 0; j < 2; j++)
                cube[f][i][j] = Color[x];
       }
       x++;

    }

}

void printCube() {
    string faces[6] = {"U","D","F","B","L","R"};
    for(int f=1; f<=6; f++){
        cout << faces[f-1] << " face:\n";
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
                cout << cube[f][i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
}





void rotateDown(){

    char temp[2] = {cube[4][0][1], cube[4][1][1]};
     char temp1[2] = {cube[3][0][1], cube[3][1][1]};

    cube[4][0][1] = cube[2][0][1];
    cube[4][1][1] = cube[2][1][1];

    cube[3][0][1] = cube[1][0][1];
    cube[3][1][1] = cube[1][1][1];

    cube[1][0][1] = temp[0];
    cube[1][1][1] = temp[1];

    cube[2][0][1] = temp1[0];
    cube[2][1][1] = temp1[1];
    printCube();
}

int main(){
    string move;

    initializeCube();
    cout<<"Initial State"<<endl;
    printCube();
     cout << "Enter rotation (u, d, l, r): ";
     cin >> move;


    if(move=="d") rotateDown();


    printCube();

    return 0;
}
