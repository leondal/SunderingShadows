#include <std.h>
inherit ROOM;

void create(){
    object ob;
    ::create();
    set_light(2);
    set_property("indoors",1);
	set_short("Rider's Guild");
	set_long(
@RIDERS
%^CYAN%^%^BOLD%^The Rider's Guild%^RESET%^
You find yourself in a comfortably furnished lounge.  There are
sofas and comfy chairs scattered around the room.  Against one
wall is a bar serving various drinks and light snacks.  On another
wall, you notice the Rider's Board where members can post messages.
RIDERS
	);
	set_exits(([
		"out": "/d/shadow/guilds/riders/guild1.c"
	]));
    set_smell("default","The appetizing smell of food drifts to you from the bar.");
    set_listen("default","You hear the sound of low conversations from around the room,
but no noise from the barn reaches this quiet lounge.");
        ob = new("std/bboard");
        ob->set_name("board");
        ob->set_id( ({ "board", "riders board" }) );
        ob->set_board_id("riderguild");
        ob->set_max_posts(30);
	ob->set_location("/d/shadow/guilds/riders/guild2");
        ob->set("short", "Riders Guild Board");
        ob->set("long", "This board is for The members of the Riders "
		"Guild to post their ideas and comments.\n");
}
init() {
    ::init();
    add_action("cobble","cobbler");
       }

int cobble() {
    tell_object(this_player(),
        "You shout : 'Cobbler can you give me some boots ??'");
    tell_room(environment(this_player()),
   (string)this_player()->query_cap_name()+" calls for the cobbler.",
           ({ this_player() }) );
    call_out("restore_boots",5);
    return 1;
}

int restore_boots() {
   object boots;
    tell_object(this_player(),
        "The cobbler enters and fits you with a new pair of boots");
    tell_room(environment(this_player()),
        "The cobbler enters the room and fits "+
        (string)this_player()->query_cap_name()+" with new boots",
        ({ this_player() }) );
    boots = new("/d/shadow/guilds/riders/riders_boots.c");
    boots->move(this_player());
    return 1; 
}
