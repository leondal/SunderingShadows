#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
  set_name("burning diamond");
  setenv("MIN", "$N hovers in the air.");
  setenv("MOUT", "$N floats off to the $D.");
  set_id(({"burning diamond","diamond","burning shard","shard"}));
  set_short("%^RESET%^%^RED%^Bu%^BOLD%^rn%^RESET%^%^RED%^ing %^RESET%^%^BOLD%^Di%^RESET%^a%^CYAN%^mo%^RESET%^%^BOLD%^nd%^RESET%^");
  set_long("%^BOLD%^%^WHITE%^This diamond shard is shines brilliantly in the "+
       "light.  Fused inside the crystal clear shard are specks of %^YELLOW%^"+
       "yellow%^WHITE%^, %^BLUE%^blue%^WHITE%^, and %^MAGENTA%^pink%^WHITE%^. "+
       " The shard floats in the air. %^RESET%^ %^RED%^Sparks of fl%^BOLD%^a%^RESET%^%^RED%^me dance around the shard.");
  set_hd(35,5);
  set_max_hp(50);
  set_hp(50);
  set_gender("neuter");
  set_race("shard");
  set_body_type("snake");
  remove_limb("tail");
  remove_limb("mouth");
  remove_limb("head");
  set_ac(0);
  set_exp(1);
  set_mob_magic_resistance("extremely high");
  set_attacks_num(1);
  set_damage(3,3);
  set_attack_limbs(({"torso"}));
  set_base_damage_type("slashing");
  set_property("knock unconscious",1);
  set_base_damage_type("fire");
}
 void die(object ob) {
   //burns when deaded

    if(!objectp(ob) && objectp(TO->query_current_attacker()) )
	  ob = TO->query_current_attacker();
    else {::die(TO); return;}
   tell_object(ob,"%^RED%^Your attack breaks the diamond"+
   " shard and it bu%^BOLD%^rs%^RESET%^%^RED%^ts fire all around you.");
   tell_room(ETO,"%^RED%^The %^RESET%^diamond shard%^RED%^ ex%^BOLD%^pl%^RESET%^%^RED%^odes"+
   " in a fiery burst as "+ob->QCN+" strikes it.",ob);
   ob->cause_typed_damage(ob,0,roll_dice(2,10)+10,"fire");

   ::die(TO);
}
