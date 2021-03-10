#include <std.h>
inherit WEAPONLESS;

create() {
  object ob;
    ::create();
   set_name("spider");
   set_id(({"spider","huge spider"}));
   set_short("A huge spider");
   set("long", "This type of large spider is sometimes found in underground "
      "areas.  They are not web builders but instead raving hunters.  This one "
      "has a body that is as large as an elf's torso and her long, many-jointed "
      "legs make her stand about five ft. tall when she rears up to bite.  Her "
      "hairy body and legs are a rusty-red color, darker in places perhaps from "
      "the blood of her victims.");
   set_gender("female");
   set("race", "arachnid");
   set_body_type("arachnid");
   set_alignment(5);
   set_size(2);
   set_hd(10,5);
   set("aggressive", 20);
   set_stats("strength",10);
   set_stats("dexterity",20);
   set_max_hp(query_hp());
   set_exp(200);
   set_hp(random(15)+65);
   set_max_hp(query_hp());
   set_attack_limbs(({"head", "right fore leg", "left fore leg"}));
   set_attacks_num(2);
   set_base_damage_type("piercing");
   set_damage(2,4);
}

