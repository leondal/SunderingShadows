#include <std.h>
#include <daemons.h>
// changing to inherit /d/common street lights for consistency/bug prevention *Styx* 12/23/03, last change 7/20/98
// inherit OBJECT;
// int original_light;

inherit "/d/common/obj/misc/street_light.c";

void create() {
    ::create();
    set_id(({"fountain","dragon statue","dragon statue fountain","dragon fountain"}));
    set_name("dragon fountain");
    set_short("A Dragon Statue Fountain");
    set_dayShort("A Dragon Statue Fountain");
    set_nightShort("A Dragon Statue Fountain with %^BOLD%^%^WHITE%^brightly glowing eyes%^RESET%^");
//    set_weight(1000000);
    set_long("This fountain is essentially a statue of a dragon that is around 10 foot tall.  It is made of finely sculptured silver metal and has strange magic gems for eyes that glow brightly.  A stream of water spurts from its jaws and into the pool below.  The metalwork appears to be Dwarven.");
//    set_value(0);
//    original_light =  -9999;
}

/*
void init(){
    string tod;
        
        if(original_light == -9999)
                original_light = environment(TO)->query_light();
        tod = EVENTS_D->query_time_of_day();
        if((tod == "night") && ((int)environment(TO)->query_light() ==
original_light)){
                environment(TO)->set_light(3);
set_short("A Dragon Statue Fountain with glowing eyes");
        }
        if((tod != "night") &&  ((int)environment(TO)->query_light() !=
original_light)){
                environment(TO)->set_light(-3);
set_short("A Dragon Statue Fountain");
        }
}
*/