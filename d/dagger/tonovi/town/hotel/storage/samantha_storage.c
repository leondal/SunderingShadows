// Chernobog (1/10/21)
// Tonovi Hotel

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "cigarette girl's tray");
    set("long", "You really shouldn't be here, how rude.");
}

void reset(){
    int i;
    
    ::reset();
    if (!present("pirate's booty tobacco"))
        new("/d/common/obj/misc/tobacco/pirates_booty_tobacco")->move(TO);
    if (!present("pirate's booty tobacco 2"))
        new("/d/common/obj/misc/tobacco/pirates_booty_tobacco")->move(TO);
    if (!present("white dragon tobacco"))
        new("/d/common/obj/misc/tobacco/white_dragon_tobacco")->move(TO);
    if (!present("white dragon tobacco 2"))
        new("/d/common/obj/misc/tobacco/white_dragon_tobacco")->move(TO);
    if (!present("tsarven tobacco"))
        new("/d/common/obj/misc/tobacco/tsarven_tobacco")->move(TO);
    if (!present("tsarven tobacco 2"))
        new("/d/common/obj/misc/tobacco/tsarven_tobacco")->move(TO);
    if (!present("luxury of tharis tobacco"))
        new("/d/common/obj/misc/tobacco/luxury_of_tharis_tobacco")->move(TO);
    if (!present("luxury of tharis tobacco 2"))
        new("/d/common/obj/misc/tobacco/luxury_of_tharis_tobacco")->move(TO);
    if (!present("pipe"))
        new("/d/common/obj/misc/pipe")->move(TO);
    if (!present("pipe 2"))
        new("/d/common/obj/misc/pipe")->move(TO);
    for (i = 0; i < 6; i++){
        if (!present("light-bodied cigar " + i)){
            new("/d/common/obj/misc/tobacco/light_bodied_cigar")->move(TO);
        }
    }
    for (i = 0; i < 6; i++){
        if (!present("medium-bodied cigar " + i)){
            new("/d/common/obj/misc/tobacco/medium_bodied_cigar")->move(TO);
        }
    }
    for (i = 0; i < 6; i++) {
        if (!present("full-bodied cigar " + i)){
            new("/d/common/obj/misc/tobacco/full_bodied_cigar")->move(TO);
        }
    }
    for (i = 0; i < 6; i++) {
        if (!present("cigarette " + i)){
            new(OBJ"cigarette.c")->move(TO);
        }
    }
    if (!present("cigar box")){
        new(OBJ"cigar_box.c")->move(TO);
    }
    if (!present("cigarette case")){
        new(OBJ"cigarette_case.c")->move(TO);
    }
}

void call_reset(){
    reset();
}

