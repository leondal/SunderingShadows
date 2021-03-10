//Fallen Angels guild chest//
inherit "/std/bag_logic";

void create() {
    object money;

    ::create();
    set_id( ({"chest", "large chest"}) );
    set_name("An old wooden chest");
    set_short("An old wooden chest");
    set_long(
	"This is an old wooden chest.  Anyone may place "+
	"items or equipment into it so that others may use it.  Remember "+
	"that the items will disappear during reboots though."
    );
    set_no_clean(1);
    set_weight(99999);
    set_value(2);
    set_max_internal_encumbrance(99999);
    set_possible_to_close(1);
}
