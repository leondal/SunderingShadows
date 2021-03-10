inherit "/std/weapon";

create() {
    ::create();

set_id(({ "axe" }));
set_name("axe");
set_short("A axe");
   set_long(
"This is a huge axe that looks to be designed only for this orc.\n");
   set_weight(3);
    set_size(2);
    set_wc(1,6);
    set_large_wc(1,4);
   set_value(10);
   set_type("bludgeoning");
   set_prof_type("medium axe");
}
