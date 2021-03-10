//	_sign.c  Assassins secret hand communications
//      For the Nightmare Assassins guild
//      Coded by Kalinash 1 Nov 93
 
#include <std.h>

inherit DAEMON;

int cmd_sign(string str)
        {
        object *them;
        int x;
 
        them = all_inventory(environment(this_player()));
        them = filter_array(them, "is_living", this_object());
//	them -= ({ this_player() });
	map_array(them, "tell_them", this_object(), str);
	write("You sign your message in the secret hand "
		"code of the Assassins.");
	return 1;
	}

void tell_them(object who, string str)
	{
		tell_object(who, this_player()->query_cap_name()+ 
		" signs : "+str);
        return;
        }

int is_living(object who)
	{
	if(!living(who))
		return 0;
	if((string)who->query_guild() != "assassin")
		return 0;
	return 1;
	}
