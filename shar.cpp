#include "TXLib.h"
int seichas_v = 0;
int bil_v = 0;
int idet_v = 0;

void obl,poloj1()
{
  obl.poloj == 1;
}
void obl,poloj2()
{
  obl.poloj == 2;
}
void obl,poloj3()
{
  obl.poloj == 3;
}
void obl,poloj4()
{
  obl.poloj == 4;
}
void obl,poloj5()
{
  obl.poloj == 5;
}
void obl,poloj6()
{
  obl.poloj == 6;
}

if obl_poloj(obl, nomer_stolbca, 3)



struct tohka_Shara
{
  int xs;
  int ys;
};

//Shar1.xs = get_x_shara(2);

int get_x_shara(int nomer_stolbca); //x 288                            288,161     388,261   ������� � 100
int get_y_shara(int nomer_stroki); //y161

int get_y_shara(int nomer_stroki)
{
    int y_shara =  get_min_y(nomer_stroki) + 25;
    return y_shara;
}

int get_x_shara(int nomer_stolbca)
{
    int x_shara =  get_min_x(nomer_stolbca) + 25;
    return x_shara;
}

int kolvo_obl_shar = 40;

if(obl.lx < x_shara < obl.rx and obl.vy < y_shara < obl.ny) //� ����� ������� ������ ���
{
    int seichas_v = nomer_obl;
}

 if(y_shara + 75 == obl,poloj1() or y_shara + 75 = obl,poloj2() or y_shara + 75 = obl,poloj6() )
   {
      move_ball_down();
   }
else if(y_shara + 75 == obl,poloj3() or y_shara + 75 = obl,poloj4() or y_shara + 75 = obl,poloj4())
   {

   }


int proverit_chto_mozhno_idti_suda(
    Oblast* oblasti,   int KOLVO_OBLASTEI,
    int x_old, int y_old,
    int x_new, int y_new)
{
    int normalnyi_x_y_old = 0;
    int normalnyi_x_y_new = 0;

        for (int  nomer = 0; nomer < KOLVO_OBLASTEI; nomer++)
        {
            //��������, ����� ������
            if (x_new > x_old)
            {
                //�� ������ ����� ����� ���� ������
                if (oblasti[nomer].lx == x_old &&
                    oblasti[nomer].vy == y_old &&
                    (oblasti[nomer].poloj == 1  or oblasti[nomer].poloj == 3  or oblasti[nomer].poloj == 5    ))
                {
                    normalnyi_x_y_old  = 1;
                }

                //� ����� ����� ����� ������ �����
                if (oblasti[nomer].lx == x_new &&
                    oblasti[nomer].vy == y_new &&
                    (oblasti[nomer].poloj == 2  or oblasti[nomer].poloj == 4  or oblasti[nomer].poloj == 5    ))
                {
                    normalnyi_x_y_new  = 1;
                }
            }

            //��������, ����� ������
            else if (y_new > y_old)
            {
                //�� ������ ����� ����� ���� ������
                if (oblasti[nomer].lx == x_old &&
                    oblasti[nomer].vy == y_old &&
                    (oblasti[nomer].poloj == 3  or oblasti[nomer].poloj == 4  or oblasti[nomer].poloj == 6    ))
                {
                    normalnyi_x_y_old  = 1;
                }

                //� ����� ����� ����� ������ �����
                if (oblasti[nomer].lx == x_new &&
                    oblasti[nomer].vy == y_new &&
                    (oblasti[nomer].poloj == 1  or oblasti[nomer].poloj == 2  or oblasti[nomer].poloj == 6    ))
                {
                    normalnyi_x_y_new  = 1;
                }
            }
        }

        if (normalnyi_x_y_old && normalnyi_x_y_new)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

*/