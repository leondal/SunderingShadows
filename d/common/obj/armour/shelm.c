inherit "/d/common/obj/armour/helm";

void create() {
    ::create();
   // set_name("helm");
   // set("id", ({ "helm", "helmet", "great helm" }) );
    set_short("A small helm");
   set_long("This open face metal helmet covers the entire head, neck, and "
     "upper shoulders of the wearer.  It is designed to offer good protection "
     "but is quite unwieldy and awkward to wear.");
    set_weight(5);
    //set("value", 30);
    //set_type("armour");
    //set_limbs( ({ "head" }) );
    //set_ac(1);
    set_size(1);
   //set_remove("The helm slips off your head awkwardly.  You feel vulnerable but "
     // "much more comfortable.");
}

int is_metal() { return 1; }