#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	string a = "BE5650G-0BA CH50A A0D THE CH50ESE 9505ST4O1F EDUCAT510 A001U0CED 910DAO A0 ENTE0S510 1F THE54 EN5ST50G 2A4T0E4SH52 T1 50C14214ATE F5T0ESS A0D BAS7ETBA88 DEVE8129E0T 50E8E9E0TA4O,95DD8E A0D H5GH SCH118S AC41SS CH50A.THEA001U0CE9E0T MAS 9ADE AT A S5G050G CE4E910O T1DAO BO 0BACH50A CE1 DAV5D SH1E9A7E4 A0D NU TA1, D54ECT14 GE0E4A8 1F THE 50TE40AT510A8 C112E4AT510 A0D ENCHA0GE DE2A4T9E0T 1FTHE 9505ST4O1F EDUCAT510.\"ME A4E ENC5TED T1 B41ADE0 1U4 2A4T0E4SH52 M5TH THE9505ST4O 1F EDUCAT510 T1 9A7E A 810G-8AST50G 592ACT 10 THE 85VES 1F CH50ESESTUDE0TS TH41UGH A 6150T8O-DES5G0ED BAS7ETBA88 CU445CU8U9 A0D A M5DE 4A0GE 1FSCH118 BAS7ETBA88 241G4A9S,\" SA5D SH1E9A7E4.\"TH5S C1995T9E0T 9A47S A01THE4 958EST10E 50 THE 0BA'S O1UTHA0D BAS7ETBA88 DEVE8129E0T EFF14TS 50 CH50A.\"F8AG { GS182D9HCT9ABC5D}" ;
	char b['~'-' '+1] = {0};
	string exist, nonexist;
	for (int i=0; a[i]!= 0 ; i++ )
	{
		b[a[i]-' '] = 1;
	}
	
	for (int i=0; i<'~'-' '+1; i++)
	{
		if (b[i])
		{
			exist += static_cast<char>(i + ' ');
		}
		else
		{
			nonexist += static_cast<char>(i + ' ');
		}
	}
	cout << "存在的：" << exist << endl;
	cout << "不存在的：" << nonexist << endl;
	return 0;
}
