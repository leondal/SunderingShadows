#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("Castle Moirbin, A sitting room");
set_long("%^YELLOW%^The sitting room is comfortable.  The smooth walls glow from eons of polishing.  A small fireplace sits within the east wall and has comfortable chairs and small tables drawn up close.  A harpsichord sits in the northeast corner while books, scrolls and paintings half finished lie scattered around the room.");
set_smell("default", "%^MAGENTA%^\nThe fireplace gives off the smell of burning wood");
set_listen("default", "%^GREEN%^Crackling, spitting and snapping sounds comes from the fire");
set_exits( ([
"south" : "/d/dagger/Elvanta/forest/roomcastle4b",
"west" : "/d/dagger/Elvanta/forest/roomcastle6b",
"southwest" : "/d/dagger/Elvanta/forest/roomcastle9b",
"down" : "/d/dagger/Elvanta/forest/roomcastle5"
]) );
set_items(([
"fireplace" : "The fireplace is set into the wall with brick surrounding the fire itself.  A cheery fire burns within",
"harpsichord" : "An old, battered and beloved harpsichord wails patiently for the hands to bring it to life",
"chairs" : "The chairs are overstuffed, somewhat worn and exceedingly comfortable",
"tables" : "Small tables are placed here and there, holding cups, jugs, books and scrolls",
"books" : "Books, old, new and ancient lay upon the tables with subjects covered from the arcane to zenoas",
"scrolls" : "Many crumbling yellowed pieces of parchment lay here for any reader of old",
"paintings" : "Someone has an eye for beauty, as shown by the half finished paintings at rest around the room.  Dragons, flowers and trees are partially brought to life, waiting to be completed"
]) );
}
void reset() {
::reset();
if(!present("mika"))
new("/d/dagger/Elvanta/forest/mon/mika")->move(TO);
}
