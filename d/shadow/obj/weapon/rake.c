#include <std.h>
inherit WEAPON;
create(){
::create();
set_name("rake");
set_id( ({"rake", "the rake", "a rake"}) );
set_short("a rake");
set_long("This is a well used farmer's rake.");
set_weight(2);
set_size(2);
set_wc(1,3);
set_large_wc(1,2);
set_type("bludgeoning");
    set_prof_type("tool");
set_value(1);
set_wield("You feel rather silly wielding this, but hey it's a weapon!");
set_hit("You bash your opponent's shins with the rake!");
set_unwield("You no longer feel foolish as you unwield the rake.");
   set_weapon_speed(4);
}
