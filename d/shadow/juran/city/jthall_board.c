//Room for copies of main board for Juran - 
//essentially copied from /d/shadow/room/city/townhall.c

#include <std.h>
#include "../juran.h"

inherit ROOM;
object ob;

void create() {
	::create();
	set_property("light",-2);
	set_property("indoors",1);
	set_terrain(STONE_BUILDING);
	set_travel(PAVED_ROAD);
	set_short("ShadowGate Town Hall Board");
	set_long("This is where you can read most of the significant announcements "+
	  "over recent months by the wizards of ShadowGate.  This board is for "+
	  "you to READ ONLY.  Posts are made only by staff members.  It is an "+
	  "important board to read if you're away for even a week or two, because "+
	  "important announcements may have been cycled off of the Reality Board."
	);
   	ob = new("std/bboard");
   	ob->set_name("board");
  	ob->set_id( ({ "board", "bulletin board", "announcement board" }) );
  	ob->set_board_id("announcement_board");
  	ob->set("short", "The Official Announcement Board");
  	ob->set("long", "An old cork board where the adventurers "
          "who pass through ShadowGate can read about the information "
          "the Wizards of the Realms announced.\n");
   	ob->set_max_posts(100);
   	ob->set_location(JROOMS+"jthall_board.c");

   	set_exits(([
      	"east": JROOMS+"r16"
   	]));
}

void reset(){
   ::reset();
}

void init() {
   ::init();
   add_action("post_func","remove");
   add_action("post_func","post");
   add_action("post_func","edit");
   add_action("post_func","answer");
}

int post_func(string str) {
   if( wizardp(TP) ) return 0;
   if( avatarp(TP) ) return 0;
   if( !avatarp(TP) ) {
      tell_object(TP,"If you are not a wiz, you aren't allowed to do that!");
      tell_room(ETO,TPQCN+" just tried to do something bad!",TP);
      return 1;
   }
   return 1;
}
