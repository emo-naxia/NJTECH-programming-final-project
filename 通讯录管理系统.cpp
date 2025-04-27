//�˻��ž���Ϊ��CODING
#include<iostream>
#include<string>
#define Max 1000
using namespace std;
struct person
{
	string m_name;
	int m_sex;//�Ա�1-�У�2-Ů
	int m_age;
	string m_phone;
	string m_addr;
};
struct addressbooks
{
	struct person parr[Max];
	int m_size;
};
/*���˵�*/void showmenu()
{
	cout << "**************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "**************************" << endl;
}
/*��麯��*/int check(addressbooks* ads, string name)//����1��ͨѶ¼���������ǱȶԵ�����
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
/*1.�����ϵ��*/void addperson(addressbooks* ads)
{
	if (ads->m_size == Max)
	{
		cout << "ͨѶ¼�������޷���ӣ�������"<< endl;
	}
	else
	{
		//�������
		string name;
		cout << "������������"<< endl;
		cin >> name;
		ads->parr[ads->m_size].m_name = name;
		//---------------------------------------------------//
		//����Ա�
		cout << "�������Ա�" << endl;
		cout << "1-�У�2-Ů" << endl;
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
				cout << "��Ч����,����������" << endl;
			}
		}
	    //---------------------------------------------------//
		//����������
		int age;
		cout << "�����������" << endl;
		cin >> age;
		ads->parr[ads->m_size].m_age = age;
		//--------------------------------------------------//
		//��������ϵ�绰
		string phone_number;
		cout << "���������ϵ�绰" << endl;
		cin >> phone_number;
		ads->parr[ads->m_size].m_phone =phone_number;
		//-------------------------------------------------//
		//�������ͥסַ
		string address;
		cout << "������ļ�ͥסַ" << endl;
		cin >> address;
		ads->parr[ads->m_size].m_addr = address;
		//�����sizeҪ����
		ads->m_size++;
		//��ʾ��ӳɹ�
		cout << "��ӳɹ�������" << endl;
	    //��������
		system("pause");
		system("cls");
	}
}//1.�����ϵ��
/*2.��ʾ��ϵ��*/void showperson(addressbooks* ads)
{
	if (ads->m_size == 0)
	{
		cout << "���ˣ���ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < ads->m_size; i++)
		{
			cout << "������" << ads->parr[i].m_name << "\t";
			cout << "�Ա�" << (ads->parr[i].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << ads->parr[i].m_age << "\t";
			cout << "��ϵ��ʽ��" << ads->parr[i].m_phone << "\t";
			cout << "��ͥסַ��" << ads->parr[i].m_addr<< endl;
	    }
	}
	system("pause");
	system("cls");
}
/*3.ɾ����ϵ��*/void deleteperson(addressbooks* ads)
{
	cout << "������Ҫɾ������" << endl;
	string name;
	cin >> name;
	int temp = check(ads, name);
	if (temp !=-1 )
	{
		for (int i = temp; i < ads->m_size; i++)
		{
			//��������ݸ���ǰ�������
			ads->parr[i] = ads->parr[i + 1];
		}
		ads->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
/*4.������ϵ��*/void findperson(addressbooks* ads)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int temp = check(ads, name); 
	if (temp != -1)
	{
		cout << "������" << ads->parr[temp].m_name << "\t";
		cout << "�Ա�" << ads->parr[temp].m_sex << "\t";
		cout << "���䣺" << ads->parr[temp].m_age << "\t";
		cout << "��ϵ��ʽ��" << ads->parr[temp].m_phone << "\t";
		cout << "��ͥסַ��" << ads->parr[temp].m_addr<< "\t";
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
/*5.�޸���ϵ��*/void modifyperson(addressbooks* ads)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int temp = check(ads, name);
	if (temp != -1)//�ҵ�ָ����ϵ��
	{
		string name;
		cout << "��������������:" << endl;
		cin >> name;
		ads->parr[temp].m_name = name;
		int sex;
		cout << "�����������Ա�:" << endl;
		cout << "1-�У�2-Ů" << endl;
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
				cout << "������������������" << endl;
			}
		}
		int age;
		cout << "��������������:" << endl;
		cin >> age;
		ads->parr[temp].m_age = age;
		string phone;
		cout << "������������ϵ��ʽ:" << endl;
		cin >> phone;
		ads->parr[temp].m_phone =phone;
		string address;
		cout << "�����������ͥסַ:" << endl;
		cin >> address;
		ads->parr[temp].m_addr = address;
	}
	else//�Ҳ���ָ����ϵ��
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
/*6.�����ϵ��*/void cleanperson(addressbooks* ads)
{
	ads->m_size = 0;
	cout << "ͨѶ¼����գ�����" << endl;
	system("pause");
	system("cls");
}
int main()
{
	addressbooks ads;//����ͨѶ¼�ṹ�����
	ads.m_size = 0;//��ʼ��ͨѶ¼�е�ǰ��Ա����
	int select = 0;
	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://1.�����ϵ��
			addperson(&ads);
			break;
		case 2://2.��ʾ��ϵ��
			showperson(&ads);
			break;
		case 3://3.ɾ����ϵ��			
			deleteperson(&ads);
			break;
		case 4://4.������ϵ��			
			findperson(&ads);
			break;
		case 5://5.�޸���ϵ��		
			modifyperson(&ads);
			break;
		case 6://6.�����ϵ��
			cleanperson(&ads);
			break;
		case 0://0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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