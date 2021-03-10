inherit "/std/weapon";

create() {
    ::create();
set_id(({"dagger","long","long dagger"}));
set_name("long dagger");
   set_short("A long dagger");
   set_long(
"This is a long sharp, well crafted dagger."
   );
   set_weight(3);
   set_size(1);
   set("value", 500);
   set_wc(1,6);
   set_large_wc(1,6);
   set_type("piercing");
set_prof_type("small blades");
}
