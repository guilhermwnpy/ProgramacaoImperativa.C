#include <stdio.h>
#include <stdlib.h>  //usado system
#include <ctype.h>   //usado toupper
#include <string.h>  //usado strcmp

//------------- STRUCT TpFarma -------------
struct TpFarma{
    char Nome[20];
    float Preco;
    int QEstoque; // se QEstoque >= 0 então pode ser exibido no programa | se QEstoque >= -1 então é considerado excluido
  };
  
typedef struct TpFarma TpFARMA; // struct TpFarma == TpFARMA
//------------- FIM STRUCT -------------

TpFARMA RgFarma; // [ struct TpFarma RgFarma; ] == [ TpFARMA RgFarma; ]
  
FILE *ArqFarma; // definindo o ponteiro de uso do Arquivo

long int Tamanho=20*sizeof(char)+sizeof(float)+sizeof(int); // definindo o tamanho da struct

//------------- INCLUIR ------------- 
void Incluir() {
  char R;
  do{
    printf("*** inclusao ***\n\n");
    printf("Nome: ");
    char nomeMedicamento[20];
    scanf("%s",nomeMedicamento);
    // Verifica se o medicamento já existe no arquivo
    fseek(ArqFarma,0,0);
    int encontrado = 0;
    while (fread(&RgFarma,Tamanho,1,ArqFarma) == 1) {
      if (strcmp(RgFarma.Nome, nomeMedicamento) == 0) {
        encontrado = 1;
        break;
      }
    }
    if (encontrado) {
      printf("Medicamento ja existe!\n");
    } else {
      strcpy(RgFarma.Nome, nomeMedicamento);
      printf("Preco: ");
      scanf("%f",&RgFarma.Preco);
      printf("Estoque: ");
      scanf("%d",&RgFarma.QEstoque);
      fseek(ArqFarma,0,2);
      fwrite(&RgFarma,Tamanho,1,ArqFarma);
      printf("\nNova inclusao? S/N ");
      scanf(" %c",&R);
      R=toupper(R);
    }
  } while (R!='N');}
//------------- FIM INCLUIR -------------

//------------- TAMANHO DO ARQUIVO -------------
long int TArquivo(){
    fseek(ArqFarma,0,2);
    long int R=ftell(ArqFarma)/Tamanho;
    return R;}
//------------- FIM TAMANHO DO ARQUIVO-------------

//------------- EXCLUIR -------------
void Excluir(){
  if (TArquivo()!=0){
    fclose(ArqFarma);
    ArqFarma=fopen("Farmacos.dat","r+b");
    printf("*** excluir ***\n\n");  
    fseek(ArqFarma,0,0);
    printf("Qual farmaco? ");
    char Farmaco[20];
    scanf("%s",Farmaco);
    int Achou=0;
    do {
      fread(&RgFarma,Tamanho,1,ArqFarma);
      if (strcmp(RgFarma.Nome,Farmaco)==0){
        Achou=1;
        RgFarma.QEstoque = -1;
        fseek(ArqFarma,-Tamanho,1);
        fwrite(&RgFarma,Tamanho,1,ArqFarma);
        printf(">>> Exclusao efetuada com sucesso! <<<\n");
        break;
      }
    } while (!feof(ArqFarma)&&(Achou==0));
    if (Achou==0) {
      printf("Registro inexistente!"); 
    }
    fclose(ArqFarma);
    ArqFarma=fopen("Farmacos.dat","a+b");
  } else {
    printf("Arquivo Vazio. Nao existem dados a excluir.");
  }
  return;
}

//------------- FIM EXCLUIR -------------


//------------- ALTERAR-------------
void Alterar(){
  if (TArquivo()!=0){
  fclose(ArqFarma);
  ArqFarma=fopen("Farmacos.dat","r+b");
  printf("*** alterar ***\n\n");  
  fseek(ArqFarma,0,0);
  printf("Qual farmaco? \n");
  char Farmaco[20];
  scanf("%s",Farmaco);
  int Achou=0;
  do {
    fread(&RgFarma,Tamanho,1,ArqFarma);
    if (strcmp(RgFarma.Nome,Farmaco)==0){
      Achou=1;  
      printf("----------------\n");
      printf("-- INFORMACOES ATUAIS --\n");
      printf("Nome: %s\n",RgFarma.Nome);
      printf("Valor: R$%.2f\n",RgFarma.Preco);
      printf("Estoque: %d\n",RgFarma.QEstoque);
      printf("----------------\n");}}
  while (!feof(ArqFarma)&&(Achou==0));
  if (Achou==0)
    printf("Registro inexistente!"); 
  else{
    printf("Qual o novo preco? \n"); 
    scanf("%f",&RgFarma.Preco);
    printf("Qual a nova quantidade? \n");
    scanf("%d",&RgFarma.QEstoque);
    fseek(ArqFarma,-Tamanho,1);
    fwrite(&RgFarma,Tamanho,1,ArqFarma);
    printf(">>> Alteracao efetuada com sucesso! <<<\n");
    printf("----------------\n");
    printf("-- INFORMACOES ALTERADAS --\n");
    printf("Nome: %s\n",RgFarma.Nome);
    printf("Valor: R$%.2f\n",RgFarma.Preco);
    printf("Estoque: %d\n",RgFarma.QEstoque);
    printf("----------------\n");}
  fclose(ArqFarma);
  ArqFarma=fopen("Farmacos.dat","a+b");}
  else{
    printf("Arquivo Vazio.  Nao existem dados a alterar.");}
  return;}
//------------- FIM ALTERAR -------------

//------------- COLSULTAR -------------
void Consultar(){
  printf("*** consulta ***\n\n");  
  fseek(ArqFarma,0,0);
  printf("Qual farmaco? ");
  char Farmaco[20];
  scanf("%s",Farmaco);
  int Achou=0;
  do{
      fread(&RgFarma,Tamanho,1,ArqFarma);
      if (strcmp(RgFarma.Nome,Farmaco)==0 && RgFarma.QEstoque != -1){
        Achou=1;    
        printf("Nome: %s\n",RgFarma.Nome);
        printf("Valor: R$%.2f\n",RgFarma.Preco);
        printf("Estoque: %d\n",RgFarma.QEstoque);
      }
    } while (!feof(ArqFarma)&&(Achou==0));
  if (Achou==0)
    printf("Registro inexistente!");  
  return;
}

//------------- FIM CONSULTAR -------------

//------------- LISTAR TODOS -------------
void LTodos(){
  printf("*** lista todos ***\n\n"); 
  fseek(ArqFarma,0,0);
  do {
    fread(&RgFarma,Tamanho,1,ArqFarma);
    if (!feof(ArqFarma)){
      if(RgFarma.QEstoque >= 0){
        printf("Nome: %s\n",RgFarma.Nome);
        printf("Valor: R$%.2f\n",RgFarma.Preco);
        printf("Estoque: %d\n",RgFarma.QEstoque);
        printf("***\n\n");
      }
    }
  } while (!feof(ArqFarma));
}

//------------- FIM LISTAR TODOS -------------

//------------- PRINCIPAL -------------
int main(){
  ArqFarma=fopen("Farmacos.dat","a+b");
  char Opcao;
  do{
    printf("\n\n> > > Pague Pouco < < < \n\n");
    printf("Que deseja fazer? \n\n");
    printf("I - Incluir \n");  
    printf("E - Excluir \n");
    printf("A - Alterar \n");
    printf("C - Consultar \n");
    printf("T - Listar Todos \n");
    printf("S - Sair \n\n");
    scanf(" %c", &Opcao);
    Opcao=toupper(Opcao);
    switch (Opcao){
      case 'I': Incluir(); break;
      case 'E': Excluir(); break;
      case 'A': Alterar(); break;
      case 'C': Consultar(); break;
      case 'T': LTodos(); break;}}
  while (Opcao != 'S');
  fclose(ArqFarma);
  return 0;}
//------------- FIM PRINCIPAL -------------

//------------- FIM CODIGO -------------
