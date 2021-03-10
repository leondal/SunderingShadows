//      /bin/dev/_echo.c
//      from the Nightmare Mudlib
//      echoes to the player's environment
//      created by ????

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_echo(string str)
{
	object *usrs;
	int x, min, max;
	string posxxx, range, msg, *tmp;
   	if(!objectp(TP)) { return 0; }
	posxxx = lower_case((string)TP->query_position());
   	if(posxxx == "builder" || posxxx == "apprentice")
   	{
      	tell_object(TP,"You cannot use this command as a builder or apprentice.");
       	return 1;
   	}

    	if(!str)
	{
      	notify_fail("Echo what?\n");
        	return 0;
    	}


	if(sscanf(str,"%s | %s", range, msg))
	{
		tmp = explode(range, " ");

		if(sizeof(tmp) > 1)
		{
			range = tmp[1];
		}
		tmp = explode(range, "-");

		if(sizeof(tmp) > 1)
		{
			min = to_int(tmp[0]);
			max = to_int(tmp[1]);
		}
		else
		{
			min = to_int(range);
			max = min;
		}

		if(!intp(min) || !min)
		{
			tell_object(TP, "You failed to specify a level range.");
			tell_object(TP, "Try echo level minlevel-maxlevel | msg");
			return 1;
		}
		usrs = users();
		tell_object(TP, "%^BOLD%^%^CYAN%^Echoing to players level "+
		"%^BOLD%^%^YELLOW%^<"+
		"%^BOLD%^%^WHITE%^"+min + "%^BOLD%^%^CYAN%^ to %^BOLD%^%^WHITE%^"+
		max+"%^BOLD%^%^YELLOW%^>%^BOLD%^%^CYAN%^ the message "+msg);
		for(x = 0;x < sizeof(usrs);x++)
		{
			if(!objectp(usrs[x])) continue;
			if(usrs[x]->query_level() >= min &&
			usrs[x]->query_level() <= max)
			{
				tell_object(usrs[x], msg);
				continue;
			}
		}
		seteuid(UID_LOG);
	  	str = replace_string(str,"\n","%^NL%^");
    		seteuid(getuid());
		return 1;
	}
	str = replace_string(str,"%^NL%^","\n");
	message("echo", str, environment(this_player()));
    	seteuid(UID_LOG);
  	str = replace_string(str,"\n","%^NL%^");
    	seteuid(getuid());
    	return 1;
}

void help()
{
	message("help",
      "Syntax: <echo [message]>\n"
	"\t<echo level minlevel-maxlevel | [msg]\n\n"
      "Echoes the message to everyone in your environment.  Do not abuse "
      "this power or you will have to deal with law. \n\nAlternatively you can "
	"also echo a message to players within a particular level range "
	"by using the syntax echo level minlevel-maxlevel | message. "
	"For example echo 10-20 | A Rabbit Hops By! would tell everyone "
	"online in the level range of 10 - 20 the message 'A Rabbit Hops By!", this_player());
}
