//Cleaned up the code a bit, gave a new desc and random colors - Cythera 4/05
//removed "cloak" from id 6/3/01 - Styx

inherit "/std/armour";
#define COLORS ({"%^BOLD%^%^WHITE%^snow white","%^BOLD%^%^RED%^crimson red","%^RED%^scarlet red","%^BOLD%^%^GREEN%^emerald green","%^GREEN%^forest green","%^BOLD%^%^BLACK%^jet black","%^BOLD%^%^BLUE%^royal blue", "%^BLUE%^midnight blue", "%^YELLOW%^sunshine yellow","%^ORANGE%^tan","%^ORANGE%^dark orange","%^BOLD%^%^CYAN%^sky blue","%^BOLD%^%^CYAN%^teal green","%^MAGENTA%^dark violet","%^BOLD%^%^MAGENTA%^bright pink","%^BOLD%^%^BLACK%^charcoal gray","%^BOLD%^%^BLACK%^raven black","%^BOLD%^%^CYAN%^sea-green","%^BOLD%^%^WHITE%^pale cream","%^RESET%^smokey gray"})


void create(){
     	int j;
	string str, COLOR;
	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
    	set_name("robe");
    	set_id(({ "robe", "armor" }) );
    	set_short("%^RESET%^%^CYAN%^A "+COLOR+" %^RESET%^%^CYAN%^quilted cotton robe%^RESET%^");
    	set_long("%^CYAN%^Layers of "+COLOR+"%^RESET%^%^CYAN%^ cotton have"+
		" been quilted together to create this robe.  The thick robe"+
		" seems a little on the bulky side, which would help cut the"+
		" chill of even the coldest wind.  Despite its bulk the "+
		"cotton robe seems as if it would be somewhat comfortable"+
		" to wear in the warmer months.  The simple robe crosses in"+
		" the front, where it is tied closed with a "+COLOR+"%^RESET%^"+
		"%^CYAN%^ sash.  The long sleeves of the robe flare out to a"+
		" bell like shape.  The edges of the robe has been bound "+
		"with bias cut strips of linen "+
		"in "+COLOR+"%^RESET%^%^CYAN%^.%^RESET%^\n");
    set_weight(10);
    set_value(4);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
    set_ac(1);
}

int is_metal() { return 0; }