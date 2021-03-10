#include <std.h>
inherit ARMOUR;
void make_me();


#define COLORS ({"%^BOLD%^%^BLACK%^pitch black",\
"%^BOLD%^%^WHITE%^snow white",\
"%^BOLD%^%^RED%^cardinal red",\
"%^RESET%^%^RED%^blood red",\
"%^RESET%^%^ORANGE%^sunset orange",\
"%^RESET%^%^ORANGE%^walnut brown",\
"%^YELLOW%^goldenrod",\
"%^BOLD%^%^GREEN%^jade green",\
"%^RESET%^%^GREEN%^forest green",\
"%^BOLD%^%^BLUE%^cerulean blue",\
"%^RESET%^%^BLUE%^midnight blue",\
"%^RESET%^%^CYAN%^slate blue",\
"%^BOLD%^%^CYAN%^teal",\
"%^RESET%^%^MAGENTA%^violet",\
"%^BOLD%^%^MAGENTA%^bright pink",\
"%^BOLD%^%^BLACK%^charcoal gray",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^BOLD%^%^BLUE%^sapphire blue",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r",\
"%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d",\
"%^BOLD%^%^RED%^ruby red",\
"%^BOLD%^%^WHITE%^light cream",\
"%^BOLD%^%^BLACK%^raven black",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^MAGENTA%^wine",\
"%^BOLD%^%^MAGENTA%^pale pink",\
"%^CYAN%^sea-green"})

#define types ({"slippers","shoes","high boots","riding boots","sandals","ankle boots"})

void create(){
        ::create();
   	make_me();
   	set_lore("A well stocked costume shop in any theater will always"+
		" have a variety of shoes on hand for the performers.  The shoes"+
		" help to further add detail to the costumes the actors and "+
		"actresses wear, making their roles that more believable.  "+
		"Suede is often used for it's durability and value.  Suede "+
		"keeps better than leather, and is easier to repair as well."+
		" - Dress You Up - A History of Clothing and Styles in the "+
		"Theater - Donetella Versaski.\n");
   	set_property("lore difficulty",7);
        set_ac(0);
       set_property("enchantment",random(2)+1);
   	set_weight(2);
   	set_value(30);
   	set_type("clothing");
   	set_limbs(({"right foot","left foot"}));
   	set_size(random(2)+1); 
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
case "slippers":
	TO->set_long("Crafted from suede, these slippers have been "+
                "dyed "+COLOR+"%^RESET%^.  The padded leather soles of the"+
		" slippers help to ensure the feet are kept safe from harm."+
		"  The rounded toe slippers have been lined with fleece, "+
		"adding a touch of comfort.  While more commonly used by"+
		" nobles for formal occasions, these slippers look as if "+
		"they might offer some protection to ones feet.\n");
   	TO->set_name("slippers");
   	TO->set_short("%^RESET%^"+COLOR+" suede slippers%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" suede slippers%^RESET%^");
   	TO->set_id(({"slippers","suede slippers"}));
	break;
case "shoes":
      TO->set_long("Crafted from suede these shoes have been dyed"+
		" "+COLOR+"%^RESET%^.  The padded leather soles of the shoes"+
		" help to ensure the feet are kept safe from harm.  Pieced"+
		" together in sections, the seams of the shoes help to offer"+
		" a perfect tight fit.  The pointed toes shoes lace up the "+
		"front, letting the wearer determine just how tight to lace "+
		"them.  \n");  
   	TO->set_name("shoes");
   	TO->set_short("%^RESET%^"+COLOR+" suede shoes%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" suede shoes%^RESET%^");
   	TO->set_id(({"shoes","suede shoes"}));   
      break;
case "high boots":
      TO->set_long("Crafted from suede these high boots have been"+
		" dyed "+COLOR+"%^RESET%^.  The padded leather soles of these"+
		" boots help to ensure the feet are kept safe from harm.  "+
		"Running down the back seams are a series of laces, allowing"+
		" for the wearer to slip into these thigh high boots.  The "+
		"suede is soft enough that movement is not compromised, while"+
		" offering some protection to ones feet.\n");
   	TO->set_name("high boots");
   	TO->set_short("%^RESET%^"+COLOR+" suede high boots%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" suede high boots%^RESET%^");
   	TO->set_id(({"boots","suede boots","high boots","suede high boots"}));
      break;
case "riding boots":
      TO->set_long("Crafted from hard suede these riding boots have"+
		" been dyed "+COLOR+"%^RESET%^.  The hard leather soles of the"+
		" boots help to ensure the feet are kept safe from harm.  The "+
		"square toed boots rise to mid shin, the stiff hard suede offering"+
		" protection. Without any laces, ones feet have to be gently forced"+
		" into these boots, creating a tight fit.\n");
   	TO->set_name("riding boots");
   	TO->set_short("%^RESET%^"+COLOR+" suede riding boots%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" suede riding boots%^RESET%^");
   	TO->set_id(({"boots","suede boots","riding boots","suede riding boots"}));
      break;
case "sandals":
      TO->set_long("Crafted from woven suede strips, these sandals "+
		"have been dyed "+COLOR+"%^RESET%^.  The hard leather soles of the"+
		" sandals help to ensure the feet are kept safe from harm.  The "+
		"suede strips work to mold around ones foot, offering a tight fit."+
		"  Three suede strips slip into three %^BOLD%^%^WHITE%^mithril"+
		"%^RESET%^ buckles, offering further control of fit to these sandals.\n");
   	TO->set_name("sandals");
   	TO->set_short("%^RESET%^"+COLOR+" suede sandals%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" suede sandals%^RESET%^");
   	TO->set_id(({"sandals","suede sandals"}));
      break;
case "ankle boots":
      TO->set_long("Crafted from woven suede, these ankle boots"+
		" have been dyed "+COLOR+"%^RESET%^.  The hard leather platform "+
		"soles of the boots help to ensure the feet are kept safe from harm."
		"  Rising to just under the ankles, these boots features lacings on"+
		" the insides; giving the wearer total control over the fit.  A two"+
		" inch heel is attached to each boot.  While the heel might seem "+
		"severe to many, in truth the platform sole helps to distribute the"+
		" weight evenly.\n");
   	TO->set_name("ankle boots");
   	TO->set_short("%^RESET%^"+COLOR+" suede ankle boots%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" suede ankle boots%^RESET%^");
   	TO->set_id(({"ankle boots","suede ankle boots","boots","suede boots"}));
      break;
	}
	TO->add_id("randshoesxxx");
}
