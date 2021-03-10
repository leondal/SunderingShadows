inherit "/std/vendor";

create() {
   ::create();
set_name("elven baby");
set_id(({"elvin baby", "baby", "elf baby", "elf"}));
set_short("%^GREEN%^elvin baby");
   set("aggressive", 0);
set_level(5);
set_long("%^GREEN%^Lying upon a quilted blanket, a tiny form wriggles and coos at you.  No bigger than a loaf of bread, your gaze is held by emerald eyes, full of life, time, joy and sorrow.");
set_gender("female");
   set_alignment(4);
set("race", "elf");
   set_body_type("human");
set_hd(0,0);
set_size(1);
add_exp(-100);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
set_mp(random(100));
   set_max_mp(query_mp());
}
