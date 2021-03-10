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

int i, j;
string str, STYLE;

void create()
{
	::create();
}

void create_tunic(object obj)
{
   j = random(sizeof(COLORS));
	str = COLORS[j];
   i = random(sizeof(SHADES));
	STYLE = SHADES[i];
	if(str == "%^BOLD%^%^BLACK%^black%^RESET%^" || str == "%^BOLD%^%^WHITE%^white%^RESET%^") {
		STYLE = "lovely";
	}
	obj->set_long("This is a plain cotton tunic. It is rather thick and"+
	" heavy, but looks quite durable. It has been dyed a "+STYLE+" "+str+""+
	" shade and is good for daily activities and work.");
	obj->set_value(8+random(3));
	obj->set_weight(5);
	obj->set_name("tunic");
	obj->set_short("A "+str+" cotton tunic");
	obj->set_id(({"tunic","mina_clothing","r_tunic","clothing",""+str+" tunic","cotton shirt",""+str+" cotton tunic"}));
	obj->set_limbs(({"torso"}));
	obj->set_type("clothing");
	obj->set_ac(0);
	obj->set_size(2);
}
