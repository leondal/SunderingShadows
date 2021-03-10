#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "south"     :PATH+"room47"
             ]));

}


void reset()
{
  ::reset();
    if(!present("sister"))
    {
    new(MON"sister_of_fate1")->move(TO);
    new(MON"sister_of_fate2")->move(TO);
    new(MON"sister_of_fate3")->move(TO);
    }
}
