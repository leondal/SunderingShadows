#include <std.h>

inherit "/std/riding_animal.c";

private static int regulate;

void create() {
   ::create();
   set_name("hippogriff");
   set_id( ({"hippogriff","hippo"}) );
   set_short("Hippogriff");
   set_long("This is a hippogriff.");
   set_level(10);
  set_riding_level(10);  // added for riding nwp by *Styx*  11/14/03
   set_value(2000);
   set_race("hippogriff");
   set_gender("male");
   set_body_type("hippogriff");
   set_size(3);
   set_max_hp(200);
   set_hd(10,4);
   set_hp(200);
   set_overall_ac(5);
   set_exp(10);
   set_max_distance(20);
   set_enter_room("rides in.");
   set_exit_room("leaves riding a hippogriff.");
   set_vehicle_short("Hippogriff");
   add_limb("beak","head",0,0,0);
   add_limb("right leg","torso",0,0,0);
   add_limb("left leg","torso",0,0,0);
   add_limb("torso","torso",0,0,0);
   add_limb("head","torso",0,0,0);
   set_attack_limbs( ({"beak","right leg","left leg"}) );
   set_attacks_num(3);
   set_damage(1,6);
   regulate = 1;
}

int enter(string str) {
   int lvl,tphp;
   lvl = TP->query_level();
   if( (string)TP->query_race() == "elf" ) {
      tphp = TP->query_hp();
      set_level(lvl);
      set_hp(tphp);
      set_damage(2,lvl / 5);
      if(lvl > 20)
         set_max_hp(10 * lvl);
      set_stats("strength",18);
      set_exp( 100 * lvl );
      if( regulate || query_max_hp() < query_hp() ) {
         set_hp( query_max_hp() );
         regulate = 0;
      }
      return ::enter(str);
   }
   else
      return notify_fail("The hippogrif refuse to let you mount it!\n");
}
