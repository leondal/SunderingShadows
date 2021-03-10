//Octothorpe (7/23/09)
//Attaya Torches
//Based on /d/common/obj/misc/street_light.c

#include <std.h>
#include <daemons.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("bamboo torches");
   set_id(({"torhces","torch","bamboo","bamboo torches","bamboo torch"}));
   set_weight(1000000);
   set_short("%^RESET%^%^ORANGE%^l%^RED%^i%^ORANGE%^t bamboo torch"+
      "%^BOLD%^%^MAGENTA%^");
   set_long("%^ORANGE%^These perpetually burning torches are found at "+
      "ten foot intervals along both sides of the path.  The torches "+
	  "are nothing more than five foot tall bamboo shoots driven into "+
	  "the soil.  The gentle %^BOLD%^fl%^RED%^a%^RESET%^%^ORANGE%^me "+
	  "appears to do no damage to the bamboo itself, and suggests "+
	  "ignition through magical means.%^RESET%^");
   set_value(0);
   set_property("no animate",1);
   set_property("magic",1);
}

void init(){
   string tod;
   ::init();
   if(!interactive(TP)) return;
   tod = EVENTS_D->query_time_of_day();
   if((tod == "night") && !query_property("light")){ 
      set_property("light",3);
   }
   if((tod != "night") && query_property("light")){
      remove_property("light");
   }
}