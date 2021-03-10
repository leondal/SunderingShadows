inherit "/std/weapon";

create() {
    ::create();

set_id(({ "sword" }));
     set_name("sword");
set_short("A Skeleton Sword");
   set_long(
"The sword is made out of the leg of a dead skeleton.\n");
set_weight(11);
    set_size(2);
    set_wc(1,6);
    set_large_wc(1,8);
   set_value(50);
set_type("slashing");
}
