#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^You leave the small town behind you for the peace and sanctuary of the forest.  As you stop to look out upon the forest, you see the massive oaks stand out evenly, endlessly before you, their great mass an impenetrable wall of damp, scarred bark on wide, deep-rooted bases.  The trees have stood there for countless ages of man and will very likely be there until the destruction of the land itself.");
set_smell("default", "%^BOLD%^BLUE%^Damp earth and rotting vegetation greets your senses.");
set_listen("default", "%^CYAN%^Droning insects, the scrabble of little claws and the wind through great boughs carresses your ears.");
set_exits (([
"northeast" : PMID+"room87.c",
"south" : PMID+"room85.c"
]));
set_items(([
"town" : "A small town, ramshackle for the most part",
"trees" : "Mostly oaks, too large to guess how tall they are, cover this area, but other trees are found, ash, chestnut, willow.",
"path" : "The pathway now begins to become softer, easier on your feet as evergreen needles accumulate.",
"forest" : "Lush green canopies of leaves cover the horizon.",
"oaks" : "Massive, giant sized, huge, whatever words you may use to describe grandeur would fit here.",
"foliage" : "Small plants, creeping ivies and wild flowers make up the foliage under the trees"
]));
}
