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
    set_short("%^BOLD%^Kitchen of the White Dragon Inn");
    set_long(
        "%^WHITE%^You are in the kitchen of the White Dragon Inn. This is where all the meals that are served in the dining room are created. The chef here is said to be excellent and people have begun coming from all around to taste his cooking. Stews are his specialty, but he can do wonders with poultry as well. The kitchen is kept very tidy. There are several large %^RED%^s%^RED%^t%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^v%^BOLD%^%^BLACK%^es,%^RESET%^%^WHITE%^ some with %^BOLD%^%^BLACK%^p%^BLACK%^o%^BLACK%^ts%^RESET%^%^WHITE%^ of stew on them and others with %^ORANGE%^b%^BOLD%^%^ORANGE%^r%^ORANGE%^e%^RESET%^%^ORANGE%^ad%^WHITE%^ or cakes baking in the oven. People are busily chopping vegetables and washing dishes here while the chef supervises everything. A little window on the north wall lets cool air into this hot room. Through the window you can see a little garden. Freshly picked %^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^erbs%^WHITE%^ and vegetables must come from there.
"
        );
    set_smell("default", "Aromas of all sorts of wonderful dishes" +
              " fill the room.");
    set_listen("default", "The clank and clatter of dishes being moved" +
               " and washed is constant.");
    set_items(([
                   ({ "stove", "stoves" }) : "Several large stoves are heated, some" +
                   " have pots of stew cooking on them while others have breads and" +
                   " cakes baking within.",
                   ({ "pots", "stew", "pot" }) : "Large metal pots are heating on the" +
                   " stoves around the room, they appear to contain different types" +
                   " of stews.",
                   "window" : "There's a little window on the north wall that is" +
                   " open to allow a cool breeze to drift into the room. You can see" +
                   " a little garden area outside of it containing herbs and" +
                   " vegetables.",
                   "floor" : "The hardwood floor is kept very clean.",
                   "vegetables" : "There are chopped vegetables on cutting boards" +
                   " around the room.",
                   ({ "board", "cutting board", "cutting boards" }) : "Wooden cutting" +
                   " boards are scattered about the room, handy for chopping things" +
                   " up on.",
                   ({ "knife", "knives" }) : "Sharp knives can be found around the room," +
                   " some are used for vegetables and others for different types of" +
                   " meat.",
                   ({ "lamp", "lamps", "oil lamps" }) : "Oil lamps are hung around the" +
                   " room to give the cooks some light.",
                   "dishes" : "Some people are busily washing dishes in the sink on" +
                   " the far side of the room.",
                   "garden" : "You can see a garden through the little window. It" +
                   " is small, but grows many herbs and vegetables that are used in" +
                   " the cooking.",
                   ({ "herb", "herbs" }) : "On one of the cutting boards are some" +
                   " freshly chopped herbs.",
                   ({ "oven", "ovens" }) : "Large ovens bake the breads and cakes that" +
                   " are freshly served here.",
                   ({ "bread", "breads", "cake", "cakes" }) : "Numerous breads and cakes" +
                   " are baking in the ovens around the room.",
               ]));
    set_exits(([
                   "west" : ROOMS + "inn2",
               ]));
    set_door("door", ROOMS + "inn2", "west", 0);
}

void reset()
{
    ::reset();
    if (!present("thiliwan")) {
        new(MONS + "thiliwan")->move(TO);
    }
    return;
}
