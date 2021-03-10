#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

int boat;
object boatroom;

void create(){ 
   set_monsters(({MON"pirateguard.c",MON"pirateguard2.c",MON"pirateguard3.c"}),({1,2,1}));
   ::create();
   set_repop(50);
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
   set_name("East docks");
   set_short("East docks");
   set_long("%^BOLD%^East docks%^RESET%^\n"
"This is the far eastern end of the docks, but even this far from the main path it is regularly active with "
"pirates and dockworkers  Beneath your feet, %^ORANGE%^wooden slats%^RESET%^ form the boardwalk that is held "
"above the water by sturdy wooden stilts.  Along the edges of the dock are stacked numerous boxes and "
"crates, though you have no idea what might be held within them.  You can see the %^ORANGE%^wooden boarding "
"%^RESET%^continue westward, where it meets with several docked boats, and a dirt path heading away from the "
"water.  To the south stretch the %^BLUE%^%^BOLD%^undulating waves%^RESET%^ of the ocean as far as you can "
"see, often passed over by boats of varying description.  A smaller section of boardwalk extends out into "
"the ocean here, where a large pirate ship is docked.\n");
   set("night long","%^BOLD%^East docks%^RESET%^\n"
"This is the far western end of the docks, mostly deserted in the %^BLACK%^%^BOLD%^darkness%^RESET%^ of "
"night.  Beneath your feet, %^ORANGE%^wooden slats%^RESET%^ form the boardwalk that is held above the water "
"by sturdy wooden stilts.  Along the edges of the dock are stacked numerous boxes and crates, though you "
"have no idea what might be held within them.  You can see the %^ORANGE%^wooden boarding%^RESET%^ continue "
"westward, where it meets with several docked boats, and a dirt path heading away from the water.  To the "
"south stretches the %^BLUE%^dark expanse%^RESET%^ of the ocean as far as you can see.  A smaller section of "
"boardwalk extends out into the ocean here, where a large pirate ship is docked.\n");
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
"being replaced or carried away by some dockworker.",
     ({"ship","pirate ship"}):"A great ship is docked here, bearing a pirate flag and many buccaneers."
   ]));

   set_exits(([
     "west":COVE"dock6",
     "ship":COVE"boatb02",
//     "dive":OCEAN"1-7"
   ]));
   set_pre_exit_functions(({"ship"}),({"GoThroughDoor"}));
//   set_pre_exit_functions(({"dive","ship"}),({"splash_fun","GoThroughDoor"}));
//   set_invis_exits(({"dive"}));
   boatroom = find_object_or_load(COVE"boatb02");
   boat = 1;
}

int GoThroughDoor(){
   if(TP->query_true_invis()) return 1;
   if(!present("pirate")) return 1;
   tell_object(TP,"There's no way to board the boat, there's too many pirates in your way.");
   return 0;
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

/* void reset() {
   int i;
   ::reset();
   if(boatroom) {
     if(boat) {
       if(!random(3)) {
         remove_exit("ship");
         tell_room(TO,"The pirate ship at the dock raises anchor, and sails out onto the clear blue yonder!");
         remove_item("ship");
         remove_item("pirate ship");
         boatroom->remove_exit("dock");
         boat = 0;
         for (i=1;i<10;i++) {
           boatroom = find_object_or_load(COVE+"boatb0"+i);
           tell_room(boatroom,"%^RED%^%^BOLD%^The ship raises anchor, and sails out from the dock!");
         }
         boatroom = find_object_or_load(COVE+"boatb10");
         tell_room(boatroom,"%^RED%^%^BOLD%^The ship raises anchor, and sails out from the dock!");
         boatroom = find_object_or_load(COVE+"boatb11");
         tell_room(boatroom,"%^RED%^%^BOLD%^The ship raises anchor, and sails out from the dock!");
         boatroom = find_object_or_load(COVE"boatb02");
       }
     }
     else {
       tell_room(TO,"A great pirate ship sails up to the dock, and lowers its gangplank!");
       add_exit(COVE"boatb02","ship");
       add_item(({"ship","pirate ship"}),"A great ship is docked here, bearing a pirate flag and many "
"buccaneers");
       boatroom->add_exit(COVE"dock7","dock");
       boat = 1;
       for (i=1;i<10;i++) {
         boatroom = find_object_or_load(COVE+"boatb0"+i);
         tell_room(boatroom,"%^RED%^%^BOLD%^The ship sails into a cove and drops anchor, lowering its "
"gangplank!");
       }
       boatroom = find_object_or_load(COVE+"boatb10");
       tell_room(boatroom,"%^RED%^%^BOLD%^The ship sails into a cove and drops anchor, lowering its "
"gangplank!");
       boatroom = find_object_or_load(COVE+"boatb11");
       tell_room(boatroom,"%^RED%^%^BOLD%^The ship sails into a cove and drops anchor, lowering its "
"gangplank!");
       boatroom = find_object_or_load(COVE"boata02");
     }
   }
} */
