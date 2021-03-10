#include <std.h>
#include "keep.h"
#include <daemons.h>
inherit DAEMON;

#define POTIONS ({"healing","healing","healing","healing","healing","poison","cure_poison",\
"heal","extra_heal"})
#define ARMORS ({"srobe","sshield"})
#define WEAPS ({"dagger","knife","scimitar","handaxe","hammer_sm","spear_sm"})

void do_found_object() 
{
    object ob;
    switch(random(18)) 
    {
        case 0..5:
            return new("/d/common/obj/armour/"+ARMORS[random(sizeof(ARMORS))]);
            break;
        case 6..13:
            return new("/d/common/obj/weapon/"+WEAPS[random(sizeof(WEAPS))]);
            break;
        case 14..17:
            ob = new("/d/common/obj/potion/"+POTIONS[random(sizeof(POTIONS))]);
            if((string)ob->query_short() == "A kit of blue healing vials") 
            {
                ob->set_uses(random(11) + 5 + random(11));
            }
            return ob;
            break;
    }
}
