//	/cmds/hm/_wizfollow.c
//	from the Nightmare mudlib
//	allows players to follow one another
//	created by Descartes of Borg 15 february 1993
//      modified /cmds/mortal/follow.c by Aragorn 10-21-94 
#include <std.h>

inherit DAEMON;

int cmd_wizfollow(string str)
{
	object ob;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

	if(!avatarp(this_player())) { return 0; }
	if(!str)
	{
		notify_fail("Correct syntax: <follow [who]> or <follow off>\n");
		return 0;
	}

	if(str != "off")
	{

		ob = this_player()->query_following();
		if(ob)
		{
			notify_fail("You are already following "+ob->query_cap_name()+".\n");
			return 0;
		}
		if(!find_player(str))
		{
			notify_fail("No "+capitalize(str)+" in our reality.\n");
			return 0;
		}
		ob = present(lower_case(str), environment(this_player()));
		if(!ob)
		{
			notify_fail("No one by that name around here.\n");
			return 0;
		}
		if(ob == this_player())
		{
			notify_fail("You cannot wizfollow yourself!\n");
			return 0;
		}
		if(wizardp(ob))
		{
			notify_fail("You cannot wizfollow another wizard.\n");
			tell_object(ob, this_player()->query_cap_name()+" tried to wizfollow you!\n");
			return 0;
		}
		if(!ob->add_follower(this_player()))
		{
			notify_fail("You cannot wizfollow someone who is following you!\n");
			return 0;
		}
		write("You are now following "+capitalize(str)+".\n");
		return 1;
	}
	ob = this_player()->query_following();
	if(!ob)
	{
		notify_fail("You are not wizfollowing anyone.\n");
                TP->set_following(0);
		return 0;
	}
	ob->remove_follower(this_player());
	write("You are no longer following "+capitalize(ob->query_name())+".\n");
        TP->set_following(0);
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
