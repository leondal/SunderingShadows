//duel.c - coded by ~Circe~ 4/26/05
#include <std.h>
inherit "/d/common/obj/weapon/rapier";

void create()
{
   	::create();
   	set_name("rapier");
   	set_short("%^RESET%^%^CYAN%^D%^RESET%^u%^BOLD%^e%^RESET%^%^CYAN%^l%^RESET%^");
   	set_obvious_short("%^RESET%^%^CYAN%^an exquisite rapier%^RESET%^");
   	set_id(({"rapier","foil","exquisite rapier","duel","Duel","sword","blade"}));
   	set_long("%^CYAN%^This exquisite rapier is crafted "+
         "from flawless folded %^BOLD%^adamantium%^RESET%^"+
         "%^CYAN%^ that holds a razor edge on both sides.  "+
         "Rather than a true basket, the hilt of the sword is "+
         "protected by a series of %^BOLD%^%^BLACK%^sweeping "+
         "curves %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^"+
         "connecting bars%^RESET%^%^CYAN%^ carved of "+
         "%^BOLD%^%^WHITE%^mithril%^RESET%^%^CYAN%^.  A crosspiece "+
         "made of hammered %^BOLD%^%^WHITE%^mithril %^RESET%^"+ 
         "%^CYAN%^provides a sense of balance and elegance.  "+
         "The hilt is made of crushed and molded %^BOLD%^"+
         "%^WHITE%^mother-of-pearl%^RESET%^%^CYAN%^, and a "+
         "full %^BOLD%^%^WHITE%^pearl %^RESET%^%^CYAN%^is "+
         "set within the center of the %^BOLD%^crossguard"+
         "%^RESET%^%^CYAN%^.  The entire sword has been polished "+
         "to a %^BOLD%^%^WHITE%^mirrored finish%^RESET%^%^CYAN%^, "+
         "right down to the conical pommel.%^RESET%^"); 
   	set_value(2500);
	set_lore("Clearly the sword of a nobleman, the craftsmanship "+
         "of this weapon places it within the upper "+
         "reaches of society.  The mother-of-pearl hilt has "+
         "long been in fashion among the nobles of the land, "+
         "and it is considered a mark of honor to bear a blade "+
         "with such riches.  There are some nobles who would "+
         "consider it an insult to see a commoner with such "+
         "a weapon, though...the one who could take it would "+
         "surely be able to defend himself, one would hope.");
   	set_property("enchantment",3);
   	set_hit((:TO,"hitme":));
      set_wield((:TO,"wieldme":));
      set_unwield((:TO,"unwieldme":));
}

int wieldme(){
int i;
object *weapons;
   if((string)ETO->query_name() == "Cassius") return 1;
   if((int)ETO->query_stats("dexterity") < 16){
      tell_object(ETO,"%^BOLD%^%^CYAN%^You don't have the grace to "+
         "even begin thinking of how to us so fine a rapier.");
      return 0;
   }
   if(member_array("Defeated Cassius in a Duel",ETO->query_mini_quests()) == -1) {
      tell_object(ETO,"%^BOLD%^%^CYAN%^You've not yet earned the "+
         "the right to wield such a rapier!  Seek out the true owner "+
         "for a challenge.");
      return 0;
   }
   weapons = ETO->query_wielded();
   if(sizeof(weapons)){
      if(weapons[0]->id("Duel")){
         tell_object(ETO,"%^CYAN%^You may not wield two such "+
            "exquisite rapiers at once!");
         return 0;
      }
   }
   tell_object(ETO,"%^BOLD%^%^CYAN%^You draw the rapier with a "+
      "flourish, noting how it perfectly fits your palm.");
   tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" draws "+ETO->QP+" "+
      "rapier with a dramatic flair.",ETO);
   return 1;
}

int unwieldme(){
   tell_object(ETO,"%^BOLD%^%^CYAN%^You swing the rapier quickly before "+
      "putting it away.");
   tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" swings the rapier in a "+
      "quick arc before putting it away.",ETO);
   return 1;
}

int hitme(object targ){
int dmg = roll_dice(2,4);
int i;
object *weapons;
object obj;
string ids;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   if(!random(7)) {
      switch(random(10)){
         case 0..7:  tell_object(ETO,"%^CYAN%^You parry "+targ->QCN+"'s "+
                     "attack and strike back with a confident riposte!");
                     tell_object(targ,"%^CYAN%^With amazing speed, "+
                     ""+ETOQCN+" parries your attack and launches "+
                     "one of "+ETO->QP+" own!");
                     tell_room(EETO,"%^CYAN%^With amazing speed, "+
                     ""+ETOQCN+" counters "+targ->QCN+"'s attack "+
                     "with one of "+ETO->QP+" own!",({ETO,targ}));
                     targ->do_damage("torso",dmg);
                     set_property("magic",1);
                     ETO->do_damage("torso",-1*dmg);
                     set_property("magic",-1);
                     break;
         default:  tell_object(ETO,"%^BOLD%^%^RED%^You thrust your "+
                   "rapier into "+targ->QCN+", leaving a small "+
                   "puncture wound!");
                   tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" lunges "+
                   "at you and thrusts "+ETO->QP+" rapier into you, "+
                   "leaving a burning puncture wound!");
                   tell_room(EETO,"%^BOLD%^%^RED%^With a well-practiced "+
                   "grace, "+ETOQCN+" lunges at "+targ->QCN+", creating "+
                   "a small puncture wound with "+ETO->QP+" rapier!",({ETO,targ}));
                   obj = new("/d/dagger/Torm/obj/puncture");
                   obj->move(targ);
                   obj->hurt(targ);
                   break;
      }
      return 1;
   }
   if(!random(45)){
      weapons = targ->query_wielded();
      if(sizeof(weapons)){
         if((int)weapons[0]->query_property("enchantment") < 0){
//tell_object(ETO,"%^BOLD%^%^MAGENTA%^Warning, cursed item!");
            return 1;
         }
         tell_object(ETO,"%^BOLD%^%^BLUE%^You sense an opening in "+
            ""+targ->QCN+"'s defenses and move to strike!  Foolish "+
            ""+targ->query_race()+", "+targ->QS+" dropped "+targ->QP+" "+
            "weapon when you hit "+targ->QP+" hand!");
         tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" moves with "+
            "fantastic speed, striking the back of your hand before "+
            "catching your weapon with "+ETO->QP+" rapier and sending "+
            "it skittering to the ground!");
         tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" moves with "+
            "fantastic speed, striking the back of "+targ->QCN+"'s hand before "+
            "catching "+targ->QP+" weapon with "+ETO->QP+" rapier and sending "+
            "it skittering to the ground!",({ETO,targ}));
         ids = weapons[0]->query_id();
         targ->force_me("unwield "+ids[0]+"");
         targ->force_me("drop "+ids[0]+"");
         return 1;
      }
   }
   return 1;
}
