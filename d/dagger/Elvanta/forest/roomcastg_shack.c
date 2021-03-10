#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A guard post");
set ("day long", "%^ORANGE%^As you look around this guard post, you notice just how neat and tidy everything appears.  The room has <chairs>, a <table> with dinner remains upon it and a <rack> where <weapons> are stored.  The <walls> and ceiling are made of wood apparently molded from the tree itself.  Slit <windows> are spaced eight feet apart.");
set ("night long", "%^CYAN%^As you look around this guard post, lit by globes hanging from silver chains, you notice how neat and tidy everything appears.  The room has <chairs>, a <table> with dinner remains upon it and a <rack> whre <weapons> are stored.  The <walls> and ceiling are made of wood apparently molded from the tree itself.  Slit <windows> are spaced eight feet apart.");
set_smell ("default", "%^MAGENTA%^You can smell roast of some sort coming from the table.");
set_listen ("default", "You hear only papers being shuffled and the odd excalmation of disgust.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/room128",
"east" : "/d/dagger/Elvanta/forest/roomcastg_shack2",
"southwest" : "/d/dagger/Elvanta/forest/room127"
]));
set_items
(([
"chairs" : "These chairs look stiff and uncomfortable and very utilitarian.",
"table" : "The table is four feet by four feet and stands upon a carved base.",
"rack" : "This is very plain, no carving nor decorations.  It was made to hold weapons and nothing else.",
"weapons" : "The most prominent weapons are the crossbow and bow.  They appear to be made of hardwood.  The bow is five feet long.  The crossbow has metal fittings.  It looks quite dangerous.  There are also swords made of bright metal and knives with wickedly curved edges.",
"walls" : "The walls of the post show years of age.  Dirt and grime left over the centuries from a fireplace mark the walls.",
"windows" : "The windows are three feet long and eight inches wide.  Quite obviously they were designed for archers to protect the city."
]));
}
void reset(){
::reset();
if(!present("archer"));
new("/d/dagger/Elvanta/forest/mon/archer")->move(TO);
if(!present("castleguard"));
new("/d/dagger/Elvanta/forest/mon/castleguard")->move(TO);
}
