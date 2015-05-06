/* 
 * File:   main.cpp
 * Author: Lotrox
 *
 * Created on 6 de mayo de 2015, 1:43
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
bool factible(int puestas, int* *sol){
    int x = puestas/9;
    int y = puestas%9;
    for(int i=0;i<9;i++){
        if((sol[x][y] == sol[x][i]) && (y != i)) return false; /*Coincidencia en fila.*/
        if((sol[x][y] == sol[i][y]) && (x != i)) return false; /*Coincidencia en columna.*/
    }
    
    while(x%3 != 0)x--;
    while(y%3 != 0)y--;
    
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            if((i != puestas/9) && (j != puestas%9)){
                if(sol[puestas/9][puestas%9] == sol[i][j]) return false;
            }
        }
    }
    return true;
}

void imprimirSol(int* *sol){
    cout<<"SOLUCION";
    for(int i=0;i<9;i++){
        cout<<endl;
        for(int j=0;j<9;j++) cout<<sol[i][j]<<" ";
    }
}

void sudokuBT(bool& fin, int puestas, int* *sol){
    if(puestas == 81) fin = true;
    else if(!sol[puestas/9][puestas%9]){
        for(int c=1;c<=9;c++){
            sol[puestas/9][puestas%9] = c;
            if(factible(puestas, sol)){
                sudokuBT(fin, puestas+1, sol);
            }
        }
        sol[puestas/9][puestas%9] = 0;
    }else{
        sudokuBT(fin, puestas+1, sol);
    }
}

int main(int argc, char** argv) {
    int* *sudoku = new int*[9];
    int* *solucion = new int*[9];
    
    for(int i=0;i<9;i++){
        sudoku[i] = new int[9];
        solucion[i] = new int[9];
        for(int j=0;j<9;j++){
            sudoku[i][j] = 0;
            solucion[i][j] = 0;
        }
    }
    
    sudoku[0][0] = 5; 
    sudoku[0][1] = 3;
    sudoku[0][4] = 7;
    sudoku[1][0] = 6;
    sudoku[1][3] = 1;
    sudoku[1][4] = 9;
    sudoku[1][5] = 5;
    sudoku[2][1] = 9;
    sudoku[2][2] = 8;
    sudoku[2][7] = 6;  
    sudoku[3][0] = 8;
    sudoku[3][4] = 6;
    sudoku[3][8] = 3;
    sudoku[4][0] = 4;
    sudoku[4][3] = 8;
    sudoku[4][5] = 3;
    sudoku[4][8] = 1;
    sudoku[5][8] = 6;
    sudoku[5][0] = 7;
    sudoku[5][4] = 2;
    sudoku[6][1] = 6;
    sudoku[6][6] = 2;
    sudoku[6][7] = 8;
    sudoku[7][3] = 4;
    sudoku[7][4] = 1;
    sudoku[7][5] = 9;
    sudoku[7][8] = 5;
    sudoku[8][4] = 8;
    sudoku[8][7] = 7;
    sudoku[8][8] = 9;
    
    
    
    cout<<"SUDOKU PROPUESTO";
    for(int i=0;i<9;i++){
        cout<<endl;
        for(int j=0;j<9;j++){
            solucion[i][j] = sudoku[i][j];
            cout<<sudoku[i][j]<<" ";
        }
    }
    cout<<endl<<endl;
    bool fin = false;
    sudokuBT(fin, 0, solucion);
    if(fin) imprimirSol(solucion);
    return 0;
}

