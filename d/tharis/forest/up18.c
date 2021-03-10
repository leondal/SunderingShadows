//up18.c

#include <std.h>
#include "./forest.h"

inherit "/d/tharis/forest/forest_up";

void create(){
    ::create();
    set_exits(([
            "down":TFOREST"forest127"
            ]));
}

/* changing to use CROOM & inherit while fixing typos
void reset(){
    ::reset();


    if(!present("small archer"))
        if(random(10) < 7){
            new(MONS"earcher")->move(TO);
            if(random(10) < 4)
                new(MONS"earcher")->move(TO);
        }

}
*/
