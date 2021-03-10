inherit "/d/common/obj/weapon/warhammer";

create() {
    ::create();
   set_id(({ "warhammer","hammer","war hammer","war","mithril hammer","mithril warhammer","mithril war hammer","mithril dwarven warhammer","dwarven hammer","dwarven warhammer","dwarven war hammer" }));
   set_name("mithril dwarven warhammer");
   set_short("A mithril dwarven warhammer");
   set_long(
   "This is a bright silvery mithril dwarven warhammer. It was forged by one of the Dwarves of Mt. Sholkum. Dwarven runes line the handle of the warhammer and it glows with strength. On the head of the hammer is the crest of the Army of the Dagger Reaches."
   );
//set_weight(6);
//set_size(2);
   set("value", 2);
//set_wc(1,4);
//set_large_wc(1,4);
//set_type("bludgeoning");
//set_prof_type("medium hammer");
   set_property("enchantment",1);
//set_weapon_speed(4);
}
