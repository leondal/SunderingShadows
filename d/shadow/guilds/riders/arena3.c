//coded by grendel, with no idea what the hell he's doing.
#include <std.h>
inherit ROOM;
void create() {
::create();
set_name("Rider's Jousting Court");
set_short("Jousting Court");
set_long(
"Here you can see a long jousting court where you and your fellow members may hone your combative skills.  A long pole runs down the center of the field, for those people who wish to work on their charging abilities."
);
set_property("indoors",0);
set_property("light",1);
set_property("no teleport",1);
set_property("arena", 1);
set_property("deathmove","/d/shadow/guilds/riders/arenaheal.c");
set_listen("default", "you hear the clash of weapons and the shouts of victory in the distance");
set_smell("default","you smell the sweat from the exertion of men and horses.");
set_exits(([
"north" : "/d/shadow/guilds/riders/arena4.c",
"south" : "/d/shadow/guilds/riders/arena2.c",
]));
}
