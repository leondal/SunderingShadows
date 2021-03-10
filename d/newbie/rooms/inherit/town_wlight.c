#include <std.h>

#include "../../newbie.h"
inherit ROOM;

void create(){
   ::create();
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");  
    set_exits( ([
    ]) );
}

void reset(){
        if(!present("street_light",TO))
                new(MISCDIR+"street_light")->move(TO);
}