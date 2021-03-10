//Added lore - Cythera 4/05
#include <std.h>
inherit "/std/armour";

create() {
  ::create();
  	set_name("ring");
   	set_id(({"ring of protection", "ring", "hematite ring"}));
   	set_short("%^BOLD%^%^BLACK%^A hematite ring%^RESET%^");
   	set_long("%^BOLD%^%^BLACK%^This ring is made out of a whole"+
		" piece of hematite that has been carefully carved and"+
		" polished into this ring. Many believe that hematite "+
		"has protective powers, and it is often used as a ward "+
		"or the basis for protective enchantments. The ring "+
		"looks ordinary enough, however, except there's not "+
		"a single scratch on it. .");
    	set_type("ring");
  	set_ac(0);
  	set_weight(2);
  	set("value", 25);
  	set_limbs(({"right hand","left hand"}));
        set_property("enchantment",random(2)+2);
  	set_wear((:TO,"do_wear":));
	set_lore("Hematite is prized by many for its protective powers."+
		"  The stone is used often as a ward of the basis for "+
		"protective enchantments. There are a few Old Wives "+
		"tales of hematite being a bane of were creatures and "+
		"undead.  When then undead and were creatures took hold"+
		" of the Dark Woods and the Dark Trail, hematite was in "+
		"high demand in Antioch.  People would hang strings of "+
		"hematite around their door, in hopes to ward off the "+
		"undead and any other foul creatues.");
	set_property("lore",11);   
}

int do_wear(){
	object *stuff;
	int i,j, flag;
	
	stuff = TP->all_armour();
	j = sizeof(stuff);
	for(i=0;i<j;i++){
      if(!objectp(stuff[i])) continue;
      if((string)stuff[i]->query_type() == "ring"){
//         if(stuff[i]->query_property("enchantment")){
            if(member_array("ring of protection",stuff[i]->query_id()) != -1){
               flag = 1;
               break;
            }
//         }
	}
   }
	if(flag){
		write("%^BOLD%^The magic of the ring already worn prevents you from wearing this one!");
		return 0;
	}
	return 1;
}
