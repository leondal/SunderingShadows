//chains that shock room
//6/8/11 hades
#include <std.h>
inherit "/d/common/obj/armour/chain.c";

void create(){
        ::create();
        set_name("shocking chains");
        set_id(({"armor","chains", "chain","shocking chains","dirty
chains"}));
        set_short("%^RESET%^%^ORANGE%^s%^YELLOW%^h%^RESET%^%^ORANGE%^ocking chai%^YELLOW%^n%^RESET%^%^ORANGE%^s%^RESET%^");
        set_obvious_short("dirty chains");
        set_long("%^ORANGE%^These chains look like they were designed to"+
                " secure a small but strong beast.  There are thick "+
                "strands of %^BOLD%^%^BLACK%^iron%^RESET%^%^ORANGE%^ with "+
                "%^BOLD%^%^BLACK%^strange etchings%^RESET%^%^ORANGE%^ into the surface."+
                "  The chains are secured by several locks.  These "+
                "locks look to be secured in some mystical fashion "+
                "as there is no keyhole, just a large %^YELLOW%^yellow gem%^RESET%^%^ORANGE%^ in "+
                "the center that %^YELLOW%^sparks with energy.%^RESET%^ ");
        
                set_lore("These chains are something a rather sick mage "+
                "enchanted to keep a powerful creation in place.  The "+
                "mage captured a whole lightning storm into the gems "+
                "and locked them around the creature.  This can shock "+
                "the creature as well as protect the owner's 'property'.  ");
        set_property("lore",30);
    
        set_value(4000);
        set_size(1);
        set_property("enchantment",4);
        set_item_bonus("charisma",-1);
        set_wear((:TO,"wearme":));
        set_remove((:TO,"removeme":));
        set_struck((:TO,"strikeme":));

}
int wearme(){ 
 
   tell_object(ETO,"%^ORANGE%^You wrap yourself in the"+
   " chains and receive a few unpleasant "+
   "%^YELLOW%^shocks%^RESET%^%^ORANGE%^ in the process.");
   set_property("magic",1);
   ETO->do_damage("torso",random(7)+1);
   set_property("magic", -1);
                return 1;
}
int removeme(){
   tell_object(ETO,"%^ORANGE%^You are glad to be out of these"+
                " disgusting chains.  "+
                                "It is like being someone's property");
        return 1;
}
int strikeme(int damage, object what, object who){
  object *attackers;
  int i;
  
  if(!random(20)) {
     attackers = ETO->query_attackers();
   for(i=0; i < sizeof (attackers); i++) 
          {set_property("magic",1);
		   attackers[i]->cause_typed_damage(attackers[i],0,roll_dice(2,6)+7,"electricity");
           set_property("magic", -1);
          }                   
       
   tell_room(environment(query_worn()),"%^ORANGE%^"+""
   +ETOQCN+"'s chains are struck and let out a burst of %^YELLOW%^sparks.",ETO);
   tell_object(ETO,"%^ORANGE%^The chains erupt into %^YELLOW%^sparks"+
         "%^RESET%^%^ORANGE%^ that %^YELLOW%^arc wildly%^RESET%^%^ORANGE%^ across the room.");
      
       return damage -1;  }
        else
           return damage;
}
