#include <std.h>
#include "../inherit/keep.h"
inherit VAULT;

int STONE;

void create() {
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_property("indoors",1);
   set_property("light",1);
   set_name("A secret basement");
   set_short("%^ORANGE%^A secret basement%^RESET%^");
   set_long("%^ORANGE%^A secret basement%^RESET%^\n"
"This is the end of a short passageway in the secret basement you've found.  "
"The smooth stone %^BLUE%^walls %^RESET%^offer a dreary aspect to this "
"underground passageway.  There is a large door within the west that appears to "
"be in surprisingly good condition.  Set into the eastern wall seems to be some "
"kind of %^ORANGE%^archway%^RESET%^.\n");
   set_smell("default","The faint scent of charred flesh lingers in the air.");
   set_listen("default","The silence is eerie.");
   set_items(([
     "hole" : ((:TO,"hole_desc":)),
     ({"arch","archway"}) : ((:TO,"arch_desc":)),
     "walls" : "%^BLUE%^The stone walls are unnaturally smooth, forming "
"perfect angles with the floor and ceiling.  Within the west wall there is "
"a large and sturdy door.  Directly opposite upon the eastern wall, there "
"appears to be a matching %^ORANGE%^archway%^BLUE%^.%^RESET%^",
   ]));
   set_exits(([
     "south" : ROOMS"basement1",
     "west" : ROOMS"basement3",
   ]));
   set_door("door",ROOMS"basement3","west","keep master_key");
   set_door_description("door","%^ORANGE%^There is a large, sturdy door in "
"the western wall.  It is in surprisingly good condition.%^RESET%^");
   set_locked("door",1,"lock");
   lock_difficulty("door",20,"lock");
}

void init() {
   ::init();
   add_action("insert","insert");
}

int insert(string str) {
   object obj;

   if(!str) {
      tell_object(TP,"%^RESET%^Try %^YELLOW%^insert item into hole"
"%^RESET%^.");
      return 1;
   }
   if(STONE == 1) {
      tell_object(TP,"There is already something in the hole!");
      return 1;
   }
   if(str != "stone into hole") {
      tell_object(TP,"%^RESET%^Try %^YELLOW%^insert item into hole"
"%^RESET%^.");
      return 1;
   }
   if(!present("keep_stone",TP)) {
      tell_object(TP,"The item you have doesn't seem to fit, you had better find another one.");
      return 1;
   }
   STONE = 1;
   add_exit(ROOMS+"basement4","east");
   tell_object(TP,"%^BOLD%^%^WHITE%^The stone fits perfectly!%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^"+TPQCN+" inserts a stone into the "
"hole.%^RESET%^",TP);
   obj = present("keep_stone",TP);
   obj->remove();
   tell_room(TP,"%^YELLOW%^The stone portal slowly slides open.%^RESET%^");
   return 1;
}

string hole_desc() {
   if(STONE) return("%^CYAN%^There is a slight indentation in the eastern "
"wall to the right of the archway, which looks as if it would fit something "
"small, perhaps the size of a human fist.  However, it seems currently to "
"be already filled.%^RESET%^");
   else return("%^CYAN%^There is a small hole to the right of the stone "
"archway.  It almost looks like you could %^YELLOW%^insert %^RESET%^%^CYAN%^"
"an item into it.  It is a very unusual shape, however.%^RESET%^");
}

string arch_desc() {
   if(STONE) return("%^ORANGE%^Within the eastern wall is an archway of "
"stone, distinguished by being of a slightly lighter color than the walls.  "
"It is currently open, allowing access into a small room beyond.  Upon "
"closer inspection, you see a small %^YELLOW%^hole %^RESET%^%^ORANGE%^to "
"the right of the archway which is currently filled.%^RESET%^");
   else return ("%^ORANGE%^Within the eastern wall is an archway of stone, "
"distinguished by being of a slightly lighter color than the walls.  It is "
"perfectly smooth, and has no knob or any other apparent way to open it.  "
"Upon closer inspection, however, you see a small %^YELLOW%^hole %^RESET%^"
"%^ORANGE%^to the right of the archway.%^RESET%^");
}

void reset_stone() { STONE = 0; }
