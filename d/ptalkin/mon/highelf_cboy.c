inherit "/std/vendor";

create() {
   ::create();
set_name("elvin boy");
set_id(({"elvin boy", "boy", "elf boy", "elf"}));
set_short("%^GREEN%^elvin boy");
   set("aggressive", 0);
set_level(10);
set_long("%^GREEN%^This little fellow looks to be about ten human years old.  He is spending most of his time just looking around.  Peering into shop windows and eyeing the merchandise.  Now, whether or not he is going to 'buy' something or not is debatable.  Most shopkeepers keep a close eye on this jaunty young fellow.");
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
set_emotes(2, ({
"the elvin boy looks at you, all innocence in his blue eyes - 'Who me?"
}), 0);
}
