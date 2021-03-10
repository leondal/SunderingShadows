//up9.c

#include <std.h>
#include "./forest.h"

inherit "/d/tharis/forest/forest_up";

void create(){
    ::create();
    set_exits(([
            "down":TFOREST"forest63"
            ]));
}

/* changing to use CROOM & inherit while fixing typos
void reset(){
    ::reset();

    if(!present("archer"))
        if(random(10) < 9)
            new(MONS"e_archer")->move(TO);
    if(!present("sprite"))
        if(random(10) < 5){
            new(MONS"sprite")->move(TO);
            new(MONS"sprite")->move(TO);
        }
}
*/
