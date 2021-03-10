#include <std.h>
#include "/d/common/common.h"
#include "keep.h"
inherit VAULT;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_short("Library of a Ruined Keep");
   set_long(
   "This room must have once been a pleasant library when the keep was still"+
   " in good shape. There are bookshelves on the north and east walls that"+
   " are filled with mildewed books. On the west side is a large study desk"+
   " with a candle holder on it. The chair that must have gone with the desk"+
   " is in many pieces on the floor. The floor itself is very dusty, but"+
   " free from mud and moss. This room seems to be better insulated against"+
   " the elements."
   );
   set_smell("default","The smell of mildew is almost over powering.");
   set_listen("default","Everything is quiet in here.");
   set_items(([
   "door" : "The door to the north has managed to withstand the passage of"+
   " time with minimal decay. The metal brackets reinforcing the door as"+
   " well as the hinges and knob are quite rusty, but the door itself seems"+
   " sturdy enough.",
   ({"bookshelf","bookshelves"}) : "Large oak bookshelves are still standing"+
   " on the north and east walls. They are filled with books that will never"+
   " be used again.",
   "books" : "There are many large, leather bound volumes on the shelves."+
   " Unfortunately, whatever knowledge they contained is now long gone"+
   " because they are covered in mildew and absolutely ruined.",
   "candle holder" : "There is a simple pewter candle holder on the desk."+
   " It is encrusted with wax, but holds no candle.",
   ({"desk","study desk"}) : "This is a large oak study desk. You can"+
   " imagine that it was once used for reading and writing when the keep"+
   " was actually used. The chair that used to match it apparently toppled"+
   " to the floor and broke into several pieces.",
   "floor" : "The floor is covered in dust.",
   "walls" : "The walls are made of smaller cut stones that have been"+
   " mortared together to insulate the room better, preventing sound, wind"+
   " and rain from intruding so easily.",
   "ceiling" : "The ceiling seems to be fairly intact here, you're not"+
   " worried about this section caving in on your head at least.",
   ]));
   set_exits(([
   "south" : ROOMS+"keep4",
   ]));
   set_door("door",ROOMS+"keep4","south","keep master_key");
   set_locked("door",1,"lock");
   lock_difficulty("door",40,"lock");
   set_string("door","open","The door creaks open rather loudly.");
   set_string("door","close","The hinges on the door creak noisily as it closes.");
}

void reset() {
   object obj, obj2;

   ::reset();
   if(!present("chest") && !random(3)) {  // making only here on random reset too *Styx*
      obj = new("/d/common/obj/misc/schest");
      obj->move(TO);
      obj->set_key("chestkey");
      obj->set_short("A rusty chest");
      obj->set_long("This is a small, rusty chest.\nIt is closed.");
      obj->set_name("rusty chest");
      obj->set_id(({"chest","small chest","schest","rusty chest"}));
      obj->set_open_long("A small, rusty chest.\nIt is open.");
      obj->set_closed_long("A small, rusty chest.\nIt is closed.");
// making scrolls more random to prevent ooc info. abuse *Styx* 12/28/03, lc 8/9/03
      if(!random(5)) {
	obj2 = new("/d/magic/scroll");
      	obj2->set_spell(random(2)+1);
      	obj2->move(obj);
      }
      switch(random(4)) {
	case 0:  RANDSTUFF->find_stuff(obj, "component", random(5)+1);	
	case 1:  RANDSTUFF->find_stuff(obj, "coins", random(50)+10);    break;
	case 2:  RANDSTUFF->find_stuff(obj, "kit", random(10)+2);       
	case 3:  RANDSTUFF->find_stuff(obj, "stuff"); 		        break;
      }
      obj->toggle_closed();
      obj->set_lock("locked");
      obj->lock_difficulty(35);
   }
}
