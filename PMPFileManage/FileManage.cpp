#include "afx.h"
#include <windows.h> 
#include <stdio.h> 
#include "stdio.h"
#include "Afxtempl.h"

CArray<CString ,CString &> * MyFileList=new CArray<CString ,CString &>();
CArray<CArray<CString ,CString &> ,CArray<CString ,CString &> &> * MyModuList=new CArray<CArray<CString ,CString &> ,CArray<CString ,CString &> &>();
CArray<CArray<CArray<CString ,CString &> ,CArray<CString ,CString &> &> ,CArray<CArray<CString ,CString &> ,CArray<CString ,CString &> &> &> * MyProjList=new CArray<CArray<CArray<CString ,CString &> ,CArray<CString ,CString &> &> ,CArray<CArray<CString ,CString &> ,CArray<CString ,CString &> &> &>();

CArray<CString ,CString &> * m_ModuleSpinFilesList = new CArray<CString ,CString &>();
CStringArray m_ModuleSpinBmpList;
CStringArray m_ModuleSpinFortList;
CStringArray m_ModuleSpinOtherList;

CArray<CString ,CString &> * m_ModulePiezFilesList =new CArray<CString ,CString &>();
CStringArray m_ModulePiezDataList;
CStringArray m_ModulePiezFortList;
CStringArray m_ModulePiezOtherList;

CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &>  * ModuleSpin = new CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &>();
CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &>  * ModulePiez = new CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &>();

CArray<CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &>,CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &> & > * ModuleList = new CArray<CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &>,CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &> & >();

CArray<CArray<CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &>,CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &> & >,CArray<CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &>,CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &> & > &> * ProjectList=new CArray<CArray<CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &>,CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &> & >,CArray<CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &>,CArray<CArray<CString ,CString &>,CArray<CString ,CString &> &> & > &>();

void FileManage();
void ScanDirectory(CString str,int depth,CString parent);
void main(){
FileManage();
}


void FileManage(){

	// 扫描目录载入内存
	int depth=1;
	CString relativePath="";
	ScanDirectory("F:\\PMPWorkspace",depth,relativePath);
	/*
	for (int i= 0;MyProjList->GetSize();i++){
		for (int j =0 ;j<MyModuList->GetSize();j++)
		{
			for (int m=0;m<MyFileList->GetSize();m++)
			{
					printf(MyFileList->GetAt(m));
			}
		}
	}
	//*/

	delete m_ModuleSpinFilesList;
	delete m_ModulePiezFilesList;
	delete ModuleSpin;
	delete ModulePiez;
	delete ModuleList;
	delete ProjectList;
}

void ScanDirectory(CString str,int depth,CString relativePath){

	CFileFind finder;
	// build a string with wildcards
	CString strWildcard(str);
	strWildcard += _T("\\*.*");

	// start working for files
	// 存在文件或者文件夹
	BOOL bWorking = finder.FindFile(strWildcard);

	while (bWorking)
	{

		bWorking = finder.FindNextFile();
		// skip . and .. files; otherwise, we'd
		// recur infinitely!

		if (finder.IsDots()){
			continue;
		// if it's a directory, recursively search it

		//if(!finder.IsDirectory()){
		//	CString temp = finder.GetFileName();
		//	printf("%s\n",temp);
		//	//ScanDirectory(str,depth);
		//}
		}else if(finder.IsDirectory()){
			CString temp = finder.GetFileName();
			CString tempRelativePath = relativePath;
			relativePath.Append(temp+"\\");
			printf("\t%s \tdepth=%d relativepath=%s\n",temp,depth,relativePath);
			str.Append("\\"+temp);
			depth++;
			ScanDirectory(str,depth,relativePath);
			str = str.Left(str.GetLength()-temp.GetLength());
			depth--;
			relativePath = tempRelativePath;
			
		}else if (!finder.IsDots()  && !finder.IsDirectory()){
			CString temp = finder.GetFileName();
			CString tempRelativePath = relativePath;
			relativePath.Append(temp);
			printf("\t%s \tdepth=%d relativepath=%s\n",temp,depth,relativePath);
			relativePath=tempRelativePath;
		}

	}

	finder.Close();
}