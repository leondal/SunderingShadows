inherit "/std/weapon";

create() {
    ::create();

set_id(({ "arm", "an arm", "a arm" }));
set_name("arm");
set_short("An arm");
   set_long(
"It seems to be fresh, from a larger creature.\n");
set_weight(11);
set_size( 2 );
    set_wc(1,6);
    set_large_wc(1,8);
   set_property("monsterweapon",1);
}
