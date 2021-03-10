inherit "/std/vendor";

create() {
   ::create();
set_name("delivery boy");
set_id(({"delivery boy", "delivery_boy", "elf", "boy"}));
set_short("delivery boy");
set_long("%^CYAN%^This little urchin stand about 3 feet tall, with riotous red hair, freckles, scraped knees, and a bruised chin.  Like most elven children, he is used to running through the trees, as easily as one would run on the ground, however, this fellow seems to come a cropper quite often.  He is dressed in an amber coloured tunic, with matching trousers, and has a soft piece of rope as a belt.  His feet are covered in very good, soft hide boots, and he carries a deep forest green cloak.");

set_languages( ({"common", "elvish"}) );
set_gender("male");
set("race", "elf");
set_body_type("human");
set_size(2);
set_class("fighter");
set("aggressive", 0);
set_alignment(4);

set_level(10);
set_stats("intelligence", 14);
set_stats("wisdom", 14);
set_stats("strength", 10);
set_stats("charisma", 10);
set_stats("dexterity", 15);
set_stats("constituion", 10);

set_hp(75);
set_hd(10,2);

set_wielding_limbs(({"right hand", "left hand", "torso"}));





add_money("gold", (100));
}
