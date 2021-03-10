#include <std.h>
#include "keep.h"
inherit VAULT;

int FLAG;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_short("A cozy study");
   set_long(
   "This is a rather cozy little study chamber. A %^ORANGE%^bear skin rug%^RESET%^ is spread"+
   " out in the center of the floor and there is a large desk with a"+
   " comfortable chair on the south side of the room. There is another"+
   " padded chair in the northwest corner that is larger. Two book shelves"+
   " are on the eastern wall, one on either side of the doorway."
   );
   set_smell("default","Dust and mildew tickle your nose.");
   set_listen("default","The silence is complete.");
   set_items(([
   "floor" : "The stone floor is mostly covered by a large bear skin rug.",
   ({"rug","bear skin rug","bear rug"}) : "%^ORANGE%^This is a rug that has been"+
   " made from the hide of a very large brown bear. It is thrown across"+
   " the center of the floor and makes the place feel a bit more cozy.%^RESET%^",
   "ceiling" : "From the ceiling hangs a %^YELLOW%^sphere%^RESET%^ that constantly sheds"+
   " a soft %^YELLOW%^yellow light%^RESET%^ upon the room.",
   "sphere" : "%^YELLOW%^A softly glowing sphere hangs down from a chain"+
   " attached to the ceiling. It is obviously a mage light used to illuminate"+
   " this room, but over the course of the years its power has faded to just"+
   " a dull yellow light instead of the once bright light that it must"+
   " have been capable of.%^RESET%^",
   ({"shelves","book shelves"}) : "There are two book shelves filled with"+
   " some very rotted and mildewed books, one on either side of the doorway.",
   "door" : "A very sturdy door leads back to the rest of the secret basement.",
   "chair" : "There is a slightly padded wooden chair at the desk.",
   ({"large chair","chair 2","padded chair"}) : "In the northwest corner"+
   " is a large padded rocking chair that looks comfortable. You're not"+
   " sure the legs would hold anyone's weight anymore, but at one time"+
   " this must have been a nice place to sit and relax away from the noise"+
   " of the rest of the keep.",
   "desk" : "The large desk on the south side of the room appears to have"+
   " seen much use in its days, but is still in fairly good shape. There"+
   " are a few large drawers and compartments on it for stashing stuff away.",
   ]));
   set_exits(([
   "east" : ROOMS+"basement2",
   ]));
   set_door("door",ROOMS+"basement2","east","keep master_key");
   set_locked("door",1,"lock");
   lock_difficulty("door",20,"lock");
   set_search("desk",(:TO,"search_desk":));
   set_search("drawer",(:TO,"search_desk":));
   set_search("compartment",(:TO,"search_desk":));
}

void reset()
{
   ::reset();
   if(FLAG != 0) FLAG = 0;
}

int search_desk()
{
   object obj, obj2, obj3, obj4;

   if(FLAG == 1) {
      tell_object(TP,"It looks as though someone has already searched through"+
      " the drawers of the desk, there's nothing left.");
      tell_room(ETP,""+TPQCN+" searches through the drawers of the desk but"+
      " finds nothing.",TP);
      return 1;
   }
   tell_object(TP,"You search through the desk drawers and find a small"+
   " pouch and some gold.");
   tell_room(ETP,""+TPQCN+" searches through the desk drawers and appears"+
   " to find something of interest.",TP);
   TP->add_money("silver",random(30)+5);
   TP->add_money("electrum",random(20)+3);
   TP->add_money("gold",random(10)+4);
   obj = new(OBJ2+"pouch");
   obj->move(TO);
   obj2 = new(OBJ2+"gem");
   obj2->move(obj);
   obj3 = new(OBJ2+"gem");
   obj3->move(obj);
   obj4 = new(OBJ2+"gem");
   obj4->move(obj);
   FLAG = 1;
   return 1;
}
