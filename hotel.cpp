#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
const int R=40;//房间总数40
class Cus//客户信息 
{ 
public:
    string ID;
    string name;
    int Day;
    int subscription;//订金
    void get_C_info();
	void show_C_info();
    Cus(){};
};
void Cus::get_C_info()
{
	cout<<"客户姓名：";
    cin>>name;
    cout<<"客户身份证信息：";
    cin>>ID;
    cout<<"订金:";
    cin>>subscription;
    cout<<"入住天数";
    cin>>Day;
}
void Cus::show_C_info()
{
    cout<<"客户姓名："<<name<<endl;;
    cout<<"客户身份证信息："<<ID<<endl;
    cout<<"订金:"<<subscription<<endl;
    cout<<"入住天数"<<Day<<endl;
}

class HotelRoom:public Cus
{
 public:
    int Price;
    string Type;
    int num;
    int money(){return(Price*Day-subscription);}//结算金额函数
    void get_HR_info();
    void show_HR_info();
    void show_HRC_info();
    void get_HR1_info();
    HotelRoom()//无参的构造函数，对数据成员进行初始化
	{
		num=0;
        subscription=0;
        Price=0;
        Type="空";
        Day=0;
        name="空";
        ID="0";
	}
};
void HotelRoom::get_HR_info()//输入客房信息
{
	cout<<"房间号:";
	cin>>num;
    cout<<"房间类型：";
	cin>>Type;
	cout<<"房间价格:";
	cin>>Price;
}
void HotelRoom::get_HR1_info()//显示客房信息
{
    cout<<"房间类型：";
	cin>>Type;
	cout<<"房间价格: ";
	cin>>Price;
}
void HotelRoom::show_HR_info()//输入总的信息
{
    cout<<"房间号: "<<num<<endl;
    cout<<"房间类型："<<Type<<endl;
	cout<<"房间价格: "<<Price<<endl;
}
void HotelRoom::show_HRC_info()//显示总的信息
{
    cout<<"房间号:"<<num<<endl;
    cout<<"房间类型："<<Type<<endl;
	cout<<"房间价格: "<<Price<<endl;
	show_C_info();
}
 
void set_C_info(HotelRoom *Room);
void set_HR_info(HotelRoom *Room);
void Display_HR_info(HotelRoom *Room);
void add_HR_info(HotelRoom *Room);
void Change_HR_info(HotelRoom *Room);
void find_choose(HotelRoom *Room);
void find_HR_ByNum(HotelRoom *Room);
void find_HR_ByName(HotelRoom *Room);
void PrintAll(HotelRoom *Room);
void Count(HotelRoom *Room);

void set_HR_info(HotelRoom *Room)//****************客房信息的录入
{
	if(Room[0].num==0)
	{
		int size;
		cout<<"暂无住房信息，请添加！"<<endl;
		static int Number=1;
		cout<<"请输入要添加的房间数：";
		cin>>size;
		for(int i=0;i<size;i++)
		{
			Room[i].num=Number++;
			cout<<"房间号码："<<Room[i].num<<endl;
			Room[i].get_HR1_info();
			cout<<endl;
		}
        cout<<"客房信息录入成功！"<<endl;
	}
    else 
	{
		string P;
		cout<<"客房信息已有，是否要添加房间？（Y/N）";
		cin>>P;
		if(P=="Y")
		add_HR_info(Room);
		else if(P=="N")
		cout<<"已取消添加！"<<endl;
		else cout<<"非法的操作！"<<endl;
	}
    system("pause");
    system("cls");
}

void set_C_info(HotelRoom *Room)//********************客户信息的录入
{
	int Num;
    int t=0;
    cout<<"输入房间号码：";
    cin>>Num;
    for(int i=0;i<30;i++)
	{
		if(Num==Room[i].num&&Room[i].Day==0)
		{
			cout<<"房间已找到！";
			cout<<"房间类型："<<Room[i].Type<<endl;
			cout<<"房间价格："<<Room[i].Price<<endl;
			cout<<"请输入客户信息："<<endl;
			cout<<"是否确定要订房？（Y/N）";
			string p;
			cin>>p;
			if(p=="Y")
			{
				Room[i].get_C_info();
				cout<<"信息录入成功！"<<endl;
			}
            else if(p=="N")
            cout<<"取消订房！"<<endl;
            else cout<<"无效操作！"<<endl;
            t++;
		}
        else if(Num==Room[i].num&&Room[i].Day!=0)
		{
			cout<<"此房已住！";
            t++;
		}
        else if(t==0&&i==39)
        cout<<"没有该房间！";
	}
    system("pause");
    system("cls");
}
void add_HR_info(HotelRoom *Room)//************添加住房信息
{
	static int Number=1;
    string P;
    do
	{
		int Number=1;
        for(int i=0;i<40;i++)
		{
		    if(Room[i].num==0)
			{
			     Room[i].num=Number++;
			     cout<<"房间号码："<<Room[i].num<<endl;
			     Room[i].get_HR1_info();
			     cout<<"房间添加成功，是否继续添加？（Y/N）";
			     cin>>P;break;
			}
            else Number++;
		}
	}
	while(P=="Y");
    if(P=="N")
	{cout<<"已取消添加！"<<endl;}
    else cout<<"此操作非法！"<<endl;
}

void Change_HR_info(HotelRoom *Room)//************修改住房信息
{
	int Num;
    cout<<"请输入要修改的房间号码："<<endl;
    cin>>Num;
    string name2;
    string ID2;
    int subscription2;
    int Day2;
    string Price2;
    string Type2;
    int t=0;
    for(int i=0;i<40;i++)
	{
	    if(Num==Room[i].num)
		{
		    Room[i].show_HRC_info();
	    	cout<<"房间信息已找到！"<<endl;
	    	cout<<"是否要修改房间信息？(Y/N)";
	    	string p;
	    	cin>>p;
		    if(p=="Y")
			{
			    cout<<"客户姓名：";
			    cin>>name2;
		    	Room[i].name=name2;
			    cout<<endl;
			    cout<<"客户身份证号码：";
		    	cin>>ID2;
		    	Room[i].ID=ID2;
		    	cout<<endl;
		    	cout<<"订金：";
		    	cin>>subscription2;
		    	Room[i].subscription=subscription2;
			    cout<<"退房时间延长至";
		    	cin>>Day2;
		    	cout<<"天后";
		    	Room[i].Day=Day2;
		    	cout<<endl;
		    	cout<<"修改成功！"<<endl;
			}
		    else if(p=="N")
			cout<<"已取消修改";
			else cout<<"无效操作！";
	    	t++;
		}
    	else if(t==0&&i==39&&Room[i].Type=="空")
		cout<<"没有该房间！"<<endl;
	}
    system("pause");
    system("cls");
}
void Display_HR_info(HotelRoom *Room)//***************显示所有客房信息
{
	int t=0;
    for(int i=0;i<40;i++)
	{
		if(Room[i].Day==0&&Room[i].num!=0)
		{
			Room[i].show_HR_info();
            t++;
		}
        else if(t==0&&i==39)
		{
			cout<<"暂无空房！";
		}
	}
    system("pause");
    system("cls");
}

void find_choose(HotelRoom *Room)//**************选择查询
{
	int P=0;
    while(P==0)
	{
		cout<<"\n\n       客房管理系统       \n\n";
        cout<<"*********************************\n\n";
        cout<<"        1.通过房号查询客房\n\n";
        cout<<"        2.通过客户姓名查询客房\n\n";
        cout<<"        3.查询所有空客房\n\n";
        cout<<"        4.返回主菜单\n\n";
        cout<<"请选择（请输入1--4数字）：";
        int choose=0;
        cin>>choose;
        system("cls");
        switch (choose)
		{
		     case 1:find_HR_ByNum(Room);break;
             case 2:find_HR_ByName(Room);break;
             case 3:Display_HR_info(Room);break;
             case 4:P=4;break;
             default:;break;
		}
	}
}

void find_HR_ByNum(HotelRoom *Room)//************通过房号查询
{
	int Num;
    int t=0;
    cout<<"输入要查询的房间号：";
    cin>>Num;
    for(int i=0;i<40;i++)
    if(Num==Room[i].num&&Room[i].Day!=0)
	{
		Room[i].show_HRC_info();
		cout<<"此房已住！"<<endl;
		cout<<Room[i].Day<<"天后退房！"<<endl;
		t++;
	}
    else if(Num==Room[i].num&&Room[i].Day==0)
	{
		Room[i].show_HRC_info();
		t++;
	}
   else if(t==0&&i==39&&Room[i].Type=="空")
   {
	   cout<<"没有该房间！"<<endl;
   }
   system("pause");
   system("cls");
}
void find_HR_ByName(HotelRoom *Room)//**************通过姓名查询
{
	int t=0;
    string Name;
    cout<<"请输入客户姓名：";
    cin>>Name;
    for(int i=0;i<40;i++)
	{
		if(Name==Room[i].name&&Room[i].Day!=0)
		{
			Room[i].show_HRC_info();
			cout<<"此房已住！";
			cout<<Room[i].Day<<"天后退房！";
			t++;
		}
        else if(Name==Room[i].name&&Room[i].Day==0)
		{
			Room[i].show_HRC_info();
			t++;
		}
        else if(t==0&&i==39)
        cout<<"查询不到此客户！"<<endl;
	}
    system("pause");
    system("cls");
}
void Count(HotelRoom *Room)//***************退房结算
{
	int Num;
    int t=0;
    cout<<"请输入房间号码：";
    cin>>Num;
    for(int i=0;i<40;i++)
	{
	    if(Num==Room[i].num&&Room[i].Day!=0)
		{
			string B;
	        cout<<"房间已找到！"<<endl;
	        Room[i].show_HRC_info();
			cout<<"房间费用"<<Room[i].money()<<endl;
			Room[i].money();
	        cout<<"请确定是否要退房（Y/N）:";
	        cin>>B;
    	    if(B=="Y")
			{
			     Room[i].Day=0;
	             Room[i].subscription=0;
	             Room[i].name="空";
	             Room[i].ID="0";
	             cout<<"退房成功！"<<endl;
			}
        	else if(B=="N")
			{cout<<"取消退房！"<<endl;}
	        else cout<<"无效操作！"<<endl;
        	t++;
		}
	    else if(Num==Room[i].num&&Room[i].Day==0)
		{
			cout<<"空房间！";
	        t++;
		}
	    else if(t==0&&i==39&&Room[i].Type=="空")
		{cout<<"没有该房间！";}
	}
    system("pause");
    system("cls");
}
/**/
void PrintAll(HotelRoom *Room)//***************显示所有信息
{
	int t=0;
	for(int i=0;i<40;i++)
	{
		if(Room[i].Type!="空")
		{
			Room[i].show_HRC_info();
			t++;
		}
    	if(t==0&&i==39)
		cout<<"暂无任何客房信息！"<<endl;
	}
	system("pause");
	system("cls");
}

/*主函数，系统界面，用switch语句实现功能选择*/
int main()
{
	HotelRoom Room[40];
	while(1)
	{
		cout<<"\n\n             欢 迎 入 住 酒 店      \n\n";
		cout<<"*********************************************\n\n";
		cout<<"**             1.录入客房信息              **\n\n";
		cout<<"**             2.客户入住登记              **\n\n";
		cout<<"**             3.修改客房信息              **\n\n";
		cout<<"**             4.客户退房结算              **\n\n";
		cout<<"**             5.显示所有客房信息          **\n\n";
		cout<<"**             6.查询客房信息              **\n\n";
		cout<<"**             7.退出系统                  **\n\n";
		cout<<"*********************************************\n\n";
		cout<<"请选择（请输入1--7数字）：";
		int choose=0;
		cin>>choose;
		system("cls");
		switch(choose)
		{
	    	case 1:set_HR_info(Room);break;        /*输入客房信息*/
	    	case 2:set_C_info(Room);break;         /*客人入住登记*/
	    	case 3:Change_HR_info(Room);break;     /*修改客房信息*/
	    	case 4:Count(Room);break;              /*客户退房*/
	    	case 5:PrintAll(Room);break;           /*查询所有客房信息*/
	    	case 6:find_choose(Room);break;        /*查询*/
			case 7:exit(0);                        /*退出*/
            default: break;
		}
	}
	return 0;
}