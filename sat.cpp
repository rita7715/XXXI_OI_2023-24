#include <bits/stdc++.h>

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
 cin.tie(0);
    int n, p, m;
    cin >> n >> p >> m;
    vector <string> kody;
    set <int> rozne1;
    set <int> rozne2;
    for (int i=0;i<=2*n;i++)
    {
        kody.push_back("");
    }
    int tmp1, tmp2;;

    vector <vector <int> > polaczenia_inaczej;
    vector <vector <int> > pol1;
     vector <vector <int> > pol2;
     unordered_map <int, vector <int> > detektor;
    vector <int> tmpv;
   for (int i=0;i<=2*n;i++)
    {
        polaczenia_inaczej.push_back(tmpv);

    }
    for (int i=0;i<n;i++)
    {
        pol1.push_back(tmpv);
        pol2.push_back(tmpv);
    }
    vector <pair <int, int> > polaczenia;
    for (int i=0;i<p;i++)
    {
        cin  >> tmp1 >> tmp2;
        rozne1.insert(tmp1);
        rozne2.insert(tmp2);
        pol1[tmp1-1].push_back(tmp2);
        pol2[tmp2-1-n].push_back(tmp1);
        polaczenia.push_back({tmp1, tmp2});

        tmp1=0;
        tmp2=0;
    }
    for (int i=0;i<n;i++)
    {
       sort( pol1[i].begin(), pol1[i].end() );
        sort( pol2[i].begin(), pol2[i].end() );
    }
    sort( pol1.begin(), pol1.end() );
pol1.erase( unique( pol1.begin(), pol1.end() ), pol1.end() );
sort( pol2.begin(), pol2.end() );
pol2.erase( unique( pol2.begin(), pol2.end() ), pol2.end() );
if (rozne1.size() > rozne2.size() && pol1.size() == pol2.size())
{
    pol1.push_back(tmpv);
}

  //  cout << rozne1.size() << " " << rozne2.size();
    if (pol2.size() < pol1.size())
    {
        for (int i=0;i<p;i++)
        {
            polaczenia_inaczej[polaczenia[i].second].push_back(polaczenia[i].first);
        }
        for (int i=n+1;i<=n*2;i++)
    {
        sort(polaczenia_inaczej[i].begin(), polaczenia_inaczej[i].end());
    }
    int wykonane_polaczenia = 0;

    int wykonane_dla[2*n+1] = {0};
        bool wyjscie = false;
        m=n;
        int poczatek=0;
        vector <int> gdzie_c;

        if (p!=0){
        for (int i=n+1;i<=2*n;i++)
        {
            gdzie_c.clear();

            if (polaczenia_inaczej[i].size() - wykonane_dla[i] == 0)
            {
                continue;
            }
            for (int j=0;j<polaczenia_inaczej[i].size();j++)
            {
                ++wykonane_polaczenia;
                kody[polaczenia_inaczej[i][j]] += "A";
            }
            for (int j=1;j<=n;j++)
            {
                if (kody[j].length() != kody[i].length()+1)
                {
                    kody[j] += "C";
                    gdzie_c.push_back(j);
                }
            }
            if (gdzie_c.size()==0)
            {
                int pp = 0;
                for (int j=n+1;j<=n+n;j++)
            {

                if (j != i && polaczenia_inaczej[j] != polaczenia_inaczej[i])
                {
                    ++pp;
                    if (pp%2==0)
                    {

                        kody[j] += "C";
                    }else
                    {
                        kody[j] += "B";
                    }

                }else
                {
                    kody[j] += "A";

                    wykonane_dla[j] += polaczenia_inaczej[i].size();

                    if (j>i){
                            detektor[i].push_back(j);
                    wykonane_polaczenia+= polaczenia_inaczej[i].size();
                    }
                }
            }
            if (kody[1].length()==m || wykonane_polaczenia >= p)
            {
                break;
            }else
            {
                continue;
            }
            }
            int da=0, dc=0;
            for (int j=n+1;j<=n+n;j++)
            {
                if (j != i && polaczenia_inaczej[j] != polaczenia_inaczej[i])
                {

                    if (polaczenia_inaczej[j] == gdzie_c && j>i && gdzie_c.size()!=0)
                    {
                        wykonane_polaczenia += gdzie_c.size();
                        wykonane_dla[j] += gdzie_c.size();


                        kody[j] += "C";
                    }else
                    {





                        kody[j] += "B";



                    }




                }else
                {
                    kody[j] += "A";
                    wykonane_dla[j] += polaczenia_inaczej[i].size();

                    if (j>i){
                            detektor[i].push_back(j);
                    wykonane_polaczenia+= polaczenia_inaczej[i].size();
                    }
                }

            }
            if (wykonane_polaczenia >= p)
            {
                break;
            }
        }
        }

    }else{

        for (int i=0;i<p;i++)
        {
            polaczenia_inaczej[polaczenia[i].first].push_back(polaczenia[i].second);
        }

    polaczenia_inaczej[0].push_back(0);
    for (int i=1;i<=n;i++)
    {
        sort(polaczenia_inaczej[i].begin(), polaczenia_inaczej[i].end());
    }

    int wykonane_polaczenia = 0;
    int wykonane_dla[n+1] = {0};
        bool wyjscie = false;
        m=n;
        int poczatek=0;
        vector <int> gdzie_c;
        if (p!=0){
        for (int i=1;i<=n;i++)
        {
            gdzie_c.clear();

            if (polaczenia_inaczej[i].size() - wykonane_dla[i] == 0)
            {
                continue;
            }
            for (int j=0;j<polaczenia_inaczej[i].size();j++)
            {
                ++wykonane_polaczenia;
                kody[polaczenia_inaczej[i][j]] += "A";
            }
            for (int j=n+1;j<=2*n;j++)
            {
                if (kody[j].length() != kody[i].length()+1)
                {
                    kody[j] += "C";
                    gdzie_c.push_back(j);
                }
            }
            if (gdzie_c.size()==0)
            {
                int pp = 0;
                for (int j=1;j<=n;j++)
            {

                if (j != i && polaczenia_inaczej[j] != polaczenia_inaczej[i])
                {
                    ++pp;
                    if (pp%2==0)
                    {

                        kody[j] += "C";
                    }else
                    {
                        kody[j] += "B";
                    }

                }else
                {
                    kody[j] += "A";

                    wykonane_dla[j] += polaczenia_inaczej[i].size();

                    if (j>i){
                    wykonane_polaczenia+= polaczenia_inaczej[i].size();
                    detektor[i].push_back(j);
                    }
                }
            }
            if (kody[1].length()==m || wykonane_polaczenia >= p)
            {
                break;
            }else
            {
                continue;
            }
            }
            int da=0, dc=0;
            for (int j=1;j<=n;j++)
            {
                if (j != i && polaczenia_inaczej[j] != polaczenia_inaczej[i])
                {

                    if (polaczenia_inaczej[j] == gdzie_c && j>i && gdzie_c.size()!=0)
                    {
                        wykonane_polaczenia += gdzie_c.size();
                        wykonane_dla[j] += gdzie_c.size();


                        kody[j] += "C";
                    }else
                    {





                        kody[j] += "B";



                    }




                }else
                {
                    kody[j] += "A";
                    wykonane_dla[j] += polaczenia_inaczej[i].size();

                    if (j>i){
                            detektor[i].push_back(j);

                    wykonane_polaczenia+= polaczenia_inaczej[i].size();
                    }
                }

            }
            if (wykonane_polaczenia >= p)
            {
                break;
            }
        }
        }
      //  cout << kody[1].length() << "\n";
    }









        vector <string>kody2;
        kody2.push_back("");
        for (int i=n+1;i<kody.size();i++)
        {
            kody2.push_back(kody[i]);
        }
        for (int i=0;i<n;i++)
        {
            kody.pop_back();
        }




    bool zostanie = true;
while (zostanie==true)
{

unordered_map<string, int> stringCount;
    unordered_map<string, vector<int>> stringPositions;
    for (int i = 0; i < kody.size(); i++) {
        const string& currentString = kody[i];

        stringCount[currentString]++;


        stringPositions[currentString].push_back(i);
    }
    int maxIntValue = numeric_limits<int>::min();
    for (const auto& pair : stringCount) {
        if (pair.second > maxIntValue) {
            maxIntValue = pair.second;
        }
    }
    if (maxIntValue == 1)
    {
        zostanie=false;
        break;
    }


    for (const auto& entry : stringCount) {
        if (entry.second > 1) {
            const vector<int>& positions = stringPositions[entry.first];
            bool oznakowanie = false;
            for (int i=0;i<positions.size()/2;i++) {
                kody[positions[i]] += "B";
                kody2[positions[i]] += "C";
            }
            for (int i=positions.size()/2;i<positions.size();i++) {
                        kody[positions[i]] += "A";
                kody2[positions[i]] += "C";
            }        }else
        {

            const vector<int>& positionn = stringPositions[entry.first];
            for (int i=0;i<positionn.size();i++)
            {
                kody[positionn[i]] += "B";
                kody2[positionn[i]] += "C";
            }
        }
    }
}



while (zostanie==false)
{

std::unordered_map<std::string, int> stringCount;
    std::unordered_map<std::string, std::vector<int>> stringPositions;
    for (int i = 0; i < kody2.size(); i++) {
        const std::string& currentString = kody2[i];
        stringCount[currentString]++;

        stringPositions[currentString].push_back(i);
    }
    int maxIntValue = std::numeric_limits<int>::min();
    for (const auto& pair : stringCount) {
        if (pair.second > maxIntValue) {
            maxIntValue = pair.second;
        }
    }
    if (maxIntValue == 1)
    {
        zostanie=true;
        break;
    }


    for (const auto& entry : stringCount) {
        if (entry.second > 1) {            const std::vector<int>& positions = stringPositions[entry.first];
            bool oznakowanie = false;
            for (int i=0;i<positions.size()/2;i++) {
                kody[positions[i]] += "B";
                kody2[positions[i]] += "C";
            }
            for (int i=positions.size()/2;i<positions.size();i++) {
                kody[positions[i]] += "B";
                kody2[positions[i]] += "A";
            }
        }else
        {

            const std::vector<int>& positionn = stringPositions[entry.first];
            for (int i=0;i<positionn.size();i++)
            {
                kody[positionn[i]] += "B";
                kody2[positionn[i]] += "C";
            }
        }
    }
}




if (kody[1].length() <n+1)
{
     for (int i=1;i<=n;i++)
        {
            kody[i] += "B";
            kody2[i] += "C";
        }
}



cout << kody[1].length() << "\n";
    for (int i=1;i<=n;i++)
        {
    cout << kody[i] << "\n";
        }
        for (int i=1;i<=n;i++)
        {
        cout << kody2[i] << "\n";
        }






//cout << shfjkfjkf<<"\n";












    return 0;
}
