#include <std.h>
inherit ROOM;

void place_board()
{
    string which, desc;
    object obj;
    if(!present("plotsboard", TO))
    {
        obj = new("std/bboard");
        obj->set_name("plots");
        obj->set_id(({"board", "bulletin board","plotsboard"}));
        obj->set_board_id("plotsboard");
        obj->set_short("OOC plots board");
        obj->set("long", "A large board where current events and plot hooks are displayed.");
        obj->set_max_posts(400);
        obj->set_location("/d/common/boards/plotsboard.c");
        obj->set_ooc_board(1);
        obj->set_anonymous_board(1);
//      obj->set_restricted_read();
    }
}

void create(){
    ::create();
    set_no_clean(1);
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no teleport",1);
    set_short("Plots board room");
    set_long("Just one of the rooms housing a board.  Nothing more, nothing less.");
    set_exits( ([ "out" : "/d/dagger/boards_portal", ]) );
}

void reset()
{
    ::reset();
    place_board();
}
