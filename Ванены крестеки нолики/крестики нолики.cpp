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

    while (!GetAsyncKeyState(VK_ESCAPE))
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



     txSleep(10);
		txEnd();
   }

  return 0;
}
