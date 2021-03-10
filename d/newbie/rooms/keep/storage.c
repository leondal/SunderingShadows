#include <std.h>
#include "/d/common/common.h"
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
   set_short("%^ORANGE%^A ruined storage room%^RESET%^");
   set_long("%^ORANGE%^A ruined storage room%^RESET%^\n"
"You are standing in what appears to be an old storage room.  There are many "
"%^CYAN%^shelves %^RESET%^along the %^BLUE%^walls %^RESET%^holding various "
"items, most of which are fairly useless and all of them are covered in dust.  "
"A few of the shelves have rotted through in the middle, and dumped their "
"contents onto the %^ORANGE%^floor%^RESET%^.  There are a few %^ORANGE%^boxes"
"%^RESET%^, %^BLUE%^crates %^RESET%^and %^RED%^barrels %^RESET%^as well, all "
"stacked around the room.%^RESET%^\n");
   set_smell("default","The dust and mildew are almost overpowering.");
   set_listen("default","It is fairly quiet here.");
   set_items(([
     "crates" : "%^BLUE%^The crates are filled with carefully packed dishes, "
"but it seems this hasn't helped, as they are all broken now.%^RESET%^",
     "barrels" : "%^RED%^Looking inside the barrels you find that they were "
"mainly filled with salted fish.  The stench from them is terrible, and there "
"is not much left other than bones and some salty scales.%^RESET%^",
     ({"walls","shelves","wall"}) : "%^CYAN%^There are wooden shelves covering "
"most of the stone walls of the room.  A few of them have held up, but most of "
"them have rotted and broken under the weight of their loads.%^RESET%^",
     "floor" : "%^ORANGE%^The floor is covered in dust and mud.  You can see "
"several broken pottery jars, that appear to have fallen and shattered when the "
"shelves they were sitting on rotted through.  Their contents have decayed with "
"time and are useless now.%^RESET%^",
     "boxes" : ((:TO,"box_desc":)),
   ]));
   set_search("default","%^ORANGE%^There are a lot of things in this room to "
"search through.  %^CYAN%^Shelves %^ORANGE%^surround most of the walls, and "
"there are several %^RED%^barrels%^ORANGE%^, %^BLUE%^crates %^ORANGE%^and "
"%^RESET%^boxes %^ORANGE%^upon the floor.%^RESET%^");
   set_search("barrels","%^RED%^You search through the fish filled barrels and "
"find nothing, but now your hands stink of rotted and salty fish.%^RESET%^");
   set_search("shelves","%^CYAN%^The shelves don't have much on them, some "
"rotted bags of flour and herbs that have dried to dust.%^RESET%^");
   set_search("crates","%^BLUE%^You find plenty of broken plates, cups, and "
"bowls.  And dust, lots and lots of dust.%^RESET%^");
   set_search("boxes",(:TO,"search_boxes":));
   set_exits(([
     "east" : ROOMS"keep7",
   ]));
   set_door("rotted door",ROOMS"keep7","east",0);
   set_door_description("rotted door","%^ORANGE%^Though it once may have been "
"quite sturdy, this door is now falling apart.  One corner has decayed away, "
"leaving a hole through which to see the storage room on the other side.  It "
"leans precariously from its hinges.");
   set_string("rotted door","open", "The rotted door almost falls off its "
"hinges as it swings open.");
   set_string("rotted door","close", "The rotted door shudders to a close.");
}

void reset() {
   ::reset();
   FOUND = 0;
}

int search_boxes(string str) {
   if(present("xvart")) {
     tell_object(TP,"There is a xvart in the way!");
     return 1;
   }
   if(FOUND) {
     tell_object(TP,"%^ORANGE%^It appears someone has already searched through "
"the boxes and there is nothing left to find here.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through the boxes but finds "
"nothing of interest.%^RESET%^",TP);
     return 1;
   }
   RANDSTUFF->find_stuff(TO, "stuff");
   tell_object(TP,"%^ORANGE%^You search carefully through the boxes and find "
"something.%^RESET%^");
   tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through the boxes and finds "
"something.%^RESET%^",TP);
   FOUND = 1;
   return 1;
}

string box_desc() {
   if(FOUND) return("%^ORANGE%^The boxes have been carefully stacked in one "
"corner of the room, but it appears someone has recently rummaged through their "
"contents.%^RESET%^");
   else return("%^ORANGE%^The boxes have been carefully stacked in one corner "
"of the room and the lids sealed tight.  They seem undamaged, so perhaps you "
"could still find something of value in them if you tried to %^YELLOW%^search "
"%^RESET%^%^ORANGE%^them.%^RESET%^");
}
