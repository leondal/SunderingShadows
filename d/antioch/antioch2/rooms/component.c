#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_short("%^BOLD%^The Dragon's Tail");
    set_long(
        "%^WHITE%^The shop is filled to capacity with all sorts of strange items. There are hundreds of jars of strange %^GREEN%^herbs%^WHITE%^ and odd %^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^q%^CYAN%^u%^RESET%^%^CYAN%^ids,%^WHITE%^ different %^RED%^anim%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^l%^WHITE%^ body parts and %^BOLD%^%^BLACK%^min%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^rals,%^RESET%^%^WHITE%^ some crushed into a fine powder. A musky odor hangs in the air, other strange scents, some unpleasant, can be faintly detected. The whole store is simply filled with %^ORANGE%^sh%^BOLD%^%^BLACK%^e%^BLACK%^l%^BLACK%^v%^RESET%^%^ORANGE%^es%^WHITE%^ that are piled with strange and exotic items, there doesn't seem to be any sort of method to the filing system. The %^CYAN%^f%^BLUE%^loor%^WHITE%^ is covered in a a dark blue carpet that looks like it needs to be cleaned. At the back of this darkly lit store is a little desk that is covered in scrolls. Music is playing in here, but you can't tell where it's coming from, must be some sort of magic.
"
        );
    set_smell("default", "The scents of strange herbs and other" +
              " musty unknown items assualt your nose.");
    set_listen("default", "The melody of a gentle song echoes through" +
               " the air.");
    set_items(([
                   ({ "floor", "carpet" }) : "%^BLUE%^The floor is covered in a very" +
                   " thick dark blue carpet that hasn't been cleaned in some time.",
                   "shelves" : "The shelves are packed full of all sorts of mysterious" +
                   " items, herbs, animal parts, and minerals. There doesn't appear" +
                   " to be any sort of organization to it at all.",
                   ({ "herb", "herbs", "strange herbs" }) : "There are odd herbs of every" +
                   " shape and color here, some fairly fresh and others are old and" +
                   " dried, they range in color from white to a dark purple.",
                   ({ "liquid", "odd liquid", "liquids" }) : "Oddly shaped containers" +
                   " and jars hold all sorts of liquids, some of them are bubbling" +
                   " and others sit still. A few bottles have stoppers to them while" +
                   " others are open. You can't begin to imagine what all of these" +
                   " are for.",
                   ({ "mineral", "minerals", "powder", "fine powder" }) : "Several types" +
                   " of minerals have been crushed into powders, some grainy and" +
                   " others very fine. A few minerals are left whole or in chunks.",
                   ({ "animal bodies", "animal parts" }) : "Different bits and pieces" +
                   " of animals, lizards, and other unidentifiable creatures are" +
                   " stacked on the shelves. Some are in jars, containers, or sacks," +
                   " but others are just sitting on top of the shelves.",
               ]));
    set_exits(([
                   "north" : ROOMS + "street19",
               ]));
    set_door("walnut door", ROOMS + "street19", "north", 0);
}

void reset()
{
    ::reset();
    if (!present("helirin")) {
        new(MONS + "helirin")->move(TO);
    }
}
