#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10

struct List
{
   int elemento[MAX_SIZE];
   int tamanho;
};

struct No
{
   int id;
   struct List lista;
   struct No *proximo;
};

typedef struct No No;

void insere(struct List **l, int valor, int chave)
{
   // verificar se a lista está vazia
   if ((*l)->tamanho >= MAX_SIZE)
   {
      printf("\nA lista esta cheia!");
      return;
   }
   if (chave < 0 || chave > (*l)->tamanho)
   {
      printf("Chave invalida");
      return;
   }
   for (int i = (*l)->tamanho - 1; i >= chave; i--)
   {
      (*l)->elemento[i + 1] = (*l)->elemento[i];
   }
   (*l)->elemento[chave] = valor;
   (*l)->tamanho++;
};

void remover(struct List **l, int chave)
{

   if ((*l)->tamanho < 0)
   {
      printf("Lista vazia. Impossivel remover");
      return;
   }

   if (chave < 0 || chave >= (*l)->tamanho)
   {
      printf("Chave invalida");
      return;
   }

   for (int i = chave; i < (*l)->tamanho - 1; i++)
   {
      (*l)->elemento[i] = (*l)->elemento[i + 1];
   }
   (*l)->tamanho--;
}

void imprime(struct List **l)
{
   printf("\nChave: ");
   for (int i = 0; i < (*l)->tamanho; i++)
   {
      printf("%i \t", i);
   }
   printf("\nLista: ");
   for (int i = 0; i < (*l)->tamanho; i++)
   {
      printf("%d \t", (*l)->elemento[i]);
   }
}

void RemoverDuplicatas(struct List **l)
{
   for (int i = 0; i < (*l)->tamanho; i++)
   {
      for (int j = 0; j < (*l)->tamanho; j++)
      {
         if (j != i)
         {
            if ((*l)->elemento[i] == (*l)->elemento[j])
            {
               for (int m = j; m < (*l)->tamanho - 1; m++)
               {
                  (*l)->elemento[m] = (*l)->elemento[m + 1];
               }
               (*l)->tamanho--;
            }
         }
      }
   }
}

void encontrarMinEMax(struct List **l)
{
   if ((*l)->tamanho < 0)
   {
      printf("Lista vazia. Impossivel continuar");
      return;
   }

   int Min, Max;

   for (int i = 0; i < (*l)->tamanho; i++)
   {
      if (Min == NULL || Min > (*l)->elemento[i])
         Min = (*l)->elemento[i];
      if (Max == NULL || Max < (*l)->elemento[i])
         Max = (*l)->elemento[i];
   }

   printf("Minimo: %d \t", Min);
   printf("Maximo: %d \t", Max);
}

void inverterLista(struct List **l)
{
   int apoioA, apoioB, j = (*l)->tamanho - 1;

   if ((*l)->tamanho < 0)
   {
      printf("Lista vazia. Impossivel continuar");
      return;
   }

   for (int i = 0; i < (*l)->tamanho; i++)
   {
      if (j > i)
      {
         apoioA = (*l)->elemento[i];
         apoioB = (*l)->elemento[j];
         (*l)->elemento[j] = apoioA;
         (*l)->elemento[i] = apoioB;
         j--;
      }
   }

   printf("Lista invertida com sucesso!\n");
}

void editarLista(struct List *lista, int Id)
{
   int opcao, elemento, chave, flag = 1;

   do
   {
      system("cls");
      printf("Editando Lista de Id: %d\n\n", Id);
      printf("Escolha uma opcao:\n");
      printf("1 - Adicionar elemento\n");
      printf("2 - Remover elemento\n");
      printf("3 - Listar elementos\n");
      printf("4 - Encontrar Minimo e Maximo\n");
      printf("5 - Inverter Lista\n");
      printf("6 - Remover Duplicatas da Lista\n");
      printf("0 - Sair\n");
      scanf("%d", &opcao);

      switch (opcao)
      {
      case 1:
         system("cls");
         printf("1 - Adicionar chave de elemento\n");
         printf("2 - Adicionar elemento ao Final\n");
         printf("3 - Adicionar elemento ao Inicio\n");
         scanf("%d", &opcao);

         switch (opcao)
         {
         case 1:
            printf("Digite a chave: ");
            scanf("%d", &chave);
            printf("Digite o elemento a ser adicionado: ");
            scanf("%d", &elemento);
            insere(&lista, elemento, chave);
            break;
         case 2:
            printf("Digite o elemento a ser adicionado: ");
            scanf("%d", &elemento);
            insere(&lista, elemento, lista->tamanho);
            break;
         case 3:
            printf("Digite o elemento a ser adicionado: ");
            scanf("%d", &elemento);
            insere(&lista, elemento, 0);
            break;
         case 0:
            printf("voltando!\n");
            break;
         default:
            printf("Opção inválida!\n");
            break;
         }

         if (opcao == 1 || opcao == 2 || opcao == 3)
            printf("Elemento adicionado com sucesso!\n");

         system("pause");
         break;
      case 2:
         system("cls");
         printf("1 - Remover elemento por chave\n");
         printf("2 - Remover elemento ao Final\n");
         printf("3 - Remover elemento ao Inicio\n");
         scanf("%d", &opcao);

         switch (opcao)
         {
         case 1:
            printf("Digite a chave: ");
            scanf("%d", &chave);
            remover(&lista, chave);
            break;
         case 2:
            remover(&lista, lista->tamanho - 1);
            break;
         case 3:
            remover(&lista, 0);
            break;
         default:
            printf("Opção inválida!\n");
            break;
         }
         if (opcao == 1 || opcao == 2 || opcao == 3)
            printf("Elemento removido com sucesso!\n");

         system("pause");
         break;
      case 3:
         system("cls");
         imprime(&lista);
         system("pause");
         break;
      case 4:
         system("cls");
         encontrarMinEMax(&lista);
         system("pause");
         break;
      case 5:
         system("cls");
         inverterLista(&lista);
         system("pause");
         break;
      case 6:
         system("cls");
         RemoverDuplicatas(&lista);
         printf("Duplicatas removidas com sucesso!\n");
         system("pause");
         break;
      case 0:
         printf("Saindo...\n");
         flag = 0;
         system("pause");
         break;
      default:
         printf("Opção inválida!\n");
         break;
      }
   } while (flag != 0);
}

void adicionarNo(No **cabeca, int id)
{
   if (id == 0)
   {
      printf("Impossivel criar Elemento de ID 0");
      return;
   }

   No *novoNo = (No *)malloc(sizeof(No));
   novoNo->id = id;
   novoNo->lista.tamanho = 0;

   if (*cabeca == NULL)
   {
      *cabeca = novoNo;
   }
   else
   {
      No *atual = *cabeca;
      while (atual->proximo != *cabeca)
      {
         atual = atual->proximo;
      }
      atual->proximo = novoNo;
   }
   novoNo->proximo = *cabeca;
}

void removerNo(No **cabeca, int id)
{
   if (*cabeca == NULL)
   {
      printf("A lista está vazia!\n");
      return;
   }
   No *atual = *cabeca;
   No *anterior = NULL;

   do
   {
      if (atual->id == id)
      {
         if (anterior == NULL)
         {
            *cabeca = atual->proximo;
         }
         else
         {
            anterior->proximo = atual->proximo;
         }
         free(atual);
         printf("Elemento removido com sucesso!\n");
         return;
      }
      anterior = atual;
      atual = atual->proximo;
   } while (atual != *cabeca);

   printf("Elemento não encontrado na lista!\n");
}

void selecionarListaElementos(No **cabeca)
{
   int id, i = 1;
   if (cabeca == NULL)
   {
      printf("A lista está vazia!\n");
      return;
   }
   No *atual = *cabeca;
   printf("\n0 para sair");
   printf("         ID");
   do
   {
      printf("\nLista %d: %d ", i, atual->id);
      atual = atual->proximo;
      i++;
   } while (atual != *cabeca);
   printf("\n");

   printf("\nDigite o ID da lista para selecionar: ");
   scanf("%d", &id);

   if (id == 0)
      return;

   atual = *cabeca;

   do
   {
      if (atual->id == id)
      {
         editarLista(&(atual->lista), atual->id);
      }
      atual = atual->proximo;
   } while (atual != *cabeca);

   printf("\n");
}

void dividirListaAoMeio(No **cabeca, int id)
{
   No *atual = *cabeca;
   do
   {
      if (atual->id == id)
      {
         for (int m = 0; m < atual->lista.tamanho + 1 / 2; m++)
         {
            No *atualsecundario = *cabeca;
            do
            {
               printf("\n3");
               if (atualsecundario->id == id + 99)
               {
                  for (int i = atualsecundario->lista.tamanho - 1; i >= 0; i--)
                  {
                     atualsecundario->lista.elemento[i + 1] = atualsecundario->lista.elemento[i];
                  }
                  atualsecundario->lista.elemento[0] = atual->lista.elemento[atual->lista.tamanho - 1];
                  atualsecundario->lista.tamanho++;
                  atual->lista.tamanho--;
               }
               atualsecundario = atualsecundario->proximo;
            } while (atualsecundario != *cabeca);
         }
      }
      atual = atual->proximo;
   } while (atual != *cabeca);
}

int concatenarListaMesmoTamanho(No **cabeca)
{
   int id1, id2, i = 1;
   if (cabeca == NULL)
   {
      printf("A lista está vazia!\n");
      return 0;
   }
   No *atual = *cabeca;
   printf("\n[<- 0 para sair]\n");
   printf("         ID");
   do
   {
      printf("\nLista %d: %d ", i, atual->id);
      atual = atual->proximo;
      i++;
   } while (atual != *cabeca);
   printf("\n");

   printf("\nDigite o ID da lista 1 (Destino): ");
   scanf("%d", &id1);

   if (id1 == 0)
      return 0;

   printf("\nDigite o ID da lista 2: ");
   scanf("%d", &id2);

   if (id2 == 0)
      return 0;

   atual = *cabeca;
   int tamanho1;
   struct List lista2;
   do
   {

      if (atual->id == id1 || atual->id == id2)
         printf("\nTamanho lista de ID %d: %d", atual->id, atual->lista.tamanho);

      if (atual->id == id1)
         tamanho1 = atual->lista.tamanho;

      if (atual->id == id2)
      {
         lista2 = atual->lista;
      }

      atual = atual->proximo;
   } while (atual != *cabeca);

   if (tamanho1 == 0 || lista2.tamanho == 0)
   {
      printf("\nUma ou mais listas pode estar vazia!");
      return 0;
   }

   if (tamanho1 != lista2.tamanho)
   {
      printf("\nO Tamanho das listas não são iguais");
      return 0;
   }

   if (tamanho1 == lista2.tamanho)
   {
      atual = *cabeca;
      do
      {
         if (atual->id == id1)
         {
            for (int i = 0; i < atual->lista.tamanho; i++)
            {
               atual->lista.elemento[i] = atual->lista.elemento[i] * pow(10, (int)log10(lista2.elemento[i]) + 1) + lista2.elemento[i];
            }
         }
         atual = atual->proximo;
      } while (atual != *cabeca);

      printf("\nLista concatenada com sucesso!\n");

      return id2;
   }

   printf("\n");
}

int main()
{
   No *cabeca = NULL;
   int opcao, elemento;

   do
   {
      system("cls");
      printf("Escolha uma opção:\n");
      printf("1 - Escolher Lista\n");
      printf("2 - Criar Lista\n");
      printf("3 - Remover Lista\n");
      printf("4 - Concatenar Listas de mesmo tamanho\n");
      printf("5 - Dividir uma Lista ao meio\n");
      printf("0 - Sair\n");
      scanf("%d", &opcao);

      switch (opcao)
      {
      case 1:
         selecionarListaElementos(&cabeca);
         break;
      case 2:
         if (cabeca == NULL || cabeca->proximo == cabeca)
         {
            printf("Digite um ID para lista de 10 elementos: ");
            scanf("%d", &elemento);
            adicionarNo(&cabeca, elemento);
            printf("Lista de 10 elementos criada com sucesso!\n");
            system("pause");
         }
         else
         {
            printf("A lista já possui o máximo de elementos (5)!\n");
            system("pause");
         }
         break;
      case 3:
         if (cabeca == NULL)
         {
            printf("Não há listas!!\n");
         }
         else
         {
            printf("Digite o ID da lista a ser removida: ");
            scanf("%d", &elemento);
            removerNo(&cabeca, elemento);
         }
         system("pause");
         break;
      case 4:
         if (cabeca == NULL)
         {
            printf("Não há listas!\n");
         }
         else
         {
            int id2 = concatenarListaMesmoTamanho(&cabeca);
            removerNo(&cabeca, id2);
         }
         system("pause");
         break;
      case 5:
         if (cabeca == NULL)
         {
            printf("Não há listas!\n");
         }
         else
         {
            int i = 1, id;
            No *atual = cabeca;
            printf("\n[<- 0 para sair ]\n");
            printf("         ID");
            do
            {
               printf("\nLista %d: %d ", i, atual->id);
               atual = atual->proximo;
               i++;
            } while (atual != cabeca);
            printf("\n");

            printf("\nDigite o ID da lista para selecionar: ");
            scanf("%d", &id);

            adicionarNo(&cabeca, id + 99);
            dividirListaAoMeio(&cabeca, id);
         }
         system("pause");
         break;
      case 0:
         printf("Saindo...\n");
         break;
      default:
         printf("Opção inválida!\n");
         break;
      }
   } while (opcao != 0);

   return 0;
}