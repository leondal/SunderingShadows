//mage_shaundakul.c - reward for Riddle Quest. Cythera 8/05
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("jacket of gloom");
	set_id(({ "robe","jacket","silk jacket","dark black jacket","jacket of gloom" }));
	set_obvious_short("%^BOLD%^%^BLACK%^A dark black silk jacket%^RESET%^");
	set_short("%^BOLD%^%^MAGENTA%^J%^RESET%^%^RED%^a%^BOLD%^%^MAGENTA%^"+
		"c%^RESET%^%^RED%^k%^BOLD%^%^MAGENTA%^e%^RESET%^%^RED%^t"+
		"%^BOLD%^%^BLACK%^ of Gloom%^RESET%^");
	set_long(
@CYTHERA
%^BOLD%^%^BLACK%^Shaped out of silk, this half-jacket has been dyed a deep black shade.  The jacket is cut full in the chest and sleeves, giving plenty of room for the wearer.  Flowing lines in %^BOLD%^%^MAGENTA%^mauve%^BOLD%^%^BLACK%^ and %^RESET%^%^RED%^dark red%^BOLD%^%^BLACK%^ cut through the black silk creating antler like shapes across the fabric.  The inside of the jacket is lined with %^BOLD%^%^MAGENTA%^mauve%^BOLD%^%^BLACK%^ silk, giving a bright flash of color as one moves about.  A single large button made from a black antler rests at the neck of the jacket, serving at the only fastener.  Inside the jacket a pair of pockets have been sewn into the lining, allowing one to keep treasured items close.%^RESET%^
CYTHERA
	);
	set_lore(
@CYTHERA
The Gloomwings, or Glooms as they were known, was a cabal of dark mages dedicated to Beshaba.  The Glooms worked to spread the misfortunes of The Maid of Misfortune across the lands.  Known for their colorful jackets and gloomwing stylized masks they wore the Gloomwings often came into frequent battles with the followers of Tymora.  Most people tried to run the other way when they saw a Gloom in public, not wishing in incur the touch of Black Bess.
CYTHERA
	);
	set_property("lore",12);
	set_remove("%^CYAN%^You slip out of the jacket, knowing the "+
		"time to spread Beshaba's misfortunes will come again.");
}
