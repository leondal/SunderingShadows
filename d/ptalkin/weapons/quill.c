inherit "/std/weapon";
#include "std.h";
drop(str);

create() {
    ::create();
set_id(({"quill"}));
set_name("quill");
set_short("quill");
    set_property("monsterweapon",1);
   set_weight(1);
   set_size(1);
	set_wc(10,3);
	set_large_wc(12,4);
set_type("piercing");
set_hit((:TO,"weapon_hit":));
}
int weapon_hit(object targ){
	if(!"daemon/saving_d"->saving_throw(targ,
"paralysation_poison_death", 0)){
tell_object(targ,"You are slightly paralyzed by the quills");
	targ->set_paralyzed(10, "You are having trouble moving");
tell_room(environment(environment(TO)), ""+targ->query_cap_name()+" is paralyzed by the porcupines quills", ({TP,targ}) );
}
}
