#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
   object ob;
   ::create();
   set_exits( ([
   "south" : ROOMS+"entrance",
   "west" : ROOMS+"v3",
   "east" : ROOMS+"v5",
   "north" : ROOMS+"v18",
   ]) );
   ob = new("std/bboard");
   ob->set_name("board");
   ob->set_id(({"board","bulletin board","valley board"}));
   ob->set_board_id("valley_board");
   ob->set_short("Moonstone Vale information board");
   ob->set_long("This is a large board where wondering adventurers can post news to other visitors of the valley.");
   ob->set_max_posts(50);
   ob->set_location(ROOMS+"v4");
}
