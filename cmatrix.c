#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <time.h>

struct cmatrix {
	char ***chars;
	int **y;
};

int main(){
	
	int linha;
	int coluna;
	char c;

	// Hiragana: caracteres básicos do gojūon
	char *hiragana[] = {
	    "あ", "い", "う", "え", "お",     // a i u e o
	    "か", "き", "く", "け", "こ",     // ka ki ku ke ko
	    "さ", "し", "す", "せ", "そ",     // sa shi su se so
	    "た", "ち", "つ", "て", "と",     // ta chi tsu te to
	    "な", "に", "ぬ", "ね", "の",     // na ni nu ne no
	    "は", "ひ", "ふ", "へ", "ほ",     // ha hi fu he ho
	    "ま", "み", "む", "め", "も",     // ma mi mu me mo
	    "や",       "ゆ",       "よ",     // ya    yu    yo
	    "ら", "り", "る", "れ", "ろ",     // ra ri ru re ro
	    "わ",             "を",           // wa       (w)o
	    "ん"                              // n
	};

	// Katakana: caracteres equivalentes em katakana
	char *katakana[] = {
	    "ア", "イ", "ウ", "エ", "オ",
	    "カ", "キ", "ク", "ケ", "コ",
	    "サ", "シ", "ス", "セ", "ソ",
	    "タ", "チ", "ツ", "テ", "ト",
	    "ナ", "ニ", "ヌ", "ネ", "ノ",
	    "ハ", "ヒ", "フ", "ヘ", "ホ",
	    "マ", "ミ", "ム", "メ", "モ",
	    "ヤ",       "ユ",       "ヨ",
	    "ラ", "リ", "ル", "レ", "ロ",
	    "ワ",             "ヲ",
	    "ン"
	};



	char *charac[] = {
		"A", "B", "C", "D", "E", "F", "G", "H"
	};

	setlocale(LC_ALL, "en_US.UTF-8");
	srand(time(NULL)); // time(storeVar), null means "not store"

	struct cmatrix matrix;
	// lenght 15 estava adcionando um a mais ao final, n sei por que
	int lenght = 35;

	initscr();
	noecho();
	
	getmaxyx(stdscr, linha, coluna);

	// aloca memoria igual ao numero de colunas

	matrix.chars = (char***)malloc(coluna*sizeof(char*));
	matrix.y = (int**)malloc(coluna*sizeof(int*));


	// cria a estrutura completa
	for(int i = 0; i < coluna; i++){
	
		matrix.chars[i] = (char**)malloc(lenght*sizeof(char*));
		matrix.y[i] = (int*)malloc(coluna*sizeof(int*));

		for(int j = 0; j < lenght; j++){

			matrix.chars[i][j] = charac[rand() % (sizeof(charac)/sizeof(charac[0]))];
			if(j == 0){
				matrix.y[i][j] = -(rand() % lenght);
			} else if(j % 4 == 0){ 
			        matrix.y[i][j] = matrix.y[i][0]+=2;
			} else {
				matrix.y[i][j] = matrix.y[i][0]++;
			}
		}	
	
	}

	while(1){
		// imprime os chars
		clear();
		for(int i = 0; i < coluna; i+=2){
			int next = 1;
			for(int j = 0; j < lenght; j++){
				
				matrix.y[i][j]++;
				if(matrix.y[i][j] > linha){ matrix.y[i][j] = 0; } 

				if(j != lenght-1){
				
					matrix.chars[i][j] = matrix.chars[i][next];
					next++;	
				} else {
					matrix.chars[i][j] = charac[(rand() % (sizeof(charac)/sizeof(charac[0])))];
				}
				

				mvprintw(matrix.y[i][j], i, matrix.chars[i][j]);
			}
		}
		usleep(55000);
		refresh();
	}

	endwin();

	/*
	 * função que retorna um char aleatorio de um array x
	 * garantir que a memoria esteja sendo usada (sem espaços vazios ou desperdícios)
	 * desbagunçar o código, fazendo um programa mais fácil de ler
	 * fazer um cmatrix mais responsivo, com possibilidade de alterar
	 * 	- número de chars na coluna
	 * 	- cor
	 * 	- resize (de forma que uma janela menor ao virar maior aceite mais colunas);
	 */

	return 0;
}

