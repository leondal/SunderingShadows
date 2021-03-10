//Room for copies of main boards for Juran - 
//essentially copied from /d/shadowgate/abyss
#include <std.h>
#include "../juran.h"

inherit ROOM;
object ob;

void create() {
	::create();
	set_property("light",-2);
        set_property("indoors",1);
        set_property("no teleport",1);
	set_terrain(STONE_BUILDING);
	set_travel(PAVED_ROAD);
	set_short("%^BOLD%^The abyss of souls");
	set_long(	"%^BOLD%^%^MAGENTA%^  You look behind you, and see that the door "+
	 	"you just entered is a small portal standing free in the air, on a small "+
    		"circular stone formation.  You are now standing on an outcropping of those "+
    		"stones and, as you look around you, you see the eternal nothing.  It is "+
    		"said that even in space, you can see the stars.  Here there is nothing, as "+
    		"you tumble through the endless void.\n\nAs you stand on the stones, "+
    		"suddenly small points of light appear in the distance, and start to float "+
    		"towards you.  As they get closer, you can see that they are vaguely human.  "+
    		"You then recognise them as the lost souls of those people who have had "+
    		"their existances here terminated.  They float around you in this dawnless "+
    		"hell.%^RESET%^"
    	);
   	ob = new("std/bboard");
   	ob->set_name("board");
   	ob->set_id( ({ "board", "bulletin board", "rid board" }) );
   	ob->set_board_id("Ridboard");
   	ob->set("short", "The board of riddings");
   	ob->set("long", "This board is here for riddings to be posted, and if "+
    		"warranted, the reason why.  Players who wish to post here, please keep "+
    		"it pertinent.\n");
   	ob->set_max_posts(100);
   	ob->set_location(JROOMS+"jrid_board");

   	set_exits(([
      	"portal": JROOMS+"p5"
      ]));
}

void reset(){
   ::reset();
}
