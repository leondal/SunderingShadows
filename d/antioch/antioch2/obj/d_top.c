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

void create_top(object obj)
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
			LENGTH = "short sleeved";
			break;
		case 1:
			LENGTH = "long sleeved";
			break;
	}

	val = random(40);
	switch(val) {
		case 0..10:
			FABRIC = "cotton";
			obj->set_long("This is a light "+LENGTH+" cotton shirt. It has"+
			" been dyed a "+STYLE+" "+str+" shade and is very comfortable."+
			" It has a scoop necked cut and is obviously made for a woman.");
			break;
		case 11..20:
			FABRIC = "woolen";
			obj->set_long("This is a warm "+LENGTH+" woolen shirt. It has been"+
			" dyed a "+STYLE+" "+str+" shade and is quite soft. It has a high"+
			" neckline for it is meant to be worn during the winter months to"+
			" keep a lady warm.");
			break;
		case 21..30:
			FABRIC = "satin";
			obj->set_long("This fine satin shirt is "+LENGTH+". It is made of"+
			" high quality fabric and has been dyed a "+STYLE+" "+str+" shade."+
			" The neckline dips down into a V-cut, and is a bit revealing.");
			break;
		case 31..40:
			FABRIC = "silk";
			obj->set_long("This beautiful "+LENGTH+" silk shirt has been dyed"+
			" a "+STYLE+" "+str+" shade. It tends to cling to the wearer's"+
			" body, complementing a pretty figure. It is ever so soft to the"+
			" touch, but not very warm.");
			break;
	}
	obj->set_value(val+1);
	obj->set_weight(3);
	obj->set_name("shirt");
	obj->set_short("A "+str+" "+FABRIC+" shirt");
	obj->set_id(({"shirt","mina_clothing","r_top","clothing",""+str+" shirt",""+str+" "+FABRIC+" shirt",""+FABRIC+" shirt",""+LENGTH+" shirt"}));
	obj->set_limbs(({"torso"}));
	obj->set_type("clothing");
	obj->set_ac(0);
	obj->set_size(2);
}
