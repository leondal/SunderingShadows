//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Minor tweaks to difficulty and XP to make trails on par with Yntala - Octothorpe 12/26/09
//updated 5/3/04 by Circe with new weapon.

#include <std.h>
#include "../valley.h"
inherit FM_WANDER;

void create(){
	::create();
	set_name("shade");
	set_id(({"shade","undead","monster","human","human shade","man","odd man"}));
	set_short("An odd man");
	set_long(
	"The man standing before you looks almost normal, but there"+
	" is just something not quite right about him. His skin is"+
	" a pale gray in color. He dresses in gray and black tones"+
	" as well, blending into the shadows. There is something"+
	" strange about his eyes...there is no white to his eyes,"+
	" they're completely dark gray. This man must have bonded"+
	" with the stuff of shadows to become a shade."
	);
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_size(2);
	set_property("undead",1);
	set_hd(20,6);
	set_max_level(15);
	set_overall_ac(-2);
	set_max_hp(random(50)+120);
	set_hp(query_max_hp());
	set("aggressive",15);
	set_property("swarm",1);
	set_alignment(6);
	add_money("electrum",random(1000));
	set_class("fighter");
	set_mlevel("fighter",20);
	set_class("mage");
	set_mlevel("mage",20);
	set_level(20);
	set_spells(({"phantom guardians","magic missile","vampiric touch"}));
	set_spell_chance(30);
//        set_exp(11500);
	set_new_exp(20,"normal");
	set_wielding_limbs(({"right hand","left hand"}));
      switch(random(20)){
         case 0..4:  new(OBJ+"shadow_blade")->move(TO);
                     command("wield sword");
                     break;
         case 5..9:  new(OBJ"chainwhip")->move(TO);
                     command("wield whip");
                     break;
         case 10..19:  new("/d/common/obj/weapon/shortsword.c")->move(TO);
                       command("wield sword");
                       break;
         default:  new("/d/common/obj/weapon/shortsword.c")->move(TO);
                       command("wield sword");
                       break;
      }
	if(!random(5)) {
		new(OBJ+"dshield")->move(TO);
	}
	else {
         new("/d/common/obj/armour/shield.c")->move(TO);
	}
	if(!random(10)) {
		new(OBJ+"dhelm")->move(TO);
	}
	else {
            new("/d/common/obj/armour/coif.c")->move(TO);
	}
	if(!random(3)) {
		new(OBJ+"bbelt")->move(TO);
	}
	if(!random(15)) {
		new(OBJ+"bboots")->move(TO);
	}
	command("wearall");
      set_resistance("negative energy",10);
      set_resistance("positive energy",-10);
}
