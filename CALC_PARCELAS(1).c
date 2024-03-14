#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    
    setlocale(LC_ALL, "Portuguese_Brazil");
    
//iniciando vari�veis 

    float jurosMes2,jurosMes, jurosDia, multa, parcela = 0;
    int numParcelas, diasVencidos, mesesVencidos = 0;
    
//recebe o valor da parcela 
    
    printf("Insira o valor da parcela: \n ");
    scanf("%f", &parcela);
    
    jurosMes2 = 0.1 * parcela;
    multa = 0.02 * parcela;
    
//recebe os dias, meses vencidos 
    
    printf("Dias vencidos: \n");
    scanf("%d", &diasVencidos);
    
    printf("Meses vencidos: \n");
    scanf("%d", &mesesVencidos);
    
    printf("Parcelas atrasadas: \n");
    scanf("%d", &numParcelas);
    
//checa se os dois valores est�o zerados ou se um deles � negativo
    
    if(diasVencidos < 0 || mesesVencidos < 0){
            printf("Algum dos valores est� inv�lido.\n");
    }
        
    if(diasVencidos == 0 && mesesVencidos == 0){
        printf("Valores zerados, insira os valores novamente.");
    }
    
//faz o calculo dos juros por dia e por mes 
        
    if(diasVencidos > 0){
        
        jurosDia = 0.1 * parcela;   
        jurosDia /= 30;
        jurosDia *= diasVencidos;
    }
    
    else if(diasVencidos==0){
        jurosDia = 0;
    }
    
    if(mesesVencidos >= 1){
        
        jurosMes = (0.1 * parcela)*mesesVencidos;
    }
    
    
    else if(mesesVencidos == 0){
        jurosMes = 0;
    } 
    
    parcela += jurosMes + jurosDia + multa;
    
     printf("Valor da parcela 1 �: %.2f \n", parcela);
     
    
//exibi��o de cada uma das parcelas  
    
    for(int i = 2; i <= numParcelas; i++){
        
        parcela -= jurosMes2;
        printf("O valor da parcela %d �: %.2f \n", i, parcela);
    }

    system("pause");
    return 0;
}
