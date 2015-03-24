//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Source.h"

namespace projet_mostefaoui {

Define_Module(Source);

Source::Source()
{
    timerMessage = NULL;
}

Source::~Source()
{
    cancelAndDelete(timerMessage);
}
    double Emp;
    int dBS,Efs,Eelec,EDA,N,k;
    double dCH[3]={50,82.6,98.23};
    int l[4]={1000,1500,2000,4500};


void Source::initialize()
{
    timerMessage = new cMessage("timer");
    scheduleAt(simTime(), timerMessage);
    Eelec=50;
    Efs=10;
    Emp=0.0013;
    EDA=5;
    dBS=100;
    Bi=5000000;
    k=1;
    N=4;
    cMessage *msg = new cMessage("data");
    msg->setKind(0);
}

double Source::fECH(){
    double ECH=(double)(l[4]*Eelec*(((double)N/k)-1) + l[4]*EDA*((double)N/k) + l[4]*Eelec + l[4]*Emp*dBS*dBS*dBS*dBS)/1000000000000;
    return ECH;
}

double Source::fEnonCH(int i){
    double EnonCH = ((double)(l[i]*Eelec + l[i]*Efs*dCH[i]*dCH[i])/1000000000000);
    return EnonCH;
}

void Source::handleMessage(cMessage *msg)
{   int id=getIndex();
    ASSERT(msg==timerMessage);

    cMessage *job = new cMessage("job");
    send(job, "out");

    scheduleAt(simTime()+par("sendInterval").doubleValue(), timerMessage);
    job->setKind(0);
    Bi = Bi - (double)fEnonCH(id);
    ev<<Bi<<endl;
    if(Bi<=0){
        ev<<"!!!"<<endl;
        endSimulation();
    }

}

}; // namespace
