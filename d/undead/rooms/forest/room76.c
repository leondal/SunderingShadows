#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room69",
        "northeast" :PATH+"room70",
        "southwest" :PATH+"room80",
        "west"      :PATH+"room75"
             ]));

}
