//Alunos: Bernardo Nemitz Tomazoni, João Henrique Cavanha, João Paulo Tomazoni, Nickolas Campestrini Roeder e Rodrigo dos Santos

#include <iostream>
#include <cstdlib>
using namespace std;
int main(){

  srand(time(NULL));

  int respostamenu, num1, num2, num3, num4, nr1, nr2, nr3, nr4, cTentativas, resposta, tentativas, nCLC, nCLE, contador;

do{
      cout << " Digite:"<<endl<<" 1 para Jogar"<<endl<<" 2 para Ler Sobre"<<endl<<" 3 para Sair do jogo\n";
      cin >> respostamenu; 

    switch(respostamenu){
      case 1:
        nCLC=0, nCLE=0, contador=1, tentativas=1;

        while(contador==1){//serve para definir os códigos utilizados no jogo, eles são gerados aleatoriamente, sem se repetir;
          num1=rand()%6+1;
          num2=rand()%6+1;
          num3=rand()%6+1;  
          num4=rand()%6+1;
            if(num1!=0 && num1<7 && num2!=0 && num2<7 && num2!=num1 && num3!=0 && num3<7 && num3!=num2 && num3!=num1 && num4!=0 && num4<7 && num4!=num1 && num4!=num2 && num4!=num3){
               contador++;
            }
          } 
        cout<<"\033c";//serve para limpar o console;
        while(tentativas<=10){
          cout << "Adivinhe o código de 4 números distintos de 1 a 6:  ";
          cin>>resposta;

          nr4=resposta%10;//serve para separar os numeros que o jogador digitou em 4 variaveis;
          resposta/=10;
          nr3=resposta%10;
          resposta/=10; 
          nr2=resposta%10;
          resposta/=10;
          nr1=resposta%10;

            if(nr1<1 || nr1>6 || nr2<1 || nr2>6 || nr3<1 || nr3>6 ||nr4<1 || nr4>6||nr1==nr2||nr1==nr3||nr1==nr4||nr2==nr3||nr2==nr4||nr3==nr4||resposta>=10){
              cout<<"Resposta inválida, tente novamente\n";
            } else{
          if(num1==nr2||num1==nr3||num1==nr4){//Codigo para contabilizar os numeros que estão certos mas no lugar errado;
            nCLE++;
          }
          if(num2==nr1||num2==nr3||num2==nr4){
            nCLE++;
          }
          if(num3==nr1||num3==nr2||num3==nr4){
            nCLE++;
          }
          if(num4==nr1||num4==nr2||num4==nr3){
            nCLE++;
          }
          if(num1==nr1){//Codigo para contabilizar os numeros que estão certos no lugar correto;
            nCLC++;
          }
          if(num2==nr2){
            nCLC++;
          }
          if(num3==nr3){
            nCLC++;
          }
          if(num4==nr4){
            nCLC++;
          }
          if(num1==nr1 && num2==nr2 && num3==nr3 && num4==nr4){//Quebra o loop caso o jogador acerte o codigo;
            break;
          }
          cTentativas=10-tentativas;

          cout<<"\033c";
          cout<<"Última tentativa: "<<nr1<<nr2<<nr3<<nr4<<"\nNúmeros certos nas posições corretas: "<<nCLC<<endl<< "Números certos nas posições incorretas: "<<nCLE<<endl<< "Tentativas restantes: "<<cTentativas<<endl;

          nCLC=0;//Zera os valores das variaveis cada vez que o jogador errar e ter que digitar o codigo novamente;
          nCLE=0;

          tentativas ++;
              }
          cout<<endl;
        }
        if(num1==nr1 && num2==nr2 && num3==nr3 && num4==nr4){
          cout<<"\033c";
          cout<<"Você acertou o código em "<<tentativas<< " tentativas"<<endl;
        } else{
          cout<<"\033c";
          cout<<"Você perdeu, o código era: "<<num1<<num2<<num3<<num4<<endl;
        }
  cout<<"\nPressione enter para voltar ao menu";
  cin.ignore();
  cin.get();
  cout<<"\033c";
      break;    

      case 2:
        cout<<"\033c";
        cout<<"\nDesenvolvedores: \n" << "Bernardo Nemitz Tomazoni\n"<< "João Henrique Cavanha\n"<< "João Paulo Tomazoni Dos Santos\n"<< "Nickolas Campestrini Roeder\n" << "Rodrigo dos Santos\n" << endl << "\nProjeto desenvolvido em 05/2024\n"<<"Sob supervisão do professor Rafael Ballottin\n"<<"Matéria: Algoritmos e Programação I"<<endl;

        cout<<"\nPressione enter para voltar ao menu";
        cin.ignore();
        cin.get();
        cout<<"\033c";
      break;

      case 3:
        cout<<"\033c";
        cout<<"Você saiu do jogo, espero que tenha gostado";
      break;

      default: 
        cout<<"\033c";
        cout<<"Opção inválida, tente novamente"<<endl;
        cout<<"\nPressione enter para voltar ao menu"; 
        cin.ignore();
        cin.get();
        cout<<"\033c";
    }
  }while(respostamenu != 3);
}