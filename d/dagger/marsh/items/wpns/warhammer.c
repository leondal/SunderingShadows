inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "warhammer","hammer","war ahmmer","war" }));
   set_name("warhammer");
set_short("A 2-handed war hammer");
   set_long(
"This is a 2-handed War Hammer, it does terrible damage. "
   );
set_weight(55);
set_size(3);
set("value", 45);
set_wc(1,10);
set_large_wc(1,12);
   set_type("bludgeoning");
   set_prof_type("large hammer");
}
