
#include <std.h>
inherit WEAPONLESS;

create() {
   ::create();
set_name("%^ORANGE%^toadstool");
set_id(({"toadstool"}));
set("race", "fungi");
set_body_type("snake");
set_short("%^GREEN%^a toadstool");
set_long("%^ORANGE%^This is an ordinary toadstool, except, perhaps the fact that it is about one and a half feet wide.  The dark brown spots almost seem to form a face upon the stem of the fungus.  Wide eyes, and gaping mouth.  How strange.  The cap is milky white with giant dark brown spots and two small bumps that if you used your imagination could be considered to look like ears.  What a strange thing.");
	set("aggressive", 6);
	set_alignment(8);
	set_size(1);
set_stats("intelligence", 8);
set_stats("wisdom", 12);
set_stats("strength", 16);
set_stats("charisma", 5);
set_stats("dexterity", 12);
set_stats("constitution", 12);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_hd(12,0);
	set_exp(350);
	set_max_hp(query_hp());
set_overall_ac(5);
remove_limb("head");
remove_limb("tail");
remove_limb("mouth");
add_limb("stalk", "torso", 0, 0, 0);
add_limb("roots", "torso", 0, 0, 0);
add_limb("gill1", "torso", 0, 0, 0);
add_limb("gill2", "torso", 0, 0, 0);
add_limb("gill3", "torso", 0, 0, 0);
add_limb("gill4", "torso", 0, 0, 0);
add_limb("gill5", "torso", 0, 0, 0);
add_limb("gill5", "torso", 0, 0, 0);
add_limb("gill6", "torso", 0, 0, 0);
add_limb("gill7", "torso", 0, 0, 0);
add_limb("gill8", "torso", 0, 0, 0);
add_limb("gill9", "torso", 0, 0, 0);
add_limb("gill10", "torso", 0, 0, 0);
add_limb("gill11", "torso", 0, 0, 0);
add_limb("gill12", "torso", 0, 0, 0);
set_attack_limbs(({"gill1", "gill2", "gill3", "gill4", "gill5", "gill6", "gill7", "gill8", "gill9", "gill10", "gill11", "gill12"}));
set_attacks_num(12);
set_base_damage_type("piercing");
set_damage(1,2);
}
