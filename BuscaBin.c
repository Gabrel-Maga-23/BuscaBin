#include <stdio.h>  

#include <string.h>  

typedef struct _Endereco Endereco;  

struct _Endereco  

{  


char logradouro[72];  

char bairro[72];  

char cidade[72];  

char uf[72];  

char sigla[2];  

char cep[8];  

char lixo[2]; // Ao Espaço no final da linha + quebra de linha  

};  


int main(int argc, char**argv)  

{  

FILE *f;  

Endereco e;  

long comeco=0;  

long fim;  

long meio;  

if(argc != 2)  

{  

fprintf(stderr, "USO: %s [CEP]", argv[0]);  

return 1;  

}  

f = fopen("cep_ordenadoRJ.dat","rb");  

fseek(f,0,SEEK_END); 

fim = ftell(f); 

fim=fim/sizeof(Endereco); 


while(comeco <= fim)  

{  

meio = (fim+comeco)/2;  

fseek(f,meio*sizeof(Endereco),SEEK_SET);  

fread(&e,sizeof(Endereco),1,f);  

if(strncmp(argv[1], e.cep, 8) == 0){ printf("\nAchou\n\n"); break;}  

if(strncmp(argv[1], e.cep, 8) < 0) {  

fim = meio - 1;  

}  

if(strncmp(argv[1], e.cep, 8) > 0) {  

comeco = meio + 1;  


}  

}  


printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);  

 
fclose(f);  



} 