//updated by Circe 6/2/04 for weapons in Tabor
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
seamlessly.  Beautiful %^MAGENTA%^mahogany racks %^CYAN%^stand around the room, supporting 
%^BOLD%^weapons %^RESET%^%^CYAN%^of all types.  Many of these are quite ornate and heavily carved, 
and it seems clear that these are more displays of craftsmanship than 
for sale.  The case near the %^ORANGE%^counter %^CYAN%^in the southern part of the room 
holds the weapons that are for sale.  A doorway to the west is open, 
letting the %^RED%^he%^YELLOW%^a%^RESET%^%^RED%^t %^CYAN%^of the %^RED%^forge %^CYAN%^into the shop.  The dwarven brothers, 
however, never seem to notice the heat.  
TABOR
);
    set_smell("default","You smell coal being burned in the forge out back.");
    set_listen("default","You hear the deafening racket of the bellows and hammers.");
    set_exits(([
       "north" : ROOMDIR+"math3",
       "west" : ROOMDIR+"forge"
    ]));
    set_items(([
       ({"stands","weapons"}) : "Naldek is the master weaponsmith of the "+
          "Lutgehr brothers, and several of his most extraordinary pieces "+
          "have been put on display in elegant mahogany racks.  Most "+
          "often, you see ornate hammers and axes, although there are a "+
          "few large swords as well.  Several of these have carved "+
          "handles of hardwoods and many have been set with gems.",
       ({"counter","wooden counter"}) : "This low counter is kept "+
          "clear of clutter and has been highly varnished.  A "+
          "case is right in front of it, displaying the weapons "+
          "for sale.",
       ({"case","weapons case"}) : "This wooden case has no top or "+
          "front, instead left open so people can try the weapons "+
          "hanging from the racks inside.  The weapons here are less "+
          "ornate and more practical than those displayed around the "+
          "shop but they are no less well-made."
    ]));
}

void reset(){
    ::reset();
        if(!present("naldek"))
            new("/d/darkwood/tabor/mon/naldek")->move(TO);
}
