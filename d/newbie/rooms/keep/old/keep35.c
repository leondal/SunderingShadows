#include <std.h>
#include "keep.h"
inherit VAULT;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("An old armory");
   set_long(
   "You are standing in the old armory of a ruined keep. There are weapons racks of"+
   " spears and halberds that have rotted handles and rusted blades. A sword rack on"+
   " the south side is mostly empty except for a few bent and rusted swords. There"+
   " are crates of bolts and quarrels, all of them worthless now. There are only a"+
   " few pieces of worthless armor scattered around, most of which even need mending"+
   " but wouldn't be worth repairing now."
   );
   set_smell("default","Rust fills this room.");
   set_listen("default","You can hear the wind moaning in the hallway outside.");
   set_items(([
   "racks" : "There is a rack of halberds on the north wall, and a rack of spears"+
   " on the west wall. Neither of them are in good shape.",
   ({"spears","spear rack","rack of spears","west rack","west wall"}) : "There is a"+
   " rack of spears on the west wall. Most of them are in pretty bad shape with"+
   " rotted shafts and rusted tips. Strangely, there is one spear towards the back"+
   " of the rack that appears in good condition somehow.",
   "spear" : "This spear is the one thing in the entire room that doesn't appear"+
   " to have rotted or rusted. It is in the back of the rack and seems to be in good"+
   " shape. Upon closer inspection you realize that the shaft is made of bronzewood,"+
   " which is very strong and tends not to rot. The spear tip is made of rather dull"+
   " stone and would probably be rather useless in battle unless you wanted to try and"+
   " irritate your opponent to death. How odd that a weapon like this is here.",
   ({"halberds","halberd rack","rack of halberds","north rack","north wall"}) : "Against"+
   " the north wall is a rack of halberds. They all have rotted shafts and the blades"+
   " are very rusted, making the weapons completely useless.",
   ({"swords","sword rack","rack of swords","south wall","south rack"}) : "There is a"+
   " swords rack on the south wall. There are only a few swords left, most of them"+
   " are bent and all of them are completely rusted through.",
   ({"crates","bolts","quarrels","arrows"}) : "There are a few crates that are filled"+
   " with now useless bolts, quarrels, and arrows that have rusted and rotted.",
   "armor" : "There are a few pieces of armor scattered about the floor here. It looks"+
   " as though all of the pieces were originally in here for repair anyway, and with"+
   " time having taken its toll they are all worthless.",
   "floor" : "The floor is covered in dust and dirt and a few pieces of armor that"+
   " have been left on the floor to rot.",
   ]));
   set_search("spear","Upon closer inspection of the spear you realize that it is"+
   " fixed into the weapons rack. You also discover that the spear tip itself is"+
   " mobile and that you could probably %^BOLD%^twist%^RESET%^ it.");
   set_search("racks","You search the weapons racks and discover a single spear"+
   " in the west rack that has not rotted or rusted.");
   set_exits(([
   "east" : ROOMS+"keep32",
   ]));
   set_door("door",ROOMS+"keep32","east","keep master_key");
}

void reset()
{
   ::reset();
   set_exits((["east" : ROOMS+"keep32"]));
}

void init()
{
   ::init();
   add_action("twist","twist");
}

void twist(string str)
{
   if(str != "spear" && str != "tip") {
      tell_object(TP,"Twist what?");
      return 1;
   }
   if(member_array("west",ETP->query_exits()) != -1) {
      tell_object(TP,"You twist the spear and watch as the opening in the west wall"+
      " slides shut.");
      tell_room(ETP,""+TPQCN+" does something with one of the spears and the opening"+
      " in the west wall slides shut.",TP);
      remove_exit("west");
      tell_room("/d/newbie/rooms/keep/keep36","The opening in the east wall soundlessly"+
      " slides shut.");
      "/d/newbie/rooms/keep/keep36"->remove_exit("east");
      return 1;
   }
   else {
      tell_object(TP,"You twist the spear tip and watch as a small section of the west"+
      " wall slides open to reveal a secret passage.");
      tell_room(ETP,""+TPQCN+" does something with one of the spears and suddenly a"+
      " section of the west wall slides to the side to reveal a secret passage.",TP);
      add_exit(ROOMS+"keep36","west");
      tell_room("/d/newbie/rooms/keep/keep36","A small section of the east wall"+
      " soundlessly slides open to reveal a passage.");
      "/d/newbie/rooms/keep/keep36"->add_exit(ROOMS+"keep35","east");
      return 1;
   }
}
