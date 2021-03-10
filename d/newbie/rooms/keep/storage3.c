#include <std.h>
#include "../inherit/keep.h"
inherit VAULT;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("An old armory");
   set_short("%^RESET%^%^ORANGE%^An old armory%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^An old armory%^RESET%^\n"
"This appears to be the remains of the armory, lying at the rear of the keep.  "
"%^RED%^Weapon racks %^RESET%^line the walls, set with %^CYAN%^spears "
"%^RESET%^and %^ORANGE%^halberds %^RESET%^that are far too damaged to be of "
"further use.  A rack of %^BLUE%^swords %^RESET%^lies mostly empty, save for a "
"few pieces that are bent beyond repair.  There are %^ORANGE%^crates "
"%^RESET%^of bolts and quarrels, all now as worthless as the broken and rusted "
"%^BOLD%^%^WHITE%^armor %^RESET%^scattered across the floor.\n");
   set_smell("default","The air is dry and stale.");
   set_listen("default","It is fairly quiet here.");
   set_items(([
     ({"racks","weapon racks","weapons"}) : "%^RED%^Many weapon racks stand "
"here, holding weapons in various states of disrepair.  Most hold "
"%^CYAN%^spears %^RED%^and %^ORANGE%^halberds%^RED%^, while another holds a "
"few bent %^BLUE%^swords%^RED%^.  Some of the %^CYAN%^spears %^RED%^look a "
"little out of place, and perhaps merit a closer look.%^RESET%^",
     ({"spears","halberds"}) : "%^CYAN%^Most of the weapon racks hold spears "
"and halberds, with rusted tips and rotted hafts.  A second glance, however, "
"reveals that a few of the spears are actually in surprisingly good nick, which "
"is definitely strange.  Perhaps you should %^YELLOW%^search %^RESET%^%^CYAN%^"
"through them.%^RESET%^",
     "swords" : "%^BLUE%^One rack seems to be for swords, though it is mostly "
"empty.  The only swords still lying upon it are bent beyond repair.%^RESET%^",
     ({"crates","bolts","quarrels"}) : "%^ORANGE%^A few crates reveal a store "
"of bolts and quarrels, but all are rotted and worthless.%^RESET%^",
     "armor" : "%^BOLD%^%^WHITE%^A few rusted and torn pieces of armor, both "
"metal and leather, have been discarded upon the floor.  None seem as if they "
"would be of value.%^RESET%^",
     ({"tip","spear tip"}) : "%^CYAN%^Searching through the spears reveals "
"that a few are in much better shape than the others.  One in particular stands "
"out, with a stone tip rather than metal.  It also appears to be mobile, and "
"you're sure you could %^YELLOW%^twist %^RESET%^%^CYAN%^it.%^RESET%^",
   ]));
   set_search("default","%^ORANGE%^Everything seems fairly worthless here.  "
"Some of the %^YELLOW%^weapon racks%^RESET%^%^ORANGE%^, however, do catch "
"your eye and perhaps merit a closer look.%^RESET%^");
   set_search("racks","%^ORANGE%^Most of the weapons still hanging from the "
"racks seem to be beyond repair.  Oddly, a second glance reveals that a few of "
"the %^CYAN%^spears %^ORANGE%^seem in surprisingly good shape.%^RESET%^");
   set_search("weapon racks","%^ORANGE%^Most of the weapons still hanging from "
"the racks seem to be beyond repair.  Oddly, a second glance reveals that a few "
"of the %^CYAN%^spears %^ORANGE%^seem in surprisingly good shape.%^RESET%^");
   set_search("spears","%^CYAN%^Searching through the spears reveals that a few "
"are in much better shape than the others.  One in particular stands out, with "
"a stone tip rather than metal.  It also appears to be mobile, and you're sure "
"you could %^YELLOW%^twist %^RESET%^%^CYAN%^it.%^RESET%^");
   set_exits(([
     "east" : ROOMS"keep19",
   ]));
   set_door("door",ROOMS"keep19","east",0);
   set_door_description("door","%^ORANGE%^A simple wooden door, scratched and "
"grimy from years of abuse, but still intact.  Its hinges are rusted and "
"probably very stiff.%^RESET%^");
   set_string("door","open","The door sheds dust as it creaks open.");
   set_string("door","close","The door creaks shut.");
}

void init() {
   ::init();
   add_action("twist_fun","twist");
}

int twist_fun(string str) {
   if(!str) return notify_fail("Twist what?\n");
   if(str != "tip" && str != "spear" && str != "spear tip")
     return notify_fail("You can't twist that.\n");
   if(member_array("west",TO->query_exits()) != -1) {
     tell_object(TP,"%^ORANGE%^You twist the spear tip, and the opening in the "
"west wall slides shut.%^RESET%^");
     tell_room(TO,"%^ORANGE%^"+TPQCN+" pokes around with one of the spear "
"racks, and the opening in the west wall slides shut.%^RESET%^",TP);
     remove_exit("west");
     if(member_array("east",ROOMS"hidden3"->query_exits()) != -1) {
       tell_room(ROOMS"hidden3","%^ORANGE%^The opening in the east wall slides "
"soundlessly shut.%^RESET%^");
       ROOMS"hidden3"->remove_exit("east");
     }
   return 1;
   }
   tell_object(TP,"%^ORANGE%^You twist the spear tip, and suddenly a section of "
"the west wall slides open, revealing a secret passage.%^RESET%^");
   tell_room(TO,"%^ORANGE%^"+TPQCN+" pokes around with one of the spear "
"racks, and suddely a section of the west wall slides open, revealing a secret "
"passage.%^RESET%^",TP);
   add_exit(ROOMS"hidden3","west");
   if(member_array("east",ROOMS"hidden3"->query_exits()) == -1) {
     tell_room(ROOMS"hidden3","%^ORANGE%^A small section of the east wall "
"slides open, revealing an abandoned armory room beyond.%^RESET%^");
     ROOMS"hidden3"->add_exit(ROOMS"storage3","east");
   }
   return 1;
}

void reset() {
   ::reset();
   if(member_array("west",TO->query_exits()) != -1) {
     tell_room(TO,"%^ORANGE%^The opening in the west wall slides soundlessly "
"shut.%^RESET%^");
     remove_exit("west");
     if(member_array("east",ROOMS"hidden3"->query_exits()) != -1) {
       tell_room(ROOMS"hidden3","%^ORANGE%^The opening in the east wall slides "
"soundlessly shut.%^RESET%^");
       ROOMS"hidden3"->remove_exit("east");
     }
   }
}
