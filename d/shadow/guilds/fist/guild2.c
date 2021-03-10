#include <std.h>
inherit ROOM;

void create(){
    ::create();
set_short("The Great Hall of the Iron Fist");
	set_long(
@FIST
%^BLUE%^This is the Great Hall of the %^RED%^Iron Fist%^BLUE%^.
Here it's members have gathered since times forgotten to revel and share
stories of their adventures. There is a massive, oaken, table running the length of the hall, lined with hulking great chairs.
The ceiling is shrouded in shadow, the light of the torches flickering on the wall doing little to disperse the heavy darkness.
FIST
	);
set_property("no teleport",1);
set_light(2);
set_property("no attack",1);
set_property("no steal",1);
set_property("indoors",1);
	set_exits(([
"north":"/d/shadow/guilds/fist/guild4.c",
"out": "/d/shadow/guilds/fist/guild1.c"
,"east":"/d/shadow/guilds/fist/guild3.c"
	]));
set_smell("default","You catch a faint scent of stale wine and roast boar underlying the dank smell of aged stone.");
set_listen("default","You hear the scurrying of tiny feet, and faint conversation coming from the door to your east.");
}
