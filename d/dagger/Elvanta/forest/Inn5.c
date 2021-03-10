#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property ("indoors", 1);
set_short ("The Wrath of Grapes Inn, Storage Room");
set_long ("%^ORANGE%^As you come down the stairs, dim light allows you only to see barrels of <wine>, barrels of pipe <tobacco>, <shelves> littered with <foodstuffs> and a large food <bowl> and water <dish>.%^RESET%^");
set_smell ("default", "%^RED%^Musty odours mingle with tobacco and wine and a sort of wet fur smell.  YECHHHH!%^RESET%^");
set_listen ("default", "Soft scratches reach your ears, you wonder what is here, hiding in the dim light.");
set_exits (([
"up" : "/d/dagger/Elvanta/forest/Inn1"
]));
set_items
(([
"wine" : "The wine is a good vintage made ten years ago by men.  It has been allowed to age well.",
"tobacco" : "Tobacco leaf from the hobbits best year is stored here.  Excellent quality.",
"foodstuffs" : "Potatoes, onions, other root vegetables are stored here in the darkness.",
"shelves" : "Shelves line the walls here, four feet deep and reach to the ceiling.",
"bowl" : "A bowl big enough for a small child to bathe in is here.  Scraps of roasted something, potatoes and some gravy fill the bowl.",
"dish" : "This dish is filled to the brim with water, some spilled over the side.  From the size of this dish, you do not want to meet the user."
]));
}
void reset(){
::reset();
if(!present("bugbear"))
new("/d/dagger/Elvanta/forest/mon/bugbear")->move(TO);
}
