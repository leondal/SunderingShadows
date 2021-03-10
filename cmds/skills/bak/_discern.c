//      _discern.c
//      Fighter ability
//      created 04 November 1992

#include <std.h>

inherit DAEMON;

int cmd_discern(string str) {
    string x, type, limbs;
    object tp, ob;

    tp = this_player();
    if((string)tp->query_class() != "fighter") return 0;
    if(!str) return notify_fail("Discern what?\n");
    if(tp->query_sp() < 5) {
        notify_fail("You fail.\n");
        return 0;
    }
    ob = present(str, tp);
    if(!ob) ob = parse_objects(tp, str);
    if(!ob) {
        notify_fail("No "+str+" here!\n");
        return 0;
    }
    x = (string)ob->query_type();
    if(!x) {
	notify_fail("That is neither armour or a weapon!\n");
        return 0;
    }
    if(!ob->query_wc()) {
	if(!limbs=ob->query_limbs())
            return notify_fail("That is neither armour or a weapon!\n");
	tp->add_sp(-10);
        message("info", sprintf("%s is of type %s.", capitalize(str),
	  x), tp);
	message("info", sprintf("%s covers your : ", capitalize(str)),
	  tp);
	message("info", sprintf("%s", format_page(limbs, 5)), tp);
        return 1;
    }
    message("info", sprintf("%s is of type %s.", capitalize(str), x), tp);
    tp->add_sp(-5);
    return 1;
}

void help() {
    message("help", "Syntax: <discern [weapon | armour]>\n\n"
      "For fighters, this gives what type of weapon or armour the "
      "item is.  If it is armour, it tells you what it protects.",
      this_player());
}
