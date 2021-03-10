//lslide2.c for use with ptrail19.c
#include <std.h>
#include "../kildare.h"

inherit ROOM;
void create(){
    ::create();
    set_terrain(BARREN);
    set_travel(RUBBLE);
    set_name("Landslide trap");
    set_short("A rocky landslide");
    set_long(
       "Rocks have spilled down the pathway, creating a painful "+
       "barrier to the trail.  Dust rises into the air from the "+
       "broken rocks, making breathing a little difficult.  The "+
       "once green trees surround the small clearing here, their "+
       "skeletal limbs moving lightly on the breeze.  Though the "+
       "rocks are piled high here, you might be able to climb over "+
       "them."
    );
    set_property("light",1);
    set_property("indoors",0);
    set_listen("default","Screeches and roars battle against the buffeting wind");
    set_smell("default","A strange scent of decay hangs in the air.");
}

void init(){
    ::init();
    TP->do_damage(TP->return_target_limb(),roll_dice(2,10));
    add_action("climb","climb");
}

int climb(string str){ //was running off thief climb skill; ported to athletics DC12. Nienne, 07/09
    int roll;
    roll = (int)TP->query_skill("athletics") + roll_dice(1,20);
    if(roll >= 12){
        tell_object(TP,"You clamber over the rocks back onto the trail.");
        tell_room(ETP,""+TPQCN+" clambers over the rocks.",TP);
        TP->move(ROOMS"ptrail19");
        return 1;
    }
    tell_object(TP,"You start to scramble over the rocks but slip and fall!");
    tell_room(ETP,""+TPQCN+" starts climbing over the rocks but slips and falls.",TP);
    TP->do_damage(TP->return_target_limb(),roll_dice(1,10));
    TP->add_attacker(TO);
    return 1;
}