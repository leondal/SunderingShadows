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
string str, GEM, METAL, X, R;

void create()
{
	::create();
}

void create_necklace(object obj)
{
   i = random(sizeof(GEMS));
	GEM = GEMS[i];
   j = random(sizeof(METALS));
	METAL = METALS[j];
	if(GEM == "%^BOLD%^%^GREEN%^emerald%^RESET%^" || GEM == "%^RESET%^%^MAGENTA%^amethyst%^RESET%^" || GEM == "%^BOLD%^%^BLACK%^onyx%^RESET%^" || GEM == "%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^%^l%^RESET%^" || GEM == "%^RESET%^%^ORANGE%^amber%^RESET%^" || GEM == "%^BOLD%^%^CYAN%^aquamarine%^RESET%^" || GEM == "%^RESET%^%^GREEN%^agate%^RESET%^" || GEM == "%^BOLD%^%^CYAN%^azurite%^RESET%^") {
		X = "An";
	}
	else {
		X = "A";
	}
	if(METAL == "%^YELLOW%^e%^WHITE%^l%^YELLOW%^e%^WHITE%^c%^YELLOW%^t%^WHITE%^r%^YELLOW%^u%^WHITE%^m%^RESET%^") {
		R = "an";
	}
	else {
		R = "a";
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
			price2 = random(100)+600;
			break;
		case 1..2:
			price2 = random(150)+700;
			break;
		case 3..4:
			price2 = random(100)+1000;
			break;
		case 5:
			price2 = random(200)+1500;
			break;
	}
	obj->set_name(""+GEM+" necklace");
	obj->set_short(""+X+" "+GEM+" necklace");
	obj->set_id(({"antioch_jewelry","necklace",""+GEM+" necklace",""+METAL+" necklace",""+METAL+" "+GEM+" necklace",""+GEM+" "+METAL+" necklace","r_necklace"}));
	obj->set_long("This is a beautiful necklace with "+R+" "+METAL+" chain."+
	" "+X+" "+GEM+" pendant is set in the center of the necklace."); 
	obj->set_weight(2);
	obj->set_value(price1+price2);
	obj->set_type("ring");
	obj->set_limbs(({"neck"}));
	obj->set_ac(0);
}
