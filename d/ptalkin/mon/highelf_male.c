inherit "/std/vendor";

create() {
   ::create();
set_name("male elf");
set_id(({"elf", "high elf", "male elf"}));
set_short("male elf");
set_long("%^CYAN%^Standing around five feet tall, this elf is fair of skin and hair and has blue eyes.  He is wearing a pale blue tunic with matching trousers tied with a beaten silver belt.  He wears a travelling cloak of forest green.");

set_gender("male");
set("race", "elf");
set_body_type("human");
set_size(2);
set_class("fighter");
set("aggressive", 0);
set_alignment(4);

set_level(17);
set_stats("intelligence", 20);
set_stats("wisdom", 14);
set_stats("strength", 14);
set_stats("charisma", 10);
set_stats("dexterity", 21);
set_stats("constitution", 16);

set_hp(120);
set_hd(15,3);

set_wielding_limbs(({"right hand", "left hand", "torso"}));
new("/d/shadow/obj/weapon/longsword")->move(this_object());
command("wield longsword in right hand");





add_money("gold", (100));
}
