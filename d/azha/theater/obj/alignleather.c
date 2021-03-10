//Shar and Diego project - Cythera updated desc and colors 1/05\\
#include <std.h>
inherit "/d/common/obj/armour/leather_plate.c";

string OWNER;

void init() {
 	::init();
    	if(interactive(ETO) && ETO==environment(TO) && !OWNER) OWNER = ETOQN;
}
void create() {
	::create();
   	set_name("leather breastplate");
	set_id(({ "leather","leather armor", "armor", "armour",
		"leather breastplate","breastplate" }));
   	set_short("%^RESET%^%^ORANGE%^poorly formed leather breastplate%^RESET%^");
   	set_obvious_short("%^RESET%^%^ORANGE%^poorly formed leather breastplate%^RESET%^");
   	set_long("%^RESET%^%^ORANGE%^This is a piece of hardened leather that, "+
		"although barely formed, looks like it might have the makings "+
		"of a breastplate.\n%^RESET%^");
	set_lore("Kazim in The Thief from Tharis was known to have "+
		"found a leather breastplate on one of his missions"+
		" to plunder the pockets and houses of the residents of"+
		" Tharis.  This breastplate was rumored to be able to change"+
		" color and form depending on the ethos who ever wears it is."+
		" Kazim's leather breastplate itself has a key role"+
		" in the play, for it reveals to him the killer of Nev'esha."+
		" - The Play and Life of Prenicus -Ovelia Fewenspare.");
   	set_property("lore difficulty",13);
   	set("value",700);
   	set_property("enchantment",2);
   	set_wear((:TO,"do_wear":));
	set_remove((:TO,"remove_func":));
}
int do_wear() {
	int align = ETO->query_alignment();
        if((int)ETO->query_lowest_level() < 10) {
   		notify_fail("%^RESET%^%^ORANGE%^The leather breastplate will not "+
   			"buckle for some reason!");
   		return 0;
}
   	if(interactive(ETO) && (string)ETO->query_name() != OWNER){
	tell_object(ETO,"%^RESET%^%^ORANGE%^The armor rejects you forcefully!");
    		set_property("magic",1);
			ETO->cause_typed_damage(ETO, "torso", random(40), "force");
    		set_property("magic",-1);
		return 0;
	}
		switch(align) {
case 1: case 2: case 3:
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+" "+
		"wears the formless piece of leather and it glows "+
		"reshaping itself into a hardened leather breastplate,"+
		" %^BLUE%^b%^BOLD%^righ%^RESET%^%^BLUE%^t "+
		"%^BOLD%^b%^CYAN%^l%^BLUE%^ue%^CYAN%^ in color,"+
		" that fits "+ETO->QO+" perfectly.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You put on the formless piece of "+
		"leather and it suddenly glows and reshapes into a perfectly "+
		"fitting, hardened leather, %^BOLD%^%^BLUE%^bright blue"+
		"%^CYAN%^ in color.%^RESET%^");
   	set_short("%^RESET%^%^BLUE%^Leather Breastplate of %^BOLD%^Law%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^%^A bright blue leather breastplate%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This leather breastplate is a "+
		"%^BLUE%^b%^BOLD%^righ%^RESET%^%^BLUE%^t %^BOLD%^b%^CYAN%^"+
		"l%^BLUE%^ue %^RESET%^%^CYAN%^color.  The hardened leather"+
		" has been shaped to create the breastplate that protects "+
		"the torso from attacks.  The breastplate is often used by "+
		"one who wished to have some form of protection, without "+
		"wearing a full suit of armor.  Surrounded by a braided"+
		" %^ORANGE%^g%^YELLOW%^o%^RESET%^%^ORANGE%^lden%^CYAN%^"+
		" border in the center of this breastplate is the"+
		" image of a %^BOLD%^%^WHITE%^ white roc%^RESET%^%^CYAN%^"+
		" soaring over a %^RESET%^ fortress like castle"+
		"%^CYAN%^.%^RESET%^\n");
			return 1;
case 4: case 5: case 6:
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" "+
		"wears the formless piece of leather and it glows "+
		"reshaping itself into a hardened leather breastplate,"+
		"%^GREEN%^b%^BOLD%^righ%^RESET%^%^GREEN%^t "+
		"%^BOLD%^%^GREEN%^green%^CYAN%^ in color, that fits"+
		" "+ETO->QO+" perfectly.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You put on the formless piece of "+
		"leather and it suddenly glows and reshapes into a perfectly "+
		"fitting, hardened leather,"+
		"%^GREEN%^b%^BOLD%^righ%^RESET%^%^GREEN%^t %^BOLD%^green"+
		"%^CYAN%^ in color.%^RESET%^");
   	set_short("%^RESET%^%^GREEN%^Leather Breastplate of "+
		"%^BOLD%^Neutrality%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^A bright green leather breastplate%^RESET%^");
	set_long("%^CYAN%^This leather breastplate is a "+
		"%^GREEN%^b%^BOLD%^righ%^RESET%^%^GREEN%^t%^BOLD%^"+
		" green%^RESET%^%^CYAN%^ color.  The hardened leather"+
		" has been shaped to create the breastplate that protects"+
		" the torso from attacks.  The breastplate is often used"+
		" by one who wishes to have some form of protection, "+
		"without wearing a full suit of armor.  Surrounded by "+
		"an %^BOLD%^%^GREEN%^ivy%^RESET%^%^CYAN%^ border in the "+
		"center of the breastplate is the image of a %^RESET%^"+
		"gray owl%^CYAN%^ flying over a %^GREEN%^lush virgin"+
		" forest%^RESET%^%^CYAN%^.%^RESET%^\n");
			return 1;
case 7: case 8: case 9:
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+" "+
		"wears the formless piece of leather and it glows "+
		"reshaping itself into a hardened leather breastplate"+
		", %^RESET%^%^CYAN%^b%^BOLD%^righ%^RESET%^"+
		"%^CYAN%^t %^BOLD%^cya%^RESET%^%^CYAN%^n%^BOLD%^ "+
		"in color, that fits "+ETO->QO+" perfectly.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You put on the formless piece of "+
		"leather and it suddenly glows and reshapes into a perfectly "+
		"fitting, hardened leather, %^RESET%^%^CYAN%^"+
		"b%^BOLD%^righ%^RESET%^%^CYAN%^t %^BOLD%^cya"+
		"%^RESET%^%^CYAN%^n%^BOLD%^ in color.%^RESET%^");
   		set_short("%^RESET%^%^CYAN%^Leather Breastplate of "+
		"%^BOLD%^Chaos%^RESET%^");
    	set_obvious_short("%^CYAN%^A bright cyan leather breastplate%^RESET%^");
	set_long("%^CYAN%^This leather breastplate is a "+
		"%^BOLD%^br%^RESET%^%^CYAN%^i%^BOLD%^ght %^RESET%^"+
		"%^CYAN%^c%^BOLD%^yan%^RESET%^%^CYAN%^ color.  The"+
		" hardened leather has been shaped to create the breastplate"+
		" that protects the torso from attacks.  The breastplate is"+
		" often used by one who wishes to have some form of"+
		" protection, without wearing a full suit of armor.  "+
		"Surrounded by a broken jagged%^BOLD%^%^WHITE%^ silver%^RESET%^"+
		" %^CYAN%^border in the center of the breastplate is "+
		"the image of a %^RED%^red hawk%^CYAN%^ soaring above the "+
		"%^BOLD%^%^WHITE%^snowcapped%^RESET%^%^CYAN%^ peak of a"+
		" %^MAGENTA%^mountain%^CYAN%^.%^RESET%^\n");
			return 1;
default:
	tell_object(ETO,"See a Wiz about this armor.  Your alignment "+
		"is whacked.");
			return 0;
		}
	}
int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+" removes "+
		"the breastplate and it reverts back to a poorly formed piece "+
		"of armor.%^RESET%^",ETO);
	tell_object(ETO,"%^CYAN%^You remove the breastplate and it reverts "+
		"back to a poorly formed piece of leather armor.%^RESET%^");
      	set_short("%^RESET%^%^ORANGE%^poorly formed leather breastplate%^RESET%^");
      	set_obvious_short("%^RESET%^%^ORANGE%^poorly formed leather breastplate%^RESET%^");
		set_long("%^RESET%^%^ORANGE%^This is a piece of hardened leather that, "+
		"although barely formed, looks like it might have the makings "+
		"of a breastplate.\n%^RESET%^");
			return 1;
}

