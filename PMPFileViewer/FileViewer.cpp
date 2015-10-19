#include "FileViewer.h"

CFileViewer::CFileViewer(){
	FileFullPath="";
	FileName="";
	visible=false;
}
CFileViewer::~CFileViewer(){
}
void CFileViewer::setFileFullPath(CString fileFullPath){
	this->FileFullPath = fileFullPath;
}
CString CFileViewer::getFileFullPath(){
	return this->FileFullPath;
}
void CFileViewer::setFileName(CString fileName){
	this->FileName =fileName;
}
CString CFileViewer::getFileName(){
	return this->FileName;
}
void CFileViewer::setVisible(bool visible){
	this->visible = visible;
}
bool CFileViewer::getVisible(){
	return this->visible;
}