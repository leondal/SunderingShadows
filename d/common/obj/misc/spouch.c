//Giving variety to pouches - Cythera 4/05
#include <std.h>
inherit "/d/common/obj/misc/pouch.c";
#define COLORS ({"%^BOLD%^%^WHITE%^snow white",\
"%^BOLD%^%^RED%^crimson red",\
"%^RED%^scarlet red",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^GREEN%^forest green",\
"%^BOLD%^%^BLACK%^jet black",\
"%^BOLD%^%^BLUE%^royal blue",\
 "%^BLUE%^midnight blue",\
 "%^YELLOW%^sunshine yellow",\
"%^ORANGE%^tan",\
"%^ORANGE%^dark orange",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^BOLD%^%^CYAN%^teal green",\
"%^MAGENTA%^dark violet",\
"%^BOLD%^%^MAGENTA%^bright pink",\
"%^BOLD%^%^BLACK%^charcoal gray",\
"%^BOLD%^%^BLACK%^raven black",\
"%^BOLD%^%^CYAN%^sea-green",\
"%^BOLD%^%^WHITE%^pale cream",\
"%^RESET%^smokey gray"})


void create(){
     	int j;
	string str, COLOR;
	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
	set_id( ({"pouch","leather pouch"}) );
    	set_name("small pouch");
    	set_short("%^RESET%^A "+COLOR+"%^RESET%^ small leather belt pouch");
	set_long("Fashioned from thin pieces of "+COLOR+"%^RESET%^"+
		" leather, this pouch looks ready to hold some treasured"+
		" items safe.  The pouch features a drawstring cord sewn"+
		" into a casing around the top part of the pouch, allowing"+
		" it to be pulled closed.  There is enough excess in the "+
		"cords to allow them to tie onto a belt, keeping the pouch"+
		" safe.  The inside of the pouch is lined in complementary"+
		" cotton dyed "+COLOR+"%^RESET%^.\n");
    	set_value(7);
    	set_cointype("silver");
    	set_max_internal_encumbrance(5);
      set_property("repairtype",({ "leatherwork","tailor" }));
}
