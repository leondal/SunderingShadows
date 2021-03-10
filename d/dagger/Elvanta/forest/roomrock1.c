#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A dark, still moat around a castle");
set_long("%^CYAN%^You stand upon a rock of granite, perhaps three feet by four feet wide.  Something seems to be swirling around you in the waters at your feet.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell stale water, reeds and some unknown creatures perhaps.");
set_listen("default", "You hear the occasional cricket, a slithering sound from some animal close by, and your own breath echoing off the banks of the moat.");
set_exits (([
"down" : "/d/dagger/Elvanta/forest/roommoat3"
]));
set_items
(([
]));
}
void reset(){
::reset();
if(!present("amphisbaena"))
new("/d/dagger/Elvanta/forest/mon/amphisbaena")->move(this_object());
}
