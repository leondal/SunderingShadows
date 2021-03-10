//	/cmds/hm/_wizfollow.c
//	from the Nightmare mudlib
//	allows players to follow one another
//	created by Descartes of Borg 15 february 1993
//      modified /cmds/mortal/follow.c by Aragorn 10-21-94 
#include <std.h>

inherit DAEMON;

int cmd_sfollow(string str)
{
	object ob;
   	string posxxx; 
	if(!objectp(TP)) { return 0; }
   	if(!avatarp(this_player())) { return 0; }
	if(!str)
	{
		notify_fail("Correct syntax: <sfollow [who]> or <sollow off>\n");
		return 0;
	}
	if(str == "off")
	{
		if(!objectp(ob = present("s_follow_object", TP))) 
		{
			notify_fail("You are not currently super following anyone...");
			return 0;
		}
		tell_object(TP, "Super follow ending....");
		ob->remove();
		return 1;
	}
	ob = new("/realms/saide/sfollow_ob.c");
	ob->move(TP);
	ob->set_target(str);
	return 1;	
}


void help()
{
    write("Syntax: <wizfollow [name]>\n\
        <wizfollow off>\n\n\
<wizfollow off> allows to stop following a player.\n\
<wizfollow> allows you to follow a player.\n"
);
}
