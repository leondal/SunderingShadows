#include <std.h>
inherit PARMOUR;

int newpack;
string owner;

void create() {
    ::create();
    set_id( ({"pack", "backpack", "tsarvani pack", "tsarvani army backpack" }) );
    set_name("backpack");
    set("short", "A frame backpack");
    set_weight(55);
    set_long(
@TSARVEN
This is a frame backpack that carries the obvious signs of the Imperial 
Army of Tsarven on it.  There is a crude frame and straps so that the 
pack may be worn comfortably on the back.  The adjustments for the pack 
appear to be custom adjusted for the size of the person who bought it.  This 
adds strength to the pack, allowing the frame to be all of one piece, 
without seams.  The problem is that you can't adjust it and its resale 
value is likely very low.
TSARVEN
	);
	set_value(1500);
	set_max_internal_encumbrance(55);
	set_limbs(({"waist"}));
	set_type("clothing");
	set_wear((:TO,"check_wear":));
	newpack = 1;
}

int query_size(){
    if(!objectp(ETO)) return 2;
    return 2;
}

int check_wear() {
	string classes;
	string race;
	if(newpack) {
		TO->set_value(15);
		newpack = 0;
		owner = TPQN;
	}
	race = TP->query_race();
	classes = TP->query_classes();
	if(member_array("fighter", classes) == -1) {
		write("You have no idea how to use this military equipment.");
		return 0;
	}
	if(owner && (string)TPQN != owner) {
		write("The frame on this pack was constructed for someone else, the weight distribution is terrible.");
		set_weight(45);
		return 1;
	}
	if(race == "half-elf" || race == "half-drow") {
		write("You can get the pack on, but the weight isn't perfectly balanced.");
		set_weight(25);
		return 1;
	}
	if(race == "elf" || race == "drow") {
		write("The pack fits for the most part, but the weight is very poorly distributed for your build.");
		set_weight(35);
		return 1;
	}
	if(race == "human") {
		write("With a tug at the straps, you're pack is well positioned on your back.");
		set_weight(15);
		return 1;
	}	
	write("You couldn't get this on to save your life.");
	return 0;
}

	