#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no teleport",1);
    set_name("builderlounge");
    set_short("Builder & Apprentice Lounge");
    set_long(
@OLI
    You are in a large glowing sphere.  In the middle of the sphere rests
a large board where you can post your ideas and questions.  Feel free to 
post questions about your code if no one is around to help at the time, 
thoughts or questions about your areas, and updates on your progress of
files/sections ready for review and feedback.
Behave yourself here or Styx might sic her code demons on you or your code.
OLI
   
    );
    set_smell("default", "You smell the fear of the mortals at what you may create.");
    set_listen("default", "You hear the cackle of the other wizzes as they watch their creations torment the mortals.");
    set_exits( ([
        "lib":"/d/dagger/lib_room",
	"wizlounge" : "/d/laerad/wizlounge",
    ]) );
}

void reset() {
  object ob;
  ::reset();
  if(!present("poster"))
     new("/d/common/immortals/fixit_poster")->move(TO);
  if (!objectp(present("builders board"))) {
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "builders board" }) );
    ob->set_board_id("builders_board");
    ob->set("short", "The Builders' discussion board");
    ob->set("long", "A large board where the builders and other wizzes can discuss new areas and coding challenges.");
    ob->set_max_posts(100);
    ob->set_location("/d/common/immortals/builderlounge");
//added by Styx 6/02 just in case a mortal ends up in the room
    ob->set_restricted_read();
    ob->set_ooc_board(1);
  }
}

void init(){
    ::init();
    if(!userp(TP)) return;
    if(!wizardp(TP)) {
	write("Sorry, but you aren't allowed in there unless you are at least a builder.");
	if(avatarp(TP))
   	   TP->move("/d/dagger/avalounge");
	else TP->move("/d/shadowgate/adv_main");
	return 1;
    }
}
