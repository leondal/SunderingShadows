#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
   set_name("East docks");
   set_short("East docks");
   set_long("%^BOLD%^East docks%^RESET%^\n"
"East of the main dock, it is regularly active here with pirates and dockworkers.  Beneath your feet, "
"%^ORANGE%^wooden slats%^RESET%^ form the boardwalk that is held above the water by sturdy wooden stilts.  "
"Along the edges of the dock are stacked numerous boxes and crates, though you have no idea what might be "
"held within them.  You can see the %^ORANGE%^wooden boarding %^RESET%^continue westward, where it meets "
"with several docked boats, and a dirt path heading away from the water.  To the south stretch the %^BLUE%^"
"%^BOLD%^undulating waves%^RESET%^ of the ocean as far as you can see, often passed over by boats of varying "
"description.\n");
   set("night long","%^BOLD%^East docks%^RESET%^\n"
"East of the main dock, it is mostly deserted here in the %^BLACK%^%^BOLD%^darkness%^RESET%^ of night.  "
"Beneath your feet, %^ORANGE%^wooden slats%^RESET%^ form the boardwalk that is held above the water by "
"sturdy wooden stilts.  Along the edges of the dock are stacked numerous boxes and crates, though you have "
"no idea what might be held within them.  You can see the %^ORANGE%^wooden boarding%^RESET%^ continue "
"westward, where it meets with several docked boats, and a dirt path heading away from the water.  To the "
"south stretches the %^BLUE%^dark expanse%^RESET%^ of the ocean as far as you can see.\n");
   set_smell("default","The salty smell of the ocean fills the air.");
   set_listen("default","Water sloshes up against the wooden stilts, split by the sounds of seabirds.");

   set_items(([
     ({"ships","boats"}):"Occasionally a boat sails across the water, as it enters or leaves the docks.",
     ({"water","ocean","sea","waves"}):"The ocean's waves lap quietly against the stilts of the boardwalk, "
"the %^BLUE%^watery surface%^RESET%^ stretching as far as the eye can see to the south.",
     ({"boardwalk","boarding","stilts","slats","dock","docks"}) : "Parallel %^ORANGE%^wooden slats%^RESET%^ "
"form the boardwalk beneath your feet, which is supported by thick stilts that disappear under the water's "
"surface.",
     ({"crates","boxes","cargo"}):"Numerous stacked boxes and crates line the edge of the dock here, often "
"being replaced or carried away by some dockworker."
    ]));

   set_exits(([
     "east":COVE"dock7",
     "west":COVE"dock5",
//     "dive":OCEAN"1-6"
   ]));
//   set_pre_exit_functions(({"dive",}),({"splash_fun",}));
//   set_invis_exits(({"dive"}));
}

int splash_fun(){
   if(TP->query_true_invis()) return 1;
   tell_object(TP,"You dive into the water with a %^BLUE%^%^BOLD%^sp%^CYAN%^l%^BLUE%^a%^WHITE%^s%^CYAN%^h%^RESET%^!");
   if(TP->query_invis()) tell_room(TO,"A %^BLUE%^%^BOLD%^sp%^CYAN%^l%^BLUE%^a%^WHITE%^s%^CYAN%^h%^RESET%^ "
"breaks the ocean's surface, as though someone or something had just dropped into the water.",TP);
   else tell_room(TO,"A %^BLUE%^%^BOLD%^sp%^CYAN%^l%^BLUE%^a%^WHITE%^s%^CYAN%^h%^RESET%^ breaks the ocean's "
"surface as "+TP->QCN+" jumps in!",TP);
   return 1;
}
