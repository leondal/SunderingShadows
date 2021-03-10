#include <std.h>
inherit ROOM;

void create(){
    object ob;
    ::create();
	set_short("The Entrance to the Storage Room of the Iron Fist");
        set_long(
@FIST
%^BLUE%^This is the entrance to the storage room where the
%^RED%^Iron Fist%^BLUE%^ members store items to be sold at a later
time. There is very little in this room other than
a board in the center of the room. The store is
through an arch to the south.
FIST
        );
	set_light(2);
    set_property("no teleport",1);
	set_property("no attack",1);
	set_property("no steal",1);
	set_property("indoors",1);
    set_exits(([
        "north":"/d/guilds/fist/hall/main",
		"south":"/d/guilds/fist/hall/store"
	]));
	set_items(([
		"sign":"Read it to get a list of commands"
	]));
    ob = new(BBOARD);
    ob->set_name("board");
    ob->set_id(({"board","request board"}));
    ob->set_board_id("fistrequest");
    ob->set_max_posts(60);
    ob->set_location("/d/guilds/fist/hall/store1.c");
    ob->set_short("Iron Fist Board of Requests");
  ob->set_long("%^MAGENTA%^This board is for the %^RED%^Iron Fist %^MAGENTA%^members to post items requested by others.\n");
}

