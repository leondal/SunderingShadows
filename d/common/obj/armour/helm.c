inherit "/std/armour";

void create() {
    ::create();
    set_name("helm");
    set_armor_prof("heavy");
    set("id", ({ "helm", "helmet", "great helm" }) );
    set("short", "Great helm");
    set("long", "This massive metal helmet covers the entire head, neck, and "
     "upper shoulders of the wearer.  It is designed to offer good protection "
     "but is quite unwieldy and awkward to wear.  The only gaps are for "
     "the small eyeslits and a grate in front of the mouth for air.");
    set_weight(6);
    set("value", 30);
    set_type("armour");
    set_limbs( ({ "head" }) );
    set_ac(1);
    set_remove("The helm slips off your head awkwardly.  You feel vulnerable but "
      "much more comfortable.");
}

int is_metal() { return 1; }
