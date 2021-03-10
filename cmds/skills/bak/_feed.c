//	/bin/users/_feed.c
//	from the Nightmare mudlib
//	Mage ability
//	created by Descartes of Borg

#include <std.h>

inherit DAEMON;

int cmd_feed(string str) {
    int amount;
    string class;

    if(!str) {
	notify_fail("Feed on what?\n");
	return 0;
    }
    if(sscanf(str, "on %s", str) != 1 && str != "corpse") {
	notify_fail("You can only feed on corpses.\n");
	return 0;
    }
    if(!present("remains", environment(this_player()))) {
	notify_fail("No corpse here!\n");
	return 0;
    }
    class = (string)this_player()->query_class();
    if(class != "mage" && class != "monk" && class != "cleric") {
	notify_fail("Yuck!\n");
	return 0;
    }
    write("You feed on the soul of the recently deceased.\n");
    say(this_player()->query_cap_name()+" feeds on the soul of the recently deceased.\n", this_player());
    amount = random((int)this_player()->query_skill("conjuring")/7 + 6);
    this_player()->heal(amount);
    present("remains", environment(this_player()))->remove();
    return 1;
}

void help() { 
    write("Syntax: <feed on corpse>\n\n"+
	"Allows the magic user to gain strength through feeding on the souls\n"+
	"of the recently deceased.\n");
}
