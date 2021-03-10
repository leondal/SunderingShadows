#include <std.h>
#include "/d/deku/inherits/forest.h"
#include <daemons.h>
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^BOLD%^%^BLACK%^Outskirts of Shadowlord Forest%^RESET%^");
    set_name("outskirts of shadowlord forest");
    
    set_long("%^BOLD%^%^BLACK%^The forest around you sprawls "+
    "to the west of you as far as the eye can see and begins "+
    "breaking up to the east where it meets a rocky shoreline "+
    "that runs along a vast blue ocean.  The %^GREEN%^trees%^BOLD%^"+
    "%^BLACK%^ here shoot upward, some of them as "+
    "far as several hundred feet, with much younger "+
    "%^RED%^saplings%^BOLD%^%^BLACK%^ dwelling beneath them.  "+
    "The once proud and powerful %^BOLD%^%^GREEN%^limbs"+
    "%^BOLD%^%^BLACK%^ of both sapling and tree are now "+
    "withered and gnarled, falling ever more frequently "+
    "to the already covered %^GREEN%^ground%^BOLD%^%^BLACK%^.  "+
    "A mysterious %^WHITE%^dark fog%^BOLD%^%^BLACK%^ seeps "+
    "up and out of the ground.  It hangs over everything in the "+
    "forest, shrouding the entire area and offering a %^BLUE%^cold "+
    "chill%^BOLD%^%^BLACK%^ to anyone having found themselves here.");
  
   
    set_listen("default","Strange sounds echo throughout the "+
    "forest and mingle with the sound of water crashing against rocks.");
}
