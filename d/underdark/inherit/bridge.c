#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   if(!random(4)) set_property("no teleport",1);
   set_terrain(NAT_CAVE);
   set_travel(PAVED_ROAD);
   set_name("A bridge crossing the Wailing Chasm");
   set_short("%^MAGENTA%^A bridge crossing the Wailing Chasm%^RESET%^");
   set_long("%^BLUE%^This narrow stone bridge crosses the breadth of a chasm of %^RED%^massive proportions"
"%^BLUE%^.  Above and below, no ceiling or floor of the chasm is revealed in the complete %^BOLD%^%^BLACK%^"
"darkness%^RESET%^%^BLUE%^, nor can you see the far side of this great sunder through the earth.  The bridge "
"itself is of the same %^WHITE%^bleak stone %^BLUE%^as the wall behind you, running in a tenuous span over the "
"empty air below.  You have no idea how far up the chasm you must be, only that it is a very long way down..."
"%^RESET%^");
   set_smell("default","Dry winds buffet you from all directions, making it difficult to balance.");
   set_listen("default","A low wail constantly surrounds you as the winds rush by.");
   set_items(([
     ({"chasm","sunder"}):"%^BLUE%^This massive chasm stretches away past your vision to the northwest and "
"southeast, up and down, a great cleft through the earth.%^RESET%^",
     ({"ceiling","roof","floor"}):"%^BLUE%^There's no way to see the ceiling or floor of the chasm from here, "
"as they're far too distant, lost in the %^BOLD%^%^BLACK%^shadows %^RESET%^%^BLUE%^above and below you."
"%^RESET%^",
     ({"bridge","span"}):"%^BLUE%^This narrow bridge of %^WHITE%^stone%^BLUE%^ runs in a tenuous span across "
"the massive chasm.  It is wide enough only for one person, making it near impossible to remain mounted here, "
"and immensely difficult to pass anyone coming in the opposite direction.%^RESET%^",
   ]));
}

int GoThroughDoor() {
   if (TP->query_in_vehicle()) {
     if ((member_array("spider",TP->query_in_vehicle()->query_id()) == -1) && (member_array("lizard",TP->query_in_vehicle()->query_id()) == -1)) {
       tell_object(TP,"%^BLUE%^You realise you probably can't ride your "+TP->query_in_vehicle()->QCN+
"%^RESET%^%^BLUE%^ along such a narrow bridge.%^RESET%^");
       tell_room(TO,"%^BLUE%^The bridge seems too narrow for "+TP->QCN+" to ride "+TP->QP+" "
+TP->query_in_vehicle()->query_name()+"%^RESET%^%^BLUE%^ along.%^RESET%^",TP);
       return 0;
     }
     tell_object(TP,"%^BLUE%^Your "+TP->query_in_vehicle()->query_name()+"%^RESET%^%^BLUE%^ easily picks its "
"way along the narrow bridge.%^RESET%^");
     tell_object(TO,"%^BLUE%^"+TP->QCN+"'s "+TP->query_in_vehicle()->query_name()+"%^RESET%^%^BLUE%^ easily "
"picks its way along the narrow bridge.%^RESET%^");
   }
   return 1;
}
