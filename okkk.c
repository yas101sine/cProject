#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#ifdef _WIN32
#endif

    //         function to set color 
//     void SetColor(int num){
//     WORD newc;               
//     //This handle is needed to get the current background attribute
//     
//     HANDLE change = GetStdHandle(STD_OUTPUT_HANDLE);
//     CONSOLE_SCREEN_BUFFER_INFO scr;   
//     //csbi is used for wAttributes word
//             
//     if(GetConsoleScreenBufferInfo(change, &scr))
//     {
//          //To mask out all but the background attribute, and to add the color
//          newc = (scr.wAttributes   &0xF0) + (num &0x0F);
//          SetConsoleTextAttribute(change, newc);
//     }
//    
//}
  // la strecture produit
    typedef struct Produit{
      char code[20];
	  char nom[20];
	  int quantite;
	  float prix;	
	}Produit;
     
   typedef struct stat{
   	 float tot;
   	 float max;
   	 float min;
     int day_achat;
     int month_achat;
     int year_achat;
   }stat;

//    struct tm *mytime=localtime(&ti);
//  printf("%i/%i/%i\n",mytime->tm_mon+1,mytime->tm_mday,mytime->tm_year+1900); 
     
  stat st;
 
  Produit p[100];
  // la fonction ajouter Produit
  int i=0,j;
  int k=0;
  int l=0;
   
//void mjs(char s[])
//{
//  int r;
//  for (r=0;r<strlen(s);r++)
//    {
//      s[r]=toupper(s[r]);
//    }
//}

    void AjouterProduit(){
     system("color 03");
    	
//  	SetColor(10);
    
  	printf("\n\tdonner le code de votre produit:\t");
  	scanf("%s",&p[i].code);
  	printf("\tdonner le nom du produit:\t");
  	scanf("%s",&p[i].nom);
  	printf("\tdonner le prix du produit:\t");
  	scanf("%f",&p[i].prix);
  	printf("\tdonner la quantit� du produit:\t");
  	scanf("%d",&p[i].quantite);
//  	SetColor(5);
  	printf("\n\tvotre produit est bien enregistrer\n");
  	i++;
  	int r;
//  	SetColor(6);
  	printf("\n\t0-> Retour au menu principale\n");
  	printf("\t");
  	scanf("%d",&r);
  	while(r!=0){
//  		SetColor(4);
  		printf("\til faut entrer le 0 pour retourner au menu principale:\t");
  		scanf("%d",&r);
	  }
	  system("cls");
	  main();
  }
    void AjouterPlusiurProduit(){
     system("color 03");
  	int np;
//  	SetColor(5);
    printf("\n\tdonner le nombre des produit que tu veux saisir :");
    printf("\t");
  	scanf("%d",&np);
  	while(np<0 || np>100){
//  		SetColor(4);
  		printf("\n\tveuiller saisir un nombre comprie entre 0 et 100 :");
  		printf("\t");
  		scanf("%d",&np);
	  }
	  int a=i;
	  for(i;i<np+a;i++){
//	  	SetColor(10);
     	printf("\n\tdonner le code du produit N�%d:\t",i+1);
    	scanf("%s",p[i].code);
    	printf("\tdonner le nom du produit N�%d:\t",i+1);
    	scanf("%s",p[i].nom);
    	printf("\tdonner le prix du produit N�%d:\t",i+1);
    	scanf("%f",&p[i].prix);
     	printf("\tdonner la quantit� du produit N�%d:\t",i+1);
    	scanf("%d",&p[i].quantite);
//       AjouterProduit();
    	printf("\n");
	  }
	  int x;
//	    SetColor(6);
	    printf("\n\t0-> Retour au menu principale\n\t");
	    scanf("%d",&x);
	    while(x!=0){
//	    	SetColor(4);
	    	printf("\til faut entrer le 0 pour retourner au menu principale:\t");
	    	scanf("%d",&x);
		}
		system("cls");
		main();
  }
    void ListerProduit(){
     system("color 03");
  	int nl;
//  	SetColor(1);
  	usleep(300000);
  	printf("\n\t1->lister tous les produits selon l�ordre alphab�tique� croissant du nom\n");
  	usleep(300000);
  	printf("\n\t2->lister tous les produits selon l�ordre� d�croissant du prix\n\n\t");
//    SetColor(6);
    usleep(300000);
	printf("\n\t0-> Retour au menu principale\n\t");
	wrong:
	scanf("%d",&nl);
  	switch (nl)
	{
		int k;
		Produit ch;
		case 0:
			system("cls");
			main();
			break;
    	case 1:
    		system("cls");
//    		SetColor(5);
//			printf("\n\tProduit :Nom \t Prix \t PrixTTc  \n");
    		for(j=0;j<i;j++){
    			for(k=j+1;k<i;k++){
    				if(strcasecmp(p[j].nom,p[k].nom)>0){
    					ch=p[j];
    					p[j]=p[k];
    					p[k]=ch;
					}   

				}
			}
            for(j=0;j<i;j++){
    	    printf("\n\tP[%d]   : Nom:  %s \t Prix: %.2f \t PrixTTC: %.2f  \n",j+1,p[j].nom,p[j].prix,p[j].prix*1.15);
    		}
//			SetColor(6);
		   	printf("\n\t0-> Retour au menu principale\n");
		   	printf("\t1-> Retour au menu pr�cidant\n\t");
		   	int pm;
		   	se:
		   	scanf("%d",&pm);
		   	switch(pm){
		   	    case 0:
		   		system("cls");
		   		main();
		   		break;
		   		case 1:
		   		system("cls");
		   		ListerProduit();
		   		break;
		   		default:
		   		
//		   				SetColor(4);
		   				printf("\tc'est op�ration n'�xiste pas !!\n");
		   				printf("\tentrer le 0 ou le 1:\t");
		   				goto se;
		   		break;
		   	}
		break;
    	case 2:
    	system("cls");
//    	SetColor(5);
//    	printf("\n\tProduit :Nom \t Prix \t PrixTTc \t la date d'achat \n");

    		for(j=0;j<i;j++){
    		for(k=j+1;k<i;k++){
    	    if(p[j].prix<p[k].prix){
    	    	ch=p[k];
    	    	p[k]=p[j];
    	    	p[j]=ch;
			}
    	    }
    	   	}
            for(j=0;j<i;j++){
    	    printf("\n\tP[%d]   Nom:  %s \t Prix: %.2f \t PrixTTC: %.2f \n",j+1,p[j].nom,p[j].prix,p[j].prix*1.15);
    	    }
//    	    SetColor(6);
    	    printf("\n\t0-> Retour au menu principale\n");
		   	printf("\t1-> Retour au menu pr�cidant\n\t");
		   	int spm;
		   	sse:
		   	scanf("%d",&spm);
		   	switch(spm){
		   	    case 0:
		   		system("cls");
		   		main();
		   		break;
		   		case 1:
		   		system("cls");
		   		ListerProduit();
		   		break;
		   		default:
		   		
//		   				SetColor(4);
		   				printf("\tc'est op�ration n'existe pas !!\n");
		   				printf("\tentrer le 0 ou le 1:\t");
		   				goto sse;
		   		break;
		   	}
    	break;
    	default:
//    		SetColor(4);
    		printf("\tc'est op�ration n'existe pas !!!\n");
    		printf("\tentrer une op�ration valide \n\t");
    		goto wrong;
    	break;
    }
}
    void Acheterproduit(){
     system("color 03");
	int comp=0;
	char code1[20];
	first:
//	SetColor(10);
	printf("\n\tdonner un code du produit: \t");
	scanf("%s",code1);
	for(j=l;j<i;j++){

    if(strcasecmp(p[j].code,code1)==0){
    	comp++;
    	break;
	}
	}
	if(comp>0){
		
			int q;
			printf("\tdonner la qauntit� que tu veut d�duire:\t");
			scanf("%d",&q);
			if(p[j].quantite==0){
//				SetColor(4);
				printf("\tCe produit est en rupture de stock");
				goto first;
			}else{
			while(q>p[j].quantite || q<0){
//				SetColor(5);
				printf("\tla quantit� de se produit dans le stock est %d\n",p[j].quantite);
				printf("\tdonc il faut entrer une quantit� raisonable:\n\t");
				scanf("%d",&q);
			}
		     time_t now = time(NULL);
             struct tm *dt =localtime(&now);
		     st.day_achat=(dt->tm_mday);
		     st.month_achat=(dt->tm_mon+1);
		     st.year_achat=(dt->tm_year+1900);
		    
		     st.tot+=p[j].prix*q;
        	 p[j].quantite-=q;
        	 if(j==0){
        	 	st.max=p[0].prix*q;
        	 	st.min=p[0].prix*q;
			 }else{
             if(p[j].prix*q<st.min){
             	st.min=p[j].prix*q;
			 }
			 else if(p[j].prix*q>st.max){
			 	st.max=p[j].prix*q;
			 }
              }
        	int n;
			printf("\n\top�ration bien �fectuer\n");
		    l++;
			
//			printf(ctime(&t));
//            SetColor(2);
			printf("\n\t0-> retour au menu principale\n\t");
			scanf("%d",&n);
			while(n!=0){
//				SetColor(4);
				printf("\tinvalide operation \n ");
				printf("\tentrer le 0 pour retourner au menu principale\n\t");
				scanf("%d",&n);
			}
			system("cls");
			main();
		}

    
	}else{
//		SetColor(4);
		printf("\n\tle code que tu as entrer n'�xiste pas\n");
		goto first;
	}

}
 
    void RechercherProduits(){
     system("color 03");
	int o;
	usleep(300000);
//	SetColor(1);
	printf("\n\t1->chercher le produit selon le code\n");
	usleep(300000);
	printf("\n\t2->chercher le produit selon la quantit�\n\n");
//	SetColor(6);
	usleep(300000);
	printf("\t0->Retour au menu Principale\n\t");
	oper:
//	SetColor(2);	
//	printf("\n\tchoisir une operation:\t");
	scanf("%d",&o);
	while(o<0 || o>2){
//		SetColor(4);
		printf("\tc'est op�ration n'�xiste pas\n\t");
		goto oper;
	}
	char c[20];
   	int cmp=0;
   	int qu;
	switch (o){
	  case 0:
	  	system("cls");
	  	main();
	  break;	
	  case	1:
	  	system("cls");
//	  	SetColor(2);
	  	printf("\n\tdonner un code :\n\t");
	  	scanf("%s",c);
	  	for(j=0;j<i;j++){
	  		if(strcasecmp(p[j].code,c)==0){
	  	   	printf("P[%d] : Nom: %s \t Prix:  %.2f \t PrixTTC: %.2f \n",j+1,p[j].nom,p[j].prix,p[j].prix*1.15);
			 cmp++;
			}
		  }
		  if(cmp==0){
		  	system("cls");
//		  	SetColor(4);
		  	printf("\n\tle code que tu as entrer ne reference aucun produit\n");
//		  	SetColor(6);
		  	printf("\n\t0->Retour au menu pr�cedant\n");
		    printf("\t1->Retour au menu principale\n\t");
		    int op;
		    opr:
		    scanf("%d",&op);
		    	switch (op){
	                case 1:
	  	            system("cls");
	             	main();
	                break;
	                case 0:
	                system("cls");
	                RechercherProduits();
	                break;
	                default:
//	                SetColor(4);
	                printf("\tcette op�ration n'�xiste pas\n");
	                goto opr;
	                break;
                }
		    
		  }else{
//		  	SetColor(6);
		  	printf("\n\t0->\tRetour au menu pr�cedant\n");
		    printf("\t1->tRetour au menu principale\n\t");
		    int ope;
		    opra:
		    scanf("%d",&ope);
		    	switch (ope){
	                case 1:
	  	            system("cls");
	             	main();
	                break;
	                case 0:
	                system("cls");
	                RechercherProduits();
	                break;
	                default:
//	                SetColor(4);
	                printf("\tcette op�ration n'�xiste pas\n");
	                goto opra;
	                break;
                }
		  }
		  
	  break;
	  case 2:
	  	system("cls");
//	  	SetColor(2);
	  	printf("\n\tdonner une quantit� :\n\t");
	  	scanf("%d",&qu);
	  	for(j=0;j<i;j++){
	  		if(p[j].quantite==qu){
	  	   	printf("\tP[%d]:   Nom: %s \t Prix: %.2f \t PrixTTC: %.2f \n",j+1,p[j].nom,p[j].prix,p[j].prix*1.15);
			 cmp++;
			}
		  }
		  	if(cmp==0){
		  	system("cls");
//		  	SetColor(4);
		  	printf("\n\tla quantit� que tu as entrer ne reference aucun produit\n");
//		  	SetColor(6);
		  	printf("\n\t0->Retour au menu pr�cedant\n");
		    printf("\t1->Retour au menu principale\n\t");
		    int op;
		    opr1:
		    
		    scanf("%d",&op);
		    	switch (op){
	                case 1:
	  	            system("cls");
	             	main();
	                break;
	                case 0:
	                system("cls");
	                RechercherProduits();
	                break;
	                default:
//	                SetColor(4);
	                printf("\tcette op�ration n'�xiste pas\n");
	                goto opr1;
	                break;
                }
		    
		  }else{
//		  	SetColor(6);
		  	printf("\n\t0->\tRetour au menu pr�cedant\n");
		    printf("\t1->tRetour au menu principale\n\t");
		    int ope;
		    opra1:
		  
		    scanf("%d",&ope);
		    	switch (ope){
	                case 1:
	  	            system("cls");
	             	main();
	                break;
	                case 0:
	                system("cls");
	                RechercherProduits();
	                break;
	                default:
//	                SetColor(4);
	                printf("\tcette op�ration n'�xiste pas\n");
	                goto opra1;
	                break;
                }
		  }
	  break;
	}
	
	
}
  
    void EtatStock(){
     system("color 03");
    	int comp=0;
//	SetColor(5);
	printf("\n\tles produit dont la quantit� inferieur � 3 est : \n");
	for(j=0;j<i;j++){
		if(p[j].quantite<3){
//		 SetColor(8);
		 printf("\n\tP[%d]:  Nom: %s \t Prix: %.2f \t PrixTTC: %.2f \n",j+1,p[j].nom,p[j].prix,p[j].prix*1.15);
		 comp++;
		}
	}
	int n;
	if(comp==0){
//		SetColor(4);
		printf("\n\til n'existe aucun produit dans la quantit� est inferieur � 3\n");
//		SetColor(6);
		printf("\n\t0->Retour au menu principale:\n\t");
		scanf("%d",&n);
		while(n!=0){
//			SetColor(4);
			printf("\tc'est op�ration n'existe pas\n");
			printf("\tentrer une op�ration valid�:\n\t");
		    scanf("%d",&n);
		}
		system("cls");
		main();
	}
	else{
//		SetColor(7);
		printf("\n\t0->Retour au menu principale:\n\t");
		scanf("%d",&n);
		while(n!=0){
//			SetColor(4);
			printf("\tc'est op�ration n'�xiste pas\n");
//			SetColor(2);
			printf("\tentrer un op�ration valid�:\n\t");
		    scanf("%d",&n);
		}
		system("cls");
		main();
	}
}
  
    void AlimenterStock(){
     system("color 03");
    char ch[20];
    int q,cmp=0;
//    SetColor(5);
  	printf("\n\tdonner le code du produit que tu veut augmenter dans votre stock\n\t");
  	scanf("%s",&ch);
  	for(j=0;j<i;j++){
  		if(strcasecmp(p[j].code,ch)==0){
  			cmp++;
  			break; 
		  }
	  }
	  if(cmp>0){
	  	printf("\tdonner la quantit� que tu veux ajouter\n\t");
	  	scanf("%d",&q);
	  	while(q<=0){
	  		printf("\tvous devez ajouter une quantit� sup�rieur � 0\n\t");
	  		scanf("%d",&q);
		  }
		  p[j].quantite+=q;
		  printf("\n\top�ration bien �ffectuer\n");
		  printf("\n\t0->retour au menu principale\n\t");
		  int n;
		  scanf("%d",&n);
		  while(n!=0){
		  	printf("\til faut entrer le 0 pour retour au menu principale\n\t");
		    scanf("%d",&n);
		  }
		  system("cls");
		  main();
	  }
	  else{
	  	int n;
//	  	SetColor(4);
	  	printf("\n\tle code que tu as entrer ne reference aucun produit\n");
//	  	SetColor(6);
	  	printf("\n\t0-> Retour au menu Principale\n\t");
		scanf("%d",&n);
		  while(n!=0){
		  	printf("\til faut entrer le 0 pour retour au menu principale\n\t");
		  	scanf("%d",&n);
		  }
		  system("cls");
		  main();
	  }
  }

    void SupprimerProduits(){
     system("color 03");
    	char sc[20];
    	int comp=0;
//    	SetColor(5);
    	printf("\tdonner le code du produit que tu veux supprimer\n\t");
    	scanf("%s",&sc);
    	for(j=0;j<i;j++){
    		if(strcmp(p[j].code,sc)==0){
    			comp++;
    			p[j]=p[j+1];
    			i--;
    			break;
			}
		}
		if(comp==0){
//			SetColor(4);
			printf("\tle code que tu as entrer ne r�fernce aucun produit\n");
//			SetColor(6);
			printf("\t0->Retour au menu principale\n\t");
			int n;
			scanf("%d",&n);
			while(n!=0){
//				SetColor(4);
				printf("\top�ration non valide \n");
				printf("\til faut entrer le 0 pour retourner au menu principale\n\t");
				scanf("%d",&n);
			}
				system("cls");
			main();
		}else{
//			SetColor(2);
			int k;
//			Produit ch;
//			for(j=0;j<i;j++){
//					p[j]=p[j+1];				
//			}
//			SetColor(2);
			printf("\tle produit est bien supprimer\n");
//			SetColor(4);
			printf("\t0->Retour au menu Principale\n\t");
			int n;
			scanf("%d",&n);
			while(n!=0){
//				SetColor(4);
				printf("\top�ration non valide \n");
				printf("\til faut entrer le 0 pour retourner au menu principale\n\t");
				scanf("%d",&n);
			}
			system("cls");
			main();
			
		}
	}

    void StatistiqueVente(){
     system("color 03");
//    	SetColor(9);
    	int n,m;
    	usleep(300000);
    	printf("\n\t1->Afficher le total des prix des produits vendus en journ�e courante \n");
    	usleep(300000);
    	printf("\n\t2->Afficher la moyenne des prix des produits vendus en journ�e courante \n");
    	usleep(300000);
    	printf("\n\t3->Afficher le Max des prix des produits vendus en journ�e courante \n");
    	usleep(300000);
    	printf("\n\t4->Afficher le Min des prix des produits vendus en journ�e courante \n");
    	usleep(300000);
//    	SetColor(6);
    	printf("\n\t0->Retour au menu principale\n\t");
    	scanf("%d",&n);
    	menup:
    	switch(n){
    		case 0:
    			system("cls");
    			main();
    		break;
			case 1:
    		    system("cls");
//    		    for(j=0;j<i;j++){
//    		    	st.tot+=p[j].prix;
//				}
//				SetColor(5);
    		    printf("\n\tle total des prix des produits vendus en journ�e courante sont:%.2f dont la date est %i/%i/%i \t",st.tot,st.day_achat,st.month_achat,st.year_achat);
//    		    SetColor(2);
    		    printf("\n\t0->Retour au menu pr�cedant ");
    		    printf("\n\t1->Retour au menu principale\n\t");
                scanf("%d",&m);
                menu:
                switch(m){
                	case 0:
						system("cls");
						StatistiqueVente();
					break;
                	case 1:
                		system("cls");
                		main();
                	break;
					
					default:
//						SetColor(4);
						printf("\tc'est op�ration n'est pas valid�\n\t");
						scanf("%d",&m);
						goto menu;
					break;	
				}
    		break;	
			case 2:
				 system("cls");
			    
//				SetColor(5);
				if(l==0){
//					SetColor(4);
					printf("\n\til n'ya aucun produit achet� ce jour l�\n");
//						SetColor(2);
    		    printf("\n\t0->Retour au menu pr�cedant ");
    		    printf("\n\t1->Retour au menu principale\n\t");
                scanf("%d",&m);
                menuu:
                switch(m){
                	case 1:
                		system("cls");
                		main();
                	break;
					case 0:
						system("cls");
						StatistiqueVente();
					break;
					default:
//						SetColor(4);
						printf("\tc'est op�ration n'est pas valid�\n\t");
						scanf("%d",&m);
						goto menuu;
					break;	
				}
				}else{
				
				printf("\n\t la moyenne des prix des produits vendus en journ�e courante est:%.2f dont la date est %i/%i/%i t\n",st.tot/l,st.day_achat,st.month_achat,st.year_achat);
//    			SetColor(2);
    		    printf("\n\t0->Retour au menu pr�cedant ");
    		    printf("\n\t1->Retour au menu principale\n\t");
                scanf("%d",&m);
                menu1:
                switch(m){
                	case 1:
                		system("cls");
                		main();
                	break;
					case 0:
						system("cls");
						StatistiqueVente();
					break;
					default:
//						SetColor(4);
						printf("\tc'est op�ration n'est pas valid�\n\t");
						scanf("%d",&m);
						goto menu1;
					break;	
				}
				}
    		break;	
			case 3:
				system("cls");    			
//				SetColor(5);
    			printf("\n\tle Max des prix des produits vendus en journ�e courante sont :%.2f dh dont la date est %i/%i/%i \t",st.max,st.day_achat,st.month_achat,st.year_achat);
//    			 SetColor(2);
    		    printf("\n\n\t0->Retour au menu pr�cedant ");
    		    printf("\n\t1->Retour au menu principale\n\t");
                scanf("%d",&m);
                 menu2:
                switch(m){
                	case 1:
                		system("cls");
                		main();
                	break;
					case 0:
						system("cls");
						StatistiqueVente();
					break;
					default:
//						SetColor(4);
						printf("\tc'est op�ration n'est pas valid�\n\t");
						scanf("%d",&m);
						goto menu2;
					break;	
				}
    		break;	
			case 4:
			    system("cls");
			 
//				SetColor(5);
    			printf("\n\tle Min des prix des produits vendus en journ�e courante sont :%.2f dh dont la date est %i/%i/%i \t",st.min,st.day_achat,st.month_achat,st.year_achat);
//    			 SetColor(2);
    		    printf("\n\n\t0->Retour au menu pr�cedant ");
    		    printf("\n\t1->Retour au menu principale\n\t");
                scanf("%d",&m);
                 menu3:
                switch(m){
                	case 1:
                		system("cls");
                		main();
                	break;
					case 0:
						system("cls");
						StatistiqueVente();
					break;
					default:
//						SetColor(4);
						printf("\tc'est op�ration n'est pas valid�\n\t");
						scanf("%d",&m);
						goto menu3;
					break;	
				}
    		break;
    		default:
//    				SetColor(4);
						printf("\tc'est op�ration n'est pas valid�\n\t");
						scanf("%d",&n);
						goto menup;
    		break;	
		}
	
	
}

    int main() {
    // specifeid charcters
    SetConsoleOutputCP(GetACP());
    SetConsoleCP(GetACP());
     system("color 8F");
    int i,j;
//    SetColor(11);
    printf("\n\t\t ");
    for(i=0;i<30;i++){
    	printf(":");
    	usleep(1000);
	}
	printf("!! bienvenue !!");
	for(i=0;i<30;i++){
		printf(":");
		usleep(1000);
	}
    
    
    printf("\n\n");
//    SetColor(9);
              // menu
    printf("\t1-> Ajouter un nouveau produit\n\n");
    usleep(100000);
    printf("\t2-> Ajouter plusieurs nouveaux produits \n\n");
    usleep(100000);
    printf("\t3-> Lister tous les produits \n\n");
    usleep(100000);
    printf("\t4-> Acheter un produit\n\n");
    usleep(100000);
    printf("\t5-> Rechercher des produits \n\n");
    usleep(100000);
    printf("\t6-> Etat du stock\n\n");
    usleep(100000);
    printf("\t7-> Alimenter le stock\n\n");
    usleep(100000);
    printf("\t8-> Supprimer les produits\n\n");
    usleep(100000);
    printf("\t9-> Statistique de vente\n\n");
    usleep(100000);
    printf("\t10-> Quitter l'application\n\n");
    usleep(100000);
//    SetColor(15);
    int numerooperation;
    do{
    printf("\tchoisire votre propre op�ration :\n\t");
    scanf("%d",&numerooperation);
	}while(numerooperation<1 || numerooperation>10);
	
    system("cls");
    switch (numerooperation)
	{
    	case  1 :
    	    AjouterProduit();
    	break;
    	case  2 :
    		AjouterPlusiurProduit();
    	break;
    	case  3 :
    		ListerProduit();
    	break;
    	case 4 :
    		Acheterproduit();
    	break;
    	case 5 :
    		RechercherProduits();
    	break;
    	case 6:
    		EtatStock();
    	break;
    	case 7:
    		AlimenterStock();
    	break;
    	case 8:
    	    SupprimerProduits();
    	break;
    	case 9:
    		StatistiqueVente();
    	break;
    	case 10:
    		exit(0);
    	break;
	}
	return 0;
}
