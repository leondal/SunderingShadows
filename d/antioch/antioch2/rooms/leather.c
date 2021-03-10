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
    set_short("%^ORANGE%^The Tannery%^RESET%^");
    set_long(
        "%^WHITE%^This is a quaint little shop. It is rather tiny and crowded with various %^ORANGE%^hides%^WHITE%^ in different stages of tanning. Along the southern wall is a large display of clothing. On the back wall is a long table with cutting instruments and various %^MAGENTA%^dye%^RED%^s%^MAGENTA%^.%^WHITE%^ There also appears to be a %^ORANGE%^b%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^ck %^ORANGE%^d%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^or%^WHITE%^ that the shop keeper probably uses to hang the hides in. The %^ORANGE%^floor%^WHITE%^ is covered in a thick green carpet and sound seems kind of muffled in here because of all the furs and hides. There are a few %^ORANGE%^s%^BOLD%^%^BLACK%^t%^BLACK%^o%^RESET%^%^ORANGE%^ols%^WHITE%^ for customers to sit down on while they decide what they want to buy.
"
        );
    set_smell("default", "The smell of hide is strong here.");
    if (query_night() == 1) {
        set_listen("default", "Everything is quiet at this time of night.");
    }else {
        set_listen("default", "You can hear the muffled sounds of a" +
                   " busy city through the door.");
    }
    set_items(([
                   ({ "hides", "hide", "fur", "furs", "leather" }) : "There are" +
                   " various types of hides and furs stretched out across the room.",
                   "clothing" : "There is a wide variety of leather garments hung" +
                   " on the left wall.",
                   ({ "floor", "carpet" }) : "%^GREEN%^The floor is covered in a thick green" +
                   " carpet.",
                   "tools" : "There are several tools used for cutting and carving" +
                   " different types of hide and furs.",
                   ({ "dye", "dyes" }) : "These dyes come in all sorts of colors and" +
                   " are used to color the leather to the desired shade.",
                   "table" : "The table is covered in hides, tools, and dyes.",
                   ({ "door", "back door" }) : "You can see an area through the door" +
                   " that seems to be used exclusively for storing and tanning" +
                   " hides.",
                   ({ "stool", "stools", "chair", "chairs" }) : "There are several wooden" +
                   " stools that customers can sit on.",
               ]));
    set_exits(([
                   "east" : ROOMS + "street3",
               ]));
    set_door("door", ROOMS + "street3", "east", 0);
}

void reset()
{
    ::reset();
    if (!present("mydan")) {
        new(MONS + "mydan.c")->move(TO);
    }
}
