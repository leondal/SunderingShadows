#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no teleport",1);
    set_name("Area idea room");
  set_short("Area idea room.");
    set_long(
@OLI

This is a room with a bunch of pictures painted on the walls and on the boards, with ideas
of areas yet to be realized or maybe ideas that haven't been completely thought out yet.

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
  if(!present("houses_sign"))
     new("/d/common/immortals/houses_sign")->move(TO);
  if (!objectp(present("areas_board"))) {
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "areas_board" }) );
    ob->set_board_id("areas_board");
    ob->set("short", "The Area idea and discussion board");
    ob->set("long", "A large board where the builders and other wizzes can discuss new areas and coding challenges.");
    ob->set_max_posts(100);
    ob->set_location("/d/common/immortals/arearoom");
//added by Styx 6/02 just in case a mortal ends up in the room
    ob->set_restricted_read();
    ob->set_ooc_board(1);
  }
}

void init(){
    ::init();
    if(!wizardp(TP)) {
	write("Sorry, but you aren't allowed in there unless you are at least a builder.");
	if(avatarp(TP))
   	   TP->move("/d/dagger/avalounge");
	else TP->move("/d/shadowgate/adv_main");
	return 1;
    }
}
