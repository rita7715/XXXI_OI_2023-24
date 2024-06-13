#include <bits/stdc++.h>
using namespace std;


int m, n;
set <pair <int, int> > zajete;
int dsk=0, dsk2=0, dsk3=0, dsk4=0;
int dot_poz=0, dot_pion=0;
int func(char **zmieniana_plyta, int konieczna)
{
    int max = 0;
    pair <int, int> koniec;
    for (int i = 0; i < n; i++)
    {
        int zliczanie = 0;
        for (int j = 0; j < n; j++)
        {
            if (zmieniana_plyta[i][j] == '.')
                zliczanie++;

            if (zliczanie > max && zliczanie <=konieczna)
            {
                max = zliczanie;
                koniec.first=i;
                koniec.second=j;
            }


            if (zmieniana_plyta[i][j] != '.')
                zliczanie = 0;
        }
    }
    bool czy_pionowo = false;
    for (int i = 0; i < n; i++)
    {
        int number = 0;
        for (int j = 0; j < n; j++)
        {
            if (zmieniana_plyta[j][i] == '.')
                number++;

            if (number > max && number <=konieczna)
            {
                 max = number;
                koniec.first=j;
                koniec.second=i;
                czy_pionowo=true;
            }


            if (zmieniana_plyta[j][i] != '.')
                number = 0;
        }
    }
    if (czy_pionowo==false)
    {
        dot_poz+=1;
            for (int j=koniec.second;j>koniec.second-max;j--)
            {
                cout << koniec.first << "," << j << " ";
                zajete.insert({koniec.first, j});
                zmieniana_plyta[koniec.first][j] = 'X';
            }

    }else
    {
        dot_pion+=1;
        for (int j=koniec.first;j>koniec.first-max;j--)
            {
                cout << j << "," << koniec.second << " ";
                zajete.insert({j, koniec.second});
                zmieniana_plyta[j][koniec.second] = 'X';
            }
    }

    return max;
}

int funcvertical(char **zmieniana_plyta, int konieczna)
{
    ++dot_pion;
    int max = 0;
    pair <int, int> koniec;

    bool czy_pionowo = false;
    for (int i = 0; i < n; i++)
    {
        int number = 0;
        for (int j = 0; j < n; j++)
        {
            if (zmieniana_plyta[j][i] == '.')
                number++;

            if (number > max && number <=konieczna)
            {
                 max = number;
                koniec.first=j;
                koniec.second=i;
                czy_pionowo=true;
            }


            if (zmieniana_plyta[j][i] != '.')
                number = 0;
        }
    }
     for (int j=koniec.first;j>koniec.first-max;j--)
            {
                cout << j << "," << koniec.second << " ";
                //zajete.insert({j, koniec.second});
                zmieniana_plyta[j][koniec.second] = 'X';
            }


    return max;
}


int funchorizontal(char **zmieniana_plyta, int konieczna)
{
    ++dot_poz;
    int max = 0;
    pair <int, int> koniec;

    bool czy_pionowo = false;
    for (int i = 0; i < n; i++)
    {
        int number = 0;
        for (int j = 0; j < n; j++)
        {
            if (zmieniana_plyta[i][j] == '.')
                number++;

            if (number > max && number <=konieczna)
            {
                 max = number;
                koniec.first=i;
                koniec.second=j;
                czy_pionowo=true;
            }


            if (zmieniana_plyta[i][j] != '.')
                number = 0;
        }
    }
    for (int j=koniec.second;j>koniec.second-max;j--)
            {
                cout << koniec.first << "," << j << " ";
              //  zajete.insert({koniec.first, j});
                zmieniana_plyta[koniec.first][j] = 'X';
            }


    return max;
}



bool czy_polaczono;
int func2(char **zmieniana_plyta, int konieczna)
{
    int max = 0;
    int uzyte=0;
    bool wzieto=false;
    pair <int, int> koniec;
    for (int i = 0; i < n; i++)
    {
        int zliczanie = 0;
        uzyte=0;
        dsk=0;
                dsk2=0;
                dsk3=0;
                dsk4=0;
        for (int j = 0; j < n; j++)
        {
            bool zmniejszono=false;
            wzieto=false;
            if (zmieniana_plyta[i][j] == '.' ){
                ++zliczanie;

            }else
            {
                if ((zajete.count({i, j}) && uzyte==0)){
                        dsk=1;

                for (int k=i;k<n;k++)
                {
                    if (zajete.count({k,j}))
                        {
                            ++dsk3;
                        }
                }
                for (int k=i;k>=0;k--)
                {
                    if (zajete.count({k,j}))
                        {
                            ++dsk4;
                        }
                }
                ++zliczanie;
                ++uzyte;
                dsk2 = zliczanie;

                wzieto=true;
                }
            }
            int temp;
            if (uzyte==1){
            if (zliczanie <= dsk3-1 || zliczanie <= dsk4-1)
            {
                dsk=0;
            }else
            {
                int c= zliczanie-dsk2;
                if (c>=dsk3-1 && c>=dsk4-1)
                {
                    dsk=dsk2;
                }else
                {
                    if (dsk3>dsk4)
                    {
                        dsk=zliczanie-dsk3+1;
                    }else
                    {
                        dsk=zliczanie-dsk4+1;
                    }
                }
            }
            }



            if (zliczanie == max && uzyte==0)
            {
                max = zliczanie;
                koniec.first=i;
                koniec.second=j;
                czy_polaczono=false;
            }
            if (zliczanie-dsk > max && zliczanie <=konieczna)
            {
                max = zliczanie-dsk;
                koniec.first=i;
                koniec.second=j;
                if (uzyte!=0)
                {
                    czy_polaczono=true;
                }else
                {
                    czy_polaczono=false;
                }
            }
            if (max==konieczna)
            {
                return max;
            }



            if (zmieniana_plyta[i][j] != '.' && wzieto==false){

                zliczanie = 0;
                uzyte=0;
                dsk=0;
                dsk2=0;
                dsk3=0;
                dsk4=0;

            }
        }
    }
    bool czy_pionowo = false;
    for (int i = 0; i < n; i++)
    {
        int zliczanie = 0;
        int number = 0;
        uzyte=0;
        dsk=0;
                dsk2=0;
                dsk3=0;
                dsk4=0;

        for (int j = 0; j < n; j++)
        {
            wzieto=false;
            bool zmniejszono=false;

            if (zmieniana_plyta[j][i] == '.' ){
                ++zliczanie;


            }else
            {
                if ((zajete.count({j, i}) && uzyte==0)){
                        dsk=1;

                for (int k=i;k<n;k++)
                {
                    if (zajete.count({j,k}))
                        {
                            ++dsk3;
                         //   cout << dsk3 << "\n";
                        }
                }
                for (int k=i;k>=0;k--)
                {
                    if (zajete.count({j,k}))
                        {
                            ++dsk4;
                        }
                }
                ++zliczanie;
                ++uzyte;
                dsk2 = zliczanie;
                if (dsk2>dsk3)
                {
                    dsk2=dsk3;
                }
                if (dsk2>dsk4)
                {
                    dsk2=dsk4;
                }
               // cout << "\n" << dsk2 << "\n";
                wzieto=true;

                }
            }
            int temp;

            if (uzyte==1){
            if (zliczanie <= dsk3-1 || zliczanie <= dsk4-1)
            {
                dsk=0;
            }else
            {
                int c= zliczanie-dsk2;
                if (c>=dsk3-1 && c>=dsk4-1)
                {
                    dsk=dsk2;
                }else
                {
                    if (dsk3>dsk4)
                    {
                        dsk=zliczanie-dsk3+1;
                    }else
                    {
                        dsk=zliczanie-dsk4+1;
                    }

                }
            }
            }

            if (zliczanie == max && uzyte==0)
            {
                max = zliczanie;
                koniec.first=i;
                koniec.second=j;
                czy_polaczono=false;
            }
            if (zliczanie-dsk > max && zliczanie <=konieczna)
            {
                max = zliczanie-dsk;
                koniec.first=i;
                koniec.second=j;
                if (uzyte!=0)
                {
                    czy_polaczono=true;
                }else
                {
                    czy_polaczono=false;
                }
            }



            if (zmieniana_plyta[j][i] != '.' && wzieto==false){


                zliczanie = 0;
                uzyte=0;
                dsk=0;
                dsk2=0;
                dsk3=0;
                dsk4=0;

            }
        }
    }


    return max;
}








int main()
{
    ifstream wejscie ("o1ocen.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    wejscie >> n >> m;
    char** plyta_startowa =new char *[n];
    for (int i = 0; i < n; i++)
    {
        plyta_startowa[i] = new char[n];
        for (int j = 0; j < n; j++)
        {
            wejscie >> plyta_startowa[i][j];
        }
    }
    char** plyta_startowa2 =new char *[n];
    for (int i = 0; i < n; i++)
    {
        plyta_startowa2[i] = new char[n];
        for (int j = 0; j < n; j++)
        {
            plyta_startowa2[i][j] = plyta_startowa[i][j];
        }
    }
    int h1, h2, v1, v2;
    while (dot_pion<2)
    {
        v1 = funcvertical(plyta_startowa2, n);
        cout << "\n\n";
        v2 = funcvertical(plyta_startowa2, n);
        cout << "\n\n";
    }
    char** plyta_startowa3 =new char *[n];
    for (int i = 0; i < n; i++)
    {
        plyta_startowa3[i] = new char[n];
        for (int j = 0; j < n; j++)
        {
            plyta_startowa3[i][j] = plyta_startowa[i][j];
        }
    }
    while(dot_poz<2)
    {
        h1 = funchorizontal(plyta_startowa3, n);
        cout << "\n\n";
        h2 = funchorizontal(plyta_startowa3, n);
        cout << "\n\n";
    }
    int result = func(plyta_startowa, n);

    cout << "\n";
    if (m==2)
    {

        int x = func2(plyta_startowa, result);
        if (x>result/2)
        {
            result = x;
        }else
        {
            result = result/2;
        }
        if (h2>result)
        {
            result=h2;
        }
        if (v2>result)
        {
            result=v2;
        }

    }

    cout << result;



    return 0;
}
