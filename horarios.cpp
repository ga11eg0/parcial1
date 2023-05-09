#include <iostream>
#include <fstream>

using namespace std;

void run();
void leer_plantilla(char *** horario);


int main(){

    //leer_plantilla();
    run();
    return 0;
}

void run(){

    char *** horario = nullptr;

    leer_plantilla(horario);
    
}


void leer_plantilla(char *** horario){
    
    fstream leer;
    char name[] = "/home/paris/Documents/Documents/informatica II/parcial1/formato_horario.txt";
    

    try{

        int rows = 6;
        int cols = 18;
        char *** dictionary = new char**[rows];

        leer.open(name);
        if (!leer.is_open()){ // check for errors 
            throw 1; 
        }

        


        char c;

        for ( int i = 0; i < rows; i++){

            dictionary[i] = new char*[cols];

            for ( int j = 0; j < cols; j++){

                dictionary[i][j] = new char[7]; 

                for( int m = 0, k = 0; m <= 7 ; m++){

                    leer.get(c);
                    if ( c != ',' && c!='\n' && m != 7 ){
                        dictionary[i][j][k] = c;
                        
                        k++;
                    }

                }
                //cout << dictionary[i][j] << endl;
            }
        }
        
        int hour = 6;
        /*
        for (int j= 0; j < cols; j++ ) {

            if ( j != 0 ){

                if ( hour < 10 ){
                    cout << hour << "  |";
                } else{
                    cout << hour << " |";
                }
                ++hour;
            } else{
                cout << "___|";
            }
            for(int i = 1 ; i < rows; i++) {
               cout << dictionary[i][j] << " |" ;

            }
            cout << endl;

            
        }*/

        horario = new char**[rows];

        for ( int i = 0; i < rows; i++){

            horario[i] = new char*[cols];

            for ( int j = 0; j < cols; j++){

                horario[i][j] = new char[7]; 

                for( int m = 0; m <7 ; m++){

                    /*leer.get(c);
                    if ( c != ',' && c!='\n' && m != 7 ){
                        (*horario)[i][j][k] = c;
                        
                        k++;
                    }*/
                    horario[i][j][m] = dictionary[i][j][m];
                }
                //cout << dictionary[i][j] << endl;
            }
        }

        
        for ( int i = 0; i < rows; i++ ){
            for( int j = 0; j < cols; j++){
                delete[]dictionary[i][j];
            }
            delete[]dictionary[i];
        }
        delete[]dictionary;
        dictionary = nullptr;
      



    }catch( int c ){
        if( c == 1){
            cout << "error al abrir archivo para lectura:" << endl;
        }
    }
}

