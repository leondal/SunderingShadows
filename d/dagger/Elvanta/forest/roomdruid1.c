#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("The Druids' Room");
set_long("%^GREEN%^This is the resting place for the druids of Elvanta.  Herein lies a simple couch for rest, a desk for writing, and a chair for thought.  All of these are crafted by the love the druid holds for this forest realm, of the realm, and by the realm.  So you have the answer as to how the trees formed the city, by the love of the tree druid.");
set_smell ("default", "%^MAGENTA%^\nThe faint odour of jasmine and sandlewood mixes in the air, refreshing your weary senses.%^RESET%^");
set_listen ("default", "%^ORANGE%^Only the whispers of time are heard in this room");
set_exits( ([
"west" : "/d/dagger/Elvanta/forest/roomdruid2",
"north" : "/d/dagger/Elvanta/forest/roomcastle4b"
]) );
set_items(([
"couch" : "%^BOLD%^BLUE%^A worn, faded, well used couch takes up the north east corner of the room, it has been used for ages and shows the wear, tear and worry.",
"desk" : "Another work of art, molded from the great trees themselves, by the love the trees hold for the druid",
"chair" : "Worn in spots, but lovingly cared for, the seat of the chair is shiny and smooth, polished by eons of thought"
]) );
}
void reset() {
::reset();
if(!present("wirinth"))
new("/d/dagger/Elvanta/forest/mon/wirinth")->move(TO);
}
