#include <std.h>

#define GEMS ({"%^BOLD%^%^WHITE%^sno%^BLACK%^w%^WHITE%^flake %^BLACK%^obs%^WHITE%^i%^BLACK%^dian","%^RESET%^%^ORANGE%^tig%^YELLOW%^e%^RESET%^%^ORANGE%^r's eye","%^RESET%^%^RED%^carn%^BOLD%^e%^RESET%^%^RED%^lian","%^BOLD%^%^RED%^red jasper","%^YELLOW%^citrine","%^RESET%^%^ORANGE%^py%^YELLOW%^ri%^RESET%^%^ORANGE%^te","%^GREEN%^aventurine","%^BOLD%^%^MAGENTA%^rose quartz","%^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^thy%^BOLD%^s%^RESET%^%^MAGENTA%^t","%^CYAN%^aquamarine","%^CYAN%^turq%^BOLD%^uo%^RESET%^%^CYAN%^ise","%^BOLD%^%^WHITE%^clear calcite"})

inherit DAEMON;

int j;
string str, GEM;

void create_crystal(object obj)
{
	j = random(sizeof(GEMS));
	GEM = GEMS[j];
	obj->set_value(random(20)+20);
	obj->set_name(""+GEM+" necklace");
	obj->set_short(""+GEM+" necklace");
	obj->set_id(({"necklace",""+GEM+" necklace","crystal","crystal necklace"}));
	obj->set_long("%^ORANGE%^This is a rather simple necklace.  It "+
         "is made of a tanned leather strip supporting an unpolished "+
         ""+GEM+" %^RESET%^%^ORANGE%^left in "+
         "the rough.  Crystals are said to affect one's life in many "+
         "ways.  This is a simple, yet beautiful, trinket.%^RESET%^");
	obj->set_weight(1);
	obj->set_type("ring");
	obj->set_limbs(({"neck"}));
	obj->set_ac(0);
}
