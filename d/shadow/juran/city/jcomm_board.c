//Room for copies of comment board for Juran - 
//essentially copied from /d/shadowgate/ombud_hall

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
	set_short("Comments Department");
	set_long(
    		"%^BOLD%^%^CYAN%^"+
		"This room is pristine and clean as if the decay and ruin that "+
		"has infected the rest of Juran can not touch this place.  A "+
		"board is hanging in mid-air where players can make helpful "+
		"comments or constructive criticisms known.  Flames are not "+
		"required, desired, or accepted here and will be removed with "+
		"possible consequences to the flamer.  The comments placed on "+
		"this magical board are not to be placed in-character.  "+
		"Note that there are special commands for <typo>s, <bug>s, "+
		"and <praise> and you are encouraged to use them if it's "+
		"something that isn't necessarily a general concern.%^RESET%^"
	);
   	ob = new("std/bboard");
   	ob->set_name("board");
   	ob->set_id( ({ "board", "comments board", "ombud" }) );
   	ob->set_board_id("ombud");
           ob->set_ooc_board(1);
   	ob->set("short", "The ShadowGate Comments Board");
  	ob->set("long", "Suspended in air with no physical means of "+
  		"support this message device appears to be made of a dark "+
  		"cloud like substance that retains letters that you write "+
  		"with your finger.\n");
   	ob->set_max_posts(30);
  	ob->set_location("/d/shadow/juran/city/jcomm_board");
   	set_exits(([
      	"up": JROOMS+"p1"
   	]));
}

void reset(){
   ::reset();
   
}
