#include <std.h>
#include "/d/guilds/pack/short.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("no steal", 1);
set_short("%^BOLD%^%^BLUE%^The Great Hall of the Illuminati");
    set_long(
@SEETH
%^BOLD%^%^RED%^You are standing in the Great Hall of the Illuminati%^RESET%^
%^MAGENTA%^As you enter the %^RED%^Great Hall%^MAGENTA%^, the enclosed feeling of the corridor leaves you. Above you is the Midnight sky, and the mystical faerie fire on some of the walls are the only light source throughout the Great Hall. There are many confortable wooden benches placed around the Hall for members to relax. To the west you can hear the moanings of the injured as well as the sounds of warriors training for battle.
SEETH
    );
    set_items( ([

      ]) );
    set_exits( ([
        "south" : HALL "hall.c",
        "east" : HALL "donate.c",
        //"west" : HALL "recovery.c",
        "stairs" : ARENADIR "heal.c",
      ]) );

    set_smell("default", "You can smell blood and death throughout the hall.");
    set_listen("default", "The Hall is filled with many conversations and deathly sounds.");

}
