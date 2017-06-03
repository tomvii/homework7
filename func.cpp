#include"calcu.h"
void file::writefile(char *str, char *p)
{
	FILE *out;
	if ((out = fopen(p, "a")) == NULL)
	{
		cout << "Can not write it!!!";
		exit(0);
	}
	fputs(str, out);
	fputs("\n", out);
}

void equation::print(int v, int c)
{
	file u;
	char temp0[20] = { 0 }, temp1[20] = { 0 };
	cout << "Right:" << v << endl;
	cout << "Wrong:" << c << endl;
	temp0[0] = 'R';
	temp0[1] = 'i';
	temp0[2] = 'g';
	temp0[3] = 'h';
	temp0[4] = 't';
	temp0[5] = ':';
	temp0[6] = v + 48;

	u.writefile(temp0, p);

	temp1[0] = 'W';
	temp1[1] = 'r';
	temp1[2] = 'o';
	temp1[3] = 'n';
	temp1[4] = 'g';
	temp1[5] = ':';
	temp1[6] = c + 48;
	u.writefile(temp1, p);


}

void file::boundary(equation &cp, char *p2)
{
	char chinese[50] = { "已读写成功(#结束测试)" };
	char english[50] = { "Already done(Use # to end this test.)" };
	cp.set_p(p2);
	srand(time(NULL));
	int pq;
	cout << "0(中文) 1(Enlish):";
	cin >> pq;
	cout << "*******************************************************" << endl;
	if (pq == 0)
	{
		cout << "已读写成功(#结束测试)";
		writefile(chinese, p2);
	}
	if (pq == 1)
	{
		cout << "Already done(Use # to end this test.)";
		writefile(english, p2);
	}
	cout << endl << "*******************************************************" << endl;
}

void RandomNumber::random()
{
	tempa = 10 * rand() / RAND_MAX;
	tempb = 10 * rand() / RAND_MAX;
	tempc = 10 * rand() / RAND_MAX;
	tempd = 10 * rand() / RAND_MAX;
	while (tempb == 0 || tempd == 0)
	{
		tempb = 10 * rand() / RAND_MAX;
		tempd = 10 * rand() / RAND_MAX;
	}
}
int file::fileread(char *p1)
{
	pr = p1;
	FILE *in;
	char c[50] = { 0 };
	char ch[5] = { 0 };
	if ((in = fopen(pr, "r")) == NULL)
	{
		cout << "Can not open it!!!";
		exit(0);
	}
	fgets(ch, 3, in);
	num = atoi(ch);
	cout << num << endl;
	return num;
}
void RandomOperation::random()
{
	int int_sign;
	int_sign = 4 * rand() / RAND_MAX + 1;
	switch (int_sign)
	{
	case 1:tempo = '+'; break;
	case 2:tempo = '-'; break;
	case 3:tempo = '*'; break;
	case 4:tempo = '/'; break;
	}
}
string equation::int_string(int number)
{
	int temp = abs(number);
	char str[200];
	_itoa_s(temp, str, 10, 10);
	return str;
}

float equation::calcusum(int a, int b, string sig)
{
	float v, a1, b1;
	a1 = a;
	b1 = b;
	if (sig == "+")
		v = a1 + b1;
	else if (sig == "-")
		v = a1 - b1;
	else if (sig == "*")
		v = a1*b1;
	else if (sig == "/")
		v = a1 / b1;
	return v;
}

string equation::combine(string a, string b, string sign)
{
	string st;
	st = a + sign + b;
	return st;
}

int equation::generateExpression(int x)
{
	Random *r;
	RandomNumber N;
	RandomOperation O;
	stack<string>s;
	file u;
	string str, str_num1, str_num2, str_num3, str_num4, temp1, temp2, temp;
	string t;
	string sign1, sign2, signm;
	int w = 0;
	float sum1, sum2, sum, reply;
	int x1, x2, y1, y2;
	x = x % 2;
	r = &N;
	r->random();
	N.get_n(x1, y1, x2, y2);
	r = &O;
	r->random();
	O.get_o(sign1);
	r->random();
	O.get_o(sign2);
	r->random();
	O.get_o(signm);
	s.push("=?");
	str_num1 = '(' + int_string(x1);
	str_num2 = int_string(y1) + ')';
	str_num3 = '(' + int_string(x2);
	str_num4 = int_string(y2) + ')';
	if (x == 0)
	{
		sum1 = calcusum(x1, y1, sign1);
		sum1 = (int)(sum1 * 100 + 0.5) / 100.0;
		s.push(str_num2);
		s.push(sign1);
		s.push(str_num1);
		temp1 = combine(str_num1, str_num2, sign1);
		temp1 = temp1 + "=?";
		while (!s.empty())
		{
			cout << s.top();
			s.pop();
		}
		cout << endl;
		u.writefile(&temp1[0], p);
		cin >> reply;
		ostringstream ss1;
		ss1 << reply;
		string str1 = ss1.str();
		u.writefile(&str1[0], p);
		cout << "Right answer:" << sum1 << endl;
		ostringstream ss2;
		ss2 << sum1;
		string str2 = ss2.str();
		str2 = "Right answer:" + str2;
		u.writefile(&str2[0], p);
		if (reply == sum1)
			return 1;
		else
			return 0;
	}
	else
	{
		sum1 = calcusum(x1, y1, sign1);
		s.push(str_num4);
		s.push(sign2);
		s.push(str_num3);
		s.push(signm);
		s.push(str_num2);
		s.push(sign1);
		s.push(str_num1);
		temp1 = combine(str_num1, str_num2, sign1);
		sum2 = calcusum(x2, y2, sign2);
		temp2 = combine(str_num3, str_num4, sign2);
		temp = combine(temp1, temp2, signm) + "=?";
		if ((int)sum1 - sum1 != 0 || (int)sum2 - sum2 != 0)
			calcusum_fra(sum1, sum2, signm);          //分数
		else
			sum = calcusum(sum1, sum2, signm);
		sum = (int)(sum * 100 + 0.5) / 100.0;
		while (!s.empty())
		{
			cout << s.top();
			s.pop();
		}
		cout << endl;
		u.writefile(&temp[0], p);
		cin >> reply;
		ostringstream ss3;
		ss3 << reply;
		string str3 = ss3.str();
		u.writefile(&str3[0], p);

		cout << "Right answer:" << sum << endl;
		ostringstream ss4;
		ss4 << sum1;
		string str4 = ss4.str();
		str4 = "Right answer:" + str4;
		u.writefile(&str4[0], p);
		if (reply == sum)
			return 1;
		else
			return 0;
	}




}
int equation::test(int total, char *p1)
{
	int i, v, u = 0;
	p = p1;
	for (i = 0; i<total; i++)
	{
		v = 8 * rand() / RAND_MAX;
		u = u + generateExpression(v);
		if (getchar() == '#')
		{
			u++;
			break;
		}
	}
	right = u;
	wrong = total - u;
	return u;
}

void equation::set_p(char *p1)
{
	p = p1;
}
float equation::calcusum_fra(float a, float b, string sig)
{
	float v, a1, b1;
	a1 = a;
	b1 = b;
	if (sig == "+")
		v = a1 + b1;
	else if (sig == "-")
		v = a1 - b1;
	else if (sig == "*")
		v = a1*b1;
	else if (sig == "/")
		v = a1 / b1;
	return v;
}

void RandomOperation::get_o(string &temp)
{
	temp = tempo;
}
void RandomNumber::get_n(int &a, int &b, int &c, int &d)
{
	a = tempa;
	b = tempb;
	c = tempc;
	d = tempd;
}