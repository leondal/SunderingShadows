//%^BOLD%^NOTE: %^RESET%^This was originally meant to be a 
//mirror but was taken out when the Imms decided not to 
//put mirrors in temples. ~Circe~ 9/11/05
// A mirror [meant as a target for the magic mirror spell]
// Place this in mage towers, and other places of magical
// artifice.  
// Thorn@ShadowGate
// 010103
// mirror.c

#include <std.h>

inherit OBJECT;

void create() {
	::create();
	set_name("table");
	set_id(({"table","round table"}));
	set_short("%^BOLD%^%^BLACK%^Obsidian round table%^MAGENTA%^");
	set_property("no animate", 1);
    set_long("%^BOLD%^%^BLACK%^This luxurious round table rises "+
       "from a central pillar that is anchored to the floor "+
       "somewhere beneath the murky darkness underfoot.  A "+
       "%^RESET%^%^MAGENTA%^ring %^BOLD%^%^BLACK%^of %^RESET%^"+
       "%^MAGENTA%^deep purple %^BOLD%^%^BLACK%^pine surrounds "+
       "the glossy obs%^WHITE%^i%^BLACK%^d%^RESET%^i%^BOLD%^a"+
       "%^BLACK%^n disk set in its center.  The surface of the "+
       "obsidian is absolutely flawless and refl%^RESET%^e%^BOLD%^"+
       "%^BLACK%^ct%^WHITE%^i%^BLACK%^ve like a pitch black "+
       "%^RESET%^mirror%^BOLD%^%^BLACK%^.  Surrounding the table "+
       "are a collection of %^RESET%^%^MAGENTA%^matching chairs"+
       "%^BOLD%^%^BLACK%^, %^RESET%^%^MAGENTA%^dark purple pine "+
       "%^BOLD%^%^BLACK%^with glossy black cushions.");
	set("value", 1001);
	set_weight(100000);
	set_no_clean(1);
}

int get() { return 0; }

int drop() { return 1; }
