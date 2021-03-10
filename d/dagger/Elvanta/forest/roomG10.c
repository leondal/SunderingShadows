#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A storage room");
set ("day long", "%^ORANGE%^This storage room is full of arms and armour.  The most prominent weapons being the <long bow> and the <crossbow>.  Assorted <swords> and <knives> complete the inventory.%^RESET%^");
set ("night long", "%^CYAN%^This storage room is full of arms and armour.  The most prominent weapons being the <long bow> and the <crossbow>.  Assorted <swords> and <knives> complete the inventory.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell only the oil which is used for honing weapons.");
set_listen ("default", "You hear small animals running through the forest outside.");
set_exits (([
"east" : "/d/dagger/Elvanta/forest/roomG9"
]));
set_items
(([
"long bow" : "These bows are five feet long and made of hardwood.  They are strung and instantly available for use.",
"crossbow" : "This weapon is a bit more exotic that the long bow.  It is also made of hardwood but has metal fittings and looks to be quite dangerous in the right hands.",
"swords" : "Ranging from two to four feet long, these swords are a joy to behold.  Made of the finest steel they are etched along the blade showing designs of ivy.  The hands of the wielder are protected by curved metal reaching over the hand to the handle of the sword.  The handle itself is made of wood, wrapped by braided cord.",
"knives" : "These knives are wicked.  Honed edges glimmer in the light.  As with the swords, the curved blade is joined by a handle wrapped in braided cord."
]));
}
void reset(){
::reset();
if(!present("archer"));
new("/d/dagger/Elvanta/forest/mon/archer")->move(this_object());
}
