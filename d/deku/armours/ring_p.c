#include <std.h>
inherit ARMOUR;

void create()
{
	::create();
	"/d/deku/armours/ring_p_base.c"->create_ring(TO);
}

int do_wear() {
    object *stuff;
    int i,j, flag;

    stuff = ETO->all_armour();
    j = sizeof(stuff);
    for(i=0;i<j;i++) {
        if(!objectp(stuff[i])) continue;
        if((string)stuff[i]->query_type() == "ring") {
//         if(stuff[i]->query_property("enchantment")){
            if(member_array("ring of protection",stuff[i]->query_id()) != -1) {
                flag = 1;
                break;
            }
//         }
        }
    }
    if(flag) {
        write("%^BOLD%^The magic of the ring already worn prevents you from wearing this one!");
        return 0;
    }
    return 1;
}
