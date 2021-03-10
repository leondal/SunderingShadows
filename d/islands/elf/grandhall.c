//grand hall
#include <std.h>
#include "elf.h"
inherit VAULT;


void create(){
    ::create();
set_property( "light", 2);
    set_property( "indoors", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Grand Hall");
    set_short("Grand Hall");
    set_long(
"%^GREEN%^This hall exemplifies the most ornate of elven "
"architecture%^MAGENTA%^.%^GREEN%^ It has a thick %^ORANGE%^carpeted%^GREEN%^ floor that "
"stretches between branches that arc upward toward the ceiling%^MAGENTA%^.%^GREEN%^  "
"%^CYAN%^S%^MAGENTA%^t%^CYAN%^a%^MAGENTA%^i%^CYAN%^n%^MAGENTA%^e%^CYAN%^d "
"g%^MAGENTA%^l%^CYAN%^a%^MAGENTA%^s%^CYAN%^s%^GREEN%^ windows depict classic stories of "
"elves%^MAGENTA%^.%^GREEN%^ The windows fill the room with color%^MAGENTA%^.%^GREEN%^  Most noticeably, is "
"a long black polished table made of sturdy and thick wood%^MAGENTA%^.%^GREEN%^  "
"Every now when something comes up a counsil of elders meet to "
"discuss things about elven kind, to pass judgment,"
" or to solve other important matters%^MAGENTA%^.%^GREEN%^ "
" It is a quiet place and feels very somber%^MAGENTA%^.%^GREEN%^%^RESET%^");

	set_items(([
      (({"floor","carpet"})) :
        "There is a dark brown carpet with branches used for trim.",
      (({"table"})) : "A large black table is in the center of the room.",
      (({"glass","stained glass"})) : "The windows depict "+
	  "elves fighting orc, ogres, and humans.",
	   ]));

   
      set_exits(([ "north" : ROOMS"hall4",
        "west" : ROOMS"hall8",	  ]));

   set_listen("default","The smell of trees fill the room.");
   set_smell("default",
   "This place is very quiet.");
}
void reset() {

  object ob;
  ::reset();
  if (!objectp(present(getuid(TO)+"_board"))) {
     ob = new(BBOARD);
     ob->set_name("Ashtae'Rathai_board");
     ob->set_id( ({ "board", getuid(TO)+"_board", "ashtae'rathai board" }) );
     ob->set_board_id("Ashtae'Rathai_board");
     ob->set("short", "%^RESET%^%^GREEN%^Ashtae'Rathai Board%^RESET%^");
     ob->set("long", "%^ORANGE%^A wooden board for people to"+
	 " pin notes.%^RESET%^");
     ob->set_max_posts(50);
     ob->set_location(base_name(TO));
     ob->move(TO);



  }
}
