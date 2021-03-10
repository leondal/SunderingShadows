
#include <std.h>
#include "/d/guilds/pack/short.h"
#include <arena.h>
inherit ARENAENTER;

void create(){
    :: create();

    set_short("Arena healing room.");
    set_long(
      "You are in the entrance to the arena.  type 'enter safe' to enter the arena for mock combat, or 'enter live' to enter without any safeguards."
    );

    set_items(([
      ]));

    set_exits(([
      "down" : "/d/guilds/pack/hall/ghall.c",
      ]));
    set_smell("default", "It smells of blood here.");
    set_listen("default","You can hear the soothing sounds made by the water in the pool.");
    set_enter_room("/d/guilds/pack/arena/arena1.c");
}
