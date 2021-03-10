#include <std.h>
#include "/d/deku/inherits/forest.h"
#include <daemons.h>
inherit "/std/pier.c";
//inherit ROOM;
//inherit FOREST_ENCOUNTERS;

void create() {
    ::create();
    set_short("%^BLUE%^Bank of The Silent River%^RESET%^");
    set_name("Bank of The Silent River");
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_water_body("river");
    set_long("%^CYAN%^You have stumbled upon the "+
    "bank of a meandering and silent %^BLUE%^river%^CYAN%^.  The river "+
    "is completely covered by the mysterious %^BOLD%^%^BLACK%^"+
    "dark fog%^RESET%^%^CYAN%^ that seeps up from the ground of "+
    "this strange forest.  Only the cool breeze that rises up "+
    "from the river and the very slight occassional sound "+
    "of rushing water reveal what is hidden beneath the "+
    "immense blanket of %^BOLD%^%^BLACK%^fog%^RESET%^%^CYAN%^, otherwise "+
    "one could easily completely miss the river.  The %^BOLD%^"+
    "%^GREEN%^trees%^RESET%^%^CYAN%^ of the forest rise up all around you, some of them as "+
    "far as several hundred feet overhead.   Their once "+
    "proud and powerful %^BOLD%^%^GREEN%^limbs%^RESET%^%^CYAN%^ now "+
    "hanging gnarled and withered.  The ground in this part "+
    "of the forest is kept relatively picked up.%^RESET%^");

        
    set_listen("default","Strange sounds echo through the "+
    "forest.");
    set_smell("default","The decay of the forest mingles with "+
    "the sweet cool scent of fresh water.");
    
    set_items(( [
     "forest" : "You find yourself in the forest.",
     ({"trees","large trees"}) : "%^GREEN%^The large trees of "+
     "this forest sprout upward and some reach several hundred "+
     "feet into the sky.  Their once proud and powerful limbs "+
     "now hang gnarled and withered.%^RESET%^",
     ({"blanket of fog","fog blanket","fog","thick fog","heavy fog","dark fog"}) : 
     "%^BOLD%^%^WHITE%^This dark and thick fog seems to seep "+
     "up from the ground.  It blankets the entire river and "+
     "almost completely masks its existence.%^RESET%^",
     ({"limbs","gnarled limbs","withered limbs"}) : "%^GREEN%^"+
     "The limbs of the trees have lost all strength, hanging "+
     "gnarled and withered.%^RESET%^",
     ({"ground"}) : "%^BOLD%^%^GREEN%^The ground here is "+
     "mostly picked up with only an occassional limb finding its "+
     "way down.  A dark and mysterious fog seeps up from it."+
     "%^RESET%^",
     ({"river","silent river"}) : "%^BLUE%^This mostly silent river "+
     "is covered with a blanket of thick and dark fog.  "+
     "Its noise is masked by the fog and its existence is almost "+
     "completely hidden from view by it.%^RESET%^",
    ] ));
    set_search("default","You see nothing that would offer a "+
    "good hiding spot.");
}

void reset() {
    ::reset();
    FENC->dissolve_me(TO);
    if(!random(300)) {
        FENC->place_hag(TO);
        return;
    }
    if(!random(300)) {
        FENC->place_athach(TO);
        return;
    }
    if(!random(300)) {
        FENC->make_gnoll_pack(TO);
    }
    if(!random(350)) {
        FENC->make_kobold_gang(TO);
    }
    if(present("werewolf",TO) && (string)EVENTS_D->query_time_of_day() != "night") {
        FENC->remove_werewolf(TO);
    }
     if(!random(50)) {
        FENC->doomsday_voice(TO);
    }
}