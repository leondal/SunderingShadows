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

void create_shorts(object obj)
{
   j = random(sizeof(COLORS));
	str = COLORS[j];
   i = random(sizeof(SHADES));
	STYLE = SHADES[i];
	if(str == "%^BOLD%^%^BLACK%^black%^RESET%^" || str == "%^BOLD%^%^WHITE%^white%^RESET%^") {
		STYLE = "lovely";
	}
	obj->set_long("This is a pair of plain cotton shorts. They are great"+
	" for wearing during the summer months when it gets very hot. They"+
	" have been dyed a "+STYLE+" "+str+" shade and look quite comfortable.");
	obj->set_value(15+random(3));
	obj->set_weight(5);
	obj->set_name("shorts");
	obj->set_short("A pair of "+str+" shorts");
	obj->set_id(({"shorts","mina_clothing","r_shorts","clothing",""+str+" shorts","cotton shorts",""+str+" cotton shorts","pair of shorts","pair of "+str+" shorts"}));
	obj->set_limbs(({"left leg","right leg"}));
	obj->set_type("clothing");
	obj->set_ac(0);
	obj->set_size(2);
}
