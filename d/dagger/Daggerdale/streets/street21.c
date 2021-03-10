#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("A ruined town square");
    set_short("%^BOLD%^%^BLACK%^A ruined town square%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You stand on a ruined street. It was obviously the scene of a %^RESET%^%^RED%^"
"bloody battle%^BOLD%^%^BLACK%^, as the ground is pockmarked with small craters and the fine cobblestones have "
"been mostly ruined. To the east you see the rema%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^ns of a f%^RESET%^"
"%^WHITE%^ou%^BOLD%^%^BLACK%^nt%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^in.%^RESET%^\n\n");
    set_smell("default","%^RESET%^%^ORANGE%^An acrid, burnt smell fills the air.%^RESET%^");
    set_listen("default","%^RESET%^%^GREEN%^It is deathly quiet here.%^RESET%^");

    set_exits(([
      "north" : STREETS"street27",
      "south" : STREETS"street14",
      "east" : FOUNTAIN"fountain",
      "west" : STREETS"street20",
    ]));
}