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
"%^BOLD%^%^WHITE%^platinum%^RESET%^"})

inherit DAEMON;

int i, j, price1, price2;
string str, GEM, METAL;

void create()
{
	::create();
}

void create_armband(object obj)
{
	j = random(sizeof(GEMS));
	GEM = GEMS[j];
	i = random(sizeof(METALS));
	METAL = METALS[i];
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
		case 0..2:
			price2 = random(50)+200;
			break;
		case 3..5:
			price2 = random(100)+400;
			break;
		case 6:
			price2 = random(125)+800;
			break;
		case 7..9:
			price2 = random(200)+1500;
			break;
	}

	obj->set_value(price1+price2);
	obj->set_name(""+METAL+" armbands");
	obj->set_short("A pair of "+METAL+" armbands");
	obj->set_id(({"armbands","antioch_jewelry",""+METAL+" armbands","pair of "+METAL+" armbands","pair of armbands","r_armband"}));
	obj->set_long("This is a beautiful pair of "+METAL+" armbands."+
	" They have been carefully crafted into an intricate set of circles"+
	" that loop around your arms. They are encrusted with "+GEM+" and"+
	" are very lovely.");
	obj->set_weight(5);
	obj->set_type("ring");
	obj->set_limbs(({"right arm","left arm"}));
	obj->set_ac(0);
}
