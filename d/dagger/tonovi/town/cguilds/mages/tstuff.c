//updated by Circe 5/31/04 with color, etc.
// Wizbam Redux, Tower of the Arcane, Tabor
// Thorn@ShadowGate
// 010306
// Tabor
// tfloor4.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
    ::create();
    set_name("Wizbam Redux, Tower of the Arcane, Tabor");
    set_short("Wizbam Redux, Tower of the Arcane, Tabor");
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_long(
"%^BOLD%^Wizbam Redux in the Tower of the %^CYAN%^A%^YELLOW%^r"+
"%^CYAN%^c%^YELLOW%^a%^CYAN%^n%^YELLOW%^e%^WHITE%^, Tabor%^RESET%^\n"+
"%^CYAN%^Those who are familiar with Wizbert, part-owner of the "+
"%^BOLD%^Mage Tower %^RESET%^%^CYAN%^in Shadow, know that he is "+
"wonderfully rich.  What isn't known is that he got his start in "+
"Tabor in this tower, selling backups and books from a small "+
"storefront.  This is that very store, and after moving to Shadow, "+
"he put his talented and similarly weird son Wizbam in charge of the "+
"place.  Its not much to look at really, but it gets quite a bit of "+
"business.  Ask a mage sometime just how annoyed they'd be if they lost "+
"their book and had no backup.  (We suggest you do it from inside an "+
"anti-magic shell, just in case they construe that as a threat.)\n\n"+
"%^RESET%^<help store> will give you help on how to use the store.\n"
	);
    set_light(2);
    set_indoors(1);
    set_smell("default","You smell old, dusty parchment.");
    set_listen("default","You hear the mumblings of apprentices "+
        "working in the back of the store.");
     set_exits( ([
        "north" : ROOMDIR+"tfloor4",
        ]) );
}

void reset()
{
    ::reset();
    if(!present("wizbam"))
        find_object_or_load(MONDIR+"wizbam")->move(TO);
}
