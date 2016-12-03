#include <iostream>
#include <string.h>
using namespace std;
 int main(int argc, char *argv[])
{
	string szMsg("_Community=public&_MachineName=192.168.6.96&_Port=161&devicetype=_SnmpWin&seid=2");
	char *pPos = strstr(szMsg.c_str(), "devicetype=");
	if(pPos)
	{
		char *chDevID = new char[strlen(pPos)];
		if(chDevID)
		{
			memset(chDevID, 0, strlen(pPos));
			cout << pPos << endl;
			sscanf(pPos, "devicetype= %[^&]", chDevID);
			cout << "Device Type is:" << chDevID << endl;
			delete []chDevID;
		}
	}
	return 0; 
}
