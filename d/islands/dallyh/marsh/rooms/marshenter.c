#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create() 
{
    ::create();
    set_exits( ([
        "northeast" : MRPATH "marsh2",
        "northwest" : MRPATH "marsh3",
    ]) );

    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ A %^BOLD%^%^WHITE%^sheer cliff%^BOLD%^%^BLACK%^"+
    " to the south stops the marsh from going any further in that direction and leads back up to "+
    "the forest about forty feet above.%^RESET%^");
    add_item(({"cliff", "cliffs"}), "%^BOLD%^%^WHITE%^This sheer cliff leads up into the forest about "+
    "forty feet above you. You could attempt to %^RESET%^climb%^BOLD%^%^WHITE%^ it if you were "+
    "so inclined.%^RESET%^");
    set_climb_exits((["climb":({
    FRPATH"forest8",25,15,300})]));
    
    set_fall_desc(
        "You fall down about forty feet and land in a thick foul sludge!"
    );
}
