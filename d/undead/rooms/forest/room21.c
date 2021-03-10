#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room12",
        "east"      :PATH+"room22",
        "west"      :PATH+"room20",
        "northwest" :PATH+"room11",
        "northeast" :PATH+"room13"
             ]));

}
