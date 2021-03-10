#include <std.h>
#include "../antioch.h"

#define GEMS ({"%^BOLD%^%^WHITE%^diamond%^RESET%^",\
"%^BOLD%^%^GREEN%^emerald%^RESET%^",\
"%^BOLD%^%^RED%^ruby%^RESET%^",\
"%^BOLD%^%^BLUE%^sapphire%^RESET%^",\
"%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l%^RESET%^",\
"%^RESET%^%^MAGENTA%^amethyst%^RESET%^",\
"%^RESET%^%^ORANGE%^topaz%^RESET%^",\
"%^RESET%^%^RED%^garnet%^RESET%^",\
"%^RESET%^%^ORANGE%^amber%^RESET%^",\
"%^RESET%^%^GREEN%^agate%^RESET%^",\
"%^BOLD%^%^BLACK%^ma%^GREEN%^l%^BLACK%^ach%^GREEN%^i%^BLACK%^te%^RESET%^",\
"%^BOLD%^%^WHITE%^moonstone%^RESET%^",\
"%^RESET%^%^GREEN%^beryl%^RESET%^",\
"%^BOLD%^%^WHITE%^pearl%^RESET%^",\
"%^BOLD%^%^BLACK%^hematite%^RESET%^",\
"%^BOLD%^%^WHITE%^quartz crystal%^RESET%^",\
"%^YELLOW%^citrine%^RESET%^",\
"%^BOLD%^%^RED%^carnelian%^RESET%^",\
"%^BOLD%^%^GREEN%^blo%^RED%^o%^GREEN%^dst%^RED%^o%^GREEN%^ne%^RESET%^",\
"%^BOLD%^%^CYAN%^azurite%^RESET%^",\
"%^BOLD%^%^GREEN%^peridot%^RESET%^",\
"%^BOLD%^%^BLACK%^bl%^GREEN%^a%^BLACK%^ck op%^GREEN%^a%^BLACK%^l%^RESET%^",\
"%^BOLD%^%^RED%^flamedance%^RESET%^",\
"%^CYAN%^tur%^BOLD%^q%^RESET%^%^CYAN%^uoise%^RESET%^",\
"%^BOLD%^%^MAGENTA%^rose quartz%^RESET%^",\
"%^BOLD%^%^BLACK%^smokey quartz%^RESET%^",\
"%^RESET%^%^ORANGE%^tiger's eye%^RESET%^",\
"%^BOLD%^%^CYAN%^aquamarine%^RESET%^",\
"%^BOLD%^%^BLACK%^onyx%^RESET%^"})
#define METALS ({"%^RESET%^%^ORANGE%^brass%^RESET%^",\
"%^YELLOW%^bronze%^RESET%^",\
"%^RESET%^%^ORANGE%^copper%^RESET%^",\
"%^BOLD%^%^WHITE%^silver%^RESET%^",\
"%^YELLOW%^e%^WHITE%^l%^YELLOW%^e%^WHITE%^c%^YELLOW%^t%^WHITE%^r%^YELLOW%^u%^WHITE%^m%^RESET%^",\
"%^BOLD%^%^WHITE%^mi%^CYAN%^t%^WHITE%^hril%^RESET%^",\
"%^YELLOW%^gold%^RESET%^",\
"%^BOLD%^%^CYAN%^adamantite%^RESET%^",\
"%^BOLD%^%^WHITE%^titanium%^RESET%^",\
"%^BOLD%^%^WHITE%^platinum%^RESET%^",\
"%^BOLD%^%^MAGENTA%^rose gold%^RESET%^",\
"%^BOLD%^%^WHITE%^white gold%^RESET%^",\
"%^RESET%^%^MAGENTA%^darksteel%^RESET%^"})
inherit DAEMON;

int i, j, price1, price2;
string str, GEM, METAL,X;

void create()
{
	::create();
}

void create_circlet(object obj)
{
   j = random(sizeof(GEMS));
	GEM = GEMS[j];
   i = random(sizeof(METALS));
	METAL = METALS[i];
	if(METAL == "%^YELLOW%^e%^WHITE%^l%^YELLOW%^e%^WHITE%^c%^YELLOW%^t%^WHITE%^r%^YELLOW%^u%^WHITE%^m%^RESET%^" || METAL == "%^BOLD%^%^CYAN%^adamantite%^RESET%^") {
		X = "An";
	}
	else {
		X = "A";
	}
	switch(j) {
		case 0:
			price1 = random(100)+1000;
			break;
		case 1..3:
			price1 = random(200)+800;
			break;
		case 4..20:
			price1 = random(350)+400;
			break;
	}
	switch(i) {
		case 0..1:
			price2 = random(50)+200;
			break;
		case 2:
			price2 = random(100)+400;
			break;
		case 3..4:
			price2 = random(150)+500;
			break;
		case 5:
			price2 = random(200)+800;
			break;
		case 6..8:
			price2 = random(500)+1300;
			break;
	}
	obj->set_value(price1+price2);
	obj->set_name(""+METAL+" circlet");
	obj->set_short(""+X+" "+METAL+" circlet");
	obj->set_id(({"circlet",""+METAL+" circlet","antioch_jewelry",""+GEM+" circlet",""+GEM+" "+METAL+" circlet","r_circlet"}));
	obj->set_long("This is a lovely "+METAL+" circlet. It has been carefully"+
	" crafted to fit around the top of your head. The front part of the"+
	" circlet is studded with "+GEM+".");
	obj->set_type("ring");
	obj->set_limbs(({"head"}));
	obj->set_weight(2);
	obj->set_ac(0);
}
