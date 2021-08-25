#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>

#include "cliente.h"
#include "funcionario.h"


int TelaPrincipal(void){
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
            if(opcao == 7){
              //return 0;
              wclear(win);
              mvwprintw(win, 4, 0, "O programa foi encerrado com sucesso");
              wrefresh(win);
              sleep(2);
              //exit(0);
              
              sair = 1;
              break;
            }

           
        }
    }

    endwin(); //restaura o terminal padrão


}


int main()
{
    TelaPrincipal();

    return 0;
}




