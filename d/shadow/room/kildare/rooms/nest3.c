//nest3.c
#include "../kildare.h"

inherit NEST;

void create()
{
    ::create();
    if(!present("peryton")) {
        new(MON"peryking")->move(TO);
    }
    set_climb_exits(([
        "descend":({ROOMS"ptrail15",10,4,100}),
    ]));
}

void reset() {
    ::reset();
    if(!present("peryton")){
        if(!random(3)){
            new(MON"peryking")->move(TO);
        }
    }
}
