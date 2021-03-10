#include <std.h>
#include <security.h>
inherit DAEMON;

void help();

int cmd_hpcheck(string str)
{
        string targ;
	object target;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

	if(!str) return help();
        if(sscanf(str,"%s", targ) != 1) return help();
	if(!target = find_player(targ)) {
		return notify_fail("There is no player named "+targ+" that you can see online!\n");
	}
	return 1;
}

void help()
{
	write("Syntax: hpcheck <player>\n\n"+
        "Create a diagnostic report of the named player's HP array.");
	return 1;
}
