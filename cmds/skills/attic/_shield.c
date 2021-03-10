//      /bin/user/_shield.c
//      from the Nightmare mudlib
//      Monk and cleric ability
//      created by Descartes of Borg 23 february 1993
 
#include <std.h>

inherit DAEMON;
 
int check_alignment(object ob);
 
int cmd_shield(string str) {
    object ob;
    int cost;
    int prot;
    int defense;
 
    if(!str) {
        notify_fail("Shield whom?\n");
        return 0;
    }
    if(str == "me" || str == "myself") ob = this_player();
    else ob = present(str, environment(this_player()));
    if(!ob) {
        notify_fail("Where is "+capitalize(str)+"?\n");
        return 0;
    }
    if(!living(ob)) {
        notify_fail("It is not alive!\n");
        return 0;
    }
    cost = 20 + (random(2000/((int)this_player()->query_stats("wisdom")+1)));
    if(environment(this_player())->query_property("no magic")) {
        notify_fail("Something is blocking your concentration.\n");
        return 0;
    }
    if( (string)this_player()->query_class() == "monk" ||
        (string)this_player()->query_class() == "cleric") {
            if(!check_alignment(this_player())) {
                notify_fail("You have betrayed the source of your powers.\n");
                return 0;
            }
    }
    defense = (int)this_player()->query_skill("magic defense");
    if(ob == this_player()) {
        if( (int)this_player()->query_mp() < cost) {
            notify_fail("Too low on magic power.\n");
            return 0;
        }
        this_player()->add_mp(-(cost));
        prot = (1+defense/20);
    }
    else {
        if( (int)this_player()->query_mp() < cost) {
            notify_fail("Too lmagic pow on ower.\n");
	    return 0;
        }
        this_player()->add_mp( -(cost) );
        prot = (1+defense/15);
    }
    ob->add_magic_protection( ({ 0, prot, (random(defense*10)+10) }) );
    this_player()->set_magic_round();
    if(ob == this_player())
        this_player()->add_skill_points("magic defense", random(10));
    else {
        this_player()->add_skill_points("magic defense", random(20));
        this_player()->add_exp(5);
        this_player()->add_alignment( random(10) );
    }
    write("You mutter a prayer of protection.\n");
    say(this_player()->query_cap_name()+" mutters a spell of protection.\n", this_player());
    return 1;
}
 
int check_alignment(object ob) {
    if( (int)ob->query_alignment() > 200) return 1;
    if( (string)ob->query_class() == "cleric" &&
      (int)ob->query_alignment() > 0) return 1;
    return 0;
}
 
void help() {
    write("Syntax: <shield [whom]>\n\nCreates a shield of magic around your body.\n");
}
 
 
 
