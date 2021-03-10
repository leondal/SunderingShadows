#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

#define eletypes ({"air","water","fire","earth"})

string eletype;

void create(){
   int x;
   x = random(sizeof(eletypes));
   eletype = eletypes[x];
   ::create();
   	set_lore("Fey creature have always had a deep respect for"+
		" nature.  It is not uncommon for the fey to dress "+
		"themselves in garments and accessories that carry a "+
		"nature there.  Thus the creations of gowns and tunics"+
		" for the females and males of the fey races seems like"+
		" the logical next step.  The garments are rumored to be"+
		" woven with plenty of fey magic in them as well as "+
		"infusing each garment with its respectable element.  "+
		"There are rumors that the fey enchant each tunic with"+
            " hidden pockets, to aide in mischief.\n");
   	set_property("lore difficulty",4);
   	set_ac(0);
   	set_weight(5);
   	set_value(200);
	set_property("enchantment",2);
	set_item_bonus("will",1);
	set_item_bonus("reflex",1);
	set_item_bonus("fortitude",1);
   	set_type("clothing");
   	set_limbs(({"torso"}));
      set_max_internal_encumbrance(5);
      set_size(TP->query_size());
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
   	switch(eletype){
case "air":
	TO->set_long("%^BOLD%^%^BLACK%^This fitted tunic is made from"+
		" lightweight silk.  The stormy gray silk tunic is cut "+
		"to fit close to a man's body, showing off his physique."+
		"  Short fitted sleeves are sewn onto the body of the tunic."+
		"  The collarless tunic is trimmed with %^CYAN%^sky blue"+
		"%^BLACK%^ silk bands.  %^WHITE%^M%^RESET%^e%^BOLD%^t%^RESET%^a"+
		"%^BOLD%^l%^RESET%^l%^BOLD%^i%^RESET%^c%^BOLD%^%^BLACK%^ threads"+
		" have been woven into the stormy gray silk, giving it a slight "+
		"sheen.  The lightweight tunic pays tribute to the free flowing"+
		" nature of the air.%^RESET%^\n");
   	TO->set_name("tunic of air");
   	TO->set_short("%^BOLD%^%^BLUE%^Tunic of %^WHITE%^A%^BLACK%^i%^WHITE%^r%^RESET%^");
   	TO->set_obvious_short("%^BOLD%^%^BLACK%^A stormy gray silk tunic%^RESET%^");
   	TO->set_id(({"tunic","shirt","tunic of air"}));
	break;
case "earth":
	TO->set_long("%^GREEN%^This fitted tunic is made from heavy silk."+
		"  Oak leaves cut from %^BOLD%^green%^RESET%^%^GREEN%^ silk"+
		" have been appliqued over the silk base of the tunic.  "+
		"The leaves are so detailed in design and colors that they"+
		" almost seem life like.  The collarless tunic features short"+
		" fitted sleeves that come to the mid bicep of the wearer.  "+
		"The overlapping oak leaves pays tribute to the bounty and "+
		"strength of the earth.%^RESET%^\n");
   	TO->set_name("tunic of earth");
   	TO->set_short("%^RESET%^%^GREEN%^Tunic of %^BOLD%^E%^RESET%^%^GREEN%^a"+
		"%^BOLD%^r%^RESET%^%^GREEN%^t%^BOLD%^h%^RESET%^");
   	TO->set_obvious_short("%^RESET%^%^GREEN%^A green heavy silk tunic%^RESET%^");
   	TO->set_id(({"tunic of the earth","tunic","shirt"}));
	break;
case "fire":
	TO->set_long("%^RED%^This fitted tunic is made from heavy "+
		"%^BOLD%^fiery red%^RESET%^%^RED%^ silk.  The dramatic"+
		" and bold tunic features appliqus of tendrils of "+
		"flames in fiery shades of r%^BOLD%^e%^RESET%^%^RED%^d"+
		", %^ORANGE%^orange%^RED%^, and %^YELLOW%^yellow%^RESET%^"+
		"%^RED%^.  The flames lick around the short sleeves and "+
		"body of the tunic.  The collarless tunic is trimmed with"+
		" metallic %^YELLOW%^gold%^RESET%^%^RED%^ silk bands, further"+
		" increasing the intense visual of this tunic.  The tunic "+
		"pays tribute to the dramatic nature of fire.%^RESET%^\n");
   	TO->set_name("tunic of fire");
   	TO->set_short("%^BOLD%^%^RED%^Tunic of %^RESET%^%^RED%^F%^BOLD%^i%^RESET%^"+
		"%^ORANGE%^r%^YELLOW%^e%^RESET%^");
   	TO->set_obvious_short("%^BOLD%^%^RED%^A fiery red silk tunic%^RESET%^");
   	TO->set_id(({"tunic","shirt","tunic of fire"}));
	break;
case "water":
	TO->set_long("%^CYAN%^This fitted tunic is made from medium weight silk."+
		"  The sea green silk tunic is cut to fit close to a man's body, "+
		"showing off his physique.  Short fitted sleeves are attached to "+
		"the body of the tunic.  The sea green silk features rippling bands"+
		" of %^BLUE%^b%^BOLD%^l%^CYAN%^u%^BLUE%^e%^RESET%^%^BLUE%^s%^CYAN%^"+
		" to illustrate the flowing nature of water.  Bands of %^BOLD%^%^WHITE%^"+
		"white%^RESET%^%^CYAN%^ silk trim the sleeves, neckline and hem of "+
		"the tunic.  The tunic pays tribute to the versatility and strength"+
		" of water.%^RESET%^\n");
   	TO->set_name("tunic of water");
   	TO->set_short("%^RESET%^%^CYAN%^Tunic of W%^BOLD%^%^BLUE%^a%^WHITE%^t"+
		"%^BLUE%^e%^RESET%^%^CYAN%^r%^RESET%^");
   	TO->set_obvious_short("%^RESET%^%^CYAN%^A sea green silk tunic%^RESET%^");
   	TO->set_id(({"tunic","shirt","tunic of water"}));
	break;
	}
}
int wear_func(){
	 if (!userp(ETO)){
      return 1;
   }

// don't see any reason a female can't wear a tunic? Standard wear for travellers/melee. N, 12/13
/*        if((string)ETO->query_gender() == "female") {
        	tell_object(ETO,"%^BOLD%^%^BLACK%^Thinking of everyone who "+
			"will laugh at you, you choose not to wear the tunic.");
        	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
        		" stops to ponder something before she tries to wear the tunic.",ETO);
		return 0;
} */
        tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" pulls the silk tunic on over "+ETO->QP+" head.",ETO);
     	tell_object(ETO,"%^BOLD%^You slide on the silk tunic, feeling the soft "+
		"silk against your skin.");
      return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" slides off his"+
		" silk tunic slowly.",ETO);
     	tell_object(ETO,"%^BOLD%^You slide the silk tunic off slowly, "+
		"enjoying the softness of the silk.");
     	return 1;
}
