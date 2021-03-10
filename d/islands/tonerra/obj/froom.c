//froom.c
#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

// also changing to use CROOM since the salamanders get moved by the lavastream *Styx*  11/22/03

inherit CROOM;

object *lizards = ({});

void create() 
{
    // these aren't spawning with set monsters for whatever reason, so going to create them another way -Ares
    set_monsters( ({ MON+"salamander" }), ({ random(4)+1 }) );
    ::create();
    set_repop(50);
    set_property("indoors",1);
    set_name("fiery hole");
    set_short("Fiery hole");
    set_terrain(BARREN);  // also adding terrain/travel 11/22/03, Styx
    set_travel(LEDGE);
    set_property("no teleport",1);
    set_long("%^ORANGE%^You are standing on a small ledge over looking the magma.  "
        "Every now and then a piece of rock falls off and erupts into "
        "flames before it hits the surface. The flames dance around you "
        "The very rock you stand seems to be on fire. The fire and the heat "
        "burn you as you stand here.");
    set_smell("default","The fumes from the burning rock are stifling.");
    set_listen("default","The flames roar around you.");
    set_heart_beat(10);
    set_property("continue heartbeat",1);
}

/*
void reset()
{
    object mon;
    int i;
    ::reset();   
    lizards -= ({ 0 });
    
//    if(!random(2) && !sizeof(lizards))
    if(!sizeof(lizards))
    {
        for(i=0;i<roll_dice(1,3);i++)
        {
            mon = new(MON+"salamander");
            lizards += ({ mon });
            mon->move(TO);
        }
    }
}
Removing this as the problem seemed to be that the room was not loading properly ~Circe~ 7/23/19
*/

void heart_beat()
{
    object *inven;
    int i;

    if(!objectp(TO)) return;
    ::heart_beat();

    inven = all_living(TO);

    for(i=0;i<sizeof(inven);i++)
    {
        if(!objectp(inven[i])) { continue; }
        // added exclude true invis immortals *Styx*  9/20/03, last change was 6/00
        if(inven[i]->query_true_invis()) { continue; }
        if(inven[i]->query_property("fire resistant")) { continue; }

        tell_object(inven[i],"%^RED%^You are scorched by the heat.");
        inven[i]->add_attacker(TO);
        inven[i]->do_damage("torso",roll_dice(3,4));
        inven[i]->continue_attack();
        // adding another objectp check due to consistent bugs *Styx*  11/22/03, last change 9/20/03
        if(objectp(inven[i])) { inven[i]->remove_attacker(TO); }
    }
}
