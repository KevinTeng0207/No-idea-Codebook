class Rational
{
	friend istream &operator>>(istream &, Rational & );
	friend ostream &operator<<(ostream &, const Rational & );
public:
	Rational()  //constructor one
	{		
		m_numeitor = 0;
		m_denominator = 1;
	}
	Rational(int a, int b)	//constructor two
	{
		if (b < 0 || b == 0)	//avoids negative denominators. && prevents a 0 denominator
		{
			cout << "This Rational number can't be used.\n\n";
			m_numeitor = 0;
			m_denominator = 0;
		}
		else
		{
			cout << "This Rational number can be used.\n\n";
			m_numeitor = a;
			m_denominator = b;
		}		
	}
	Rational operator+(const Rational& a);	//加
	Rational operator-(const Rational& a);	//減
	Rational operator*(const Rational& a);	//乘	
	Rational operator/(const Rational& a);	//除
	bool operator==(const Rational& a);		//相等
	void reduce();	//化簡
private:
	int m_numeitor;
	int m_denominator;	
};
istream &operator>>(istream &input, Rational &test )
{
	char temp;	
	
	input >> test.m_numeitor;
	input >> temp;
	input >> test.m_denominator;
	Rational final(test.m_numeitor, test.m_denominator);	//final用來告訴使用者這數字符不符合!
	if (test.m_denominator < 0 || test.m_denominator == 0)   //不符合(再輸入一次)
	{
		while (test.m_denominator < 0 || test.m_denominator == 0)   //有可能輸入的東西還是不符合,所以用迴圈
		{
			cout << "Enter another Rational number (n/d): ";
			input >> test.m_numeitor;
			input >> temp;
			input >> test.m_denominator;
			Rational final(test.m_numeitor, test.m_denominator);	//final用來告訴使用者這數字符不符合!
		}
		return input;
	}
	else
		return input;	
}
ostream &operator<<(ostream &output, const Rational &test )
{
	output << test.m_numeitor;
	if(test.m_numeitor == 0)
		return output;		
	if (test.m_denominator == 1)
		return output;
	else
	{
		output << "/";
		output << test.m_denominator;
	}
	return output;
}
Rational Rational::operator+(const Rational& a)
{
	Rational c;
	c.m_denominator = this->m_denominator * a.m_denominator;  //通分(同乘)
	c.m_numeitor = (this->m_numeitor * a.m_denominator) + (a.m_numeitor * this->m_denominator); 
	c.reduce();
	return c;
}
Rational Rational::operator-(const Rational& a)
{
	Rational c;
	c.m_denominator = this->m_denominator * a.m_denominator;
	c.m_numeitor = (this->m_numeitor * a.m_denominator) - (a.m_numeitor * this->m_denominator);	
	c.reduce();
	return c;
}
Rational Rational::operator*(const Rational& a)
{
	Rational c;
	c.m_denominator = this->m_denominator * a.m_denominator;
	c.m_numeitor = this->m_numeitor * a.m_numeitor;
	c.reduce();
	return c;
}
Rational Rational::operator/(const Rational& a)
{
	Rational c;
	c.m_denominator = this->m_denominator * a.m_numeitor;
	c.m_numeitor = this->m_numeitor * a.m_denominator;	
	c.reduce();
	return c;
}
bool Rational::operator==(const Rational& a)
{
	if (m_numeitor == a.m_numeitor)
	{
		if (m_denominator == a.m_denominator)
			return true;
		else
			return false;
	}
	else
		return false;		
}
void Rational::reduce()
{
	int i;
	int max;
	if(m_numeitor> m_denominator)
		max = m_numeitor;
	else
		max = m_denominator;
	for (i = 2; i <= max; i++)
	{
		if (m_denominator % i == 0 && m_numeitor % i == 0)
		{
			m_denominator /= i;
			m_numeitor /= i;
			i = 1;
			max = m_denominator;
			continue;
		}
	}
}