//	chest.c
//	a lockable treasure chest
//	written by Descartes 21 October 1992

inherit "/std/bag_logic";

void create() {
    object money;

    ::create();
    set_id( ({"chest", "large chest"}) );
    set_name("chest");
    set("short", "%^BOLD%^%^RED%^A large chest%^RESET%^");
    set("long", "%^RESET%^%^ORANGE%^This is a large wooden chest. It looks quite old.\n%^RESET%^It is closed.");
    set_open_long("%^RESET%^%^ORANGE%^This is a large wooden chest. It looks quite old.\n%^RESET%^It is open.");
    set_closed_long("%^RESET%^%^ORANGE%^This is a large wooden chest. It looks quite old.\n%^RESET%^It is closed.");
    set_no_clean(1);
    set_weight(25);
    set_value(2);
    set_max_internal_encumbrance(150);
    set_possible_to_close(1);
}
