#include <std.h>
#include <daemons.h>
#include "/d/islands/argentrock/argabbr.h"

inherit OBJECT;

object target;
int count;

void create() {
    set_name("black death vortex");
    set_id( ({"vortex","death vortex"}) );
    set("short","%^BLACK%^A black death vortex");
    set("long","%^BLACK%^A large black vortex. It continues twisting and "+
        "doing damage on living things. This cloud of energy is powerful and "+
        "devastating.");
    set_weight(10000);
    set_property("no offer",1);
    set_property("magic",1);
    set_property("no animate",1);
    set_property("no rush",1);
    set_property("no death",1);
    count = 0;
}

void set_target(object vic) { target = vic; }

object query_target() { return target; }

void init() 
{
    ::init();
    if(!objectp(target) || !present(target) ) { return; }
    set("long","%^BLACK%^A large black vortex. It continues twisting "+
        "and drives towards "+target->query_cap_name()+". This cloud of "+
        "energy is powerful and devastating.");
    set_heart_beat(1);
}

void kill_him(object vic) 
{
    if(!objectp(ETO) || !objectp(vic)) { return; }
    
    tell_room(ETO,"%^BLACK%^The black death vortex drives at "+vic->query_cap_name()+"!",vic);
    tell_object(vic,"%^BLACK%^The black death vortex drives at you!");
    if( vic->query_paralyzed() ) 
    {
        tell_room(ETO,"%^RED%^"+vic->query_cap_name()+" is caught helplessly in "+
            "the black twisting horror!",vic);
        tell_object(vic,"%^RED%^You are caught helplessly in the black twisting "+
            "horror!");
        vic->do_damage( "torso",(random(30) + 50) );
        return;
    }
    
    //if( SAVING_D->saving_throw(vic,"spell",-8) ) 
    if(vic->reflex_save(20+roll_dice(1,20)))
    {
        tell_room(ETO,"%^ORANGE%^"+vic->query_cap_name()+" managed to "+
            "avoid the twisting horror.",vic);
        tell_object(vic,"%^ORANGE%^You managed to avoid the twisting "+
            "horror.");
        return;
    }
    else 
    {
        tell_room(ETO,"%^RED%^"+vic->query_cap_name()+" tries to avoid "+
            "the black twisting horror but fails and is caught in it!",vic);
        tell_object(vic,"%^RED%^You try to avoid the black twisting horror "+
            "but fail and are caught in it!");
        vic->do_damage( "torso",(random(50) + 30) );
        return;
    }
}

void heart_beat() 
{
    if(!objectp(TO) || !objectp(ETO) || !objectp(target)) 
    {
        if(objectp(TO)) { TO->remove(); }
        return; 
    }
    if( !present("batlin",ETO) ) 
    {
        tell_room(ETO,"%^BLUE%^The vortex loses its power and vanishes.");
        TO->remove();
        return;
    }
    if( !present(target,ETO) ) 
    {
        tell_room(ETO,"%^BOLD%^BLUE%^The vortex twists for a while, but it "+
            "cannot locate its target, so it vanishes.");
        TO->remove();
        return;
    }
    if( !count && objectp(TO) ) 
    {
        count = 3;
        call_out("kill_him",1,target);
    }
    count--;
}
