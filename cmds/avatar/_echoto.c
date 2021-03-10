#include <std.h>
#include <security.h>
inherit DAEMON;

void help();

int cmd_echoto(string str)
{
	string targ, line;
	object target;
	string nme;

   string posxxx;
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

	if(!str) return help();
	if(sscanf(str,"%s %s", targ, line) != 2) return help();
	if(!target = find_player(targ)) {
		return notify_fail("There is no player named "+targ+" that you can see online!\n");
	}
	if(target == TP) {
		return notify_fail("Oh baby, that feels sooo good...freak.\n");
	}
	seteuid(UID_LOG);
	seteuid(getuid());
  line = replace_string(line,"%^NL%^","\n");
        message("echo",line,target);
        message("echo","You echoto "+targ+":\n"+line+"",TP);
	return 1;
}

void help()
{
	write("Syntax: echoto <player> <message>\n\n"+
	"The echo will only be seen by the player you have"+
	" specified. So drive them insane, make them think"+
	" they're hearing voices, and have fun.");
	return 1;
}
