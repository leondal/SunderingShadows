#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_name("rogue suit");
        set_id(({ "suit", "rogue suit" }));
        set_short("%^BOLD%^%^BLACK%^R%^BLUE%^o%^BLACK%^gue's S%^RESET%^%^"+
	  	"BLUE%^u%^BOLD%^%^BLACK%^it%^RESET%^");
        set_obvious_short("%^BOLD%^%^BLACK%^A black suit%^RESET%^");
        set_long( "%^BOLD%^%^BLACK%^This black suit has a streamline look"+
	  	" to it.  The top and pants of this suit are sew in one continuou"+
	  	"s piece, offering a better fit to the outfit.  Made from thin bl"+
	  	"ack leather it almost looks like an iconic rogue's suit.  The ta"+
	  	"pered legs of the suit are made to fit close to the wearer's bod"+
	  	"y, to close one might think.  The top part of this garment is ma"+
	  	"de to look like a sleeveless jerkin, and again fitting very clos"+
	  	"e to the wearer's body.  A deep V down the front of the suit see"+
	  	"ms to be the only way into the garment, that sure looks like a t"+
	  	"ight fit.  A lightly embroidered pattern of %^RESET%^%^BLUE%^d%^"+
	  	"BOLD%^a%^RESET%^%^BLUE%^g%^BOLD%^%^BLACK%^ge%^BLUE%^r%^BLACK%^s "+
	  	"in %^RESET%^%^BLUE%^dark blue%^BOLD%^%^BLACK%^ and black threads"+
	  	" is sewn into the top of the suit, almost blending in with the d"+
	  	"ark black leather.%^RESET%^\n");
        set_weight(4);
        set_value(300);
        set_lore( "The Thief of Tharis was one of the most successful pla"+
	  	"ys scribed by Prenicus.  Drawing on romance, action, suspense, m"+
	  	"ystery and betrayal Prenicus was able to pen his finest work man"+
	  	"y say.  In The Thief of Tharis the title character, Karim, wages"+
	  	" a war against the city of Tharis for the hand of an elven maide"+
	  	"n named Nev'esha.  The Thief of Tharis is a staple favorite for "+
	  	"many, for it always draws a large crowd and is always wildly suc"+
	  	"cessful.  Many sages count it as one of the 10 best plays of all"+
	  	" time.  - The Play and Life of Prenicus - Ovelia Fewenspare.");
        set_property("lore difficulty",14);
        set_type("clothing");
        set_limbs(({ "torso" }));
        set_size(2);
        set_property("enchantment",2);
	set_item_bonus("stealth",1);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
}
int wear_func(){
	if(!ETO->is_class("thief")){
   		tell_object(ETO,"%^CYAN%^You fumble with the suit and can't seem to fig"+
   			"ure how to wear it.");
      		return 0;
        }
        if((int)ETO->query_lowest_level() < 15) {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^You fumble with the suit but can't"+
			" figure how to get inside of it.%^RESET%^");
      		return 0;
	}
        if (member_array((string)ETO->query_body_type(), ({ "plump",
"hardy" ,"stocky", "portly", "stout", "brawny", "massive",
"rotund","heavy" }) ) != -1 ){      
		tell_object(ETO,"%^BOLD%^%^BLUE%^You can't squeeze into that!");
                return 0;}
        	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" manages to"+
	  		" slip into the body molding suit.",ETO);
        	tell_object(ETO,"%^BOLD%^%^BLACK%^You manage to slide into the suit.");
        		return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" fights to peel the"+
		" suit off, finally managing to get it off.",ETO);
      tell_object(ETO,"%^BOLD%^%^BLACK%^You fight to peel the suit off, "+
	  	"wow that was a tight fit.");
        		return 1;
}
