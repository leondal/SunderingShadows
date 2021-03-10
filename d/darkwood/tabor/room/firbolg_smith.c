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
    set_name("Anvil of the Colossus");
    set_short("Anvil of the Colossus");
    set_long(
@TABOR
%^BOLD%^Anvil of the Colossus%^RESET%^
%^CYAN%^Unlike the other buildings of Tabor, this one is most definitely 
built to accommodate one of a giant's stature.  The ceilings seem 
vaulted, reaching heights of twenty feet at the center, most 
unusual for a forge.  The rosy glow of the %^RED%^fire %^CYAN%^coming from the 
northeastern corner fills the room, making the place almost 
unbearably hot.  Suits of %^BOLD%^%^WHITE%^armor %^RESET%^%^CYAN%^are displayed on stands around 
the shop, all of them crafted by a master.  Both %^RESET%^metal %^CYAN%^and 
%^ORANGE%^leather %^CYAN%^armors stand near %^ORANGE%^shelves %^CYAN%^of folded %^RESET%^cotton robes %^CYAN%^in 
varying colors.  %^YELLOW%^Giant-sized weapons %^RESET%^%^CYAN%^are on display as well, 
well-made but not ostentatious.  It seems clear the shopkeeper 
has only one type of buyer in mind - the rather large type.  
TABOR
);
    set_smell("default","You smell the almost acrid scent of coal burning.");
    set_listen("default","You hear the roaring of hammers amid the talk of customers.");
    set_exits(([
       "west" : ROOMDIR+"math8"
    ]));
    set_items(([
       ({"ceiling","ceilings"}) : "Far from the dwarven forge "+
          "also in Tabor, this particular smithy features a "+
          "twenty foot domed ceiling that allows ample headroom "+
          "for the massive smith.",
       ({"fire","forge"}) : "In the northeastern corner of the "+
          "room stands the forge proper, featuring a firepit "+
          "encased in stone and sporting several different "+
          "sized anvils and hammers, among other tools.  Leather"+
          "working equipment can be seen as well.",
       ({"armor","armors","leather","metal"}) : "Both the leather "+
          "and metal armors seem meticulously made with attention "+
          "being paid to every functional detail.  While not overly "+
          "ornate, the armors are exquisite in their own right.",
       ({"robe","robes","shelves"}) : "Narrow shelves feature "+
          "folded robes in varying colors, all roughly the same "+
          "size and made to be worn beneath the suits of armor "+
          "as padding.",
       ({"weapon","weapons"}) : "Weapons ranging from swords to "+
          "simple clubs stand on display, ready to be bought.  "+
          "Each looks to be well-made and sturdy."
    ]));
}

void reset(){
    ::reset();
        if(!present("niall"))
            new(MONDIR+"niall")->move(TO);
}
