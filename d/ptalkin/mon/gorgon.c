//monsters by the House of Svaha

#include <std.h>

inherit MONSTER;

void create() {
::create();
set_name("gorgon");
set_id(({"gorgon"}));
set_short("%^GREEN%^gorgon");
set_long(
"%^GREEN%^
This gorgon is a bull-like creature, covered with thick metal scales. She
prefers the vastness of a wilderness or dreary caverns.  She has two
foot long curved horns, with wickedly sharp points.  She can attack 
you with her horns, teeth, and huge sharp-edged hooves.  
%^RESET%^");

set("race", "gorgon");
set_gender("female");
set_body_type("quadruped");
set_size(3);

set_level(15);
set_class("fighter");
set("aggressive", 10);

set_stats("strength", 15);
set_stats("intelligence", 13);
set_stats("wisdom", 10);
set_stats("dexterity", 15);
set_stats("constitution", 19);
set_stats("charisma", 10);

set_hd(15,8);
set_hp(100);

set_wielding_limbs(({"head", "right forepaw", "left forepaw"}));
new("/d/ptalkin/weapons/gor_teeth")->move(this_object());
new("/d/ptalkin/weapons/hoof")->move(this_object());
new("/d/ptalkin/weapons/hoof")->move(this_object());
command("wield hoof in right forepaw");
command("wield hoof 2 in left forepaw");
command("wield teeth in head");
}
