// -*- coding:   utf-8 -*-
// Author：      gsk21dx
// CreateTime：  2023/11/27  23:43
// FileName：    D-M-S_into_degrees
// Description:  度分秒转换成度/Degrees-minutes-seconds-and-degrees-are-converted-into-degrees

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	
  int iDegeree, iMin;
	double dDms,dSec,dDeg;
	cin>>dDms;
	iDegeree = int(dDms);
	iMin = round((dDms - iDegeree)*100);
	//

	dSec = ((dDms - iDegeree) * 100 - iMin) * 100;
	dDeg = iDegeree + double(iMin) / 60 + dSec / 3600;
	cout<<dDeg<<endl;

  return 0;
}



/*
------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
//这里的程序可以设计成MFC程序，即可以通过添加可视化控件的编程。

//2.1度分秒向角度的转换。

//说明：这里的度分秒指的整数为度，小数前两位为分，后两位为秒。例如：30.3030°表示的是30°30′30″。角度指的是以度为单位，也就是十进制度。例如：30.5000°表示的是30°30′00″。

void CAngleTransferApplicationDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	int iDegeree, iMin;
	double dSec;
	iDegeree = int(dDms);
	iMin = int((dDms - iDegeree) * 100);
	dSec = ((dDms - iDegeree) * 100 - iMin) * 100;
	dDeg = iDegeree + double(iMin) / 60 + dSec / 3600;
	UpdateData(FALSE);
}
//参数说明：dDeg为十进制角度（度），是一个控件变量，可以设置一个控件添加变量为dDeg。dDms为度分秒格式角度。输入的是度分秒(dDms)，输出的是角度(dDeg)。

//2.2角度向度分秒的转换。

//说明：相关的参数同上，输入的是角度dDeg,输出的是度分秒dDms。

void CAngleTransferApplicationDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	int iDegeree, iMin;
	double dSec;
	iDegeree = int(dDeg);
	iMin = int((dDeg - iDegeree) * 60);
	dSec = ((dDeg - iDegeree) * 60-iMin)*60;
	dDms = iDegeree + double(iMin) / 100 + dSec / 10000;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}
//针对角度互转程序可以在一个MFC程序中实现，首先添加相应的控件，添加成员变量。如图所示：

//可以为“转换”按钮添加事件，代码为：

void CAngleTransferDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	if (iDegree != NULL || iMin != NULL || dSec != NULL)
	{
		dDeg = iDegree + double(iMin) / 60 + dSec / 3600;
		radian = dDeg * 3.1415926535 / 180;
	}
	else if (dDeg != NULL)
	{
		radian = dDeg * 3.1415926535 / 180;
		iDegree = int(dDeg);
		iMin = int((dDeg - iDegree) * 60);
		dSec = ((dDeg - iDegree) * 60 - iMin) * 60;
	}
	else
	{
		dDeg = radian * 180 / 3.145926535;
		iDegree = int(dDeg);
		iMin = int((dDeg - iDegree) * 60);
		dSec = ((dDeg - iDegree) * 60 - iMin) * 60;
		iDegree = int(dDeg);
	}
		UpdateData(FALSE);	// TODO: 在此添加控件通知处理程序代码
}
//变量补充说明：radian为弧度，double类型。

//为“清除”按钮添加事件为：

void CAngleTransferDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	dDeg = iMin = iDegree = dSec = radian = 0;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}
//需要说明的是，上述代码仍有不足之处，例如没有考虑到小数位数的长度以及在测绘领域进行数字的“四舍六入”原则，再输入一次数据之后需要点击清除才能进行其他转换。
