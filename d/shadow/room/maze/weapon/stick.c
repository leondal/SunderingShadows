inherit "/std/weapon";

create() {
    ::create();

set_id(({ "stick" }));
set_name("stick");
set_short("A large stick");
set_long("This is a stick that looks liek it could be made out of metal.");
set_weight(5);
   set_size( 3 );
   set("value", 25);
   set_wc(1,10);
   set_large_wc(1,10);
   set_type("bludgeoning");
}
