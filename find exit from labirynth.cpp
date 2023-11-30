//Algorythm for finding exit from maze
void szukajWyjscia(int x, int y)
{
    //instrukcje do uzupełnienia

    int nr_proby_ruchu = 0;

    do
    {
        int xn = x, yn = y;

        switch(nr_proby_ruchu)
        {
            case(0): --yn;
                break;
            case(1): --xn;
                break;
            case(2): ++yn;
                break;
            default: ++xn;
                break;
        }

        if((xn >= 0 && xn <= 12 && yn >= 0 && yn <= 12) && (lab[xn][yn] == ' ' || lab[xn][yn] == 'k'))
        {
            lab[xn][yn] = 'o';
            { gotoxy(xn + 2, yn + 2); cout << 'o'; }; Sleep(200);

            if(xn == xKoniec && yn == yKoniec)
            {
                czyKoniec = true;
                { gotoxy(xn + 2, yn + 2); cout << 'k'; }; Sleep(200);
                return;
            }
            else szukajWyjscia(xn, yn);

            if(!czyKoniec)
            {
                lab[xn][yn] = '.';
                { gotoxy(xn + 2, yn + 2); cout << '.'; }; Sleep(200);
            }
        }
        
    } while (!czyKoniec && nr_proby_ruchu++ < 4);
}
