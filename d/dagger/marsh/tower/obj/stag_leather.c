#include <std.h>
inherit "/d/common/obj/armour/leather.c";

void create(){
	::create();
	set_name("leather of the stag");
	set_id(({ "leather", "stag leather", "leather armor", "leather of the stag" }));
	set_short("%^RESET%^%^ORANGE%^Leather of the %^BOLD%^%^BLACK%^S%^RESET%^t"+
		"%^BOLD%^%^BLACK%^a%^RESET%^g%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^Soft leather armor with"+
		" a stag image%^RESET%^");
	set_long("%^ORANGE%^This leather armor is crafted out of "+
		"buttery soft leather.  The leather seems on the thin"+
		" side, but feels as strong as the thickest hide.  "+
		"Crafted into a shirt and kilt rather than a typical"+
		" suit of armor, the leather offers comfort and "+
		"protection.  Cut to fit tight against the skin, the"+
		" leather molds to the body of the wearer, increasing"+
		" it's protection abilities.  A leather kilt is "+
		"attached to the body of the armor, protecting the "+
		"legs from danger.  The kilt, common for men to wear,"+
		" is studded with %^YELLOW%^bronze%^RESET%^%^ORANGE%^ "+
		"discs.  %^BOLD%^%^BLACK%^Burnt%^RESET%^%^ORANGE%^ "+
		"into the leather on the front torso of the armor is "+
		"the image of a mighty proud %^BOLD%^%^BLACK%^s%^RESET%^"+
		"t%^BOLD%^%^BLACK%^a%^RESET%^g%^ORANGE%^ with a powerful "+
		"looking rack of horn.  %^RESET%^");
	set_value(1200);
	set_lore("The Leather of the Stag is a suit of armor prized by"+
		" rangers and those that live in the wilds.  The armor "+
		"is said to have been crafted by an elven mage by the "+
		"name of Olindal.  Olindal crafted the armor to honor "+
		"the services of the human ranger Kalab Greenleave.  "+
		"Kalab fought a hard and long battle long side the elves "+
		"to protect the forest form a trio of evokers who wished "+
		"to burn the forest down.  Olindal and the other elves "+
		"were so touched that a human would fight along side them "+
		"to protect the woods that a need was felt to honor the "+
		"ranger.  Olindal selected to use a stag for the front of "+
		"the armor, as a symbol of masculinity and male fertility. "+
		" The elven wizard was also rumored to have infused the "+
		"essence of nature into the armor.");
	set_property("lore difficulty",10);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
string long;
   if(!interactive(ETO)) return 1;
	if((string)ETO->query_gender() == "female") {
		tell_object(ETO,"%^BOLD%^This armor seems to have been "+
			"crafted for a man's body.");
            tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
                	" just can't seem to squeeze herself into the masculine armor.",ETO);
		   		 return 0;
	}
	if((string)ETO->query_diety() == "mielikki"){
		tell_object(ETO,"%^ORANGE%^You slip into the leather with"+
			" ease and admire the image of the stag.");
		tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" slips into the leather"+
			" with ease and takes a moment to admire the image of the stag.",ETO);
   	}else{
		tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" exhales "+
         		"deeply, squeezing himself into the fitted leather.",ETO);
		tell_object(ETO,"%^BOLD%^%^GREEN%^You slip into the fitted leather, "+
         		"having to exhale deeply to squeeze yourself into it.");
	}
	long = ETO->query_long();
      ETO->set("long","%^ORANGE%^"+capitalize(nominative(ETO))+" is cloaked "+
         "in a rich masculine musk scent.");
	return 1;
}
int remove_func(){
string long;
   if(!interactive(ETO)) return 1;
	if((string)ETO->query_diety() == "mielikki"){
		tell_object(ETO,"%^GREEN%^You slip out of the leather with"+
			" ease and admire the proud image of the stag.");
		tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" slips out of the leather"+
			" with ease and takes a moment to admire the image of the stag.",ETO);
   	}else{
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" pulls "+
         "off the leather, taking a moment to catch "+
         "his breath.",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You pull the leather off, "+
         "taking a moment to catch your breath.");
	}
	long = ETO->query_long();
      ETO->set("long");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 75){
	tell_room(environment(query_worn()),"%^GREEN%^A ghostly image of "+
		"a stag charges out of "+ETOQCN+"'s leather armor and "+
		"rams into "+who->QCN+", knocking "+who->QO+" down.",({ETO,who}));
	tell_object(ETO,"%^GREEN%^A ghostly image of a stag charges out of"+
		" your armor and rams into "+who->QCN+", knocking "+who->QO+" down.");
	tell_object(who,"%^GREEN%^A ghostly image of a stag charges out of"+
		" "+ETOQCN+"'s armor and rams into you, knocking you down!");
		who->set_paralyzed(random(4),"%^ORANGE%^You are picking yourself back up.");
	}
}