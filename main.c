#include <stdio.h>
# define SIZE 5

typedef struct {
	char RA[127];
	char Arquivo[127];
	char Extensao[127];
	char Matricula[127]; 
} Aluno;

void enqueue();
void dequeue();
void pouseAndClean();
void show();
Aluno inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;
void pouse();
int confirmOperacao();
void cleanExercicios();
main()
{
    int ch;
    int loop = 1;
    
    while (loop)
    {
    	show();
    	
        printf("1.Adicionar exercicio\n");
        printf("2.Deletar o primeiro exercicio\n");
        printf("3.Limpar lista de exercicios\n");
        printf("4.Sair\n\n");
        printf("Digite um numero para executar a operacao desejada : ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1:
            system("clear||cls");
            enqueue();
            system("clear||cls");
            break;
            case 2:
            dequeue();
            system("clear||cls");
            break;
            case 3:
            cleanExercicios();
            system("clear||cls");
            break;
            case 4:
            loop = 0;	
            break;
            default:
            	 printf("\n\n");
            printf("Opcao invalida!!! Clique (Enter) para voltar ao Menu\n");
            pouseAndClean();
        } 
    } 
    
    return 0;
} 
  
void enqueue()
{
     Aluno insert_item;
    if (Rear == SIZE - 1) 
	{
		printf("A Lista de exercicios esta cheia!!!\n");
		pouseAndClean();
	}
   
    else
    {
        if (Front == - 1) 
		{
			Front = 0;	
		}
       
       	printf("==========================================================\n");
		printf("=              		Adicionando exercicio                =\n");
		printf("==========================================================\n\n");
		printf("Digite a RA do Aluno : ");
        scanf("%s", &insert_item.RA);
        printf("Digite o Nome do Arquivo : ");
        scanf("%s", &insert_item.Arquivo);
        printf("Digite a Extensao do Arquivo : ");
        scanf("%s", &insert_item.Extensao);
        printf("Digite a Matricula do Professor Responsavel : ");
        scanf("%s", &insert_item.Matricula);
        Rear = Rear + 1;
        inp_arr[Rear] = insert_item;
    }
} 
  
void dequeue()
{	
	int indexAluno;
	int indexUpdate;
	Aluno alunos[SIZE];
	int confirm;
	
	for(indexAluno = 0; indexAluno < SIZE; indexAluno++) 
	{
		alunos[indexAluno] = inp_arr[indexAluno]; 	
	}
	
	
    if (Front == - 1 || Front > Rear)
    {
    	printf("\n");
        printf("  A Lista esta vazia!!! clique (Enter) para voltar ao Menu\n\n");
		pouseAndClean();
		return ; 
    }
    else
    {   
    	printf("\n");
        printf("O Exercicio sera excluido: RA do Aluno: %s, Nome do Arquivo: %s, Extensao do Arquivo: %s, Matricula: %s \n", 
		inp_arr[Front].RA, inp_arr[Front].Arquivo, inp_arr[Front].Extensao, inp_arr[Front].Matricula);
        
        confirm = confirmOperacao();
        
        
		if(confirm == 1)
		{
			
			for(indexUpdate = 0; indexUpdate < SIZE; indexUpdate++) 
			{
				inp_arr[indexUpdate] = alunos[(indexUpdate + 1)];
			}
			
			Front = 0;
			Rear = Rear - 1;	
		}
    }
} 
  
void show()
{
	printf("==========================================================\n");
	printf("=                         Menu                           =\n");
	printf("==========================================================\n\n");
	printf("==========================================================\n");
	printf("=                  Lista de Exercicios                   =\n");
	printf("==========================================================\n\n");
	
    int i;
    if (Front == - 1) return;

	else
    {
        printf("Exercicios: \n\n");
        for ( i = Front; i <= Rear; i++)
            printf(" 	ID: %d, RA do Aluno: %s, Nome do Arquivo: %s, Extensao do Arquivo: %s, Matricula: %s \n", 
			i + 1, inp_arr[i].RA, inp_arr[i].Arquivo, inp_arr[i].Extensao, inp_arr[i].Matricula);
        printf("\n");
    }
} 

void cleanExercicios() 
{
	if (Front == - 1 || Front > Rear)
    {
    	printf("\n");
        printf("  A Lista esta vazia!!! clique (Enter) para voltar ao Menu\n\n");
		pouseAndClean();
		return ; 
    }
	Front =  -1;
	Rear = -1;
}

void pouseAndClean() 
{
	getch();
	system("clear||cls");
}

void pouse() 
{
	system("clear||cls");	
}

int confirmOperacao() 
{
	int confirm;
	printf("\n");
	printf("Deseja confirma essa operacao 1 - Sim | 2 - Nao  : ");
    scanf("%d", &confirm);
}
