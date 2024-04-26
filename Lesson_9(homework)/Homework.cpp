#include <iostream>

using namespace std;

template <typename T>
class Array
{
private:
	T* ptr;
	int m_size;
public:
	Array(int size)
	{
		srand(static_cast<unsigned>(time(nullptr)));
		if (size > 0)
		{
			ptr = new T[size];

			for (int i = 0; i < size; i++)
			{
				/*ptr[i] = rand() % ('Z' - 'A') + 'A';*/
				ptr[i] = rand() % 101;
			}
			m_size = size;
		}
		else
		{
			ptr = nullptr;
			m_size = -1;
		}
	}

	void Show()
	{
		if (ptr == nullptr)
		{
			return;
		}
		for (int i = 0; i < m_size; i++)
		{
			cout << ptr[i] << ' ';
		}
		cout << endl;
	}

	bool is_Empty();

	int Get_Size()
	{
		return m_size;
	}

	void Error()
	{
		delete[] ptr;
		exit(1);
	}

	void Remove_All()
	{
		delete[] ptr;
		ptr = nullptr;
		m_size = -1;
	}

	T Get_Value(int index)
	{
		if (index >= m_size || index < 0)
		{
			cout << "ERROR!\n";
			Error();
		}

		return ptr[index];
	}

	void Set_Value(T value, int index)
	{
		if (index >= m_size || index < 0)
		{
			cout << "ERROR!\n";
			Error();
		}

		ptr[index] = value;
	}

	T& operator [](int index)
	{
		if (index >= m_size || index < 0)
		{
			cout << "ERROR!\n";
			Error();
		}

		return ptr[index];
	}

	void Add(int index, T value)
	{
		if (index >= m_size || index < 0)
		{
			cout << "ERROR!\n";
			Error();
		}
		m_size++;
		T* temp_ptr = new T[m_size];
		for (int i = 0; i < index; i++)
		{
			temp_ptr[i] = ptr[i];
		}
		temp_ptr[index] = value;
		for (int i = index; i < m_size - 1; i++)
		{
			temp_ptr[i + 1] = ptr[i];
		}
		delete[] ptr;
		ptr = temp_ptr;
	}

	void Append(T* ptr_arr, const int size)
	{
		T* temp_ptr = new T[m_size + size];
		for (int i = 0; i < m_size; i++)
		{
			temp_ptr[i] = ptr[i];
		}
		for (int i = 0; i < size; i++)
		{
			temp_ptr[m_size + i] = ptr_arr[i];
		}
		m_size += size;
		delete[] ptr;
		ptr = temp_ptr;
	}

	void operator = (const Array& array)
	{
		if (this != &array)
		{
			delete[] this->ptr;
			this->m_size = array.m_size;
			this->ptr = new T[this->m_size];
			for (size_t i = 0; i < this->m_size; i++)
			{
				ptr[i] = array.ptr[i];
			}
		}
	}

	T* Get_Data()
	{
		/*cout << ptr << endl;*/
		return ptr;
	}

	void Inser_At(T value)
	{
		m_size++;
		T* temp_ptr = new T[m_size];
		for (int i = 0; i < m_size-1; i++)
		{
			temp_ptr[i] = ptr[i];
		}
		temp_ptr[m_size-1] = value;
		delete[] ptr;
		ptr = temp_ptr;
	}

	void Remove_At()
	{
		m_size--;
		T* temp_ptr = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			temp_ptr[i] = ptr[i];
		}
		delete[] ptr;
		ptr = temp_ptr;
	}

	~Array()
	{
		if (ptr != nullptr)
		{
			delete[] ptr;
		}
	}
};

template <typename T>
bool Array<T>::is_Empty()
{
	return ptr == nullptr ? true : false;
}

int main()
{
	Array<int> array_1(10);
	array_1.Show();
	/*cout << array_1.Get_Size() << endl;*/
	/*array_1.Remove_All();
	cout << array_1.is_Empty() << endl;*/
	//array_1.Set_Value(12, 2);
	//array_1.Show();
	//cout << array_1.Get_Value(2) << endl;
	//array_1[-1] = 13;
	//array_1.Show();
	/*array_1.Add(2, 10000);
	array_1.Show();*/
	/*int* ptr_arr = new int[6] {1, 2, 3, 4, 5, 6};
	array_1.Append(ptr_arr, 6);
	array_1.Show();
	delete[] ptr_arr;*/
	/*Array<int> array_2(5);
	array_2.Show();
	array_1 = array_2;
	array_1.Show();*/
	/*cout << array_1.Get_Data() << endl;*/
	array_1.Inser_At(100000);
	array_1.Show();
	array_1.Remove_At();
	array_1.Show();

	return 0;
}