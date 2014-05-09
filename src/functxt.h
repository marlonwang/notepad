/*
 * functxt.h
 *
 *  Created on: 2014-3-16
 *      Author: WAY
 */

#ifndef FUNCTXT_H_
#define FUNCTXT_H_

#define Error -1
#define Succcess 1

#include <vector>
#include <string>
using std::vector;

class FILETXT
 {

public:
	std::string filepath;

public:
	bool isExist(std::string flname);		//存在判断
	bool fileCreate(std::string flname);	//创建文本
	bool fileWrite(std::string flpath,vector<char> &vecstr); 	//写入文本
	bool fileRead(std::string flpath); 	//保存文本
	bool fileCopy(std::string flpath1,std::string flpath2); //复制文本
	bool fileClear(std::string flpath); 	//删除文本
 };

#endif /* FUNCTXT_H_ */
