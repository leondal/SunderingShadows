#include <std.h>
#include <objects.h>
inherit ROOM;
void create() {
   ::create();
    set_property("smithy",1); 
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(1);
    set_short("%^BOLD%^%^CYAN%^G%^RESET%^%^CYAN%^e%^BOLD%^%^MAGENTA%^ms%^WHITE%^t%^BLUE%^o%^RESET%^%^MAGENTA%^ne %^BOLD%^%^WHITE%^Smithy%^RESET%^");
    set_long("You find yourself in the %^BOLD%^%^BLACK%^smithy %^RESET%^of %^ORANGE%^Kinaro%^WHITE%^. This is one of the %^BOLD%^%^BLACK%^great %^"
	     	 "RED%^f%^RESET%^%^RED%^o%^BOLD%^r%^RESET%^%^RED%^g%^BOLD%^e%^RESET%^%^RED%^s %^WHITE%^of the %^BOLD%^%^CYAN%^realm %^RESET%^and it is"
			 " clear that the %^BOLD%^%^BLACK%^master smith %^RESET%^here runs his shop with both %^BOLD%^%^RED%^passion %^RESET%^and d%^BOLD%^%^CY"
			 "AN%^iscipline%^RESET%^. You see several young %^ORANGE%^dwarf %^CYAN%^apprentices %^WHITE%^running around, hauling %^BOLD%^%^BLUE%^wa"
			 "ter %^RESET%^in barrels, and manning the two huge %^BOLD%^%^BLACK%^bellows%^RESET%^. At the center of the room you can see the big %^"
			 "BOLD%^%^RED%^f%^RESET%^%^RED%^o%^BOLD%^rg%^RESET%^%^RED%^e%^WHITE%^, with a %^BOLD%^%^RED%^fire %^RESET%^that seems as hot as the %^B"
			 "OLD%^%^RED%^flames %^RESET%^of %^BOLD%^%^RED%^h%^RESET%^%^RED%^e%^BOLD%^ll %^RESET%^itself. The forge has been built from massive blo"
			 "cks of %^BOLD%^%^BLACK%^stone%^RESET%^. It has an open front with a large round %^ORANGE%^chimney %^WHITE%^at the top to let out %^BO"
			 "LD%^smoke%^RESET%^. %^BOLD%^%^CYAN%^Anvils %^RESET%^of all sizes are placed near the forge, each with its own assortion of smithing t"
			 "ools; suchs as %^BOLD%^tongs%^RESET%^, %^BOLD%^hammers%^RESET%^, %^BOLD%^chisels %^RESET%^and various specialized equipment that is n"
			 "ever far from a %^BOLD%^%^BLACK%^master smith %^RESET%^when he is working with %^BOLD%^%^RED%^hot %^BLACK%^metal%^RESET%^.");
    set_smell("default","The smell of oil and iron pervades in this area.");
	set_listen("default","You hear the anvil clanging against metal");
    set_exits((["east" : "/d/dagger/kinaro/street3"]));

}

void reset(){
    ::reset();
    if(!present("gake"))
	new("/d/dagger/kinaro/mon/gake")->move(TO);
}