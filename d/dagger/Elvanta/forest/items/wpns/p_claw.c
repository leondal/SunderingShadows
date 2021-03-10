#include <std.h>
inherit WEAPON;
void create(){
    ::create();
set_name("poison claw");
set_short("poison claw");
set_id(({"claw"}));
set_long("A poison claw");
   set_weight(1);
   set_size(1);
   set("value",0);
    set_wc(1,10);
    set_large_wc(1,10);
set_type("piercing");
    set_property("monsterweapon",1);
    set_hit((:TO,"weapon_hit":));
}
int weapon_hit(object targ){
   if(!"daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death",0)){
tell_object(targ,"%^BOLD%^YELLOW%^You are paralyzed by the poisoned claw!");
    targ->set_paralyzed(70,"You are frozen solid.");
tell_room(environment(environment(TO)),"%^BOLD%^YELLOW%^"+targ->query_cap_name()+" is paralyzed by the poisoned claw!", ({TP, targ}) );
}
}
