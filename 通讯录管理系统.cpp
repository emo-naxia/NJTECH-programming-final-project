//人活着就是为了CODING
#include<iostream>
#include<string>
#define Max 1000
using namespace std;
struct person
{
	string m_name;
	int m_sex;//性别1-男，2-女
	int m_age;
	string m_phone;
	string m_addr;
};
struct addressbooks
{
	struct person parr[Max];
	int m_size;
};
/*主菜单*/void showmenu()
{
	cout << "**************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "**************************" << endl;
}
/*检查函数*/int check(addressbooks* ads, string name)//参数1是通讯录，参数二是比对的姓名
{
	for (int i = 0; i < ads->m_size; i++)
	{
		if (ads->parr[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}
/*1.添加联系人*/void addperson(addressbooks* ads)
{
	if (ads->m_size == Max)
	{
		cout << "通讯录已满，无法添加，请扩容"<< endl;
	}
	else
	{
		//添加姓名
		string name;
		cout << "请输入姓名："<< endl;
		cin >> name;
		ads->parr[ads->m_size].m_name = name;
		//---------------------------------------------------//
		//添加性别
		cout << "请输入性别" << endl;
		cout << "1-男，2-女" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 2 || sex == 1)
			{
				ads->parr[ads->m_size].m_sex = sex;
				break;
			}
			else
			{
				cout << "无效输入,请重新输入" << endl;
			}
		}
	    //---------------------------------------------------//
		//请输入年龄
		int age;
		cout << "输入你的年龄" << endl;
		cin >> age;
		ads->parr[ads->m_size].m_age = age;
		//--------------------------------------------------//
		//请输入联系电话
		string phone_number;
		cout << "输入你的联系电话" << endl;
		cin >> phone_number;
		ads->parr[ads->m_size].m_phone =phone_number;
		//-------------------------------------------------//
		//请输入家庭住址
		string address;
		cout << "输入你的家庭住址" << endl;
		cin >> address;
		ads->parr[ads->m_size].m_addr = address;
		//数组的size要增加
		ads->m_size++;
		//提示添加成功
		cout << "添加成功！！！" << endl;
	    //清屏操作
		system("pause");
		system("cls");
	}
}//1.添加联系人
/*2.显示联系人*/void showperson(addressbooks* ads)
{
	if (ads->m_size == 0)
	{
		cout << "无人，当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < ads->m_size; i++)
		{
			cout << "姓名：" << ads->parr[i].m_name << "\t";
			cout << "性别：" << (ads->parr[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << ads->parr[i].m_age << "\t";
			cout << "联系方式：" << ads->parr[i].m_phone << "\t";
			cout << "家庭住址：" << ads->parr[i].m_addr<< endl;
	    }
	}
	system("pause");
	system("cls");
}
/*3.删除联系人*/void deleteperson(addressbooks* ads)
{
	cout << "输入你要删除的人" << endl;
	string name;
	cin >> name;
	int temp = check(ads, name);
	if (temp !=-1 )
	{
		for (int i = temp; i < ads->m_size; i++)
		{
			//后面的数据覆盖前面的数据
			ads->parr[i] = ads->parr[i + 1];
		}
		ads->m_size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
/*4.查找联系人*/void findperson(addressbooks* ads)
{
	cout << "输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int temp = check(ads, name); 
	if (temp != -1)
	{
		cout << "姓名：" << ads->parr[temp].m_name << "\t";
		cout << "性别：" << ads->parr[temp].m_sex << "\t";
		cout << "年龄：" << ads->parr[temp].m_age << "\t";
		cout << "联系方式：" << ads->parr[temp].m_phone << "\t";
		cout << "家庭住址：" << ads->parr[temp].m_addr<< "\t";
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
/*5.修改联系人*/void modifyperson(addressbooks* ads)
{
	cout << "输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int temp = check(ads, name);
	if (temp != -1)//找到指定联系人
	{
		string name;
		cout << "请重新输入姓名:" << endl;
		cin >> name;
		ads->parr[temp].m_name = name;
		int sex;
		cout << "请重新输入性别:" << endl;
		cout << "1-男，2-女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ads->parr[temp].m_sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		int age;
		cout << "请重新输入年龄:" << endl;
		cin >> age;
		ads->parr[temp].m_age = age;
		string phone;
		cout << "请重新输入联系方式:" << endl;
		cin >> phone;
		ads->parr[temp].m_phone =phone;
		string address;
		cout << "请重新输入家庭住址:" << endl;
		cin >> address;
		ads->parr[temp].m_addr = address;
	}
	else//找不到指定联系人
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
/*6.清空联系人*/void cleanperson(addressbooks* ads)
{
	ads->m_size = 0;
	cout << "通讯录已清空！！！" << endl;
	system("pause");
	system("cls");
}
int main()
{
	addressbooks ads;//创建通讯录结构体变量
	ads.m_size = 0;//初始化通讯录中当前人员个数
	int select = 0;
	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://1.添加联系人
			addperson(&ads);
			break;
		case 2://2.显示联系人
			showperson(&ads);
			break;
		case 3://3.删除联系人			
			deleteperson(&ads);
			break;
		case 4://4.查找联系人			
			findperson(&ads);
			break;
		case 5://5.修改联系人		
			modifyperson(&ads);
			break;
		case 6://6.清空联系人
			cleanperson(&ads);
			break;
		case 0://0.退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}
//created by emo