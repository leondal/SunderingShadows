// New description by Lurue! Nienne, 05/08.
//Changed + to every 7 for kicks - Octothorpe 3/22/10
//Changed WC to reflect weapon standardization
#include <std.h>
inherit "/d/common/obj/weapon/dagger";
int max;

void create(){
   ::create();
   set_name("halfling dagger");
   set_id(({"dagger","halfling dagger","Halfling dagger"}));
   set_short("%^BOLD%^%^WHITE%^D%^RESET%^a%^BOLD%^%^BLACK%^w%^WHITE%^ns%^RESET%^t%^BOLD%^%^BLACK%^a%^WHITE%^r D%^RESET%^a%^BOLD%^%^BLACK%^g%^WHITE%^g%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^");
   set_obvious_short("%^RESET%^an %^BOLD%^i%^RESET%^v%^BOLD%^%^BLACK%^o%^WHITE%^ry %^RESET%^carved dagger");
   set_long("%^RESET%^Carved from %^BOLD%^i%^RESET%^v%^BOLD%^%^BLACK%^o%^WHITE%^ry%^RESET%^, this dagger is "
"polished until it nearly gleams with a pale white %^BOLD%^%^WHITE%^l%^RESET%^u%^BOLD%^%^BLACK%^s%^WHITE%^t"
"%^RESET%^e%^BOLD%^%^WHITE%^r %^RESET%^all its own.  Darkening only along the handgrip where a band of clear "
"%^BOLD%^%^BLACK%^r%^RESET%^a%^BOLD%^%^WHITE%^w%^BLACK%^hi%^RESET%^d%^BOLD%^%^BLACK%^e %^RESET%^has been "
"stretched, the blade keeps its brilliant glow and razor edge, despite the porous materials from which it is "
"made.  Etched into the surface of the blade is a delicate %^BOLD%^%^WHITE%^s%^RESET%^c%^BOLD%^%^BLACK%^r"
"%^WHITE%^ollw%^RESET%^o%^BOLD%^%^BLACK%^r%^WHITE%^k %^RESET%^which serves not only as decoration but "
"functions as a blood groove as well.  Set into the pommel is a circular disk that displays a five pointed "
"star of a %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^a%^WHITE%^rf%^RESET%^i%^BOLD%^%^BLACK%^s%^WHITE%^h "
"%^RESET%^and hanging from the ends of the rawhide strips are tiny pieces of %^BOLD%^%^WHITE%^shell%^RESET%^.");
   set_lore("Among those who have, at one time or another, owned such a blade as this is the pirate Tibbin "
"Shindigger, one time Captain of the Dawnstar.  Said to be a fierce and dangerous pirate captain, Shindigger "
"was in truth a simple halfling man who spent a part of his youth sailing the seas.  And, through fate and "
"fortune, found himself captain of one of the most feared rogue ships in the Saakrune Sea.  Though rumors "
"abound as to just how he came to be captain of the ship, many speculate that he came to possess it when he "
"filched the Dawnstar Dagger from its prior owner and gained the secret word to summon the mysterious ship.  "
"Others claim he won both the dagger and the ship during a very heated game of Pokiir.");
   set_property("lore difficulty",8);
   set_value(400);
   set_wield((:TO,"wield_me":));
   set_unwield((:TO,"unwield_me":));
   set_hit((:TO,"hit_em":));
}

int hit_em(object targ){
   if(!objectp(targ)) return 5;
   if(!random(10)){
      tell_room(environment(targ),"%^BOLD%^"+ETO->query_cap_name()+" cuts "+targ->query_cap_name()+" deeply.",({targ,ETO}));
      tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+" cuts you deeply.");
      tell_object(ETO,"%^BOLD%^You cut "+targ->query_cap_name()+" deeply!");
      set_property("magic",1);
      targ->do_damage("torso",random(10));
      return random(6);
   }
   return 0;
}

int wield_me(){
   if((string)ETO->query_race() != "halfling") return 1;
   //set_wc(2,4); removing due to weapon standardization
  //set_large_wc(2,5);
   if((int)ETO->query_lowest_level() > 5){  // chg. to lowest *Styx*  12/13/04
        max = (int)ETO->query_lowest_level()/7;
	if(max > 4) max = 4;
	//set_wc(2,2+max);
	//set_large_wc(2,3+max);
      remove_property("enchantment");

// making it grow a little slower *Styx*  2/20/05
        max = (int)ETO->query_lowest_level()/7;
    	if(max > 5) max = 5;
    	set_property("enchantment", max);
        while(query_property("enchantment") < 0){
	 remove_property("enchantment");
    	 set_property("enchantment", max);
        }
   }
   return 1;
}


void init(){
   ::init();
   if(TP == ETO){
       if((string)TP->query_race()=="halfling") set_ac(1);
     else {
       set_ac(0);
       remove_property("enchantment");
//       set_wc(1,4);
//	 set_large_wc(1,5);
     }
   }
}

int unwield_me(){
   remove_property("enchantment");
//   set_wc(1,4);
//   set_large_wc(1,5);
   return 1;
}

int save_me(string file){
   ::save_me(file);
   return 1;
}
