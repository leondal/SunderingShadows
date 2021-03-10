#include <std.h>
#include <objects.h>



inherit "/d/attaya/spec/cliff";

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("Passage of the Black Dawn Temple.");
    set_long("
    This passage is carved into the mountain with tremendous care.  It has been painstakingly polished and bears numerous lines of pictograms and writings.  Brilliant torches are recessed within the walls in places, each with its own smoke duct so as to not flood this hallway with smoke.  
    The ground has been fashioned from marble tiles, each with the crest of the Kinnesaruda upon it.
");

     set_listen("default","Screams echo through this passage.");
 
    set_exits(([

       "west" : "/d/attaya/cliff56",
       "east" : "/d/attaya/cliff16",

    ] ));
    set_items(([
        "torches" : "They are recessed in the walls and glow brightly.  They draw from their own resivoirs of oil, and have their own smoke vents.",
        "pictograms" : "Hundreds of pictograms line the walls.  You don't have the time to decipher them now.",
        "walls" : "They are smooth with the exception of the pictograms and writing vcarved into them.",
        "tiles" : "The tiles are marked with the symbol of the Kinnesaruda and have been brought to this island from elsewhere."
    ] ));
}
