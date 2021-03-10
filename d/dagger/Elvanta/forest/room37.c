#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The Wrath of Grapes Inn");
set ("day long", "%^ORANGE%^You appear to have come to a small inn.  Sounds of merriment and music can be heard from from the <doors> of the inn.  It looks to be a nice place to rest.%^RESET%^");
set ("night long", "%^CYAN%^You appear to have come to a small inn.  Light shines through the windows and you can hear songs and laughter coming from the small place.  The <doors> are halfway open and the sounds and light welcoming.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou can smell pipe smoke, chimney smoke and odours of food and drink coming from the inn.");
set_listen ("default", "Music, singing and laughter is pouring out of the inn, a welcome sound after all the silence.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/Inn1",
"west" : "/d/dagger/Elvanta/forest/room38",
"southeast" : "/d/dagger/Elvanta/forest/room36"
]));
set_items
(([
"doors" : "The doors of the Inn are carved from the trees themselves.  Brass fittings hold the doors in place and are etched as well, with designs of goblets, decanters and mugs.  Somewhat fitting you think.  The doors swing open to reveal a large room inside the Wrath of Grapes Inn.  Perhaps you could stop for a few.",
"forest" : "This forest feels comfortable, you are not afraid as you walk through the circle of trees.  However, it might not be a bad idea to still be on your guard.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
