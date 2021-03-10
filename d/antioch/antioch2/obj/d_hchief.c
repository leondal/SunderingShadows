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
string str, STYLE, DESIGN;

void create()
{
	::create();
}

void create_handkerchief(object obj)
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

	obj->set_long("This is a cotton handkerchief with a "+DESIGN+""+
	" pattern. It has been dyed a "+STYLE+" "+str+" shade and can"+
	" be worn on your head.");
	obj->set_value(5+random(3));
	obj->set_name("handkerchief");
	obj->set_id(({"handkerchief","clothing","r_hchief","mina_clothing",""+str+" handkerchief",""+DESIGN+" handkerchief",""+DESIGN+" "+str+" handkerchief","cotton handkerchief",""+str+" handkerchief",""+DESIGN+" "+str+" cotton handkerchief"}));
	obj->set_short("A "+DESIGN+" "+str+" handkerchief");
	obj->set_type("ring");
	obj->set_limbs(({"head"}));
	obj->set_ac(0);
	obj->set_size(2);
	obj->set_weight(1);
        obj->set_property("repairtype",({ "tailor" }));
}
