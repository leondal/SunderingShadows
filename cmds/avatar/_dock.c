#include <std.h>

inherit DAEMON;


int cmd_dock(string str){
	string *docks, tmp = "";
	int x;
	if (!str) 
	{
		//Added by Saide to allow avatars to simply type 'dock' to see the available 
		//docks - 3/18/2007
		docks = get_dir("/d/shadow/virtual/sea/");
		for(x = 0;x < sizeof(docks);x++)
		{			
			if(docks[x][strlen(docks[x])-7..(strlen(docks[x])-1)] == ".dock.c")
			{
				tmp += replace_string(docks[x], ".dock.c", "") + "\n";
			}
		}
		write("%^CYAN%^Available Docks : %^RESET%^\n");
		write(tmp);
		return 1;
	}
		//return notify_fail("You need to specify a dock first.\n");
    	if(catch(TP->move_player("/d/shadow/virtual/sea/"+str+".dock"))){
     		return notify_fail("no such dock\n");
   	}
   	return 1;
}

int help(){
	write("Syntax: dock || dock <dockname> \n\n"+
	"The command dock without an argument will list the docks that are available to you.  "+
	"If you use dock <dockname> and dockname is a valid dock it will move you to the "+
	"specified <dockname>.");
	return 1;
}
