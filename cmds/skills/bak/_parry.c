//      /bin/user/_parry.c
//      from the Nightmare mudlib
//      Fighter ability
//      created by Descartes of Borg
 
#include <std.h>

inherit DAEMON;
 
int cmd_parry() {
    object tp, ob, obj;
    int def1, def2;
 
    tp = this_player();
    if(!sizeof((object *)tp->query_wielded())) {
        notify_fail("You don't have anything to parry with!\n");
        return 0;
    }
    if(tp->query_ghost()) {
        notify_fail("You are dead and cannot do that.\n");
        return 0;
    }
    if(tp->query_disable()) return 1;
    if (environment(tp)->query_property("no attack")) {
        notify_fail("You cannot parry here.\n");
        return 0;
    }
    if((int)tp->query_sp() < 10) {
        notify_fail("You are too exhausted to parry.\n");
        return 0;
    }
    if(!(ob = (object)tp->query_current_attacker())) {
         notify_fail("You are not in battle.\n");
         return 0;
    }
    tp->set_disable();
    def1 = (int)tp->query_skill("defense");
    def2 = random((int)ob->query_skill("attack"));
    if( (string)tp->query_class() == "fighter")
         def1 = def1 + (int)tp->query_stats("dexterity");
    if(def1 >= def2) {
          write("You parry "+(string)ob->query_cap_name()+".\n");
         say(tp->query_cap_name() + " parries " +
              (string)ob->query_cap_name()+".\n");
         tp->add_magic_protection(0, def1-def2, 5);
    }
    else {
        write("You fail to parry "+(string)ob->query_cap_name()+".\n");
         say(tp->query_cap_name()+ " tries to parry, but fails.\n");
         tp->add_sp(-10);
         return 1;
    }
    def1 = (int)tp->query_skill("defense");
    tp->add_skill_points("defense",((def1 + def1)/50 + def1 / 20) * 5 );
    tp->add_sp(-10);
    return 1;
}
 
void help() {
    write("Syntax: <parry>\n\n"
        "Allows you to block the oncoming attack of an enemy.\n"
    );
}
