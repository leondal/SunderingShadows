//	Watermargin Town Hall
//	Thorn@Shadowgate
//	11/15/94
//	Darkwood Forest Area
//	town_hall.c

#include <std.h>
#include <rooms.h>

inherit ROOM;

void create() {
    object ob;
    ::create();
    set_light(1);
    set_indoors(1);
    set_short("Watermargin Town Hall");
set_long(
@THORN
	
	This is the Town Hall for the Village of Watermargin.  Here 
you can go to post about the Darkwood County area.  The mayor
of Watermargin is here and is waiting to greet you and point 
out some of the finer features of his town.  The Darkwood
Main Board is here.
THORN
);
    set_exits(
              (["north" : "/d/darkwood/watermargin/street1"]) );

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "darkwood board" }) );
    ob->set_board_id("darkwood");
    ob->set_max_posts(30);
    ob->set_location("/d/darkwood/watermargin/town_hall");
    ob->set("short", "Darkwood Main Board");
    ob->set("long", "This is the Darkwood Main Board, feel free to place comments, suggestions or questions here.\n");

}

void reset() {
	::reset();
	if(!present("mayor")) {
		new("/d/darkwood/mon/mayor")->move(this_object());
	}
}
