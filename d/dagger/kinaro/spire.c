#include <std.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light", 3);
    set_property("indoors", 1);
    set_property("no attack", 1);
    set_short("%^YELLOW%^The %^CYAN%^Tr%^RESET%^%^CYAN%^a%^BOLD%^d%^RESET%^%^CYAN%^e"
			 "%^YELLOW%^Sp%^RESET%^%^ORANGE%^i%^BOLD%^r%^RESET%^%^ORANGE%^e%^WHITE%^");
    set_long("This %^BOLD%^%^CYAN%^majestically %^RESET%^crafted %^BOLD%^%^BLACK%^stone"
			 " structure %^RESET%^is the %^YELLOW%^financial%^RESET%^, %^BOLD%^%^MAGENTA"
			 "%^social %^RESET%^and %^BOLD%^political %^RED%^heart %^RESET%^of %^ORANGE"
			 "%^Kinaro%^WHITE%^. The first floor of %^YELLOW%^The Trade Spire %^RESET%^"
			 "features a large, %^BOLD%^open %^RESET%^trade %^MAGENTA%^market%^WHITE%^."
			 " %^ORANGE%^Kinaro's %^BOLD%^trade guild %^RESET%^conduct business here wi"
			 "th representatives of every other %^ORANGE%^settlement%^WHITE%^, %^BOLD%^"
			 "%^CYAN%^mercantile organization %^RESET%^and %^BOLD%^noble familiy %^RESET"
			 "%^on the %^BOLD%^%^BLACK%^Shadow %^RESET%^continent. Entire %^YELLOW%^fort"
			 "unes %^RESET%^have been made and %^BOLD%^los%^RESET%^t on its floor in the"
			 " space of hours, as one %^BOLD%^%^CYAN%^trader %^RESET%^finds a market %^B"
			 "OLD%^hungry %^RESET%^for goods and another finds one that wouldn't take his"
			 " %^CYAN%^offerings %^WHITE%^for free. %^BOLD%^%^CYAN%^Traders %^WHITE%^nego"
			 "tiate %^RESET%^prices for the %^ORANGE%^town's goods, %^WHITE%^meet with %^"
			 "ORANGE%^crafters %^WHITE%^to discuss terms of pending sales or to plan %^CY"
			 "AN%^production %^WHITE%^for the coming %^YELLOW%^year %^RESET%^and %^YELLO"
			 "W%^broker %^RESET%^meetings between %^ORANGE%^Kinaro's %^BOLD%^%^CYAN%^arti"
			 "sans %^RESET%^and buyers from outside town. The second and third floors hol"
			 "d %^BOLD%^offices %^RESET%^for the %^ORANGE%^mining %^WHITE%^and %^BOLD%^%^"
			 "CYAN%^crafting guilds %^RESET%^that operate under the %^BOLD%^%^CYAN%^trades"
			 "guild. %^RESET%^A squad of four %^BOLD%^%^RED%^guards %^RESET%^keep an eye on"
			 " %^YELLOW%^The Trade Spire's %^RESET%^entrance and visitors at all times.");
    set_smell("default","%^RESET%^%^ORANGE%^The different smells of a crowd of people from many far"
						" away places fills your nostrils.");
    set_listen("default","%^RESET%^%^GREEN%^You hear the s"
	                     "ound of arguments, deals and agr"
						 "eements being discussed. .");
	set_exits((["northwest" : "/d/dagger/kinaro/street5"]));
}
void reset(){
    ::reset();
    if(!present("dulag")) {
	new("/d/dagger/kinaro/mon/dulag")->move(TO);
    }
}



