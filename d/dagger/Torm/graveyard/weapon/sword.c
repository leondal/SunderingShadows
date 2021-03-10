#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
  set_id(({"sword", "shortsword"}));
  set_name("shortsword");
  set_short("Shortsword");
   set_long(
	"This is the sword of a Skeleton Warrior."
   );
   set_weight(3);
   set_size(2);
   set("value", 20);
  set_wc(3,3);
  set_large_wc(2,5);
  set_type("slashing");
  set_wield("You grip a fine crafted sword.");
  set_hit("You slice through your opponent!");
  set_property("monsterweapon",1);
 set_hit ((:TO,"extra_hit":)); 
}
int extra_hit() {
    object ob;
    string dam;
    ob=(object)query_wielded()->query_current_attacker();
 
    if(!ob) return 0;
  if(random(6)) return 1;
    if("daemon/saving_d"->saving_throw(ob,"rod_staff_wand")) {
        dam="slightly";
    } else {
       dam="heavily";
    }
    tell_object(ob,
	"The sword drives deep into your chest "+dam+
	" as blood pours from your body!"
    ,ob);
    tell_room(environment(ob),
	"The sword strikes "+ob->query_cap_name()+
	" deep into their chest "+dam+" as blood pours "
	" from their wounds!"
    ,ob);
    if(dam == "slightly") {
       ob->do_damage("head",roll_dice(1,6));
    } else {
       ob->do_damage("head",roll_dice(2,6));
 
       ob->set_paralyzed(30,
	"Your body is unable to move from the deep sword wound!"
       );
    }
    return 1;
}


