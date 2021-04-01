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
    call_out("check_sack_count",1);
}

void check_sack_count() {
    // Intentionally not deep_inventory
    if (TP && collapse_array(all_inventory(TP)->is_sack()) > 5) {
        write("%^B_CYAN%^%^BOLD%^%^GREEN%^You have too many containers. Lower the amount held as soon as roleplay permits.%^RESET%^");
        call_out("check_sack_count", 30);
        return;
    }
    remove_call_out("check_sack_count");
}

int is_sack()
{
    return 1;
}

int is_light_opaque()
{
    return 1;
}
