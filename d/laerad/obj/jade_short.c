#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";

void create()
{
   ::create();
   set_obvious_short("A short sword");
   set_name("jade short sword");
   set_obvious_short("%^BOLD%^%^GREEN%^A jade-hilted short sword%^RESET%^");
   set_short("%^BOLD%^%^GREEN%^Dreamblade%^RESET%^");
   set_id(({"sword","short sword","jade short sword","jade-hilted sword","jade-hilted short sword","jade sword","dreamblade","blade","Dreamblade"}));
   set_long("%^BOLD%^%^GREEN%^The blade of this magnificent short sword"+
   " is made of fine steel with a razor sharp edge. The blade curves"+
   " slightly, allowing for easier removal from an opponent. The hilt"+
  ", however, is what truly draws your eye, for it is"+
   " made of a solid piece of polished green jade. Overall the short"+
   " sword looks like a well balanced weapon of exquisite craftsmanship.");
   set_lore("This unusual sword gets its name from the belief that "+
      "jade will help a person have meaningful dreams.  Modeled after "+
      "what was originally a ceremonial blade, this sword is now meant "+
      "to send people to the eternal sleep.");
   set_weight(6);
   set_value(1000);
   //set_wc(2,4);
   //set_large_wc(2,5);
   //set_type("slashing");
   set_property("enchantment",3);
   //set_weapon_speed(3);
   //set_size(1);
   //set_prof_type("small blades");
   set_hit((:TO,"hitme":));
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
}

int wieldme() {
   if((int)ETO->query_highest_level() < 20 && interactive(TP)) {
      tell_object(ETO,"You are not yet ready for such a fine blade.");
      return 0;
   }
   if(ETO->is_class("thief")) {
      tell_object(ETO,"%^BOLD%^%^GREEN%^The jade handle is cool and smooth in your grasp.");
   }
   return 1;
}

int removeme()
{
   if(ETO->is_class("thief")) {
      tell_object(ETO,"You release the well-balanced short sword.");
   }
   return 1;
}

int hitme(object targ)
{
   if(!objectp(targ)) return random(8);
   if(!random(12)) {
      message("my_action","%^BOLD%^Your sword slices through "+targ->query_cap_name()+""+
      " like butter.",ETO);
      message("other_action","%^BOLD%^"+ETO->query_cap_name()+" slices"+
      " "+ETO->query_possessive()+" sword through "+targ->query_cap_name()+""+
      " quite easily.",environment(targ),(({ETO,targ})));
      message("my_action","%^BOLD%^"+ETO->query_cap_name()+"'s sword"+
      " slices easily through your flesh!",targ);
      targ->do_damage("torso",random(10)+5);
      return 1;
   }
   if(!random(20)) {
      message("my_action","%^BOLD%^%^GREEN%^You quickly slip your sword"+
      " up under "+targ->query_cap_name()+"'s guard for a vicious strike.",ETO);
      message("other_action","%^BOLD%^%^GREEN%^"+ETO->query_cap_name()+""+
      " slips "+ETO->query_possessive()+" sword easily under "+targ->query_cap_name()+"'s"+
      " guard for a vicious strike!",environment(targ),(({ETO,targ})));
      message("my_action","%^BOLD%^%^GREEN%^"+ETO->query_cap_name()+""+
      " quickly moves "+ETO->query_possessive()+" sword under your guard,"+
      " landing a vicious blow!",targ);
   targ->do_damage("torso",random(20)+10);
      return 1;
   }
}
