#include <std.h>
#include "../valley.h"

#define GEMS ({"%^BOLD%^%^WHITE%^diamond%^RESET%^",\
"%^BOLD%^%^GREEN%^emerald%^RESET%^",\
"%^BOLD%^%^RED%^ruby%^RESET%^",\
"%^BOLD%^%^BLUE%^sapphire%^RESET%^",\
"%^RED%^garnet%^RESET%^",\
"%^MAGENTA%^amethyst%^RESET%^",\
"%^ORANGE%^topaz%^RESET%^",\
"%^BOLD%^%^RED%^fire opal%^RESET%^",\
"%^BOLD%^%^WHITE%^moonstone%^RESET%^",\
"%^BOLD%^%^BLACK%^black opal%^RESET%^",\
"%^BOLD%^%^WHITE%^o%^CYAN%^p%^WHITE%^a%^MAGENTA%^l%^RESET%^",\
"%^ORANGE%^piece of amber%^RESET%^",\
"%^BOLD%^%^GREEN%^piece of jade%^RESET%^",\
"%^BOLD%^%^CYAN%^water opal%^RESET%^"})

#define GEMNAMES ({"diamond","emerald","ruby","sapphire","garnet","amethyst","topaz","fire opal","moonstone","black opal","opal","amber","jade","water opal"})

inherit OBJECT;

void create()
{
	int i,j, val;
	string str,mygem;

	::create();
	j=random(14); //was 9, for some reason - adjusted by ~Circe~ 3/22/16; also added ids for each gem type
	str= GEMS[j];
      mygem = GEMNAMES[j];
	val = random(600);
	switch(val) {
		case 0..200:
			set_long("This is a small "+str+". The light catches"+
			" in the gem and it looks like it would sell for a"+
			" nice price.");
			set_short("Small "+str+"");
			break;
		case 201..400:
			set_long("This is a "+str+" of a nice size. From the"+
			" way the light catches within the gem, it could"+
			" probably be sold for a fair sum.");
			set_short("Medium "+str+"");
			break;
		case 401..600:
			set_long("This is a fairly nice sized "+str+". The"+
			" light twinkles within the gem very prettily and"+
			" it is obviously worth a fair bit of gold.");
			set_short("Large "+str+"");
			break;
		}
	if(val < 50) {
		set_value(50);
	}
	else {
		set_value(val);
	}
	set_id(({"gem",str,mygem}));
	set_name("gem");
	set_weight(5);
}

int is_gem(){return 1;}