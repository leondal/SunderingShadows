#include <std.h>
#include <daemons.h>
#include <security.h>

#include "area_stuff.h"
#include "/d/common/common.h"

inherit CVAULT;
//inherit VAULT;
//inherit "/d/deku/hhouse/inherits/test/controlvault";

void create()
{
   // log_file("deku_code", "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@@START@@\n haunting.c before ::create in "+base_name(TO)+"\n");
    ::create();
    set_property("no scry", 1);
   // log_file("deku_code", "@@END@@\n haunting.c after ::create in "+base_name(TO)+"\n##################################\n\n");
}

void reset()
{
    //log_file("deku_code", "\n\n$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$\n@@RESET@@START\n haunting.c before ::reset in "+base_name(TO)+"\n");
    ::reset();
    //log_file("deku_code", "@@RESET@@END\n haunting.c after ::reset call in "+base_name(TO)+"\n$*$*$*$*$*$*$*$$*$*$*$*$$*$*$*$*$*$*$*$\n\n");   
}

void init()
{
    object hob;
    int x;
  //  log_file("deku_code", "\n\n$*$*$*$*$*$*$*$$*$*$*$*$$*$*$*$*$*$*$*$\n@@INIT@@START\n haunting.c before ::init in "+base_name(TO)+"\n");
    ::init();    
  //  log_file("deku_code", "@@INIT@@END\n haunting.c after ::init in "+base_name(TO)+"\n$*$*$*$*$*$*$*$$*$*$*$*$$*$*$*$*$*$*$*$\n\n");
    if(!objectp(TP)) return;
    if(!living(TP)) return;
    if(!TP->is_player()) return;
    if(hob = present("saide_haunting_object", TP)) 
    {
        if(!x = (int)hob->query_property("place_encounters")) 
        {
            hob->place_encounters();
            return;
        }
        else if(time() >= x) hob->place_encounters();
        return;
    }

    if(catch(hob = new(HHMON+"haunting_ob")))
    {
        log_file("deku_code", "\n@@HAUNTINGOB@@ haunting_ob broke for some reason\n");
        return;
    }
    hob->set_delay(15);
    hob->move(TP);
    hob->curse_me();
    hob->place_encounters();    
    return;
}
