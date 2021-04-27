//updated to have a saving throw for trip and not due untyped damage 
//-hades 10/18/20
#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

void create(){
	::create();
	set_name("glass cutlass");
	set_id(({"cutlass","sword","weapon","glass cutlass"}));
	set_short("%^BOLD%^%^WHITE%^U%^RESET%^n%^BOLD%^b%^RESET%^r"+
           "%^BOLD%^e%^RESET%^a%^BOLD%^k%^RESET%^a%^BOLD%^b%^RESET%^l%^BOLD%^e%^RESET%^");
	set_obvious_short("%^RESET%^A %^BOLD%^%^WHITE%^gl%^RESET%^a%^BOLD%^%^WHITE%^ss%^RESET%^ cutlass");
	set_long(
"%^BOLD%^%^WHITE%^This cutlass looks to be made out of perfectly cut %^CYAN%^glass%^WHITE%^."+
" The bladed edge of the cutlass looks to have been sharpened and has a cutting %^BOLD%^%^RED%^blood groove %^WHITE%^along its edge."+
" The basket-handle, also made of glass has been perfectly carved with smooth ridges for comfort while in the hand."+
" Small geometrical etchings have been made in the glass along the basket archs and within the etchings it has been marked with a %^RESET%^%^MAGENTA%^purple ink%^BOLD%^%^WHITE%^."+
" The pommel of the blade is simple and light, just a small pike with a %^RESET%^%^BLUE%^steel tip%^RESET%^."

	);
	set_value(10000);
	set_lore(
" This rare weapon was crafted for the great pirate Remmels. Remmels sailed the coasts of Deku and traded with the continent often through black trade networks with his smuggled goods."+
" While on a raid, he happened upon a wizard who was being held captive by the merchant. On oath of release, the wizard was commissioned to have created (with the help of his most trusted craftsmen, Kerolys) a perfectly glass blade."+
" This had been a dream of the pirate for many years. The blade made and the oath fulfilled, the wizard left the pirate to his days. Not a week later, word of the pirate's ship sunk and the demise was heard throughout the shipyards and cove."+
" Rumors say the pirate survived and the blade still lives on, for this was to have happened thirty years ago."+
" Others say the sword has been spotted near the coastal regions of Torm. Or...it could be at the bottom of the ocean."

	);

	set_property("enchantment",5);
     set_wield((:TO,"wield_func":));
     set_hit((:TO,"hit":));
}
int wield_func(){
   if((int)ETO->query_level() < 30) {
          tell_object(ETO,"You may not wield such a fine weapon!");
          return 0;
          }
          TO->set_overallStatus(100);
          return 1;
     }

int hit(object targ){
   if(!objectp(targ)) return 0;
   if(!random(5)){
      switch(random(4)){
         case 0:
            tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" %^BOLD%^%^BLUE%^lacerates %^BOLD%^%^RED%^"+targ->QCN+" across the chest, letting the blood grooves of the cutlass cause a severe wound!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^RED%^You %^BOLD%^%^BLUE%^lacerate %^BOLD%^%^RED%^your enemy across the chest, causing a severe wound with the grooves of the blade!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" %^BOLD%^%^BLUE%^lacerates%^BOLD%^%^RED%^ you across the chest, leaving a serious wound in its path!%^RESET%^");
        
            break;
         case 1:
            tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+" slips in under the defenses of "+targ->QCN+" and slides the cutlass into unarmored territory!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^You make your way through "+targ->QCN+"'s defenses to deliver a massive blow to unprotected territory!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" finds a way pass your defenses to slip the cutlass into unarmored territory!%^RESET%^");
            
            break;
         case 2:
            tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETOQCN+" slashes up the torso with ease, but then brings the sword back down with force across "+targ->QCN+"'s torso to %^BOLD%^RED%^cross the X%^BOLD%^%^BLUE%^!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^BLUE%^You slash up the chest of your foe and then quickly bring the blade back down across the chest, %^BOLD%^%^RED%^crossing the X%^BOLD%^%^BLUE%^!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" slashes up your chest then quickly back down, %^BOLD%^%^RED%^crossing the X%^BOLD%^%^BLUE%^!%^RESET%^");
       
            break;
         case 3:
            tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" plants "+ETO->QP+" cutlass between "+targ->QCN+"'s legs, tripping "+targ->QO+". Swiftly bringing the glass cutlass up, "+ETO->QCN+" deals a clean blow to "+targ->QCN+".%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^WHITE%^Using the cutlass to trip "+targ->QCN+", you swiftly bring the sword up to slice a clean blow as "+targ->QS+" starts to fall.%^RESET%^");
            tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" plants "+ETO->QP+" cutlass between your legs, tripping you.\n"+
               " As you start to fall down "+ETO->QCN+" swiftly brings "+ETO->QP+" sword up to slice a clean blow into you!%^RESET%^");
            if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-25))
            targ->set_tripped(1,"You're trying to pick yourself up off the ground.");

            break;
         }
      return roll_dice(2,5)+3;
   }
   return 0;
}
