#include <std.h>

#define GEMS ({"%^BOLD%^%^BLACK%^on%^WHITE%^y%^BLACK%^x","%^YELLOW%^top%^RESET%^%^ORANGE%^a%^YELLOW%^z","%^BOLD%^%^MAGENTA%^ame%^RESET%^%^MAGENTA%^t%^BOLD%^hyst","%^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y","%^BOLD%^%^GREEN%^em%^WHITE%^e%^GREEN%^ra%^RESET%^%^GREEN%^l%^BOLD%^d","%^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^hi%^WHITE%^r%^BLUE%^e","%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l","%^BOLD%^%^WHITE%^dia%^CYAN%^m%^WHITE%^ond"})
#define METALS ({"%^GREEN%^cop%^YELLOW%^p%^RESET%^%^GREEN%^er","sil%^BOLD%^v%^RESET%^er","%^YELLOW%^gold","%^BOLD%^white gold","%^BOLD%^elec%^CYAN%^t%^WHITE%^rum","%^BOLD%^plat%^YELLOW%^i%^WHITE%^num"})

inherit DAEMON;

int i, j, price1, price2;
string str, GEM, METAL, X;

void create()
{
	::create();
}

void create_clasp(object obj)
{
   j = random(sizeof(GEMS));
	GEM = GEMS[j];
   i = random(sizeof(METALS));
   METAL = METALS[i];
	if(GEM == "%^BOLD%^%^GREEN%^em%^WHITE%^e%^GREEN%^ra%^RESET%^%^GREEN%^l%^BOLD%^d" || GEM == "%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l" || GEM == "%^BOLD%^%^BLACK%^on%^WHITE%^y%^BLACK%^x" || GEM == "%^BOLD%^%^MAGENTA%^ame%^RESET%^%^MAGENTA%^t%^BOLD%^hyst") {
		X = "An";
	}
	else {
		X = "A";
	}
	switch(j) {
		case 0:
			price1 = random(150)+300;
			break;
		case 1..3:
			price1 = random(200)+400;
			break;
		case 4..7:
			price1 = random(300)+500;
			break;
	}
	switch(i) {
		case 0:
			price2 = random(50)+50;
			break;
		case 1:
			price2 = random(75)+100;
			break;
		case 2..4:
			price2 = random(200)+300;
			break;
		case 5:
			price2 = random(200)+500;
			break;
	}
	obj->set_name(""+GEM+" clasp");
	obj->set_short(""+X+" "+GEM+" clasp%^RESET%^");
	obj->set_id(({"clasp",""+GEM+" clasp",""+METAL+" clasp","r_clasp","cloak clasp"}));
	obj->set_long("This is a "+METAL+" %^RESET%^clasp designed to fasten a cloak.  It is diamond-"+
         "shaped and has been set with a round, highly polished "+GEM+" %^RESET%^that "+
         "sparkles when light touches it.  The "+METAL+" %^RESET%^has been formed into delicate "+
         "scrollwork and provides a handsome base for the "+GEM+"%^RESET%^.");
	obj->set_weight(6);
	obj->set_value(price1+price2);
	obj->set_type("ring");
	obj->set_limbs(({"neck"}));
	obj->set_ac(0);
}
