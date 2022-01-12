#include<iostream>
#include<fstream>
//#define WRITE_TO_LIFE
#define READ_TO_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef  WRITE_TO_LIFE
	std::cout << "Hello World!" << std::endl;


	std::ofstream fout("file.txt",std::ios::app);
	fout << "Hello World!" << std::endl;
	fout.close();

	system("notepad file.txt");
#endif //  WRITE_TO_LIFE
#ifdef READ_TO_FILE
	const int SIZE = 102400;
	char buffer[SIZE]{};
	std::ifstream fin;
	fin.open("file.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(buffer, SIZE);
			//fin >> buffer;
			std::cout << buffer<<std::endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found"<<std::endl;
	}
	fin.close();
#endif // READ_TO_FILE

}