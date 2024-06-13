#include <bits/stdc++.h>
using namespace std;
struct wyklad {
    int order;
    int startTime;
    int endTime;
};

vector <wyklad>  scheduleEvents(vector<wyklad>& wyklady) {
    sort(wyklady.begin(), wyklady.end(), [](const wyklad& a, const wyklad& b) {
         if (a.endTime !=b.endTime){
        return a.endTime < b.endTime;}else{
        return a.startTime > b.startTime;
        }
    });

   vector<wyklad>  scheduledEvents;
    vector<wyklad> scheduledEvents2;
    int lastScheduledTime = 0;

    for (const wyklad& wykklad : wyklady)
        {
        if (wykklad.startTime >= lastScheduledTime) {





            scheduledEvents.push_back( wykklad );
            lastScheduledTime = wykklad.endTime;


        }
        }



    return scheduledEvents;

}

vector <wyklad>  schodki(vector<wyklad>& wyklady) {
    sort(wyklady.begin(), wyklady.end(), [](const wyklad& a, const wyklad& b) {
         if (a.endTime !=b.endTime)
        return a.endTime < b.endTime;
        return a.startTime > b.startTime;
    });

   vector<wyklad>  scheduledEvents;
    vector<wyklad> scheduledEvents2;
    int lastScheduledTime = 0;
    int lastScheduledTime2 = 0;
    int secondscheduled=0;
    int na_zmiane=0;
    wyklad na_zastepstwo = {0,0,0};

    for (const wyklad& wykklad : wyklady)
        {

            if (na_zmiane%2==0){

        if (wykklad.startTime >= lastScheduledTime && wykklad.startTime >= secondscheduled) {
               // cout << "1 " << wykklad.endTime << "\n";

            scheduledEvents.push_back( wykklad );
            lastScheduledTime2=lastScheduledTime;
            lastScheduledTime = wykklad.endTime;
            ++na_zmiane;
            if (na_zastepstwo.endTime != 0 )
                {
                    scheduledEvents.push_back( na_zastepstwo );
                    ++na_zmiane;
                    if (wykklad.startTime < na_zastepstwo.endTime)
                    {
                        secondscheduled = na_zastepstwo.endTime;
                        na_zastepstwo = {0,0,0};

                    }



                }


        }else
        {
            if (wykklad.startTime >= lastScheduledTime)
            {
                na_zastepstwo = wykklad;
            }
        }
            }else
            {
                if (wykklad.startTime >= lastScheduledTime2)
                {
                    scheduledEvents.push_back( wykklad );
                    secondscheduled = wykklad.endTime;

                    ++na_zmiane;
                }
            }





        }



    return scheduledEvents;

}





int main() {
    int ile;
    cin>> ile;
    vector<wyklad> wyklady;
    vector<wyklad> ostateczne;
    int tmp1, tmp2;
    for (int i=1;i<=ile;i++)
    {
        cin >> tmp1 >> tmp2;
        wyklady.push_back({i, tmp1, tmp2});
    }
    vector <wyklad> pelne_schodki = schodki(wyklady);

    vector <wyklad>  scheduledEvents = scheduleEvents(wyklady);
    if (pelne_schodki.size()/2 >= scheduledEvents.size())
    {
        for (int i=0;i<pelne_schodki.size();i++)
    {

           ostateczne.push_back(pelne_schodki[i]);
    }
    }else{


    bool do_usuniecia=false;




    for (int i=0;i<scheduledEvents.size()-1;i++)
    {

            ostateczne.push_back(scheduledEvents[i]);
            ostateczne.push_back(scheduledEvents[scheduledEvents.size()-1]);
    }
    }

cout << ostateczne.size()/2 << "\n";
    for (int i=0;i<ostateczne.size();i=i+2)
    {
    cout <<ostateczne[i].order <<  " "  <<ostateczne[i+1].order << "\n";
    }

    return 0;
}
