//updated by Circe 6/2/04
// Thorn@ShadowGate
// 001013
// Tabor
// armor.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_property("noattack",1);
    set_name("Lutgehr Brothers Forge and Smithy");
    set_short("Lutgehr Brothers Forge and Smithy");
    set_long(
@TABOR
%^BOLD%^Lutgehr Brothers Forge and Smithy%^RESET%^
%^CYAN%^This stone building features the fantastic craftsmanship of the 
%^YELLOW%^dwarves%^RESET%^%^CYAN%^.  The walls are smooth and joined together almost 
seamlessly.  Several suits of ornate %^BOLD%^%^WHITE%^full plate armors %^RESET%^%^CYAN%^are displayed on 
stands around the room, and %^ORANGE%^counters %^CYAN%^topped with %^BOLD%^%^BLACK%^black velvet %^RESET%^%^CYAN%^proudly 
support other pieces of %^WHITE%^armors %^CYAN%^and %^YELLOW%^shields%^RESET%^%^CYAN%^.  A round %^WHITE%^stone table %^CYAN%^
near the back of the room seems to be where the dwarven brothers 
conduct their business.  A doorway to the south is open, letting the 
%^RED%^he%^YELLOW%^a%^RESET%^%^RED%^t %^CYAN%^of the %^RED%^forge %^CYAN%^into the shop.  The dwarven brothers, however, 
never seem to notice the heat.  
TABOR
);
    set_smell("default","You smell coal being burned in the forge out back.");
    set_listen("default","You hear the deafening racket of the bellows and hammers.");
    set_exits(([
       "east" : ROOMDIR+"math3",
       "south" : ROOMDIR+"forge"
    ]));
    set_items(([
       ({"stands","full plate armors","armors"}) : "Dunkirk has several "+
          "of what he considers to be his greatest pieces on display.  "+
          "There is a shining suit made entirely of mithral, engraved "+
          "with the image of a phoenix in flight upon its chest.  Beside "+
          "it stands a wickedly fluted suit of darkened armor that must "+
          "make the wearer a fearsome sight indeed.  A suit of light "+
          "chainmail that looks so well made as to be silent is also "+
          "among the pieces displayed.",
       ({"counters","black velvet","velvet","armor pieces","shields"}) : "The "+
          "wooden counters have been covered with black velvet to provide "+
          "an even contrast for the armor pieces displayed there.  Many "+
          "of these look like they are for sale - there are shields and "+
          "various pieces of suits of armor, all of very good quality.",
       ({"table","stone table","round table"}) : "The thick stone table "+
          "is about knee high for most humans, but seems sized just "+
          "right for the dwarven brothers who run this shop.  Two wooden "+
          "chairs are just beside it, but they do not seem to get much "+
          "use."
    ]));
}

void reset(){
    ::reset();
        if(!present("dunkirk"))
            new("/d/darkwood/tabor/mon/dunkirk")->move(TO);
}
