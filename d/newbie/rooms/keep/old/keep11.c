#include <std.h>
#include "keep.h"
inherit VAULT;

int FOUND;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("A storage room");
   set_long(
   "You are standing in what appears to be an old storage room. There are many shelves"+
   " along the walls holding various items, most of which are fairly useless and all"+
   " of them are covered in dust. A few of the shelves have rotted through in the"+
   " center and dumped their contents onto the floor. There are a few boxes, crates"+
   " and barrels as well, though you can't imagine finding anything useful in any of"+
   " them."
   );
   set_smell("default","The dust and mildew are almost overpowering.");
   set_listen("default","You hear the scrabbling of tiny claws on stone.");
   set_items(([
   ({"door","rotted door"}) : "The rotted door on the east leads back out to the"+
   " main hallway of the keep.",
   "boxes" : "The boxes have been carefully stacked in one corner of the room and"+
   " the lids sealed tight.",
   "crates" : "The crates are filled with carefully packed dishes, some of which"+
   " broke anyway.",
   "barrels" : "Looking inside the barrels you find that they were mainly filled with"+
   " salted fish. The stench is terrible and there is not much left other than bones"+
   " and some salty scales.",
   "shelves" : "There are wooden shelves covering the walls of the room. Most of"+
   " them have held up, but a few shelves that had heavier items gave way and broke"+
   " under the weight after having rotted some. Looking over the other items you"+
   " don't see anything that could be of use anymore.",
   "floor" : "The floor is covered in dust, you can see several broken pottery jars"+
   " that appear to have fallen when the shelves they were sitting on broke. Their"+
   " contents have decayed with time and are useless now.",
   ({"wall","walls"}) : "The walls are covered in shelves filled with various items,"+
   " some of which have rotted away and spilled their contents to the floor.",
   ]));
   set_search("barrels","You search through the fish filled barrels and find nothing,"+
   " but now your hands stink of rotted and salty fish.");
   set_search("shelves","The shelves don't have much on them, some rotted bags of"+
   " flour and herbs that have dried to dust.");
   set_search("crates","You find plates, cups, bowls, and dust, lots and lots of dust.");
   set_search("boxes",(:TO,"search_boxes":));
   set_exits(([
   "east" : ROOMS+"keep10",
   ]));
   set_door("rotted door",ROOMS+"keep10","east","keep master_key");
   set_string("rotted door","open", "The rotted door almost falls off its hinges as it swings open.");
   set_string("rotted door","close", "The rotted door shudders to a close.");
}

void reset()
{
   ::reset();
   FOUND = 0;
   add_item("boxes","The boxes have been carefully stacked in one corner of the"+
   " room and the lids sealed tight.");
}

int search_boxes(string str)
{
   object obj;
   string treasure;

   if(FOUND == 1) {
      tell_object(TP,"It appears someone has already searched through the boxes and"+
      " there is nothing left to find here.");
      tell_room(ETP,""+TPQCN+" searches through the boxes but finds nothing of interest.",TP);
      return 1;
   }
   if(!random(6)) {
      switch(random(7)) {
         case 0:
            treasure = "beacon lantern";
            obj = new("/d/common/obj/misc/beacon");
            break;
         case 1:
            treasure = "bullseye lantern";
            obj = new("/d/common/obj/misc/bullseye");
            break;
         case 2:
            treasure = "pair of boots";
            obj = new(CLOTHING+"boots");
            break;
         case 3:
            treasure = "leather belt";
            obj = new(CLOTHING+"belt");
            break;
         case 4:
            treasure = "leather cloak";
            obj = new(CLOTHING+"cloak");
            break;
         case 5:
            treasure = "set of lock picks";
            obj = new("/d/tharis/obj/thief_tools");
            break;
         case 6:
            treasure = "set of climbing tools";
            obj = new("/d/common/obj/misc/climb_tool");
            break;
      }
      tell_object(TP,"You search carefully through the boxes and find a "+treasure+".");
      tell_room(ETP,""+TPQCN+" searches through the boxes and finds something.",TP);
      obj->move(ETP);
      add_item("boxes","The boxes have been carefully stacked in one corner of the"+
      " room, but it appears someone has recently rummaged through their contents.");
      FOUND = 1;
      return 1;
   }
   tell_object(TP,"You search through the boxes but don't find anything of interest.");
   tell_room(ETP,""+TPQCN+" searches through the boxes but finds nothing of interest.",TP);
   return 1;
}
