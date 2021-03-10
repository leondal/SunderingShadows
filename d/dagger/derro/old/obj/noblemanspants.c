// updated cha bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;

#define COLS ({"red","green","blue","gray"})
#define COLC ({"%^RED%^","%^GREEN%^","%^BLUE%^","%^BOLD%^%^WHITE%^"})
#define COL_DESC ({"%^RED%^de%^BOLD%^e%^RESET%^%^RED%^p r%^BOLD%^e%^RESET%^%^RED%^d",\
    "%^GREEN%^de%^BOLD%^e%^RESET%^%^GREEN%^p gr%^BOLD%^ee%^RESET%^%^GREEN%^n",\
    "%^BLUE%^de%^BOLD%^e%^RESET%^%^BLUE%^p bl%^BOLD%^u%^RESET%^%^BLUE%^e",\
    "%^WHITE%^de%^BOLD%^e%^RESET%^p gr%^BOLD%^a%^RESET%^y"})
string color, color_desc;


void create(){
    int x;
	::create();
    
	set_name("suede pants");
    x = random(sizeof(COLS));

    color = COLS[x];
    color_desc = COL_DESC[x];

    set_id(({ "pants", color +" suede pants", "suede pants", color +" pants" }));
	
    set_short("%^RESET%^A pair of "+color_desc+"%^RESET%^ suede "+
    "pants");
    
    //set_obvious_short("%^RESET%^A pair of %^RESET%^%^RED%^de%^BOLD%^e%^RESET%^%^RED%^p r%^BOLD%^e%^RESET%^%^RED%^d %^RESET%^suede pants");
	
    set_long("These pants are made of a high quality suede dyed "+
    "a deep, rich "+COLC[x]+color+"%^RESET%^.  Traditional, "+
    "shiny %^YELLOW%^brass buttons %^RESET%^run up the crotch to "+
    "keep them on the wearer.  Fancy %^YELLOW%^gold embroidery "+
    "%^RESET%^runs down the outseams of each leg giving them a "+
    "flashy look.  The supple, soft %^ORANGE%^suede %^RESET%^is "+
    "of the calibre of what nobles would wear, and the quality of "+
    "the craftsmanship adds to that effect.  They are styled in "+
    "a slightly loose fashion to allow the wearer freedom of "+
    "movement.");

	set_weight(3);
	set_value(1000);
	set_lore("It is rumored these pants were originally crafted "+
    "for a gilded youth who wanted aid in his quest to woo his "+
    "lover.  They became especially popular with all young men, "+
    "however, and are highly sought after by officials of "+
    "state, monarchs, high priests, dashing rogues, handsome "+
    "gamblers, and anyone else who wants to look more fashionable.");

	set_property("lore difficulty",9);
	set_type("clothing");
	set_limbs(({ "left leg", "right leg" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
      set("chabonus",1);
}
int wear_func(){
    if(ETO->query_highest_level() < 21) {
        tell_object(ETO,"You're not yet powerfully enough to "+
        "don these.");
        return 0;
    }
	tell_room(environment(ETO),""+ETOQCN+" slips on the suede "+
    "pants and secures the %^YELLOW%^brazen buttons.%^RESET%^",ETO);
	tell_object(ETO,"You slip on the suede pants and secure the "+
    "%^YELLOW%^brazen buttons%^RESET%^, the pants make you feel "+
    "like you could now appear a bit more charming.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" undoes the "+
    "%^YELLOW%^brazen buttons %^RESET%^and removes "+ETO->QP+
    " pants.",ETO);
	tell_object(ETO,"You remove the pants and feel less stylish.");
	return 1;
}
