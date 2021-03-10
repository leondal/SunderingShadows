//updated to current code ~Circe~ 10/1/19
#include <std.h>
#include <daemons.h>
#include "../defs.h"

inherit "/d/common/obj/weapon/mace";

int FLAG;

void create(){
   ::create();
   set_name("prismatic mace");
   set_id(({"mace","prismatic mace","scepter","dream mace","sandman's scepter"}));
   set_obvious_short("%^CYAN%^p%^BLUE%^r%^GREEN%^i%^YELLOW%^s%^RED%^m%^MAGENTA%^a%^CYAN%^t%^BLUE%^i%^GREEN%^c %^MAGENTA%^mace%^RESET%^");
   set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^YELLOW%^n%^RESET%^%^ORANGE%^d%^YELLOW%^m%^RESET%^%^ORANGE%^a%^YELLOW%^n%^RESET%^%^ORANGE%^'%^YELLOW%^s %^WHITE%^S%^CYAN%^c%^RESET%^%^CYAN%^e%^RESET%^p%^BOLD%^t%^CYAN%^e%^RESET%^%^CYAN%^r%^RESET%^");
   set_long("%^CYAN%^This unusual mace is crafted of a solid piece of c%^RESET%^o%^CYAN%^r%^RESET%^u%^CYAN%^s%^RESET%^c%^CYAN%^a%^RESET%^t%^CYAN%^i%^RESET%^n%^CYAN%^g %^BOLD%^crystal %^RESET%^%^CYAN%^that has been wrapped in a comfortable grip of %^BOLD%^%^CYAN%^c%^BLUE%^o%^GREEN%^l%^YELLOW%^o%^RED%^r%^MAGENTA%^e%^CYAN%^d %^RESET%^%^CYAN%^leather thongs braided together.  The head of the mace is made of a %^MAGENTA%^violet crystal ball %^CYAN%^surrounded by six curving crystal blades of differing color.  They form a rainbow of color from %^BOLD%^%^RED%^red%^RESET%^%^CYAN%^, %^ORANGE%^orange%^CYAN%^, %^YELLOW%^yellow%^RESET%^%^CYAN%^, %^BOLD%^%^GREEN%^green%^RESET%^%^CYAN%^, %^BOLD%^%^BLUE%^blue%^RESET%^%^CYAN%^, and %^BLUE%^indigo%^CYAN%^.  The base of the hilt has been fitted with an iridescent white leather thong, designed to be worn around the wrist.%^RESET%^");
   set_lore("Crafted from the remnants of scattered dreams and nightmares, the Sandman's Scepter holds the the power to alter a person's mental state.  Its manner of creation is unknown in this realm, but it has been known to exist here.  I can only surmise that a being from the mystical Realm of Dreams crafted such a scepter, and it has found its way here through one of the rare points where the waking world meets the dream. - Matylin the Wise, 'An Account of the Dream Realm'");
   set_property("enchantment",4);
   while((int)TO->query_property("enchantment") != 4){
      TO->remove_property("enchantment");
      TO->set_property("enchantment",4);
   }
   set_item_bonus("caster level",1);
   set_item_bonus("attack bonus",2);
   set_value(3000);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
   set_hit((:TO,"hitme":));
   FLAG = 0;
}

int wieldme(){
    if(member_array("%^BOLD%^%^CYAN%^Lucid Dreams%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"You have not earned the right to make use of this item.");
      return 0;
   }
   if((string)ETO->is_class("cleric")){
      tell_object(ETO,"%^BOLD%^%^CYAN%^Light plays upon the mace as you wield it, leaving you reeling with the might of the Dream Realm!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^CYAN%^Light plays upon the "+TO->query_obvious_short()+" %^BOLD%^%^CYAN%^as "+ETOQCN+" wields it, and "+ETO->QS+" seems to grow in stature!%^RESET%^",ETO);
      set_item_bonus("attack bonus",1);
      FLAG = 1;
      return 1;
   }
   set_item_bonus("attack bonus",0);
   tell_object(ETO,"%^CYAN%^You hear a faint whispering at the edge of your perception as you grip the mace.%^RESET%^");
   tell_room(EETO,"%^CYAN%^"+ETOQCN+" hefts the mace and seems to be listening to something unheard.%^RESET%^",ETO);
   return 1;
   
}

int unwieldme(){
   if(FLAG){
      tell_object(ETO,"%^CYAN%^The mace seems to grow dull and lifeless as you put it aside, and you feel power drain from you.%^RESET%^");
      tell_room(EETO,"%^CYAN%^"+ETOQCN+" seems to diminish as "+ETO->QS+" puts aside the mace.%^RESET%^",ETO);
      FLAG = 0;
      return 1;
   }
   tell_object(ETO,"%^CYAN%^Your mind suddenly grows quiet as you lower the mace.%^RESET%^");
   tell_room(EETO,"%^CYAN%^"+ETOQCN+"'s face suddenly looks clearer as "+ETO->QS+" lowers the mace.%^RESET%^",ETO);
   return 1;
}

int hitme(object targ){
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(11)){
      switch(random(25)){
         case 14..24:
            tell_object(ETO,"%^RED%^The %^BOLD%^red crystal %^RESET%^%^RED%^begins to glow and shoots forth a ray of light at "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^RED%^The %^BOLD%^red crystal %^RESET%^%^RED%^on the mace held by "+ETOQCN+" suddenly glows and blasts you with a ray of light!%^RESET%^");
            tell_room(EETO,"%^RED%^The %^BOLD%^red crystal %^RESET%^%^RED%^on the mace held by "+ETOQCN+" suddenly glows and blasts "+targ->QCN+" with a ray of light!%^RESET%^",({targ,ETO}));
            targ->do_damage(targ->return_target_limb(),roll_dice(1,4));
            break;
         case 9..13:
            tell_object(ETO,"%^ORANGE%^The orange crystal glitters dangerously before exploding in a blast of light at "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^ORANGE%^The orange crystal on "+ETOQCN+"'s mace glitters dangerously before exploding in a blast of light at you!%^RESET%^");
            tell_room(EETO,"%^ORANGE%^The orange crystal on "+ETOQCN+"'s mace glitters dangerously before exploding in a blast of light at "+targ->QCN+"!%^RESET%^",({targ,ETO}));
            targ->do_damage(targ->return_target_limb(),roll_dice(2,4));
            break;
         case 6..8:
            tell_object(ETO,"%^YELLOW%^Light builds in in the yellow crystal, making it vibrate in your hands before unleashing a bolt of lightning at "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^YELLOW%^You see light building in the yellow crystal of the mace held by "+ETOQCN+" before lightning suddenly bursts forth and strikes you!%^RESET%^");
            tell_room(EETO,"%^YELLOW%^Light builds in the yellow crystal of the mace held by "+ETOQCN+" before lightning suddenly bursts forth and strikes "+targ->QCN+"!  BZZT!%^RESET%^",({targ,ETO}));
            ETO->set_property("magic",1);
            targ->do_damage(targ->return_target_limb(),roll_dice(2,6));
            ETO->set_property("magic",-1);
            break;
         case 4..5:
            tell_object(ETO,"%^GREEN%^A sickly %^BOLD%^green mist %^RESET%^%^GREEN%^forms around the green crystal before shrouding "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^GREEN%^A sickly %^BOLD%^green mist %^RESET%^%^GREEN%^forms around the green crystal of the mace held by "+ETOQCN+" before it slithers forth and shrouds you!%^RESET%^");
            tell_room(EETO,"%^GREEN%^A sickly %^BOLD%^green mist %^RESET%^%^GREEN%^forms around the green crystal of the mace held by "+ETOQCN+" before it slithers forth and shrouds "+targ->QCN+"!%^RESET%^",({targ,ETO}));
//            if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death",-4)){
            if(!"daemon/saving_throw_d"->fort_save(targ,-10)){
               targ->add_poisoning(25); //does this still work?
               tell_object(targ,"%^BOLD%^%^GREEN%^Your veins burn with poison!%^RESET%^");
               tell_room(EETO,"%^RED%^"+targ->QCN+" screams in pain!%^RESET%^",targ);
            }else{
               tell_object(targ,"%^GREEN%^You seem to have fought off the effects.%^RESET%^");
            }
            break;
         case 2..3:
            tell_object(ETO,"%^BOLD%^%^BLUE%^The blue crystal seems to shatter, sending a wave of shards at "+targ->QCN+"!\n%^RESET%^%^BLUE%^Miraculously, the crystal is still whole!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^BLUE%^The blue crystal on the mace held by "+ETOQCN+" looks to shatter into countless pieces.  Time stands still...then they all slam into you!%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^BLUE%^A crackling sound fills the air before countless blue shards blast into "+targ->QCN+"!%^RESET%^",({targ,ETO}));
            ETO->set_property("magic",1);
            targ->do_damage(targ->return_target_limb(),roll_dice(2,6));
            targ->set_paralyzed(3+random(4),"You are picking out crystal shards!");
            ETO->set_property("magic",-1);
            break;
         case 1:
            tell_object(ETO,"%^BLUE%^An indigo haze surrounds the crystal, seeming to darken the room around you.\nSuddenly, the crystal %^BOLD%^flares %^RESET%^%^BLUE%^to light, right into "+targ->QCN+"'s eyes!%^RESET%^");
            tell_object(targ,"%^BLUE%^An indigo haze surrounds the crystal on "+ETOQCN+"'s mace, seeming to darken the room around "+ETO->QO+".\nSuddenly, the crystal %^BOLD%^flares %^RESET%^%^BLUE%^to light, right into your eyes!%^RESET%^");
            tell_room(EETO,"%^BLUE%^An indigo haze surrounds the crystal on "+ETOQCN+"'s mace, seeming to darken the room around "+ETO->QO+".\nSuddenly, the crystal %^BOLD%^flares %^RESET%^%^BLUE%^to light, right into "+targ->QCN+"'s eyes!%^RESET%^",({ETO,targ}));
            if(!(int)targ->query_constitution() > random(20)){
               targ->set_temporary_blinded(10,"%^BLUE%^An indigo haze blots out your vision!%^RESET%^");
            }else{
               tell_object(targ,"%^BOLD%^%^BLUE%^You avert your gaze, but the after-image confuses you for a moment!%^RESET%^");
               targ->set_paralyzed(2,"Your eyes are burning!");
            }
            break;
         default:
            tell_object(ETO,"%^MAGENTA%^The orb in the center of your mace %^BOLD%^pulses %^RESET%^%^MAGENTA%^just before the shadow of an ephemeral djinn bursts forth, colliding with "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^MAGENTA%^The orb in the center of "+ETOQCN+"'s mace %^BOLD%^pulses %^RESET%^%^MAGENTA%^just before the shadow of an ephemeral djinn bursts forth, ramming into you!%^RESET%^");
            tell_room(EETO,"%^MAGENTA%^The orb in the center of "+ETOQCN+"'s mace %^BOLD%^pulses %^RESET%^%^MAGENTA%^just before the shadow of an ephemeral djinn bursts forth, colliding with "+targ->QCN+"!%^RESET%^",({targ,ETO}));
            ETO->set_property("magic",1);
            targ->do_damage(targ->return_target_limb(),roll_dice(4,6));
            targ->set_paralyzed(6+random(4),"The laughter of the djinn fills your mind!");
            ETO->set_property("magic",-1);
            break;
      }
      return roll_dice(2,3);
   }
   return roll_dice(1,4);
}