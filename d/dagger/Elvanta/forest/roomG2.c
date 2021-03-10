#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A guard post");
set("day long", "%^ORANGE%^This is a storage room of the guard post.  There is a bed, a small table, and boxes overflowing with papers.  An elf is going through the papers obviously searching for something and not succeeding.%^RESET%^");
set ("night long", "%^CYAN%^This is the storage room of the guard post.  There is a <bed>, a small <table>, and <boxes> overflowing with papers.  By the light of a small globe hanging from a silver chain, an elf is going through the <papers> obviously looking for something and not succeeding.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell the roast from the other room and the musty scent of old papers.");
set_listen ("default", "You hear the papers being rifled through and exclamations of annoyance.");
set_exits (([
"east" : "/d/dagger/Elvanta/forest/roomG1"
]));
set_items
(([
"bed" : "The bed does not look comfortable as it appears to be a slab of wood covered only by blankets",
"table" : "The table is laden with papers and writing materials and looks somewhat untidy.",
"papers" : "The papers have beautiful writing upon them and look to be records of some kind.",
"chairs" : "These chairs look stiff and uncomfortable and very utilitarian.",
"rack" : "This is very plain, no carving nor decorations.  It was made to hold weapons and nothing else.",
"weapons" : "The most prominent weapons are the crossbow and bow.  They appear to be made of hardwood.  The bow is five feet long.  The crossbow has metal fittings.  It looks quite dangerous.  There are also swords made of bright metal and knives with wickedly curved edges.",
"boxes" : "These appear to be made of metal and are overflowing with papers of all shapes and sizes.",
"walls" : "The walls of the post show years of age.  Dirt and grime left over the centuries from a fireplace mark the walls.",
"windows" : "The windows are three feet long and eight inches wide.  Quite obviously they were designed for archers to protect the city."
]));
}
void reset() {
::reset();
if(!present("archer"))
new("/d/dagger/Elvanta/forest/mon/archer")->move(this_object());
}
