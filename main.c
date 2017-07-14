#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX 50
FILE *arq;
FILE *arqt;
FILE *log;
int i;
int op=0;
int opt=0;
int result=0;
int qt=0,qtv=0;

typedef struct time 
{
	int tm_sec; 
	int tm_min; 
	int tm_hour;
	int tm_mday;
	int tm_mon; 
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
} Tm;

typedef struct tarefas
{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    char nome[50];
    char nota[400];
    
} Tarefas;


char *strupr(char *str){
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = toupper(*p);
      p++;
  }

  return str;
}

void menutarefa()
{	
	Tm *local;
	time_t ta;
	ta=time(NULL);
	local=localtime(&ta);
	int d,m,a,h,min,s;
	d=local->tm_mday;
	m=local->tm_mon;
	a=local->tm_year;
	h=local->tm_hour;
	min=local->tm_min;
	s=local->tm_wday;
	
	
//AGENDA INICIO
    puts("\t##########	##########	##########	###	 ##	######		##########");
    puts("\t##	##	##		##		## ##    ##	##    ##	##	##");
    puts("\t##	##	##		##		##  ##   ##	##	##	##	##");
    puts("\t##########	##	###	##########	##   ##	 ##	##	##	##########");
    puts("\t##	##	##	##	##		##    ## ##	##    ##	##	##	");
    puts("\t##	##	##########	##########	##     ####	######		##	##\n\n");
//Agenda FIM
//FUP INICIO
    puts("\t\t\t\t#########	##	##	#########");
    puts("\t\t\t\t##		##	##	##	##");
    puts("\t\t\t\t##		##	##	##	##");
    puts("\t\t\t\t#########	##	##	#########");
    puts("\t\t\t\t##		##	##	##");
    puts("\t\t\t\t##		##########	##\n\n");
//FUP FIM
 
    	printf("\t\t\t\t");
    	if(s==0)
		{
			printf("	DOM : ");
		}
		if(s==1)
		{
			printf("	SEG : ");
		}
		if(s==2)
		{
			printf("	TER : ");
		}
		if(s==3)
		{
			printf("	QUA : ");
		}
		if(s==4)
		{
			printf("	QUI : ");
		}
		if(s==5)
		{
			printf("	SEX : ");
		}
		if(s==6)
		{
			printf("	SAB : ");
		}	
   	printf(" %d/%d/%d %d:%d		\n",d,m+1,a+1900,h,min);
   
//OPí•©ES INICIO
    puts("\t\t\t\t##########################################");
    puts("\t\t\t\t##     		TAREFAS		        ##");
    puts("\t\t\t\t##	Digite				##");
    puts("\t\t\t\t##	1->Adicionar Tarefa 	        ##");
    puts("\t\t\t\t##	2->Exibir Tarefa                ##");
    puts("\t\t\t\t##	3->Editar Tarefa	        ##");
    puts("\t\t\t\t##	4->Excluir Tarefa	        ##");
    puts("\t\t\t\t##	5->Buscar Tarefas       	##");
    puts("\t\t\t\t##	6->Sair				##");
    printf("\t\t\t\t##	TOTAL DE TAREFAS: %d		##\n",qt);
    puts("\t\t\t\t##########################################");
    //OPí•©ES FIM
}

void menutarefaop()
{
//AGENDA INICIO
    puts("\t##########	##########	##########	###	 ##	######		##########");
    puts("\t##	##	##		##		## ##    ##	##    ##	##	##");
    puts("\t##	##	##		##		##  ##   ##	##	##	##	##");
    puts("\t##########	##	###	##########	##   ##	 ##	##	##	##########");
    puts("\t##	##	##	##	##		##    ## ##	##    ##	##	##	");
    puts("\t##	##	##########	##########	##     ####	######		##	##\n\n");
//Agenda FIM
//FUP INICIO
    puts("\t\t\t\t#########	##	##	#########");
    puts("\t\t\t\t##		##	##	##	##");
    puts("\t\t\t\t##		##	##	##	##");
    puts("\t\t\t\t#########	##	##	#########");
    puts("\t\t\t\t##		##	##	##");
    puts("\t\t\t\t##		##########	##\n\n");
//FUP FIM
}
void menueventos()
{

	Tm *local;
	time_t ta;
	ta=time(NULL);
	local=localtime(&ta);

//AGENDA INICIO
    puts("\t##########	##########	##########	###	 ##	######		##########");
    puts("\t##	##	##		##		## ##    ##	##    ##	##	##");
    puts("\t##	##	##		##		##  ##   ##	##	##	##	##");
    puts("\t##########	##	###	##########	##   ##	 ##	##	##	##########");
    puts("\t##	##	##	##	##		##    ## ##	##    ##	##	##	");
    puts("\t##	##	##########	##########	##     ####	######		##	##\n\n");
//Agenda FIM
//FUP INICIO
    puts("\t\t\t\t#########	##	##	#########");
    puts("\t\t\t\t##		##	##	##	##");
    puts("\t\t\t\t##		##	##	##	##");
    puts("\t\t\t\t#########	##	##	#########");
    puts("\t\t\t\t##		##	##	##");
    puts("\t\t\t\t##		##########	##\n\n");
//FUP FIM
//OPí•©ES INICIO
    puts("\t\t\t\t##########################################");
    puts("\t\t\t\t##     				        ##");
    puts("\t\t\t\t##	Digite				##");
    printf("\t\t\t\t##	1->Tarefas no DIA: %d   	##\n",local->tm_mday);
    printf("\t\t\t\t##	2->Tarefas no MÊS: %d            ##\n",local->tm_mon+1);
    printf("\t\t\t\t##	3->Tarefas no ANO: %d         ##\n",local->tm_year+1900);
    printf("\t\t\t\t##	4->Sair				##\n");
    printf("\t\t\t\t##	TOTAL DE TAREFAS: %d		##\n",qt);
    puts("\t\t\t\t##########################################");
//OPí•©ES FIM
}
void logteclas(char c[])
{
	Tm *local;
	time_t t;
	t=time(NULL);
	local=localtime(&t);
	int dia,mes,ano,hora,minuto,segundo;
	dia=local->tm_mday;
	mes=local->tm_mon+1;
	ano=local->tm_year+1900;
	hora=local->tm_hour;
	minuto=local->tm_min;
	segundo=local->tm_sec;
	log=fopen("log.txt","at");
	fprintf(log,"%d/%d/%d | %d:%d:%d\n",dia,mes,ano,hora,minuto,segundo);
	fprintf(log,"%s\n\n",c);
	fclose(log);
}
void eventos(Tarefas** t)
{
	Tm *local;
	int ct=0;
	time_t ta;
	ta=time(NULL);
	local=localtime(&ta);
	system("cls || clear");
	menueventos();
	op=scan();
	while(op!= 1 && op !=2 && op !=3 && op != 4)
    {
    	printf("Valor inválido\n");
    	op=scan();
	}
	if(op==4)
	{
		printf("Deseja voltar para o Menu Principal?\n1->SIM\n2->NÃO\n");
    	opt=scan();
	    switch(opt)
    	{
    		case 1:
        	menu(t);
        		break;
    	    case 2:
            exit(1);
           		break;
    	}
	}
	for(i=0;i<qt;i++)
	{
		if(op==1)
		{
			
			if(local->tm_mday == t[i]->dia)
			{
				ct++;
		  	 	printf("\t\t\t\t\t##########################\n\t\t\t\t\t##	TAREFA N°%d	##\n\t\t\t\t\t##########################\n\t\t\t\t\t--Nome: %s\n\t\t\t\t\t--Data: %d/%d/%d\n\t\t\t\t\t--Hora: %d:%d\n\t\t\t\t\t--Anotação: %s\n",i+1,t[i]->nome,t[i]->dia,t[i]->mes,t[i]->ano,t[i]->hora,t[i]->minuto,t[i]->nota);
			}
		}
		if(op==2)
		{
			
			if(local->tm_mon+1 == t[i]->mes)	
			{
				ct++;
				printf("\t\t\t\t\t##########################\n\t\t\t\t\t##	TAREFA N°%d	##\n\t\t\t\t\t##########################\n\t\t\t\t\t--Nome: %s\n\t\t\t\t\t--Data: %d/%d/%d\n\t\t\t\t\t--Hora: %d:%d\n\t\t\t\t\t--Anotação: %s\n",i+1,t[i]->nome,t[i]->dia,t[i]->mes,t[i]->ano,t[i]->hora,t[i]->minuto,t[i]->nota);
			}
		}
		if(op==3)
		{
			
			if(local->tm_year+1900 == t[i]->ano)
			{
				ct++;
				printf("\t\t\t\t\t##########################\n\t\t\t\t\t##	TAREFA N°%d	##\n\t\t\t\t\t##########################\n\t\t\t\t\t--Nome: %s\n\t\t\t\t\t--Data: %d/%d/%d\n\t\t\t\t\t--Hora: %d:%d\n\t\t\t\t\t--Anotação: %s\n",i+1,t[i]->nome,t[i]->dia,t[i]->mes,t[i]->ano,t[i]->hora,t[i]->minuto,t[i]->nota);
			}
		}
		
	}
	
	printf("TAREFAS NA DATA: %d/%d/%d : %d\n",local->tm_mday,local->tm_mon+1,local->tm_year+1900,ct);
    printf("Deseja Fazer uma Nova busca?\n1->SIM\n2->NÃO\n");
    op=scan();
    while(op!= 1 && op != 2)
    {
    	printf("Valor inválido\n");
    	op=scan();
	}
    if(op==1)
        eventos(t);
    if(op==2)
   		printf("Deseja voltar para o Menu Principal?\n1->SIM\n2->NÃO\n");
    opt=scan();
    switch(opt)
    {
    	case 1:
        	menu(t);
        	break;
        case 2:
            exit(1);
            break;
    }

}
int scan()
{
    char strop[4];
    int scanop=0;
    while (1)
    {
        gets(strop);
        if ( sscanf (strop, "%d", &scanop) != 1)
        {
            
            logteclas(strop);
        }
        else
        {
            break;
        }
    } 
	logteclas(strop);
    return scanop;
}
void quantidade(Tarefas** t)
{
    int c;
    qt=0;
    arqt=fopen("tarefas.bin","rb");
    while((c=getc(arqt) ) != EOF)
    {
        if(c=='\n')
        {
            qt++;
        }
    }
    fclose(arqt);
}
void carregar(Tarefas** t)
{
    
    quantidade(t);
    arqt=fopen("tarefas.bin","rb");
    for(i=0; i<qt; i++)
    {
        t[i]=(Tarefas*)malloc(sizeof(Tarefas));
        fscanf(arqt," %49[^\t] %d %d %d %d %d %399[^\n]\n",t[i]->nome,&t[i]->dia,&t[i]->mes,&t[i]->ano,&t[i]->hora,&t[i]->minuto,t[i]->nota);
        strupr(t[i]->nome);
    	strupr(t[i]->nota);
    }
    fclose(arqt);
}
void inicializar(Tarefas** t)
{
    for(i=0; i<qt+MAX; i++)
    {
        t[i]=NULL;
    } 
	carregar(t);  
}
void busca(Tarefas** t)
{
    int dia=0,mes=0,ano=0,ct=0;  
    quantidade(t);
    system("clear || cls");
    printf("Digite a Data do Evento:\n");
    printf("DIA:\n");
    dia=scan();
    while(dia<=0 || dia>31)
    {
        printf("Data Inválida\nDigite o DIA Novamente\n");
        dia=scan();
    }
    printf("MÊS:\n");
    mes=scan();
    while(mes<=0 || mes>12)
    {
        printf("Data Inválida\nDigite o MÊS Novamente\n");
        mes=scan();
    }
    printf("ANO:\n");
    ano=scan();
    while(ano<=2000 || dia>3000)
    {
        printf("Data Inváida\nDigite o ANO Novamente\n");
        ano=scan();
    }
    system("clear || cls");
    menutarefaop(); 
    for(i=0; i<qt; i++)
    {
        if(t[i]->dia==dia && t[i]->mes==mes && t[i]->ano==ano)
        {
        	ct++;
            printf("\t\t\t\t\t##########################\n\t\t\t\t\t##	TAREFA N°%d	##\n\t\t\t\t\t##########################\n\t\t\t\t\t--Nome: %s\n\t\t\t\t\t--Data: %d/%d/%d\n\t\t\t\t\t--Hora: %d:%d\n\t\t\t\t\t--Anotação: %s\n",i+1,t[i]->nome,t[i]->dia,t[i]->mes,t[i]->ano,t[i]->hora,t[i]->minuto,t[i]->nota);
        }
        if(t[i]->dia != dia && t[i]->mes != mes && t[i]->ano != ano)
        {
            printf("Não Existe Tarefas na Data Pesquisada\n");
        }

    }
    printf("TAREFAS NA DATA: %d/%d/%d : %d\n",dia,mes,ano,ct);
    printf("Deseja Fazer uma Nova busca?\n1->SIM\n2->NÃO\n");
    op=scan();
    if(op==1)
        busca(t);
    if(op==2)
    {
        printf("Deseja voltar para o Menu Principal?\n1->SIM\n2->NÃO\n");
        opt=scan();
        switch(opt)
        {
        case 1:
            menu(t);
            break;
        case 2:
            exit(1);
            break;
        }
    }
}
void salvar(Tarefas** t)
{
    quantidade(t);
    arqt = fopen("tarefas.bin","wb");
    if (arqt == NULL)
    {
        printf("Problemas na CRIAÇÃO do arquivo\n");
        exit(1);
    }
    for(i=0; i<qt; i++)
    {
        if(t[i]!=NULL)
            result = fprintf(arqt,"%s\t %d %d %d %d %d %s\n",t[i]->nome,t[i]->dia,t[i]->mes,t[i]->ano,t[i]->hora,t[i]->minuto,t[i]->nota);
    }
    if (result == EOF)
        printf("Erro na Gravação\n");
    fclose(arqt);
}
void editar(Tarefas** t)
{
    int tnum,b,bi=0;
    system("clear || cls");
    menutarefaop();
    quantidade(t);
    if(qt<=0)
    {
        printf("ERRO\n Não existe Tarefas\n");
        printf("Deseja voltar para o Menu Principal?\n1->SIM\n2->NÃO\n");
        opt=scan();
        switch(opt)
        {
        case 1:
            menu(t);
            break;
        case 2:
            exit(1);
            break;
        }
    }
    if(qt>0)
    {
        for(i=0; i<qt; i++)
        {
            printf("\t\t\t\t\t##########################\n\t\t\t\t\t##	TAREFA N°%d	##\n\t\t\t\t\t##########################\n\t\t\t\t\t--Nome: %s\n\t\t\t\t\t--Data: %d/%d/%d\n\t\t\t\t\t--Hora: %d:%d\n\t\t\t\t\t--Anotação: %s\n",i+1,t[i]->nome,t[i]->dia,t[i]->mes,t[i]->ano,t[i]->hora,t[i]->minuto,t[i]->nota);
        }
    }
    printf("Qual tarefa você deseja Editar?\nDigite o Número da Tarefa\n");
    tnum=scan();
    while(tnum <=0 || tnum > qt)
    {
    	printf("ERRO NÃO VAI DÁ NÃO\nDIGITE NUMERO DA TAREFA\n");
    	tnum=scan();
	}
    if(t[tnum-1]!=NULL)
    {
        free(t[tnum-1]);
        t[tnum-1]=NULL;
        t[tnum-1]=(Tarefas*)malloc(sizeof(Tarefas));
    }
    printf("Digite o Nome da Tarefa\n");
    scanf(" %50[^\n]",t[tnum-1]->nome);
    logteclas(t[tnum-1]->nome);
    printf("Digite o Dia\n");
    t[tnum-1]->dia=scan();
    while(t[tnum-1]->dia <=0 || t[tnum-1]->dia > 31)
    {
        printf("Valor inválido\nDigite do Dia\n");
        t[tnum-1]->dia=scan();
    }
    printf("Digite o Mês\n");
    t[tnum-1]->mes=scan();
    while(t[tnum-1]->mes <=0 || t[tnum-1]->mes >12  )
    {
        printf("Valor inválido\nDigite do Mês\n");
        t[tnum-1]->mes=scan();
    }
    printf("Digite o Ano\n");
    t[tnum-1]->ano=scan();
    while(t[tnum-1]->ano < 1900)
    {
        printf("Valor inválido\nDigite do Ano\n");
        t[tnum-1]->ano=scan();
    }
    b=t[tnum-1]->ano;
    if(b%400==0)
        bi++;
    if(b%4==0)
        bi++;
    if(b%100==0)
        bi++;
    while(t[tnum-1]->dia >28 && t[tnum-1]->mes==2 && bi==0)
    {
        printf("Data Inválida\nANO NÃO BISSEXTO\nDigite o DIA o MÊS e o ANO novamente\n");
        printf("Digite o DIA:\n");
        t[tnum-1]->dia=scan();
        printf("Digite o MÊS:\n");
        t[tnum-1]->mes=scan();
        printf("Digite o ANO:\n");
        t[tnum-1]->ano=scan();
    }
    printf("Digite A Hora\n");
    t[tnum-1]->hora=scan();
    while(t[tnum-1]->hora > 23)
    {
        printf("Valor inválido\nDigite a Hora\n");
        t[tnum-1]->hora=scan();

    }
    printf("Digite o Minuto\n");
    t[tnum-1]->minuto=scan();
    while(t[tnum-1]->minuto > 59)
    {
        printf("Valor inválido\nDigite o Minuto\n");
        t[tnum-1]->minuto=scan();
    }
    printf("Digite uma Anotação\n");
    scanf(" %399[^\n]",t[tnum-1]->nota);
    logteclas(t[tnum-1]->nota);
    system("clear || cls");
    menutarefaop();
    printf("Tarefa EDITADA!\n");
    printf("Deseja editar outra Tarefa?\n1->SIM\n2->NÃO\n");
    op=scan();
    switch(op)
    {
		case 1:
    		salvar(t);
        	editar(t);
        	break;
    	case 2:
        	printf("\n\nDeseja voltar para o Menu Principal?\n1->SIM\n2->NÃO\n");
        	opt=scan();
	        if(opt==1)
    	    {
	            salvar(t);
	        	carregar(t);
	        	menu(t);	
	        }
	        if(opt==2)
	        {
	            exit(1);
	    	}
	            break;
		default:
			system("pause");
			break;
	}
}
void apagar(Tarefas** t)
{
    int tnum;
    system("clear || cls");
    quantidade(t);
    menutarefaop();
    if(qt>0)
    {
        for(i=0; i<qt; i++)
        {
            if(t[i]!=NULL)
                printf("\t\t\t\t\t##########################\n\t\t\t\t\t##	TAREFA N°%d	##\n\t\t\t\t\t##########################\n\t\t\t\t\t--Nome: %s\n\t\t\t\t\t--Data: %d/%d/%d\n\t\t\t\t\t--Hora: %d:%d\n\t\t\t\t\t--Anotação: %s\n",i+1,t[i]->nome,t[i]->dia,t[i]->mes,t[i]->ano,t[i]->hora,t[i]->minuto,t[i]->nota);
        }
    }
    if(qt<=0)
    {
        printf("ERRO\n Não existe Tarefas\n");
        printf("Deseja voltar para o Menu Principal?\n1->SIM\n2->NÃO\n");
        opt=scan();
        switch(opt)
        {
        case 1:
            menu(t);
            break;
        case 2:
            exit(1);
            break;
        }
    }

    printf("Qual tarefa você deseja Apagar?\nDigite o Número da Tarefa\n");
    tnum=scan();
    while(tnum-1<0 || tnum-1>qt+MAX || t[tnum-1]==NULL || tnum>qt)
    {
        printf("ERRO\n Tarefa Não Existe\nDigite o Numero da Tarefa\n");
        tnum=scan();
    }
    free(t[tnum-1]);
    t[tnum-1]=NULL;
    printf("Tarefa Apagada!\n");
    quantidade(t);
    printf("Deseja apagar outra Tarefa?\n1->SIM\n2->NÃO\n");
    op=scan();
    if(op==1)
    {
        salvar(t);
        carregar(t);
        apagar(t);
    }
    if(op==2)
    {
        salvar(t);
        printf("Deseja voltar para o Menu Principal?\n1->SIM\n2->NÃO\n");
        opt=scan();
        if(opt==1)
        {
        	carregar(t);
            menu(t);
        }
        if(opt==2)
            exit(1);
    }
}
void exibirtarefa(Tarefas** t)
{
    int i;
    quantidade(t);
    system("clear || cls");
    menutarefaop();
    for(i=0; i<qt; i++)
    {
        printf("\t\t\t\t\t##########################\n\t\t\t\t\t##	TAREFA N°%d	##\n\t\t\t\t\t##########################\n\t\t\t\t\t--Nome: %s\n\t\t\t\t\t--Data: %d/%d/%d\n\t\t\t\t\t--Hora: %d:%d\n\t\t\t\t\t--Anotação: %s\n",i+1,t[i]->nome,t[i]->dia,t[i]->mes,t[i]->ano,t[i]->hora,t[i]->minuto,t[i]->nota);
    }
    printf("\n\nDeseja voltar para o Menu Principal?\n1->SIM\n2->NÃO\n");
    op=scan();
    switch(op)
    {
    case 1:
        menu(t);
    case 2:
        exit(1);
    default:
        printf("Valor inválido\n");
        break;
    }
}
void addtarefa(Tarefas** t)
{
    int bi=0,b;
    quantidade(t);
    if(qt==0)
    {
        qt=1;
    }
    i=qt-1;
    system("clear || cls");
    menutarefaop();
    if(t[i]!=NULL)
        t[i]=NULL;
    t[i]=(Tarefas*)malloc(sizeof(Tarefas));
    printf("Digite o Nome da Tarefa\n");
    scanf(" %50[^\n]",t[i]->nome);
    strupr(t[i]->nome);
    logteclas(t[i]->nome);
    printf("Digite o Dia\n");
    t[i]->dia=scan();
    while(t[i]->dia <=0 || t[i]->dia > 31)
    {
        printf("Valor inválido\nDigite o Dia\n");
        t[i]->dia=scan();
    }
    printf("Digite o Mês\n");
    t[i]->mes=scan();
    while(t[i]->mes <=0 || t[i]->mes >12  )
    {
        printf("Valor inválido\nDigite o Mês\n");
        t[i]->mes=scan();
    }
    printf("Digite o Ano\n");
    t[i]->ano=scan();
    while(t[i]->ano < 2000 || t[i]->ano >3000)
    {
        printf("Valor inválido\nDigite o Ano\n");
        t[i]->ano=scan();
    }
    b=t[i]->ano;
    if(b%400==0)
        bi++;
    if(b%4==0)
        bi++;
    if(b%100==0)
        bi++;
    while(t[i]->dia >28 && t[i]->mes==2 && bi==0)
    {
        printf("Data Inválida\nANO NÃO BISSEXTO\nDigite o DIA o MÊS e o ANO novamente\n");
        printf("Digite o DIA:\n");
        t[i]->dia=scan();
        printf("Digite o MÊS:\n");
        t[i]->mes=scan();
        printf("Digite o ANO:\n");
        t[i]->ano=scan();
         b=t[i]->ano;
    	if(b%400==0)
        	bi++;
    	if(b%4==0)
        	bi++;
    	if(b%100==0)
	        bi++;
    }
    printf("Digite A Hora\n");
    t[i]->hora=scan();
    while(t[i]->hora > 23)
    {
        printf("Valor inválido\nDigite a Hora\n");
        t[i]->hora=scan();
    }
    printf("Digite o Minuto\n");
    t[i]->minuto=scan();
    while(t[i]->minuto > 59)
    {
        printf("Valor inválido\nDigite o Minuto\n");
        t[i]->minuto=scan();
    }
    printf("Digite uma Anotação\n");
    scanf(" %399[^\n]",t[i]->nota);
    strupr(t[i]->nota);
    logteclas(t[i]->nota);
    
    arqt = fopen("tarefas.bin","ab");
    if (arqt == NULL)
    {
        printf("Problemas na CRIAÇÃO do arquivo\n");
        exit(1);
    }
    result = fprintf(arqt,"%s\t %d %d %d %d %d %s\n",t[i]->nome,t[i]->dia,t[i]->mes,t[i]->ano,t[i]->hora,t[i]->minuto,t[i]->nota);
    if (result == EOF)
        printf("Erro na Gravação\n");
    fclose(arqt);
    system("clear|| cls");
    menutarefaop();
    printf("Tarefa Adicionada!\n");
    printf("Deseja Adicinar Outra Tarefa?\n1->SIM\n2->NÃO\n");
    op=scan();
    switch(op)
    {
    case 1:
    	quantidade(t);
        carregar(t);
        addtarefa(t);
        break;
    case 2:
    	carregar(t);
        menu(t);
        break;
    default:
        printf("Valor inválido\n");
        break;
    }
}
void menu(Tarefas** t)
{
    system("clear || cls");
    menutarefa();
    opt=scan();
    switch(opt)
    {
	    case 1:
            addtarefa(t);
            break;
        case 2:
            if(qt==0)
            {
                printf("Não Existem Tarefas\n Deseja Adicionar Uma?\n1->SIM\n2->NãO\n");
                op=scan();
                if(op==1)
                    addtarefa(t);
                if(op==2)
                    exit(1);
            }
            exibirtarefa(t);
            break;
        case 3:
            editar(t);
            break;
        case 4:
            apagar(t);
            break;
        case 5:
            busca(t);
            break;
        case 6:
            exit(1);
            break;
        case 7:
        	eventos(t);
        	break;
        default:
            printf("Valor inválido\n");
            break;
	}
	if(op==2)
    	exit(1);
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	Tarefas* t[MAX+qt];
	system("clear || cls");
	inicializar(t);
	menu(t);
	return 0;
}

