//monsters by the House of Svaha

#include <std.h>

inherit MONSTER;

void create(){
int resist;
:: create();

set_name("%^ORANGE%^Shargugh");
set_id(({"shargugh", "Shargugh"}));
set_short("%^ORANGE%^a shargugh");
set_long(
@DESC
%^ORANGE%^This little humanoid looks like a wizened old man, with hair 
a dirty brown colour and matted, matching its long tangled beard.  He 
looks like a walking dirty haystack.  He is wearing brown and green
clothing of some type, but its hard to tell underneath all that hair.
He has large deep brown eyes which reflect the passage of time, and
carries a small silver dagger of great beauty.  He is only about three
feet tall, and very quick with his gnarled fingers.
DESC
);
set_race("shargugh");
set_gender("male");
set_body_type("humanoid");
set("size", 2);
set_class("thief");
set("aggressive", 5);
set_alignment(5);
set_overall_ac(5);

set_stats("intelligence", 15);
set_stats("wisdom", 13);
set_stats("strength", 17);
set_stats("charisma", 4);
set_stats("dexterity", 15);
set_stats("constitution", 20);

set_hd(9,4);
set_exp(100);
set_hp(75);

set_wielding_limbs(({"left hand"}));
new("/realms/general/weapons/knife")->move(this_object());
command("wield knife in left hand");

resist = 30 + random(30) + random(30);
set_property("magical resistance", resist);

add_money("gold", (50));

set_thief_skill("pick pockets", 85);
toggle_steal();
}
