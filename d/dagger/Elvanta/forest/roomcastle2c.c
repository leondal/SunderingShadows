#include <std.h>
#include "/d/shadow/room/city/melnmarn.h"
inherit ROOM;

void create() {
  ::create();
    set_properties((["light":2, "indoors":1]));
set_short("Weapons Storage");
set_long("%^BOLD%^RED%^This is where the arms and armour for the protectors of Elvanta reside.");
set_exits(([
"north" : "/d/dagger/Elvanta/forest/roomcastle4c",
"west" : "/d/dagger/Elvanta/forest/roomcastle1c",
"east" : "/d/dagger/Elvanta/forest/roomcastle3c",
"northwest" : "/d/dagger/Elvanta/forest/roomcastle5c"
]));
}
