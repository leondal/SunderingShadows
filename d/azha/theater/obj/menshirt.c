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
"%^BOLD%^%^BLACK%^gray-%^RESET%^%^GREEN%^green",\
"%^BOLD%^%^WHITE%^ivory white",\
"%^BOLD%^%^BLACK%^stormy gray",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r",\
"%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d",\
"%^BOLD%^%^RED%^ruby red",\
"%^BOLD%^%^WHITE%^light cream",\
"%^BOLD%^%^BLACK%^raven black",\
"%^MAGENTA%^wine",\
"%^RED%^blood red",\
"%^CYAN%^sea green"})

int j;
string str, COLOR;


void create(){
      ::create();
      j = random(sizeof(COLORS));
      COLOR = COLORS[j];
	set_name("cotton shirt");
      set_id(({ "shirt","cotton shirt" }));
	set_short("%^RESET%^"+COLOR+" cotton shirt%^RESET%^");
      set_long( "A staple for any man, these cotton shirts cross social"+
		" and racial lines.  The soft washed cotton poplin of the "
		"shirt makes it a favorite, for it's ease in care and "+
		"longevity in wear.  The collarless"+
		" shirt is cut full, as to fit a variety of body types."+
		"  The long sleeves of the shirt puff out before they are"+
		" fitted into tight fitting cuffs.  Shearing at the shoulder"+
		" seams gives a loose draping feel to the shirt.  A deep v"+
		" shaped placket comes down to the middle in the front.  "+
		"Long cotton laces crisscross up the shirt, allowing the "+
		"wearer to choose just how tight to lace the shirt.  This"+
		" cotton has been dyed "+COLOR+", giving a"+
		" sense of style to the utilitarian garment.\n");
    	set_weight(4);
      set_value(700);
      set_lore( "A staple in any man's wardrobe, these shirts are used by"+
		" common folk and noble born alike.  Though there may be some"+
		" variation on the fabrics used or color, the shirts are "+
		"popular with everyone.  Any good theater has a wide selection"+
		" of these shirts on had in all colors.  Most men typically "+
		"wear these kinds of shirts under a jerkin or a jacket, "+
		"though they can be worn alone.  Their simplicity in design"+
		" and fit make them easy for any man to use.  - Dress You Up"+
		" - A History of Clothing and Styles "+
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
	if((string)ETO->query_gender() == "female") {
      	tell_object(ETO,"%^BOLD%^%^GREEN%^You listen to your inner"+
			" voice, passing on wearing the men's shirt.");
             tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->QCN+""+
                	" has second thoughts about wearing the men's shirt.",ETO);
		   		 return 0;
	}
      	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" pulls the stylish"+
	  		" shirt on over his head.",ETO);
        	tell_object(ETO,"%^CYAN%^You pull the shirt on over your head.  "+
	  		"Feeling the softness of the cotton against your "+
			"flesh, you realize why these shirts are so popular."+
			" Don't forget to adjust your %^BLUE%^laces%^CYAN%^.");
        			return 1;
}
int remove_func(){
	  tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" unlaces his shirt and pul"+
	  		"ls it off over his head",ETO);
        tell_object(ETO,"%^CYAN%^You unlace the shirt and pull it off over your "+
	  		"head.");
        			return 1;
}
int laces(string str)
{
 	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed()
|| ETO->query_tripped()) {
    	TP->send_paralyzed_message("info",TP);
       	return 1;
	}

      if(query_worn() && !str) {
         	tell_object(ETO,"%^CYAN%^You fiddle with the laces on the shirt.");
            tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+" fiddles with the"+
		 	" laces on his shirt.",ETO);
                		return 1;
   	}
}