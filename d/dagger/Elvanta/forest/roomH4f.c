#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("An elven home, upstairs hallway");
set_long ("%^GREEN%^The hallway is average as hallways go.  It gets you from one place to another.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe scent of the forest reaches you.");
set_listen ("default", "You hear soft music being played upon a wooden flute.");
set_exits( ([
"south" : "/d/dagger/Elvanta/forest/roomH4j",
"west" : "/d/dagger/Elvanta/forest/roomH4e",
"east" : "/d/dagger/Elvanta/forest/roomH4g",
"down" : "/d/dagger/Elvanta/forest/roomH4a"
]) );
set_items(([
]) );
}
