#include <std.h>
#include "../antioch.h"

#define SHADES ({"%^BOLD%^%^WHITE%^light%^RESET%^",\
"%^BOLD%^%^BLACK%^dark%^RESET%^",\
"%^BOLD%^%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^e%^RESET%^p",\
"%^BOLD%^%^WHITE%^p%^RESET%^a%^BOLD%^l%^RESET%^e",\
"%^BOLD%^%^WHITE%^bright%^RESET%^"})

#define PATTERNS ({"striped","checkered","solid"})

#define COLORS ({"%^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^RESET%^",\
"%^RESET%^%^ORANGE%^brown%^RESET%^",\
"%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^",\
"%^BOLD%^%^BLACK%^black%^RESET%^",\
"%^BOLD%^%^WHITE%^white%^RESET%^",\
"%^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^lu%^BOLD%^e%^RESET%^",\
"%^YELLOW%^yellow%^RESET%^",\
"%^RESET%^%^MAGENTA%^purple%^RESET%^"})

inherit DAEMON;

int i, j, m;
string str, STYLE, LENGTH, DESIGN;

void create()
{
	::create();
}

void create_shirt(object obj)
{
   j = random(sizeof(COLORS));
	str = COLORS[j];
   i = random(sizeof(SHADES));
	STYLE = SHADES[i];
	if(str == "%^BOLD%^%^BLACK%^black%^RESET%^" || str == "%^BOLD%^%^WHITE%^white%^RESET%^") {
		STYLE = "lovely";
	}
	m = random(3);
	DESIGN = PATTERNS[m];
	switch(random(2)) {
		case 0:
			LENGTH = "short sleeved";
			break;
		case 1:
			LENGTH = "long sleeved";
			break;
	}
   if(DESIGN == "solid") {
      obj->set_long("This is a fine "+LENGTH+" cotton shirt. It is of good"+
      " quality, but nothing fancy, suitable for wearing everyday. It is a"+
      " solid color and has been dyed a "+STYLE+" "+str+" shade. It buttons up"+
      " in the front and has a collar around the neck.");
   }
   else {
	obj->set_long("This is a fine "+LENGTH+" cotton shirt. It is of good"+
	" quality, but nothing fancy, suitable for wearing everyday. It has a"+
	" "+DESIGN+" and has been a dyed "+STYLE+" "+str+" shade. It buttons up"+
   " in the front and has a collar around the neck.");
   }
	obj->set_value(12+random(4));
	obj->set_weight(3);
	obj->set_name("shirt");
	obj->set_short("A "+DESIGN+" "+str+" shirt");
	obj->set_id(({"shirt","mina_clothing","r_shirt","clothing",""+str+" shirt",""+str+" "+DESIGN+" shirt",""+DESIGN+" shirt",""+LENGTH+" shirt","cotton shirt"}));
	obj->set_limbs(({"torso"}));
	obj->set_type("clothing");
	obj->set_ac(0);
	obj->set_size(2);
}
