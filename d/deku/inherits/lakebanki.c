#include <std.h>
#include "/d/deku/inherits/forest.h"
#include <daemons.h>
inherit "/std/pier.c";

//inherit ROOM;
//inherit FOREST_ENCOUNTERS;

void create() {
    ::create();
    set_short("%^BLUE%^Bank of The Shadowlord Lake%^RESET%^");
    set_name("Bank of The Shadowlord Lake");
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_water_body("lake");
    set_travel(DIRT_ROAD);
    set_long("%^CYAN%^You find yourself standing on the bank "+
    "of the stagnant %^BLUE%^shadowlord lake%^CYAN%^.  The water of "+
    "the lake is covered with a thick layer of "+
    "%^GREEN%^moss%^CYAN%^ and offers an even more unpleasant "+
    "odor to this part of the forest.  The forest continues around "+
    "you, its %^GREEN%^trees%^CYAN%^ sprouting up far overhead, "+
    "some of them as far as several hundred feet.  Their once "+
    "proud and powerful %^BOLD%^%^GREEN%^limbs%^RESET%^%^CYAN%^ "+
    "now hanging gnarled and withered.  The ground here "+
    "is in remarkably better shape than most of the forest, "+
    "suggesting that whatever creatures dwell in this forest "+
    "may very well like to keep the ground of their watering "+
    "hole relatively picked up.  The mysterious %^BOLD%^"+
    "%^BLACK%^dark fog%^RESET%^%^CYAN%^ common to this "+
    "forest still seeps up from the "+
    "ground, even here, shrouding the area around the lake "+
    "and offering a %^BLUE%^cold chill%^CYAN%^ to anyone "+
    "finding themselves here.%^RESET%^");
     
    set_listen("default","Strange sounds echo through the "+
    "forest.");
    set_smell("default","The decay of the forest mingles with "+
    "the soured water from the lake.");
    
    set_items(( [
     "forest" : "You find yourself in the forest.",
     ({"trees","large trees"}) : "%^GREEN%^The large trees of "+
     "this forest sprout upward and some reach several hundred "+
     "feet into the sky.  Their once proud and powerful limbs "+
     "now hang gnarled and withered.%^RESET%^",
     ({"chill","cold chill"}) : "%^BLUE%^A cold chill courses "+
     "through your body as your flesh is bathed in the "+
     "thick fog.%^RESET%^",
     ({"fog","thick fog","heavy fog","dark fog"}) : 
     "%^BOLD%^%^WHITE%^This dark and thick fog seems to seep "+
     "up from the ground.  It shrouds the entire area around the "+
     "lake and offers you a %^BLUE%^cold chill%^BOLD%^%^WHITE%^ as "+
     "it comes into contact with your flesh.%^RESET%^",
     ({"limbs","gnarled limbs","withered limbs"}) : "%^GREEN%^"+
     "The limbs of the trees have lost all strength, hanging "+
     "gnarled and withered.%^RESET%^",
     ({"ground"}) : "%^BOLD%^%^GREEN%^The ground here is "+
     "mostly picked up with only an occassional limb finding its "+
     "way down.  A dark and mysterious fog seeps up from it."+
     "%^RESET%^",
     ({"moss","gree moss"}) : "%^GREEN%^This thick green moss "+
     "covers the top of the lake.%^RESET%^",
     ({"lake","shadowlord lake","stagnant lake","stagnant shadowlord lake"}) : 
     "%^BLUE%^You are on the bank of this stagnant lake, the top "+
     "of it is covered by a thick layer of moss and you are "+
     "unable to see down into its murky depths.%^RESET%^",
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
}

