//Octothorpe (1/28/12)
//Attaya, Spectral Entity for Cursed Titanium Sword
//Original by Thundercracker

#include <std.h>
inherit WEAPONLESS;

void create() {
   ::create();
   set_name("spectral entity");
   set_id(({"spectral entity","entity"}));
   set_short("%^BOLD%^%^BLACK%^sp%^RESET%^e%^BOLD%^%^BLACK%^ctr%^RESET%^"+
      "a%^BOLD%^%^BLACK%^l entity%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This entity is a skeletal figure in a "+
      "spectral form.  The skull is clearly defined, but the rest of "+
	  "the skeletal frame seems to dissolve into the air.  The skull's "+
	  "eye sockets are engulfed with a radiant, %^RESET%^s%^BOLD%^i"+
	  "%^RESET%^lv%^BOLD%^e%^RESET%^r %^BOLD%^%^BLACK%^flame.");
   set_hd(30,5);
   set_max_hp(25);
   set_hp(query_max_hp());
   set_race("undead");
   set_body_type("human");
   set_attack_limbs(({"right hand","left hand","head"}));
   set_ac(0);
   set_exp(1);
   set_property("magic",1);
   set_mob_magic_resistance("average");
   set_attacks_num(1);
   set_damage(3,3);
   command("message in flies in slowly.");
   command("message out flies slowly to the $D.");
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void die(object ob){
   tell_room(ETO,"%^BOLD%^%^BLACK%^With a horrible shriek, the spectral "+
      "entity disperses into nothingness.%^RESET%^");
   TO->remove();
}
