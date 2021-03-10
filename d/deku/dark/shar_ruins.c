#include <std.h>

inherit ROOM;

void create() {
    ::create();
           set_smell("default","The air is filled with the smell of candles burning.");
           set_listen("default","Sounds reach your ears from the shadows of the dark room.");
           set_name("Ruined Temple of Shar");
           set_short("Ruined Temple of Shar");
           set_long(
@DESC
%^BOLD%^%^BLUE%^The Ruined Temple of Shar%^RESET%^
You are in a small underground temple dedicated to the worship of Shar.  A few candles burn on the altar, but the room is mostly shrouded in darkness.  The altar has nearly been destroyed and there are scorch marks all around it.  It looks like it was set on fire at one point.  The faithful of Shar wait here, safe from the light, until it is night and time for them to do her bidding. Shar's charge to her followers is displayed on one of the walls.
DESC
           );
           set_items(([
              "wall":"You see Shar's charge to her followers on the wall.",
              "charge":"Maybe you should read it.",
           ]));
    set_exits(([
       "out" : "/d/deku/dark/pub"
    ] ));
}
