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
bool factible(int* *problema, int puestas, int* *sol){
    int x = puestas/9;
    int y = puestas%9;
    for(int i=0;i<9;i++){
        if((sol[x][y] == sol[x][i]) && (y != i)) return false; /*Coincidencia en fila.*/
        if((sol[x][y] == sol[i][y]) && (x != i)) return false; /*Coincidencia en columna.*/
    }
    /*while(x%3 != 0){
        x--;
    }
    while(y%3 != 0){
        y--;
    }*/
    return true;
}

void imprimirSol(int* *sol){
    cout<<"SOLUCION"<<endl;
    for(int i=0;i<9;i++){
        cout<<endl;
        for(int j=0;j<9;j++) cout<<sol[i][j]<<" ";
    }
    cin.get();
}

void sudokuBT(int* *problema, int puestas, int* *sol){
    if(puestas == 81) imprimirSol(sol);
    cout<<endl<<"Puestas: "<<puestas<<endl;
    if(!problema[puestas/9][puestas%9]){
        cout<<"No hay numero ("<<puestas/9<<","<<puestas%9<<")."<<endl;
        for(int c=1;c<=9;c++){
            sol[puestas/9][puestas%9] = c;
            if(factible(problema, puestas, sol)){
                cout<<c<<" es factible."<<endl;
                sudokuBT(problema, puestas+1, sol);
            }
        }
        sol[puestas/9][puestas%9] = 0;
    }else{
        cout<<sol[puestas/9][puestas%9]<<" ya está puesta."<<endl;
        sudokuBT(problema, puestas+1, sol);
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
    
    solucion[0][0] = 5; 
    solucion[0][1] = 3;
    solucion[0][4] = 7;
    solucion[1][0] = 6;
    solucion[1][3] = 1;
    solucion[1][4] = 9;
    solucion[1][5] = 5;
    solucion[2][1] = 9;
    solucion[2][2] = 8;
    solucion[2][7] = 6;
    
    for(int i=0;i<9;i++){
        cout<<endl;
        for(int j=0;j<9;j++) cout<<sudoku[i][j]<<" ";
    }
    
    sudokuBT(sudoku, 0, solucion);
    
    return 0;
}

