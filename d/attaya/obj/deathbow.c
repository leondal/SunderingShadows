//updated by Circe 1/1/05 with new lore, etc.
//converted to new ranged combat system, making a screamer equivalent (stoneskin bypass). N, 12/13.
#include <std.h>
inherit "/d/common/obj/lrweapon/hcrossbow";

void create() {
    ::create();
    set_name("crossbow");
    set_id(({"ethereal crossbow","crossbow","ethereal","bow"}));
    set_obvious_short("%^CYAN%^a crystalline crossbow%^RESET%^");
    set_short("%^BOLD%^%^CYAN%^Ethereal Crossbow%^RESET%^");
    set_long("%^CYAN%^This devastating weapon is most unusual in "+
       "construction.  It looks to be a crossbow made of %^BOLD%^"+
       "crystal %^RESET%^%^CYAN%^with no string whatsoever.  A series of "+
       "%^ORANGE%^leather straps %^CYAN%^and a thin %^ORANGE%^"+
       "leather pad %^CYAN%^may be used to attach the crossbow "+
       "to the forearm of the user for added stability and ease of "+
       "use.  When loaded with the right arrows, this crossbow "+
       "looks to magically project the arrow faster than any normal "+
       "bow ever could.%^RESET%^");
    set_lore("This crossbow is crafted entirely of energy used to "+
       "enchant a crystalline substance and give it the strength "+
       "of steel and the versatility of magic itself, in order to "+
       "pierce even the greatest of arcane protections.  Some "+
       "say that anything crafted of the Kinnesaruda is evil in "+
       "its very nature, while others maintain that evil is only "+
       "found in the way a weapon is used.  This weapon does not "+
       "radiate any aura of evil, though none of good either.");
    set_property("lore difficulty",15);
    set_value(1200);
    set_ammo("arrows");
    set_property("enchantment",5);
    set_item_bonus("attack bonus",3);
   set_item_bonus("spell damage resistance",20);
    set_wield((:TO,"wieldme":));
    set_unwield("You unlatch the leather straps that attach the "+
       "crossbow to your arm.  The glow fades.");
    set_lrhit((:TO,"extra_lrhit":));
}

int wieldme(){
   if((int)ETO->query_lowest_level() < 30){
      tell_object(ETO, "You are far too weak to wield the might of the bow!");
      return 0;
   }
   tell_object(ETO,"You raise the crossbow and attach it to your "+
      "arm.  It begins to glow.");
   tell_room(EETO,"%^YELLOW%^The crossbow begins to glow as "+ETOQCN+" "+
      "attaches it to "+ETO->QP+" arm.",ETO);
   return 1;
}

int extra_lrhit(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(3)){
     tell_object(ETO,"%^BOLD%^%^MAGENTA%^You shoot a glowing arrow of light into your target.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^MAGENTA%^"+ETOQCN+" shoots a glowing arrow of light into "
+targ->QCN+"!%^RESET%^",({ETO,targ}));
     tell_object(targ,"%^BOLD%^%^MAGENTA%^"+ETOQCN+" shoots a glowing arrow of light into you!%^RESET%^");
     TO->set_property("magic",1);
     //targ->do_damage("torso",roll_dice(3,12));
     TO->set_property("magic",-1);
     return roll_dice(2, 6);
   }
   return 0;
}
