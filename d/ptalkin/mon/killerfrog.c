#include <std.h>

inherit "/std/monster";

void create() {

::create();

set_name("%^BOLD%^BLUE%^killer frog");
set_id(({"killer frog", "killerfrog", "frog"}));
set_short("%^BOLD%^BLUE%^a killer frog");
set_long("
This is one of the smallest frogs, however, the most deadly as it
fights with talons and teeth.  It is a man-eating, specially bred
mutant.
");

set("race", "amphibian");
set_gender("male");
set_body_type("quadruped");
set_size(1);

set_level(5);
set_class("fighter");

set_hd(5,5);
set_hp(50);

set_wielding_limbs(({"right forepaw", "left forepaw", "head"}));
new("/d/ptalkin/weapons/p_talon")->move(this_object());
command("wield talon in right forepaw");
new("/d/ptalkin/weapons/p_talon")->move(this_object());
command("wield talon in left forepaw");
new("/d/ptalkin/weapons/kfteeth")->move(this_object());
command("wield teeth in head");

add_money("silver", (50));
}
