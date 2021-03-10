#include <std.h>
inherit "/d/common/obj/lrweapon/longbow";

int mysize;
void setthesize(int setsize);

void create(){
    ::create();
    set_lore("This weapon was said to have been the finest creation of Harresh'nak Dragonbane, a hunter "
"of half-orcish descent.  Once feared across the sands and grasslands, the rocky mountains and the "
"dense forests of the Tsarven empire, he was only ever known to travel alone, and woe to those who "
"accidentally crossed his path.  But as his skill surpassed even the greatest of mercenaries and "
"justicars sent to put an end to his terror, he sought yet greater foes, those beasts and monsters "
"spoken of only in legend and myth.  Beasts of the great depths and the high peaks, whose breath were "
"acid and fire and ice.  He bested many of their number, and the blessings of the Beastlord himself "
"were bestowed upon a bow crafted from a rib of the most fearsome among them, the mighty red dragon "
"Tarr'ginah'sek the Terrible.");
    set_property("enchantment",4);
    set_property("lore difficulty",35);
    set_property("id difficulty",35);
    set_value(7900);
    set_item_bonus("damage bonus",2);
    set_item_bonus("perception",2);
    setthesize(2);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_lrhit((:TO,"extra_lrhit":));
}

void init(){
   int playersize;
   ::init();
   if(!objectp(ETO)) return;
   if(interactive(ETO) && !avatarp(ETO)){
      if(mysize == 2 && (int)ETO->query_size() == 1) {
        tell_object(ETO,"The bow seems to shrink, fitting itself perfectly to your hands.");
        setthesize(1);
      }
      if(mysize != 2 && (int)ETO->query_size() != 1) {
        tell_object(ETO,"The bow seems to lengthen, fitting itself perfectly to your hands.");
        setthesize(2);
      }
   }
}

void setthesize(int setsize) {
    if(setsize == 1) {
      mysize = 1;
      set_size(2);
      set_wc(2,4);
      set_large_wc(2,4);
      set_range(5,10,15);
      set_ammo("shortbow arrow");
      set_name("bone shortbow");
      set_id(({ "short bow","longbow","bow","bone shortbow","runed shortbow","runed shortbow of bone","dragonbone shortbow","dragonbone bow" }));
      set_short("%^RESET%^%^RED%^Dr%^BOLD%^%^RED%^a%^RESET%^%^RED%^go%^BOLD%^%^RED%^n%^RESET%^%^RED%^bo%^BOLD%^%^RED%^n%^RESET%^%^RED%^e Sh%^BOLD%^%^RED%^o%^RESET%^%^RED%^rt%^BOLD%^%^RED%^b%^RESET%^%^RED%^ow%^RESET%^");
      set_obvious_short("%^RESET%^%^RED%^r%^BOLD%^%^RED%^u%^RESET%^%^RED%^n%^BOLD%^%^RED%^e%^RESET%^%^RED%^d %^BOLD%^%^BLACK%^shortbow of %^RESET%^bone%^RESET%^");
      set_long("%^BOLD%^%^BLACK%^This shortbow bears no apparent joins or segmentation, suggesting it "
"has been carved from a single, %^RESET%^%^RED%^massive %^BOLD%^%^BLACK%^piece of bone, perhaps a rib "
"judging by the gentle bend to its length.  It has been carefully worked with an %^RESET%^%^CYAN%^"
"elegant %^BOLD%^%^BLACK%^curve, thickened ridges at intervals for %^RESET%^%^BLUE%^strength"
"%^BOLD%^%^BLACK%^, and it splits to several long, fine %^YELLOW%^spikes %^BOLD%^%^BLACK%^at each end.  "
"It bears %^RESET%^blackened %^BOLD%^%^BLACK%^patches along its shaft, as if burnt by %^RESET%^%^RED%^f"
"%^BOLD%^%^RED%^l%^YELLOW%^a%^RESET%^%^ORANGE%^m%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^, while in other "
"places it is pure, polished %^BOLD%^%^WHITE%^ivory%^BOLD%^%^BLACK%^.  What appears to be sinew, dyed "
"%^RESET%^%^RED%^bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d-r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d%^BOLD%^"
"%^BLACK%^, has been wrapped carefully in the centre of the bow to provide a secure grip for the "
"wielder.  Several dark runes have been etched into its length, and they gleam ma%^RESET%^l%^BOLD%^"
"%^BLACK%^ig%^RESET%^%^RED%^na%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^y, almost like "
"something living, as they run their way down the dark and light of the bone shaft.%^RESET%^\n");
    }
    if(setsize == 2) {
      mysize = 2;
      set_size(3);
      set_wc(2,6);
      set_large_wc(2,6);
      set_range(7,15,21);
      set_ammo("longbow arrow");
      set_name("bone longbow");
      set_id(({ "long bow","longbow","bow","bone longbow","runed longbow","runed longbow of bone","dragonbone longbow","dragonbone bow" }));
      set_short("%^RESET%^%^RED%^Dr%^BOLD%^%^RED%^a%^RESET%^%^RED%^go%^BOLD%^%^RED%^n%^RESET%^%^RED%^bo%^BOLD%^%^RED%^n%^RESET%^%^RED%^e L%^BOLD%^%^RED%^o%^RESET%^%^RED%^ng%^BOLD%^%^RED%^b%^RESET%^%^RED%^ow%^RESET%^");
      set_obvious_short("%^RESET%^%^RED%^r%^BOLD%^%^RED%^u%^RESET%^%^RED%^n%^BOLD%^%^RED%^e%^RESET%^%^RED%^d %^BOLD%^%^BLACK%^longbow of %^RESET%^bone%^RESET%^");
      set_long("%^BOLD%^%^BLACK%^This longbow bears no apparent joins or segmentation, suggesting it "
"has been carved from a single, %^RESET%^%^RED%^massive %^BOLD%^%^BLACK%^piece of bone, perhaps a rib "
"judging by the gentle bend to its length.  It has been carefully worked with an %^RESET%^%^CYAN%^"
"elegant %^BOLD%^%^BLACK%^curve, thickened ridges at intervals for %^RESET%^%^BLUE%^strength"
"%^BOLD%^%^BLACK%^, and it splits to several long, fine %^YELLOW%^spikes %^BOLD%^%^BLACK%^at each end.  "
"It bears %^RESET%^blackened %^BOLD%^%^BLACK%^patches along its shaft, as if burnt by %^RESET%^%^RED%^f"
"%^BOLD%^%^RED%^l%^YELLOW%^a%^RESET%^%^ORANGE%^m%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^, while in other "
"places it is pure, polished %^BOLD%^%^WHITE%^ivory%^BOLD%^%^BLACK%^.  What appears to be sinew, dyed "
"%^RESET%^%^RED%^bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d-r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d%^BOLD%^"
"%^BLACK%^, has been wrapped carefully in the centre of the bow to provide a secure grip for the "
"wielder.  Several dark runes have been etched into its length, and they gleam ma%^RESET%^l%^BOLD%^"
"%^BLACK%^ig%^RESET%^%^RED%^na%^BOLD%^%^BLACK%^nt%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^y, almost like "
"something living, as they run their way down the dark and light of the bone shaft.%^RESET%^\n");
    }
}

int wield_func(){
   if(ETO->query_level() < 30) {
     tell_object(ETO,"You are not experienced enough to use this weapon.");
     return 0;
   }
   tell_object(ETO,"%^RED%^You grip the bow and a rush of adrenaline and heightened awareness runs through your veins!%^RESET%^");
   tell_room(EETO,"%^RED%^"+ETO->QCN+" grips the bow, and "+ETO->QP+" eyes gleam brightly!%^RESET%^",ETO);
   return 1;
}

int unwield_func(){
   tell_object(ETO,"%^RED%^You loose your hold on the bow, and your senses feel dulled.%^RESET%^");
   tell_room(EETO,"%^RED%^"+ETO->QCN+" looses hold on the bow, and "+ETO->QP+" eyes grow dull.%^RESET%^",ETO);
   return 1;
}

int extra_lrhit(object targ){
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 0;
   if(random(1000) < 300){
     switch(random(36)){
       case 0..26:
         tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" launches an arrow and it bursts into brilliant "
"%^BOLD%^%^RED%^f%^YELLOW%^l%^BOLD%^%^WHITE%^a%^BOLD%^%^RED%^m%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^as it "
"seeks its mark!%^RESET%^",ETO);
         tell_object(ETO,"%^BOLD%^%^BLACK%^You launch an arrow and it bursts into brilliant %^BOLD%^"
"%^RED%^f%^YELLOW%^l%^BOLD%^%^WHITE%^a%^BOLD%^%^RED%^m%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^as it seeks "
"its mark!%^RESET%^");
         set_property("magic",1);
         targ->do_damage("torso",random(10)+25);
         set_property("magic", -1);
       break;
       case 27..31:
         tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s eyes %^RESET%^%^RED%^g%^BOLD%^%^RED%^le"
"%^RESET%^%^RED%^am %^BOLD%^%^BLACK%^as "+ETO->QS+" moves with sudden speed, firing arrow after arrow "
"almost effortlessly!",ETO);
         tell_object(ETO,"%^BOLD%^%^BLACK%^The world seems to slow as a rush of %^RESET%^%^RED%^e"
"%^BOLD%^%^RED%^ne%^RESET%^%^RED%^r%^BOLD%^%^RED%^g%^RESET%^%^RED%^y %^BOLD%^%^BLACK%^fills you, and "
"effortlessly you fire arrow after arrow at your foes!");
         ETO->execute_attack();
       break;
       default:
         tell_room(EETO,"%^BOLD%^%^BLACK%^The bone bow gleams %^RESET%^%^RED%^bl%^BOLD%^%^RED%^oo"
"%^RESET%^%^RED%^d-r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^ as "+ETO->QCN+" fires a "
"shot!  It sinks into "+targ->QCN+"'s skin and "+targ->QS+" freezes suddenly!%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^BOLD%^%^BLACK%^The bone bow gleams %^RESET%^%^RED%^bl%^BOLD%^%^RED%^oo"
"%^RESET%^%^RED%^d-r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^ as you loose a shot!%^RESET%^");
         tell_object(targ,"%^BOLD%^%^BLACK%^As the arrow pierces your skin, a %^RESET%^%^BLUE%^snarl "
"%^BOLD%^%^BLACK%^echoes in your ears and a sudden chill of horror runs through you!  You %^BOLD%^"
"%^CYAN%^freeze %^BOLD%^%^BLACK%^almost instinctively!%^RESET%^");
         targ->set_paralyzed((random(4)+6),"You're sure there's nothing behind you... is there?");
        break;
     }
   }
   return 1;
}
