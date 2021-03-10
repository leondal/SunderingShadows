// New description by Lurue! Nienne, 05/08.
//Updated by odin to use weapon standardization
#include <std.h>
inherit "/d/common/obj/weapon/pick";
int max;

void create(){
   ::create();
   set_name("pick");
   set_id(({"pick","stonewood pick","stone wood pick","primordial pick"}));
   set_short("%^BOLD%^%^BLUE%^P%^BLACK%^r%^RESET%^%^BLUE%^i%^CYAN%^m%^BOLD%^%^BLUE%^or%^RESET%^%^BLUE%^d%^BOLD%^%^BLACK%^i%^BLUE%^al %^BLUE%^P%^RESET%^%^CYAN%^i%^BLACK%^%^BOLD%^c%^BLUE%^k%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a %^BLUE%^s%^RESET%^%^BLUE%^t%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^n%^BOLD%^%^BLUE%^ew%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^o%^BLUE%^d %^BLACK%^mining pick%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This dark hafted pick is slightly larger then your averaging mining tool.  "
"Created from %^RESET%^%^CYAN%^steel %^BOLD%^%^BLACK%^wrapped %^WHITE%^titanium%^BLACK%^, the pick is both "
"heavy and solid, giving it a good weight for striking into %^RESET%^stone%^BOLD%^%^BLACK%^ or whatever object "
"one might need to hit.  The blending of metals gives the pick a unique coloration which begins as %^RESET%^"
"%^BLUE%^d%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^r%^BLUE%^k b%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^n%^BLUE%^ds "
"%^BOLD%^%^BLACK%^around the spade like half of the fluke and lightens in rippling ribbons of %^BOLD%^%^WHITE%^"
"s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^er %^BLACK%^toward the sharp, narrow tip.  The "
"%^BLUE%^c%^BOLD%^l%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^t%^RESET%^%^BLUE%^h %^BOLD%^%^BLACK%^wrapped haft is "
"created from a slice of petrified %^RESET%^%^BLUE%^sh%^CYAN%^a%^BLUE%^dow%^CYAN%^t%^BLUE%^op%^BOLD%^%^BLACK%^"
", adding an additional counter weight to the tool and giving it a sense of %^WHITE%^a%^RESET%^n%^BOLD%^"
"%^BLACK%^t%^RESET%^i%^BOLD%^%^WHITE%^qu%^BLACK%^i%^WHITE%^ty%^BLACK%^.%^RESET%^");
   set_lore("The Svirfneblin have long held the pick as a sacred weapon, coveting its versatility within the "
"dark realms of the Underdark.  So well respected is this weapon and tool combination that whole clans of "
"crafters are devoted to creating the picks.  Among these crafters, few are as well respected and admired as "
"the Skeesken clan whose underground mines hold a treasure trove of petrified wood which is in turn used to "
"create exceptionally balanced and strong picks from.  The Skeesken Forest, as the mine is called is rumored "
"to have once been a vast primordial forest that was buried under the earth during a volcanic eruption.  "
"Captured within the ash, the wood was preserved and transformed over the centuries into stone.  Though rumor "
"holds that many of these trees still hold the primordial magical essence of the ancient wood within them, and "
"this is why the Skeesken weapons are so coveted.");
   set_property("lore difficulty",8);
   set_value(400);
   set_wield((:TO,"wield_me":));
   set_unwield((:TO,"unwield_me":));
   set_hit((:TO,"hit_em":));
}

int hit_em(object targ){
   if(!objectp(targ)) return 5;
   if(!random(10)){
      tell_room(environment(targ),"%^BOLD%^"+ETO->query_cap_name()+" pierces "+targ->query_cap_name()+" deeply with the pick.",({targ,ETO}));
      tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+" pierces you deeply with a pick.");
      tell_object(ETO,"%^BOLD%^Your pick pierces "+targ->query_cap_name()+"!");
      set_property("magic",1);
      targ->do_damage("torso",random(10));
      return random(6);
   }
   return 0;
}

int wield_me(){
   if((string)TP->query_race() != "gnome") return 1;

   if((int)TP->query_highest_level() > 5){
           max = (int)TP->query_highest_level()/7;
	if(max > 4) max = 4;
	//set_wc(2,3+max); Removing due to weapon standardization.
	//set_large_wc(2,4+max);
        remove_property("enchantment");
// making it grow a little slower *Styx*  2/20/05
       max = (int)TP->query_lowest_level()/7;
	if(max > 5) max = 5;
	set_property("enchantment", max);
        while(query_property("enchantment") < 1){
	   remove_property("enchantment");
    	   set_property("enchantment", max);
        }
   }
   return 1;
}

int unwield_me(){
   remove_property("enchantment");
//   set_wc(2,3);
//   set_large_wc(2,4);
   return 1;
}

int save_me(string file){
   ::save_me(file);
   return 1;
}

void init(){
   ::init();
   if(TP == ETO){
      if((string)TP->query_race()=="gnome") set_ac(1);
      else {
    	remove_property("enchantment");
	set_ac(0);
//	set_wc(2,3);
//        set_large_wc(2,4);
      }
   }
}
