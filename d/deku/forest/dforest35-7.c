#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"36-7",
       "east" : F_ROOMS"34-7",
       "north" : F_ROOMS"35-8",
       "south" : F_ROOMS"35-6",
       "southeast" : F_ROOMS"34-6",
       "southwest" : F_ROOMS"36-6",
       "northeast" : F_ROOMS"34-8",
       "northwest" : F_ROOMS"36-8",
    ] ));
}

void reset() {
    int r;
    ::reset();

    if(!present("chest")){
        r=random(2);
        if(r == 0)  new("/d/hm_quest/chests/chest14")->move(TO);
        else  new("/d/hm_quest/chests/chest22")->move(TO);
    }
}
