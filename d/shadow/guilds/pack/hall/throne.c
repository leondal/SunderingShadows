
#include <std.h>
inherit ROOM;


void create(){
object ob;
:: create();

set_light(0);
set_indoors(1);
set_property("no steal",1);
set_property("no teleport",1);
set_short("
%^MAGENTA%^Lord Soth's throne.
");
set_long(
@SEETH
%^BLUE%^You have entered Lord Soth's domain. The room is very dark and hard to see through. Against the wall at the center is a large shadowy mass. It appears to be a throne, yet oddly shaped. In the center of the room is a large cauldron. The cauldron looks to be filled with some sort of liquid. The rest of the room is shrouded in blackness.

SEETH
);

set_items(([
"throne" : "%^BLACK%^You inspect %^BLUE%^Lord Soth's throne %^BLACK%^ closer, and find that it has been made of the corpses of many kinds of creatures.",
"cauldron" : "%^BLUE%^You aproach the large cauldron cautiously and peer into the liquid while bringing light towards it. You find that this cauldron is filled with %^RED%^Blood %^BLUE%^.",
"corpses" : "%^MAGENTA%^Many assorted corpses are used and there seems to be a %^BLACK%^black aura %^MAGENTA%^eminating from the bodies.",

]));

set_exits(([
"south" : "/d/shadow/guilds/pack/hall/pack4.c",

]));

set_smell("default", "%^BLACK%^The smell of death fills the air.");
set_listen("default", "%^BLUE%^The only sound you hear is that of your own heartbeat.");

}
