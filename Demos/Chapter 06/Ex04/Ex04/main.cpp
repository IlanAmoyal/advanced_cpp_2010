#include <iostream>
#include <cstdio>

class BaseX
{
private:
	int m_n1;
public:
	void PrintAddresses()
	{ 
		printf("BaseX(%d bytes): this = %.8X, &m_n1 = %.8X\n", sizeof(BaseX), this, &m_n1); 
	}
};

class BaseY
{
private:
	int m_n2;
	int m_n3;
public:
	void PrintAddresses()
	{ 
		printf("BaseY(%d bytes): this = %.8X, &m_n2 = %.8X, &m_n3 = %.8X\n",sizeof(BaseY), this, &m_n2, &m_n3); 
	}
};

class BaseZ
{
private:
	int m_n4;
	int m_n5;
	int m_n6;
public:
	void PrintAddresses()
	{ 
		printf("BaseZ(%d bytes): this = %.8X, &m_n4 = %.8X, &m_n5 = %.8X, &m_n6 = %.8X\n", sizeof(BaseZ), this, &m_n4, &m_n5, &m_n6);
	}
};

class Derived : public BaseX, public BaseY, public BaseZ
{
private:
	int m_n7;
public:
	void PrintAddresses()
	{ 
		BaseX::PrintAddresses(); 
		BaseY::PrintAddresses(); 
		BaseZ::PrintAddresses(); 
		printf("Derived(%d bytes): this = %.8X, &m_n7 = %.8X\n", sizeof(Derived), this, &m_n7);
	}
};

int main(int argc, char **argv)
{
	Derived *pDerived = new Derived();
	pDerived->PrintAddresses();
	printf("\n");
	printf("pDerived = %.8X\n", pDerived);
	printf("static_cast<BaseX *>(pDerived) = %.8X\n", static_cast<BaseX *>(pDerived));
	printf("static_cast<BaseY *>(pDerived) = %.8X\n", static_cast<BaseY *>(pDerived));
	printf("static_cast<BaseZ *>(pDerived) = %.8X\n", static_cast<BaseZ *>(pDerived));
	printf("\n");
	static_cast<BaseX&>(*pDerived).PrintAddresses();
	delete pDerived;
}