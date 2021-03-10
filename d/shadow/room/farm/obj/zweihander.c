//coded by ~Circe~ 4/6/05
#include <std.h>

inherit "/d/common/obj/weapon/two_hand_sword";

void create(){
   ::create();
   set_name("zweihander");
   set_id(({"sword","two handed sword","zweihander","Zweihander","two-handed sword","blue sword","cobalt sword","greatsword"}));
   set_obvious_short("%^BOLD%^%^BLUE%^a cobalt blue greatsword%^RESET%^");
   set_short("%^BOLD%^%^BLUE%^Zweihander%^RESET%^");
   set_long("%^CYAN%^This greatsword features a blade forged "+
      "from a deep %^BOLD%^%^BLUE%^cobalt blue metal%^RESET%^%^CYAN%^.  "+
      "The thick blade flares a few inches above the hilt "+
      "before narrowing again, giving a more vicious look to "+
      "the blood groove filled with %^RESET%^molten silver "+
      "%^CYAN%^running the length of the blade.  The crosspiece "+
      "is fashioned from %^RESET%^silver %^CYAN%^set with "+
      "three rounded %^YELLOW%^o%^GREEN%^p%^CYAN%^a%^BLUE%^l "+
      "gems%^RESET%^%^CYAN%^.  The hilt is wrapped in "+
      "%^BOLD%^%^BLACK%^black leather %^RESET%^%^CYAN%^"+
      "and ends with a silvered pommel set with a glittering "+
      "round %^YELLOW%^w%^GREEN%^a%^CYAN%^t%^BLUE%^e%^YELLOW%^r "+
      "%^GREEN%^o%^CYAN%^p%^BLUE%^a%^YELLOW%^l%^RESET%^%^CYAN%^.%^RESET%^");
   set_lore("The Zweihander is a greatsword once wielded "+
      "by an order of rangers of Istishia called the "+
      "Disciples of the Yielding Way.  They were guardians "+
      "of the waterways around the cities of Shadow and "+
      "Tabor.  The rangers were known for two things - "+
      "their dedication to their tasks and the two-handed "+
      "swords they wielded.  They were unusual among "+
      "those who follow the ways of the wild, as they "+
      "shunned two weapons in favor of this one.  The "+
      "Disciples began fading around the year 350 SG when "+
      "the orcs who battled the Needles of the Forest "+
      "began spreading their plague more eastward.");
   set_value(175);
   set_property("enchantment",1);
   set_wield((:TO,"wieldme":));
   set_hit((:TO,"hitme":));
}

int wieldme(){
   if((string)ETO->query_diety() == "istishia"){
      tell_object(ETO,"%^CYAN%^The cobalt blade seems to "+
         "ripple like the waves as you grasp its hilt.");
      tell_room(EETO,"%^CYAN%^The cobalt blue blade "+
         "of "+ETOQCN+"'s sword seems to ripply like "+
         "a wave as "+ETO->QS+" grasps its hilt.",ETO);
      return 1;
   }
   if((string)ETO->query_diety() == "kossuth"){
      tell_object(ETO,"%^CYAN%^As you try to "+
         "grasp the hilt of the sword, you are drenched "+
         "in a %^BOLD%^%^BLUE%^torrential downpour%^RESET%^"+
         "%^CYAN%^, and the sword just melts away!");
      tell_room(EETO,"%^CYAN%^As "+ETOQCN+" tries to "+
         "wield the sword, a violent storm %^BOLD%^%^BLUE%^"+
         "soaks %^RESET%^%^CYAN%^"+ETO->QO+" and the "+
         "sword seems to melt away!",ETO);
      TO->remove();
      return 0;
   }
   tell_object(ETO,"%^CYAN%^As you wield the cobalt sword, "+
      "you could almost swear the weight shifts on its own.");
   tell_room(EETO,"%^CYAN%^"+ETOQCN+" seems somewhat "+
      "surprised as "+ETO->QS+" wields the sword.",ETO);
   return 1;
}

int hitme(object targ){
   if(!objectp(targ)) return 1;
   if(!objectp(ETO)) return 1;
   if(!random(9)){
      tell_object(ETO,"%^CYAN%^You skim the tip of the sword "+
         "along the ground in a wide arc, finishing near your "+
         "head.\n%^BOLD%^%^BLUE%^A cresting wave rises from the "+
         "blade and slams into "+targ->QCN+"!");
      tell_object(targ,"%^CYAN%^"+ETOQCN+" skims the tip of "+
         ""+ETO->QP+" sword along the ground in a wide arc, "+
         "ending near "+ETO->QP+" head.\n%^BOLD%^%^BLUE%^"+
         "Suddenly, a cresting wave rises from the blade and "+
         "slams into you!");
      tell_room(EETO,"%^CYAN%^"+ETOQCN+" skims the tip of "+
         ""+ETO->QP+" sword along the ground in a wide arc, "+
         "ending near "+ETO->QP+" head.\n%^BOLD%^%^BLUE%^"+
         "Suddenly, a cresting wave rises from the blade and "+
         "slams into "+targ->QCN+"!",({ETO,targ}));
      if(!random(7)){
         tell_object(ETO,"%^BOLD%^%^CYAN%^You strike at "+
            ""+targ->QCN+" again quickly, while "+targ->QS+" "+
            "is standing drenched and sputtering like an idiot.");
         tell_object(targ,"%^BOLD%^%^CYAN%^You are left "+
            "drenched and sputtering while "+ETOQCN+" "+
            "strikes at you again!");
         tell_room(EETO,"%^BOLD%^%^CYAN%^As "+targ->QCN+" "+
            "stands drenched and sputtering, "+ETOQCN+" "+
            "takes the opportunity for another quick "+
            "attack!",({ETO,targ}));
         ETO->execute_attack();
      }
      return roll_dice(1,8);
   }
}