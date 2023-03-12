#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

struct sCliente{
    int codigo;
    char nome[50];
    char telefone[50];
    char endereco[50];
};
typedef struct sCliente cliente;
cliente vetClientes[1];

struct sVeiculo{
    int codigo;
    char descricao[100];
    char cor[50];
    char modelo[50];
    char placa[10];
    int qtdPassageiros;
    float valorDiaria;
    char status[10];
};
typedef struct sVeiculo veiculo;
veiculo vetVeiculos[1];

void cadCliente(int i, int codigo, char nome[50], char telefone[50], char endereco[50], FILE *pClientes, cliente vetClientes[50]){
    char linhas[150];
    int qtdLinhas = 0;
    bool stop = false;

    pClientes = fopen("clientes.txt", "r+w");

    if(pClientes != NULL){
        while(!feof(pClientes)){
            fgets(linhas, 150, pClientes);
            qtdLinhas ++;
        }
    //strtok para pegar a string por completo
        char *aux = strtok(linhas, "");

        while(aux != NULL){
            if(codigo == atoi(aux) || codigo == aux){
                printf("Codigo inválido! Esse código já está em uso!");
                return;
            }

            aux = strtok(NULL, "");
            vetClientes[i].codigo = codigo;
            strcpy(vetClientes[i].nome, nome);
            strcpy(vetClientes[i].telefone, telefone);
            strcpy(vetClientes[i].endereco, endereco);
            fflush(stdin);

            fprintf(pClientes, "%d %s %s %s\n", vetClientes[i].codigo, vetClientes[i].nome, vetClientes[i].telefone, vetClientes[i].endereco);
            printf("Cadastro realizado com sucesso!");
            i++;
            fclose(pClientes);
            return;
        }
        fclose(pClientes);
    } else{
        printf("Arquivo não encontrado ou não existe");
    }
}

void cadVeiculo(int j, int codigo, char descricao[100], char cor[50], char modelo[50], char placa[10], int qtdPassageiros, float valorDiaria, char status[10], FILE *pVeiculo, veiculo vetVeiculos[50]){
    char linhas[2500];
    int qtdLinhas = 0;

    pVeiculo = fopen("veiculos.txt", "r+w");

    if(pVeiculo != NULL){
        while(!feof(pVeiculo)){
            fgets(linhas, 2500, pVeiculo);
            qtdLinhas ++;
        }

        char *aux = strtok(linhas, "");
        while(aux != NULL){
            if(codigo == atoi(aux) || codigo == aux){
                printf("Codigo inválido! Esse código já está em uso!");
                return;
            }

            aux = strtok(NULL,"");
            vetVeiculos[j].codigo = codigo;
            strcpy(vetVeiculos[j].descricao, descricao);
            strcpy(vetVeiculos[j].cor, cor);
            strcpy(vetVeiculos[j].modelo, modelo);
            strcpy(vetVeiculos[j].placa, placa);
            vetVeiculos[j].qtdPassageiros = qtdPassageiros;
            vetVeiculos[j].valorDiaria = valorDiaria;
            strcpy(vetVeiculos[j].status, status);

            fflush(stdin);

            fprintf(pVeiculo, "%d, %s, %s, %s, %s, %d, %5.2f, %s", vetVeiculos[j].codigo, vetVeiculos[j].descricao, vetVeiculos[j].cor, vetVeiculos[j].modelo, vetVeiculos[j].placa, vetVeiculos[j].qtdPassageiros, vetVeiculos[j].valorDiaria, vetVeiculos[j].status);
            printf("Cadastro realizado com sucesso!");
            j++;
            fclose(pVeiculo);
        }
    } else{
        printf("Arquivo não encontrado ou não existe");
    }


}

int main()
{
    setlocale(LC_ALL, "portuguese");

    FILE *pCliente;
    FILE *pVeiculo;
    int opcao;
    int i = 0, j = 0;
    int codigoCliente, codigoVeiculo, qtdPassageiros;
    char nomeCliente[50], telCliente[50], endCliente[50];
    char descrVeiculo[100], corVeiculo[50], modelVeiculo[50], placaVeiculo[10], statusVeiculo[10];
    float valorDiaria;

    while(opcao !=0 ){
        printf("\nEscolha a ação que deseja executar, conforme o menu abaixo\n\n");
        printf(" __________________ M E N U ________________\n");
        printf("|                                           |\n");
        printf("|        1 - Cadastro de Clientes           |\n");
        printf("|        2 - Cadastro de Veículos           |\n");
        printf("|        3 - Cadastro de Locação            |\n");
        printf("|        4 - Baixa em Locação               |\n");
        printf("|        5 - Cadastro de Clientes           |\n");
        printf("|        6 - Pesquisa de Clientes           |\n");
        printf("|        7 - Pesquisa de Veículos           |\n");
        printf("|        8 - Locação por Cliente            |\n");
        printf("|        9 - Programa de Fidelidade         |\n");
        printf("|       10 - Premiação de Fidelidade        |\n");
        printf("|       11 - ???                            |\n");
        printf("|        0 - SAIR                           |\n");
        printf("|___________________________________________|\n");
        printf("\nOpção escolhida: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("\nInforme o codigo do cliente: ");
                scanf("%d", &codigoCliente);
                printf("Informe o nome do cliente: ");
                scanf("%s", &nomeCliente);
                printf("Informe o telefone do cliente: ");
                scanf("%s", &telCliente);
                printf("Informe o endereço do cliente: ");
                scanf("%s", &endCliente);
                cadCliente(i, codigoCliente, nomeCliente, telCliente, endCliente, pCliente, vetClientes);
                i++;
            break;
            case 2:
                printf("\nInforme o codigo do veiculo: ");
                scanf("%d", &codigoVeiculo);
                printf("Descreva as caracteristicas do veiculo: ");
                scanf("%s %[^\n]", &descrVeiculo);
                printf("Informe a cor do veiculo: ");
                scanf("%s", &corVeiculo);
                printf("Informe o modelo do carro: ");
                scanf("%s %[^\n]", &modelVeiculo);
                printf("Informe a placa do veiculo: ");
                scanf("%s %[^\n]", &placaVeiculo);
                printf("Informe a quantidade de passageiros do veiculo: ");
                scanf("%d", &qtdPassageiros);
                printf("Informe o valor da diaria do carro: ");
                scanf("%5.2f", &valorDiaria);
                printf("Informe o status do veiculo: ");
                scanf("%s", &statusVeiculo);
                cadVeiculo(j,codigoVeiculo, descrVeiculo, corVeiculo, modelVeiculo, placaVeiculo, qtdPassageiros, valorDiaria, statusVeiculo, pVeiculo, vetVeiculos);
                j++;
                break;
            default:
                printf("\n");
                printf("__________________________________\n");
                printf("Finalizando programa..\n");
        }
    }

    return 0;
}
