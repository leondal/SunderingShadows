#include <std.h>
#include <config.h>
#include "short.h"

inherit CITYIN;

void create() {
   object ob;

   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_property("indoors", 1);
   set_short("Adventurer's Hall of Seneca");
   set_long(
@DESC
%^BOLD%^This is the Seneca branch of the Adventurers' Hall.%^RESET%^
The room is formed of smooth walls and mathematical angles that 
give interesting lines to the room.  On the wall before you is 
a map of the realm as it exists currently.
DESC
   );
   set_exits( ([
      "out" : "/d/attaya/seneca/advyard",
   ]) );
   set_door("door","/d/attaya/seneca/advyard","out",0);
   ob = new("std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "board", "bulletin board", "seneca board", "adventurer's board"}) );
   ob->set_board_id("seneca_board");
   ob->set("short", "The Adventurer's Board");
   ob->set("long", "An old cork board where the adventurers who pass through Attaya post notes to others on various topics of concern or interest.\n");
   ob->set_max_posts(50);
   ob->set_queue();  // added by Styx 10/25/02 now that these boards are IC
   ob->set_location("/d/attaya/seneca/adv_hall.c");
}

void init() {
   ::init();
   add_action("Look","look");
   add_action("Look","exa");
}

int Look(string str) {
   if(!str || (str != "wall" && str != "map")) return 0;
   TP->more("/realms/vetri/map");
   return 1;
}
