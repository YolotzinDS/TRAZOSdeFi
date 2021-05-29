#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <C:\Program Files (x86)\Dev-Cpp\include\GL\glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
//#include "CuadradoDDA.cpp"

using namespace std;

//definimos la svariables parra usar elm algoritmo dda
	int x_1 = 1 ;
	int  y_1 =1;
	int x_2 =18;
	int   y_2 =18 ;
	int Pasos, c, p;
	int dy, dx;
		int steps = 0;
		float xinc, yinc;
		float Pendiente;
		//brem, funcion que crea la imagen
		//descricpion geometrica de la imagen se va us
		void algoritmoBre(){//Contiene mas infor
		//PONER LOS PIXELES EN LA PEN.
		Pendiente = (dy * 1.0) + (dx * 1.0);
   		int x = x_1;
		int y= y_1;
        dx= (x_2 - x_1);
		dy= (y_2 - y_1);
		Pasos = max(dy, dx);
		glClear(GL_COLOR_BUFFER_BIT); //Con esta funcion el color de la ventana
		glColor3f(1,1,1);//Establecer color de objeto
		glLoadIdentity();
		
		//Plano Cartesiano
		glLineWidth(5.0);
		glColor3f(0.0471,  0.7176, 0.949); //sky blue
		glBegin(GL_LINES);
		        glVertex2d(-20, 0);
		        glVertex2d(20, 0);
                glVertex2d(0, 20);
                glVertex2d(0, -20);
			glEnd();
  //lc
  glLineWidth (2.0);
  glColor3f(0, 2, 1);
  glBegin(GL_LINES);

        for(int j = 21; j > -20; j--){ //Lin h
            glVertex2f(-20, j + 0.5);
            glVertex2f(20, j + 0.5);
			}
		for(int j = 21; j > -20; j--){//Lin v
            glVertex2f( j + 0.5 , -20);
            glVertex2f( j + 0.5, 20);
				}
			glEnd();
			glPointSize(18); //Se define el tama�o del pixel dependiendo
			glBegin(GL_POINTS);
		    	    glColor3f(1.0, 1.0, 0.0);
		        	glColor3f(4, 0.788, 0.41);
		//INICIO A
		Pendiente=(dy/dx);
		if (Pendiente==1){ //INIT A
			p= (2*dy-dx);
			for(int k = 0; k < p + 1 ; k++){
				glVertex2d(round(x_1),round(y_1));
				y_1++;
				cout <<"(" << x_1 <<","<< y_1 <<")" ",";
            }		cout <<"\n";//funcion de la funcion
			for(int k = 0 ;k < p + 1 ; k++){
				glVertex2d(round(x_1),round(y_1-1));
				x_1= x_1 + 1;
				cout <<"(" << x_1 <<","<< y_1 <<")" ",";
			}cout <<"\n"; //ini de la funcion x2
			for(int k = 0 ; k < p + 1 ; k++){
				glVertex2d(round(x_2),round(y_1-1));
				y_1--;
				cout <<"(" << x_2 <<","<< y_1 <<")" ",";
			}	cout <<"\n";
			for(int k = 0 ; k < p + 1 ; k++){
				glVertex2d(round(x_2),round(y_1));
				x_2--;
				cout <<"(" << x_2 <<","<< y_1 <<")" ",";
			}
		}else{
			glutHideWindow();
		}
		glEnd();
		glFlush();
	}
	void algoritmoDDA()//contiene
		{
			//delta
			dy = y_2 - y_1;
			dx = x_2 - x_1;
		//Pendiente = (dy * 1.0) / (dx * 1.0);
        Pendiente=(dy/dx);
		//  Numero de pasos
		Pasos = max(dy, dx);
		glClear(GL_COLOR_BUFFER_BIT); //Con esta funcion el color de la ventana
		glColor3f(1,1,1);//Establecer color de objeto
		glLoadIdentity();
		//Plano Cartesiano
		glLineWidth(5.0);
		glColor3f(0.0471,  0.7176, 0.949); // blue
		glBegin(GL_LINES);
		glVertex2d(-20, 0);
        glVertex2d(20, 0);
	    glVertex2d(0, 20);
        glVertex2d(0, -20);
			glEnd();
	  //cruce
	  glLineWidth (2.0);
	  glColor3f(4, 2, 0);
	  glBegin(GL_LINES);

        for(int j = 21; j > -20; j--){ //Lineas horizontales
            glVertex2f(-20, j + 0.5);
            glVertex2f(20, j + 0.5);
		}
		for(int j = 21; j > -20; j--)//Lineas verticales
		{
         glVertex2f( j + 0.5 , -20);
            glVertex2f( j + 0.5, 20);

			}
		glEnd();
		glPointSize(18); //Se define el tama�o del pixel dependera de que ta�a�o lo quiera
		glBegin(GL_POINTS); //prin grefica
		        glColor3f(1.0, 1.0, 0.0);
		        glColor3f(1, 0, 1);


	if(dx>dy){
				steps=dx;
			}
			else{
				steps=dy;
			}
				yinc = dy/ steps;
	xinc = dx/ steps;

			if(Pendiente==1){
    //COMIENZO DE UNA U OTRA
   	for(int i=0;i<steps+1;i++){
					glVertex2d(round(x_1),round(y_1));
					y_1= y_1 + yinc;
					cout <<"(" << x_1 <<","<< y_1 <<")" ",";
				}
					cout << "\n";
				//SEGUNDA PART
				for(int i=0;i<steps+1;i++){
					glVertex2d(round(x_1),round(y_1-1));
					x_1= x_1 + xinc;
					cout <<"(" << x_1 <<","<< y_1 <<")" ",";
				}
				cout << "\n";

				/* PARTE 3*/for(int i=0 ; i < steps + 1 ; i++){
					glVertex2d(round(x_2),round(y_1-1));
					y_1= y_1 - yinc;
					cout <<"(" << x_2 <<","<< y_1 <<")" ",";
				}
				cout << "\n";
				/* PAR ifn*/	for(int i = 0 ; i < steps + 1 ; i++){
					glVertex2d(round(x_2),round(y_1));
					x_2= x_2 - xinc;
					cout <<"(" << x_2 <<","<< y_1 <<")" ",";
				}
			}else{
				glutHideWindow();
			}
//printf( " %f\n", x1 6
     //
	//		    printf("x1 = %f", x1);

 		glEnd();

        glLineWidth(0.000001);
           glVertex2d(x_1 * 1.0, y_1 * 1.0);
            glVertex2d(x_2 * 1.0, y_2 * 1.0);

		glEnd();//Elemento paa que no se cierre la ventana

		glFlush(); //
	}
		void Init(){
			glClearColor(1, 1,1, 0); //Color de pantalla de la 2da vengtana
		}
		void reshape(int width, int height)
		{
			glViewport(0, 0, width, height);
			glMatrixMode(GL_PROJECTION);//Tipo de proyeccion
			glLoadIdentity(); //Asigna nr la matriz identidad como de proyecto
			glOrtho (-20, 20, -20, 20, -1, 1);//SSe debe de usar una proyeccion
			glMatrixMode(GL_MODELVIEW);
			  }
		int eleccion;
/*	void menuRE(){
                do{
			system("cls");
			cout << "CUADRADO, FAVOR DE SELECCIONAR EL METODO QUE " << endl ;
			cout << "[1].Salir " << endl ;
		    cout << "[2].Volver " << endl ;

			cin >> e;


		switch (e){
            system("cls");
			case 1:
                    exit (0);
                    break;
					default:

						break;

			}

			}while( eleccion != 0);
				system("pause>null");


			}*/
		int main(int argc, char * argv[]){

		system ("color 0b "); //COLOR PANT

		do{
			system("cls");
			cout << "CUADRADO, FAVOR DE SELECCIONAR EL METODO QUE " << endl ;
			cout << "[1].Metodo de ADD " << endl ;
		    cout << "[2].Metodo de Bresen " << endl ;
			cout << "[3].Limpiar ventana " << endl ;
			cout << "[4]. Salir " << endl ;
			cin >> eleccion;

		switch (eleccion){
            system("cls");
			case 1:
                system ("color 0d ");
		cout << "HOLA la figura asi quedaria:) " << endl ;
		printf( "COORDENADA DE ORIGEN PARA X1:  %d\n", x_1 );
       		printf( "COORDENADA DE ORIGEN PARA Y1: %d\n", y_1 );
       			printf( "COORDENADA DE ORIGEN PARA X2:  %d\n", x_2 );
       		printf( "COORDENADA DE ORIGEN PARA Y2: %d\n", y_2 );
//		cout << "Coordenada de origen pora Y= " ; cin >> y_1;
//  cout << "Ingrese cuanto pixeles sera el cuadrado " ; cin >> c;

			glutInit(&argc, argv); //Realizar inclinacion
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//numero
		glutInitWindowSize(800, 800);//va ser cundo se va a  establecer la altura y la anchura del pixel
		glutCreateWindow("Algoritmo DDA"); //se gegnerara una 2da ventana de visualizacion
		Init();//p.init

			glutDisplayFunc(algoritmoDDA);//signa img.
		glutReshapeFunc(reshape);//Cambio de tama�o de la ventana actual
		glutMainLoop();//Con esta funcion las ventanas  que hayan creado
;
		//cout << "Ingrese Y2: " ; cin >> y_2;


			break;
			case 2:
                 system ("color 0a ");
		        	cout << "HOLA la figura asi quedaria:) " << endl ;

			printf( "COORDENADA DE ORIGEN PARA X1:  %d\n", x_1 );
       		printf( "COORDENADA DE ORIGEN PARA Y1: %d\n", y_1 );
       			printf( "COORDENADA DE ORIGEN PARA X2:  %d\n", x_2 );
       		printf( "COORDENADA DE ORIGEN PARA Y2: %d\n", y_2 );
//		cout << "Coordenada de origen pora Y= " ; cin >> y_1;
//		cout << "Ingrese cuanto pixeles sera el cuadrado " ; cin >> c;
			glutInit(&argc, argv); //Realizar inclinacion
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//numero
		glutInitWindowSize(800, 800);//va ser cundo se va a  establecer la altura y la anchura del pixel
		glutCreateWindow("Algoritmo Bresem"); //se gegnerara una 2da ventana de visualizacion
		Init();//p.init

			glutDisplayFunc(algoritmoBre);//signa img.
		glutReshapeFunc(reshape);//Cambio de tama�o de la ventana actual
		glutMainLoop();//Con esta funcion las ventanas  que hayan creado
;
		//cout << "Ingrese Y2: " ; cin >> y_2;
				break;
				case 3:
					cleardevice();
					break;
					case 4:
                         
                         system ("color 0C ");
                         
	cout << "SALIENDO >_<" << endl ;
cout << " >_<" << endl ;
cout << " >_<" << endl ;
						exit (0);
						break;

			}

	}while( eleccion != 0);
		system("pause>null");

	}
