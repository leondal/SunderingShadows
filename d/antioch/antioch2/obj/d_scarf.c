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
string str, FABRIC, STYLE;

void create()
{
	::create();
}

void create_scarf(object obj)
{
   j = random(sizeof(COLORS));
	str = COLORS[j];
   i = random(sizeof(SHADES));
	STYLE = SHADES[i];
	if(str == "%^BOLD%^%^BLACK%^black%^RESET%^" || str == "%^BOLD%^%^WHITE%^white%^RESET%^") {
		STYLE = "lovely";
	}

	val = random(20);
	switch(val) {
		case 0..5:
			FABRIC = "cotton";
			obj->set_long("This is a cotton scarf that can be worn around"+
			" the neck for decoration. It has been dyed a "+STYLE+" "+str+""+
			" shade and is quite pretty.");
			break;
		case 6..10:
			FABRIC = "woolen";
			obj->set_long("This is a woolen scarf that is normally worn during"+
			" the winter months, it helps to keep you warm. It is hand made"+
			" and soft to the touch, it has been dyed a "+STYLE+" "+str+" shade.");
			break;
		case 11..15:
			FABRIC = "satin";
			obj->set_long("This satin scarf is fancier than what is normally"+
			" worn, typically only the nobles wear such finery. It has been"+
			" dyed a "+STYLE+" "+str+" shade and can be wrapped around the"+
			" neck.");
			break;
		case 16..20:
			FABRIC = "silk";
			obj->set_long("This silk scarf is beautiful as well as rather"+
			" extravagent. It is incredibly soft to the touch and feels"+
			" wonderful against your neck. It has been dyed a "+STYLE+" "+str+""+
			" shade.");
			break;
	}
	obj->set_value(val+1);
	obj->set_name("scarf");
	obj->set_id(({"scarf","clothing","r_scarf","mina_clothing",""+str+" scarf",""+FABRIC+" scarf",""+str+" "+FABRIC+" scarf"}));
	obj->set_short("A "+str+" "+FABRIC+" scarf");
	obj->set_type("ring");
	obj->set_limbs(({"neck"}));
	obj->set_ac(0);
	obj->set_size(2);
	obj->set_weight(1);
        obj->set_property("repairtype",({ "tailor" }));
}
