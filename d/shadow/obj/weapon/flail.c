inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "flail" }));
   set_name("flail");
   set_short("A flail");
   set_long(
   "This flail has a long wooden handle that is topped with a swivel which is connected to a chain that has a heavy, shorter piece of wood attached."
    "  The smaller piece of wood is shod in iron and has small spikes protuding from it to increase the damage to the area struck when it's whirled."
   );
   set_weight(15);
   set_size(2);
   set("value", 15);
   set_wc(1,6);
   set_large_wc(2,4);
   set_type("bludgeoning");
   set_prof_type("flail");
   set_weapon_speed(7);
}
