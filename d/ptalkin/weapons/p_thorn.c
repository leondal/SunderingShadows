//weapons by the House of Svaha

#include <std.h>
inherit WEAPON;

void create(){
    ::create();


set_name("thorn");
set_short("thorn");


set_id(({"thorn"}));
set_long("thorn");


   set_weight(1);
   set_size(1);


   set("value",0);
   set_wc(1,3);


   set_large_wc(1,5);
set_type("piercing");
    set_property("monsterweapon",1);



    set_hit((:TO,"weapon_hit":));
}
int weapon_hit(object targ){





   if(!"daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death",0)){
tell_object(targ,"%^BOLD%^YELLOW%^You are slightly paralyzed by the thorn!");
    targ->set_paralyzed(20,"You feel a sting from the thorn.");
tell_room(environment(environment(TO)),"%^BOLD%^YELLOW%^"+targ->query_cap_name(
)+" is paralyzed by the poisoned thorn!", ({TP, targ}) );
}
}
