//calm_light.c - inherit for bard rewards in Nereid's Riddle Quest.  Circe 12/10/03
#include <std.h>
#include <daemons.h>

inherit OBJECT;

int OWNED;
string owner;

void create(){
    ::create();
    set_name("instrument");
}

void init(){
    ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
        }
    add_action("play","play");
}

int play(string str) {
    if((string)TPQN != owner) {
       tell_object(TP,"This is not your instrument!");
       return 1;
    }
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
    tell_room(ETP, ""+TPQCN+" plays a gentle melody.",TP);
    new("/cmds/spells/l/_light")->use_spell(TP,TP,10,100,"cantrip");
    TP->set_paralyzed(1,"You are busy creating a light.");
    return 1;
}

int is_instrument(){return 1;}
string query_prof_type() { return "instrument"; }
