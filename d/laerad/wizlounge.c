//Coded by Bane@Shadowgate for use by Immortals//
#include <std.h>
inherit ROOM;
object ob;
void create(){
    ::create();
    set_short("Hall of Immortals.");
    set_long(
	"%^BOLD%^YELLOW%^A Fantastic Golden Hall.%^RESET%^
You are standing in the Hall of Immortals!  Here all the wizards of the "+
	"realm can relax and talk, with the company of fellow wizards only.  "+
	"Huge marble pillars stretch from the floor into the infinite "+
	"skies above.  A large waterfall pours from the ceiling at the "+
	"northern end of the room, water splashing into a small pool at its "+
	"ending.  The walls hold shelves which are filled with a countless "+
	"number of tomes, containing all the knowledge of the universe.  "+
	"The room is very comfortable and pleasant."
    );
    set_property("indoors",1);
    set_property("light",3);
    set_smell("default","A wonderful fragrance fills the room.");
    set_listen("default","The pleasant chatter of the realms Immortals can be heard.");
    set_exits( ([
	"east" : "/d/laerad/bugreports",
	"west" : "/d/laerad/typos",
        "lib":"/d/dagger/lib_room",
	"builders" : "/d/common/immortals/builderlounge",
        "areas" : "/d/common/immortals/arearoom",
    ]) );
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id(({"board"}));
    ob->set_board_id("wizboard");
ob->set_max_posts(500);
    ob->set_location("/d/laerad/wizlounge");
    ob->set_short("Board of Immortals");
    ob->set_long("This is the Immortal posting board.  Everyone please post your new changes and or ideas or anything else that you are working on or have finished for the mud!  ");
    ob->set_property("no steal",1);
}

void init(){
    ::init();
    if(!userp(TP)) return;
    if(!wizardp(TP) && interactive(TP)) {
 	if(avatarp(TP)) {
	   write("Sorry, avatars aren't allowed in the wiz lounge.");
	   TP->move("/d/dagger/avalounge");
	} else {
	   TP->move("/d/shadowgate/adv_main");
	   write("You aren't allowed in there mortal.");
	}
	return 1;
    }
}
