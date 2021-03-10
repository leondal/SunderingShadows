#include <std.h>
#include "/d/guilds/pack/short.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("no steal", 1);
set_short("%^RED%^The Crimson Hand %^BOLD%^War Room");
    set_long(
@SEETH
%^BOLD%^%^RED%^The Great War Room of The Crimson Hand%^RESET%^
%^BOLD%^%^BLUE%^The room is extremely Large! The most notable thing is the large picture
of a Knight dressed in a suit of %^BLACK%^black armor.%^BLUE%^ He rides a Nightmare and 
looks down upon the room. This must be the infamous %^RED%^Lord Soth.%^BLUE%^ There is a
%^CYAN%^Large Oaken table %^BLUE%^has maps of the land spread all over it...marking's
on each of the maps show maybe old plans, some new plans. There are five
plush chairs around it. A large throne is at the head of the head of the
table, a half empty mug still sits, abandoned from a sudden rush to
battle. the floor is %^RED%^carpeted red,%^BLUE%^ and paintings of each %^YELLOW%^Council member%^BLUE%^
lines the walls. A window out to the south allows clear view of shadow over the smoke and fog.
SEETH
    );
    set_items( ([

      ]) );
    set_exits( ([
      ]) );

    set_smell("default", "The room is filled with the smell of maps and smoke.");
    set_listen("default", "The only sound you hear is your mind at work and the other council members.");

}
