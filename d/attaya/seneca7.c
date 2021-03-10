#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",1);
    set_terrain(CITY);
    set_travel(FOOT_PATH);
    set_property("training",1);
    set_short("%^RESET%^%^MAGENTA%^Train%^BOLD%^%^WHITE%^i%^RESET%^%^MAGENTA%^ng %^MAGENTA%^hall%^RESET%^");
    set_long("%^RESET%^%^MAGENTA%^Train%^BOLD%^%^WHITE%^i%^RESET%^%^MAGENTA%^ng %^MAGENTA%^hall%^RESET%^
%^RESET%^%^BLUE%^Tall pillars support a series of %^MAGENTA%^arche%^BOLD%^%^WHITE%^s%^RESET%^%^BLUE%^ and braces above you. They have been delicately carved to tell stories of ancient lore, all but forgotten. This is an old training and study chamber. Ancient %^BOLD%^%^WHITE%^s%^RESET%^%^MAGENTA%^cro%^BOLD%^%^WHITE%^l%^RESET%^%^MAGENTA%^ls%^BLUE%^ lie around you, many disintegrating. The air is musty. The sun enters the chamber in ribbons of dusty light. Their paths across the walls of scrolls is marked like a natural sundial in the faded texts as the sunlight has bleached the parchments casting their contents to the depths of time.%^RESET%^");

     set_smell("default","A rush of ancient air assaults you as you enter the dusty training room.");
 
    set_exits(([

       "west" : "/d/attaya/pub",
      "south" : "/d/attaya/seneca3",

    ] ));
    set_items(([
        "arches" : "They are tall marble columns that support heavy arches.",
        "scrolls" : "many have disintegrated to a point beyond reading.  they are written in ancient texts.",
    ] ));
}
