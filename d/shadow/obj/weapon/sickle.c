inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sickle" }));
   set_name("sickle");
   set_short("A sickle");
   set_long(
   "This short, heavy tool has a curved, almost semicircular, blade with the inside of the curve used most often to cut."
   "  It doesn't look like a very effective weapon compared to things like a two handed sword, but surprise is often the key."
   );
   set_weight(3);
   set_size(1);
   set("value", 6);
   set_cointype("silver"); 
   set_wc(1,4);
   set_large_wc(1,4);
   set_type("slash");
   set_prof_type("tool");
   set_weapon_speed(4);
}
