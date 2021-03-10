//	/bin/user/_brand.c
//	from the Nightmare mudlib
//	a mage spell for calling monsters
//	created by Descartes of Borg

#include <std.h>

inherit DAEMON;

int cmd_brand(string str) {
    object ob, brand;
    int con, wis;

    if(!str) {
	notify_fail("Brand what?\n");
	return 0;
    }
    if(this_player()->query_ghost()) return 0;
    ob = present(lower_case(str), environment(this_player()));
    if(!ob) {
        notify_fail(capitalize(str)+" is not here.\n");
	return 0;
    }
    if(!living(ob)) {
	notify_fail("You cannot brand that!\n");
	return 0;
    }
    if(environment(this_player())->query_property("no magic")) {
	notify_fail("Something prevents you from using your powers.\n");
	return 0;
    }
    if(present("monster brand", ob)) {
	notify_fail(capitalize(str) + " has already been branded.\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 20) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    con = (int)this_player()->query_skill("conjuring");
    if(con < 10) {
	notify_fail("You flail about like an idiot.\n");
	return 0;
    }
    this_player()->add_mp(-20);
    wis = (int)ob->query_stats("wisdom");
    con -= wis;
    if(random(101) > con) {
        write("You fail.");
	return 1;
    }
    brand = new("/std/obj/brand");
    brand->init_brand((string)this_player()->query_cap_name(), (con * 4));
    brand->move(ob);
    write("You brand your victim.");
    say(this_player()->query_cap_name()+" magically brands "+ob->query_cap_name()+" for combat.", ob);
    tell_object(ob, this_player()->query_cap_name()+" magically brands you for combat.");
    this_player()->add_skill_points("conjuring", random(5));
    return 1;
}

void help() {
    write("Syntax: <brand [victim]>\n\n");
    write("Allows you to mark for a period of time a monster or player for combat.\n");
    write("See also: keep, hold\n");
}
