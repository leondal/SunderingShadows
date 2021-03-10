#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(NAT_CAVE);
    set_travel(FOOT_PATH);
    set_short("%^BOLD%^%^BLACK%^Enclosed Forest Passage%^RESET%^");
    set_name("enclosed forest passage");

    set_long("%^BOLD%^%^BLACK%^The forest around you has grown into "+
    "a literal enclosed passageway and you now find yourself "+
    "wandering through it.  The %^GREEN%^trees%^BOLD%^%^BLACK%^ "+
    "have grown together and their withered and gnarled branches "+
    "embrace to form a canopy that blocks out even the most "+
    "powerful rays of sunlight.  The %^RED%^ceiling%^BOLD%^%^BLACK%^ of this "+
    "passageway is so far overhead that a giant could easily walk "+
    "here with no difficulty.  The mysterious %^BOLD%^%^WHITE%^dark"+
    " fog%^BOLD%^%^BLACK%^ common to this forest has intensified "+
    "here and seems to be every churning slightly above "+
    "the %^GREEN%^ground%^BOLD%^%^BLACK%^, preventing you "+
    "from being able to discern what it is that you walk on and "+
    "offering only a %^BLUE%^cold chill%^BOLD%^%^BLACK%^ for "+
    "reassurance.%^RESET%^");
        
    set_listen("default","Strange sounds echo through the "+
    "forest.");
    set_smell("default","You smell the decaying of the forest.");
    
    set_items(( [
     "forest" : "You find yourself in the forest.",
     ({"trees","large trees"}) : "%^GREEN%^The large trees of "+
     "this forest sprout upward here, their gnarled and withered "+
     "limbs embracing to form a canopy that blocks out even "+
     "the most powerful rays of sunlight.%^RESET%^",
     ({"ceiling","canopy"}) : "%^RED%^The canopy ceiling of "+
     "this passageway is forged from the embraced limbs of "+
     "many trees.  It is so thick and effective that not even "+
     "the most powerful rays of sunlight can find their way "+
     "through.%^RESET%^",
     ({"chill","cold chill"}) : "%^BLUE%^A cold chill courses "+
     "through your body as your flesh is bathed in the "+
     "thick fog.%^RESET%^",
     ({"fog","thick fog","heavy fog","dark fog"}) : 
     "%^BOLD%^%^WHITE%^This dark and thick fog seems to seep "+
     "up from the ground and strangely continues churning "+
     "slightly above it.  It shrouds the ground, preventing you "+
     "from determining what it is that you now walk on and "+
     "offering only a %^BLUE%^cold chill%^BOLD%^%^WHITE%^ "+
     "for reassurance.%^RESET%^",
     ({"limbs","gnarled limbs","withered limbs"}) : "%^GREEN%^"+
     "The limbs of the trees here meet in an embrace that "+
     "forms such a thick canopy that not even the most "+
     "powerful rays of sunlight can break through.%^RESET%^",
     ({"ground"}) : "%^BOLD%^%^WHITE%^The ground here is "+
     "covered with a heavy blanket of thick fog that continually "+
     "churns.  It is impossible to determine its state of being "+
     "as the heavy fog continually blocks it from clear view."+
     "%^RESET%^",
    ] ));
    set_search("default","Perhaps something of interest "+
    "could have fallen to the ground?");
    set_search("ground","%^BOLD%^%^GREEN%^The fog is too thick "+
    "to permit searching the ground here.%^RESET%^");
}

void reset() {
    ::reset();
    if(!random(50)) {
        FENC->doomsday_voice(TO);
    }
}