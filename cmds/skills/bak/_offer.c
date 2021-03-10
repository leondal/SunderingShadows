//	/bin/users/_offer.c
//	from the Nightmare mudlib
//	Kattan ability
//	created by Gregon@nightmare
 
 
#include <std.h>
 
inherit DAEMON;
 
int cmd_offer(string str) {
    int amount;
    string class;
 
    if(str!="corpse") {
	notify_fail("Offer what?\n");
	return 0;
    }
    if(!present("remains", environment(this_player()))) {
	notify_fail("No corpse here!\n");
	return 0;
    }
    class = (string)this_player()->query_class();
    if(class != "kataan") {
	notify_fail("The demons of the underworld laugh at you.\n");
	return 0;
    }
    write("You offer this soul to the demons of the underworld.");
    say(this_player()->query_cap_name()+" pleases the demons with a fresh "
        "soul.", this_player());
    amount = random((int)this_player()->query_skill("faith")/7 + 6);
    this_player()->heal(amount);
    present("remains", environment(this_player()))->remove();
    return 1;
}
 
void help() { 
    write("Syntax: <offer corpse>\n\n"+
	"Allows a kataan to gain strength through offering the souls of "+
	"the dead to the demons of the underworld.\n");
}
