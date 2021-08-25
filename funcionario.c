#include "funcionario.h"
#include "cliente.h"

    int lugar1[5];
    int lugar2[2];
    char lugar3[2];
    char filme[5][50];
    char bilhetefilme[5][50];
    int numero, qtd_ingresso;
    int numsala[5] = {0, 0, 0, 0, 0};
    int valorsala[5] = {0, 0, 0, 0, 0};
    char nome[20];
    int sala;
    int opcaoglobal;

    char filmeatual[50];

    int salaA=0, salaB=0, salaC=0, salaD=0, salaE=0;
    int lotado=0;
    char sala1[8][10] = {
    '@','@','@','@','@','@','@','@', '@', '@',
    '@','@','@','@','@','@','@','@', '@', '@',
    ' ','@','@','@','@','@','@','@', '@', ' ',
    ' ','@','@','@','@','@','@','@', '@', ' ',
    ' ',' ','@','@','@','@','@','@', ' ', ' ',
    ' ',' ','@','@','@','@','@','@', ' ', ' ',
    ' ',' ',' ','@','@','@','@',' ', ' ', ' ',
    ' ',' ',' ',' ','@','@',' ',' ', ' ', ' ',
    };
    
    char sala2[8][10] = {
    '@','@','@','@','@','@','@','@', '@', '@',
    '@','@','@','@','@','@','@','@', '@', '@',
    ' ','@','@','@','@','@','@','@', '@', ' ',
    ' ','@','@','@','@','@','@','@', '@', ' ',
    ' ',' ','@','@','@','@','@','@', ' ', ' ',
    ' ',' ','@','@','@','@','@','@', ' ', ' ',
    ' ',' ',' ','@','@','@','@',' ', ' ', ' ',
    ' ',' ',' ',' ','@','@',' ',' ', ' ', ' ',
    };

    char sala3[8][10] = {
    '@','@','@','@','@','@','@','@', '@', '@',
    '@','@','@','@','@','@','@','@', '@', '@',
    ' ','@','@','@','@','@','@','@', '@', ' ',
    ' ','@','@','@','@','@','@','@', '@', ' ',
    ' ',' ','@','@','@','@','@','@', ' ', ' ',
    ' ',' ','@','@','@','@','@','@', ' ', ' ',
    ' ',' ',' ','@','@','@','@',' ', ' ', ' ',
    ' ',' ',' ',' ','@','@',' ',' ', ' ', ' ',
    };

    char sala4[8][10] = {
    '@','@','@','@','@','@','@','@', '@', '@',
    '@','@','@','@','@','@','@','@', '@', '@',
    ' ','@','@','@','@','@','@','@', '@', ' ',
    ' ','@','@','@','@','@','@','@', '@', ' ',
    ' ',' ','@','@','@','@','@','@', ' ', ' ',
    ' ',' ','@','@','@','@','@','@', ' ', ' ',
    ' ',' ',' ','@','@','@','@',' ', ' ', ' ',
    ' ',' ',' ',' ','@','@',' ',' ', ' ', ' ',
    };

    char sala5[8][10] = {
    '@','@','@','@','@','@','@','@', '@', '@',
    '@','@','@','@','@','@','@','@', '@', '@',
    ' ','@','@','@','@','@','@','@', '@', ' ',
    ' ','@','@','@','@','@','@','@', '@', ' ',
    ' ',' ','@','@','@','@','@','@', ' ', ' ',
    ' ',' ','@','@','@','@','@','@', ' ', ' ',
    ' ',' ',' ','@','@','@','@',' ', ' ', ' ',
    ' ',' ',' ',' ','@','@',' ',' ', ' ', ' ',
    };
		

 void RemoveFilme(void){
   int max_x, max_y, maxY, maxX, sala;
    int meiox, qtd_ingresso;
    int ch, sair = 0, x = 0, y = 0, opcao = 4;
    int centro_x, centro_y;
    char nome[20], nomeFilme[50];
    WINDOW *win;

    initscr();
  
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; 

    //bordas
    for(x=max_x/4; x < 3 * max_x/4+1; x++){
        mvprintw(max_y/4-1,x, "-" ); 
        //mvprintw(3*max_y/4+1, x, "-");
    }
    mvwprintw(win,11, 0, "------------------------------------");


    refresh();

    mvwprintw(win, 0, meiox - 10, "CINE-IFB - Funcionario");
    mvwprintw(win, 2, 0, "Qual filme sera removido:"); 
    if(strcmp(filme[0], "\0")!=0){
      mvwprintw(win, 4, 2, " %s (Sala 1)", filme[0]);
    }if(strcmp(filme[1], "\0")!=0){
      mvwprintw(win, 5, 2, " %s (Sala 2)", filme[1]);
    }if(strcmp(filme[2], "\0")!=0){
      mvwprintw(win, 6, 2, " %s (Sala 3)", filme[2]);
    }if(strcmp(filme[3], "\0")!=0){
      mvwprintw(win, 7, 2, " %s (Sala 4)", filme[3]);
    }if(strcmp(filme[4], "\0")!=0){
      mvwprintw(win, 8, 2, " %s (Sala 5)", filme[4]);
    }

    //note que a linha 7 não existe, voce precisa saltar ela no loop while
    mvwprintw(win, 10, 2, "Voltar");
    wrefresh(win);
  
   while (!sair)
    {
        mvwprintw(win, opcao, 0, "->");
        wrefresh(win);
        ch = getch();

        switch (ch)
        {
        case KEY_DOWN:
            if (opcao != 10)
            { 
                mvwprintw(win, opcao, 0, "  ");
                opcao++;
                if(opcao == 9){ 
                    opcao = 10;
                }
            }
            else
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao = 4; 
            }
            break;
        case KEY_UP: 
            if (opcao != 4)
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao--;
                if(opcao == 9){
                    opcao = 8; 
                               
                }
                
            }
            else
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao = 10; 
            }
            break;
        case '\n':
            if (opcao == 10)
            {
              MenuFuncionario();
            }
            if (opcao == 4){
              strcpy(filme[0], "\0");
              valorsala[0] = 0;
              wclear(win);
              mvwprintw(win, 0, meiox - 10, "CINE-IFB - Funcionario");
              mvwprintw(win, 2, 0, "Filme removido com sucesso!");
              mvwprintw(win, 3, 0, "------------------------------------");
              wrefresh(win);
              sleep(3);
              MenuFuncionario();
            }else if(opcao==5){
              strcpy(filme[1], "\0");
              valorsala[1] = 0;
              wclear(win);
              mvwprintw(win, 0, meiox - 10, "CINE-IFB - Funcionario");
              mvwprintw(win, 2, 0, "Filme removido com sucesso!");
              mvwprintw(win, 3, 0, "------------------------------------");
              wrefresh(win);
              sleep(3);
              MenuFuncionario();
            }else if(opcao==6){
              strcpy(filme[2], "\0");
              valorsala[2] = 0;
              wclear(win);
              mvwprintw(win, 0, meiox - 10, "CINE-IFB - Funcionario");
              mvwprintw(win, 2, 0, "Filme removido com sucesso!");
              mvwprintw(win, 3, 0, "------------------------------------");
              wrefresh(win);
              sleep(3);
              MenuFuncionario();
            }else if(opcao==7){
              strcpy(filme[3], "\0");
              valorsala[3] = 0;
              wclear(win);
              mvwprintw(win, 0, meiox - 10, "CINE-IFB - Funcionario");
              mvwprintw(win, 2, 0, "Filme removido com sucesso!");
              mvwprintw(win, 3, 0, "------------------------------------");
              wrefresh(win);
              sleep(3);
              MenuFuncionario();
            }else{
              strcpy(filme[4], "\0");
              valorsala[4] = 0;
              wclear(win);
              mvwprintw(win, 0, meiox - 10, "CINE-IFB - Funcionario");
              mvwprintw(win, 2, 0, "Filme removido com sucesso!");
              mvwprintw(win, 3, 0, "------------------------------------");
              wrefresh(win);
              sleep(3);
              MenuFuncionario();
            }

            sair = 1;
        }
    }

    endwin(); //restaura o terminal padrão


    wrefresh(win);
   
    endwin(); //restaura o terminal padrão


 }

//#include "funcionario.h"

void MenuFuncionario(void){
  void TelaPrincipal (void);
  int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 4;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win

    for(x=max_x/4; x < 3 * max_x/4+1; x++){
        mvprintw(max_y/4-1,x, "-" );  
        //mvprintw(3*max_y/4+1, x, "-");//segunda linha
    }
    mvwprintw(win, 9, 0, "------------------------------------");


    refresh();

    mvwprintw(win, 0, meiox - 10, "CINE-IFB - Funcionario");
    mvwprintw(win, 2, 0, "Selecione uma opção"); 
    mvwprintw(win, 4, 2, "Cadastrar Filme");
    mvwprintw(win, 5, 2, "Remover Filme");
    mvwprintw(win, 6, 2, "Visualizar sala");
    
    mvwprintw(win, 8, 2, "Sair");
    wrefresh(win);

    while (!sair)
    {
        mvwprintw(win, opcao, 0, "->");
        wrefresh(win);
        ch = getch();

        switch (ch)
        {
        case KEY_DOWN:
            if (opcao != 8)
            { 
                mvwprintw(win, opcao, 0, "  ");
                opcao++;
                if(opcao == 7){ 
                    opcao = 8;
                }
            }
            else
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao = 4; 
            }
            break;
        case KEY_UP: 
            if (opcao != 4) 
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao--;
                if(opcao == 7){
                    opcao = 6; 
                }
            }
            else
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao = 8; 
            }
            break;
        case '\n':
            if (opcao == 4)
            {
              nomeFilme();
            }
            if(opcao == 6){
              VisualizaSala();
            }
            if(opcao == 5){
              RemoveFilme();
            }
            if(opcao == 8){
              TelaPrincipal();
            }

            sair = 1;
        }
    }

    endwin(); //restaura o terminal padrão


}


void nomeFilme(void){
    void nomeFilme(void);
    int max_x, max_y, maxY, maxX, sala;
    int meiox, qtd_ingresso;
    int ch, sair = 0, x = 0, y = 0, opcao = 4;
    int centro_x, centro_y;
    //int numsala[5] = {0, 0, 0, 0, 0};

    WINDOW *win;

    initscr();
  
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; 

    //bordas
    for(x=max_x/4; x < 3 * max_x/4+1; x++){
        mvprintw(max_y/4-1,x, "-" ); 
        //mvprintw(3*max_y/4+1, x, "-");
    }
    mvwprintw(win, 4, 0, "------------------------------------");


    refresh();

    // Para cadastras novas salas verificamos se as salas estão cheias, se a sala estiver cheia pula para o proximo teste se não fazemos o cadastro 
  
    mvwprintw(win, 0, meiox - 10, "CINE-IFB - Funcionario");
    mvwprintw(win, 2, 0, "Nome do Filme: ");
    wscanw(win, "%[^\n]s", filmeatual); 
    mvwprintw(win, 3, 0, "Sala: ");
    wscanw(win,"%d", &numero);
    wclear(win);

    if(valorsala[numero-1]==0 && (numero>0 && numero<6)){
      valorsala[numero-1] = 1;
      numsala[numero] = numero;
      strcpy(filme[numero-1], filmeatual);
      mvwprintw(win, 0, meiox - 10, "CINE-IFB - Funcionario");
      mvwprintw(win, 2, 0, "Filme cadastrado com sucesso!");
      mvwprintw(win, 3, 0, "------------------------------------");
      wrefresh(win);
      sleep(3);
      MenuFuncionario();
      ++lotado;
    }else{
        mvwprintw(win, 0, meiox - 10, "CINE-IFB - Funcionario");
        mvwprintw(win, 2, 0, "Sala ocupada ou inexistente");
        mvwprintw(win, 3, 0, "------------------------------------");
        wrefresh(win);
        sleep(3);
        MenuFuncionario();
      wrefresh(win);
    }
  


    //verifica se todas as salas estão cheias
    if(lotado == 5){
      mvwprintw(win, 3, 0, "------------------------------------");
      mvwprintw(win, 2, 0, "Todas as salas já estão ocupadas");
      wrefresh(win);
      sleep(3);
    }

  
    wrefresh(win);
   
    endwin(); //restaura o terminal padrão

 }


 void VisualizaSala(void){
    void visualizaMatriz1(void);
    int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 4;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win


  
    for(x=max_x/4; x < 3 * max_x/4+1; x++){
        mvprintw(max_y/4-1,x, "-" ); //aqui segue a mesma logica porem alterando o eixo x, ja que o eixo y é fixo para a primeira linha e para a segunda 
        //mvprintw(3*max_y/4+1, x, "-");//segunda linha
    }
    mvwprintw(win, 11, 0, "------------------------------------");

    refresh();
    
    mvwprintw(win, 0, meiox - 10, "CINE-IFB - Funcionario");
    mvwprintw(win, 2, 0, "Qual sala será consultada:"); 
    if(strcmp(filme[0], "\0")!=0){
      mvwprintw(win, 4, 2, "Sala 1: %s", filme[0]);
    }if(strcmp(filme[1], "\0")!=0){
      mvwprintw(win, 5, 2, "Sala 2: %s", filme[1]);
    }if(strcmp(filme[2], "\0")!=0){
      mvwprintw(win, 6, 2, "Sala 3: %s", filme[2]);
    }if(strcmp(filme[3], "\0")!=0){
      mvwprintw(win, 7, 2, "Sala 4: %s", filme[3]);
    }if(strcmp(filme[4], "\0")!=0){
      mvwprintw(win, 8, 2, "Sala 5: %s", filme[4]);
    }
    //note que a linha 7 não existe, voce precisa saltar ela no loop while
    mvwprintw(win, 10, 2, "Voltar");
    wrefresh(win);

    while (!sair)
    {
        mvwprintw(win, opcao, 0, "->");
        wrefresh(win);
        ch = getch();

        switch (ch)
        {
        case KEY_DOWN:
            if (opcao != 10)
            { 
                mvwprintw(win, opcao, 0, "  ");
                opcao++;
                if(opcao == 9){ 
                    opcao = 10;
                }
            }
            else
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao = 4; 
            }
            break;
        case KEY_UP: 
            if (opcao != 4)
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao--;
                if(opcao == 9){
                    opcao = 8; 
                               
                }
                
            }
            else
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao = 10; 
            }
            break;
        case '\n':
            if (opcao == 10)
            {
              MenuFuncionario();
            }
            if (opcao == 4){
              wclear(win);
              visualizaMatriz1();
            }
            if(opcao == 5){
              wclear(win);
              visualizaMatriz2();

            }
             if(opcao == 6){
              wclear(win);
              visualizaMatriz3();

            }
             if(opcao == 7){
              wclear(win);
              visualizaMatriz4();

            }
              if(opcao == 8){
              wclear(win);
              visualizaMatriz5();

            }
            

            sair = 1;
        }
    }

    endwin(); //restaura o terminal padrão


 }


 void matriz1(void){
   int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 4;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win

int i,j,lotado=0,ok;
int npessoas = 0, aux=0;



while(aux < qtd_ingresso){
  
    wclear(win);
    mvwprintw(win, 0, meiox - 10, "CINE-IFB Funcionario");
    mvwprintw(win, 12, 0, "------------------------------------");
    mvwprintw(win,1, 2, "0123456789\n");
    wrefresh(win);
    for(int i=0; i < 8; i++){
      mvwprintw(win,i+2,0,"%d", i);
      for(int j=0; j < 10; j++){
        mvwprintw(win,i+2,j+2,"%c", sala1[i][j]);
      }
    }
    wrefresh(win);
  

mvwprintw(win, 10,0,"\nDigite uma coordenada (x,y): ");
wscanw(win,"%d,%d", &x, &y);

lugar1[0] = x;
lugar1[1] = y;

if(sala1[x][y] == ' '){
  mvwprintw(win,6,0,"Por favor escolha uma localizacao segura\n");
}
else{
  sala1[x][y] = 'P';
        
        if(sala1[x][y] == 'P'){
        if(sala1[x + 1][y] == '@'){
            sala1[x + 1][y] = '#';
        }else if(sala1[x + 1][y] == ' ' ){
        sala1[x + 1][y] = ' ';
        }
        else{
            sala1[x + 1][y] = '#';
        }
      }
      if(sala1[x][y] == 'P'){
        if(sala1[x][y + 1] == '@'){
            sala1[x][y + 1] = '#';
        }else if(sala1[x][y + 1] == ' ' ){
        sala1[x][y + 1] = ' ';
        }
        else{
            sala1[x][y + 1] = '#';
        }
      }

      if(sala1[x][y] == 'P'){
        if(sala1[x][y - 1] == '@'){
            sala1[x][y - 1] = '#';
        }else if(sala1[x][y - 1] == ' ' ){
        sala1[x][y - 1] = ' ';
        }
        else{
            sala1[x][y - 1] = '#';
        }
      }

      if(sala1[x][y] == 'P'){
        if(sala1[x - 1][y] == '@'){
            sala1[x - 1][y] = '#';
        }else if(sala1[x - 1][y] == ' ' ){
        sala1[x - 1][y] = ' ';
        }
        else{
           sala1[x - 1][y] = '#';
        }
      }
      
  aux++;
}

ok = 0;

}

wclear(win);
    mvwprintw(win,0, 2, "0123456789\n");
    wrefresh(win);
    for(int i=0; i < 8; i++){
      mvwprintw(win,i+1,0,"%d", i);
      for(int j=0; j < 10; j++){
        mvwprintw(win,i+1,j+2,"%c", sala1[i][j]);
      }
    }
  wrefresh(win);

  endwin();
}

void matriz2 (void){

int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 4;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win

int i,j,lotado=0,ok;
int npessoas = 0, aux=0;



while(aux < qtd_ingresso){
  
    wclear(win);
    mvwprintw(win, 0, meiox - 10, "CINE-IFB Funcionario");
    mvwprintw(win, 12, 0, "------------------------------------");
    mvwprintw(win,1, 2, "0123456789\n");
    wrefresh(win);
    for(int i=0; i < 8; i++){
      mvwprintw(win,i+2,0,"%d", i);
      for(int j=0; j < 10; j++){
        mvwprintw(win,i+2,j+2,"%c", sala2[i][j]);
      }
    }
    wrefresh(win);
  

mvwprintw(win, 10,0,"\nDigite uma coordenada (x,y): ");
wscanw(win,"%d,%d", &x, &y);

lugar1[0] = x;
lugar1[1] = y;

if(sala2[x][y] == ' '){
  printf("Por favor escolha uma localizacao segura\n");
}
else{
  sala2[x][y] = 'P';
        
        if(sala2[x][y] == 'P'){
        if(sala2[x + 1][y] == '@'){
            sala2[x + 1][y] = '#';
        }else if(sala2[x + 1][y] == ' ' ){
        sala2[x + 1][y] = ' ';
        }
        else{
            sala2[x + 1][y] = '#';
        }
      }
      if(sala2[x][y] == 'P'){
        if(sala2[x][y + 1] == '@'){
            sala2[x][y + 1] = '#';
        }else if(sala2[x][y + 1] == ' ' ){
        sala2[x][y + 1] = ' ';
        }
        else{
            sala2[x][y + 1] = '#';
        }
      }

      if(sala2[x][y] == 'P'){
        if(sala2[x][y - 1] == '@'){
            sala2[x][y - 1] = '#';
        }else if(sala2[x][y - 1] == ' ' ){
        sala2[x][y - 1] = ' ';
        }
        else{
            sala2[x][y - 1] = '#';
        }
      }

      if(sala2[x][y] == 'P'){
        if(sala2[x - 1][y] == '@'){
            sala2[x - 1][y] = '#';
        }else if(sala2[x - 1][y] == ' ' ){
        sala2[x - 1][y] = ' ';
        }
        else{
           sala2[x - 1][y] = '#';
        }
      }
      
  aux++;
}

ok = 0;

}

printf("     0  1  2  3  4  5  6  7  8  9\n");
for(i=0; i < 8; i++){
  printf("%3d", 0+i);          //printf("%3c", 72-i)
  for(j=0; j < 10; j++){
    printf("%3c", sala2[i][j]);
  }
  puts("");
}

}

void matriz3 (void){

int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 4;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win

int i,j,lotado=0,ok;
int npessoas = 0, aux=0;



while(aux < qtd_ingresso){
  
    wclear(win);
    mvwprintw(win, 0, meiox - 10, "CINE-IFB Funcionario");
    mvwprintw(win, 12, 0, "------------------------------------");
    mvwprintw(win,1, 2, "0123456789\n");
    wrefresh(win);
    for(int i=0; i < 8; i++){
      mvwprintw(win,i+2,0,"%d", i);
      for(int j=0; j < 10; j++){
        mvwprintw(win,i+2,j+2,"%c", sala3[i][j]);
      }
    }
    wrefresh(win);
  

mvwprintw(win, 10,0,"\nDigite uma coordenada (x,y): ");
wscanw(win,"%d,%d", &x, &y);

lugar1[0] = x;
lugar1[1] = y;

if(sala3[x][y] == ' '){
  printf("Por favor escolha uma localizacao segura\n");
}
else{
  sala3[x][y] = 'P';
        
        if(sala3[x][y] == 'P'){
        if(sala3[x + 1][y] == '@'){
            sala3[x + 1][y] = '#';
        }else if(sala3[x + 1][y] == ' ' ){
        sala3[x + 1][y] = ' ';
        }
        else{
            sala3[x + 1][y] = '#';
        }
      }
      if(sala3[x][y] == 'P'){
        if(sala3[x][y + 1] == '@'){
            sala3[x][y + 1] = '#';
        }else if(sala3[x][y + 1] == ' ' ){
        sala3[x][y + 1] = ' ';
        }
        else{
            sala3[x][y + 1] = '#';
        }
      }

      if(sala3[x][y] == 'P'){
        if(sala3[x][y - 1] == '@'){
            sala3[x][y - 1] = '#';
        }else if(sala3[x][y - 1] == ' ' ){
        sala3[x][y - 1] = ' ';
        }
        else{
            sala3[x][y - 1] = '#';
        }
      }

      if(sala3[x][y] == 'P'){
        if(sala3[x - 1][y] == '@'){
            sala3[x - 1][y] = '#';
        }else if(sala3[x - 1][y] == ' ' ){
        sala3[x - 1][y] = ' ';
        }
        else{
           sala3[x - 1][y] = '#';
        }
      }
      
  aux++;
}

ok = 0;

}

printf("     0  1  2  3  4  5  6  7  8  9\n");
for(i=0; i < 8; i++){
  printf("%3d", 0+i);          //printf("%3c", 72-i)
  for(j=0; j < 10; j++){
    printf("%3c", sala3[i][j]);
  }
  puts("");
}

}

void matriz4 (void){

int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 4;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win

int i,j,lotado=0,ok;
int npessoas = 0, aux=0;



while(aux < qtd_ingresso){
  
    wclear(win);
    mvwprintw(win, 0, meiox - 10, "CINE-IFB Funcionario");
    mvwprintw(win, 12, 0, "------------------------------------");
    mvwprintw(win,1, 2, "0123456789\n");
    wrefresh(win);
    for(int i=0; i < 8; i++){
      mvwprintw(win,i+2,0,"%d", i);
      for(int j=0; j < 10; j++){
        mvwprintw(win,i+2,j+2,"%c", sala4[i][j]);
      }
    }
    wrefresh(win);
  

mvwprintw(win, 10,0,"\nDigite uma coordenada (x,y): ");
wscanw(win,"%d,%d", &x, &y);

lugar1[0] = x;
lugar1[1] = y;


if(sala4[x][y] == ' '){
  printf("Por favor escolha uma localizacao segura\n");
}
else{
  sala4[x][y] = 'P';
        
        if(sala4[x][y] == 'P'){
        if(sala4[x + 1][y] == '@'){
            sala4[x + 1][y] = '#';
        }else if(sala4[x + 1][y] == ' ' ){
        sala4[x + 1][y] = ' ';
        }
        else{
            sala4[x + 1][y] = '#';
        }
      }
      if(sala4[x][y] == 'P'){
        if(sala4[x][y + 1] == '@'){
            sala4[x][y + 1] = '#';
        }else if(sala4[x][y + 1] == ' ' ){
        sala4[x][y + 1] = ' ';
        }
        else{
            sala4[x][y + 1] = '#';
        }
      }

      if(sala4[x][y] == 'P'){
        if(sala4[x][y - 1] == '@'){
            sala4[x][y - 1] = '#';
        }else if(sala4[x][y - 1] == ' ' ){
        sala4[x][y - 1] = ' ';
        }
        else{
            sala4[x][y - 1] = '#';
        }
      }

      if(sala4[x][y] == 'P'){
        if(sala4[x - 1][y] == '@'){
            sala4[x - 1][y] = '#';
        }else if(sala4[x - 1][y] == ' ' ){
        sala4[x - 1][y] = ' ';
        }
        else{
           sala4[x - 1][y] = '#';
        }
      }
      
  aux++;
}

ok = 0;

}

printf("     0  1  2  3  4  5  6  7  8  9\n");
for(i=0; i < 8; i++){
  printf("%3d", 0+i);          //printf("%3c", 72-i)
  for(j=0; j < 10; j++){
    printf("%3c", sala4[i][j]);
  }
  puts("");
}

}

void matriz5 (void){
int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 4;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win

int i,j,lotado=0,ok;
int npessoas = 0, aux=0;



while(aux < qtd_ingresso){
  wclear(win);
    mvwprintw(win, 0, meiox - 10, "CINE-IFB Funcionario");
    mvwprintw(win, 12, 0, "------------------------------------");
    mvwprintw(win,1, 2, "0123456789\n");
    wrefresh(win);
    for(int i=0; i < 8; i++){
      mvwprintw(win,i+2,0,"%d", i);
      for(int j=0; j < 10; j++){
        mvwprintw(win,i+2,j+2,"%c", sala5[i][j]);
      }
    }
    wrefresh(win);
  

mvwprintw(win, 10,0,"\nDigite uma coordenada (x,y): ");
wscanw(win,"%d,%d", &x, &y);

lugar1[0] = x;
lugar1[1] = y;


if(sala5[x][y] == ' '){
  printf("Por favor escolha uma localizacao segura\n");
}
else{
  sala5[x][y] = 'P';
        
        if(sala5[x][y] == 'P'){
        if(sala5[x + 1][y] == '@'){
            sala5[x + 1][y] = '#';
        }else if(sala5[x + 1][y] == ' ' ){
        sala5[x + 1][y] = ' ';
        }
        else{
            sala5[x + 1][y] = '#';
        }
      }
      if(sala5[x][y] == 'P'){
        if(sala5[x][y + 1] == '@'){
            sala5[x][y + 1] = '#';
        }else if(sala5[x][y + 1] == ' ' ){
        sala5[x][y + 1] = ' ';
        }
        else{
            sala5[x][y + 1] = '#';
        }
      }

      if(sala5[x][y] == 'P'){
        if(sala5[x][y - 1] == '@'){
            sala5[x][y - 1] = '#';
        }else if(sala5[x][y - 1] == ' ' ){
        sala5[x][y - 1] = ' ';
        }
        else{
            sala5[x][y - 1] = '#';
        }
      }

      if(sala5[x][y] == 'P'){
        if(sala5[x - 1][y] == '@'){
            sala5[x - 1][y] = '#';
        }else if(sala5[x - 1][y] == ' ' ){
        sala5[x - 1][y] = ' ';
        }
        else{
           sala5[x - 1][y] = '#';
        }
      }
      
  aux++;
}

ok = 0;

}

printf("     0  1  2  3  4  5  6  7  8  9\n");
for(i=0; i < 8; i++){
  printf("%3d", 0+i);          //printf("%3c", 72-i)
  for(j=0; j < 10; j++){
    printf("%3c", sala5[i][j]);
  }
  puts("");
}

}




void visualizaMatriz1(void){
   int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 10;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win
    wclear(win);
    wrefresh(win);
    mvwprintw(win, 0, meiox - 10, "CINE-IFB Funcionario");
    mvwprintw(win, 11, 0, "------------------------------------");
    mvwprintw(win,1, 2, "0123456789\n");
    wrefresh(win);
    for(int i=0; i < 8; i++){
      mvwprintw(win,i+2,0,"%d", i);
      for(int j=0; j < 10; j++){
        mvwprintw(win,i+2,j+2,"%c", sala1[i][j]);
      }
    }
    mvwprintw(win, 10,2, "Voltar");
    wrefresh(win);
    while(!sair){
      mvwprintw(win, opcao, 0, "->");
        wrefresh(win);
        ch = getch();

        switch (ch){
          case '\n':
            if (opcao == 10)
            {
              VisualizaSala();
            }

            sair = 1;
        }  
    }
    wrefresh(win);
    endwin();

}

void visualizaMatriz2(void){
   int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 10;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win
    wclear(win);
    wrefresh(win);
    mvwprintw(win, 0, meiox - 10, "CINE-IFB Funcionario");
    mvwprintw(win, 11, 0, "------------------------------------");
    mvwprintw(win,1, 2, "0123456789\n");
    wrefresh(win);
    for(int i=0; i < 8; i++){
      mvwprintw(win,i+2,0,"%d", i);
      for(int j=0; j < 10; j++){
        mvwprintw(win,i+2,j+2,"%c", sala2[i][j]);
      }
    }
    mvwprintw(win, 10,2, "Voltar");
    wrefresh(win);
    while(!sair){
      mvwprintw(win, opcao, 0, "->");
        wrefresh(win);
        ch = getch();

        switch (ch){
          case '\n':
            if (opcao == 10)
            {
              VisualizaSala();
            }

            sair = 1;
        }  
    }
    wrefresh(win);
    endwin();

}

void visualizaMatriz3(void){
   int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 10;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win
    wclear(win);
    wrefresh(win);
    mvwprintw(win, 0, meiox - 10, "CINE-IFB Funcionario");
    mvwprintw(win, 11, 0, "------------------------------------");
    mvwprintw(win,1, 2, "0123456789\n");
    wrefresh(win);
    for(int i=0; i < 8; i++){
      mvwprintw(win,i+2,0,"%d", i);
      for(int j=0; j < 10; j++){
        mvwprintw(win,i+2,j+2,"%c", sala3[i][j]);
      }
    }
    mvwprintw(win, 10,2, "Voltar");
    wrefresh(win);
    while(!sair){
      mvwprintw(win, opcao, 0, "->");
        wrefresh(win);
        ch = getch();

        switch (ch){
          case '\n':
            if (opcao == 10)
            {
              VisualizaSala();
            }

            sair = 1;
        }  
    }
    wrefresh(win);
    endwin();

}

void visualizaMatriz4(void){
   int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 10;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win
    wclear(win);
    wrefresh(win);
    mvwprintw(win, 0, meiox - 10, "CINE-IFB Funcionario");
    mvwprintw(win, 11, 0, "------------------------------------");
    mvwprintw(win,1, 2, "0123456789\n");
    wrefresh(win);
    for(int i=0; i < 8; i++){
      mvwprintw(win,i+2,0,"%d", i);
      for(int j=0; j < 10; j++){
        mvwprintw(win,i+2,j+2,"%c", sala4[i][j]);
      }
    }
    mvwprintw(win, 10,2, "Voltar");
    wrefresh(win);
    while(!sair){
      mvwprintw(win, opcao, 0, "->");
        wrefresh(win);
        ch = getch();

        switch (ch){
          case '\n':
            if (opcao == 10)
            {
              VisualizaSala();
            }

            sair = 1;
        }  
    }
    wrefresh(win);
    endwin();


}

void visualizaMatriz5(void){
   int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 10;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    /* Verificar o tamanho da janela inteira*/
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win
    wclear(win);
    wrefresh(win);
    mvwprintw(win, 0, meiox - 10, "CINE-IFB Funcionario");
    mvwprintw(win, 11, 0, "------------------------------------");
    mvwprintw(win,1, 2, "0123456789\n");
    wrefresh(win);
    for(int i=0; i < 8; i++){
      mvwprintw(win,i+2,0,"%d", i);
      for(int j=0; j < 10; j++){
        mvwprintw(win,i+2,j+2,"%c", sala5[i][j]);
      }
    }
    mvwprintw(win, 10,2, "Voltar");
    wrefresh(win);
    while(!sair){
      mvwprintw(win, opcao, 0, "->");
        wrefresh(win);
        ch = getch();

        switch (ch){
          case '\n':
            if (opcao == 10)
            {
              VisualizaSala();
            }

            sair = 1;
        }  
    }
    wrefresh(win);
    endwin();


}