#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Função de login exclusivo para administrador
int loginAdministrador() {
    char usuario[20], senha[20];

    printf("=== ÁREA RESTRITA ===\n");
    printf("Digite o login do administrador: ");
    scanf("%s", usuario);
    printf("Digite a senha do administrador: ");
    scanf("%s", senha);

    if (strcmp(usuario, "admin") == 0 && strcmp(senha, "admin") == 0) {
        printf("Login realizado com sucesso.\n");
        system("pause");
        return 1; // acesso permitido
    } else {
        printf("Acesso negado. Login ou senha incorretos.\n");
        return 0; // acesso negado
    }
}

void registro() {
    char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    strcpy(arquivo, cpf);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fprintf(file, "%s,%s,%s,%s\n", cpf, nome, sobrenome, cargo);
    fclose(file);

    printf("Registro salvo com sucesso!\n");
    system("pause");
}

void consulta() {
    char cpf[40], conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("CPF não encontrado!\n");
    } else {
        fgets(conteudo, 200, file);
        printf("As informações são: %s\n", conteudo);
        fclose(file);
    }

    system("pause");
}

void deletar() {
    char cpf[40];

    printf("Digite o CPF do registro a ser deletado: ");
    scanf("%s", cpf);

    int resultado = remove(cpf);
    if (resultado == 0) {
        printf("Arquivo deletado com sucesso.\n");
    } else {
        printf("Erro ao deletar. Arquivo pode não existir.\n");
    }

    system("pause");
}

int main() {
    int opcao = 0;
    setlocale(LC_ALL, "Portuguese");

    // Solicita login do administrador antes de acessar o menu
    if (!loginAdministrador()) {
        printf("Encerrando o sistema por falha de autenticação.\n");
        return 0;
    }

    while (1) {
        system("cls");
        printf("### Cartório da EBAC – Área Administrativa ###\n\n");
        printf("Escolha a opção desejada:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
                system("pause");
                break;
        }
    }

    return 0;
}

