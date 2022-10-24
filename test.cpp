#include <iostream>
#include <fstream>
#include <string>

void testWrite(std::string, std::fstream&);
//	测试写文件功能，参数列表分别为1、文件名。2、创建的fstream文件对象。
void testRead(std::string, std::fstream&);
//	测试读文件功能，参数列表分别为1、文件名。2、创建的fstream文件对象。
std::string getFilename_at_Desktop();
//	方便获取读写文件的文件路径对象（以ljc用户的桌面为例）

int main()
{
	
	std::fstream fout;

	// testWrite(filename, fout);
	testRead(getFilename_at_Desktop(), fout);

	return 0;
}

void testWrite(std::string filename, std::fstream& fout)
{
	fout.open(filename, std::ios::app);

	if (!fout.is_open())
	{
		std::cout << "failed to open " << filename << '\n';
	}
	else
	{
		fout << "\nen taro Tarssadar!";
		fout.close();
	}
}

void testRead(std::string filename, std::fstream& fin)
{
	fin.open(filename, std::ios::in);

	if (!fin.is_open())
	{
		std::cerr << "failed to open " << filename << '\n';
	}
	else
	{
		char buf[1024] = {0};
		//	上面是临时申请一个1024字节大小的读空间（即buffer），并初始化为0
		while (fin >> buf)
		{
			std::cout << buf << std::endl;
			// std::cout << "一次读取进buf" << std::endl;
			//	每一次的buf是空格或回车键（即白色字符）分开的元素
		}
		
	}
}

std::string getFilename_at_Desktop()
{
	std::string Desktop_path = "C:\\Users\\ljc\\Desktop\\";
	std::string filename = Desktop_path + "test2.txt";


	return filename;
}