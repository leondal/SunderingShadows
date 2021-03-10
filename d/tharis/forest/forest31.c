//forest31.c

#include <std.h>

#include "./forest.h"

inherit ROOM;

void create(){
    ::create();

    set_properties((["light":2,"indoors":0]));
    set_short("Small clearing in the forest");
    set_terrain(MEADOWLANDS);
    set_travel(FOOT_PATH);
    set_long(
@OLI
    %^BOLD%^%^GREEN%^This is a small clearing in the forest%^RESET%^
You have reached a small clearing in the forest. Lovely sunshine
filters through to the grassy floor. This appears to be a haven
from the horrors of the war going on now. Here other creatures
come to play. The lush green grass waves in a slight wind. The
tranquility of this place is truly relaxing after having to
fight your way here.
OLI
    );
    set_smell("default","The wonderful fragrances of nature abound here.");
    set_listen("default","You can here the wonderful cheer sound almost as the wind caresses your face.");
    set_exits(([
        "west":TFOREST"forest30",
        "northwest":TFOREST"forest53",
        "northeast":TFOREST"forest66"
        ]));
    set_items(([
        "grass":"This is a thick, green grass. not un common to meadows."
        ]));
}

void reset(){
    int num, i;
    ::reset();

    if(!present("satyr")){
        num = random(3)+1;
        for(i=0;i<num;i++)
            new("/d/tharis/monsters/satyr")->move(TO);
    }

    if(!present("korred")){
        num = random(3)+1;
        for(i=0;i<num;i++)
        new("/d/tharis/monsters/korred")->move(TO);
    }
}
