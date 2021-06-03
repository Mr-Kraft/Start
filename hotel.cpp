#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
const int R=40;//��������40
class Cus//�ͻ���Ϣ 
{ 
public:
    string ID;
    string name;
    int Day;
    int subscription;//����
    void get_C_info();
	void show_C_info();
    Cus(){};
};
void Cus::get_C_info()
{
	cout<<"�ͻ�������";
    cin>>name;
    cout<<"�ͻ����֤��Ϣ��";
    cin>>ID;
    cout<<"����:";
    cin>>subscription;
    cout<<"��ס����";
    cin>>Day;
}
void Cus::show_C_info()
{
    cout<<"�ͻ�������"<<name<<endl;;
    cout<<"�ͻ����֤��Ϣ��"<<ID<<endl;
    cout<<"����:"<<subscription<<endl;
    cout<<"��ס����"<<Day<<endl;
}

class HotelRoom:public Cus
{
 public:
    int Price;
    string Type;
    int num;
    int money(){return(Price*Day-subscription);}//�������
    void get_HR_info();
    void show_HR_info();
    void show_HRC_info();
    void get_HR1_info();
    HotelRoom()//�޲εĹ��캯���������ݳ�Ա���г�ʼ��
	{
		num=0;
        subscription=0;
        Price=0;
        Type="��";
        Day=0;
        name="��";
        ID="0";
	}
};
void HotelRoom::get_HR_info()//����ͷ���Ϣ
{
	cout<<"�����:";
	cin>>num;
    cout<<"�������ͣ�";
	cin>>Type;
	cout<<"����۸�:";
	cin>>Price;
}
void HotelRoom::get_HR1_info()//��ʾ�ͷ���Ϣ
{
    cout<<"�������ͣ�";
	cin>>Type;
	cout<<"����۸�: ";
	cin>>Price;
}
void HotelRoom::show_HR_info()//�����ܵ���Ϣ
{
    cout<<"�����: "<<num<<endl;
    cout<<"�������ͣ�"<<Type<<endl;
	cout<<"����۸�: "<<Price<<endl;
}
void HotelRoom::show_HRC_info()//��ʾ�ܵ���Ϣ
{
    cout<<"�����:"<<num<<endl;
    cout<<"�������ͣ�"<<Type<<endl;
	cout<<"����۸�: "<<Price<<endl;
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

void set_HR_info(HotelRoom *Room)//****************�ͷ���Ϣ��¼��
{
	if(Room[0].num==0)
	{
		int size;
		cout<<"����ס����Ϣ������ӣ�"<<endl;
		static int Number=1;
		cout<<"������Ҫ��ӵķ�������";
		cin>>size;
		for(int i=0;i<size;i++)
		{
			Room[i].num=Number++;
			cout<<"������룺"<<Room[i].num<<endl;
			Room[i].get_HR1_info();
			cout<<endl;
		}
        cout<<"�ͷ���Ϣ¼��ɹ���"<<endl;
	}
    else 
	{
		string P;
		cout<<"�ͷ���Ϣ���У��Ƿ�Ҫ��ӷ��䣿��Y/N��";
		cin>>P;
		if(P=="Y")
		add_HR_info(Room);
		else if(P=="N")
		cout<<"��ȡ����ӣ�"<<endl;
		else cout<<"�Ƿ��Ĳ�����"<<endl;
	}
    system("pause");
    system("cls");
}

void set_C_info(HotelRoom *Room)//********************�ͻ���Ϣ��¼��
{
	int Num;
    int t=0;
    cout<<"���뷿����룺";
    cin>>Num;
    for(int i=0;i<30;i++)
	{
		if(Num==Room[i].num&&Room[i].Day==0)
		{
			cout<<"�������ҵ���";
			cout<<"�������ͣ�"<<Room[i].Type<<endl;
			cout<<"����۸�"<<Room[i].Price<<endl;
			cout<<"������ͻ���Ϣ��"<<endl;
			cout<<"�Ƿ�ȷ��Ҫ��������Y/N��";
			string p;
			cin>>p;
			if(p=="Y")
			{
				Room[i].get_C_info();
				cout<<"��Ϣ¼��ɹ���"<<endl;
			}
            else if(p=="N")
            cout<<"ȡ��������"<<endl;
            else cout<<"��Ч������"<<endl;
            t++;
		}
        else if(Num==Room[i].num&&Room[i].Day!=0)
		{
			cout<<"�˷���ס��";
            t++;
		}
        else if(t==0&&i==39)
        cout<<"û�и÷��䣡";
	}
    system("pause");
    system("cls");
}
void add_HR_info(HotelRoom *Room)//************���ס����Ϣ
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
			     cout<<"������룺"<<Room[i].num<<endl;
			     Room[i].get_HR1_info();
			     cout<<"������ӳɹ����Ƿ������ӣ���Y/N��";
			     cin>>P;break;
			}
            else Number++;
		}
	}
	while(P=="Y");
    if(P=="N")
	{cout<<"��ȡ����ӣ�"<<endl;}
    else cout<<"�˲����Ƿ���"<<endl;
}

void Change_HR_info(HotelRoom *Room)//************�޸�ס����Ϣ
{
	int Num;
    cout<<"������Ҫ�޸ĵķ�����룺"<<endl;
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
	    	cout<<"������Ϣ���ҵ���"<<endl;
	    	cout<<"�Ƿ�Ҫ�޸ķ�����Ϣ��(Y/N)";
	    	string p;
	    	cin>>p;
		    if(p=="Y")
			{
			    cout<<"�ͻ�������";
			    cin>>name2;
		    	Room[i].name=name2;
			    cout<<endl;
			    cout<<"�ͻ����֤���룺";
		    	cin>>ID2;
		    	Room[i].ID=ID2;
		    	cout<<endl;
		    	cout<<"����";
		    	cin>>subscription2;
		    	Room[i].subscription=subscription2;
			    cout<<"�˷�ʱ���ӳ���";
		    	cin>>Day2;
		    	cout<<"���";
		    	Room[i].Day=Day2;
		    	cout<<endl;
		    	cout<<"�޸ĳɹ���"<<endl;
			}
		    else if(p=="N")
			cout<<"��ȡ���޸�";
			else cout<<"��Ч������";
	    	t++;
		}
    	else if(t==0&&i==39&&Room[i].Type=="��")
		cout<<"û�и÷��䣡"<<endl;
	}
    system("pause");
    system("cls");
}
void Display_HR_info(HotelRoom *Room)//***************��ʾ���пͷ���Ϣ
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
			cout<<"���޿շ���";
		}
	}
    system("pause");
    system("cls");
}

void find_choose(HotelRoom *Room)//**************ѡ���ѯ
{
	int P=0;
    while(P==0)
	{
		cout<<"\n\n       �ͷ�����ϵͳ       \n\n";
        cout<<"*********************************\n\n";
        cout<<"        1.ͨ�����Ų�ѯ�ͷ�\n\n";
        cout<<"        2.ͨ���ͻ�������ѯ�ͷ�\n\n";
        cout<<"        3.��ѯ���пտͷ�\n\n";
        cout<<"        4.�������˵�\n\n";
        cout<<"��ѡ��������1--4���֣���";
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

void find_HR_ByNum(HotelRoom *Room)//************ͨ�����Ų�ѯ
{
	int Num;
    int t=0;
    cout<<"����Ҫ��ѯ�ķ���ţ�";
    cin>>Num;
    for(int i=0;i<40;i++)
    if(Num==Room[i].num&&Room[i].Day!=0)
	{
		Room[i].show_HRC_info();
		cout<<"�˷���ס��"<<endl;
		cout<<Room[i].Day<<"����˷���"<<endl;
		t++;
	}
    else if(Num==Room[i].num&&Room[i].Day==0)
	{
		Room[i].show_HRC_info();
		t++;
	}
   else if(t==0&&i==39&&Room[i].Type=="��")
   {
	   cout<<"û�и÷��䣡"<<endl;
   }
   system("pause");
   system("cls");
}
void find_HR_ByName(HotelRoom *Room)//**************ͨ��������ѯ
{
	int t=0;
    string Name;
    cout<<"������ͻ�������";
    cin>>Name;
    for(int i=0;i<40;i++)
	{
		if(Name==Room[i].name&&Room[i].Day!=0)
		{
			Room[i].show_HRC_info();
			cout<<"�˷���ס��";
			cout<<Room[i].Day<<"����˷���";
			t++;
		}
        else if(Name==Room[i].name&&Room[i].Day==0)
		{
			Room[i].show_HRC_info();
			t++;
		}
        else if(t==0&&i==39)
        cout<<"��ѯ�����˿ͻ���"<<endl;
	}
    system("pause");
    system("cls");
}
void Count(HotelRoom *Room)//***************�˷�����
{
	int Num;
    int t=0;
    cout<<"�����뷿����룺";
    cin>>Num;
    for(int i=0;i<40;i++)
	{
	    if(Num==Room[i].num&&Room[i].Day!=0)
		{
			string B;
	        cout<<"�������ҵ���"<<endl;
	        Room[i].show_HRC_info();
			cout<<"�������"<<Room[i].money()<<endl;
			Room[i].money();
	        cout<<"��ȷ���Ƿ�Ҫ�˷���Y/N��:";
	        cin>>B;
    	    if(B=="Y")
			{
			     Room[i].Day=0;
	             Room[i].subscription=0;
	             Room[i].name="��";
	             Room[i].ID="0";
	             cout<<"�˷��ɹ���"<<endl;
			}
        	else if(B=="N")
			{cout<<"ȡ���˷���"<<endl;}
	        else cout<<"��Ч������"<<endl;
        	t++;
		}
	    else if(Num==Room[i].num&&Room[i].Day==0)
		{
			cout<<"�շ��䣡";
	        t++;
		}
	    else if(t==0&&i==39&&Room[i].Type=="��")
		{cout<<"û�и÷��䣡";}
	}
    system("pause");
    system("cls");
}
/**/
void PrintAll(HotelRoom *Room)//***************��ʾ������Ϣ
{
	int t=0;
	for(int i=0;i<40;i++)
	{
		if(Room[i].Type!="��")
		{
			Room[i].show_HRC_info();
			t++;
		}
    	if(t==0&&i==39)
		cout<<"�����κοͷ���Ϣ��"<<endl;
	}
	system("pause");
	system("cls");
}

/*��������ϵͳ���棬��switch���ʵ�ֹ���ѡ��*/
int main()
{
	HotelRoom Room[40];
	while(1)
	{
		cout<<"\n\n             �� ӭ �� ס �� ��      \n\n";
		cout<<"*********************************************\n\n";
		cout<<"**             1.¼��ͷ���Ϣ              **\n\n";
		cout<<"**             2.�ͻ���ס�Ǽ�              **\n\n";
		cout<<"**             3.�޸Ŀͷ���Ϣ              **\n\n";
		cout<<"**             4.�ͻ��˷�����              **\n\n";
		cout<<"**             5.��ʾ���пͷ���Ϣ          **\n\n";
		cout<<"**             6.��ѯ�ͷ���Ϣ              **\n\n";
		cout<<"**             7.�˳�ϵͳ                  **\n\n";
		cout<<"*********************************************\n\n";
		cout<<"��ѡ��������1--7���֣���";
		int choose=0;
		cin>>choose;
		system("cls");
		switch(choose)
		{
	    	case 1:set_HR_info(Room);break;        /*����ͷ���Ϣ*/
	    	case 2:set_C_info(Room);break;         /*������ס�Ǽ�*/
	    	case 3:Change_HR_info(Room);break;     /*�޸Ŀͷ���Ϣ*/
	    	case 4:Count(Room);break;              /*�ͻ��˷�*/
	    	case 5:PrintAll(Room);break;           /*��ѯ���пͷ���Ϣ*/
	    	case 6:find_choose(Room);break;        /*��ѯ*/
			case 7:exit(0);                        /*�˳�*/
            default: break;
		}
	}
	return 0;
}