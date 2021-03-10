#include <std.h>
#include "../inherit/keep.h"
inherit CVAULT;

int FOUND;

void create() {
   set_monsters(({MONS+"xvart"}),({1}));
   ::create();
   set_repop(40);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("A ruined storage room");
   set_short("%^RESET%^%^ORANGE%^A ruined storage room%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^A ruined storage room%^RESET%^\n"
"You are standing in what appears to be an old food storage room.  A few "
"%^ORANGE%^sacks %^RESET%^and %^RED%^crates %^RESET%^have been placed around "
"the room, some stacked atop others.  Many %^CYAN%^shelves %^RESET%^line the "
"walls, a few of which have rotted through and dropped their contents upon the "
"%^BLUE%^floor%^RESET%^.  A fine layer of %^ORANGE%^dust %^RESET%^covers "
"everything, hinting that nothing here has been touched in a long time.\n");
   set_smell("default","The dust and mildew are almost overpowering.");
   set_listen("default","It is fairly quiet here.");
   set_items(([
     ({"crates","sacks"}) : "%^ORANGE%^Sacks and crates have been stacked upon "
"the ground.  Most are spoiled with mould and mildew, and some have torn open "
"to spill their rotted contents across the floor.  Little grains roll underfoot "
"as you walk.  None of their contents appears edible.",
     "floor" : "%^BLUE%^The floor is covered in dust and mud.  Sacks and crates "
"are stacked around, many of which have split or broken and strewn their "
"contents everywhere.  You can see several broken pottery jars, that appear to "
"have fallen and shattered when the shelves they were sitting on rotted through"
".  Their contents have decayed with time and are useless now.",
     "dust" : "%^ORANGE%^A fine layer of dust covers everything in the room.  "
"Likely nothing here has been touched in a long time.%^RESET%^",
     "shelves" : ((:TO,"shelf_desc":)),
   ]));
   set_search("default","%^ORANGE%^There are a lot of things in this room to "
"search through.  %^CYAN%^Shelves %^ORANGE%^surround most of the walls, and "
"there are several %^WHITE%^sacks %^ORANGE%^and %^RED%^crates %^ORANGE%^upon "
"the floor.");
   set_search("sacks","%^ORANGE%^Hard, ruined grain spills out between your "
"fingers, but none of it seems edible.%^RESET%^");
   set_search("crates","%^RED%^Just getting close to the crates is enough to "
"warn you away by the smell of decay.  Whatever was kept in them has long since "
"rotted.%^RESET%^");
   set_search("shelves",(:TO,"search_shelves":));
   set_exits(([
     "west" : ROOMS"keep18",
   ]));
   set_door("door",ROOMS"keep18","west",0);
   set_door_description("door","%^ORANGE%^A simple wooden door, scratched and "
"grimy from years of abuse, but still intact.  Its hinges are rusted and "
"probably very stiff.%^RESET%^");
   set_string("door","open","The door opens with a loud creak.");
   set_string("door","close","The door creaks shut.");
}

void reset() {
   ::reset();
   FOUND = 0;
}

int search_shelves(string str) {
   if(present("xvart")) {
     tell_object(TP,"There is a xvart in the way!");
     return 1;
   }
   if(FOUND) {
     tell_object(TP,"%^CYAN%^It appears someone has already searched through "
"the shelves and there is nothing left to find here.%^RESET%^");
     tell_room(ETP,"%^CYAN%^"+TPQCN+" searches through the shelves but finds "
"nothing of interest.%^RESET%^",TP);
     return 1;
   }
   tell_object(TP,"%^CYAN%^You search carefully through the shelves and find "
"something of value.%^RESET%^");
   tell_room(ETP,"%^CYAN%^"+TPQCN+" searches through the boxes and finds "
"something.%^RESET%^",TP);
   new(OBJ2"spices")->move(TO);
   FOUND = 1;
   return 1;
}

string shelf_desc() {
   if(FOUND) return("%^CYAN%^Some of the shelves are still intact, but it "
"appears someone has recently rummaged through their contents.%^RESET%^");
   else return("%^CYAN%^Some of the shelves are still intact and relatively "
"undamaged.  Perhaps you could still find something of value in them if you "
"tried to %^YELLOW%^search %^RESET%^%^CYAN%^them.%^RESET%^");
}
