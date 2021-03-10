#include <std.h>
#include <daemons.h>
// changing to inherit /d/common street lights for consistency/bug prevention *Styx* 12/23/03, last change 8/24/01
// inherit OBJECT;

inherit "/d/common/obj/misc/street_light.c";

void create() {
    ::create();
    set_id(({"lantern pole","pole","light"}));
    set_name("lantern pole");
    set_short("A dark lantern pole");
    set_dayShort("A dark lantern pole");
    set_nightShort("%^BOLD%^%^WHITE%^A lit lantern pole%^RESET%^");
    set_weight(100000);
    set_long("This lantern pole is 10 feet tall.  It is made of finely sculptured metal and "
          "has a metal lantern hanging from the top.  The metalwork is Dwarven.");
    set_value(0);
    set_property("no animate", 1);
}

/*
void init(){
    string tod;
   if(!interactive(TP)) return;
        tod = EVENTS_D->query_time_of_day();
   if((tod == "night") && !query_property("light")){ 
      set_property("light",3);
      set_short("A lit lantern pole");
   }
   if((tod != "night") && query_property("light")){
      remove_property("light");
      set_short("A dark lantern pole");
     }
}
*/