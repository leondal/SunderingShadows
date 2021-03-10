#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room67",
        "east"      :PATH+"room75",
        "southeast" :PATH+"room80",
        "south"     :PATH+"room79",
        "southwest" :PATH+"room78",
        "west"      :PATH+"room73"
             ]));

}
