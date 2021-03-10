//monsters by the House of Svaha

#include <std.h>

inherit MONSTER;

void create() {
::create();

set_name("phanaton");
set_id(({"phanaton"}));
set_short("%^RED%^phanaton%^");
set_long(
@DESC
This little charmer looks like a cross between a raccon and a monkey.
She in about four feet tall, and has a four foot prehensile tail.
She prefers to eat fruit and vegetables, but may on occasion eat meat.
She also has membrane between her arms and torso, so glide with.
A phanaton is a friend to elves, dryads and treants, however, they hate
aracnea, the spider-folk and will attack them on sight.
DESC
);
set("race", "phanaton");
set_body_type("humanoid");
set_gender("female");
set_class("fighter");
set_level(11);

set_alignment(1);
set("aggressive", 10);
set_size(2);

set_stats("strength", 13);
set_stats("intelligence", 10);
set_stats("wisdom", 8);
set_stats("dexterity", 17);
set_stats("constitution", 15);
set_stats("charisma", 11);

set_overall_ac(7);
set_hd(3,4);
set_hp(75);
set_sp(100);
set_property("swarm", 1);
set_wielding_limbs(({"head", "left hand", "right hand"}));
new("/d/ptalkin/weapons/teeth")->move(this_object());
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
new("/d/dagger/Elvanta/forest/items/wpns/p_claw")->move(this_object());
command("wield teeth in head");
command("wield claw in right hand");
command("wield claw 2 in left hand");
}
