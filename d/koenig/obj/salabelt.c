//salabelt.c - Belt of salamander skin for Koenig.  Circe 11/22/03
#include <std.h>
#include "../koenig.h"
inherit "/std/armour";

void create()
{
        ::create();
        set_obvious_short("a shiny black belt");
        set_short("%^BOLD%^%^BLACK%^Salamander Skin Belt%^RESET%^");
        set_name("salamander belt");
        set_id(({"belt","black belt","salamander belt","shiny belt"}));
        set_long(
         "This thin leather belt is very shiny and looks almost wet.  The "+
         "material is smooth and soft to the touch - it seems nothing like "+
         "normal leather.  One end of the belt is a salamander's small head, "+
         "and the tail has been altered to fit just inside its mouth.  The "+
         "belt would surely only fit those with a small waist."
        );
        set_size(1);
        set_value(10);
        set_cointype("silver");
        set_weight(3);
        set_type("clothing");
        set_limbs(({"waist"}));
        set_wear((:TO,"wearme":));
}

int wearme()
{
        tell_object(ETO,"You tighten the salamander belt around your waist and fasten it.");
        return 1;
}
