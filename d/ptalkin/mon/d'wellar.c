inherit "/std/vendor";

create() {
   ::create();
set_name("D'wellar, weapons master");
set_id(({"D'wellar", "d'wellar", "weaponsmaster", "weapons master"}));
set_short("D'wellar, weapons master");
   set("aggressive", 0);
   set_level(19);
set_long("%^ORANGE%^D'wellar stands five feet six inches tall, has blonde hair and blue eyes.  He is tall for an elf, and very bulky due to years of honing, repairing and making weapons.  His arms look like limbs of a tree, bulging with muscles.  Oil, dirt and metal shavings marks his leather apron.");
   set_gender("male");
   set_alignment(4);
set("race", "elf");
   add_money("gold", random(500));
   set_body_type("human");
set_size(2);
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
set_storage_room("/d/ptalkin/room/w_storage");
   set_items_allowed("weapon");
}
void init(){
    ::init();
	set_heart_beat(1);
}

