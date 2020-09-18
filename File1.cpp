#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
#include "SNAfficheur.h"
 #include "SNLigne.h"


#include <stdio.h>
#include <sstream>
#include <iostream>
#include <math.h>
#define PI 3.14159265
#include <fstream>
#include <time.h>
using namespace std;

 int SaisirBinaire()
        {
          char bin[100];
          int nb = 0;
          cin >> bin ;
          for(int i=0; i<strlen(bin);i++)
           {
             nb = nb*2+(bin[i]-'0');
           }
           return nb;
        }

        string EntierVersChaineEnBinaire(int nb)
        {
          ostringstream oss;
          bool copie = false;
          for(int i=31;i>=0;i--)
          {
            if(((nb>>i)&1) == 1)
            {
              copie = true;
            }
            if(copie == true)
            {
              oss << ((nb>>i)&1);
            }
          }
          return oss.str();
        }

int main()
{
	float choix;
	int nb;
	int ret;
	float base;
	float bases;
	float valeur1;
	float valeur2;
	float resultat;
	char operateur;
	char fonction[10];
	char phrase[200];
	char buffer[256];
	SNAfficheur aff;
	SNLigne lg;



	time_t timestamp = time(NULL);
	strftime(buffer, sizeof(buffer), "%A %d %B %Y - %X.", localtime(&timestamp));
	cout << buffer << endl;
	cout << "" << endl;




	cout << "Calcul(1), Trigo(2), Conversion(3) : ";
	cin >> choix;
	if (choix == 1 )
	{
		cout<< "Saisir le calcul :"<<endl;
		cin >> valeur1>> operateur>> valeur2 ;
		if (operateur == '+')
		{
			resultat =valeur1 + valeur2;
						sprintf(phrase ,"%.3f %c %.3f = %.3f", valeur1, operateur, valeur2, resultat);
						cout << phrase;

		}
		if (operateur == '-')
		{
			resultat =valeur1 - valeur2;
						sprintf(phrase ,"%.3f %c %.3f = %.3f", valeur1, operateur, valeur2, resultat);
						cout << phrase;
		}
		if (operateur == '*')
		{
			resultat =valeur1 * valeur2;
						sprintf(phrase ,"%.3f %c %.3f = %.3f", valeur1, operateur, valeur2, resultat);
						cout << phrase;
		}
		if (operateur == '/')
		{
			resultat =valeur1 / valeur2;
						sprintf(phrase ,"%.3f %c %.3f = %.3f", valeur1, operateur, valeur2, resultat);
						cout << phrase;
		}
	}
	if (choix == 2 )
	{
		cout<< "Saisir le calcul :"<<endl;
		cin>> fonction>> valeur1;
		if (strcmp(fonction, "cos")==0)
		{
			resultat = cos(valeur1);
						sprintf(phrase ,"%s(%.3f) = %.3f", fonction,  valeur1, resultat);
						cout << phrase;
		}
		if (strcmp(fonction, "sin")==0)
		{
			resultat = sin(valeur1);
						sprintf(phrase ,"%s(%.3f) = %.3f", fonction,  valeur1, resultat);
						cout << phrase;
		}
		if (strcmp(fonction, "tan")==0)
		{
			resultat = tan(valeur1);
						sprintf(phrase ,"%s(%.3f) = %.3f", fonction,  valeur1, resultat);
						cout << phrase;
		}
	}
	if (choix == 3 )
	{
		cout<< "Conversion"<<endl;
                cout << "Choix de la base de saisie : Decimal (1) , Hexa (2) , binaire (3)" << endl;
				cin >> bases ;
				if (bases == 1)
                {
                   cout << "saisir le nombre" << endl ;
				   cin >> nb ;
				   ret = nb ;
                }
						if (bases == 2)
                        {
						   cout << "saisir le nombre" << endl ;
						   cin >> hex >> nb;
						   ret = nb ;
						   
                        }
								if (bases == 3)
                                {
                                   cout << "saisir le nombre" << endl ;
                                   nb = SaisirBinaire();
                                }
                cout << "Choix de la base d'affichage : Decimal (1) , Hexa (2) , binaire (3)" << endl;
                cin >> base ;
				if (bases == 1)
                {
                   cout << "voici le nombre en Décimal" << endl ;
				   cout << dec << nb << endl;
				}
						else if (bases == 2)
                        {
                            cout << "voici le nombre en hexadécimal" << endl ;
                            cout << hex << nb << endl;
                        }
								else if (bases == 3)
                                {
                                    cout << "voici le nombre en binaire" << endl ;
                                    cout << EntierVersChaineEnBinaire(nb) << endl ;
                                }

	}

		cout << endl;


	 ofstream monFlux;
	 monFlux.open("calculatrice.log");
	 monFlux  << "historique de calcul :" << endl;
     monFlux << buffer << endl;
	 monFlux <<  "" << endl;
	 monFlux << phrase;


	cout << "chargement : immédiat (0) , fondu (1) , vers haut (2) , vers bas (3) , défiler gauche (4) , défiler droite (5) , ouvrir V (6) , fermer V (7) , défiler haut (8) , défiler bas (9) , tenir (10) , neige (11) , scintillement (12) , pixel (13) , HELLO WORD (14) , welcome (15) " << endl ;
	cin >> choix ;
	if (choix == 0) {
		lg.ModifierEffetChargement(LEADING_IMMEDIATE);
	}
		else if (choix == 1) {
				 lg.ModifierEffetChargement(LEADING_XOPEN);
			 }
					else if (choix == 2) {
						lg.ModifierEffetChargement(LEADING_CURTAIN_UP);
					}



	aff.ModifierAdresseIPDuServeurUDP("172.20.182.57");
	aff.ModifierPortDuServeurUDP(4321);
	lg.ModifierMessage(phrase);
	aff.EnvoyerLigneEnUDP(lg);


	monFlux.close();


	cout << "merci de votre visite sur la calculatrice , veiller rafraichir la page pour recommencer" ;
	cin.get();cin.get();cin.get();
	return 0;
  }

