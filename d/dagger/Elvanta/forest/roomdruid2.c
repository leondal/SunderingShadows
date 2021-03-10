#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("The Druids' Room");
set_long("%^GREEN%^At last, an answer, to how the forest became as it is.  How the homes were moulded from the trees, how the city became hidden.  A small table sits withing the room, a chair placed for comfort and upon the table, a scroll.");
set_smell ("default", "%^MAGENTA%^\nThe faint odour of jasmine and sandlewood mixes in the air, refreshing your weary senses.%^RESET%^");
set_listen ("default", "%^ORANGE%^Only the whispers of time are heard in this room");
set_exits( ([
"north" : "/d/dagger/Elvanta/forest/roomcastle9b",
"east" : "/d/dagger/Elvanta/forest/roomdruid1",
"west" : "/d/dagger/Elvanta/forest/roomcastle1b"
]) );
set_items(([
"couch" : "%^BOLD%^BLUE%^A worn, faded, well used couch takes up the north east corner of the room, it has been used for ages and shows the wear, tear and worry.",
"desk" : "Another work of art, molded from the great trees themselves, by the love the trees hold for the druid",
"chair" : "Worn in spots, but lovingly cared for, the seat of the chair is shiny and smooth, polished by eons of thought",
"table" : "The table is beautiful.  Carvings of unicorns, elves, dwarves, dragons and dreams tell their own story and seem to almost breathe."
]) );
}
void reset() {
::reset();
if(!present("scroll"))
new("/d/dagger/Elvanta/forest/items/scroll")->move(TO);
}
