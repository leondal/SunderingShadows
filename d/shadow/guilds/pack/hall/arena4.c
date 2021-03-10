//Mechanics by Bane, Atmosphere by Vis
#include <std.h>
inherit ROOM;
void create(){
    ::create();
set_name("%^BOLD%^%^RED%^Shades' Chamber of Death.%^RESET%^");
 set_short("Death Chamber");
    set_long(
"%^RED%^This is the Shades' Chamber of Death.%^RESET%^\n"
"You are within the Shades of Death's Arena. Here you can test your skills against your fellow guild members.\n"
"%^YELLOW%^May the most evil and crafty among you become victorious!%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_property("arena",1);
set_property("deathmove","/d/shadow/guilds/pack/hall/arena6.c");

set_listen("default","You can hear the triumphant chants of the victorious and the pittiful wailing of the vanquished.");
set_smell("default","You smell the fear and ecstacy of battle.");
    set_exits( ([
"west" : "/d/shadow/guilds/pack/hall/arena3.c",
    ]) );
}
