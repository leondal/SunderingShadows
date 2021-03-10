//	/obj/bag.c
//	from the Nightmare mudlib
//	a simple bag
//	created for the TMI distribution mudlib
//	by Truilkan 20 April 1992

inherit "/std/bag_logic";

void create() {
    set_id( ({"bag"}) );
    set_name("bag");
    set("short", "a small cloth bag");
    set_weight(274);
    set("long", "This is a simple cloth bag that you could put things in.\n");
    set_value(50);
    set_max_internal_encumbrance(500);
}
