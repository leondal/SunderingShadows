#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("A trail through Peth Forest");
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_climate("temperate");
    set_property("light", 2);

    set_short("%^BOLD%^You are on a trail.%^RESET%^");

    set_long("%^BOLD%^You are on a small trail which cuts through the woods.\n%^RESET%^"
        "To the south you see the %^GREEN%^Peth Forest%^RESET%^, a dark and dangerous "
        "assortment of trees and brush. From where you walk you can also see "
        "a meadow, with its grasses blowing strongly in the wind. Off to the "
        "west rise the Thoradin Mountains, the majestic range which splits this "
        "continent in two. While you are currently headed in the direction of "
        "the %^BLUE%^River of Sorrows%^RESET%^.");

    set_exits(([
        "west":BO+"path34",
        "south":BO+"room40",
        "east":BO+"path2"
             ]));

    set_smell("default","The smell of the wild pervades your senses.");
    set_listen("default","You can hear the ravens cawing and the river rushing.");

}