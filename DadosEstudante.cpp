// Exercicio - Criar um algoritmo que gerencia uma pequena base de dados de estudantes e permite adicionar e buscar estudantes por nome.
/*
    Requisitos: 
    • Usar uma struct para armazenar os dados do estudante (nome, idade, e numero de matricula).
    • Implementar uma funcao adicionarEstudante para adicionar um novo estudante a uma lista.
    • Implementar uma funcao buscarEstudante para buscar estudantes pelo nome.
    • Utilizar um vetor ou lista para armazenar os estudantes.
    • Utilizar comando de entrada para interagir com o usuario.
    • Utilizar comando de saida para mostrar os resultados das buscas.
    • Não utilize classes
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//=== ESTRUTURA PARA ARMAZENAR OS DADOS DO ESTUDANTE ===//
struct Estudante
{
    string nomeEstudante;
    int idadeEstudante;
    int numMatricula;
};

//=== FUNCAO PARA ADICIONAR UM NOVO ESTUDANTE A LISTA ===/
void adicionarEstudante(vector<Estudante> &estudantes){
    Estudante novoEstudante;

    cout << "\n== CADASTRO DE ESTUDANTE ==" << endl;
    cout << "Informe o nome do estudante: ";
    cin.ignore();
    getline(cin, novoEstudante.nomeEstudante);

    // Verifica se o estudante ja foi cadastrado
    for (const auto &estudante : estudantes) { // Declarado como const, para impedir modificacoes
        if (estudante.nomeEstudante == novoEstudante.nomeEstudante) {
            cout << "\nErro: Estudante ja cadastrado!\n";
            return;
        }
    }

    cout << "Informe a idade do estudante: ";
    cin >> novoEstudante.idadeEstudante;

    cout << "Informe o numero de matricula: ";
    cin >> novoEstudante.numMatricula;

    estudantes.push_back(novoEstudante); // Adicionando um novo estudante a Lista
    cout << "\nEstudante cadastrado com sucesso!\n" << endl;
}

//=== FUNCAO PARA BUSCAR ESTUDANTES NA LISTA ===//
void buscarEstudante(const vector<Estudante> &estudantes){ // Declarado como const, para impedir modificacoes na busca
    
    if(estudantes.empty()){
        cout << "\nNenhum estudante cadastrado ainda.\n";
        return; // Funcao retorna para a funcao main, sem interromper o programa
    }

    string buscarEstudante;

    cout << "\n== BUSCAR ESTUDANTE ==" << endl;
    cout << "Digite o nome do estudante que deseja buscar: ";
    cin.ignore();
    getline(cin, buscarEstudante);

    bool estudanteEncontrado = false;
    for(const auto&estudante : estudantes){ // Declarado como const, para impedir modificacoes
        if(estudante.nomeEstudante == buscarEstudante){
            cout << "Resultado da Busca:\n";
            cout << "-------------------------------------------------" << endl;
            cout << "Nome: " << estudante.nomeEstudante << "." << endl;
            cout << "Idade: " << estudante.idadeEstudante << "." << endl;
            cout << "Numero da Matricula: " << estudante.numMatricula << "." << endl;
            cout << "-------------------------------------------------" << endl;
            estudanteEncontrado = true;
            break; // Sai do loop ao encontrar o estudante
        }

        if(!estudanteEncontrado){
            cout << "\nNenhum resultado encontrado... valide o nome do estudante, e tente novamente.\n";
        }
    }
}

int main(){
    vector<Estudante> estudantes;
    int opcao;

    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "\n1. Adicionar Estudante.\n2. Buscar Estudante.\n3. Sair do Sistema.\n" << endl;
        cout << "==========================" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            adicionarEstudante(estudantes);
            break;
        case 2:
            buscarEstudante(estudantes);
            break;

        case 3:
            cout << "Encerrando o programa..." << endl;
            break;

        default:
            cout << "Opcao invalida... tente novamente.\n" << endl;
            break;
        }
    } while(opcao != 3);
}