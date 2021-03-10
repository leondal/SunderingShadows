#include <std.h>

inherit "/d/attaya/spec/ledge3";

void create(){
	::create();
    set_long(::query_long()+"
Two %^BLACK%^st%^BLACK%^a%^BLACK%^tue%^BLACK%^s%^WHITE%^ stand at either side of a %^BLACK%^l%^BLACK%^a%^BLACK%^d%^BLACK%^der%^WHITE%^ that climbs to a ledge not far above you.%^RESET%^%^RESET%^
");
       set_exits(([
          "west":"/d/attaya/cliff33",
         "east":"/d/attaya/cliff35",
         "up":"/d/attaya/cliff70"
]));
    set_items(([
    "statues" : "The statues seem to glare down at you.  They are tall female figures with hair down to their waists.  They make you feel uneasy and are very lifelike.",
    "ladder" : "The ladder has been fastened to the cliff face by means of steel spikes.  It seems sturdy enough."
]));
}

