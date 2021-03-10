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
in the great city of Shadow. The doorways to the east and 
north both lead to other boards.
DESC
   );
*/
   set_long("This %^CYAN%^Great Hall%^RESET%^ of Seneca seems to have "
"fallen into disuse.  There are footprints in the dust where adventurers "
"occasionally wander through but it appears otherwise deserted.  It is "
"quite impressive architecture, as is typical of Seneca but the interior "
"was left largely unfinished.");
   set_exits( ([
      "east" : "/d/attaya/seneca/hall_main",
      "north" : "/d/attaya/seneca/hall_announce"
   ]) );
/*
   ob = new("std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "comments board", "board"}) );
   ob->set_board_id("ombud");
   ob->set_max_posts(30);
      ob->set_ooc_board(1);
   ob->set_edit_ok( ({ "nialson"}) );
   ob->set_location("/d/attaya/seneca/hall_complaint");
   ob->set("short", "the ShadowGate Comment Board");
   ob->set("long", "People of this reality come here to post their "
           "comments and questions for the immortals who control "
           "the fate of all reality.\n");
*/
}
