#include <std.h>
#include "../antioch.h"

#define STONES ({"%^BOLD%^%^WHITE%^diamond%^RESET%^",\
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
string str, STONE, METAL, X;

void create()
{
	::create();
}

void create_broach(object obj)
{
   i = random(sizeof(STONES));
	STONE = STONES[i];
   j = random(sizeof(METALS));
	METAL = METALS[j];
	if(STONE == "%^BOLD%^%^GREEN%^emerald%^RESET%^" || STONE == "%^RESET%^%^MAGENTA%^amethyst%^RESET%^" || STONE == "%^BOLD%^%^BLACK%^onyx%^RESET%^" || STONE == "%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^%^l%^RESET%^" || STONE == "%^RESET%^%^ORANGE%^amber%^RESET%^" || STONE == "%^BOLD%^%^CYAN%^aquamarine%^RESET%^" || STONE == "%^RESET%^%^GREEN%^agate%^RESET%^" || STONE == "%^BOLD%^%^CYAN%^azurite%^RESET%^") {
		X = "An";
	}
	else {
		X = "A";
	}
	switch(i) {
		case 0:
			price1 = random(200)+1000;
			break;
		case 1..3:
			price1 = random(200)+800;
			break;
		case 4..24:
			price1 = random(300)+400;
			break;
	}
	switch(j) {
		case 0:
			price2 = random(100)+400;
			break;
		case 1..2:
			price2 = random(150)+500;
			break;
		case 3..4:
			price2 = random(100)+800;
			break;
		case 5:
			price2 = random(200)+1300;
			break;
	}
   obj->set_name(""+STONE+" brooch");
   obj->set_short(""+X+" "+STONE+" brooch");
   obj->set_id(({"brooch",""+STONE+" brooch",""+METAL+" brooch",""+STONE+" "+METAL+" brooch","antioch_jewelry","r_broach","broach"}));
   obj->set_long("This is lovely "+METAL+" brooch with a large "+STONE+""+
   " set in the center of it. There is a pin on the back of the brooch that"+
	" can easily be attached to a shirt or cloak.");
	obj->set_weight(2);
	obj->set_value(price1+price2);
	obj->set_type("ring");
	obj->set_limbs(({"torso"}));
	obj->set_ac(0);
}
