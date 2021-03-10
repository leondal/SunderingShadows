#include <std.h>
inherit ROOM;

void place_board()
{
  string which, desc;
  object ob;
  which = "new_avatar_board";
  desc = "avatar";
  if(present("new avatar board", TO)) return;
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({ "board", "bulletin board", "new avatar board" }) );
  ob->set_board_id("new_avatar_board");
  ob->set_short("OOC avatar board");
  ob->set("long", "A large board where the avatars of the realm may post.");
  ob->set_max_posts(300);
  ob->set_location("/d/common/boards/avatarboard");
  //added by Styx 6/02 just in case a mortal ends up in the room
  ob->set_restricted_read();
  ob->set_ooc_board(1);    
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
