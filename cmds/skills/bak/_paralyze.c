//      /bin/user/_paralyze.c
//      from the Nightmare mudlib
//      paralyzes an opponent
//      created by Descartes of Borg 18 april 1993
//      slightly modified by Bohemund 31 december 1993
//      to check for property "no paralyze" in target


#include <std.h>

inherit DAEMON;

int cmd_paralyze(string str) {
    object ob;
    int healing, mag, dam;

    if(environment(this_player())->query_property("no magic")) {
        notify_fail("A magic force prevents you from doing that.\n");
        return 0;
    }
    if(!str) ob = (object)this_player()->query_current_attacker();
    else ob = present(lower_case(str), environment(this_player()));
    if(!ob && str) ob = parse_objects(environment(this_player()), lower_case(str));
    if(!ob) {
        notify_fail("Paralyze whom?\n");
        return 0;
    }
    if(!living(ob)) {
        notify_fail("Ok, the "+str+" is paralyzed.\n");
        return 0;
    }
    if(this_player()->query_ghost()) {
        notify_fail("You howl instead of pray.\n");
        return 0;
    }
    if(this_player()->query_casting()) {
        notify_fail("Your words are becoming jumbled.\n");
        return 0;
    }
    if(ob->query_property("no paralyze")) {
        notify_fail("That creature is immune to such magic!\n");
	return 0;
    }
    if(ob->query_paralyzed()) {
        notify_fail("Paralyze the paralyzed?\n");
        return 0;
    }
    if( (healing = (int)this_player()->query_skill("healing")) < 40 ) {
        notify_fail("You do not have the knowledge for that.\n");
        return 0;
    }
    mag = (int)this_player()->query_skill("magic attack");
    if(!alignment_ok(this_player())) {
        notify_fail("You have betrayed the source of your powers.\n");
        return 0;
    }
    dam = (healing/8) * ((mag+20)/10);
    if((int)this_player()->query_mp() < dam+10) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    this_player()->add_mp(-(dam+15));
    ob->set_paralyzed(dam/3+1);
    this_player()->set_magic_round();
    this_player()->add_skill_points("healing", dam);
    write("You mutter a prayer of paralyzation.\n");
    say(this_player()->query_cap_name()+" prays for the paralyzation of "+ob->query_cap_name()+".\n", ob);
    tell_object(ob, this_player()->query_cap_name()+" paralyzes you!\n");
    return 1;
}

void help() {
    write("Syntax: <paralyze [enemy]>\n\n"
        "Paralyzes a player or monster for a short period of time,\n"
      "making it impossible for it to move, fight, or otherwise\n"
      "issue commands.\n"
    );
}
