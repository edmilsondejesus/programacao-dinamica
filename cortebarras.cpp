/*
######################################################################
##																	##
##		Programação Dinâmica										##
##																	##
##																	##
######################################################################

A fábrica VAII (Vergalhões de Aço para a Indústria Imobiliária) fornece vergalhões de aço de diferentes tamanhos. O preço de um vergalhão tamanho t_i \in \{1,2,\ldots,t\} depende de condições de mercado e custo de fabricação e pode se modificar com frequência. Ajude a direção da fábrica VAII a otimizar o lucro da empresa. Para tanto, é necessário programar uma solução usada pela máquina de corte, que recebe um vergalhão de tamanho t  e fornece os cortes deste vergalhão em seguimentos de forma que o preço total das vendas é maximizado de acordo com os valores listados num vetor V. A implementação de sua solução pode estar em qualquer linguagem. Use a Programação Dinâmica para elaborá-la.

Como entrada do programa, o vetor de valores V = \{v_1,v_2,\ldots,v_t\} é fornecido.

Exemplo 1 de entrada (representando um vergalhão de entrada de tamanho 6 com valores correspondentes a vergalhões de tamanho 1,2,3,...6):

{4, 15, 18, 19, 25, 23}

Saída 1: Valor máximo de venda 45. Três vergalhões de tamanho 2.

Exemplo 2 de entrada:

{4, 5, 5, 11, 22, 23, 25, 29, 30, 35, 35, 38}

Saída 2: Valor máximo de venda 52. Dois vergalhões de tamanho 1 e dois vergalhões de tamanho 5.

Após verificar a correção de seu programa, considere a seguinte entrada para responder este questionário.

{11,27,31,41,31,77,55,57,87,103,123,150,131,79,210,177,145,258,190,277,163,149,177,121,215,179,295,203,362,306,139,278,330,406,441,318,321,252,562,533,414,398,275,715,496,394,448,413,818,269,750,703,642,441,128,357,546,700,660,719,556,505,570,735,840,442,1002,854,818,677,866,1228,458,1073,706,858,795,776,645,810,1112,1133,1120,914,841,617,1045,651,1065,637,910,651,748,1035,1426,1229,1169,990,964,1061,1444,1174,1062,711,945,323,760,404,1504,624,1215,1510,913,858,1264,618,1141,1373,1213,861,1234,759,1027,1393,1390,1634,1087,1525,1502,766,1199,1376,849,1945,1413,1309,1074,1049,2353,1476,1629,2031,2405,1756,1475,2168,1612,2258,1856,1127,1578,1331,2006,1485,1524,1984,1434,637,1384,2274,1429,1944,393,2369,1711,2185,1207,1667,1397,1792,805,1613,1719,1726,1861,1219,2425,1287,1752,1896,1553,2009,2159,3101,1496,2224,1806,1866,2174,1967,1428,3401,986,1512,2871,1303,1626,1678,1343,2270}
*/
#include <iostream>
#include <stdio.h>    
#include <stdlib.h>
#include <math.h>  
#include<locale.h>

int CorteBarrasBU(int n, int P[], int B[],int S[]) {
       int valor;
       B[0] = 0;
       for (int k=1; k<=n; k++){
           int lucro = -1;
           for (int i=1; i<=k; i++){
           		valor = P[i-1]+B[k-i];
           		if(valor > lucro){
           				lucro = valor;
           				S[k]=i;
				   }               
           }
           B[k] = lucro;
       }
       
       return 1;
   }

int main() {

	int n=200;
	
	setlocale(LC_ALL, "Portuguese");

	/* vetor de preços das barras */
	/* Exemplo 1 pró carla  co n=6 e vetor abaixo
	int P[6]={1,3,11,16,19,10};*/
	
	/*Exemplo 1 prof George  entrada (representando um vergalhão de entrada de tamanho 6 com valores correspondentes a vergalhões de tamanho 1,2,3,...6):
	int P[6]={4, 15, 18, 19, 25, 23};
	Saída 1: Valor máximo de venda 45. Três vergalhões de tamanho 2.
	*/
	/*Exemplo 2 prof Gerorge entrada: 
	int P[n]={4, 5, 5, 11, 22, 23, 25, 29, 30, 35, 35, 38};
	Saída 2: Valor máximo de venda 52. Dois vergalhões de tamanho 1 e dois vergalhões de tamanho 5.
	*/

	/* Entrada para o questionário, prof George */
	int P[n]={11,27,31,41,31,77,55,57,87,103,123,150,131,79,210,177,145,258,190,277,163,149,177,121,215,179,295,203,362,306,139,278,330,406,441,318,321,252,562,533,414,398,275,715,496,394,448,413,818,269,750,703,642,441,128,357,546,700,660,719,556,505,570,735,840,442,1002,854,818,677,866,1228,458,1073,706,858,795,776,645,810,1112,1133,1120,914,841,617,1045,651,1065,637,910,651,748,1035,1426,1229,1169,990,964,1061,1444,1174,1062,711,945,323,760,404,1504,624,1215,1510,913,858,1264,618,1141,1373,1213,861,1234,759,1027,1393,1390,1634,1087,1525,1502,766,1199,1376,849,1945,1413,1309,1074,1049,2353,1476,1629,2031,2405,1756,1475,2168,1612,2258,1856,1127,1578,1331,2006,1485,1524,1984,1434,637,1384,2274,1429,1944,393,2369,1711,2185,1207,1667,1397,1792,805,1613,1719,1726,1861,1219,2425,1287,1752,1896,1553,2009,2159,3101,1496,2224,1806,1866,2174,1967,1428,3401,986,1512,2871,1303,1626,1678,1343,2270};
	/*
	Saída encontrada:
	Corte de barras!
Vetor P com n=200
 11 27 31 41 31 77 55 57 87 103 123 150 131 79 210 177 145 258 190 277 163 149 177 121 215 179 295 203 362 306 139 278 330 406 441 318 321 252 562 533 414 398 275 715 496 394 448 413 818 269 750 703 642 441 128 357 546 700 660 719 556 505 570 735 840 442 1002 854 818 677 866 1228 458 1073 706 858 795 776 645 810 1112 1133 1120 914 841 617 1045 651 1065 637 910 651 748 1035 1426 1229 1169 990 964 1061 1444 1174 1062 711 945 323 760 404 1504 624 1215 1510 913 858 1264 618 1141 1373 1213 861 1234 759 1027 1393 1390 1634 1087 1525 1502 766 1199 1376 849 1945 1413 1309 1074 1049 2353 1476 1629 2031 2405 1756 1475 2168 1612 2258 1856 1127 1578 1331 2006 1485 1524 1984 1434 637 1384 2274 1429 1944 393 2369 1711 2185 1207 1667 1397 1792 805 1613 1719 1726 1861 1219 2425 1287 1752 1896 1553 2009 2159 3101 1496 2224 1806 1866 2174 1967 1428 3401 986 1512 2871 1303 1626 1678 1343 2270
Vetor B
 0 11 27 38 54 65 81 92 108 119 135 146 162 173 189 210 221 237 258 269 285 296 312 323 339 350 366 377 393 404 420 431 447 468 479 495 516 527 543 562 573 589 600 616 715 726 742 753 769 818 829 845 856 872 883 899 910 926 937 953 964 980 991 1007 1028 1039 1055 1076 1087 1103 1114 1130 1228 1239 1255 1266 1282 1293 1309 1320 1336 1347 1363 1374 1390 1401 1417 1438 1449 1465 1486 1497 1513 1533 1544 1560 1571 1587 1636 1647 1663 1674 1690 1701 1717 1728 1744 1755 1771 1782 1798 1809 1825 1846 1857 1873 1943 1954 1970 1981 1997 2046 2057 2073 2084 2100 2111 2127 2138 2154 2165 2181 2192 2208 2219 2235 2256 2267 2283 2353 2364 2380 2391 2407 2456 2467 2483 2494 2510 2521 2537 2548 2564 2575 2591 2602 2618 2629 2645 2666 2677 2693 2714 2725 2741 2761 2772 2788 2799 2815 2864 2875 2891 2902 2918 2929 2945 2956 2972 2983 2999 3010 3026 3068 3101 3112 3128 3139 3171 3182 3198 3209 3401 3412 3428 3439 3455 3466 3482 3493 3509
Vetor S
 0 1 2 1 2 1 2 1 2 1 2 1 2 1 2 15 1 2 18 1 2 1 2 1 2 1 2 1 2 1 2 1 2 15 1 2 18 1 2 39 1 2 1 2 44 1 2 1 2 49 1 2 1 2 1 2 1 2 1 2 1 2 1 2 15 1 2 18 1 2 1 2 72 1 2 1 2 1 2 1 2 1 2 1 2 1 2 15 1 2 18 1 2 44 1 2 1 2 49 1 2 1 2 1 2 1 2 1 2 1 2 1 2 15 1 2 44 1 2 1 2 49 1 2 1 2 1 2 1 2 1 2 1 2 1 2 15 1 2 139 1 2 1 2 72 1 2 1 2 1 2 1 2 1 2 1 2 1 2 15 1 2 18 1 2 44 1 2 1 2 49 1 2 1 2 1 2 1 2 1 2 1 2 44 184 1 2 1 44 1 2 1 192 1 2 1 2 1 2 1 2
Corte ótimo para barra de tamanho 200:
Lucro máximo: 3509
P1=2 + P2=2 + P3=2 + P4=2 + P5=192
--------------------------------
*/

	/* vetor de tamanho das barras */
    int B[n+1];
    /* Vetor de melhor solução por barra */
    int S[n+1];

	
	for(int l=0;l <n; l++){
		B[l]=0;
		S[l]=0;
	}
	
	printf("Corte de barras!\n");
	
	CorteBarrasBU(n, P, B, S) ;


	printf("Vetor P com n=%d\n",n);
	for(int l=0;l <n; l++){
		printf(" %d",P[l]);
	}
	printf("\n");


	printf("Vetor B \n");

	for(int l=0;l <=n; l++){
		printf(" %d",B[l]);
	}
	printf("\n");

	printf("Vetor S \n");
	for(int l=0;l <=n; l++){
		printf(" %d",S[l]);
	}
	printf("\n");
	
		printf("Corte ótimo para barra de tamanho %d:\n",n);
		
		printf("Lucro máximo: %d \n",B[n]);
		int i =1;
		int p=n;
	int max = 0;	
	while ( n > 0){
		if(max < S[n])
			max = S[n];
		if(i>1) printf(" + ");
		printf("P%d= (%d => %d )",i, S[n], P[S[n]-1]);		
		n = n - S[n];
		
		i++;
	}	
	printf("\n");
	printf("Tamanho do maior vergalhão: %d\n",max);
	printf("\n");
		
	/* Espera o usuário digitar algo.*/
	int tecla;
	std::cin >> tecla;
	return 0;
}
