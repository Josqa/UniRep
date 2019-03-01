using namespace std; 

class CVector 
{ 
public:
	double *arr; 
	int k; 
	void SetZero(); 
	~CVector(){Clean();} 
	//CVector(const CVector &b){CopyOnly(b);} 
	void Clean(){delete[] arr; SetZero();} 
	void CopyOnly(const CVector &b); 
	CVector &operator=(const CVector &b); 
	//CVector operator+(const CVector &b); 
	//CVector operator-(const CVector &b); 
	double operator^(const CVector &b); 
	friend ostream &operator<<(ostream &cc, CVector &b); 
	friend istream &operator>>(istream &cc, CVector &b); 
	virtual void output() = 0;
};

class CVector1 : public CVector
{
public:
	CVector1(int l = 0);
	virtual void output() { cout << *this; }
};

class CVector2 : public CVector
{
public:
	CVector2(int l = 0);
	virtual void output() { cout << *this; }
};