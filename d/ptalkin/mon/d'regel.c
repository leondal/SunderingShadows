inherit "/std/vendor";

create() {
   ::create();
set_name("D'regel");
set_id(({"shop keeper", "shopkeeper", "clerk", "D'regel", "d'regel"}));
set_short("D'regel, shopkeeper");
   set("aggressive", 0);
   set_level(19);
set_long("%^ORANGE%^This elf also has blonde hair and pointy ears, however, he charms the ladies with his deep set emerald eyes.  He putters around the store taking inventory, talking to customers and tidying his stock.");
   set_gender("male");
   set_alignment(4);
set("race", "elf");
   add_money("gold", random(500));
   set_body_type("human");
set_size(2);
set_storage_room("d/ptalkin/room/g_storage");
   set_property("no attack", 1);
   set_hd(19,3);
   set_items_allowed("misc");
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
set_emotes(2, ({
"D'regel asks : May I assist you?",
"D'regel says : Feel free to look around"
}), 0);
}
