#include <std.h>
#include "../common.h"

inherit RATPATHS;

void create(){
    ::create();
    set_light(1);
    set_exits(([
    "northwest":PATH+"rp_p013_p000",
"east":PATH+"rp_p015_n001",

                   ]));

}

void reset()
{
    ::reset();
    if (!present("thrach", TO)) {
        new(RPMON + "thrach")->move(TO);
    }
    if (!present("gnarw", TO)) {
        new(RPMON + "thrach_mount")->move(TO);
    }
}
