#include <std.h>

#define MOBS "/d/islands/serakii/mobs/"

inherit "/d/common/obj/weapon/spear_sm.c";


int hit_func;
int wield_func;
int unwield_func;

create() {
   ::create();
   set_id(({"spear","spear of fools","maple rod","ornamental bauble","long ornamental bauble","bauble"}));
   set_name("Spear of Fools");
   set_obvious_short("%^CYAN%^a long %^WHITE%^o%^RESET%^r%^BOLD%^n%^RESET%^a%^BOLD%^"+
   "m%^RESET%^e%^BOLD%^n%^RESET%^t%^BOLD%^a%^RESET%^l %^CYAN%^bauble%^RESET%^");
   set_short("%^CYAN%^S%^WHITE%^p%^BOLD%^%^BLACK%^e%^CYAN%^ar "+
   "of F%^BLACK%^o%^WHITE%^ols%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This appears to be part of a %^CYAN%^jester's "+
   "costume. %^WHITE%^The long maple rod has %^BOLD%^%^BLACK%^burnt roses %^WHITE%^engraved "+
   "from bottom to top. The roses wind around an %^RESET%^ivory bands %^BOLD%^that give the "+
   "spear like object a candy cane effect. The head of the bauble is a o%^RESET%^r%^BOLD%^"+
   "n%^RESET%^a%^BOLD%^m%^RESET%^e%^BOLD%^n%^RESET%^t%^BOLD%^a%^RESET%^l %^BOLD%^s%^RESET%^"+
   "i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r %^BOLD%^b%^RESET%^a%^BOLD%^ll with %^RESET%^"+
   "bells %^BOLD%^and %^BOLD%^%^BLACK%^feathers %^WHITE%^that fall a few inches down the "+
   "length of the rod. Hidden inside the metal ball is a ivory spearhead that only shows "+
   "itself when a secret button on the %^CYAN%^silk wrapped handle %^WHITE%^is pushed.%^RESET%^.");
   set_lore("%^CYAN%^ %^BOLD%^Filantra Lockeheart %^RESET%^%^CYAN%^was said to be the "+
   "best of the best..as far as fools go.  Only the wealthiest of families could even "+
   "think to use her services. Rumor has it the %^BOLD%^%^WHITE%^Spear of Fools "+
   "%^RESET%^%^CYAN%^was a gift given to her from an unknown married man whom she "+
   "found herself involved with for more %^WHITE%^-private- entertainment. %^CYAN%^It "+
   "is also said the spear was always at her side..right  until the time she "+
   "disappeared.%^RESET%^");
   set_property("lore difficulty",20);
   set_value(12000);
   set_property("enchantment",5);
   set_item_bonus("influence",2);
   set_hit((:TO,"hit_func":));
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));

}

int wield_func(){
   if(ETO->query_level() < 25) {
     tell_object(ETO,"%^RED%^You are not experienced enough to use this equipment.%^RESET%^");
     return 0;
   }
    tell_object(ETO,"%^WHITE%^As you wield the %^CYAN%^bauble%^WHITE%^, the %^BOLD%^"+
	"o%^RESET%^r%^BOLD%^n%^RESET%^a%^BOLD%^m%^RESET%^e%^BOLD%^n%^RESET%^t%^BOLD%^"+
	"a%^RESET%^l %^BOLD%^ball %^RESET%^on top begins to %^BOLD%^%^CYAN%^spin.%^RESET%^");
      tell_room(environment(ETO),"%^WHITE%^As"+ETO->query_cap_name()+" wields the "+
	  "%^CYAN%^bauble%^WHITE%^, the %^BOLD%^o%^RESET%^r%^BOLD%^n%^RESET%^a%^BOLD%^"+
	  "m%^RESET%^e%^BOLD%^n%^RESET%^t%^BOLD%^a%^RESET%^l %^BOLD%^ball %^RESET%^on "+
	  "top begins to %^BOLD%^%^CYAN%^spin.%^RESET%^",ETO);
   return 1;
}


int unwield_func(){
      tell_object(ETO,"As you let go of the %^CYAN%^bauble%^WHITE%^, the %^BOLD%^"+
	  "o%^RESET%^r%^BOLD%^n%^RESET%^a%^BOLD%^m%^RESET%^e%^BOLD%^n%^RESET%^t%^BOLD%^"+
	  "a%^RESET%^l %^BOLD%^ball %^RESET%^on top stops %^BOLD%^%^CYAN%^spinning "+
	  "%^RESET%^abruptly.%^RESET%^");
      tell_room(environment(ETO),"As "+ETO->query_cap_name()+" lets go of the "+
	  "%^CYAN%^bauble%^WHITE%^, the %^BOLD%^o%^RESET%^r%^BOLD%^n%^RESET%^"+
	  "a%^BOLD%^m%^RESET%^e%^BOLD%^n%^RESET%^t%^BOLD%^a%^RESET%^l %^BOLD%^ball "+
	  "%^RESET%^on top stops %^BOLD%^%^CYAN%^spinning %^RESET%^abruptly.%^RESET%^",ETO);
      return 1;
   }

int hit_func(object target) {
   object ob, baub;
   if(!objectp(target)) return 0;
   if(random(1000) < 300){
      switch(random(12)){
           case 0..10:
            tell_room(environment(ETO),"%^BOLD%^%^WHITE%^A %^CYAN%^metal "+
			"ball %^WHITE%^flies loose from the %^RESET%^%^CYAN%^bauble %^BOLD%^%^WHITE%^and spins "+
			"out of control around "+target->query_cap_name()+"'s head!",({target,ETO}));
            tell_object(ETO,"%^RESET%^The %^CYAN%^bauble's %^BOLD%^%^WHITE%^"+
			"s%^CYAN%^p%^WHITE%^inning ball %^RESET%^circles "+target->query_cap_name()+" "+
			"head with %^CYAN%^%^BOLD%^dizzying speed%^RESET%^",({environment(ETO),target}));
            tell_object(target, "%^BOLD%^%^WHITE%^A sudden rapid %^CYAN%^spinning %^WHITE%^around "+
			"your head sends you into a %^MAGENTA%^dizzying pause%^RESET%^",({environment(ETO),ETO}));
target->set_paralyzed(3+random(4), "You are still stunned!");
              break;
			  
         case 11:
            tell_room(environment(ETO),"%^CYAN%^The %^WHITE%^%^BOLD%^tiny bells %^RESET%^%^CYAN%^on "+
			"the %^BOLD%^bauble %^RESET%^%^CYAN%^begin to %^YELLOW%^ring %^RESET%^%^CYAN%^out with "+
			"song and start to dance around "+ETO->query_cap_name()+" %^WHITE%^protectively.%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^CYAN%^The %^WHITE%^%^BOLD%^tiny bells %^RESET%^%^CYAN%^on the "+
			"%^BOLD%^bauble %^RESET%^%^CYAN%^begin to %^YELLOW%^ring %^RESET%^%^CYAN%^out with song "+
			"and start to dance around you %^WHITE%^protectively.%^RESET%^",({environment(ETO),target}));
            baub =new(MOBS"bauble");
            baub ->move(environment(ETO));
            ETO->add_protector(baub);
            ETO->add_follower(baub);
             break;
      }
	  return 1;
   }
   }
