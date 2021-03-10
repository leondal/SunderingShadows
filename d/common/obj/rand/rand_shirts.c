#include <std.h>
inherit ARMOUR;
void make_me();


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
"%^CYAN%^sea-green"})

#define types ({"silk","linen","velvet","suede"})

void create(){
   	make_me();
      set_weight(4);
   	set_value(30);
	set_property("enchantment",1);
   	set_type("clothing");
   	set_limbs(({"torso"}));
   	set_size(random(3)+1); 
}

void make_me(){
int i,x;
   string type, COLOR;
    i = random(sizeof(COLORS));
       COLOR = COLORS[i];
    x = random(sizeof(types));
       type = types[x];
   ::create();
       switch(type){
case "silk":
	TO->set_long("Fashioned from light silk is this short "+
		"sleeved shirt.  The silk has been dyed "+COLOR+"%^RESET%^"+
		", bringing out the slight luster that silk possesses.  "+
		"The short sleeved shirt is made to slide over the head, "+
		"giving it a relaxed feeling.  A pointed collar on the "+
		"shirt lays loose, as silk has hardly any stability.  "+
		"The silk looks soft and luxurious.\n");
   	TO->set_name("silk shirt");
   	TO->set_short("%^RESET%^"+COLOR+" silk shirt%^RESET%^");
     	TO->set_id(({"shirt","silk shirt"}));
	break;
case "linen":
      TO->set_long("Fashioned from crisp linen is this long sleeved shirt."+
		"  The linen has been dyed "+COLOR+"%^RESET%^, bringing out "+
		"the richness of the fabric.  The long sleeved shirt is "+
		"crafted with %^BOLD%^%^WHITE%^e%^YELLOW%^l%^WHITE%^e"+
		"%^YELLOW%^c%^WHITE%^t%^YELLOW%^r%^WHITE%^u%^YELLOW%^m"+
		"%^RESET%^ buttons up the front, making it easier to get"+
		" the right fit. Tone on tone stripes travel vertically "+
		"around the shirt, giving it a fashionable look. A rounded"+
		" collar circles around the neck."+
		"  The linen looks crisp and sharp, as well as being very "+
		"comfortable.\n");  
   	TO->set_name("linen shirt");
   	TO->set_short("%^RESET%^"+COLOR+" linen striped shirt%^RESET%^");
      TO->set_id(({"shirt","linen shirt"}));   
      break;
case "velvet":
      TO->set_long("Soft plush velvet is used to fashion this rich and"+
		" noble looking shirt.  The velvet fibers soak up most of "+
		"the light, deepening the "+COLOR+"%^RESET%^ of the shirt."+
		"  The long sleeved shirt is made to slide over the head, "+
		"leaving the elegant fabric untouched.  A V shaped placket "+
		"allows for air to move freely inside the heavy velvet shirt,"+
		" and flashes a bit of skin.  The velvet looks incredibly soft"+
		" and luxurious.\n");
   	TO->set_name("velvet shirt");
   	TO->set_short("%^RESET%^"+COLOR+" velvet shirt%^RESET%^");
      TO->set_id(({"velvet shirt","shirt"}));
      break;
case "suede":
      TO->set_long("Soft but heavy suede is used to fashion this"+
		" rustic shirt.  The brushed suede brings out the "+
		"natural nape of the leather, making it feel and look"+
		" very soft and touchable.  The suede has been dyed "+
		" "+COLOR+"%^RESET%^.  The short sleeved shirt is"+
		" crafted with %^BOLD%^ivory%^RESET%^ buttons up the "+
		"front, making it easier to get the right fit.  The "+
		"collarless shirt looks very utilitarian and comfortable.\n");
   	TO->set_name("suede shirt");
   	TO->set_short("%^RESET%^"+COLOR+" suede shirt%^RESET%^");
	TO->set_id(({"suede shirt","shirt"}));
      break;
	}
}