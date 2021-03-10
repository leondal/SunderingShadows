//update by Shar.  Added in by Circe 4/26/04
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("red coat");
	set_id(({ "coat", "red coat" }));
	set_short("%^BOLD%^%^RED%^Red Coat%^RESET%^");
	set_obvious_short("A smelly %^BOLD%^%^RED%^red coat%^RESET%^");
	set_long(
         "%^BOLD%^%^RED%^This red coat is disgusting.  It smells of "+
         "spilled food, sweat, rum, and other even less savory smells.  "+
         "Sweat stains under the arms of the coat have permanantly "+
         "discolored this cotton coat.  The coat looks to have been "+
         "a lightly padded garment of fine quality at one time.  Now "+
         "it seems ruined beyond repair.  You suspect that wearing this "+
         "coat will not make you a popular individual.\n%^RESET%^");
      set_weight(8);
	set_value(75);
	set_lore(
         "This red coat looks like one that one might find in the city "+
         "of Tharis, made by the tailor Pepe.  The high grade cotton "+
         "used to construct this coat seems to lead one to belive as if "+
         "it was once a fine quality garment.  Now, it seems infused with "+
         "sweat and other foul odors.  You doubt even soaking this coat "+
         "in perfume would get rid of the smell.");
	set_type("clothing");
	set_limbs(({"torso"}));
	set_size(2);
        set_property("enchantment",2);
	set_item_bonus("charisma",-1);
	set_item_bonus("attack bonus",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
   if(ETO->query_highest_level() < 15) {
     tell_object(ETO,"%^BOLD%^You can't begin to figure out how to wear this ruined coat.%^RESET%^");
     return 0;
   }
	tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETOQCN+" puts on a red coat "+
         "and you get a wiff of the worst odor you have ever smelled.",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You are disgusted by the smell "+
         "of the coat.");
	return 1;
}
int remove_func(){
	tell_room(EETO,"%^BOLD%^%^WHITE%^You can breathe easier after "+
         ""+ETOQCN+" removes "+ETO->QP+" smelly red coat.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You remove the coat and smell "+
         "a little better, but you still need a bath.");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 150){
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^"+who->QCN+" "+
         "looks as if "+who->QS+" is ready to vomit as they gag on the "+
         "stench from the smelly red coat that "+ETOQCN+" is "+
         "wearing.",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^RED%^"+who->QCN+" seems to gag as "+
         ""+ETO->QS+" gets close to you, looking as if "+who->QS+" "+
         "is about ready to vomit.");
	tell_object(who,"%^BOLD%^%^RED%^What the hell is that smell?!  "+
         "It smells worse that sour milk, body sweat, rancid meat, "+
         "and feces combined.  The smell makes you sick at your stomach "+
         "and you can't help but gag! %^GREEN%^Better take a moment to "+
         "calm your stomache before you vomit.");
		who->set_paralyzed((random(3)+ 1)*5);
return damage;	}
}
