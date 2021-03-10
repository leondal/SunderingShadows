//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create(){
	::create();
	set_name("whipweed");
	set_id(({"whipweed","weed","monster","plant"}));
	set_short("A strange plant");
	set_long(
	"The plant is unlike any vegitation you've seen before. It"+
	" has two thin whip-like stalks which give it the name"+
	" whipweed. It has several small leaves that look like little"+
	" appendages. The body of the plant is spherical and it has"+
	" eight curious little stubs around the base. Its roots are"+
	" buried into the ground and you notice a few animal bones"+
	" scattered about. The whip-like stalks are moving slightly,"+
	" they're quite long, about nine or so feet in length."+
	" Strangely enough there is no breeze to cause the plant's"+
	" movement."
	);
	set_gender("neuter");
	set_race("plant");
	set_body_type("snake");
	set_hd(20,5);
	set_max_level(25);
	set_size(2);
	add_limb("stalk 1","torso",0,0,0);
	add_limb("stalk 2","torso",0,0,0);
	set_property("no stab",1);
   set_property("no bows",1);
	set_overall_ac(4);
	set_max_hp(random(20)+175);
	set_hp(query_max_hp());
	set_level(20);
	set_class("fighter");
	set_mlevel("fighter",20);
	set_alignment(5);
	set_attack_limbs(({"stalk 1","stalk 2"}));
	set_attacks_num(2);
	set_base_damage_type("slashing");
   set_property("no charge",1);
	set_damage(1,10);
	set_stats("intelligence",5);
	set_stats("dexterity",18);
//	set_exp(10500);
	set_new_exp(20,"normal");
	set("aggressive",25);
	set_property("swarm",1);
}

int query_watched()
{
	return 10000;
}
