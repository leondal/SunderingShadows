// new stable for Azha, including a few exotic desert animals. Nienne, 10/04. //

#include <std.h>
inherit STABLE;
#define HOR "/d/azha/town/mounts/"+

void create() {
    ::create();
    set_light(2);
    set_indoors(1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_name("azha stables");
    set_short("Azha Stables");
    set_long("%^WHITE%^%^BOLD%^Azha Stables%^RESET%^\n"
"This great, high-roofed building has been constructed to house several%^BOLD%^%^BLUE%^ "
"ex%^GREEN%^ot%^BLUE%^ic%^RESET%^ animals from distant locations.  The building's single doorway faces to "
"the east, onto the busy street outside.  Only a few %^ORANGE%^stalls%^RESET%^ line the back wall, each of "
"quite grand size, and securely enclosed to restrain whatever is kept inside them.  The%^BLACK%^%^BOLD%^ "
"stone floor%^RESET%^ is covered in dust and straw, and scattered with oats and patches of manure.  "
"A polished %^RED%^wooden counter%^RESET%^ stands near the front of the building, with a%^WHITE%^%^BOLD%^ "
"large sign%^RESET%^ set atop it.\n");
    set_items(([
    "counter" : "The counter is polished and clean, despite the somewhat messy appearance of the rest of the "
"building.  A %^WHITE%^%^BOLD%^large sign%^RESET%^ is sitting atop it.",
    "floor" : "The %^ORANGE%^dirt floor%^RESET%^ of this building is covered almost entirely with straw and "
"dust, and a few piles of manure.  The owners seem to go to at least some effort to clean it, but it seems "
"impossible to keep it that way for long.",
    "stalls" : "The five large, single stalls against the back wall are well-enclosed, leaving to curiosity "
"what sort of animals might be kept inside."
    ]));
    set_smell("default","The thick scent of animals, hay and sweat mingle with the dry, dusty air.");
    set_listen("default","The sounds of the animals mix with the loud bustle of the town outside.");

    set_animal(({"stallion","camel","tiger","elephant"}),({HOR"stallion",HOR"camel",HOR"tiger",HOR"elephant"}));
    set_animal_price(({"stallion","camel","tiger","elephant"}),({500,1000,2500,9500}));
    set_stalls(10);
    ::fill_stalls();
    set_exits( ([
        "east":"/d/azha/town/west4"
    ]) );
}

void reset(){
   if(!present("stable hand")) new("/d/azha/mon/stable")->move(TO);
}
