//spear2.c two handed spear from M+O island
//"hit_me" messages changed for clarification.  Circe 12/8/03
//updated by Circe 6/14/04 with new idea by Shar

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit "/d/common/obj/weapon/spear_lg";

void create(){
  ::create();
  set_name("spear of the ancients");
  set_id(({"spear","long","long spear","Long spear","spear of the ancients","ancient spear","aged spear","aged long spear"}));
  set_obvious_short("an aged long spear");
  set_short("%^RESET%^%^ORANGE%^Spear of the Ancients%^RESET%^");
  set_long(
     "%^RESET%^%^ORANGE%^This long spear is made cured wood that "+
     "is wonderfully light and strong.  The wood is a %^RED%^deep "+
     "red %^ORANGE%^nearly the color of %^RED%^teak%^ORANGE%^.  "+
     "The spear haft is more supple than teak, however, and gives "+
     "slightly to blows, allowing them to be deflected without "+
     "breaking the spear.  The spear is tipped with an unusual "+
     "stone - it would seem to be a %^BOLD%^%^WHITE%^dia%^CYAN%^m"+
     "%^WHITE%^ond%^RESET%^%^ORANGE%^, except that it has taken on "+
     "an aged %^YELLOW%^yellow hue%^RESET%^%^ORANGE%^.  The "+
     "head is tied on with rough twine, the ends of which dangle "+
     "freely and support large, colorful %^BOLD%^%^RED%^fea%^MAGENTA%^"+
     "th%^RED%^ers%^RESET%^%^ORANGE%^ that dance about on the wind.%^RESET%^");
  set_lore("The tribal culture of the native Tonerrans is one "+
     "that places heavy value on shamanism and totems.  The "+
     "natives have strong ties to their past, particularly "+
     "to their ancestors, and they believe that this spear "+
     "holds some of that ancient spirit.  At times it seems "+
     "they are right, as the spirit seems to guide the wielder's "+
     "hand.  The feathers are said to be taken from an aarakocra "+
     "though the natives never harm these peaceful bird creatures.");
  set_value(185);
  set_hit((:TO,"hit_me":));
  set_property("enchantment",(random(2)+2));
  set_wield((:TO,"wieldme":));
  set_unwield((:TO,"unwieldme":));
}

int hit_me(object targ){
    if(!objectp(targ)) return 0;
   if(!random(5)){
      switch(random(10)){
         case 0..4:  tell_object(ETO,"%^RESET%^%^ORANGE%^With your "+
            "feet planted firmly on the earth, you feel the power of "+
            "the ancient ones guide your spear into "+targ->QCN+"!");
                     tell_object(targ,"%^RESET%^%^ORANGE%^"+ETOQCN+" "+
            "plants "+ETO->QP+" feet upon the earth and impales you "+
            "upon "+ETO->QP+" spear!");
                     tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" "+
            "plants "+ETO->QP+" feet upon the earth and impales "+
            ""+targ->QCN+" upon "+ETO->QP+" spear!",({targ,ETO}));
                     targ->do_damage("torso",random(5)+5);
                     break;
         case 5..7:  set_property("magic",1);
                     tell_object(ETO,"%^GREEN%^The power of the jungle "+
            "flows through you, and you surge with energy, smacking "+
            ""+targ->QCN+" with the haft before piercing "+targ->QO+" "+
            "with the point!");
                     tell_object(targ,"%^GREEN%^"+ETOQCN+" smacks you "+
            "with the haft of the spear before turning it quickly and "+
            "piercing your chest!");
                     tell_room(EETO,"%^GREEN%^"+ETOQCN+" smacks "+
            ""+targ->QCN+" with the haft of the spear before turning it "+
            "quickly and piercing "+targ->QP+" chest!",({ETO,targ}));
                     ETO->execute_attack();
                     set_property("magic",-1);
                     break;
         case 9:  set_property("magic",1);
                  tell_object(ETO,"%^RED%^You feel the ancient spirits "+
            "well up inside your spear, guiding your hand towards a "+
            "vicious blow against "+targ->QCN+"!");
                  tell_object(targ,"%^RED%^"+ETOQCN+" snarls viciously "+
            "and impales you on "+ETO->QP+" spear!");
                  tell_room(EETO,"%^RED%^"+ETOQCN+" snarls viciously and "+
            "impales "+targ->QCN+" on "+ETO->QP+" spear!",({targ,ETO}));
                  targ->do_damage("torso",random(8)+10);
                  ETO->set_paralyzed(1,"You are pulling the "+
                     "spear back!");
                  set_property("magic",-1);
                  break;
      }
      return random(4);
   }
   return random(3);
}

int wieldme(){
   tell_object(ETO,"%^RESET%^%^ORANGE%^You feel the pride of the "+
      "ancient ones surround you as you heft the spear.%^RESET%^");
   tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" hefts the spear "+
      "with a noble look as the %^BOLD%^%^RED%^fea%^MAGENTA%^"+
      "th%^RED%^ers%^RESET%^%^ORANGE%^ dance on the wind.%^RESET%^",ETO);
   return 1;
}

int unwieldme(){
   tell_object(ETO,"%^RESET%^%^ORANGE%^You feel somehow isolated "+
      "as you lower the ancient spear.");
   tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" gazes around "+
      "slowly with somber eyes as "+ETO->QS+" lowers the spear.",ETO);
   return 1;
}
