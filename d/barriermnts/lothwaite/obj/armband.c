#include <std.h>

#define GEMS ({"%^BOLD%^diamonds","%^BOLD%^%^GREEN%^emeralds","%^BOLD%^%^RED%^rubies","%^BOLD%^%^BLUE%^sapphires","%^BOLD%^o%^CYAN%^p%^WHITE%^a%^RED%^l%^WHITE%^s","%^MAGENTA%^amethysts","%^YELLOW%^topaz","%^RED%^garnets","%^YELLOW%^pieces of amber","%^GREEN%^agates","%^BOLD%^malachite","%^BOLD%^moonstones","%^GREEN%^be%^BOLD%^r%^RESET%^%^GREEN%^yls","%^BOLD%^pearls","%^RED%^hema%^GREEN%^t%^RED%^ite","%^BOLD%^quartz crystals","%^YELLOW%^citrine","%^RED%^carnelian","%^RED%^bloo%^GREEN%^ds%^RED%^tone","%^CYAN%^azurite","%^YELLOW%^per%^GREEN%^id%^YELLOW%^ot"})
#define METALS ({"%^ORANGE%^brass","%^ORANGE%^bronze","%^ORANGE%^co%^GREEN%^pp%^ORANGE%^er","silver","%^BOLD%^electrum","%^BOLD%^mithril","%^YELLOW%^gold","%^BOLD%^adamantite","%^BOLD%^%^BLACK%^titanium","%^BOLD%^platinum"})

inherit ARMOUR;

int i, j, price1, price2;
string str, GEM, METAL;

void create()
{
   ::create();
	j = random(sizeof(GEMS));
	GEM = GEMS[j];
	i = random(sizeof(METALS));
	METAL = METALS[i];
	switch(j) {
		case 0:
			price1 = random(50)+500;
			break;
		case 1..3:
			price1 = random(100)+400;
			break;
		case 4..20:
			price1 = random(175)+200;
			break;
	}
	switch(i) {
		case 0..2:
			price2 = random(25)+100;
			break;
		case 3..5:
			price2 = random(50)+200;
			break;
		case 6:
			price2 = random(75)+400;
			break;
		case 7..9:
			price2 = random(100)+700;
			break;
	}

	set_value(price1+price2);
	set_name(""+METAL+" armband%^RESET%^");
	set_short(""+METAL+" armband%^RESET%^");
	set_id(({"armband",""+METAL+" armband","leather armband"}));
	set_long("This armband is several inches wide "+
         "and made to be worn over the bicep.  It is made of "+
         "%^ORANGE%^supple leather %^RESET%^edged with "+METAL+" "+
         "%^RESET%^and set with "+GEM+"%^RESET%^.  While it would "+
         "not offer any protection, it makes a beautiful ornament.");
	set_weight(6);
	set_type("ring");
	set_limbs(({"left arm"}));
	set_ac(0);
}
