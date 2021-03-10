//	_purify.c
//	Cleric ability
//	created 25 October 1992

#include <std.h>

inherit DAEMON;

int cmd_purify(string str) {
    object ob, tp;
    int i, heal, pure;

    if(!str) {
 	notify_fail("Purify whom?\n");
	return 0;
    }
    if(str == "me" || str == "myself") ob = this_player();
    else ob = present(str, environment(this_player()));
    if(!ob) {
	notify_fail(capitalize(str)+" is not here!\n");
	return 0;
    }
    if(!living(ob)) {
	notify_fail(capitalize(str)+" is not a living thing!\n");
	return 0;
    }
    tp = this_player();
    heal = (int)tp->query_skill("healing");
    if(heal < 10) {
	notify_fail("You are not skilled enough for that.\n");
	return 0;
    }
    pure = random(heal);
    if((string)this_player()->query_class() == "kataan") {
        notify_fail("Your powers are not for good ends.\n");
        return 0;
    }
    if(!alignment_ok(this_player())) {
	notify_fail("You have betrayed the source of your powers.\n");
	return 0;
    }
    if(ob == tp) pure = random(pure);
    if( (int)tp->query_mp() < pure ) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    this_player()->set_magic_round();
    write("You mutter a prayer of healing.");
    say(tp->query_cap_name()+" mutters a prayer of healing.", tp);
    tp->add_skill_points("healing", pure);
    tp->add_alignment(pure);
    ob->add_poisoning(-pure);
    tp->add_mp(-pure);
    tell_object(ob, "Your blood has been purified.");
    if(ob != tp) write("You purify the blood of "+ob->query_cap_name()+".");
    return 1;
}

void help() {
    write("Syntax: <purify [living]>\n\n"+
	"This prayer reduces the amount of poison in the blood of a player "
	"or monster.\n");
}
