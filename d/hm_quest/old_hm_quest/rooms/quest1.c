#include <std.h>
inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create(){
:: create();
set_property("light", 2);
set_property("indoors", 0);
set_short("%^ORANGE%^A pier");
set_long("%^ORANGE%^You have stepped from the boat onto a pier of wooden planks.  The pier is somewhat rickety and rotting, and you are not sure if it will hold your weight let alone the members of the rest of your party.  Small stains of rust red drops, signal that this area is dangerous to your well-being.  Off to the left and right is a sandy beach.  Small plants struggle to hold onto life within the dry and unforgiving sand.  Some type of bird is circling overhead as if waiting for dinner.");
set_smell("default", "%^CYAN%^\nThe smell of sea, warm winds and rotting wood assails your senses.");
set_listen("default", "%^BLUE%^You can hear the crash of the waves, upon the pier and the odd bird screeching overhead.");
set_exits( ([
    "southeast" : "/d/hm_quest/rooms/quest2"
]) );
set_items(([
"pier" : "The pier appears to be several hundred years old, as the pilings are rotten and the planks teeter as you tread upon them",
"beach" : "A nice looking beach of sand and small plants appears to a welcome sight for any vacationer",
"plants" : "Small bits of crabgrass and the occaisional struggling bush try to survive on just sand and sky.",
"bird" : "A bird, with red wings, and a black beak circles above you screeching with joy or hatred, it's hard to tell",
"sand" : "Miles upon miles of golden sand is to the left and right of you."
]) );
}
