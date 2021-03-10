#include <std.h>

inherit DAEMON;

void help() {
    write("Usage:  uncon <player>");
    write("\nThis command will let you knock the targeted "+
    "player unconscious.");
    return 1;
}

int cmd_uncon(string str){
    object who;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if(!str) {
        return help();
    }
    who = find_player(str);
    if(!objectp(who)) {
        write("No such player online!");
        return 1;
    }
    if(avatarp(who) && who->query_level() > TP->query_level()) {
        write("NOPE!! HA HA HA!!! courtesy of Saide ;-)");
        return 1;
    }

	if(who->query_unconscious()) 
	{ 		 
		tell_room(environment(who),who->query_cap_name()+" regains consciousness.");
		who->set_unconscious(0);	
	}
	else 
	{
		who->set_unconscious(30);
		tell_room(environment(who),who->query_cap_name()+" falls unconscious.");
	}
    return 1;
}
