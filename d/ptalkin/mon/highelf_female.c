inherit "/std/vendor";

create() {
   ::create();
set_name("female elf");
set_id(({"elf", "high elf", "female elf"}));
set_short("female elf");
set_long("%^CYAN%^Before you stands an elf.  Reaching perhaps four and a half feet tall, she is exquisite in every detail.  Fine features with slightly tiltd bright blue eyes are set within a finely boned face.  Lovely golden tresses of hair ripple in the breeze.  A tunic, autumn red in colour clads the elf in all the right places.  A thin belt of braided silver encircles her slender waist.  Bare legs, shown off to good advantage end in short leather boots.  A cape of forest green lays upon her back.");

set_gender("female");
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
