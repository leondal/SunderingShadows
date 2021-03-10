inherit "/std/weapon";

create() {
    ::create();

set_id(({ "paintbrush", "a paintbrush" }));
set_name("paintbrush");
set_short("A paintbrush");
   set_long(
"This is a large paintbrush which has blue paint on it.\n");
set_weight(11);
   set_size( 1 );
    set_size(1,4);
    set_large_wc(1,3);
   set_value(5);
set_type("bludgeoning");
   set_prof_type("tool");
}
