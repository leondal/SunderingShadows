#include <std.h>

inherit MONSTER;


void create() {
    ::create();
   set_name("beggar");
   set_id( ({ "beggar" }) );
   set_short("A poor beggar");
   set("aggressive", 0);
   set_speed(60);
   set_moving(1);
   set_gender("male");
  set_level(4);
  set_long("He is a poor beggar looking only for a few coins.\n");
   set_alignment(5);
   set("race", "human");
   set_max_hp(50);
   set_hp(50);
//    set_lang_prof("farsi", 9);
//    set_speech(20, "farsi", ({"Oh my poor missing hand!"}), 0);
   add_limb("head", "FATAL", 25, 0, 4);
   add_limb("torso", "FATAL", 50, 0, 4);
   add_limb("right arm", "right hand", 20, 0, 4);
   add_limb("right hand", "", 15, 0, 4);
   add_limb("left arm", "left hand", 20, 0, 4);
   add_limb("left hand", "", 15, 0, 4);
   add_limb("right leg", "right foot", 25, 0, 4);
   add_limb("right foot", "", 20, 0, 4);
   add_limb("left leg", "left foot", 25, 0, 4);
   add_limb("left foot", "", 20, 0, 4);
   remove_limb("left hand");
}
