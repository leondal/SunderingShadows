#include <std.h>
inherit ROOM;

void place_board()
{
  string which, desc;
  object obj;
  if(!present("ideasboard", TO))
  {
	obj = new("std/bboard");
	obj->set_name("ideas");
	obj->set_id(({"board", "bulletin board","ideasboard"}));
	obj->set_board_id("ideasboard");
	obj->set_short("OOC ideas board");
    obj->set("long", "A large board where mail from players asking for help "
    "help goes when they use the <avatarmail> command.  It is meant to "
    "facilitate the immortal discussions of the "
    "requests and/or for immortals to let others they have responded.");
    obj->set_max_posts(400);
	obj->set_location("/d/common/boards/ideasboard.c");
    obj->set_ooc_board(1);
    obj->set_anonymous_board(1);
//    obj->set_restricted_read();
  }
}

void create(){
    ::create();
    set_no_clean(1);
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no teleport",1);
    set_short("Avatar board room");
    set_long("Just one of the rooms housing a board.  Nothing more, nothing less.");
    set_exits( ([ "out" : "/d/dagger/boards_portal", ]) );
}

void reset()
{
    ::reset();
    place_board();
}
