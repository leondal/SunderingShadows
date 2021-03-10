#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A guard post");
set ("day long", "%^ORANGE%^This guard post is fairly barren, a <table> and two <chairs> and a <rack> for <weapons> are all that appear here.  The <walls> and ceiling are made of wood apparently molded from the tree.  Slit <windows> are spaced approximately eight feet apart.%^RESET%^");
set ("night long", "%^CYAN%^This guard post is fairly barren, a <table>, and two <chairs> and a <rack> for <weapons> are all that appear here.  The <walls> and ceiling are made of wood apparently molded from the tree.  Slit <windows> are spaced approximately eight feet apart.  The only light you see is from the globe hanging from the walls by a long silver chain.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell only the oil which is used for honing weapons.");
set_listen ("default", "You hear small animals running through the forest outside.");
set_exits (([
"east" : "/d/dagger/Elvanta/forest/room68",
"west" : "/d/dagger/Elvanta/forest/roomG10"
]));
set_items
(([
"bed" : "The bed does not look comfortable as it appears to be a slab of wood covered only by blankets",
"table" : "The table is four feet by four feet and very plain, however, it sits upon a carved base.  The carving is of a lily, the flat of the table lying upon open petals.  What artwork and love has gone into such a simple thing.",
"papers" : "The papers have beautiful writing upon them and look to be records of some kind.",
"chairs" : "These chairs look stiff and uncomfortable and very utilitarian.",
"rack" : "This is very plain, no carving nor decorations.  It was made to hold weapons and nothing else.",
"weapons" : "The most prominent weapons are the crossbow and bow.  They appear to be made of hardwood.  The bow is five feet long.  The crossbow has metal fittings.  It looks quite dangerous.  There are also swords made of bright metal and knives with wickedly curved edges.",
"boxes" : "These appear to be made of metal and are overflowing with papers of all shapes and sizes.",
"walls" : "The walls of the post show years of age.  Dirt and grime left over the centuries from a fireplace mark the walls.",
"windows" : "The windows are three feet long and eight inches wide.  Quite obviously they were designed for archers to protect the city."
]));
}
void reset(){
::reset();
if(!present("archer"));
new("/d/dagger/Elvanta/forest/mon/archer")->move(this_object());
}
