#include <std.h>
inherit ROOM;

void create(){
    object ob;
    ::create();
    set_light(2);
    set_property("no teleport", 1);
    set_property("indoors",1);
    set_short("Foyer of the Rider's Guild Hall");
    set_long(
      "You have entered the foyer of the hall of the Riders.  Your boots click along the beautifully crafted hardwood floors.  All around the room on the walls are banners of gold cloth with the knightpiece emblem of the riders on them.  To the northeast there is a door into a great outdoor jousting field. To the west great glass doors open into the courtyard, and to the northwest, a broad hallway filled with the paintings and tokens of justice, honory, and victory leads to the Great Hall."
    );
    set_exits(([
	"northeast" : "/d/shadow/guilds/riders/arena1.c",
	"northwest" : "/d/shadow/guilds/riders/greathall.c",
	"west" : "/d/shadow/guilds/riders/cyard.c",
	"out": "/d/shadow/guilds/riders/guild1.c"
      ]));
    set_items(([
	"floors" : "These floors are made of fine wood, and are kept amazingly clean and shiny.",
	"banners" : "These banners are made of fine woven gold fabric, and they have the emblem of the riders, a great knightpiece, emblazened on them."
      ]));
    set_smell("default","The appetizing smell of food drifts to you from the bar.");
    set_listen("default", "You hear the sound of low conversation from around the room, but no noise from the barn reaches this quiet lounge.");
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
