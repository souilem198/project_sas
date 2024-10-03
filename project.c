#include<stdio.h>
#include<string.h>


char Nom[100][30];
char Prenom[100][30];
char Telephone[100][20];
int Age[100];
char Statut[100][30];
int Reference[100];
char Date[100][30];
int Nombr = 0;
int choix;

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
        case 1:strcpy(Statut[Nombr],"Valide");
        break;
        case 2:strcpy(Statut[Nombr],"Reporte");
        break;
        case 3:strcpy(Statut[Nombr],"Annule");
        break;
        case 4:strcpy(Statut[Nombr],"Traite");
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

void Modifier_ou_supprimer(){
    int refer,i,ch_oix,nouv_age,choi;
    char nouv_nom[30],nouv_prenom[30],nouv_tele[30],nouv_statut[30];
    printf("veuillez entrer la reference du client ");
    scanf("%d",&refer);
    printf(" 1 Modifier \n");
    printf(" 2 Supprimer \n");
    printf("entrer votre choix ");
    scanf("%d",&ch_oix);
    switch(ch_oix){
    case 1:
        for(i=0;i<Nombr;i++){
        if(Reference[i]==refer){
            printf(" 1 Le nom %s\n",Nom[i]);
            printf(" 2 Le prenom %s\n",Prenom[i]);
            printf(" 3 Le telephone %s\n",Telephone[i]);
            printf(" 4 L age %d\n",Age[i]);
            printf(" 5 Le statut %s\n",Statut[i]);
        }
        printf("Entrer votre choix ");
        scanf("%d",&choi);
        switch(choi){
        case 1:
            printf("Entrer le nouveau nom \n");
            scanf("%s",nouv_nom);
             strcpy(Nom[i],nouv_nom);
             break;
        case 2:
            printf("Entrer le nouveau prenom \n");
            scanf("%s",nouv_prenom);
            strcpy(Prenom[i],nouv_prenom);
            break;
        case 3:
            printf("Entrer le nouveau telephone \n");
            scanf("%s",nouv_tele);
            strcpy(Telephone[i],nouv_tele);
            break;
        case 4:
            printf("Entrer le nouveau age \n");
            scanf("%d",&nouv_age);
            Age[i]=nouv_age;
            break;
        case 5:
            printf("Entrer le nouveau statut \n");
            scanf("%s",nouv_statut);
            strcpy(Statut[i],nouv_statut);
            break;
        default:printf("Reservation non trouver \n");
            break;
        }
    }

    case 2:
        for(i=0;i<Nombr;i++){
         if(Reference[i]==refer){
           for(int j=i;j<Nombr-1;j++){
            strcpy(Nom[j],Nom[j+1]);
            strcpy(Prenom[j],Prenom[j+1]);
            strcpy(Telephone[j],Telephone[j+1]);
            Age[j]=Age[j+1];
            strcpy(Statut[j],Statut[j+1]);
            Reference[j]=Reference[j+1];
        }
        Nombr--;
        printf("La reservation a ete supprimer \n");
        break;
    }
  }
     printf("reservation non trouvee \n");
     break;
     default:
         printf("choix invalide \n");
         break;
    }
}

void Afficher_les_details(){
    int refer,i;
    printf("veuillez entrer la reference du client ");
    scanf("%d",&refer);
     for(i=0;i<Nombr;i++){
        if(Reference[i]==refer){
            printf("Le nom : %s\n",Nom[i]);
            printf("Le prenom : %s\n",Prenom[i]);
            printf("Le telephone : %s\n",Telephone[i]);
            printf("L age : %d\n",Age[i]);
            printf("Le statut : %s\n",Statut[i]);
            printf("La date de reservation : %s\n",Date[i]);
            break;
        }
   }
   printf("Resrvation non trouver \n");
}

void Recherche_des_reservations(){
    char rech_nom[30];
    int i,c_hoix,refer;
    printf(" 1 Recherche par nom \n");
    printf(" 2 Recherche par refernce \n");
    printf(" Entrer votre choix \n");
    scanf("%d",&c_hoix);
    switch(c_hoix){
    case 1:
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
            break;
        }
    }
    case 2:
      printf("veuillez entrer la reference du client ");
      scanf("%s",refer);
      for(i=0;i<Nombr;i++){
        if(strcmp(refer,Reference[i])==0){
            printf("Le nom : %s\n",Nom[i]);
            printf("Le prenom : %s\n",Prenom[i]);
            printf("Le telephone : %s\n",Telephone[i]);
            printf("L age : %d\n",Age[i]);
            printf("Le statut : %s\n",Statut[i]);
            printf("La date de reservation : %s\n",Date[i]);
            break;
        }
      }
      default:printf("Resrvation non trouver");
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
    printf("La moyenne d age est :%d ans",moyenne);
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
    printf("%d est le nombre d age des patients entre ( 0-18ans)",categorie1);
    printf("%d est le nombre d age des patients entre ( 19-35)",categorie2);
    printf("%d est le nombre d age des patients entre ( 36+ans)",categorie3);
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
    int choisir,i;
    char Nom_tri[30];
    printf(" 1 Tri les reservations par nom \n");
    printf(" 2 Tri les reservations par statut \n");
    printf(" Entrer votre choix ");
    scanf("%d",&choisir);
    switch(choisir){
    case 1:
        printf("Entrer le nom ");
        scanf("%s",Nom_tri);
        do {
              int  test = 0;
        for(int i=0;i<Nombr-1;i++){
            for(int j=0;j<Nombr-i-1;j++){
                if(strcmp(Nom[j],Nom[j+1])<0){
                    int z = Nom[j];
                    Nom[j]=Nom[j-1];
                    Nom[j-1]=z;
                }
                    test =1;
            }
        }

    }while(test = 1 && i<Nom);
    }

}




int main(){
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
        case 5:
            Recherche_des_reservations();
            break;
        case 6:
            Moyenne_age();
            Nombr_patients_par_tranche();
            Nombre_total_des_reservation();
            break;
        case 7:
            printf("Au revoir ");
            break;
        default:printf("Numero invalide");
        break;
    }


    }while(choix>=1 && choix<=7);



return 0;

}
