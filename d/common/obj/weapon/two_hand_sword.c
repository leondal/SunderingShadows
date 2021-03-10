//updated damage per discussions with T.  Circe 5/9/04
#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "two handed sword", "two handed", "two_hand_sword" }));
   set_name("two handed sword");
   set_short("A two handed sword");
   set_long("This is a massive, six foot long sword.  It is quite slow, but you "
     "would never want to be in the way of it in a trained user's hands.  "
     "Once it gets moving the weight and wide blade make it cut deep and often "
     "even break or sever bones.  The hilt is longer than a short or long "
     "sword because it requires two hands for normal size humanoids to even "
     "wield it, hence the name.");
   set_weight(8);
   set_size(3);
   set_value(50);
   set_wc(2,6);
   set_large_wc(2,6);
   set_type("slashing");
   set_weapon_speed(10);
   set_weapon_prof("martial");
   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
