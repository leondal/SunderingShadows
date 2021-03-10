#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set ("day long", "%^ORANGE%^You are still travelling high in the redwoods through the city of Elvanta.  You try to look down, but the boughs of the immense trees get in the way.  To your right is another guard post. To the north and south of you only more pathway.  Squirrels, birds and assorted wildlife abounds.%^RESET%^");
set ("night long", "%^CYAN%^You are still travelling high in the redwoods through the city of Elvanta.  By the light of the globes lighting your way you try to look down, but only shadows are seen.  To the right of you is another guard post and to the north and south more pathway.  Owls, raccoons, and other night life abounds in the forest.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou can smell odours of cooking and smoke from the chimneys.");
set_listen ("default", "You hear the rustling of the wind through the tres, and soft murmurs of voices.");
set_exits (([
"east" : "/d/dagger/Elvanta/forest/roomG5",
"north" : "/d/dagger/Elvanta/forest/room28",
"southwest" : "/d/dagger/Elvanta/forest/room26"
]));
set_items
(([
"globes" : "You see great round glass globes hung in delicate silver chains.  They may be used to light the way on a dark night.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"branches" : "The branches can be walked upon they are so wide.  They travel through the forest like a maze.  It looks as though somehow they were coaxed to form roadways for the elves who live here.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"walkway" : "As you travel along the walkway you can't help notice how well it is built.  There is no swaying or shaking of the walkway.  The trees themselves seem to have molded the walkway and it is as sturdy as the ground below.",
"building" : "You look ahead and see a small building within the trees.  It looks like a guard post, perhaps.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
