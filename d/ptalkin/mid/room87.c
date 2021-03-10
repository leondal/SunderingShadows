#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^The trees themselves prevent you seeing far ahead.  Their great girth ranges from three to ten feet in diameter and their huge roots stretch out from the trunks like mammoth fingers digging their way relentlessly into the earth of the forest floor.");
set_smell("default", "%^BOLD%^BLUE%^\nYou smell the earthy scents of damp earth and leaves.");
set_listen("default", "%^CYAN%^Fallen leaves and twigs are soaked with a heavy dew making a cushion that masks your passage.");
set_exits (([
"northwest" : PMID+"room88.c",
"southwest" : PMID+"room86.c"
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
