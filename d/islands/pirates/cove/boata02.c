#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   set_monsters(({MON"piratecrew",MON"piratecrew2"}),({1,1}));
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Main deck");
   set_short("Main deck");
   set_long("%^BOLD%^Main deck%^RESET%^\n"
"This is the central deck of the pirate boat.  %^ORANGE%^Wooden stairs %^RESET%^lead up toward the "
"forecastle and aftercastle of the ship, which are both elevated too far for you to see clearly.  The two "
"masts rise up from each end of the deck, holding aloft the great canvas sails that propel the ship.  "
"Beneath your feet, the %^ORANGE%^wooden boards %^RESET%^are probably long overdue for a polish.  A "
"%^ORANGE%^low rail %^RESET%^runs along either side of the boat, and a few cartons and crates are sitting "
"around the deck.  Upon the far side of the deck, a gangplank has been secured for when the ship is docked.  "
"A trapdoor outlined in heavy metal is set within the deck itself, and a corridor leads beneath the "
"forecastle to what look like several closed-in rooms.\n");
   set_smell("default","You smell fresh ocean air minced with the smell of charred wood.");
   set_listen("default","You hear the boards of the ship creak in an unsettling way.");
   set_items(([
     ({"deck","boards","wooden boards"}):"The wooden boards beneath your feet form the central deck of this "
"ship.  They look rather old, and are in need of a good polish.",
     ({"masts","sails","canvas sails"}):"The two masts rise above you, holding aloft the great canvas sails "
"to propel the ship while it crosses the ocean.",
     "rail":"A low rail runs along both sides of the deck, though it's probably a bit too low to stop anyone "
"going overboard in a storm.",
     ({"crates","cartons"}):"A few crates and cartons are laid out across the deck.",
     "trapdoor":"A trapdoor is set within the deck, outlined in heavy metal.  If you're strong enough you "
"could probably try to lift it."
   ]));
   set_exits(([
     "dock":COVE"dock2",
     "aftercastle":COVE"boata01",
     "forecastle":COVE"boata03",
     "corridor":COVE"boata05"
   ]));
   find_object_or_load(COVE"dock2");
}

void reset(){
   object otherroom;
   ::reset();
   if(member_array("down",TO->query_exits()) != -1) {
     remove_exit("down");
     tell_room(TO,"Someone slams the trapdoor shut from below!");
     otherroom = find_object_or_load(COVE"boata04");
     if(member_array("up",otherroom->query_exits()) != -1) {
       tell_room(otherroom,"Someone slams the trapdoor shut from above!");
       otherroom->remove_exit("up");
     }
   }
}

void init(){
   ::init();
   add_action("liftem","lift");
}

int liftem(string str){
   object otherroom,*pirates;
   int i;
   if(!str) return notify_fail("Lift what?\n");
   if(str != "trapdoor") return notify_fail("What are you trying to lift?\n");
   if(member_array("down",TO->query_exits()) != -1) return notify_fail("It's already been lifted.\n");
   if(sizeof(TP->query_attackers()) > 0) return notify_fail("You can't do that while you're in a fight!\n");
   pirates = all_living(TO);
   if(present("pirate",TO) && !TP->query_true_invis()) {
     tell_room(TO,"The pirates turn at the sound of someone at the trapdoor, and attack with a yell!");
     TP->set_invis(0);
     for (i = 0;i< sizeof(pirates);i++) {
       if((string)pirates[i]->query_name() == "Pirate crewman") {
         pirates[i]->force_me("kill "+TPQN);
       }
     }
     return 1;
   }
   if((roll_dice(1,20)) > (TP->query_stats("strength")))
     return notify_fail("You heave mightily but you can't seem to lift the heavy trapdoor.\n");
   tell_object(TP,"You lift the heavy trapdoor, revealing a creaking stairway down.");
   tell_room(ETP,""+TPQCN+" lifts the heavy trapdoor, revealing a creaking stairway down.",TP);
   add_exit(COVE"boata04","down");
   otherroom = find_object_or_load(COVE"boata04");
   tell_room(otherroom,"Someone lifts the heavy trapdoor from above!");
   otherroom->add_exit(COVE"boata02","up");
   return 1;
}
