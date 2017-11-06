#include<conio.h> 
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<unistd.h>
#include<time.h>


using namespace std;


struct special
{
    int NO[4];                  //竞赛名次
    int time;                   //竞赛次数
    char *jingsai;              //学习竞赛
    char *biwu;                 //体能竞赛
    char *jilu[4];              //竞赛记录
}S;
struct menu
{
    int cycle;                  //每日时间
    int W_day;                  //周几
    int date;                   //距离毕业的时间
}M;
struct zhujiao
{
    int  energy;
    int max_energy;             //精力和精力上限
    int S_level;               //学习等级
    int T_level;               //训练等级
    int WL;                    //武力
    int ZL;                    //智力
    int ML;                    //魅力
    char *position;            //职位
}ZJ;





//随机事件
void ill()
{
    srand((int)time (0));
    if((rand()%ZJ.energy)<10)
    {
        system("cls");
        cout<<"你受伤了，在寝室休息一天吧~"<<endl;
        cout<<"请注意精力过低了是很容易受伤的!!"<<endl;
        ZJ.energy+=40;
        M.date-=1;
        M.W_day=M.W_day%7+1;
        cout<<"经过一天的休整，你的精力恢复了40"<<endl;
        cout<<"请按任意键继续"<<endl;
        
        getch(); 
    }
}


//进阶事件
void special()
{
    system("cls");
    if(S.time==1)
    {
        S.jingsai="--物理竞赛<1>";
        S.biwu="--技能比武<2>--";
        S.time=S.time+1;
    }
    else if(S.time==2)
    {
        S.jingsai="--数学建模<1>";
        S.biwu="--强军杯<2>--";
        S.time=S.time+1;
    }
    else if(S.time==3)
    {
        S.jingsai="--ACM大赛<1>";
        S.biwu="--模拟军演<2>--";
    }
    cout<<"****************德克军校******************"<<endl;
    cout<<"学有余力，来参加一场竞赛吧，骚年！！"<<endl;
    cout<<S.jingsai<<S.biwu<<endl;
    cout<<"******************************************"<<endl;
}

//主界面
void menu()
{
    system("cls");
    cout<<"*******************德克军校**************************"<<endl;
    cout<<"-------------------------------星期"<<M.W_day<<"----还剩"<<M.date<<"天"<<endl;
    switch(M.cycle)
    {
        case 0:
        {
            cout<<"--早上--"<<endl<<endl<<endl;
            cout<<"--学习<S>--训练<T>--生活<L>--休息<R>--"<<endl;
            break;
        }
        case 1:
        {
            cout<<"--下午--"<<endl<<endl<<endl;
            cout<<"--学习<S>--训练<T>--生活<L>--休息<R>--"<<endl;
            break;
        }
        case 2:
        {
            cout<<"--黄昏--"<<endl<<endl<<endl;
            cout<<"--学习<S>--训练<T>--生活<L>--休息<R>--"<<endl;
            break;
        }
        case 3:
        {
            cout<<"--傍晚--"<<endl<<endl<<endl;
            cout<<"--学习<S>--训练<T>--生活<L>--休息<R>--"<<endl;
            break;
        }
        case 4:
        {
            cout<<"--晚上--"<<endl<<endl<<endl;
            cout<<"--学习<S>--生活<L>--休息<R>--"<<endl;
            break;
        }
        case 5:
        {
            cout<<"--深夜--"<<endl<<endl<<endl;
            cout<<"--休息<R>--"<<endl;
            break;
        }
        default:
            cout<<"error"<<endl;
    }
    cout<<"精力："<<ZJ.energy<<"/"<<ZJ.max_energy<<endl;
    cout<<"智力："<<ZJ.ZL<<endl<<"武力："<<ZJ.WL<<endl;
    cout<<"魅力："<<ZJ.ML<<endl<<"职位："<<ZJ.position<<endl;
        cout<<"****************************************************************"<<endl;
}






















//学习
void shangke()
{
    ZJ.energy-=3*ZJ.S_level;
    ZJ.ZL+=3*ZJ.S_level;
    ZJ.ML-=ZJ.S_level;
    M.cycle+=1;
    if(ZJ.ML<0)
        ZJ.ML=0;
    if(ZJ.S_level==1)
        cout<<"你进行了大学初级课程的学习"<<endl;
    else if(ZJ.S_level==2)
        cout<<"你进行了大学中级课程的学习"<<endl;
    else if(ZJ.S_level==3)
        cout<<"你进行了大学高级课程的学习"<<endl;
    cout<<"精力减少"<<3*ZJ.S_level<<",智力增加"<<3*ZJ.S_level<<"，魅力减少"<<ZJ.S_level<<endl;
}

void jiaban()
{
    ZJ.energy-=10;
    ZJ.ZL+=10;
    ZJ.ML-=5;
    M.cycle+=1;
    if(ZJ.ML<0)
        ZJ.ML=0;
    cout<<"你加班到了深夜"<<endl;
    cout<<"精力减少10,智力增加10，魅力减少5"<<endl;

}




//体能
void naili()
{
    ZJ.energy-=5*ZJ.T_level;
    ZJ.max_energy+=2*ZJ.T_level;
    ZJ.WL+=3*ZJ.T_level;
    ZJ.ML-=2*ZJ.T_level;
    M.cycle+=1;
    if(ZJ.ZL<0)
        ZJ.ZL=0;
    cout<<"你刚才跑了一个五公里"<<endl;
    cout<<"精力减少"<<5*ZJ.T_level<<",最大精力增加"<<2*ZJ.T_level<<endl;
    cout<<"武力增加"<<3*ZJ.T_level<<",魅力减少"<<2*ZJ.T_level<<endl;
}
void liliang()
{
    ZJ.energy-=5*ZJ.T_level;
    ZJ.WL+=5*ZJ.T_level;
    ZJ.ZL-=ZJ.T_level;
    ZJ.ML+=2*ZJ.T_level;
    M.cycle+=1;
    if(ZJ.ZL<0)
        ZJ.ZL=0;
    cout<<"你做了一组单杠"<<endl;
    cout<<"精力减少"<<5*ZJ.T_level<<endl;
    cout<<"武力增加"<<5*ZJ.T_level<<",魅力减少"<<2*ZJ.T_level<<"，智力减少"<<ZJ.T_level<<endl;
}


//生活
void game()
{
    ZJ.energy+=10;
    ZJ.ML+=5;
    ZJ.WL-=5;
    ZJ.ZL-=5;
    if(ZJ.energy>ZJ.max_energy)
    {
        ZJ.energy=ZJ.max_energy;
    }
    M.cycle+=1;
    if(ZJ.WL<0)
        ZJ.WL=0;
    if(ZJ.ZL<0)
        ZJ.ZL=0;
    cout<<"精力增加10,魅力增加5，智力减少5，武力减少5"<<endl;
}
void call()
{
    ZJ.energy+=5;
    ZJ.ML+=2;
    if(ZJ.energy>ZJ.max_energy)
    {
        ZJ.energy=ZJ.max_energy;
    }
    M.cycle+=1;
    cout<<"精力增加5，魅力增加2"<<endl;
}
void waichu()
{
    ZJ.energy+=10;
    ZJ.ML+=10;
    if(ZJ.energy>ZJ.max_energy)
    {
        ZJ.energy=ZJ.max_energy;
    }
    M.cycle+=3;
    cout<<"精力增加10，魅力增加10"<<endl;
}


//休息
void rest()
{
    ZJ.energy+=10;
    if(ZJ.energy>ZJ.max_energy)
    {
        ZJ.energy=ZJ.max_energy;
    }
    M.cycle=(M.cycle+1)%6;
    if(M.cycle==0)
    {
        M.date-=1;
        M.W_day=M.W_day%7+1;
    }
    cout<<"经过休息，你的精力增加了10"<<endl;
}


//日常
void richang(int DTE)
{
    if(DTE=='S' | DTE=='s')
    {
        system("cls");
        cout<<"*--------------------------------------------------*"<<endl;
        int C=0;
        if(M.cycle==0|M.cycle==1|M.cycle==2|M.cycle==3)
            cout<<"--上课<1>--"<<endl;
        else if(M.cycle==4)
            cout<<"--加班<2>--"<<endl;
        cin>>C;
        if(C==1)
            shangke();
        else if(C==2)
            jiaban();
    }

    else if(DTE=='T' | DTE=='t')
    {
        system("cls");
        cout<<"*--------------------------------------------------*"<<endl;
        int C=0;
        cout<<"--耐力训练<1>--力量训练<2>--"<<endl;
        cin>>C;
        if(C==1)
            naili();
        else if(C==2)
            liliang();
    }
    else if(DTE=='L'|DTE=='l')
    {
        system("cls");
        cout<<"*--------------------------------------------------*"<<endl;
        int C=0;
        if((M.cycle==0|M.cycle==1)&(M.W_day==7|M.W_day==6))
            cout<<"--玩游戏<1>--打电话<2>--外出<3>--"<<endl;
        else
            cout<<"--玩游戏<1>--打电话<2>--"<<endl;
        cin>>C;
        if(C==1)
            game();
        else if(C==2)
            call();
        else if(C==3)
            waichu();
    }
    else if(DTE=='R'|DTE=='r')
    {
        system("cls");
        cout<<"*--------------------------------------------------*"<<endl;
        rest();
    }
}

















//进阶
void level_up(int DTE)
{
    system("cls");
    cout<<"-------------------------------------------"<<endl;
    M.date-=1;
    M.W_day=M.W_day%7+1;
    if(DTE=='1')
    {
        S.jilu[S.time]=S.jingsai;
        if(ZJ.ZL>(60*S.time*S.time))
        {
            S.NO[S.time]=1;
            ZJ.ML+=50*S.time;
        }
        else if(ZJ.ZL>(40*S.time*S.time))
        {
            S.NO[S.time]=2;
            ZJ.ML+=40*S.time;
        }
        else if(ZJ.ZL>(30*S.time*S.time))
        {
            S.NO[S.time]=3;
            ZJ.ML+=30*S.time;
        }
        else
            S.NO[S.time]=0;
    }
    else if(DTE=='2')
    {
        S.jilu[S.time]=S.biwu;
        if(ZJ.WL>(60*S.time*S.time))
        {
            S.NO[S.time]=1;
            ZJ.ML+=50*S.time;
        }
        else if(ZJ.WL>(40*S.time*S.time))
        {
            S.NO[S.time]=2;
            ZJ.ML+=40*S.time;
        }
        else if(ZJ.WL>(30*S.time*S.time))
        {
            S.NO[S.time]=3;
            ZJ.ML+=30*S.time;
        }
        else
            S.NO[S.time]=0;
    }
    if(S.NO[S.time]!=0)
        cout<<"恭喜你！在"<<S.jilu[S.time]<<"中取得第"<<S.NO[S.time]<<"名的好成绩！"<<"请再接再励！"<<endl;
    else
        cout<<"很遗憾，你在"<<S.jilu[S.time]<<"中没有取得名次。请继续加油！"<<endl;
}















//结局
void the_end()
{
    system("cls");
    cout<<"时光如白驹过隙，转眼间100天的毕业冲刺就结束了，你在这100天达到了什么样的成就呢？"<<endl;
    cout<<"请按任意键继续"<<endl;
    
    getch(); 
    
    system("cls");
    cout<<"你一共参加了3次竞赛"<<endl;
    for(int i=1;i<=3;i++)
    {
        if(S.NO[i]!=0)
        cout<<"在"<<S.jilu[i]<<"中，获得了第"<<S.NO[i]<<"的成绩"<<endl;
    }
    cout<<"请按任意键继续"<<endl;
    
    getch();
    
    system("cls");
    cout<<"你在本学期担任了"<<ZJ.position<<"的职务"<<endl;
    cout<<"在体能考核中取得了"<<ZJ.WL/20<<"的成绩"<<endl;
    cout<<"在期末考试中取得了"<<ZJ.ZL/20<<"的成绩"<<endl;
    cout<<"经过这100天的冲刺，你的努力最终换来的成果是"<<endl;
    cout<<"请按任意键继续"<<endl;
    
    getch(); 
    
    if(ZJ.ZL>2000&&ZJ.WL>1200)
    {
        if(S.NO[1]!=0||S.NO[2]!=0||S.NO[3]!=0)
            cout<<"保送研究生"<<endl;
        else
            cout<<"考上研究生"<<endl;
    }
    else if(ZJ.WL>1200&&ZJ.ZL>1200)
    {
        if(S.NO[1]!=0||S.NO[2]!=0||S.NO[3]!=0)
            cout<<"分配留校"<<endl;
        else
            cout<<"分配下部队"<<endl;
    }
    else
        cout<<"转业"<<endl;
    cout<<endl<<endl<<endl<<"漫漫军旅路，军校第一步。在以后的军旅生涯中，请您继续努力！"<<endl;
}

















int main()
{
	char DTE;   		//大厅选择


	M.cycle=0;
	M.date=76;
	M.W_day=1;
	S.time=1;
    ZJ.energy=100;
    ZJ.max_energy=100;
    ZJ.S_level=1;
    ZJ.T_level=1;
    ZJ.WL=7;
    ZJ.ZL=15;
    ZJ.ML=7;
    ZJ.position="学员";

DT:
    if(ZJ.energy<30)
        ill();
    if(M.date==25|M.date==50|M.date==75)
        special();
    else
        menu();

ERRIN:
    cin>>DTE;
    if(DTE=='1'|DTE=='2')
        level_up(DTE);
    else
        richang(DTE);
    cout<<"按任意键返回"<<endl;
    if(getch())
    {
    	if(M.date<0)
        	goto bye;
    	else
        	goto DT;
    } 
    
bye:
    the_end();
    return 0;
}



