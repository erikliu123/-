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
			}//这个是考虑特判即0和-0的情况
			if (flag)
			{
				sv = "ling";
				v.push_back(sv);
			}//这个flag是为了处理0何时读和不读的问题
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
			}//这个是为了加万
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
			}//加单位
			if (i == 4&& s[s.size() - 1 - i] != '-')
			{
				sv = "Wan"; v.push_back(sv);
			}
			else if (i == 8 && s[s.size() - 1 - i] != '-')
			{
				sv = "Yi"; v.push_back(sv);
			}//对万、亿进行特殊处理
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
			}//输出数字
			if (s[s.size() - 1 - i] == '-')
			{
				sv = "Fu"; v.push_back(sv);
			}//处理负号
		}
	}
	reverse(v.begin(), v.end());//反转字符串
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (i != v.size() - 1)
			cout << " ";
	}
}
/*这个题费了我很长时间，还是练得不到位。说下思路：我是从数字字符串的后面往前依次开始处理的，
首先要注意个位为0时，0是不能被读出来的（当数字不是1位时）。那么在什么情况下，0是要被读出来的？当单位之间不连续时
就应该把0读出来，举几个简单的例子理解下：101、10001、100000001，依次被读为一百零一、一万
零一和一亿零一，百、万、亿跟个位不连续，但110被读为一百一十，百和十连续。还有一种现象不知你
发现了没有，当不连续的单位之间有多个0时，只读一个0.那么这样的话，我用一个flag（默认为false）
来处理，就是说当从后开始扫到0时，不读，一直到扫到第一个不为0的数，把flag变为true，当再碰到0
时就要读出来，但读出来之后把flag置为false，后面若还是0仍不读直到再次碰到非零数重复上述过程。
再说下对单位的处理，当扫到十位时，若不是0那么就要把单位Shi加上，注意我是从后面往前扫的，加完后
把容器vector逆转下就可以得到正常的顺序，当扫到百位时，若非0就把单位Bai加上，后面依次类推，对万
跟亿单独处理即可，题目规定数字不会超过9位其实降低了难度，也就是说顶多到亿。这里再补充下对万这个单
位的添加，只要数字不会达到1亿，那么超过一万的数字按上面所说加就行。但是达到1亿了的话，那么就得判
断万位、十万位、百万位、千万位是否都为0，若是则不能把万加上，比如说100000001被读为1亿零一，没有万。
但只要有一个不为0那么万就应该加上，比如说100100000,被读为1亿零十万。
最后注意下对0和-0的处理即可，这时虽然在个位却要被读出来。其实我说的可能有点难懂，像这样看一遍看不
出来思路的题，那么按照从特殊到一般的思想，多举几种例子以帮助理解。WA多数是因为考虑问题不全面，总有
几个特殊的例子你没考虑到。所以做这样的题，使劲往刁钻处想，怎么特殊怎么想，对一般情况的处理都是较简单的。
若还不懂的话，可发我邮件一起交流交流，593807467@qq.com
*/
