/*
 * main.cpp
 * an ugly notepad under command line
 *  Created on: 2014-3-16
 *      Author: WAY
 */

#include "functxt.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

void simpleUi();
void hasFile(FILETXT file);
void clearFile(FILETXT file);
void readFile(FILETXT file);
void createFile(FILETXT file);
void writeFile(FILETXT file);
void copyFile(FILETXT file);

int main()
{
	FILETXT file;
	char ch=0;

	while(ch != 'q' || 'Q')
	{
		simpleUi();
		std::cin>>ch;
		switch (ch)
		{
		case 'm':
		    createFile(file); break;
		case 'w':
			writeFile(file); break;
		case 'r':
			readFile(file); break;
		case 'l':
			clearFile(file); break;
		case 'c':
			copyFile(file); break;
		case 'h':
			hasFile(file); break;
		case 'q':
			exit(0);
		default:
			std::cout << "Input ERROR!\n";
			break;
		}
	}
	return 0;
}

//UI DOS
void simpleUi()
{
	std::cout<<"==============MENU==============="<<std::endl;
	std::cout<<" [m] Make   [w] Write  [r] Read  "<<std::endl;
	std::cout<<" [c] Copy   [l] Clear  [h] Have  "<<std::endl;
	std::cout<<"================================="<<std::endl;
	std::cout<<"Please Input U's Choice :"<<std::endl;
}

//if file exist?
void hasFile(FILETXT file)
{
	std::cout<<"Enter file path:";
	std::cin>>file.filepath;
	if(file.isExist(file.filepath))
	{
		std::cout<<"FILE EXIST!"<<std::endl;
	}
	else
		std::cout<<"NO SUCH FILE!"<<std::endl;
}

// flush the file content which is existed
void clearFile(FILETXT file)
{
	std::cout<<"Enter file name[path]:";
	std::cin>>file.filepath;
	if (file.fileClear(file.filepath))
	{
		std::cout << "FILE CLEARED!" << std::endl;
	}
	else
		std::cout << "NO SUCH FILE!" << std::endl;
}

// print the file content
void readFile(FILETXT file)
{
	std::cout<<"Enter file name[path]:";
	std::cin>>file.filepath;
	if(file.isExist(file.filepath))
	{
		file.fileRead(file.filepath);
	}
	else
		std::cout<<"Open file ERROR!"<<std::endl;
}

void createFile(FILETXT file)
{
	std::cout<<"Enter file name[path]:";
	std::cin>>file.filepath;
	//if (!file.isExist(file.filepath))
	//{
	if (file.fileCreate(file.filepath))
		std::cout << "File created !\n";
	//}
	else
		std::cout<<"Create failed!\n";
}

// write somrthing into the file
void writeFile(FILETXT file)
{
	std::vector <char> vec_char;
	char ch;
	std::cout<<"please input name[path]:";
	std::cin>>file.filepath;
	std::cout<<"Text end with $:\n";
	while((ch=getchar())!='$')		//getchar() need stdio.h
	{
		vec_char.push_back(ch);
	}
	if(file.fileWrite(file.filepath,vec_char))
		std::cout<<"write success\n";
	else
		std::cout<<"write failed!\n";
}

//copy text from one directory to another
void copyFile(FILETXT file)
{
	std::string fileSource,fileDestination;
	std::cout<<"Input Source filepath:";
	std::cin>>fileSource;

	std::cout<<"Input Destination filepath:";
	std::cin>>fileDestination;

    if(file.fileCopy(fileSource,fileDestination))
    	std::cout<<"Copy Successed!\n";
    else
    	std::cout<<"Copy filed!\n";
}
