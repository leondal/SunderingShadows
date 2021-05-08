// Inactive notifier command
// Thorn@ShadowGate
// 1/2/96
// Fixed bug of incorrect input_to(), added time check
// By Obsidian@ShadowGate 15/4/99
// _inactive.c

#include <std.h>

inherit DAEMON;

int cmd_inactive() {
   if(TP && TP->query_forced()) return 1;
	tell_object(TP, wrap("You go inactive.\nPress RETURN to become active again.\n"));
	TP->set_property("inactive", 1);
	tell_room(environment(TP), TPQCN+" goes inactive.\n",
	({ TP }) );
        input_to("reactivate",1,time());
	return 1;
}

int reactivate(string str,int when){
        TP->remove_property("inactive");
        tell_object(TP, "You become active.");
        if((time()-when) <= 60)
           tell_object(TP,"You have been inactive for "+(time()-when)+" seconds.");
        else
           tell_object(TP,"You have been inactive for "+((time()-when)/60)+" minutes.");
        tell_room(environment(TP), TPQCN+" becomes active.\n", ({TP}) );
	return 1;
   return 1;
}

void help() {
	write(
"
%^CYAN%^NAME%^RESET%^

inactive - flag yourself away from the keyboard

%^CYAN%^DESCRIPTION%^RESET%^

By typing %^ORANGE%^<inactive>%^RESET%^ you flag yourself as being away from the keyboard (afk). This is quite different from idling as it places you under protection from player killing. While in this state other player can not attack you or %^ORANGE%^<hit>%^RESET%^ you, but it doesn't protect from %^ORANGE%^%^ULINE%^NPC%^RESET%^s and environmental hazards, so be wary of the place you choose to idle.

Be sure to read %^ORANGE%^<help pkilling>%^RESET%^, as use of this command in player kill situations - if you don't have a %^ORANGE%^%^ULINE%^PK%^RESET%^ flag - may be considered cheating, depending on the current rules.

Your inactive status will appear on the who list as well will be appended to your adjective, and everyone in room with you will get a message.

%^CYAN%^SEE ALSO%^RESET%^

quit, who, pkilling, rules

"
	);
	return 1;
}
