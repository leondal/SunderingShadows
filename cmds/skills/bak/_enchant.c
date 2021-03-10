//	_enchant.c
//	Mage ability
//	created 25 October 1992 by Descartes of Borg

#include <std.h>

inherit DAEMON;

int cmd_enchant(string str) {
    object ob, tp;
    int con, amount;

    if(!str) {
	notify_fail("Enchant what?\n");
	return 0;
    }
    tp = this_player();
    ob = present(str, tp);
    if(!ob) ob = parse_objects(tp, str);
    if(!ob) {
	notify_fail("You can't find that!\n");
	return 0;
    }
    if((int)ob->query_property("enchantment") > 0) {
	notify_fail("The item is too strong with magic already.\n");
	return 0;
    }
    if( (con = (int)tp->query_skill("conjuring")) < 35) {
	notify_fail("You are not skilled enough to cast such a spell.\n");
	return 0;
    }
    if( (int)tp->query_mp() < (amount = random(150)) ) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    tp->add_mp(-amount);
    tp->add_skill_points("conjuring", random(amount));
    write("You mutter a few mystical words.\n");
    say(tp->query_cap_name()+" mutters a few mystical words.\n", tp);
    if(con > random(101)) {
	ob->set_property("enchantment", 1);
	write("Your "+ob->query_name()+" glows with magic.\n");
	say(tp->query_cap_name()+"'s "+ob->query_name()+" glows with magic.\n");
	call_out("remove_enchantment", 5*con, ob);
    }
    else write("You fail to enchant it.\n");
    return 1;
}

void remove_enchantment(object ob) {
    if(!ob) return;
    ob->set_property("enchantment", -1);
}

void help() {
    write("Syntax: <enchant [item]>\n\n"+
	"Makes an item perform its natural functions even better.\n");
}

