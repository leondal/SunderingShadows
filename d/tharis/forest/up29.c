//up29.c

#include <std.h>
#include "./forest.h"

inherit "/d/tharis/forest/forest_up";

void create(){
    ::create();
    set_exits(([
            "down":TFOREST"forest180"
            ]));
}

/* changing to use CROOM & inherit while fixing typos
void reset(){
    ::reset();


    if(!present("small archer")){
        if(random(10) < 7)
            new(MONS"earcher")->move(TO);
        if(random(10) < 7)
            new(MONS"earcher")->move(TO);
    }

}
*/
