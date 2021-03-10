#include <std.h>
#include <config.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("batlin's note");
    set_id( ({"note","formula","batlin formula","batlin's formula"}) );
    set("short","Batlin's note");
    set("long","You will need to explore this house with care and also "+
         "imagination. You should then be able to find some good stuff "+
        "here.");
/*
    set("long",

@NOTE
As you look upon the note you realize that it is some sort of formula written down
by the owner of this house.
It reads:

The spell of Imbalance requires:
Black pearl
Bloodmoss
Garlic
Ginseng
Mandrake root
Nightshade
Spider silk
Sulfurous ash
Worm heart
NOTE
);
*/
    set_weight(1);
    set_value(0);
}
