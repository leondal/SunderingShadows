#include <std.h>
inherit WEAPON;
void create() {
    ::create();
   set_id(({ "knife"}));
   set_name("knife");
   set_short("A knife");
set_long("This is a small knife, the blade only four inches long, however, a black glisteing on the edge make you think twice about the danger it may pose.");
   set_weight(1);
   set_size(1);
set("value", 10);
   set_cointype("silver");
   set_wc(1,3);
   set_large_wc(1,2);
   set_type("piercing");
	set_hit((:TO, "weapon_hit":));
}
int weapon_hit(object targ){
	if(!"daemon/saving_d"->saving_throw(targ,
"paralyzation_poison_death",0)){
	tell_object(targ,"%^BOLD%^RED%^You feel the poison course through your veins!");
	targ->set_paralyzed(15,"%^BOLD%^YELLOW%^The poison is coursing through your veins, and you feel weak!");
tell_room(environment(environment(TO)), ""+targ->query_cap_name()+" is poisoned by the small knife!", ({TP, targ}) );
}
}
