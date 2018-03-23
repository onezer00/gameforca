#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

using namespace std;

const int quant_palavras = 20;

char banco[quant_palavras][30]={
"CACHORRO",
"COMPUTADOR",
"CADEIRA",
"AUTOMOVEL",
"EDIFICIO",
"SMARTPHONE",
"PARALELEPIPEDO",
"ELASTICO",
"TRABALHO",
"GANGORRA",
"MARRETA",
"CAVANHAQUE",
"BIGODE",
"ESCADARIA",
"ZOOLOGICO",
"LOMBADA",
"MERCURIO",
"ESTANTE",
"GAVETEIRO",
"SAPATO"};

char palavra_sort[30];
char palavra_dig[30];



int Sorteia(){
    srand(time(NULL));
    return rand() % (quant_palavras);
}

void logo(){
cout << " ___________                              " << endl;
cout << " \\_   _____/__________   ____ _____       " << endl;
cout << "  |    __)/  _ \\_  __ \\_/ ___\\\\__  \\      " << endl;
cout << "  |     \\(  <_> )  | \\/\\  \\___ / __ \\_    " << endl;
cout << "  \\___  / \\____/|__|    \\___  >____  /    " << endl;
cout << "      \\/                    \\/     \\/     " << endl;

}

void imprime_palavra_dig(){
    cout<<"\n     "<<strlen(palavra_sort)<<" LETRAS \n\n    ";
    for(int i=0;i < strlen(palavra_sort) ;i++){
        cout<<palavra_dig[i]<<" ";
    }
}

void copia(int ind){
    for(int i=0;i<30;i++){
        palavra_sort[i] = banco[ind][i];
    }
}

void limpa_palavra_dig(){

    for(int i=0;i < strlen(palavra_sort);i++){
        palavra_dig[i] = '_';
    }
}

void imprime_forca(int let_erro){
    switch(let_erro){
         case 0:
            logo();
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###  _____                                      ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"###                                             ###"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            break;
        case 1:
            logo();
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###  _____                                      ###"<<endl;
            cout<<"### |    O                                      ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            break;
        case 2:
            logo();
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###  _____                                      ###"<<endl;
            cout<<"### |    O                                      ###"<<endl;
            cout<<"### |    |                                      ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            break;
        case 3:
            logo();
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###  _____                                      ###"<<endl;
            cout<<"### |    O                                      ###"<<endl;
            cout<<"### |   /|                                      ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            break;
        case 4:
            logo();
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###  _____                                      ###"<<endl;
            cout<<"### |    O                                      ###"<<endl;
            cout<<"### |   /|\\                                    ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            break;
        case 5:
            logo();
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###  _____                                      ###"<<endl;
            cout<<"### |    O                                      ###"<<endl;
            cout<<"### |   /|\\                                    ###"<<endl;
            cout<<"### |   /                                       ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            break;
        case 6:
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###  _____                                      ###"<<endl;
            cout<<"### |    O                                      ###"<<endl;
            cout<<"### |   /|\\                                    ###"<<endl;
            cout<<"### |   / \\                                    ###"<<endl;
            cout<<"### |                                           ###"<<endl;
            cout<<"###################################################"<<endl;
            cout<<"###################################################"<<endl;
            break;
    }
}

bool verifica_letra(char letra, char vetor[26]){
    for(int i=0;i<strlen(vetor);i++){
        if(letra==vetor[i]){
            return true;
        }
    }
    return false;
}

void substitui(char letra){
    for(int i=0;i<strlen(palavra_sort);i++){
        if(palavra_sort[i]==letra){
            palavra_dig[i] = letra;
        }
    }

}

void imprime_let_dig(char letras[], int tam){

    cout<<"\n\n Letras digitadas: ";
    for(int i=0;i < tam ;i++){
        cout<<letras[i]<<", ";
    }
    cout<<"\n";
    cout<<"___________________________________________________"<<endl;
}

bool palavra_completa(){
    for(int i=0;i<strlen(palavra_sort);i++){
        if(palavra_dig[i]=='_'){
            return false;
        }
    }
    return true;
}

int main(){

    int ind_palavra = Sorteia(); //Sortear uma palavra

    copia(ind_palavra);

    limpa_palavra_dig(); // Função responsável por limpar o vetor da palavra digitada

    int cont_let_dig=0;      // contador de letras digitadas

    int cont_erros=0;

    char letras_digitadas[26];

    char letra;

    while(cont_erros<6){
        system("clear");
        imprime_forca(cont_erros);
        imprime_palavra_dig();
        imprime_let_dig(letras_digitadas,cont_let_dig);
        cout<<"\n\n Tentativas restantes: "<<6-cont_erros<<"\n\n";
        cout<<"\n\n";
        cout<<"Digite uma letra: ";
        cin>>letra;
        letra = toupper(letra);

        if(verifica_letra(letra,letras_digitadas)){
            cout<<"Letra ja foi digitada! Tente novamente!\n\n";
            system("pause");
        }else{
            letras_digitadas[cont_let_dig] = letra;
            cont_let_dig++;

            if(verifica_letra(letra,palavra_sort)){
                substitui(letra);
            }else{
                cout<<"\nLetra incorreta! Tente novamente\n\n";
                cont_erros++;
                system("pause");

            }
        }


        if(cont_erros>=6){
            system("clear");
            cout<<"\n\n\tSuas tentativas acabaram!\n Reinicie o software para tentar novamente!\n";
            system("pause");
            return 0;
        }
        if(palavra_completa()){
            cout<<"\n\tPARABENS!!!\n Voce acertou a palavra!\n\n";
            system("pause");
            return 0;
        }

    }

    return 0;
}
