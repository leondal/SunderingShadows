//scroll_chest2.c

#include <std.h>

inherit BAG;

void create(){
	set_possible_to_close(1);
	set_max_internal_encumbrance(100);

	bag_logic::create();
	set_name("chest");
	set_short("a rather impressive chest");
	set_id(({"chest"}));
	set_long(
@OLI
	This chest is carved wood with heavy iron brackets holding it shut.
You can tell that something valuable must be stored in here because 
of the heavy construction. This chest could easily withstand heavy fire,
heavy blows, and many other attacks.
OLI
	);
	set_weight(10000);
	set_value(75);
	
	set_key("black key");
	
}

void reset(){
	int imy;
	bag_logic::reset();
	imy = 20;
	if(!present("scroll"))
		while(imy--)
			new("/d/tharis/obj/pbwscroll")->move(TO);
	if(receive_objects())
		set_closed(1);	
	set_lock("locked");

}
