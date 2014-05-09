/*
 * functxt.cpp
 *
 *  Created on: 2014-3-16
 *      Author: WAY
 */

#include "functxt.h"
#include <fstream>
#include <iostream>

bool FILETXT::isExist(std::string flname)	//是否存在
{
	std::ifstream ifs;

	ifs.open(flname.c_str(),std::ios::in);	//in读取
	if(ifs)
	{
		ifs.close();
		return true;
	}
	else
		ifs.close();
	return false;
}
//ofstream是从内存到硬盘，ifstream是从硬盘到内存
bool FILETXT::fileCreate(std::string flname)	//创建文本
{
	std::ofstream ouf;
	//创建 若文本已经存在则清空
	ouf.open(flname.c_str(),std::ios::out);
	if (ouf)
	{
		ouf.close();
		return true;
	}
	return false;
}

bool FILETXT::fileWrite(std::string flpath,vector<char> &vecstr)	//写入文本
{
	std::ofstream fw(flpath.c_str(), std::ios::app);
	//打开文件用于写,若文件不存在就创建它
	if (!fw)
		return false; //打开文件失败则结束运行
	else {
		for(unsigned it=0;it<vecstr.size();it++)
		    fw << vecstr[it]; //使用插入运算符写文件内容
	}
	fw.close();
	return true;
}


bool FILETXT::fileCopy(std::string flpath1,std::string flpath2) //复制文本
{
	std::ifstream fin(flpath1.c_str(), std::ios::in);
	std::ofstream fout(flpath2.c_str(), std::ios::ate);
	if (fin && fout)
		fout << fin.rdbuf();	//from flpath2 to flpath1
	else
		return false;
	fout.close();
	fin.close();
	return true;
}

bool FILETXT::fileRead(std::string flpath)		//保存文本
{
	std::ifstream fread(flpath.c_str(), std::ios::in);
	std::string line;
	unsigned length=0;
	if(!fread)
		std::cout<<"File not EXIST"<<std::endl;
	else if (fread && !fread.eof()) 		//judge the end
	{
		while (getline(fread,line,'\r'))
		{
			std::cout << line; 		//output file content one by one
			length++;
		}
		std::cout<<std::endl;
		fread.close(); 				//circularly
		if(length==0)
			std::cout<<"File is EMPTY"<<std::endl;
		return true;
	}
	else
		fread.close();
	return true;
}

bool FILETXT::fileClear(std::string flpath)	//删除文本
{
	std::ofstream fc(flpath.c_str(), std::ios::trunc);
	if (!fc.eof()) 			//cannot judge empty
	{
		fc << "";
		fc.close();
		return true;
	} else {
		fc.close();
		std::cout << "file is empty already!\n";
	}
	return false;
}


