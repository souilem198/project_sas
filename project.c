
#include<stdio.h>
#include<string.h>


char Nom[100][30]={ "amal","zinab","omar","soufiane","aziz","ayman","said","mariem","hajar","asmae"};
char Prenom[100][30]={"ben omar","hatiti","amadid","ben drisse","ghabrit","wassaadan","chakiri","zaher","azraf","moaagag"};
char Telephone[100][20]={"0698765432","0612345678","0698765432","0712345678","0712345678","0612345678","0612345678","0712345678","0687654312","0612345678"};
int Age[100]={23,40,67,22,16,17,28,40,38,27};
char Statut[100][30]={"valide","valide","annule","traite","reporte","annule","valide","traite","valide","valide"};
int Reference[100];
char Date[100][30]={"10/02/2024","14/04/2024","04/08/2024","22/01/2024","20/05/2024","19/10/2024","23/06/2024","10/02/2024","17/03/2024","12/02/2024"};
int Nombr = 10;
int choix;

void Afficher_patients(){
    printf("Listes des patients :\n");
    for(int i=0;i<Nombr;i++){
        Reference[i]=i+1;
        printf("Refernce :%d, Nom :%s, Prenom :%s, Telephon :%s, Age :%d, Statut :%s, Dtae :%s \n",
    Reference[i], Nom[i], Prenom[i], Telephone[i], Age[i], Statut[i], Date[i]);

    }
}

void Ajouter_une_reserv(){
    printf("Veuillez entrer le nom \n");
    scanf("%s",Nom[Nombr]);
    printf("Veuillez entrer le prenom \n");
    scanf("%s",Prenom[Nombr]);
    printf("Veuillez entrer le telephone \n");
    scanf("%s",Telephone[Nombr]);
    printf("Veuillez entrer l age \n");
    scanf("%d",&Age[Nombr]);
    printf("Veuillez entrer le  statut ( 1 Valide ,2 Reporte ,3 Annule ,4 Traite \n");
    int choix_statut;
    scanf("%d",&choix_statut);
    switch(choix_statut){
        case 1:strcpy(Statut[Nombr],"valide");
        break;
        case 2:strcpy(Statut[Nombr],"reporte");
        break;
        case 3:strcpy(Statut[Nombr],"annule");
        break;
        case 4:strcpy(Statut[Nombr],"traite");
        break;
        default:printf("numero invalide\n");
        break;
    }
    printf("Veuillez entrer la date de reservation  \n");
    scanf("%s",Date[Nombr]);
    Reference[Nombr]=Nombr+1;
    printf("Le reference du client est :%d\n",Reference[Nombr]);
    Nombr++;
    printf("Votre reservation a ete ajoute \n\n");
}

void Modifier_ou_supprimer() {
    int refer, i, ch_oix, nouv_age, choi,trouv;
    char nouv_nom[30], nouv_prenom[30], nouv_tele[30], nouv_statut[30];

    printf("veuillez entrer la reference du client ");
    scanf("%d", &refer);
    printf(" 1 Modifier \n");
    printf(" 2 Supprimer \n");
    printf("entrer votre choix ");
    scanf("%d", &ch_oix);

    switch (ch_oix) {
     case 1: {
        for (i = 0; i < Nombr; i++) {
        if (Reference[i] == refer) {
          trouv = 1;
        printf(" 1 Le nom %s\n", Nom[i]);
        printf(" 2 Le prenom %s\n", Prenom[i]);
        printf(" 3 Le telephone %s\n", Telephone[i]);
        printf(" 4 L age %d\n", Age[i]);
        printf(" 5 Le statut %s\n", Statut[i]);

        printf("Entrer votre choix ");
        scanf("%d", &choi);

        switch (choi) {
        case 1:
         printf("Entrer le nouveau nom \n");
         scanf("%s", nouv_nom);
         strcpy(Nom[i], nouv_nom);
         break;
        case 2:
          printf("Entrer le nouveau prenom \n");
          scanf("%s", nouv_prenom);
          strcpy(Prenom[i], nouv_prenom);
          break;
        case 3:
          printf("Entrer le nouveau telephone \n");
          scanf("%s", nouv_tele);
          strcpy(Telephone[i], nouv_tele);
          break;
        case 4:
          printf("Entrer le nouveau age \n");
          scanf("%d", &nouv_age);
          Age[i] = nouv_age;
          break;
        case 5:
          printf("Entrer le nouveau statut \n");
          scanf("%s", nouv_statut);
          strcpy(Statut[i], nouv_statut);
          break;
         default:
           printf("numero invalide \n");
          break;
        }
        break;
    }
    }
       if (trouv == 0) {
        printf("Reservation non trouvee \n");
            }
        break;
    }

    case 2: {
     for (i = 0; i < Nombr; i++) {
     if (Reference[i] == refer) {
        trouv = 1;
        for (int j = i; j < Nombr - 1; j++) {
        strcpy(Nom[j], Nom[j + 1]);
        strcpy(Prenom[j], Prenom[j + 1]);
        strcpy(Telephone[j], Telephone[j + 1]);
        Age[j] = Age[j + 1];
        strcpy(Statut[j], Statut[j + 1]);
        Reference[j] = Reference[j + 1];
    }
        Nombr--;
        printf("La reservation a ete supprimer \n");
        break;
    }
}
    if (trouv == 0) {
    printf("reservation non trouvee \n");
    }
    break;
    }
    default:
        printf("choix invalide \n");
     break;
    }
}

void Afficher_les_details(){
    int refer,i,trouv;
    printf("veuillez entrer la reference du client ");
    scanf("%d",&refer);
    trouv =0;
     for(i=0;i<Nombr;i++){
        if(Reference[i]==refer){
            printf("Le nom : %s\n",Nom[i]);
            printf("Le prenom : %s\n",Prenom[i]);
            printf("Le telephone : %s\n",Telephone[i]);
            printf("L age : %d\n",Age[i]);
            printf("Le statut : %s\n",Statut[i]);
            printf("La date de reservation : %s\n",Date[i]);
            trouv = 1;
            break;
        }
   }
     if(trouv ==0){
        printf("Reservation non trouver \n");
   }
}

void Recherche_des_reservations(){
    char rech_nom[30];
    int i,c_hoix,refer,trouv;
    trouv = 0;
    printf(" 1 Recherche par nom \n");
    printf(" 2 Recherche par refernce \n");
    printf(" Entrer votre choix \n");
    scanf("%d",&c_hoix);
    switch(c_hoix){
    case 1:{
    printf("veuillez entrer le nom du client ");
    scanf("%s",rech_nom);
    for(i=0;i<Nombr;i++){
        if(strcmp(rech_nom,Nom[i])==0){
            printf("Le prenom : %s\n",Prenom[i]);
            printf("Le telephone : %s\n",Telephone[i]);
            printf("L age : %d\n",Age[i]);
            printf("Le statut : %s\n",Statut[i]);
            printf("La date de reservation : %s\n",Date[i]);
            printf("La reference du client  : %d\n",Reference[i]);
            trouv = 1;
            break;
        }
    }
      if(trouv ==0){
        printf("Reservation non trouver \n");
   }
         break;
    }

    case 2:{
      printf("veuillez entrer la reference du client ");
      scanf("%d",&refer);
       trouv =0;
      for(i=0;i<Nombr;i++){
        if(Reference[i] == refer){
            printf("Le nom : %s\n",Nom[i]);
            printf("Le prenom : %s\n",Prenom[i]);
            printf("Le telephone : %s\n",Telephone[i]);
            printf("L age : %d\n",Age[i]);
            printf("Le statut : %s\n",Statut[i]);
            printf("La date de reservation : %d\n",Date[i]);
            trouv = 1;
            break;
        }
      }
      if (trouv ==0){
      printf("Resrvation non trouver");
      }
      break;
    }
    default:printf("choix invalide \n");
    break;
}
}

void Moyenne_age(){
    int somme,i,moyenne;
    somme = 0;
    for(i=0;i<Nombr;i++){
        somme = somme + Age[i];
    }
    moyenne = somme/Nombr;
    printf("La moyenne d age est :%d ans \n",moyenne);

}

void Nombr_patients_par_tranche(){
    int i;
    int categorie1 =0;
    int categorie2 =0;
    int categorie3 =0;
    for(i=0;i<Nombr;i++){
        if(Age[i]<=18){
            categorie1++;
        }
        else if(Age[i]<=35){
            categorie2++;
        }
        else{
            categorie3++;
        }
    }
    printf(" %d est le nombre des patients entre (0-18 ans)\n", categorie1);
    printf("%d est le nombre des patients entre (19-35 ans)\n", categorie2);
    printf("%d est le nombre des patients entre (36 ans et plus)\n", categorie3);

}

void Nombre_total_des_reservation(){
    int i;
    int valide =0;
    int reporte =0;
    int annule =0;
    int traite =0;
    for(i=0;i<Nombr;i++){
        if(strcmp(Statut[i],"valide")==0){
            valide++;
        }
        else if((strcmp(Statut[i],"reporte")==0)){
            reporte++;
        }
        else if((strcmp(Statut[i],"annule")==0)){
            annule++;
        }
        else if((strcmp(Statut[i],"traite")==0)){
            traite++;
        }
    }
    printf("%d est le nombre des reservations validees \n",valide);
    printf("%d est le nombre des reservations reportees \n",reporte);
    printf("%d est le nombre des reservations annulees \n",annule);
    printf("%d est le nombre des reservations traitees \n",traite);
}

void tri_des_reservation(){
    int choisir,h;
    char z[30];
    printf(" 1 Tri les reservations par nom \n");
    printf(" 2 Tri les reservations par statut \n");
    printf(" Entrer votre choix ");
    scanf("%d",&choisir);
    switch(choisir){
    case 1:

        for(h=0;h<Nombr-1;h++){
            for(int j=0;j<Nombr-h-1;j++){
                if(strcmp(Nom[j],Nom[j+1])>0){
                strcpy(z,Nom[j]);
                strcpy(Nom[j],Nom[j+1]);
                strcpy(Nom[j+1],z);

                strcpy(z,Prenom[j]);
                strcpy(Prenom[j],Prenom[j+1]);
                strcpy(Prenom[j+1],z);

                strcpy(z,Telephone[j]);
                strcpy(Telephone[j],Telephone[j+1]);
                strcpy(Telephone[j+1],z);

               int tem_age = Age[j];
                Age[j]= Age[j+1];
                Age[j+1]= tem_age;

                strcpy(z,Statut[j]);
                strcpy(Statut[j],Statut[j+1]);
                strcpy(Statut[j+1],z);

                strcpy(z,Date[j]);
                strcpy(Date[j],Date[j+1]);
                strcpy(Date[j+1],z);

                int tem_ref = Reference[j];
                Reference[j]= Reference[j+1];
                Reference[j+1]= tem_ref;

                }
            }
        }
        break;
    case 2:

         for(h=0;h<Nombr-1;h++){
            for(int j=0;j<Nombr-h-1;j++){
                if(strcmp(Statut[j],Statut[j+1])>0){
                   strcpy(z,Statut[j]);
                    strcpy(Statut[j],Statut[j+1]);
                    strcpy(Statut[j+1],z);

                strcpy(z,Nom[j]);
                strcpy(Nom[j],Nom[j+1]);
                strcpy(Nom[j+1],z);

                strcpy(z,Prenom[j]);
                strcpy(Prenom[j],Prenom[j+1]);
                strcpy(Prenom[j+1],z);

                strcpy(z,Telephone[j]);
                strcpy(Telephone[j],Telephone[j+1]);
                strcpy(Telephone[j+1],z);

                int tem_age = Age[j];
                Age[j]= Age[j+1];
                Age[j+1]= tem_age;

                strcpy(z, Date[j]);
                strcpy(Date[j], Date[j + 1]);
                strcpy(Date[j + 1], z);


                int tem_ref = Reference[j];
                Reference[j]= Reference[j+1];
                Reference[j+1]= tem_ref;
                }
           }
        }
        break;
        default:printf("choix invalide \n");
        break;
    }
    Afficher_patients();
}


int main(){
    Afficher_patients();
    do{
    printf("Programme de gerer les reservations de rendez-vous dentaires \n");
    printf(" 1 Ajouter une reservation \n");
    printf(" 2 Modifier ou supprimer une reservation \n");
    printf(" 3 Afficher les details d une reservation \n");
    printf(" 4 Tri des reservations \n");
    printf(" 5 Recherche des reservations \n");
    printf(" 6 Des statistiques \n");
    printf(" 7 Quiter le programme \n");
    printf("Veuillez entrer votre choix ");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            Ajouter_une_reserv();
            break;
        case 2:
            Modifier_ou_supprimer();
            break;
        case 3:
            Afficher_les_details();
            break;
        case 4:
            tri_des_reservation();
            break;
        case 5:
            Recherche_des_reservations();
            break;
        case 6:
            Moyenne_age();
            Nombr_patients_par_tranche();
            Nombre_total_des_reservation();
            break;
        case 7:
            printf("Au revoir \n");
            break;
        default:printf("Numero invalide");
        break;
    }


    }while(choix>=1 && choix<=7);



return 0;

}
