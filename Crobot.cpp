#include <iostream>
#include <conio.h>
#include <ctime>
#include "Crobot.h"
using namespace std;
Crobot::Crobot(char name,int dol,int HP,int MP,int Atk,int Def,int Agi){
    this->name = name;
    this->dol = dol;
    this->HP = HP;
    this->MP = MP;
    this->Atk = Atk;
    this->Def = Def;
    this->Agi = Agi;
    //ctor
}

Crobot::~Crobot(){
    //dtor
}

void Crobot::showdata(void){
    cout <<Getname() << "," << GetHP() << "," << GetMP();
    cout << ","<< GetAtk() << ","<< GetDef() << endl;
}

int Arr[3];//儲存隨機變數的陣列，第一個不用
void Crobot::random(void){//製造隨機變數的陣列
        srand((unsigned)time(NULL));
        int low=1,up=2;//上下限
        double r01,r;
        for(int i=0;i<3;i++){
            r01=(double)rand()/(RAND_MAX);
            r=r01*(up-low+1.0)+low;
            Arr[i]=r;
        }
}


void Crobot::healing(void){
    if(Getname()=='W'){
    }
    else{
        HP+=10;
        cout <<Getname()<<"回血中"<< endl;
        cout <<Getname()<<"的血量變成了" << GetHP() << endl;
    }

}

bool Crobot::evasion(void){
        srand((unsigned)time(NULL));
        int low=1,up=100;//上下限
        double r01,r;
        r01=(double)rand()/(RAND_MAX);
        r=r01*(up-low+1.0)+low;
        if(Agi>r)
            return true;
        else
            return false;
}


void Crobot::fight(Crobot &C2){
    if(Getname()=='W'){
            random();
        if (Arr[2]==1){
            C2.HP-=5*(GetAtk()-C2.Def);
            cout <<Getname()<<"使出普通攻擊"<< endl;
            cout <<C2.Getname()<<"的血量變成了" << C2.GetHP() << endl;
        }
        else if (Arr[2]==2){
            C2.HP-=15*(GetAtk()-C2.Def);
            cout <<Getname()<<"使出超級攻擊"<< endl;
            cout <<C2.Getname()<<"的血量變成了" << C2.GetHP() << endl;
        }
    }
    else{
        while(1){
            char k,c=0;
            cout <<"    1:普通攻擊；2:魔法攻擊"<<endl;
            k=getch();
            if (k=='1'){
                C2.HP-=(GetAtk()-C2.Def);
                cout <<Getname()<<"使出普通攻擊"<< endl;
                cout <<C2.Getname()<<"的血量變成了" << C2.GetHP() << endl;
            }
            if (k=='2'){
                if(MP>=2){
                    C2.HP-=10*(GetAtk()-C2.Def);
                    MP-=2;
                    cout <<Getname()<<"使出魔法攻擊"<< endl;
                    cout <<C2.Getname()<<"的血量變成了" << C2.GetHP() << endl;
                }
                else{
                    cout<<"MP不足，無法使出魔法攻擊。"<<endl;
                    c=1;
                }
            }
            if(c!=1)
                break;
        }

    }


}

void Crobot::action(Crobot &C2,Crobot &C3){
    if(Getname()=='W')
    {
        random();
        if (Arr[1]==1){
            if(C2.dol!=1)
            fight(C2);
            else
            fight(C3);
        }
        else if (Arr[1]==2){
            if(C3.dol!=1)
            fight(C3);
            else
            fight(C2);
        }
    }
    else
    {
        char k;
        cout <<Getname()<<"的行動是?"<< endl;
        cout <<"  1:攻擊；2:回血"<< endl;
        k=getch();
        if (k=='1')
            fight(C3);
        else if (k=='2')
            healing();
    }
}

void Crobot::deadorlive(Crobot &C2,Crobot &C3)
{
    if(GetHP()<=0){
        dol=1;
        deadcga();
    }

    if(C2.GetHP()<=0){
        C2.dol=1;
        cout<<C2.Getname()<<"被殺死了"<<endl;
    }
    if(C3.GetHP()<=0){
        C3.dol=1;
        cout<<C3.Getname()<<"被殺死了"<<endl;
    }
    if(C2.dol==1&&C3.dol==1)
        deadcgb();
}



void Crobot::deadcga(){
        cout<<Getname()<<"被殺死了"<<endl;
        cout<<endl;
        cout<<"勝利CG:"<<endl;
        cout<<endl;
        cout<<"                 ***"<<endl;
        cout<<"           **   *****"<<endl;
        cout<<"            **  ***" <<endl;
        cout<<"            ** ***  ***"<<endl;
        cout<<"             *******"<<endl;
        cout<<"     * ******* * *  "<<endl;
        cout<<"   * * * * * * * *  "<<endl;
        cout<<"  * *           * * "<<endl;
        cout<<"  * *     *     * * "<<endl;
        cout<<"  * *  *******  * * "<<endl;
        cout<<"  * *     *     * * "<<endl;
        cout<<"   * *    *    * *  "<<endl;
        cout<<"    * *   *   * *   "<<endl;
        cout<<"   **** *   * *     "<<endl;
        cout<<"  ***** ** **       "<<endl;
        cout<<" *****    *         "<<endl;
        cout<<" ***                "<<endl;
        cout<<" *                  "<<endl;
 }

void Crobot::deadcgb(){
        cout<<"GAME OVER, 失敗CG:"<<endl;
        cout<<endl;
        cout<<"        *********"<<endl;
        cout<<"        *       *"<<endl;
        cout<<"        *       *" <<endl;
        cout<<"  *******       *******"<<endl;
        cout<<"  *                   *"<<endl;
        cout<<"  *                   *"<<endl;
        cout<<"  *******       *******"<<endl;
        cout<<"        *       *"<<endl;
        cout<<"        *       *"<<endl;
        cout<<"        *       *"<<endl;
        cout<<"        *       *"<<endl;
        cout<<"        *       *"<<endl;
        cout<<"        *       *"<<endl;
        cout<<"       *         *"<<endl;
        cout<<" ******           ******"<<endl;
        cout<<"*************************"<<endl;
 }
