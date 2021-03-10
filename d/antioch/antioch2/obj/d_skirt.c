#include <std.h>
#include "../antioch.h"

#define SHADES ({"%^BOLD%^%^WHITE%^light%^RESET%^",\
"%^BOLD%^%^BLACK%^dark%^RESET%^",\
"%^BOLD%^%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^e%^RESET%^p",\
"%^BOLD%^%^WHITE%^p%^RESET%^a%^BOLD%^l%^RESET%^e",\
"%^BOLD%^%^WHITE%^bright%^RESET%^"})

#define COLORS ({"%^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^RESET%^",\
"%^RESET%^%^ORANGE%^brown%^RESET%^",\
"%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^",\
"%^BOLD%^%^BLACK%^black%^RESET%^",\
"%^BOLD%^%^WHITE%^white%^RESET%^",\
"%^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^lu%^BOLD%^e%^RESET%^",\
"%^YELLOW%^yellow%^RESET%^",\
"%^RESET%^%^MAGENTA%^purple%^RESET%^"})

inherit DAEMON;

int i, j, val;
string str, FABRIC, STYLE, LENGTH;

void create()
{
	::create();
}

void create_skirt(object obj)
{
   j = random(sizeof(COLORS));
	str = COLORS[j];
   i = random(sizeof(SHADES));
	STYLE = SHADES[i];
	if(str == "%^BOLD%^%^BLACK%^black%^RESET%^" || str == "%^BOLD%^%^WHITE%^white%^RESET%^") {
		STYLE = "lovely";
	}
	switch(random(2)) {
		case 0:
			LENGTH = "short";
			break;
		case 1:
			LENGTH = "long";
			break;
	}

	val = random(40);
	switch(val) {
		case 0..10:
			FABRIC = "cotton";
			obj->set_long("This is a "+LENGTH+" cotton skirt. It has"+
			" been dyed a "+STYLE+" "+str+" shade and is perfect for the spring"+
			" and summer months when it is cooler.");
			break;
		case 11..20:
			FABRIC = "woolen";
			obj->set_long("This is a "+LENGTH+" woolen skirt. It has been"+
			" dyed a "+STYLE+" "+str+" shade and is soft to the touch. It has"+
			" been hand made and is very warm.");
			break;
		case 21..30:
			FABRIC = "satin";
			obj->set_long("This is a "+LENGTH+" satin skirt. It is cool and"+
			" smooth to the touch, a bit dressier than normal, everyday wear."+
			" It has been dyed a "+STYLE+" "+str+" shade and is very lovely.");
			break;
		case 31..40:
			FABRIC = "silk";
			obj->set_long("This is a "+LENGTH+" silk skirt. It has been dyed"+
			" a "+STYLE+" "+str+" shade and is incredibly soft to the touch."+
			" The silk seems to cling close to the wearer's body, but it is"+
			" nice and cool.");
			break;
	}
	obj->set_value(val+1);
	obj->set_weight(2);
	obj->set_name("skirt");
	obj->set_short("A "+LENGTH+" "+str+" "+FABRIC+" skirt");
	obj->set_id(({"skirt","mina_clothing","r_skirt","clothing",""+str+" skirt",""+str+" "+FABRIC+" skirt",""+FABRIC+" skirt",""+LENGTH+" skirt",""+LENGTH+" "+str+" "+FABRIC+" skirt"}));
	obj->set_limbs(({"waist"}));
	obj->set_type("ring");
	obj->set_ac(0);
	obj->set_size(2);
        obj->set_property("repairtype",({ "tailor" }));
}
