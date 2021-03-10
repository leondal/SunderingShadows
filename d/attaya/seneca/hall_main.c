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
in the great city of Shadow. The doorway to the west leads
to another board, to the north leads outside.
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
      "west" : "/d/attaya/seneca/hall_complaint",
      "north" : "/d/attaya/seneca/hallyard"
   ]) );
/*
   ob = new("std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "board", "bulletin board", "reality board"}) );
   ob->set_board_id("main_board");
   ob->set("short", "The ShadowGate Reality Board");
   ob->set("long", "An old cork board where the adventurers "
           "who pass through ShadowGate post information on the "
           "reality they have discovered.\n");
   ob->set_max_posts(50);
    ob->set_ooc_board(1);
   ob->set_location("/d/attaya/seneca/hall_main");
*/
}

