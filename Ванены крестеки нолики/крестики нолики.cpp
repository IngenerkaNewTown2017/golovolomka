#include "TXLib.h"

struct KrestIliNol
{
    int x;
    int y;
    int risovat;
    HDC pic;
};

  int jopa()
{
 //txCreateWindow(490,490);

HDC fon = txLoadImage ("крестикинолики.bmp");

HDC krestic = txLoadImage ("крестик.bmp");
txBitBlt (txDC(), 0, 0, 162, 163, krestic, 0, 0);

HDC nolic = txLoadImage ("нолик.bmp");
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
            txMouseButtons() & 2) //крестики
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


       int krestikV11 = 0;

		for (int counter = 0; counter < nomer_X; counter++)
        {
            if (Krestiki[counter].risovat  == true &&
                Krestiki[counter].x == 0 &&
                Krestiki[counter].y == 0 &&
                Krestiki[counter].pic == krestic)
            {
                krestikV11 = 1;
            }
        }


       int krestikV12 = 0;

		for (int counter = 0; counter < nomer_X; counter++)
        {
            if (Krestiki[counter].risovat  == true &&
                Krestiki[counter].x == 165 &&
                Krestiki[counter].y == 0 &&
                Krestiki[counter].pic == krestic)
            {
                krestikV12 = 1;
            }
        }


       int krestikV13 = 0;

		for (int counter = 0; counter < nomer_X; counter++)
        {
            if (Krestiki[counter].risovat  == true &&
                Krestiki[counter].x == 330 &&
                Krestiki[counter].y == 0 &&
                Krestiki[counter].pic == krestic)
            {
                krestikV13 = 1;
            }
        }



       int krestikV21 = 0;

		for (int counter = 0; counter < nomer_X; counter++)
        {
            if (Krestiki[counter].risovat  == true &&
                Krestiki[counter].x == 0 &&
                Krestiki[counter].y == 165 &&
                Krestiki[counter].pic == krestic)
            {
                krestikV21 = 1;
            }
        }

     int krestikV31 = 0;

		for (int counter = 0; counter < nomer_X; counter++)
        {
            if (Krestiki[counter].risovat  == true &&
                Krestiki[counter].x == 0 &&
                Krestiki[counter].y == 330 &&
                Krestiki[counter].pic == krestic)
            {
                krestikV31 = 1;
            }
        }

        int krestikV41 = 0;

		for (int counter = 0; counter < nomer_X; counter++)
        {
            if (Krestiki[counter].risovat  == true &&
                Krestiki[counter].x == 330 &&
                Krestiki[counter].y == 165 &&
                Krestiki[counter].pic == krestic)
            {
                krestikV41 = 1;
            }
        }

    int krestikV51 = 0;

		for (int counter = 0; counter < nomer_X; counter++)
        {
            if (Krestiki[counter].risovat  == true &&
                Krestiki[counter].x == 330 &&
                Krestiki[counter].y == 330 &&
                Krestiki[counter].pic == krestic)
            {
                krestikV51 = 1;
            }
        }

     int krestikV61 = 0;

		for (int counter = 0; counter < nomer_X; counter++)
        {
            if (Krestiki[counter].risovat  == true &&
                Krestiki[counter].x == 165 &&
                Krestiki[counter].y == 330 &&
                Krestiki[counter].pic == krestic)
            {
                krestikV61 = 1;
            }
        }

     int krestikV71 = 0;

		for (int counter = 0; counter < nomer_X; counter++)
        {
            if (Krestiki[counter].risovat  == true &&
                Krestiki[counter].x == 165 &&
                Krestiki[counter].y == 165 &&
                Krestiki[counter].pic == krestic)
            {
                krestikV71 = 1;
            }
        }

        if (krestikV11 == 1 && krestikV12 == 1 && krestikV13 == 1)
        {
        gameOver = true;
        }
        if (krestikV11 == 1 && krestikV21 == 1 && krestikV31 == 1)
        {
        gameOver = true;
        }
        if (krestikV13 == 1 && krestikV41 == 1 && krestikV51 == 1)
        {
        gameOver = true;
        }
        if (krestikV31 == 1 && krestikV61 == 1 && krestikV51 == 1)
        {
        gameOver = true;
        }
        if (krestikV12 == 1 && krestikV71 == 1 && krestikV61 == 1)
        {
        gameOver = true;
        }
        if (krestikV11 == 1 && krestikV71 == 1 && krestikV51 == 1)
        {
        gameOver = true;
        }
        if (krestikV21 == 1 && krestikV71 == 1 && krestikV41 == 1)
        {
        gameOver = true;
        }
        if (krestikV13 == 1 && krestikV71 == 1 && krestikV31 == 1)
        {
        gameOver = true;
        }

     txSleep(10);
		txEnd();
   }

  return 0;
}
