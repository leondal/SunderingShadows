#include <std.h>
inherit CVAULT;

string diety;
void trigger_ward();

void create() {
   ::create();
}

void set_temple(string str) {
    diety = str;
    set_property("blessed",({diety}));
}

string query_diety() {
    return diety;
}

int is_temple() { return 1; }

void init() {
   ::init();
   if(!present("templewardxxx",TP)) new("/d/magic/obj/templeward")->move(TP);
}

void trigger_ward() {
   object *combatants, destroom;
   int i, flag;
   combatants = all_living(TO);
   for(i = 0;i< sizeof(combatants); i++) {
     if(sizeof(combatants[i]->query_attackers()) || present("templewardxxx",combatants[i])->is_combatant()) {
       if(!flag) {
         destroom = new("/d/magic/room/templeward");
         flag = 1;
       }
       tell_object(combatants[i],"%^BOLD%^%^CYAN%^A s%^WHITE%^p%^CYAN%^ar"
"%^BLUE%^k%^CYAN%^ling orb of azure energy springs into being around you, and "
"the temple disappears from view!%^RESET%^");
       combatants[i]->move(destroom);
     }
   }
   if(flag) tell_room(TO,"%^BOLD%^%^CYAN%^A s%^WHITE%^p%^CYAN%^ar%^BLUE%^k"
"%^CYAN%^ling orb of azure energy springs into being around the combatants, and "
"they disappear from view!%^RESET%^");
}
