inherit "/std/bag_logic";

void create()
{
    ::create();
    set_id(({ "sack", "large sack" }));
    set_name("large sack");
    set("short", "A large cloth sack");
    set_weight(5);
    set("long", "This is a large cloth sack. You could put things in it.\n");
    set_value(2);
    set_cointype("silver");
    set_max_internal_encumbrance(30);
    set_property("repairtype",({"tailor" }));
}

void init()
{
    ::init();

    // Intentionally not deep_inventory
    if (collapse_array(all_inventory(TP)->is_sack()) > 5) {
        write("%^BOLD%^%^RED%^You struggle to hold that many sacks, and drop it on the ground.");
        TO->move(ETP);
    }
}

int is_sack()
{
    return 1;
}

int is_light_opaque()
{
    return 1;
}
