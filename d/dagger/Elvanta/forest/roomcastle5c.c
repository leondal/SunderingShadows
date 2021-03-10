#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("The Dungeon");
set_long("%^BLUE%^Herein lies nightmares.  Rusted chains are attached to dirty dank walls.  Old gratings hang scewed from aged ironworks.  Echoes of screams of terror, horrow and longing seem to ring in your ears.  Black-brown tatters of skin hang from manacles and frightening ugly hooks.  These rooms are leftovers from a time of evil, a time when kindness and hope were words whispered softly in darkened corners.");
set_smell("default", "%^MAGENTA%^The metallic smell cloys in the back of your throat");
set_listen("default", "%^ORANGE%^Echoes only, lost, bereft, haunting");
set_exits( ([
"south" : "/d/dagger/Elvanta/forest/roomcastle1c",
"east" : "/d/dagger/Elvanta/forest/roomcastle4c"
]) );
}
void reset() {
::reset();
if(!present("decapus"))
new("/realms/pegasus/mon/decapus5")->move(TO);
}
