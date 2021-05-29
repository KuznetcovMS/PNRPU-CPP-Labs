class VectorOfMoney
{
public:
	double *data;
	int size;

	VectorOfMoney(int s);
	void Print();
	double FindMin();
	double FindMax();
	void pushback(double el);
	void del(double el);
	void add2(double el1, double el2);
};
