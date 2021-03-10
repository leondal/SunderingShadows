#include <std.h>
#include "elf.h"

inherit VAULT;

void create()
{
   ::create();
   set_indoors(1);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Training Room");
   set_short("%^BOLD%^Training Room%^RESET%^");
   set_long(query_short()+"\n%^GREEN%^This is a simple area for "+
   "training.  It is a place set against a cliff "+
   "overlooking the grove that has a stone overhang"+
   " above it to protect people from the elements.  "+
   "There are some marks of powerful spells and "+
   "weapons being tested here.  To the southwest is"+
   " door that leads to a stable%^RESET%^");
   set_smell("default", "It smells of crispt and cold air.");
   set_listen("default", "Cold winds woosh along the cliff.");
   set_exits(([
      "southwest" : ROOMS"quest",
      "down" : ROOMS"cliff4",
 
   ]));
   set_items(([
      ({"mark", "marks"}): "Marks from hacks of weapons and blasts of spells are all over.",
      ({"overlook", "stones"}): "There is a stone overlook protecting this place from the elements.",
      
   ]));
   set_door("door",ROOMS"quest","southwest","key");
   set_open("door",0);
   set_locked("door",0);
}
void reset(){
    object dummy;
    ::reset();
    
    if(!present("dummy")){
     dummy = new("/d/common/mons/testdummy");
     dummy->move(TO);
     dummy->set_property("damage tester");

    }
}