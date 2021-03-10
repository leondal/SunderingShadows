inherit "/std/vendor";

create() {
   ::create();
set_name("elvin girl");
set_id(({"elvin girl", "girl", "elf girl", "elf"}));
set_short("%^GREEN%^elvin girl");
   set("aggressive", 0);
set_level(10);
set_long("%^GREEN%^This tiny little girl is perfect in every detail.  From her tiny heart shaped face to her delicate little feet.  However, tiny as she may be, she is an elf and can therefore look after herself quite well.");
set_gender("female");
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
