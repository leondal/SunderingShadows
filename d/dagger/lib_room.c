#include <std.h>

inherit ROOM;

void create(){
    object ob;
    ::create();
    set_short("Mudlib discussion room");
    set_long(
@OLI
    This room is designed to hold the discussions concerning the
    changes and improvements to the mudlib.  Used for two major purposes,
    a board stands here.  The board will alert wizes that a file has changed
    to prevent loss of code.  It will alert all wizes and avatars of changes
    made and possible impact on the players.  This will hopefully help us
    find bugs when the changing wiz is not available.
OLI
            );
    set_exits(([
               "out":"/d/dagger/avalounge",
               ]));
    set_properties((["indoors":1,"light":2]));
    set_property("no teleport",1);
    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "reality board"}) );
    ob->set_board_id("lib_board");
    ob->set("short", "The Mudlib board");
    ob->set("long", "Board meant for posts about changes to all mudlib.");
    ob->set_max_posts(300);
    ob->set_location("/d/dagger/lib_room.c");

}
