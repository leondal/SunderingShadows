inherit "/std/vendor";

create() {
   ::create();
set_name("elvin boy");
set_id(({"elvin boy", "boy", "elf boy", "elf"}));
set_short("%^GREEN%^elvin boy");
   set("aggressive", 0);
set_level(10);
set_long("%^GREEN%^Like all other elves, this little fellow wears a tunic of forest colours, to blend into the scenery.  His freckled nose lies pert beneath, great blue eyes filled with mischief.  He stands about three feet tall, and wears soft leather hide boots.");
set_gender("male");
   set_alignment(4);
set("race", "elf");
set_size(1);
set_property("wimpy", 50);
add_money("gold", random(100));
   set_body_type("human");
set_hd(10,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
set_mp(random(100));
   set_max_mp(query_mp());
}
