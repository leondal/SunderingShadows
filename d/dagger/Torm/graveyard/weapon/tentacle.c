#include <std.h>
inherit WEAPON;
void create() {
    ::create();
    set_id (({"tentacle"}));
    set_name ("Tentacle");
    set_short ("Tentacle");
    set_long ("The tentacle of a mindflayer");
    set_weight (15);
    set_size (1);
    set_value (1);
    set_property ("monsterweapon",1);
    set_wc (1,3);
    set_type ("piercing");
    set_hit ((:TO,"extra_hit":));
}
int extra_hit() {
    object ob;
    string dam;
    ob=(object)query_wielded()->query_current_attacker();
    if(!ob) return 0;
    if(random(6) ==3) return 1;
    if("daemon/saving_d"->saving_throw(ob,"rod_staff_wand")) {
        dam="slightly";
    } else {
	dam="heavily";
    }
    tell_object(ob,
	"The tentacle strikes you deep into your mind "+dam+ 
	" draining your mental essense!"
    ,ob);
    tell_room(environment(ob),
	"The tentacle strikes "+ob->query_cap_name()+
	" deep into their mind "+dam+" draining their mental "
	"essense!"
    ,ob);
    if(dam == "slightly") {
	ob->do_damage("head",roll_dice(1,6));
    } else {
	ob->do_damage("head",roll_dice(2,6));
	ob->set_paralyzed(30,
	    "%^BLUE%^Your mind is still wracked with pain causing your "
	    "nerves to not function!%^RESET%^"
	);
    }
    return 1;
}
