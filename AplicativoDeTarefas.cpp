#include <iostream>
#include <vector>
#include <string>

struct tm* recuperarTarefadeHoje()
{
    // Variavel usada para armazenar a
   // quantidade de segundos para
   // representar uma data
   time_t tt;

   // Armazena a quantidade segundos que
  // se passaram desde as 0 horas de 1
  // de jane iro de 1970 no horario de
  // Greenwich
  time(&tt ) ;

 // Transforma esses segundos em uma
 // estrutura que separa o dia , mes,
 // ano , etc . e a retorna .
 return localtime(&tt);
}

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
     INSERIR_TAREFA=1, EXIBIR_TAREFA=2,
     VER_TAREFAS_DE_HOJE, SAIR
};

void adicionarnovaAtividade()
{
struct calendarioDasatividades novaAtividade;
 std::cout<<"Digite o dia da entrega da nova Atividade:"<<std::endl;
 std::cin>>novaAtividade.dia;
 std::cout<<"Digite o mes da entrega da nova Atividade:"<<std::endl;
 std::cin>>novaAtividade.mes;
 std::cout<<"Digite o ano da entrega da nova Atividade:"<<std::endl;
 std::cin>>novaAtividade.ano;

 std::cin.ignore();

 std::cout<<"Informe o Nome da Tarefa"<<std::endl;
    std::cin>>novaAtividade.nomeDatarefa;
    
    std::cin.ignore();

 std::cout<<"Escreva a descrição da Tarefa"<<std::endl;
 std::getline(std::cin, novaAtividade.descricaoDatarefa);

 listaDeatividades.push_back(novaAtividade);
}

void mostrarnovaAtividade() 
{
  //i é a variável que indica a posição que queremos 
  //acessar dentro de nossa lista
  for (int i=0; i < listaDeatividades.size(); i++)
  {
      //Exibe o dia, mes e ano separados por "/" mais a descrição
    std::cout<<listaDeatividades [i].dia <<"/"<<
    listaDeatividades[i].mes<<"/"<<listaDeatividades[i].ano<<"-"<<
    listaDeatividades[i].descricaoDatarefa<<std::endl;
  }
}

OPERACOES exibeMenu()
{
    std::cout<<"Escolha o que você deseja fazer:"<<std::endl;
    std::cout<<INSERIR_TAREFA<<"- Inserir uma tarefa"<<std::endl;
    
    std::cout<<EXIBIR_TAREFA<<"- Exibir tarefas"<<std::endl;
    std::cout<<VER_TAREFAS_DE_HOJE<<"-Exibir todos as tarefas de hoje"<<std::endl;
    std::cout <<SAIR<<"-Sair do programa"<<std::endl;
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
    // i e a variavel que indica a posicao que queremos 
    // acessar dentro de nossa lista
    for(int i=0; i<<listaDeatividades.size(); i++)
    {
        //Exibe o dia, mes e ano separados por "/" mais a descrição
    std::cout<<listaDeatividades[i].dia<<"/"<<listaDeatividades[i].mes<<"/"<<listaDeatividades[i].mes<<"/"<<listaDeatividades[i].ano<<":"<<listaDeatividades[i].descricaoDatarefa<<std::endl;
    }
}

std::vector<struct listaDeatividades>recuperarTarefadeHoje(std::vector<struct listaDeatividades> &lista);

{
    auto data=recuperarDataAtual();
    
    std::vector<struct listaDeatividades>resultado;
    
    for (unsigned int i=0; i<lista.size(); i++)
    {
        if(data->tm_year+1900!= lista[i].ano) continue;
        if(data->tm_mom+1!= lista[i].mes) continue;
        if(data->tm_mday!= lista[i].dia) continue;
        
        resultado.push_back(lista[i]);
    }
    
    return resultado;
}

int main (int agrc, char **argv)
std::vector<listaDeatividades>tarefasDeHoje;
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
            case VER_TAREFAS_DE_HOJE:
            //recupera as tarefas de VER_TAREFAS_DE_HOJE
            tarefasDeHoje= recuperarTarefadeHoje(listaDeatividades)
            //Mostra as tarefas
            mostrarcalendarioDasatividades(tarefasDeHoje);
        break;
            case SAIR
            //Retorna ao sistema operacional
            return 0;
        default:
        std::cout<<"Opção inválida"<<std::endl;
        break;
        }
    } 
}









