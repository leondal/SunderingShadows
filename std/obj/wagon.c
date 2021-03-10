inherit "/std/bag_logic";

void create() {
    ::create();
    set_id( ({"wagon","Wagon"}) );
    set_name("Wagon");
    set("short", "An abandoned caravan wagon");
    set("long",
@OLI
    This is a beat up wooden wagon. I shows signs of a recent battle
that might explain why its here unattended. The wagon can carry many
items. It may have items still in it.

OLI

        );
    set_no_clean(1);
    set_weight(100000);
    set_value(1);
    set_max_internal_encumbrance(5000);
    set_possible_to_close(0);

}
