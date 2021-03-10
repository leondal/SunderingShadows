#include <std.h>
inherit "/std/armour";
#define COLORS ({"%^BOLD%^%^BLACK%^jet black",\
"%^BOLD%^%^WHITE%^brilliant white",\
"%^BOLD%^%^RED%^crimson red",\
"%^RESET%^%^RED%^scarlet red",\
"%^RESET%^%^ORANGE%^bright orange",\
"%^RESET%^%^ORANGE%^walnut brown",\
"%^YELLOW%^goldenrod",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^RESET%^%^GREEN%^forest green",\
"%^BOLD%^%^BLUE%^sapphire blue",\
"%^BOLD%^%^BLUE%^cerulean blue",\
"%^RESET%^%^BLUE%^midnight blue",\
"%^RESET%^%^CYAN%^slate blue",\
"%^BOLD%^%^CYAN%^aquamarine blue",\
"%^RESET%^%^MAGENTA%^deep purple",\
"%^MAGENTA%^plum",\
"%^BOLD%^%^MAGENTA%^bright pink",\
"%^BOLD%^%^BLACK%^stormy gray",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r",\
"%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d",\
"%^BOLD%^%^RED%^ruby red",\
"%^BOLD%^%^WHITE%^light cream",\
"%^BOLD%^%^BLACK%^raven black",\
"%^MAGENTA%^wine",\
"%^BOLD%^%^MAGENTA%^pale pink",\
"%^CYAN%^sea green"})

int j;
string str, COLOR;

void create(){
     	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
	set_name("velvet shirt");
      set_id(({ "shirt", "velvet shirt"}));
      set_short("%^RESET%^"+COLOR+" velvet shirt%^RESET%^");
      set_long( "This fitted shirt is made from soft high"+
		" quality velvet. The velvet has been dyed an eye pleasing s"+
		"hade of "+COLOR+"%^RESET%^.  The cut of this shirt is popular with"+
		" many for it's comfort and variety.  "+
		"The square neckline of the dress frames the wearer's "+
		"neck and collar bones. Long fitted sleeves help to keep"+
		" a lady warm, and from exposing to much flesh.  The "+
		"front panel of the shirt is made from a heavily "+
		"%^BOLD%^%^BLACK%^b%^RESET%^r%^BOLD%^%^BLACK%^o%^RESET%^c"+
		"%^BOLD%^%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^e%^RESET%^"+
		" pattern, contrasting pleasantly with the velvet.  "+
		"%^BOLD%^%^BLACK%^Ribbon%^RESET%^ trim laces up this "+
		"front panel section, serving as an adornment.\n");
     	set_weight(4);
     	set_value(100);
      set_lore( "A staple in any woman's wardrobe, these shirt are used by"+
		" common folk and noble born alike.  Though there may be some variation on "+
		"the fabrics used or color, the shirts are popular with everyone.  Any good"+
		" theater has a wide selection of these shirts on had in all colors.  The simp"+
		"listic design allows for a woman to accessorize it to her tastes and desires, m"+
		"aking no two shirts the same.  Many priestesses seem to favor these shirts a"+
		"s well, accentuating them with gemstones sacred to their faith.  - Dress You "+
		"Up - A History of Clothing and Styles "+
		"in the Theater - Donetella Versaski");
   	set_property("lore difficulty",7);
    	set_type("clothing");
      set_limbs(({ "torso" }));
      set_size(random(2)+1);
      set_property("enchantment",2);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
void init()
{
	::init();
      	add_action("laces","laces");
}
int wear_func(){
	if((string)ETO->query_gender() == "male") {
                tell_object(ETO,"%^BOLD%^%^CYAN%^You rip the shirt "+
			"to shreds as you try to squeeze into it.");
        	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+""+
        		" rips the shirt to shreads as he tries to squeeze"+
			"into it.",ETO);
				TO->remove();
		return 0;
}
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" looks"+
		" demure as she smooths"+
		" out her velvet shirt.",ETO);
     	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel "+
		"demure as you smooth out the fine velvet of this shirt.  Don't"+
		" forget to smooth out your %^BLACK%^laces%^CYAN%^.");
      return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" turns"+
		" her back to remove her shirt.  Shame on"+
		" you for trying to peek!",ETO);
     	tell_object(ETO,"%^BOLD%^%^CYAN%^You turn your back and"+
		" remove your shirt.  After all a lady never"+
		" reveals too much.");
     	return 1;
}
int laces(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed()|| ETO->query_tripped()) {TP->send_paralyzed_message("info",TP);
   	return 1;
}
	if(query_worn() && !str) {
        	tell_object(ETO,"%^BOLD%^%^BLACK%^You adjust the "+
			"laces on the shirt, keeping them from tangling.");
        	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
			" adjusts the ribbon laces on her shirt, keeping them from tangling.",ETO);
           	return 1;
	}
}
