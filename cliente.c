#include "cliente.h"
#include "funcionario.h"

    int lugar1[5];
    int lugar2[2];
    char lugar3[2];
    char filme[5][50];
    char bilhetefilme[5][50];
    int numero, qtd_ingresso;
    int numsala[5];
    int valorsala[5];
    char nome[20];
    int sala;
    int opcaoglobal;

    char filmeatual[50];

    int salaA, salaB, salaC, salaD, salaE;
    int lotado;
    char sala1[8][10];
    
    char sala2[8][10];

    char sala3[8][10];

    char sala4[8][10];

    char sala5[8][10];

/*void TelaPrincipal(void){
  void MenuFuncionario(void);
  int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 4;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

     Verificar o tamanho da janela inteira
    getmaxyx(stdscr, max_y, max_x);
    //criando a janela no centro da tela
    win = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
    getmaxyx(win, maxY, maxX);
    meiox = maxX/2; //metade da screen win


    for(x=max_x/4; x < 3 * max_x/4+1; x++){
        mvprintw(max_y/4-1,x, "-" ); 
        //mvwprintw(win,8, x, "-");
        //mvprintw(3*max_y/4+1, x, "-");
    }
    mvwprintw(win, 8, 0, "------------------------------------");





    refresh();
    
    mvwprintw(win, 0, meiox - 4, "CINE-IFB"); //vai imprimir a string no centro da linha
    mvwprintw(win, 2, 0, "Selecione uma opção");
    mvwprintw(win, 4, 2, "Cliente");
    mvwprintw(win, 5, 2, "Funcionario");
    mvwprintw(win, 7, 2, "Encerrar programa");
    
    wrefresh(win);

    while (!sair)
    {
        mvwprintw(win, opcao, 0, "->");
        wrefresh(win);
        ch = getch();

        switch (ch)
        {
        case KEY_DOWN:
            if (opcao != 7)
            { 
                mvwprintw(win, opcao, 0, "  ");
                opcao++;
                if(opcao == 6){ 
                    opcao = 7;
                }
            }
            else
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao = 4; //terminamos o loop, voltamos para a primeira linha
            }
            break;
        case KEY_UP: 
            if (opcao != 4) 
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao--;
                if(opcao == 6){
                    opcao = 5; 
                }
            }
            else
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao = 7; //completamos o loop, voltamos pra ultima linha
            }
            break;
        case '\n':
            if (opcao == 4)
            {
              ////// parte do Cliente função
              
              TelaCliente();
            
            }
            if( opcao == 5){
              MenuFuncionario();
            }

            sair = 1;
        }
    }

    endwin(); //restaura o terminal padrão


}
*/


void TelaCliente (void){
  void TelaCompra(void);
	void TelaPrincipal(void);
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
    mvwprintw(win, 9, 0, "------------------------------------");


    refresh();
    
    mvwprintw(win, 0, meiox - 8, "CINE-IFB - Cliente"); //vai imprimir a string no centro da linha
    mvwprintw(win, 2, 0, "Selecione uma opção"); 
    mvwprintw(win, 4, 2, "Comprar Ingressos");
    mvwprintw(win, 5, 2, "Consultar filmes em cartaz");
    mvwprintw(win, 6, 2, "Checar Ingresso");
    //note que a linha 7 não existe, voce precisa saltar ela no loop while
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
              TelaCompra();
            }
            if (opcao == 5){
              TelaConsulta();
            }
            if (opcao == 6){
              ChecarIngresso();
            }
            if(opcao == 8){
              TelaPrincipal();

            }

            sair = 1;
        }
    }
    wclear(win);
    clear();
    endwin(); //restaura o terminal padrão

}







void TelaCompra(void){

  void nomeIngresso(void);
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
        //mvprintw(3*max_y/4+1, x, "-");
    }
    mvwprintw(win, 9, 0, "------------------------------------");

    refresh();

    mvwprintw(win, 0, meiox - 8, "CINE-IFB - Cliente");  
    mvwprintw(win, 2, 0, "Escolha um filme:"); 
    mvwprintw(win, 4, 2, "%s", filme[0]);
    mvwprintw(win, 5, 2, "%s", filme[1]);
    mvwprintw(win, 6, 2, "%s", filme[2]);
    mvwprintw(win, 7, 2, "%s", filme[3]);
    mvwprintw(win, 8, 2, "%s", filme[4]);

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
                /*if(opcao == 9){ 
                    opcao = 10;
                }*/
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
                /*if(opcao == 9){
                    opcao = 8; 
                               
                }*/
                
            }
            else
            {
                mvwprintw(win, opcao, 0, "  ");
                opcao = 8; 
            }
            break;
        case '\n':
            
            if (opcao == 4 ){
              
              sala = 1;
              opcaoglobal = 0;
              strcpy(bilhetefilme[0], filme[0]);
              nomeIngresso();
            }else if(opcao == 5){
              
              sala = 2;
              opcaoglobal = 1;
              strcpy(bilhetefilme[1], filme[1]);
              nomeIngresso();
            }else if(opcao == 6){
              
              sala = 3;
              opcaoglobal = 2;
              strcpy(bilhetefilme[2], filme[2]);
              nomeIngresso();
            }
            else if(opcao == 7){
              
              sala = 4;
              opcaoglobal = 3;
              strcpy(bilhetefilme[3], filme[3]);
              nomeIngresso();
            }
            else if(opcao == 8){
              
              sala = 5;
              opcaoglobal = 4;
              strcpy(bilhetefilme[4], filme[4]);
              nomeIngresso();
            }

            sair = 1;
        }
    }

    endwin(); //restaura o terminal padrão

}


 void nomeIngresso(void){
   int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 4;
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
    meiox = maxX/2; 


    for(x=max_x/4; x < 3 * max_x/4+1; x++){
        mvprintw(max_y/4-1,x, "-" ); 
        //mvprintw(3*max_y/4+1, x, "-");
    }
    mvwprintw(win, 4, 0, "------------------------------------");


    refresh();
    
    mvwprintw(win, 0, meiox - 8, "CINE-IFB - Cliente"); 
    mvwprintw(win, 2, 0, "Quantidade de ingresso: ");
    wscanw(win, "%d", &qtd_ingresso);
    mvwprintw(win, 3, 0, "Nome do cliente: ");
    wscanw(win,"%s", nome);

    wclear(win);
    if(opcaoglobal == 0){
      matriz1();
    }else if(opcaoglobal == 1){
      matriz2();
    }else if(opcaoglobal == 2){
      matriz3();
    }else if(opcaoglobal == 3){
      matriz4();
    }else if(opcaoglobal == 4){ 
      matriz5();
    }
    wrefresh(win);

    Bilhete();

    wrefresh(win);
   
    endwin(); //restaura o terminal padrão

 }







 void TelaConsulta(void){
   
    int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 8;
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
        //mvprintw(3*max_y/4+1, x, "-");
    }
    mvwprintw(win, 9, 0, "------------------------------------");


    refresh();
    
    mvwprintw(win, 0, meiox - 8, "CINE-IFB - Cliente");  //vai imprimir a string no centro da linha
    mvwprintw(win, 2, 0, "Em cartaz:");
    if(strcmp(filme[0], "\0")!=0){
      mvwprintw(win, 3, 2, "%s (Sala 1)", filme[0]);
    }
    if(strcmp(filme[1], "\0")!=0){
      mvwprintw(win, 4, 2, "%s (Sala 2)", filme[1]);
    }
    if(strcmp(filme[2], "\0")!=0){
      mvwprintw(win, 5, 2, "%s (Sala 3)", filme[2]);
    }
    if(strcmp(filme[3], "\0")!=0){
      mvwprintw(win, 6, 2, "%s (Sala 4)", filme[3]);
    }
    if(strcmp(filme[4], "\0")!=0){
      mvwprintw(win, 7, 2, "%s (Sala 5)", filme[4]);
    }
    mvwprintw(win, 8, 2, "Voltar");

    while(!sair){
      mvwprintw(win, opcao, 0, "->");
        wrefresh(win);
        ch = getch();

        switch (ch){
          case '\n':
            if (opcao == 8)
            {
              TelaCliente();
            }

            sair = 1;
        }  
    }

    wrefresh(win);

    endwin(); //restaura o terminal padrão
 }

void Bilhete(void){
  int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 11;
    int centro_x, centro_y;
    WINDOW *win;

    initscr();
    //noechonoecho();
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
        //mvprintw(3*max_y/4+1, x, "-");
    }
    mvwprintw(win, 5, 35, "|");
    mvwprintw(win, 6, 35, "|");
    mvwprintw(win, 7, 35, "|");
    mvwprintw(win, 8, 35, "|");
    
    mvwprintw(win, 12, 0, "------------------------------------");
    //borda do ingresso
    mvwprintw(win, 9, 0, "x----------------------------------x");
    mvwprintw(win, 4, 0, "x----------------------------------x");



    refresh();
    
    mvwprintw(win, 0, meiox - 8, "CINE-IFB - Cliente");  //vai imprimir a string no centro da linha
    mvwprintw(win, 2, 0, "Ingresso gerado com sucesso!");
    if(opcaoglobal == 0){
      mvwprintw(win, 5, 0, "|Filme: %s", filme[0]);
      mvwprintw(win, 6, 0, "|Sala: %d", sala);
      mvwprintw(win, 7, 0, "|Cliente: %s", nome);
      mvwprintw(win, 8, 0, "|Lugar: %d,%d", lugar1[0],lugar1[1]);
      mvwprintw(win, 11, 2, "Voltar");
    }else if(opcaoglobal == 1){
      mvwprintw(win, 5, 0, "|Filme: %s", filme[1]);
      mvwprintw(win, 6, 0, "|Sala: %d", sala);
      mvwprintw(win, 7, 0, "|Cliente: %s", nome);
      mvwprintw(win, 8, 0, "|Lugar: %d,%d", lugar1[0],lugar1[1]);
      mvwprintw(win, 11, 2, "Voltar");
    }else if(opcaoglobal == 2){
      mvwprintw(win, 5, 0, "|Filme: %s", filme[2]);
      mvwprintw(win, 6, 0, "|Sala: %d", sala);
      mvwprintw(win, 7, 0, "|Cliente: %s", nome);
      mvwprintw(win, 8, 0, "|Lugar: %d,%d", lugar1[0],lugar1[1]);
      mvwprintw(win, 11, 2, "Voltar");
    }else if(opcaoglobal == 3){
      mvwprintw(win, 5, 0, "|Filme: %s", filme[3]);
      mvwprintw(win, 6, 0, "|Sala: %d", sala);
      mvwprintw(win, 7, 0, "|Cliente: %s", nome);
      mvwprintw(win, 8, 0, "|Lugar: %d,%d", lugar1[0],lugar1[1]);
      mvwprintw(win, 11, 2, "Voltar");
    }else{
      mvwprintw(win, 5, 0, "|Filme: %s", filme[4]);
      mvwprintw(win, 6, 0, "|Sala: %d", sala);
      mvwprintw(win, 7, 0, "|Cliente: %s", nome);
      mvwprintw(win, 8, 0, "|Lugar: %d,%d", lugar1[0],lugar1[1]);
      mvwprintw(win, 11, 2, "Voltar");
    }



    while(!sair){
      mvwprintw(win, opcao, 0, "->");
        wrefresh(win);
        ch = getch();

        switch (ch){
          case '\n':
            if (opcao == 11)
            {
              TelaCliente();
            }

            sair = 1;
        }  
    }

    wrefresh(win);




}


void ChecarIngresso(void){
  int max_x, max_y, maxY, maxX;
    int meiox;
    int ch, sair = 0, x = 0, y = 0, opcao = 11;
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
        //mvprintw(3*max_y/4+1, x, "-");
    }
    mvwprintw(win, 5, 35, "|");
    mvwprintw(win, 6, 35, "|");
    mvwprintw(win, 7, 35, "|");
    mvwprintw(win, 8, 35, "|");
    
    mvwprintw(win, 12, 0, "------------------------------------");
    //borda do ingresso
    mvwprintw(win, 9, 0, "x----------------------------------x");
    mvwprintw(win, 4, 0, "x----------------------------------x");



    refresh();
    
    mvwprintw(win, 0, meiox - 8, "CINE-IFB - Cliente");  //vai imprimir a string no centro da linha
    mvwprintw(win, 2, 0, "Nome do cliente: %s",nome);
    if(opcaoglobal == 0){
      mvwprintw(win, 5, 0, "|Filme: %s", filme[0]);
      mvwprintw(win, 6, 0, "|Sala: %d", sala);
      mvwprintw(win, 7, 0, "|Cliente: %s", nome);
      mvwprintw(win, 8, 0, "|Lugar: %d %d", lugar1[0], lugar1[1]);
      mvwprintw(win, 11, 2, "Voltar");
    }else if(opcaoglobal == 1){
      mvwprintw(win, 5, 0, "|Filme: %s", filme[1]);
      mvwprintw(win, 6, 0, "|Sala: %d", sala);
      mvwprintw(win, 7, 0, "|Cliente: %s", nome);
      mvwprintw(win, 8, 0, "|Lugar: %d %d", lugar1[0], lugar1[1]);
      mvwprintw(win, 11, 2, "Voltar");
    }else if(opcaoglobal == 2){
      mvwprintw(win, 5, 0, "|Filme: %s", filme[2]);
      mvwprintw(win, 6, 0, "|Sala: %d", sala);
      mvwprintw(win, 7, 0, "|Cliente: %s", nome);
      mvwprintw(win, 8, 0, "|Lugar: %d %d", lugar1[0], lugar1[1]);
      mvwprintw(win, 11, 2, "Voltar");
    }else if(opcaoglobal == 3){
      mvwprintw(win, 5, 0, "|Filme: %s", filme[3]);
      mvwprintw(win, 6, 0, "|Sala: %d", sala);
      mvwprintw(win, 7, 0, "|Cliente: %s", nome);
      mvwprintw(win, 8, 0, "|Lugar: %d %d", lugar1[0], lugar1[1]);
      mvwprintw(win, 11, 2, "Voltar");
    }else{
      mvwprintw(win, 5, 0, "|Filme: %s", filme[4]);
      mvwprintw(win, 6, 0, "|Sala: %d", sala);
      mvwprintw(win, 7, 0, "|Cliente: %s", nome);
      mvwprintw(win, 8, 0, "|Lugar: %d %d", lugar1[0], lugar1[1]);
      mvwprintw(win, 11, 2, "Voltar");
    }



    while(!sair){
      mvwprintw(win, opcao, 0, "->");
        wrefresh(win);
        ch = getch();

        switch (ch){
          case '\n':
            if (opcao == 11)
            {
              TelaCliente();
            }

            sair = 1;
        }  
    }

    wrefresh(win);




}







 //////////////////////////////////////////////////////////////////////// Funcionario ///////////////////////////



//#include "funcionario.h"

