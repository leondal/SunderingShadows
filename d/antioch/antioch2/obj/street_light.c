// changing to inherit the /d/common/obj version *Styx* 12/24/03, last change 8/24/01

#include <std.h>
#include <daemons.h>
#include "../antioch.h"
//inherit OBJECT;

inherit "/d/common/obj/misc/street_light.c";

void create() {
	::create();
   set_property("no animate",1);
	set_long(
	"This street light has been made from wrought iron and magically enchanted"+
	" to have a %^BOLD%^silver%^RESET%^ color.  It has some sort of magical"+
	" stone set into it that will light up the streets at night with a warm"+
	" %^YELLOW%^yellow%^RESET%^ light."
	);
/* all should be handled by the inherit
   set_id(({"street light","street_light","light"}));
   set_name("street light");
   set_short("A dark street light");
   set_weight(10000);
   set_value(0);
*/
}

/*
void init()
{
   string tod;
   if(!interactive(TP)) return;
   tod = EVENTS_D->query_time_of_day();
   if((tod == "night") && !query_property("light")) {
      set_property("light",3);
      set_short("A lit street light");
   }
   if((tod != "night") && query_property("light")) {
      remove_property("light");
      set_short("A dark street light");
   }
}
*/
