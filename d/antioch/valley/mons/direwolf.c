//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create()
{
      object ob;
	::create();
	set_name("dire wolf");
	set_id(({"dire wolf","wolf","monster","animal"}));
	set_short("A dire wolf");
	set_long(
	"This wolf looks just like many other wolves that you've heard"+
	" of. His fur is a dark grey shade, lighter around the paws"+
	" and face. His mouth is curled into a snarl, showing off his"+
	" dangerously sharp teeth. Ears are perked up, listening for"+
	" sounds, always on guard. Judging from the wolf's coat, he"+
	" is in quite good shape and has been feeding well. He's almost"+
	" double the size of ordinary wolves, making him more dangerous. His"+
	" %^ORANGE%^amber%^CYAN%^ eyes hold your attention, however,"+
	" they seem to look through you to your soul with a piercing"+
	" intelligence. You get the feeling that this is no ordinary"+
	" wolf, but a very deadly dire wolf."
	);
	set_race("wolf");
	set_gender("male");
	set_body_type("quadruped");
	set_hd(15,5);
	set_max_level(25);
	set_size(3);
	set_overall_ac(6);
	set_max_hp(random(50)+130);
	set_hp(query_max_hp());
	add_limb("tail","torso",0,0,0);
//	set_exp(12000);
	set_new_exp(15,"normal");
	set_level(15);
	set_class("fighter");
	set_mlevel("fighter",15);
	set_stats("intelligence",5);
	set_stats("dexterity",17);
	set("aggressive",13);
	set_property("swarm",1);
   set_property("no bows",1);
	set_attack_limbs(({"right forepaw","left forepaw"}));
	set_attacks_num(2);
	set_base_damage_type("slashing");
	set_damage(2,4);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
