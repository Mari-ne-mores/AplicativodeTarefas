#include <iostream>
#include <vector>
#include <string>

struct calendarioDasatividades
    {
    int dia;
    int mes;
    int ano;
    
    std::string descricaoDatarefa;
    
    std::string nomeDatarefa;
    };
    
    //Cria uma lista de calendarioDasatividades
    std::vector<struct calendarioDasatividades>listaDeatividades;

enum OPERACOES
{
     INSERIR_TAREFA=1, EXIBIR_TAREFA=2, SAIR=3
};

void adicionarnovaAtividade()
{
struct calendarioDasatividades novaAtividade;
 std::cout<<"Digite o dia da entrega da nova Atividade:"<<std::endl;
 std::cin>>novaAtividade.dia;
 std::cout<<"------------------------------------------------------------"<<std::endl;
 std::cout<<"Digite o mes da entrega da nova Atividade:"<<std::endl;
 std::cin>>novaAtividade.mes;
 std::cout<<"------------------------------------------------------------"<<std::endl;
 std::cout<<"Digite o ano da entrega da nova Atividade:"<<std::endl;
 std::cin>>novaAtividade.ano;
 std::cout<<"------------------------------------------------------------"<<std::endl;

 std::cin.ignore();

 std::cout<<"Informe o Nome da Matéria ou da Tarefa"<<std::endl;
    std::cin>>novaAtividade.nomeDatarefa;
    std::cout<<"------------------------------------------------------------"<<std::endl;
    
    std::cin.ignore();

 std::cout<<"Escreva a descrição da Tarefa"<<std::endl;
 std::getline(std::cin, novaAtividade.descricaoDatarefa);
 std::cout<<"------------------------------------------------------------"<<std::endl;

 listaDeatividades.push_back(novaAtividade);
}

void mostrarnovaAtividade() 
{
  //i é a variável que indica a posição que queremos 
  //acessar dentro de nossa lista
  for (int i=0; i < listaDeatividades.size(); i++)
  {
      //Exibe o dia, mes e ano separados por "/" mais a descrição
    std::cout<<"------------------------------------------------------------\n"
    <<listaDeatividades [i].dia <<"/"<<
    listaDeatividades[i].mes<<"/"<<listaDeatividades[i].ano<<"-"<<
    listaDeatividades[i].descricaoDatarefa
    <<"\n------------------------------------------------------------"<<std::endl;
  }
}

OPERACOES exibeMenu()
{
    std::cout<<"Escolha o que você deseja fazer:"<<std::endl;
    std::cout<<INSERIR_TAREFA<<"- Inserir uma tarefa"<<std::endl;
    std::cout<<EXIBIR_TAREFA<<"- Exibir tarefas"<<std::endl;
    std::cout <<SAIR<<"- Sair do programa"<<std::endl;
    int escolha = 0;
    
    std::cin>>escolha;
    
    return (OPERACOES) escolha;
}

void adicionarcalendarioDasatividades() 
    {
        struct calendarioDasatividades novaAtividade;
    std::cout<<"Informe a Data de Entrega da atividade."<<std::endl;
    
    std::cout<<"Dia da entrega:"<<std::endl;
    std::cin>>novaAtividade.dia;
    
    std::cout<<"Mês da entrega:"<<std::endl;
    std::cin>>novaAtividade.mes;
    
    std::cout<<"Ano da entrega:"<<std::endl;
    std::cin>>novaAtividade.ano;
    
    //Limpa a memoria de qualquer caractere restante 
    //Se isso nao for feito getline nao funciona
    std::cin.ignore();
    
    
    std::cout<<"Informe o Nome da Matéria"<<std::endl;
    std::cin>>novaAtividade.nomeDatarefa;
    
    std::cin.ignore();
    
    std::cout<<"Informe a descrição da tarefa:"<<std::endl;
    std::getline(std::cin,novaAtividade.descricaoDatarefa);
    
    //Adiciona esse item da atividade na listaDeatividades
    listaDeatividades.push_back(novaAtividade);
}

void mostrarcalendarioDasatividades()
{
    for(int i=0; i<<listaDeatividades.size(); i++)
    {
    std::cout<<listaDeatividades[i].dia<<"/"<<listaDeatividades[i].mes<<"/"<<listaDeatividades[i].mes<<"/"<<listaDeatividades[i].ano<<":"<<listaDeatividades[i].descricaoDatarefa<<std::endl;
    }
}

int main (int agrc, char **argv)
{
    while (true)
    {
        int escolha = exibeMenu();
        
        switch (escolha)
        {
            case INSERIR_TAREFA:
            adicionarnovaAtividade();
        break;
            case EXIBIR_TAREFA:
            mostrarnovaAtividade();
        break;
            case SAIR:
            return 0;
        default:
        std::cout<<"Opção inválida"<<std::endl;
        break;
        }
    } 
}
