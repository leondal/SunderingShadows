inherit "/std/weapon";

create() {
    ::create();
    set_name("longsword");
    set("short", "Cloud sword");
    set_obvious_short("long sword");
    set_id(({"sword", "cloud sword", "Cloud sword"}) );
    set_long("This sword is covered with small barbed\n"+
             "hooks on the edges, designed for ripping the skin when\n"+
             "it hits an opponent.\n");
    set_weight(7);
    set_size(2);
    set_type("slashing");
    set_wc(1,8);
    set_large_wc(1,12);
    set_wield_string("The sword glows when you wield it.\n");
    set_property("magic item", ({"illuminate"}) );
    set("value", 100);
    set_cointype("silver");
    set("read", "You cannot read this sword for all of the blood and gore\n"+
        "covering the naked blade.\n");
}
