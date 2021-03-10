//  Made READABLE By FireDragon
//

#include <std.h>
#include <money.h>
#include <move.h>
#include "../wemic.h"

inherit HEALER;

void create() {
    ::create();
    set_light(3);
    set_property("training",1);
    set_indoors(1);
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_short("Fourarr's Healing Tent");
    set_long("%^BLUE%^This dim little tent has a strong odour of %^ORANGE%^herbs"
      +"%^BLUE%^, %^GREEN%^salves%^BLUE%^, and %^RESET%^balms%^BLUE%^. A couple of"
      +" cots are available for the sick and wounded %^BOLD%^%^YELLOW%^wemic"
      +" %^RESET%^%^BLUE%^- or perhaps others if needed. ");
    set_smell("default", "The strong odor of herbs and balms turns your stomach.");
    set_listen("default", "The sounds of the village filter in from outside.");
    set_exits( ([
        "northeast" : ROOMS + "path05",
        "southeast" : ROOMS + "path03"
    ] ));
    set_name("Fourarr");
}

void reset(){
    ::reset();
    if(!present("fourarr")) 
        find_object_or_load(MOB + "fourarr")->move(TO);
}
