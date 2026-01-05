#include <iostream>
using namespace std;

char tablero[3][3] = {
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'}
}

char jugador = 'x'

//Muestra el tablero
void mostrarTablero() {
    cout << "Tic tac toe\n\n";
    for(int i=0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << tablero[i][j];
            if(j < 2) cout << " | ";
        }
        if(i < 2) cout << "\n---+---+---\n";
    }
    cout << "\n\n";
}

// Cambia de jugador
void cambiarJugador() {
    jugador = (jugador == 'X') ? 'O' : 'X';
}

// Verifica ganador
bool hayGanador() {
    for(int i = 0; i < 3; i++) {
        if(tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
            return true;
        if(tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
            return true;
    }
    if(tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
        return true;
    if(tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
        return true;

    return false;
}

// Verifica empate
bool hayEmpate() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(tablero[i][j] != 'X' && tablero[i][j] != 'O')
                return false;
    return true;
}

// Realiza una jugada
void jugar() {
    int opcion;
    cout << "Turno del jugador " << jugador << " : ";
    cin >> opcion;

    int fila = (opcion - 1) / 3;
    int col = (opcion - 1) % 3;

    if(opcion < 1 || opcion > 9 || tablero[fila][col] == 'X' || tablero[fila][col] == 'O') {
        cout << "Movimiento inválido\n";
        cin.ignore();
        cin.get();
        return;
    }

    tablero[fila][col] = jugador;
}

int main() {
    while(true) {
        mostrarTablero();
        jugar();

        if(hayGanador()) {
            mostrarTablero();
            cout << "El jugador " << jugador << " gana\n";
            break;
        }

        if(hayEmpate()) {
            mostrarTablero();
            cout << "Empate\n";
            break;
        }

        cambiarJugador();
    }

    return 0;
}