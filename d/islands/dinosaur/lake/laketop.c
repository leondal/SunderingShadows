#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit WATER;

void create(){
    ::create();
   set_terrain(SHALLOW_WATER);
   set_travel(FRESH_BLAZE);
    set_light(2);
}

void init(){
    ::init();
}

void reset(){
    ::reset();
}

int climb_out(){
    tell_object(TP, "%^BOLD%^You climb up the incline, slowly treading out of the water.");
    return 1;
}
