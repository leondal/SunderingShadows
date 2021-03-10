//_scry.c
//Mage ability
//created by Descartes 19 Nov 1992

#include <std.h>

inherit DAEMON;

int cmd_scry(string str) {
    object ob;
    int cost, con, wis;
    int i;
    object *inv;
    string desc;

    if(!str) {
notify_fail("Scry whom?\n");
return 0;
    }
    if(environment(this_player())->query_property("no magic")) {
        notify_fail("A magic force prevents you from using your magic.\n");
        return 0;
    }
    ob = find_living(str);
    if(!ob) {
notify_fail("You see only mist in your mind's eye.\n");
return 0;
    }
    if(environment(ob)->query_property("no scry"))
        return notify_fail("You see only mist in your mind's eye.\n");
    if(wizardp(ob)) {
	notify_fail("You fail.\n");
	return 0;
    }
    cost = random(15)+ 10;
    if((int)this_player()->query_mp() < cost) {
notify_fail("Too low on magic power.\n");
return 0;
    }
    this_player()->add_mp(-cost);
    con = (int)this_player()->query_skill("conjuring");
    wis = (int)ob->query_stats("wisdom");
    con -= wis;
    if(con < random(101)) {
      write("You see only mist in your mind's eye.");
      this_player()->add_skill_points("conjuring", 5);
      return 1;
    }
    write("Through the mists of other dimensions you see:\n");
    ob = environment(ob);
    if(!ob) write("An empty void.");
    else {
        desc = (string)ob->query_long()+"\n";
        inv = all_inventory(ob);
        for(i=0; i<sizeof(inv); i++) {
            if(inv[i]->query_invis()) continue;
            desc += (string)inv[i]->query_short()+"\n";
        }
        write(desc);
    }
    this_player()->add_skill_points("conjuring", cost);
    return 1;
}

void help() {
    write("Syntax: <scry [living]>\n\n"+
"Helps you locate the living being you seek.\n");
}
