#include <std.h>
#include <security.h>

#include <daemons.h>
inherit DAEMON;

void help() {

    write("Syntax: discussc [add|remove] [player] [reason]>\n\n"
    "This will let you add or remove a player from the discuss "
    "line for the reason you specify.");
}

int cmd_discussc(string str) {
	object ob,*mortals;
	string opt, who, reason,people,*lines,*on_chan=({});
	int i;

   string posxxx;
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

	if(!str) {
        help();
        return 1;
    }
    if(sscanf(str, "%s %s %s",opt,who,reason) != 3) {
          help();
          return 1;
    }

	mortals = users();
	mortals = filter_array(mortals,"is_non_immortal_player",FILTERS_D);
	for(i=0;i<sizeof(mortals);i++)
	{
		lines = mortals[i]->query_channels();
		if(member_array("discuss",lines) != -1)
		{
			on_chan += ({ mortals[i]->query_true_name() });
		}
	}

	if(sizeof(on_chan))
	{
		people = implode(on_chan," ");
		MESSAGING_D->avatars_message("my_mess","%^B_BLUE%^%^WHITE%^"+people+" %^RESET%^ is currently on discuss.");
	}

    if(!(ob = find_player(who = lower_case(who))))
	return notify_fail("Either that player is not online or you have the name "
    "in the wrong order.\n");
    if(opt == "remove") {
        if(avatarp(ob)) { return notify_fail("You cannot restrict another immortal.\n"); }
	    ob->restrict_channel("discuss");
  MESSAGING_D->avatars_message("my_mess","%^MAGENTA%^[%^RESET%^%^BOLD%^discussc%^RESET%^%^MAGENTA%^]%^BOLD%^%^BLUE%^ "+ capitalize(who) +" %^RESET%^was%^RED%^ removed %^RESET%^by%^GREEN%^ "+ TPQN +" %^RESET%^",({ }) );
	    message("system", sprintf("You restrict %s from the discuss line.",capitalize(who)), TP);
	    message("system", sprintf("You have lost your discuss line."),ob);
	    return 1;
    }
    if(opt == "add") {
	    ob->unrestrict_channel("discuss");
  MESSAGING_D->avatars_message("my_mess","%^MAGENTA%^[%^RESET%^%^BOLD%^discussc%^RESET%^%^MAGENTA%^]%^BLUE%^%^BLUE%^ "+ capitalize(who) +" %^RESET%^was%^CYAN%^ added %^RESET%^by%^GREEN%^ "+ TPQN +" %^RESET%^",({ }) );
	    message("system", sprintf("You can now use the discuss line."),ob);
	    message("system", sprintf("You allow %s to use the discuss line.", capitalize(who)),TP);
        return 1;
    }
    help();
    return 1;
}
