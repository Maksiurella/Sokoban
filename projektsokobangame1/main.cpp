#include <iostream>

#include <iomanip>

using namespace std;




void level1();
void won1();
void level2();
void won2();
void level3();
void won3();
void menu();
void zasady();
void lose1();
void lose2();
void menugra1();
void menugra2();
void menugra3();
void wybor();

int main()
{
    menu();
    return 0;

}

void menu()
{
    system("cls");
    cout << endl;
    cout << "     ######     ####    ##    ##    ####    ######        ##       ##      ## " << endl;
    cout << "    ##    #   ##    ##  ##   ##   ##    ##  ##   ##     ##  ##     ##      ##" << endl;
    cout << "     ##       ##    ##  ##  ##    ##    ##  ##    ##    ##  ##     ###     ##" << endl;
    cout << "      ##      ##    ##  ## ##     ##    ##  ##   ##    ##    ##    ## #    ##" << endl;
    cout << "       ##     ##    ##  ####      ##    ##  ########   ##    ##    ##  #   ##" << endl;
    cout << "        ##    ##    ##  ## ##     ##    ##  ##   ##   ##########   ##   #  ##" << endl;
    cout << "         ##   ##    ##  ##  ##    ##    ##  ##    ##  ##      ##   ##    # ##" << endl;
    cout << "     #    ##  ##    ##  ##   ##   ##    ##  ##   ##  ##        ##  ##     ###" << endl;
    cout << "      #####     ####    ##    ##    ####    ######   ##        ##  ##      ## " << endl;
    cout << endl << endl << endl;

    cout << "**************** " << "Maksymilian Szmigiel ACIR4 Projekt 1 - gra sokoban ****************\n\n";

    char opcje;

    cout << setw(50) << " 1. Rozpocznij gre!" << endl;
    cout << setw(50) << "2. Zasady gry." << endl;

    cout << setw(50) << "3. Wyjdz z gry. " << endl;
    while (1)
    {
        cin >> opcje;
        switch (opcje)
        {
        case '1': system("cls");
            level1();
            break;
        case '2': system("cls");
            zasady();
            break;

        case '3': exit(0);
            break;
        default: "Nie ma takiej opcji";
            break;
        }
    }
}

void zasady()
{
    char powrot;

    cout << "Celem gry jest ustawienie skrzynek (znak 0) na odpowiednich miejscach (znak H) za pomoc¹ ludzika." << endl;
    cout << "Sterowanie:\n w(W) - ruch w gore \n s(S) - ruch w dol \n a(A) - ruch w lewo \n d(D) - ruch w prawo \n q(Q) - wyjscie do menu \n r(R) - redo (powtorz cofniety ruch) \n  u(U) - undo (cofnij ruch)";
    cout << endl << "Nacisnij 'q', aby wrocic do menu glownego\n";
    cin >> powrot;
    if (powrot == 'q' or powrot == 'Q')
    {
        system("cls"); menu();
    }
}
void menugra1()
{
    char op1;
    cout << "MENU" << endl << "1. Kontynuuj" << endl << "2. Wyjdz do menu glownego" << endl << "3. Restart" << endl;
    cin >> op1;
    switch (op1)
    {
    case '1':
        system("cls");
        break;
    case '2':
        menu();
        break;
    case '3':
        level1();
        break;
    }
}
    void menugra2()
    {
        char op1;
        cout << "MENU" << endl << "1. Kontynuuj" << endl << "2. Wyjdz do menu glownego" << endl << "3. Restart" << endl;
        cin >> op1;
        switch (op1)
        {
        case '1':
            system("cls");
            break;
        case '2':
            menu();
            break;
        case '3':
            level2();
            break;
        }
}
    void menugra3()
    {
        char op1;
        cout << "MENU" << endl << "1. Kontynuuj" << endl << "2. Wyjdz do menu glownego" << endl << "3. Restart" << endl;
        cin >> op1;
        switch (op1)
        {
        case '1':
            system("cls");
            break;
        case '2':
            menu();
            break;
        case '3':
            level3();
            break;
        }
    }





void level1() {



    char map_nr1[10][10] = {
        178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
        178, 'H', ' ', ' ', ' ', ' ', ' ', ' ', 'H', 178,
        178, 178, ' ', ' ', 178, 178, 178, 178, 178, 178,
        178, 'H', ' ', ' ', 178, ' ', ' ', ' ', ' ', 178,
        178, ' ', ' ', ' ', 178, ' ', '0', ' ', ' ', 178,
        178, ' ', ' ', ' ', 178, ' ', '0', ' ', ' ', 178,
        178, ' ', ' ', ' ', 178, ' ', ' ', '0', ' ', 178,
        178, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 178,
        178, ' ', ' ', ' ', 178, ' ', ' ', ' ', ' ', 178,
        178, 178, 178, 178, 178, 178, 178, 178, 178, 178
    };

    int n = 140;
    int x = 1;
    int y = 1;
    char player = '@';
    char placement = 'H';
    char move;
    char border = 178;
    char space = ' ';
    char chest = 48;
    char win = 'O';


    char temp1, temp2, temp3, temp4;




    while (1)
    {


        system("cls");


        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == y && j == x)
                {
                    cout << player;
                }
                else
                {
                    cout << map_nr1[i][j];
                }
            }
            cout << endl;
        }
        cout << "Pozostala liczba ruchow: " << n << endl;

        cin >> move;



        switch (move)
        {
        case 'w': if (map_nr1[y - 1][x] == space or map_nr1[y - 1][x] == placement)
        {
            y--;
            n--;
        }
                else  if (map_nr1[y - 1][x] == chest and map_nr1[y - 2][x] == space)
        {
            temp1 = map_nr1[y - 1][x];
            map_nr1[y - 1][x] = map_nr1[y - 2][x];
            map_nr1[y - 2][x] = temp1;
            y--;
            n--;
        }
                else if (map_nr1[y - 1][x] == chest and map_nr1[y - 2][x] == placement)
        {
            map_nr1[y - 2][x] = win;
            map_nr1[y - 1][x] = space;
            y--;
            n--;
        }
                break;
        case 's': if (map_nr1[y + 1][x] == space or map_nr1[y + 1][x] == placement)
        {
            y++;
            n--;
        }
                else if (map_nr1[y + 1][x] == chest and map_nr1[y + 2][x] == space)
        {
            temp2 = map_nr1[y + 1][x];
            map_nr1[y + 1][x] = map_nr1[y + 2][x];
            map_nr1[y + 2][x] = temp2;
            y++;
            n--;
        }
                else if (map_nr1[y + 1][x] == chest and map_nr1[y + 2][x] == placement)
        {
            map_nr1[y + 2][x] = win;
            map_nr1[y + 1][x] = space;
            y++;
            n--;
        }
                break;
        case 'a': if (map_nr1[y][x - 1] == space or map_nr1[y][x - 1] == placement)
        {
            x--;
            n--;
        }
                else if (map_nr1[y][x - 1] == chest and map_nr1[y][x - 2] == space)
        {
            temp3 = map_nr1[y][x - 1];
            map_nr1[y][x - 1] = map_nr1[y][x - 2];
            map_nr1[y][x - 2] = temp3;
            x--;
            n--;
        }
                else if (map_nr1[y][x - 1] == chest and map_nr1[y][x - 2] == placement)
        {
            map_nr1[y][x - 2] = win;
            map_nr1[y][x - 1] = space;
            x--;
            n--;
        }
                break;
        case 'd': if (map_nr1[y][x + 1] == space or map_nr1[y][x + 1] == placement)
        {
            x++;
            n--;

        }
                else if (map_nr1[y][x + 1] == chest and map_nr1[y][x + 2] == space)
        {
            temp4 = map_nr1[y][x + 1];
            map_nr1[y][x + 1] = map_nr1[y][x + 2];
            map_nr1[y][x + 2] = temp4;
            x++;
            n--;
        }
                else if (map_nr1[y][x + 1] == chest and map_nr1[y][x + 2] == placement)
        {
            map_nr1[y][x + 2] = win;
            map_nr1[y][x + 1] = space;
            x++;
            n--;

        }
                break;
        case 'Q':
        case 'q': menu();
            break;
        case 'z': menugra1();
            break;
        default: "Nie ma takiej opcji";
            break;
        }

        if (n <= 0)
        {
            lose1();
        }

        if (map_nr1[1][8] == win and map_nr1[1][1] == win and map_nr1[3][1] == win)
        {
            won1();





        }
    }

}





void won1()
{

    system("cls");

    cout << "gratulacje, wygrales!" << endl;
    system("pause");
    level2();

}



    void lose1()
    {
        char retry;
        system("cls");
        cout << "Liczba ruchow zostala przekroczona, wcisnij 'r' lub 'R', jesli chcesz sprobowac jeszcze raz!" << endl;
        cout << "'q' lub 'Q' - wyjscie do menu glownego" << endl;
        cin >> retry;
        if (retry == 'r' or retry == 'R')
        {
            level1();
        }
        else if (retry == 'q' or retry == 'Q')
        {
            menu();
        }

    }



    void level2()
    {
        char map_nr2[15][20] = { 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                                 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, ' ', ' ', 178, 178, 178, 178, 178, 178, 178, 178,
                                 178, 178, ' ', '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 178, 178, 178, 178, 178, ' ', ' ', 178,
                                 178, 178, '0', 178, 178, 178, 178, 178, ' ', 178, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 178,
                                 178, 178, ' ', 178, 178, 178, 178, ' ', ' ', 178, 178, 178, 178, 178, 178, 178, 178, 178, 'H', 178,
                                 178, 178, ' ', 178, 178, 178, 178, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 178,
                                 178, 178, ' ', 178, 178, 178, 178, 178, ' ', 178, 178, 178, 178, 178, 178, 178, 178, ' ', ' ', 178,
                                 178, ' ', ' ', 178, ' ', ' ', 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                                 178, ' ', ' ', ' ', ' ', ' ', 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                                 178, 178, 178, 178, 178, ' ', 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                                 178, 178, 178, 178, 178, ' ', 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                                 178, 178, 178, 178, ' ', ' ', 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                                 178, 178, 178, 178, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'H', 178, 178, 178, 178,
                                 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                                 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178
        };

        int n = 80;
        int x = 2;
        int y = 2;
        char player = '@';
        char placement = 'H';
        char move;
        char border = 178;
        char space = ' ';
        char chest = 48;
        char win = 'O';


        char temp1, temp2, temp3, temp4;


        while(1)
        {

            system("cls");
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    if (i == y && j == x)
                    {
                        cout << player;
                    }
                    else
                    {
                        cout << map_nr2[i][j];
                    }
                }
                cout << endl;
            }
            cout << "Pozostala liczba ruchow: " << n << endl;

            cin >> move;

            switch (move)
            {
            case 'W':
            case 'w': if (map_nr2[y - 1][x] == space or map_nr2[y - 1][x] == placement)
            {
                y--;
                n--;
            }
                    else  if (map_nr2[y - 1][x] == chest and map_nr2[y - 2][x] == space)
            {
                temp1 = map_nr2[y - 1][x];
                map_nr2[y - 1][x] = map_nr2[y - 2][x];
                map_nr2[y - 2][x] = temp1;
                y--;
                n--;
            }
                    else if (map_nr2[y - 1][x] == chest and map_nr2[y - 2][x] == placement)
            {
                map_nr2[y - 2][x] = win;
                map_nr2[y - 1][x] = space;
                y--;
                n--;
            }
                    break;
            case 'S':
            case 's': if (map_nr2[y + 1][x] == space or map_nr2[y + 1][x] == placement)
            {
                y++;
                n--;
            }
                    else if (map_nr2[y + 1][x] == chest and map_nr2[y + 2][x] == space)
            {
                temp2 = map_nr2[y + 1][x];
                map_nr2[y + 1][x] = map_nr2[y + 2][x];
                map_nr2[y + 2][x] = temp2;
                y++;
                n--;
            }
                    else if (map_nr2[y + 1][x] == chest and map_nr2[y + 2][x] == placement)
            {
                map_nr2[y + 2][x] = win;
                map_nr2[y + 1][x] = space;
                y++;
                n--;
            }
                    break;
            case 'A':
            case 'a': if (map_nr2[y][x - 1] == space or map_nr2[y][x - 1] == placement)
            {
                x--;
                n--;
            }
                    else if (map_nr2[y][x - 1] == chest and map_nr2[y][x - 2] == space)
            {
                temp3 = map_nr2[y][x - 1];
                map_nr2[y][x - 1] = map_nr2[y][x - 2];
                map_nr2[y][x - 2] = temp3;
                x--;
                n--;
            }
                    else if (map_nr2[y][x - 1] == chest and map_nr2[y][x - 2] == placement)
            {
                map_nr2[y][x - 2] = win;
                map_nr2[y][x - 1] = space;
                x--;
                n--;
            }
                    break;
            case 'D':
            case 'd': if (map_nr2[y][x + 1] == space or map_nr2[y][x + 1] == placement)
            {
                x++;
                n--;

            }
                    else if (map_nr2[y][x + 1] == chest and map_nr2[y][x + 2] == space)
            {
                temp4 = map_nr2[y][x + 1];
                map_nr2[y][x + 1] = map_nr2[y][x + 2];
                map_nr2[y][x + 2] = temp4;
                x++;
                n--;
            }
                    else if (map_nr2[y][x + 1] == chest and map_nr2[y][x + 2] == placement)
            {
                map_nr2[y][x + 2] = win;
                map_nr2[y][x + 1] = space;
                x++;
                n--;

            }
                    break;

            case 'Q':
            case 'q': menu();
                break;
            case 'z': menugra2();
                break;
            default: "Nie ma takiej opcji";
                break;
            }

            if (n <= 0)
            {
                lose2();
            }

            if (map_nr2[4][18] == win and map_nr2[12][15] == win)
            {

                won2();

            }
        }

    }

    void won2()
    {
        system("cls");
        cout << "Gratulacje, kolejny raz udalo Ci mnie pokonac :)" << endl;
        system("pause");
        level3();
    }
    void lose2()
    {
        char retry;
        system("cls");
        cout << "Liczba ruchow zostala przekroczona, wcisnij 'r' lub 'R', jesli chcesz sprobowac jeszcze raz!" << endl;
        cout << "'q' lub 'Q' - wyjscie do menu glownego" << endl;
        cin >> retry;
        if (retry == 'r' or retry == 'R')
        {
            level2();
        }
        else if (retry == 'q' or retry == 'Q')
        {
            menu();
        }
    }
    void level3()
    {
        char map_nr3[15][20] = {
                               178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                               178, 178, 178, 178, 178, 178, 178, 178, 178, 178, ' ', ' ', 178, 'H' ,' ', ' ', ' ', 178, 178, 178,
                               178, 178, ' ', '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 178, 178, ' ', ' ', ' ', 178, 178, 178,
                               178, 178, 178, 178, 178, 178, 178, 178, ' ', 178, ' ', ' ', ' ', ' ', ' ', ' ', 178, 178, 178, 178,
                               178, 178, 178, 178, 178, 178, 178, ' ', ' ', 178, 178, 178, 178, 178, ' ', ' ', 178, 178, 'H', 178,
                               178, 178, 178, 178, 178, 178, 178, ' ', '0', 178, 178, 178, 178, 178, 178, 178, 178, ' ', ' ', 178,
                               178, 178, 178, 178, 178, 178, 178, ' ', '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 178,
                               178, 178, 178, 178, 178, 178, 178, 178, ' ', 178, 178, 178, 178, 178, 178, 178, 178, ' ', ' ', 178,
                               178, 178, 178, 178, 178, 178, 178, 178, ' ', 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                               178, ' ', ' ', 'H', 178, 178, 178, 178, ' ', ' ', 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                               178, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                               178, ' ', ' ', ' ', 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                               178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                               178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
                               178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178
        };

        int n = 90;
        int x = 2;
        int y = 2;
        char player = '@';
        char placement = 'H';
        char move;
        char border = 178;
        char space = ' ';
        char chest = 48;
        char win = 'O';



        char temp1, temp2, temp3, temp4;


        while (1)
        {

            system("cls");
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    if (i == y && j == x)
                    {
                        cout << player;
                    }
                    else
                    {
                        cout << map_nr3[i][j];
                    }
                }
                cout << endl;
            }
            cout << "Pozostala liczba ruchow: " << n << endl;

            cin >> move;

            switch (move)
            {
            case 'W':
            case 'w': if (map_nr3[y - 1][x] == space or map_nr3[y - 1][x] == placement)
            {
                y--;
                n--;
            }
                    else  if (map_nr3[y - 1][x] == chest and map_nr3[y - 2][x] == space)
            {
                temp1 = map_nr3[y - 1][x];
                map_nr3[y - 1][x] = map_nr3[y - 2][x];
                map_nr3[y - 2][x] = temp1;
                y--;
                n--;
            }
                    else if (map_nr3[y - 1][x] == chest and map_nr3[y - 2][x] == placement)
            {
                map_nr3[y - 2][x] = win;
                map_nr3[y - 1][x] = space;
                y--;
                n--;
            }
                    break;
            case 'S':
            case 's': if (map_nr3[y + 1][x] == space or map_nr3[y + 1][x] == placement)
            {
                y++;
                n--;
            }
                    else if (map_nr3[y + 1][x] == chest and map_nr3[y + 2][x] == space)
            {
                temp2 = map_nr3[y + 1][x];
                map_nr3[y + 1][x] = map_nr3[y + 2][x];
                map_nr3[y + 2][x] = temp2;
                y++;
                n--;
            }
                    else if (map_nr3[y + 1][x] == chest and map_nr3[y + 2][x] == placement)
            {
                map_nr3[y + 2][x] = win;
                map_nr3[y + 1][x] = space;
                y++;
                n--;
            }
                    break;
            case 'A':
            case 'a': if (map_nr3[y][x - 1] == space or map_nr3[y][x - 1] == placement)
            {
                x--;
                n--;
            }
                    else if (map_nr3[y][x - 1] == chest and map_nr3[y][x - 2] == space)
            {
                temp3 = map_nr3[y][x - 1];
                map_nr3[y][x - 1] = map_nr3[y][x - 2];
                map_nr3[y][x - 2] = temp3;
                x--;
                n--;
            }
                    else if (map_nr3[y][x - 1] == chest and map_nr3[y][x - 2] == placement)
            {
                map_nr3[y][x - 2] = win;
                map_nr3[y][x - 1] = space;
                x--;
                n--;
            }
                    break;
            case 'D':
            case 'd': if (map_nr3[y][x + 1] == space or map_nr3[y][x + 1] == placement)
            {
                x++;
                n--;

            }
                    else if (map_nr3[y][x + 1] == chest and map_nr3[y][x + 2] == space)
            {
                temp4 = map_nr3[y][x + 1];
                map_nr3[y][x + 1] = map_nr3[y][x + 2];
                map_nr3[y][x + 2] = temp4;
                x++;
                n--;
            }
                    else if (map_nr3[y][x + 1] == chest and map_nr3[y][x + 2] == placement)
            {
                map_nr3[y][x + 2] = win;
                map_nr3[y][x + 1] = space;
                x++;
                n--;

            }
                    break;

            case 'Q':
            case 'q': menu();
                break;
            case 'z': menugra3();
                break;
            default: "Nie ma takiej opcji";
                break;
            }

            if (n <= 0)
            {
                lose2();
            }
            if (map_nr3[4][18] == win and map_nr3[1][13] == win and map_nr3[9][3] == win)
            {

                won3();

            }
        }

    }



   void won3()
    {
       system("cls");
       cout << "Brawo, udalo Ci sie pokonac wszystkie poziomy, gratulacje!\n";
       system("pause");
       menu();

   }

