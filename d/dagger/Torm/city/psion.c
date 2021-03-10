#include <std.h>
#include "../tormdefs.h"
inherit ROOM;

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("A long stone building");
    set_short("%^BOLD%^%^CYAN%^A long stone building%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^A long stone building%^RESET%^\n"
"%^CYAN%^This long, stone building is rather plain in appearance, with "
"%^WHITE%^pillars %^CYAN%^at intervals along the street front allowing "
"permanent access inside and out.  Here in the eastern end of the building, "
"a sturdy %^ORANGE%^wooden desk %^CYAN%^borders an area along the middle of "
"the room and around the rear wall. Upon it are displayed countless varieties "
"and cuts of crystals, refracting %^YELLOW%^l%^WHITE%^igh%^YELLOW%^t %^RESET%^"
"%^CYAN%^from the crystals around them in a %^RED%^r%^MAGENTA%^a%^BLUE%^i"
"%^CYAN%^n%^GREEN%^b%^ORANGE%^o%^YELLOW%^w %^RESET%^%^CYAN%^of color.  Stairs "
"lead up from the street itself to the building, which to the west appears to "
"consist only of a carved circle in the floor.\n\n%^RESET%^"
"<help shop> will give you help on how to use the shop.\n");
    set_listen("default","The hustle and bustle of the city goes on in the streets below.");
    set_smell("default","Wafting scents of food and animals drift along the wind from the nearby marketplace.");
    set_items(([
    ]));
    set_exits(([
      "north":TCITY+"c7",
      "west":TCITY+"portal",
    ]));
}

void reset(){
   ::reset();
   if(!present("cassandra")) {
      find_object_or_load("/d/dagger/Torm/mon/cassandra")->move(TO);
   }
}
