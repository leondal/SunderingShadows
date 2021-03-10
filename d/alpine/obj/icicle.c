// An icicle for the Yeti to wield ... by Killashandra

#include <std.h>
#include <daemons.h>
#include "short.h"

inherit "std/weapon";
        
void create(){
        ::create();
        set_name("Icicle");
        set_id(({"icicle","large icicle"}));
        set_short("A large sharp icicle");
        set_long("A large sharp icicle.  It would probably make a good weapon!");
        set_weight(1);
        set_value(1);
        set_property("monsterweapon",1);
        set_wc(1,12);
        set_large_wc(1,16);
        set_size(3);
        set_type("slashing");
        }
