#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"spider","hunting spider","steeder","giant spider","giant hunting spider"}));
  set_name("steeder");
  set_short("A giant hunting spider");
  set_long("Giant hunting spiders such as these are known as steeders, and are a mount usually reserved for "
"the nobility, as anyone less would not be worthy of riding a sacred spider.  The spiders themselves are not "
"web-spinners, but can cling to any surface with their sticky feet, and leap up to 240ft at a time even when "
"carrying a rider.  A complex saddle has been secured to its back, to allow for a single rider.  It is covered "
"in dark fur and carries markings similar to a tarantula, and is an impressive mount indeed.");
  set_value(125);
  set_race("spider");
  set_body_type("arachnid");
  set_gender("neuter");
  set_max_hp(50);
  set_hd(10,10);
  set_size(2);
  set_max_distance(500);
  set_enter_room(" leaps in on a giant spider.");
  set_exit_room(" leaps out of the area atop a giant spider.");
  set_vehicle_short("A giant hunting spider");
  set_riding_level(9);
  TO->force_me("message in skulks in.");
  TO->force_me("message out skulks out $D.");
  set_funcs(({"special"}));
  set_func_chance(10);
  set_attack_limbs(({"left pincer","right pincer"}));
  set_attacks_num(2);
  set_damage(2,4);
  set_stats("strength",14);
  set_stats("dexterity",19);
  set_overall_ac(-6);
  set_property("knock unconscious",1);
}

void special(object target) {
   if (!objectp(target)) return;
   tell_room(ETO,"%^ORANGE%^The spider rears up, and grabs "+target->QCN+" tightly with its sticky forelegs!"
"%^RESET%^",target);
   tell_object(target,"%^ORANGE%^The spider rears up, and grabs you with its sticky forelegs!%^RESET%^");
   target->set_paralyzed(10,"%^ORANGE%^The spider has you held fast!%^RESET%^");
   call_out("special2",5,target);
   return;
}

void special2(object target) {
   if (!objectp(target)) return;
   if (!objectp(TO)) return;
   tell_room(ETO,"%^ORANGE%^"+target->QCN+" manages to struggle free of the spider's grip.%^RESET%^",target);
   tell_object(target,"%^ORANGE%^You manage to struggle free of the spider's grip!%^RESET%^");
   target->set_paralyzed(0);
   return;
}
