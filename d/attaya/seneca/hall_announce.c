// changed for ooc boards gone remote access *Styx*  3/30/03
#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
//   object ob;

   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_property("indoors", 1);
   set_short("Great Hall of Seneca");
/*
   set_long(
@DESC
The %^CYAN%^Great Hall%^RESET%^ of Seneca is a place where adventurers
can keep up to date on the happenings in the world. There 
are three boards in the building, mirror images of those
in the great city of Shadow. The doorway to the east leads 
outside, to the south leads to another board.
DESC
   );
*/
   set_long("This %^CYAN%^Great Hall%^RESET%^ of Seneca seems to have "
"fallen into disuse.  There are footprints in the dust where adventurers "
"occasionally wander through but it appears otherwise deserted.  It is "
"quite impressive architecture, as is typical of Seneca but the interior "
"was left largely unfinished.  The archway to the north leads out to the "
"main courtyard and entrance.");
   set_exits( ([
      "east" : "/d/attaya/seneca/hallyard",
      "south" : "/d/attaya/seneca/hall_complaint"
   ]) );
/*
   ob = new("std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "board", "bulletin board", "announcement board"}) );
   ob->set_board_id("announcement_board");
   ob->set("short", "The Official Announcement Board");
   ob->set("long", "An old cork board where the adventurers "
           "who pass through ShadowGate can read about the information "
           "the Wizards of the Realms announced.\n");
   ob->set_max_posts(30);
    ob->set_ooc_board(1);
   ob->set_location("/d/attaya/seneca/hall_announce");
*/
}
/*
void init() {
   ::init();
   add_action("post_func","post");
   add_action("post_func","edit");
   add_action("post_func","answer");
}

int post_func(string str) {
   if( wizardp(TP) ) return 0;
   if( avatarp(TP) ) return 0;
   if( !avatarp(TP) ) {
      tell_object(TP,"Yeah if you are not a wiz, Go away!");
      tell_room(ETO,TPQCN+" just tried to do something bad!",TP);
      return 1;
   }
   return 1;
}
*/
