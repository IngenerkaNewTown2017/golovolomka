#include "TXLib.h"

struct KrestIliNol
{
    int x;
    int y;
    int risovat;
    HDC pic;
};


int getKrestik(KrestIliNol* Krestiki, int nomer_X, int x, int y, HDC pic)
{
    int krestikV11 = 0;

    for (int counter = 0; counter < nomer_X; counter++)
    {
        if (Krestiki[counter].risovat  == true &&
            Krestiki[counter].x == x &&
            Krestiki[counter].y == y &&
            Krestiki[counter].pic == pic)
        {
            krestikV11 = 1;
        }
    }

    return krestikV11;
}


int igor()
{
    //txCreateWindow(490,490);

    HDC fon = txLoadImage ("Pictures\\XO\\��������������.bmp");

    HDC krestic = txLoadImage ("Pictures\\XO\\�������.bmp");
    txBitBlt (txDC(), 0, 0, 162, 163, krestic, 0, 0);

    HDC nolic = txLoadImage ("Pictures\\XO\\�����.bmp");
    txBitBlt (txDC(), 0, 170, 162, 158, nolic, 0, 0);

    int nomer_X = 0;
    KrestIliNol Krestiki[9];

    bool gameOver = false;


    while (!GetAsyncKeyState(VK_ESCAPE) && !gameOver)
    {
		txBegin();
        txClear();
        txBitBlt (txDC(), 0, 0, 500, 500, fon, 0, 0);

        if (txMouseButtons() & 1 or
            txMouseButtons() & 2) //��������
		{
            if (nomer_X < 9 and txMouseButtons() & 1)
            {
                Krestiki[nomer_X].risovat = true;
                Krestiki[nomer_X].pic = krestic;
                Krestiki[nomer_X].x = round(txMouseX() / 165) * 165;
                Krestiki[nomer_X].y = round(txMouseY() / 165) * 165;
			}
            else if (nomer_X < 9 and txMouseButtons() & 2)
            {
                Krestiki[nomer_X].risovat = true;
                Krestiki[nomer_X].pic = nolic;
                Krestiki[nomer_X].x = round(txMouseX() / 165) * 165;
                Krestiki[nomer_X].y = round(txMouseY() / 165) * 165;
			}

            for (int counter = 0; counter < nomer_X; counter++)
            {
                if (Krestiki[nomer_X].x == Krestiki[counter].x and Krestiki[nomer_X].y == Krestiki[counter].y
                and nomer_X < 9
                )
                {
                    nomer_X = nomer_X - 1;
                }
            }

            if (Krestiki[nomer_X].x  < 495 and Krestiki[nomer_X].y  < 495 and  nomer_X < 9)
            {
                nomer_X = nomer_X + 1;
            }
	    }


		for (int counter = 0; counter < nomer_X; counter++)
        {
            if (Krestiki[counter].risovat  == true)
            {
                txTransparentBlt (txDC(), Krestiki[counter].x, Krestiki[counter].y, 158, 158, Krestiki[counter].pic, 0, 0, TX_WHITE);
            }
        }


        int krestikV11 = getKrestik (Krestiki, nomer_X,   0,   0, krestic);
        int krestikV12 = getKrestik (Krestiki, nomer_X, 165,   0, krestic);
        int krestikV13 = getKrestik (Krestiki, nomer_X, 330,   0, krestic);
        int krestikV21 = getKrestik (Krestiki, nomer_X,   0, 165, krestic);
        int krestikV22 = getKrestik (Krestiki, nomer_X, 165, 165, krestic);
        int krestikV23 = getKrestik (Krestiki, nomer_X, 330, 165, krestic);
        int krestikV31 = getKrestik (Krestiki, nomer_X,   0, 330, krestic);
        int krestikV32 = getKrestik (Krestiki, nomer_X, 165, 330, krestic);
        int krestikV33 = getKrestik (Krestiki, nomer_X, 330, 330, krestic);
        int nolicV11 = getKrestik (Krestiki, nomer_X,   0,   0, nolic);
        int nolicV12 = getKrestik (Krestiki, nomer_X, 165,   0, nolic);
        int nolicV13 = getKrestik (Krestiki, nomer_X, 330,   0, nolic);
        int nolicV21 = getKrestik (Krestiki, nomer_X,   0, 165, nolic);
        int nolicV22 = getKrestik (Krestiki, nomer_X, 165, 165, nolic);
        int nolicV23 = getKrestik (Krestiki, nomer_X, 330, 165, nolic);
        int nolicV31 = getKrestik (Krestiki, nomer_X,   0, 330, nolic);
        int nolicV32 = getKrestik (Krestiki, nomer_X, 165, 330, nolic);
        int nolicV33 = getKrestik (Krestiki, nomer_X, 330, 330, nolic);



        //��� ���� ����� ���� for ������, ��?
        if (krestikV11 == 1 && krestikV12 == 1 && krestikV13 == 1)
        {
            gameOver = true;
        }
        if (krestikV21 == 1 && krestikV22 == 1 && krestikV23 == 1)
        {
            gameOver = true;
        }
        if (krestikV31 == 1 && krestikV32 == 1 && krestikV33 == 1)
        {
            gameOver = true;
        }
        if (krestikV11 == 1 && krestikV21 == 1 && krestikV31 == 1)
        {
            gameOver = true;
        }
        if (krestikV12 == 1 && krestikV22 == 1 && krestikV32 == 1)
        {
            gameOver = true;
        }
        if (krestikV13 == 1 && krestikV23 == 1 && krestikV33 == 1)
        {
            gameOver = true;
        }
        if (krestikV11 == 1 && krestikV22 == 1 && krestikV33 == 1)
        {
            gameOver = true;
        }
        if (krestikV13 == 1 && krestikV22 == 1 && krestikV31 == 1)
        {
            gameOver = true;
        }
        if (nolicV11 == 1 && nolicV12 == 1 && nolicV13 == 1)
        {
            gameOver = true;
        }
        if (nolicV21 == 1 && nolicV22 == 1 && nolicV23 == 1)
        {
            gameOver = true;
        }
        if (nolicV31 == 1 && nolicV32 == 1 && nolicV33 == 1)
        {
            gameOver = true;
        }
        if (nolicV11 == 1 && nolicV21 == 1 && nolicV31 == 1)
        {
            gameOver = true;
        }
        if (nolicV12 == 1 && nolicV22 == 1 && nolicV32 == 1)
        {
            gameOver = true;
        }
        if (nolicV13 == 1 && nolicV23 == 1 && nolicV33 == 1)
        {
            gameOver = true;
        }
        if (nolicV11 == 1 && nolicV22 == 1 && nolicV33 == 1)
        {
            gameOver = true;
        }
        if (nolicV13 == 1 && nolicV22 == 1 && nolicV31 == 1)
        {
            gameOver = true;
        }


        txSleep(10);
		txEnd();
    }

    return 0;
}
