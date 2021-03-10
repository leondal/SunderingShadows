#include <std.h>
#include "../inherit/keep.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("A hidden passage");
   set_short("%^ORANGE%^A hidden passage%^RESET%^");
   set_long("%^ORANGE%^A hidden passage%^RESET%^\n"
"You are standing in a hidden passageway that continues along to the west, "
"although you can't see very far in the dim light.  The corridor seems to "
"have survived the ravages of time fairly well, as the %^BLUE%^walls "
"%^RESET%^are still intact.  It is, however, very %^ORANGE%^dusty %^RESET%^"
"and probably hasn't been used in some time.  There is a %^YELLOW%^lever "
"%^RESET%^on the eastern wall.\n");
   set_smell("default","Age-old dust tickles your nose.");
   set_listen("default","Everything is fairly quiet.");
   set_items(([
     "lever" : "%^ORANGE%^There is a lever on the wall here.  Nothing "
"directly indicates its purpose, but you can see the outline of a doorway "
"in the northern wall.  Since there is no handle or other way to open the "
"doorway, it seems the only way to open it is to %^YELLOW%^pull lever"
"%^RESET%^%^ORANGE%^.%^RESET%^",
     "walls" : "%^BLUE%^The walls are coated with a layer of age-old grime "
"and dust, but aside from this they seem to have withstood the passage of "
"time fairly well.  They certainly have not crumbled, the way some walls "
"outside have done.  Upon the eastern wall is a %^YELLOW%^lever%^RESET%^"
"%^BLUE%^.%^RESET%^",
   ]));
   set_exits(([
     "west" : ROOMS"floor7",
   ]));
}

void init() {
   ::init();
   add_action("pull","pull");
}

void reset() {
   ::reset();
   if(member_array("north",TO->query_exits()) != -1) {
     tell_room(TO,"%^ORANGE%^A section of the wall slides across to close "
"the northern passage.%^RESET%^");
     remove_exit("north");
     if(member_array("south",ROOMS"floor5"->query_exits()) != -1) {
       tell_room(ROOMS"floor5","%^ORANGE%^The southern bookshelf slides "
"back into place, closing the secret passage.%^RESET%^");
       ROOMS"floor5"->remove_exit("south");
     }
   }
}

int pull(string str) {
   if(str != "lever") return notify_fail("Pull what?\n");
   if(member_array("north",ETP->query_exits()) != -1) {
     tell_object(TP,"%^ORANGE%^You pull the lever and watch as a section of "
"the wall slides across to close the northern passage.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" pulls the lever and you see a "
"section of the wall slide across to close the northern passage"
".%^RESET%^",TP);
     remove_exit("north");
     ROOMS"floor5"->remove_exit("south");
     tell_room(ROOMS"floor5","%^ORANGE%^The southern bookshelf slides back "
"into place, closing the secret passage.%^RESET%^");
     return 1;
   }
   else {
     tell_object(TP,"%^ORANGE%^You pull the lever and hear a grinding noise "
"as the wall slides open to reveal a doorway on the north.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" pulls a lever and you hear a "
"grinding noise as the wall slides open to reveal a doorway on the "
"north.%^RESET%^",TP);
     add_exit(ROOMS"floor5","north");
     ROOMS"floor5"->add_exit(ROOMS"floor6","south");
     tell_room(ROOMS"floor5","%^ORANGE%^The southern bookshelf slides to "
"the side, revealing a passage to the south.%^RESET%^");
     return 1;
   }
}
