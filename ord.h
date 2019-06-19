#ifndef _ord_h
#define _ord_h

class Ordenate{

private:
	int *data;
	int dim;

public:
	Ordenate(int n);
	~Ordenate();
	
	void BubbleSort();
	void SelectionSort();
	void InsertionSort();
	void ShellSort();
	
	inline
	void Setdata(int index ,int value){
		data[index] = value;
	}
	
	inline 
	int operator[](int index){
		return data[index];
	}

	void Show();	
	
	

};


#endif
