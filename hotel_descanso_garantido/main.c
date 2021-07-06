#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include "room/room.c"

struct Scliente
{
    int id;
    char nome[200];
    char endereco[200];
    double telefone;
};
typedef struct Scliente cliente;

struct Sfuncionario
{
    int id;
    char nome[200];
    double telefone;
    char cargo[100];
    float salario;
};
typedef struct Sfuncionario funcionario;

//Menus
void mostraMenu();
void mostraMenu2();

//Funcoes de Mostrar Info

void mostrarClientes(FILE *pcliente);
void mostrarFuncionarios(FILE *pfuncionario);

//Funcoes de Cadastro
void cadastroCliente(FILE *pcliente);
void cadastroFuncionario(FILE *pfuncionario);


//Funcoes de Pesquisa
void localizaCliente(FILE *f);
void localizaFuncionario(FILE *f);

int main()
{
    setlocale(LC_ALL,"portuguese");
    FILE *pcliente;
    FILE *pfuncionario;

    if((pcliente = fopen("clientes.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo não existe -- Criando Novo arquivo!\n");
        if((pcliente = fopen("clientes.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
        system("pause");
    }

    if((pfuncionario = fopen("funcionarios.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo não existe -- Criando Novo arquivo!\n");
        if((pfuncionario = fopen("funcionarios.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
        system("pause");
    }

    int op;
    char op2;
    do
    {
        mostraMenu();

        //op=getch();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            cadastroCliente(pcliente);
            system("pause");
            break;
        case 2:
            localizaCliente(pcliente);
            system("pause");
            break;

        case 3:
            cadastroFuncionario(pfuncionario);
            system("pause");
            break;

        case 4:
            localizaFuncionario(pfuncionario);
            system("pause");
            break;
        
        case 5:
            registerRoom();
            system("pause");
            break;

        case 7:
            mostraMenu2();
            op2=getch();
            system("cls || clear");
            switch (op2)
            {
            case 'a':
                mostrarClientes(pcliente);
                system("pause");
                break;
            case 'b':
                mostrarFuncionarios(pfuncionario);
                system("pause");
                break;
            while(op!='e');
            }
            break;
        }
    }
    while(op!=10);

    return 0;
}
//Menu Principal
void mostraMenu()
{
    system("cls || clear");
    printf("\nBem Vindo ao Hotel Descanso Garantido!\n");
    printf("\n=======================================");
    printf("\n[1]-Cadastrar Cliente");
    printf("\n[2]-Pesquisar Cliente");
    printf("\n[3]-Cadastrar Funcionario");
    printf("\n[4]-Pesquisar Funcionario");
    printf("\n[5]-Cadastrar quarto");
    printf("\n[5]-Cadastrar Estadia");
    printf("\n[6]-Fechar Estadia");
    printf("\n[7]-Mostrar informacoes");
    printf("\n[8]-Mostrar Estadias de um Cliente");
    printf("\n[9]-Mostrar Pontos Fidelidade");
    printf("\n[10]-Sair");
    printf("\n=======================================\n");
    printf("\nQuais das opções você deseja executar? ");
}
//Menu de Informações
void mostraMenu2()
{
    system("cls || clear");

    printf("\n");
    printf("\n================================================");
    printf("\n[a]-Mostrar Informações dos Clientes");
    printf("\n[b]-Mostrar Informações dos Funcionarios");
    printf("\n[c]-Mostrar Informações dos Quartos");
    printf("\n[d]-Mostrar todas estadias");
    printf("\n[e]-Sair");
    printf("\n================================================\n");
    printf("\nQuais das opções você deseja executar? ");
}

//Funcoes de Mostrar Info Cliente
void mostrarClientes(FILE *pcliente)
{
    cliente m;
    fseek(pcliente,0,SEEK_SET);
    fread(&m, sizeof(m),1, pcliente);
    printf("\n====================Clientes====================\n");
    while(!feof(pcliente))
    {
        printf("\nID____________: %d \n",m.id);
        printf("\nNome__________: %s \n",m.nome);
        printf("\nEndereço______: %s\n",m.endereco);
        printf("\nTelefone______: %.0f\n\n",m.telefone);
        fread(&m, sizeof(m),1, pcliente);
        printf("________________________________________________\n\n");
    }

}
//Funcoes de Mostrar Info Funcionário
void mostrarFuncionarios(FILE *pfuncionario)
{
    funcionario mf;
    fseek(pfuncionario,0,SEEK_SET);
    fread(&mf, sizeof(mf),1, pfuncionario);
    printf("\n=================Funcionarios=================\n");
    while(!feof(pfuncionario))
    {
        printf("\nID____________: %d \n",mf.id);
        printf("\nNome__________: %s \n",mf.nome);
        printf("\nCargo_________: %s\n",mf.cargo);
        printf("\nTelefone______: %.0f\n\n",mf.telefone);
        printf("\nSalario_______: %.0f\n\n",mf.salario);
        fread(&mf, sizeof(mf),1, pfuncionario);
        printf("________________________________________________\n\n");

    }

}

//Funcoes de Mostrar Info Estadia

//Funcoes de Mostrar Info Quarto


void cadastroCliente(FILE *pcliente)
{
    cliente c;

    int size;

    fseek(pcliente,0,SEEK_END);

    size=ftell(pcliente);

    if (size==0)
    {
        c.id=1;
        printf("\n\nParabéns você é nosso 1º Cliente!\n");
        printf("\nID: 1\n");
    }
    else
    {
        fseek(pcliente,(long int) sizeof(c)*(-1),SEEK_END);
        fread(&c, sizeof(c),1, pcliente);

        c.id++;
        printf("\n\n->ID: %d\n",c.id);
    }

    printf("\n->Nome: ");
    fflush(stdin);
    gets(c.nome);

    printf("\n->Endereco: ");
    fflush(stdin);
    gets(c.endereco);

    printf("\n->Telefone: ");
    scanf("%lf",&c.telefone);

    fseek(pcliente,0,SEEK_END);
    fwrite(&c, sizeof(c),1,pcliente);
    fflush(pcliente);

    printf("\nCadastrado Efetuado com sucesso!!\n\n");
}

//Função Localiza Cliente
void localizaCliente(FILE *f)
{
    system("cls || clear");
    int idteste,teste=0;

    printf("\n================Localiza Cliente================\n\n");
    printf(">ID do cliente: ");
    scanf("%d",&idteste);

    cliente c;

    fseek(f,0,SEEK_SET);

    fread(&c, sizeof(c),1, f);

    while(!feof(f))
    {
        if(c.id==idteste)
        {
        printf("\nID____________: %d \n",c.id);
        printf("\nNome__________: %s \n",c.nome);
        printf("\nEndereço______: %s\n",c.endereco);
        printf("\nTelefone______: %.0f\n\n",c.telefone);
        teste=1;
        }
        fread(&c, sizeof(c),1, f);
    }

    if(teste==0)
    {
        printf("\nCliente não encontrado!");
    }
}


void cadastroFuncionario(FILE *pfuncionario)
{
    funcionario f;

    int size;

    fseek(pfuncionario,0,SEEK_END);

    size=ftell(pfuncionario);

    if (size==0)
    {
        f.id=1;
        printf("\n\nParabéns você é o nosso 1º Funcionário!\n");
        printf("\nID: 1\n");
    }
    else
    {
        fseek(pfuncionario,(long int) sizeof(f)*(-1),SEEK_END);
        fread(&f, sizeof(f),1, pfuncionario);

        f.id++;
        printf("\n\n->ID: %d\n",f.id);
    }

    printf("\n->Nome: ");
    fflush(stdin);
    gets(f.nome);

    printf("\n->Cargo: ");
    fflush(stdin);
    gets(f.cargo);

    printf("\n->Telefone: ");
    scanf("%lf",&f.telefone);

    printf("\n->Salario: ");
    scanf("%f",&f.salario);

    fseek(pfuncionario,0,SEEK_END);
    fwrite(&f, sizeof(f),1,pfuncionario);
    fflush(pfuncionario);

    printf("\nCadastro Efetuado com sucesso!!\n\n");
}

void localizaFuncionario(FILE *f)
{
    system("cls || clear");
    int idteste,teste=0;

    printf("\n================Localiza Funcionário================\n\n");
    printf(">ID do funcionario: ");
    scanf("%d",&idteste);

    funcionario c;

    fseek(f,0,SEEK_SET);

    fread(&c, sizeof(c),1, f);

    while(!feof(f))
    {
        if(c.id==idteste)
        {
        printf("\nID____________: %d \n",c.id);
        printf("\nNome__________: %s \n",c.nome);
        printf("\nCargo_________: %s\n",c.cargo);
        printf("\nSalário_______: %.2f\n",c.salario);
        printf("\nTelefone______: %.0f\n\n",c.telefone);
        teste=1;
        }
        fread(&c, sizeof(c),1, f);
    }

    if(teste==0)
    {
        printf("\nFuncionário não encontrado!");
    }
}
