#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	string s,sv;
	cin >> s;
	bool flag = false; vector<string> v;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[s.size() - 1 - i] == '0')
		{
			if (s.size() == 1|| s.size() == 2 && s[0] == '-')
			{
				sv = "ling";
				v.push_back(sv);
			}//����ǿ������м�0��-0�����
			if (flag)
			{
				sv = "ling";
				v.push_back(sv);
			}//���flag��Ϊ�˴���0��ʱ���Ͳ���������
			if (i == 4)
			{
				if (s[0] != '-'&&s.size() == 9)
				{
					int j=1;
					for (j; j <= 4; j++)
						if (s[j] != '0')break;
					if (j <= 4)
					{
						sv = "Wan"; v.push_back(sv);
					}
				}
				else if (s[0] == '-'&&s.size() == 10)
				{
					int j = 2;
					for (j; j <= 5; j++)
						if (s[j] != '0')break;
					if (j <= 5)
					{
						sv = "Wan"; v.push_back(sv);
					}
				}
				else
				{
					sv = "Wan"; v.push_back(sv);
				}
			}//�����Ϊ�˼���
			flag = false;
		}
		else
		{
			flag = true;
			if (s[s.size() - 1 - i] != '-')
			{
				switch (i % 4)
				{
				case 1:sv = "Shi"; v.push_back(sv); break;
				case 2:sv = "Bai"; v.push_back(sv); break;
				case 3:sv = "Qian"; v.push_back(sv); break;
				}
			}//�ӵ�λ
			if (i == 4&& s[s.size() - 1 - i] != '-')
			{
				sv = "Wan"; v.push_back(sv);
			}
			else if (i == 8 && s[s.size() - 1 - i] != '-')
			{
				sv = "Yi"; v.push_back(sv);
			}//�����ڽ������⴦��
			switch (s[s.size() - 1 - i] - '0')
			{
			case 1:sv = "yi"; v.push_back(sv); break;
			case 2:sv = "er"; v.push_back(sv); break;
			case 3:sv = "san"; v.push_back(sv); break;
			case 4:sv = "si"; v.push_back(sv); break;
			case 5:sv = "wu"; v.push_back(sv); break;
			case 6:sv = "liu"; v.push_back(sv); break;
			case 7:sv = "qi"; v.push_back(sv); break;
			case 8:sv = "ba"; v.push_back(sv); break;
			case 9:sv = "jiu"; v.push_back(sv); break;
			}//�������
			if (s[s.size() - 1 - i] == '-')
			{
				sv = "Fu"; v.push_back(sv);
			}//������
		}
	}
	reverse(v.begin(), v.end());//��ת�ַ���
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (i != v.size() - 1)
			cout << " ";
	}
}
/*���������Һܳ�ʱ�䣬�������ò���λ��˵��˼·�����Ǵ������ַ����ĺ�����ǰ���ο�ʼ����ģ�
����Ҫע���λΪ0ʱ��0�ǲ��ܱ��������ģ������ֲ���1λʱ������ô��ʲô����£�0��Ҫ���������ģ�����λ֮�䲻����ʱ
��Ӧ�ð�0���������ټ����򵥵���������£�101��10001��100000001�����α���Ϊһ����һ��һ��
��һ��һ����һ���١����ڸ���λ����������110����Ϊһ��һʮ���ٺ�ʮ����������һ������֪��
������û�У����������ĵ�λ֮���ж��0ʱ��ֻ��һ��0.��ô�����Ļ�������һ��flag��Ĭ��Ϊfalse��
����������˵���Ӻ�ʼɨ��0ʱ��������һֱ��ɨ����һ����Ϊ0��������flag��Ϊtrue����������0
ʱ��Ҫ����������������֮���flag��Ϊfalse������������0�Բ���ֱ���ٴ������������ظ��������̡�
��˵�¶Ե�λ�Ĵ�����ɨ��ʮλʱ��������0��ô��Ҫ�ѵ�λShi���ϣ�ע�����ǴӺ�����ǰɨ�ģ������
������vector��ת�¾Ϳ��Եõ�������˳�򣬵�ɨ����λʱ������0�Ͱѵ�λBai���ϣ������������ƣ�����
���ڵ��������ɣ���Ŀ�涨���ֲ��ᳬ��9λ��ʵ�������Ѷȣ�Ҳ����˵���ൽ�ڡ������ٲ����¶��������
λ����ӣ�ֻҪ���ֲ���ﵽ1�ڣ���ô����һ������ְ�������˵�Ӿ��С����Ǵﵽ1���˵Ļ�����ô�͵���
����λ��ʮ��λ������λ��ǧ��λ�Ƿ�Ϊ0���������ܰ�����ϣ�����˵100000001����Ϊ1����һ��û����
��ֻҪ��һ����Ϊ0��ô���Ӧ�ü��ϣ�����˵100100000,����Ϊ1����ʮ��
���ע���¶�0��-0�Ĵ����ɣ���ʱ��Ȼ�ڸ�λȴҪ������������ʵ��˵�Ŀ����е��Ѷ�����������һ�鿴��
����˼·���⣬��ô���մ����⵽һ���˼�룬��ټ��������԰�����⡣WA��������Ϊ�������ⲻȫ�棬����
���������������û���ǵ����������������⣬ʹ�������괦�룬��ô������ô�룬��һ������Ĵ����ǽϼ򵥵ġ�
���������Ļ����ɷ����ʼ�һ����������593807467@qq.com
*/
