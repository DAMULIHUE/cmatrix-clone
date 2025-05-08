#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <time.h>

typedef struct {
	int y;
	char *chars;
} matrix;


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
	setlocale(LC_ALL, "en_US.UTF-8");
	srand(time(NULL)); // time(storeVar), null means "not store"

	initscr();
	noecho();

	while(1){
		
		getmaxyx(stdscr, linha, coluna);
		
		for(int i = 0; i < coluna; i++){
			matrix **cmatrix.chars = rand() % (46)
		}
	}

	endwin();

	return 0;
}
