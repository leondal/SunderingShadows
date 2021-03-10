#include <std.h>

inherit DAEMON;

int help()
{
	write("This command allows you to delete an exit from Shadowgate that leads into one of your "
		"created rooms to keep unwary players from meeting their demise when you don't yet "
		"have your popcorn ready.  Syntax: delete <exit name>");
	return 1;
}

int cmd_delete(string str)
{
	string name,path;
	if(!stringp(str) || str == "")
	{
		help();
		return 1;
	}
	name = TP->query_true_name();
	path = "/d/av_rooms/"+name+"/";
	if((string)ETP->query_exit(str) == "/d/shadowgate/void")
	{
		tell_object(TP,"That is not an exit, check your spelling and try again.");
		return 1;
	}
	if(strsrch((string)ETP->query_exit(str),path) == -1)
	{
		tell_object(TP,"You can only delete exits to rooms that lead into the "
			"/d/av_rooms/"+name+"/ path.");
		return 1;
	}
	tell_object(TP,"Exit "+str+" leading to "+(string)ETP->query_exit(str)+" removed.");
	ETP->remove_exit(str);
	return 1;
}




