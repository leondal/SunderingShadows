#include <std.h>
#include "../theater.h"
inherit "/std/riding_animal";


void create(){
	::create();
  	set_id(({"horse","wooden horse",}));
  	set_name("wooden horse");
  	set_short("A wooden horse");
  	set_long("%^GREEN%^Carved out of %^WHITE%^cedar%^GREEN%^"+
		", this wooden horse looks proud and majestic.  The wood"+
		"en stallion is crafted to have sleek muscles that give "+
		"it a powerful feeling.  The horse's flowing %^RESET%^gr"+
		"ay mane%^GREEN%^ and %^RESET%^tail%^GREEN%^ is made from"+
		" genuine horse hair, a lavish touch to this wooden crea"+
		"ture.  Dressed in %^CYAN%^steel%^GREEN%^ barding and a "+
		"%^RED%^red%^GREEN%^ and %^BOLD%^%^BLUE%^blue%^RESET%^"+
		"%^GREEN%^ cloth, the wooden horse has a noble and fancy look to it."+
		"  A %^YELLOW%^golden horn%^RESET%^"+
		"%^GREEN%^ rises from the center of the wooden horse's"+
		" head, giving a martial look to the wooden creature." );
  	set_level(10);
  	set_value(1000);
  	set_race("horse");
  	set_gender("male");
  	set_body_type("equine");
	set_size(2);
  	set_max_hp(100);
  	set_hd(10,2);
  	set_hp(100);
  	set_overall_ac(0);
  	set_exp(1000);
  	set_max_distance(100);
  	set_enter_room("rides in");
  	set_exit_room("leaves riding a wooden horse");
  	set_vehicle_short("wooden horse");
  	add_limb("horn", "head", 0,0,0);
	set_attack_limbs(({"right forehoof","left forehoof","horn"}));
  	set_attacks_num(3);
  	set_damage(1,10);
	set_riding_level(12);
  
}


int kill_ob(object victim, int which){
  	int hold;
     	hold = ::kill_ob(victim, which);
		if(objectp(owner) && member_array(victim,(object*)owner->query_attackers()) == -1)
        	if(hold){
           		owner->kill_ob(victim,which);
		} 
        return hold;
}
