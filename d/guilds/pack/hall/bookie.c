#include <std.h>
#include "/d/guilds/pack/short.h"

inherit ROOM;
//inherit "/d/guilds/inherit/g_money.c";
//this room is not loading so just making it a normal room. -H 12/27/20

void create() {
    room::create();
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("light", 1);
    set_property("no steal", 1);
    set_short("%^BOLD%^Gold Storage");
    set_long(
@SEETH
%^BOLD%^YELLOW%^You enter the Gold Storage of The Illuminati%^RESET%^
%^BOLD%^%^BLUE%^This looks pretty much like another bank. There is a counter on the far wall, with your bookie behind it. Here is where the guild funds are kept. You can donate gold to help your family financially.
SEETH
    );
    set_smell("default", "You can smell the sweet smell of Gold.");
    set_listen("default", "You hear the sounds of Gold being stacked.");
    set_exits( ([
    "west" : HALL "bank.c",

      ]) );
}
/*
void init() {
    room::init();
    money::init();
}
*/