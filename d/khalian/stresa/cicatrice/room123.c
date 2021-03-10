
//rooms by the house of Svaha

#include <std.h>
inherit ROOM;

void create() {
::create();

set_property("light", 2);
set_property("indoors", 0);

set_short("%^ORANGE%^The Cicatrice Desert");
set_long("%^ORANGE%^You are in a desert, surrounded by sand and heat.  The
first question you ask yourself is, where am I, the second question you 
ask is why am I and the third question is what Gods did I offend to get
here.");


set_smell("default", "%^CYAN%^You think perhaps you could use a bath, a
very long one");
set_listen("default", "%^CYAN%^A cry reaches your ears, but you cannot 
make out whether it was a cry from an animal or something else 
altogether.");

set_exits
(([
"north" : "/d/khalian/stresa/cicatrice/room118",
"south" : "/d/khalian/stresa/cicatrice/room126",
"southeast" : "/d/khalian/stresa/cicatrice/room127"
]));

set_items
(([
"desert" : "A desolate and sparsely occupied or unoccupied area."
]));

}
