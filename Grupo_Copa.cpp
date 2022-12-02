#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>


struct time{
	int codigoTime;
	char nomeTime[20];
	int pontuacao;
	int saldoGol;
	int classificacao;
};
struct time times[4];
int codigo=1;
menu(){
	system("cls");
	printf("\n1-Cadastrar Time");
	printf("\n2-Lan�ar Jogos");
	printf("\n3-Classifica��o\n");
}
cadastrarTime(){
	int x;
	for(x=0;x<4;x++){
		times[x].codigoTime=codigo;
		printf("\nDigite o nome do time %d: ",codigo);
		fflush(stdin);
		gets(times[x].nomeTime);
		codigo++;
			
	}
		
}
lancarJogos(){
	int time,desafiante,golT,golD;
	for(time=0;time<4;time++){
		for(desafiante=time;desafiante<4;desafiante++){
			if(time!=desafiante){
				printf("\nDigite quantidade de gols time %s partida %s X %s: ",times[time].nomeTime,times[time].nomeTime,times[desafiante].nomeTime);
				scanf("%d",&golT);
				printf("\nDigite quantidade de gols desafiante %s: ",times[desafiante].nomeTime);
				scanf("%d",&golD);
				times[time].saldoGol+=golT;
				times[desafiante].saldoGol+=golD;
				if(golT>golD){
					times[time].pontuacao+=3;
				}else if(golD>golT){
					times[desafiante].pontuacao+=3;
				}else{
					times[time].pontuacao+=1;
					times[desafiante].pontuacao+=1;
				}
			}
			
		}
	}
}
void apurar(){
	int time,desafiante,posicao=0;
	for(time=0;time<4;time++){
		posicao=0;
		for(desafiante=0;desafiante<4;desafiante++){
			if(time!=desafiante){
				if(times[time].pontuacao>times[desafiante].pontuacao){
					if(times[time].saldoGol>times[desafiante].saldoGol){
					   posicao++;
					}
				
				}else if(times[time].pontuacao==times[desafiante].saldoGol){
					posicao++;
				}
				
			}
		}
		switch(posicao){
			case 0:
				times[time].classificacao=4;
				break;
			case 1:
				times[time].classificacao=3;
				break;
			case 2:
				times[time].classificacao=2;
				break;
			case 3:
				times[time].classificacao=1;
				break;
		}
		
	}
	
	
}
void listar(){
	int time,desafiante;
	for(time=0;time<4;time++){
		for(desafiante=time;desafiante<4;desafiante++){
			if(time!=desafiante){
				if(time[times].classificacao>times[desafiante].classificacao){
					printf("\n***********************************\n");
				    printf("\ncodigo: %d",times[time].codigoTime);
			        printf("\nnome: %s",times[time].nomeTime);
		        	printf("\npontua��o: %d",times[time].pontuacao);
			        printf("\nsaldo de gol: %d",times[time].saldoGol);
			        printf("\nclassifica��o: %d",times[time].classificacao);
	}
			}
				}
				
		}
	
	system("pause");
}

main(){
	setlocale(LC_ALL, "Portuguese");
	int op;
	do{
		menu();
		scanf("%d",&op);
		switch(op){
			case 1:
				cadastrarTime();
			break;
			case 2:
				lancarJogos();
			break;
			case 3:
				listar();
			break;
		}
	}while(op!=0);
	
	
	
	return 0;
}

