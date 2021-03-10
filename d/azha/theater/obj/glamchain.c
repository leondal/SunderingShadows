#include <std.h>
inherit "/d/common/obj/armour/chain.c";
int OWNED;
string owner;


void create(){
        ::create();
      set_name("glamour chain");
      set_id(({ "chain", "chainmail","glamour chain","+
		""glamour chainmail","armour","shirt","+
		""chain shirt","jacket","armor"}));
      set_short("%^BOLD%^%^RED%^G%^RESET%^%^CYAN%^l%^BOLD%^"+
		"%^RED%^a%^RESET%^%^CYAN%^m%^BOLD%^%^RED%^o"+
		"%^RESET%^%^CYAN%^u%^BOLD%^%^RED%^r%^RESET%^%^CYAN%^"+
		" Chainmail%^RESET%^");
      set_obvious_short("%^RESET%^%^CYAN%^A chainmail shirt%^RESET%^");
      set_long( "%^CYAN%^Mithril link have been woven together"+
		" to create this tightly packed chainmail.  The chain "+
		"shirt carries some hefty weight to it,  most likely "+
		"due the metal links.  The chain shirt has short sleeves"+
		" and looks as if it would fit like a tunic, covering from"+
		" hips to shoulders.  Around the neck and shoulders area"+
		" the chainmail has been stained a deeper %^BOLD%^%^BLACK%^"+
		"black%^RESET%^%^CYAN%^ with %^RED%^r%^BLUE%^u%^RED%^"+
		"n%^BLUE%^e%^RED%^s%^RESET%^%^CYAN%^ painted onto the"+
		" dark background.\n%^RESET%^");
      set_read("%^RED%^The runes read:\n"+
		"%^BLUE%^Surprises are to be had when one wears the "+
		"%^CYAN%^Glamour Chainmail%^RESET%^");
	set_language("common");
	set_weight(30);
      set_value(1100);
      set_lore( "Hivetta's Harmony was a play scribed by the"+
		" famous playwrite Ixi Desterl.  Ixi gained"+
		" popularity for his moving operas that enchanted noble and"+
		" common folk alike.  Hivetta's Harmony was premiered"+
		" at The Desert Sun, Azha's famed theater.  Though due to"+
		" some strange happenings at The Desert Sun on "+	
		"opening night, no one has been able to report back what"+
		" kind of opera it was.  All who attended Hivetta's"+
		" Harmony that night were slain, with the church of Tyr"+
		" placing powerful wards around the theater itself."+
		"  Those who adventure into the district around the"+
		" theater claim to hear shrieking and other odd sounds"+
		" coming from the theater still to this day. An enchantee"+
		" came forward to say that Ixi had hired him to create suits"+
		" of chainmail that would create an illusions of normal "+
		"clothing items when worn.  We are only left to guess if"+
		" these chainmails shirts were used in Hivetta's Harmony"+
		" - The Desert Sun: The Rising and Setting of a Legacy -"+
		" Aisha Mydrid");
      set_property("lore difficulty",13);
      set_property("enchantment",3);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
                set_size(TP->query_size());
        }
}
int wear_func() {
	int align = ETO->query_alignment();

        if((int)ETO->query_highest_level() < 21) 
	  {
   		tell_object(ETO, "%^CYAN%^The chainmail shirt falls off of you!");
   		return 0;
	}
if(interactive(ETO) && (string)ETO->query_name() != owner){
	tell_object(ETO,"%^RESET%^%^CYAN%^The armor rejects you forcefully!");
    	set_property("magic",1);
		ETO->cause_typed_damage(ETO, "torso", random(40), "force");
    	set_property("magic",-1);
		return 0;
}
		switch(align) {
case 1: case 2: case 3:
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+"'s"+
		" chainmail changes form "+
		"becoming a tailored red wool jacket.",ETO);
		tell_object(ETO,"%^BOLD%^%^RED%^The chainmail changes"+
		" form, becoming a tailored red wool jacket.%^RESET%^");
   	set_short("%^BOLD%^%^RED%^R%^RESET%^%^RED%^e%^BOLD%^%^RED%^"+
		"d %^RESET%^%^RED%^J%^BOLD%^%^RED%^ack%^RESET%^"+
		"%^RED%^e%^BOLD%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A r%^RESET%^%^RED%^e"+
		"%^BOLD%^d wool jacket%^RESET%^");
   	set_long("%^BOLD%^%^RED%^Fine red wool has been used to "+
		"make this jacket.  The jacket is tailored to fit"+
		" close to the wearer's body, giving them a clean "+
		"tailored look.  Three %^YELLOW%^golden%^RED%^ buttons"+
		" on the front of the jacket allows for it to be closed"+
		" or open with ease.  The sleeves on the jacket have been"+
		" hemmed to stop at the wrists, with little excess cloth"+
		" to get in the way.  Though the jacket might look "+
		"binding or constricting, in truth it is really quite"+
		" comfortable to wear.  A notched collar curves around"+
		" the neck and down the front lapel"+
		" of the jacket.  A faint %^RESET%^p%^BOLD%^i%^RESET%^n"+
		"%^BOLD%^s%^RESET%^t%^BOLD%^r%^RESET%^i%^BOLD%^p%^RESET%^e"+
		"%^BOLD%^%^RED%^ covers the jacket, looking luxurious and"+
		" stylish.%^RESET%^\n");
		return 1;
case 4: case 5: case 6:
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s"+
		" chainmail changes form becoming a tailored blue wool "+
		"jacket.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^The chainmail changes"+
		" form, becoming a tailored blue wool jacket.%^RESET%^");
   	set_short("%^BOLD%^%^BLUE%^B%^BOLD%^l%^RESET%^%^BLUE%^u"+
		"%^BOLD%^e%^RESET%^%^BLUE%^ J%^BOLD%^acke%^RESET%^%^BLUE%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A b%^RESET%^%^BLUE%^l%^BOLD%^ue"+
		" wool jacket%^RESET%^");
   	set_long("%^BOLD%^%^BLUE%^Fine blue wool has been used to make"+
		" this jacket.  The jacket is tailored to fit close to the "+
		"wearer's body, giving them a clean tailored look.  Three "+
		"%^BOLD%^%^WHITE%^bone%^BLUE%^ buttons on the front of the"+
		" jacket allows for it to be closed or open with ease.  "+
		"The sleeves on the jacket have been hemmed to stop at the"+
		" wrists, with little excess cloth to get in the way.  "+
		"Though the jacket might look binding or constricting, "+
		"in truth it is really quite comfortable to wear.  A "+
		"notched collar curves around "+
		"the neck and down the front lapel of the jacket.  A"+
		" faint %^RESET%^p%^BOLD%^i%^RESET%^n%^BOLD%^s%^RESET%^"+
		"t%^BOLD%^r%^RESET%^i%^BOLD%^p%^RESET%^e%^BOLD%^%^BLUE%^"+
		" covers the jacket, looking luxurious and stylish.%^RESET%^\n");
		return 1;
case 7: case 8: case 9:
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s"+
		" chainmail changes form becoming a tailored gray wool jacket.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The chainmail changes form,"+
		" becoming a tailored gray wool jacket.%^RESET%^");
   	set_short("%^BOLD%^%^BLACK%^G%^RESET%^r%^BOLD%^%^BLACK%^a"+
		"%^RESET%^y %^BOLD%^%^BLACK%^J%^RESET%^a%^BOLD%^%^BLACK%^c"+
		"%^RESET%^k%^BOLD%^%^BLACK%^e%^RESET%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A black wool jacket%^RESET%^");
   	set_long("%^BOLD%^%^BLACK%^Fine black wool has been used to make"+
		" this jacket.  The jacket is tailored to fit close to the wearer's"+
		" body, giving them a clean tailored look.  The jacket hangs open,"+
		" as there are no buttons on it.  The sleeves on the jacket have"+
		" been hemmed to stop at the wrists, with little excess cloth to "+
		"get in the way.  Though the jacket might look binding or "+
		"constricting, in truth it is really quite comfortable to"+
		" wear.  A notched collar curves around the neck and down the"+
		" front lapel of the jacket.  A faint %^RESET%^p"+
		"%^BOLD%^i%^RESET%^n%^BOLD%^s%^RESET%^t%^BOLD%^r%^RESET%^i"+
		"%^BOLD%^p%^RESET%^e%^BOLD%^%^BLACK%^ covers the"+
		" jacket, looking luxurious and stylish.%^RESET%^\n");
		return 1;
default:
	tell_object(ETO,"%^B_MAGENTA%^%^BOLD%^%^MAGENTA%^Oh dear!  Somethings"+
		" wrong with your alignment.  Please find a wiz to have"+
		" them look at it.");
		return 0;
		}
}
int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+" removes "+
		"their jacket and it transforms back into a chainmail"+
		" shirt.%^RESET%^",ETO);
	tell_object(ETO,"%^CYAN%^You remove the jacket and it transforms"+
		" back into a chainmail shirt.%^RESET%^");
   	set_short("%^BOLD%^%^RED%^G%^RESET%^%^CYAN%^l%^BOLD%^%^RED%^a"+
		"%^RESET%^%^CYAN%^m%^BOLD%^%^RED%^o%^RESET%^%^CYAN%^"+
		"u%^BOLD%^%^RED%^r%^RESET%^%^CYAN%^ Chainmail%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^A chainmail shirt%^RESET%^");
   	set_long("%^CYAN%^Mithril link have been woven together to create this"+
		" tightly packed chainmail.  The chain shirt carries some hefty weight"+
		" to it,  most likely due the metal links.  The chain shirt has"+
		" short sleeves and looks as if it would fit like a tunic, covering"+
		" from hips to shoulders.  Around the neck"+
		" and shoulders area the chainmail has been stained a deeper "+
		"%^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^ with"+
		" %^RED%^r%^BLUE%^u%^RED%^n%^BLUE%^e%^RED%^s%^RESET%^%^CYAN%^ "+
		"painted onto the dark background.\n%^RESET%^");
		return 1;
}
