#include <std.h>
#include "area_stuff.h"
inherit FFC;

void reset()
{
    int flag;
    object mimic, targ;
    ::reset();
    if(!random(8))
    {
        targ = present("chest", TO);
        if(objectp(targ)) 
        {
            if(targ->query_mimic()) flag = 1;
        }
        if(!objectp(targ) || !flag) 
        {
            mimic = new(FFMON+"mimic");
            mimic->move(TO);
        }
    }
}