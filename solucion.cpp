#include "constantes.h"
#include "solucion.h"
#include "logica.h"

#include <iostream>
using namespace std;

/*
* Implementar esta función.
* Dependiendo el estado del juego esta debe retornar:  

GANO_X: Si Ha ganado el jugador X
GANO_O: Si Ha ganado el jugador O
EMPATE: Si ya se llenaron todas las casillas y no hay ganador
JUEGO_EN_CURSO: Si el juego aún no se ha terminado.
*/

bool obtenerEstadoEmpate(char** tablero){
    for(int indexA = 0; indexA < 3; indexA++)
        for(int indexB = 0; indexB < 3; indexB++)
            if(tablero[indexA][indexB] == '_')
                return false;
        
    return true;
}




int GetEstado()
{

    /*
    Puedes acceder a las casillas del tableroEnJuegoActual mediante el arreglo de 
    dos dimensiones tableroEnJuegoActual.  

    Los índices empiezan en cero, de modo que puedes acceder a la segunda fila, primera columna 
    de la siguiente manera:
    tableroEnJuegoActual[1][0]
    */

    char** tableroEnJuegoActual = GetTablero();

    
    for(int i = 0; i < 3; i++)
    {
        //Horizontal X
    	if(tableroEnJuegoActual[i][0] == 'X' && tableroEnJuegoActual[i][0] == tableroEnJuegoActual[i][1] && tableroEnJuegoActual[i][1] == tableroEnJuegoActual[i][2])
    		return GANO_X;
        //Horizontal O
    	else if(tableroEnJuegoActual[i][0] == 'O' && tableroEnJuegoActual[i][0] == tableroEnJuegoActual[i][1] && tableroEnJuegoActual[i][1] == tableroEnJuegoActual[i][2])
    		return GANO_O;
        //Vertical X
        else if(tableroEnJuegoActual[0][i] == 'X' && tableroEnJuegoActual[0][i] == tableroEnJuegoActual[1][i] && tableroEnJuegoActual[1][i] == tableroEnJuegoActual[2][i])
    		return GANO_X;
        //Vertical O
    	else if(tableroEnJuegoActual[0][i] == 'O' && tableroEnJuegoActual[0][i] == tableroEnJuegoActual[1][i] && tableroEnJuegoActual[1][i] == tableroEnJuegoActual[2][i])
    		return GANO_O;

    }

    //Diagonal derecha izquierda X
    if(tableroEnJuegoActual[0][2] == 'X' && tableroEnJuegoActual[0][2] == tableroEnJuegoActual[1][1] && tableroEnJuegoActual[1][1] == tableroEnJuegoActual[2][0])
        return GANO_X;
     //Diagona derecha izquierda O
    else if(tableroEnJuegoActual[0][2] == 'O' && tableroEnJuegoActual[0][2] == tableroEnJuegoActual[1][1] && tableroEnJuegoActual[1][1] == tableroEnJuegoActual[2][0])
        return GANO_O;
    //Diagonal izquierda derecha X
    else if(tableroEnJuegoActual[0][0] == 'X' && tableroEnJuegoActual[0][0] == tableroEnJuegoActual[1][1] && tableroEnJuegoActual[1][1] == tableroEnJuegoActual[2][2])
        return GANO_X;
    //Diagonal izquierda derecha O
    else if(tableroEnJuegoActual[0][0] == 'O' && tableroEnJuegoActual[0][0] == tableroEnJuegoActual[1][1] && tableroEnJuegoActual[1][1] == tableroEnJuegoActual[2][2])
        return GANO_O;
    //Si no hay empate.
    else if(obtenerEstadoEmpate(tableroEnJuegoActual) != true)
        return  JUEGO_EN_CURSO;
    //Si hay empate.
    else if(obtenerEstadoEmpate(tableroEnJuegoActual))
        return EMPATE;
    


    return JUEGO_EN_CURSO;
}
