#include <std.h>
inherit "/std/armour";

void create() {
  	::create();
  	set_name("ring");
  	set_id(({"ring of protection", "ring", "coral ring"}));
   	set_short("%^BOLD%^%^WHITE%^A %^MAGENTA%^c%^RESET%^%^ORANGE%^"+
		"o%^BOLD%^%^MAGENTA%^r%^RESET%^%^ORANGE%^a"+
		"%^BOLD%^%^MAGENTA%^l%^WHITE%^ ring");
   	set_long("%^BOLD%^%^WHITE%^Made of two kinds of coral this band has an exotic but "+
		"simple charm to it.  Actually this ring is two rings in one it seems.  "+
		"The bottom band is made of white coral and the top made of"+
		" %^MAGENTA%^pink coral.  The bands are cut with a rippling "+
		"pattern that encircles ones finger, with the bands linking "+
		"together.  It almost has a certain glow to it...%^RESET%^\n");
    	set_type("ring");
  	set_ac(0);
  	set_weight(2);
  	set_value(125);
  	set_limbs(({"right hand","left hand"}));
        set_property("enchantment",random(2)+2);
  	set_wear((:TO,"do_wear":));
	set_lore("Sirens favor the use of coral in their jewelry,"+
		" being creatures of the water.  The coral they wear "+
		"in honor of Istishia, the deity of water.  A single"+
		" coral band is said to take fifteen years to create,"+
		" as they grow the coral and manipulate it into its shape."+
		"  Some of these rings are rumored to be infused with the"+
		" watery magic of the sea, granting one the protection of "+
		"the tides.");
	set_property("lore",7);

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
