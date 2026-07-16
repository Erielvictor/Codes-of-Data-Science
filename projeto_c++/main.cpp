#include <iostream>
using namespace std;


struct dados_paciente{
    string nome;
    int idade;
    string cpf;
    int prioridade; // 1 ao 5. 1= Vermelho, 2= Laranja, 3= Amarelo, 4= Verde, 5= Azul
    dados_paciente * prox;
};

struct FilaAgendamento {
    dados_paciente *inicio;
};

void inicializarFila(FilaAgendamento& fila) {
    fila.inicio = nullptr;
}

struct Node {
    dados_paciente info;
    Node* next;
};

string obterClassificacao(int nivel) {
    switch (nivel) {
        case 1: return "VERMELHO (IMEDIATO)";
        case 2: return "LARANJA (MUITO URGENTE)";
        case 3: return "AMARELO (URGENTE)";
        case 4: return "VERDE (POUCO URGENTE)";
        case 5: return "AZUL (NAO URGENTE)";
        default: return "Desconhecido";
    }
}

dados_paciente preencher_dados() {
    dados_paciente d;
    cout << "Digite o nome: ";
    getline(cin, d.nome); //Getline para nomes com espaços

    cout << "Digite a idade: ";
    cin >> d.idade;

    cout << "Digite o cpf: ";
    cin >> d.cpf;

    cout << "Informe a prioridade: ";
    cin >> d.prioridade;

    // Limpa o buffer de entrado para a próxima leitura de string
    cin.ignore();

    return d; // Retorna a struct preenchida
}


Node* criarNo(dados_paciente d, Node* proximo) {
    Node* novo = new Node;
    novo -> info = d;
    novo -> next = proximo;
    return novo;

}

void imprimir_lista(Node* head) {
    Node* atual = head;
    while (atual != nullptr) {
        cout << "Nome: " << atual -> info.nome
            << "| Idade: " << atual -> info.idade
            << "| Prioridade: " << atual -> info.prioridade << endl;
        atual = atual -> next;
    }
}


int main(){
    dados_paciente * head;
    head = new dados_paciente;
    cout << "Digite o nome: " << endl;
    cin >> head -> nome;
}