#include<iostream>
   size_t LongueurChaine(const char* chaine);
   void CopierChaine(char* destination , const  char* source);
   void ConcatenerChaines(char* destination, const char* source);
   char* TrouverCaractere(const char* chaine,char caractere);
   size_t CompterOccurrences(const char* chaine , char caractere);
   void CopierMemoire(void* destination, const void* source, size_t taille);
   void InitialiserMemoire(void* zone, unsigned char valeur,size_t taille);
   void ExtraireSousChaine(char* destination, const char* source, size_t debut, size_t longueur);
   size_t DiviserChaine(const char*chaine , char separateur, char resultat[][100], size_t max_resultats);
   int ComparerChaines(const char* chaine1, const char* chaines2);
   void ConvertirMinuscules(char* chaine);
   bool EstChaineNumerique(const char* chaine);

 int main(){
  std::cout<<"===TEST DE MANIPULATION DE CHAINES STYLE C ==="<<std::endl;
  //Test 1: longueur de chaine
  char message[] = "Bonjour le monde";
  std::cout<<"1. Longueur de"<<message<<"\nest:" <<LongueurChaine(message)<<std::endl;
  //Test 2: copie de chaine 
     char copie[50];
   CopierChaine(copie, message);
   std::cout<<"2. Copie:"<< copie <<"'"<<std::endl;
   // Test 3: Concaténation
    char salutation[100] = "Hello ";
    ConcatenerChaines(salutation, "World!");
    std::cout << "3. Concaténation: '" << salutation << "'" << std::endl;
  // Test 4: Recherche de caractère
    char* position = TrouverCaractere(message, 'j');
    if (position != nullptr) {
        std::cout << "4. Caractère 'j' trouvé à la position: " << (position - message) << std::endl;
    } else {
        std::cout << "4. Caractère 'j' non trouvé" << std::endl;
    }
    
    // Test 5: Comptage d'occurrences
    std::cout << "5. Occurrences de 'o' dans '" << message << "': " 
              << CompterOccurrences(message, 'o') << std::endl;
    
    // Test 6: Extraction de sous-chaîne
    char sous_chaine[20];
    ExtraireSousChaine(sous_chaine, message, 3, 5);
    std::cout << "6. Sous-chaîne (pos 3, longueur 5): '" << sous_chaine << "'" << std::endl;
    
    // Test 7: Division de chaîne
    char phrase[] = "pomme,orange,banane,kiwi";
    char fruits[10][100];
    size_t nb_fruits = DiviserChaine(phrase, ',', fruits, 10);
    
    std::cout << "7. Division de '" << phrase << "':" << std::endl;
    for (size_t i = 0; i < nb_fruits; i++) {
        std::cout << "   [" << i << "] " << fruits[i] << std::endl;
    }
    
    // Test 8: Fonctions mémoire
    char zone1[10] = "ABCDEFGHI";
    char zone2[10];
    CopierMemoire(zone2, zone1, 5);
    zone2[5] = '\0';
    std::cout << "8. Copie mémoire (5 octets): '" << zone2 << "'" << std::endl;
    
    char zone3[10];
    InitialiserMemoire(zone3, 'X', 5);
    zone3[5] = '\0';
    std::cout << "9. Initialisation mémoire: '" << zone3 << "'" << std::endl;
    
    // Test 10: Comparaison de chaînes
    char chaineA[] = "apple";
    char chaineB[] = "banana";
    int resultat_comparaison = ComparerChaines(chaineA, chaineB);
    std::cout << "10. Comparaison '" << chaineA << "' vs '" << chaineB << "': " 
              << resultat_comparaison << std::endl;
    
    // Test 11: Conversion minuscules
    char mixte[] = "Hello World!";
    std::cout << "11. Avant conversion: '" << mixte << "'" << std::endl;
    ConvertirMinuscules(mixte);
    std::cout << "    Après conversion: '" << mixte << "'" << std::endl;
    
    // Test 12: Vérification numérique
    char numerique[] = "12345";
    char non_numerique[] = "12a45";
    std::cout << "12. '" << numerique << "' est numérique: " 
              << (EstChaineNumerique(numerique) ? "OUI" : "NON") << std::endl;
    std::cout << "    '" << non_numerique << "' est numérique: " 
              << (EstChaineNumerique(non_numerique) ? "OUI" : "NON") << std::endl<<std::endl<<std::endl;
    
    return 0;
  }
 size_t LongueurChaine(const char* chaine)
 {
  const char* debut = chaine;
  while (*chaine !=0)
  {
    std::cout<<*chaine;
    chaine++;
  }
  return chaine-debut;
  
 }
  /* IMPLEMENTAION DE LA FONCTION CopierChaine qui permet de copier une chaine de caratere vers une 
  destination pour illustrer cela prenons  const char* source[] =" bonjour"; cette fonction permettra de copier 
  "bonjour" dans une destination quelconque*/
void CopierChaine(char* destination , const  char* source){
    
    while (*source !='\0')
    {
      *destination = *source;
      destination ++;
      source ++;
    *destination +='\0';
    }
    
}
    /* IMPLEMENTAION DE LA FONCTION ConcatenerChaine qui est une fonction permetant de coller deux chaines de caratere
    par exemple ConcatenerChaine("bonjour" , "le monde"); on obtiendra  a la fin "bonjour le monde"*/
void ConcatenerChaines(char* destination, const char* source){
  do{

   if (*destination =='\0'){
    while(*source =='\0')
      *destination = *source;
    }  destination ++;
     } while(*destination !='\0');
  
}
   /* IMPLEMENTAION DE LA FONCTION TrouverCaratere qui permet de trouver un caractere rechercher
    dans une chaine de caractere et de retourner ca position 
    Exemple: soit const char* chaine[] = "matin"; si m'on recherche la lettre i cette fonction 
    vas le faire et retourner 3 qui est sa position*/
char* TrouverCaractere(const char* chaine,char caractere)
{  
    
     while(caractere=='\0'){
      if(*chaine ==caractere){
        return (char*)chaine;
      }else 
        return nullptr;
     
      } return 0;
     }
     

   /* IMPLEMENTAION DE LA FONCTION CompterOccurrences est une fonction qui compte le nombre de fois 
   qu'apparait un meme caractere dans une chaine de caractere
   Exemple : const char* message[]= "hello" si l'on desire trouver le nombre d'occurrence de la lettre 'l' 
   il suffit d'appeler cette fonction qui vas nous retourner son nombre d'occurrence */
size_t CompterOccurrences(const char* chaine , char caractere){
    int i;
    int n=0;
    while(caractere !='\0'){
      std::cout<<*chaine;
      i++;
    }
    if(*chaine == caractere){
        n++;
      
    }
    return n;
}
    /* IMPLEMENTAION DE LA FONCTION CopierMemoire est une fonction qui permet de copier la memoire d'une 
    chaine de caractere vers une destination definie tout en verifiant si la taille est correcte
    Exemple: CopierMemoire(message, dest); vas copier la memoire de message dans dest */
void CopierMemoire(void* destination, const void* source, size_t taille){
    unsigned char* desti= static_cast<unsigned char*>(destination);
    unsigned  const char* SRC = static_cast<unsigned const char *> (source);
    for(int i=0; i<=taille-1; i++){
      desti[i]= SRC[i];
     }  desti++;
        SRC++;
    
}
    /* IMPLEMENTAION DE LA FONCTION InitialiserMemoire est une fonction qui permet d'attribuer 
    une valeur initiale a la memoire d'une chaine de caractere*/
void InitialiserMemoire(void* zone, unsigned char valeur,size_t taille){
  unsigned char* zn = static_cast<unsigned char*>(zone);
  for(int i=0; i<=taille-1; i++){
    std::cout<<"la valeur de l'octet est:"<<valeur<<std::endl;
   taille++;
  }
}  
  /* IMPLEMENTAION DE LA FONCTION ExtraireSousChaine est une fonction qui permet de prendre une partie 
  d'une chaine de caractere et la stocke dans une destination
  Exemple ExtraireSousChaine(dest,message,'14','12'); elle vas copier une partie de message dans dest 
  si la taille depasse elle vas couper la chaine */
void ExtraireSousChaine(char* destination, const char* source, size_t debut, size_t longueur){
    for(int i=0.; i<longueur-1;i++){
      do{
      debut= *destination;
      debut = (debut - longueur-1);
      }while(*source =='\0');
      *destination +='\0';

    }
    
}  
    /* IMPLEMENTAION DE LA FONCTION DiviserChaine qui permet de 
      diviser une chaine de caractere en sous chaine qui peut etre utiliser 
      pour classer les element d'une chaine de caractere dans un tableau*/
size_t DiviserChaine(const char* chaine , char separateur, char resultat[][100], size_t max_resultats){
    
    char caractere;
    int compteur_resultats = 0;
    int index_courant = 0;
    do{
      if(caractere==separateur || caractere=='\0'){
       CopierChaine(resultat[compteur_resultats] , chaine);
        compteur_resultats ++;
        index_courant=0;
     }
    }while(*chaine =='\0');
     return compteur_resultats;
}
     /* IMPLEMENTAION DE LA FONCTION ComparerChaine qui permet de verifier si deux
     chaine de caractere sont egales ou differentes*/
int ComparerChaines(const char* chaine1, const char* chaine2){
    
      while(*chaine1 !='\0' && *chaine2 !='\0'){
        do{
          if(*chaine1 == *chaine2){
            return 0; 
          }else if(*chaine1 > *chaine2){
            return 1 ;
          } else if(*chaine1 != *chaine2){
            return (*chaine1 - *chaine2);
          }
        } while(*chaine1=='\0' && *chaine2=='\0');     
      }
      return 0;
}

    /* IMPLEMENTATION DE LA FONCTION ConvertirMinuscule qui est une fonction
     permettant de convertir une chaine de caractere en minuscule */
    
 void ConvertirMinuscules(char* chaine){
    do{

       if(('A'< *chaine)&& (*chaine < 'Z')){
        *chaine +=32;
       }
     }  while(*chaine !=0);
      
 } 
    /* IMPLEMENTATION DE LA FONCTION EstChaineNumerique qui est une fonction qui permet de verifier
    si un chaine de caractere est un nombre
    */
    bool EstChaineNumerique(const char* chaine){
    
     if(*chaine  =='-'){
       chaine++;
     }
      do{
      if(*chaine <0 || *chaine > 9){
        return false;
      }else 
      return true;
    }while( *chaine != '\0');
  }