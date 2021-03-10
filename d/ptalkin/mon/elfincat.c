inherit "std/monster";

create() {
    ::create();
set_name("%^ORANGE%^elfin cat");
set_id(({"elfin cat", "elfincat", "cat"}));
set("race", "feline");
set_gender("female");
set_short("%^ORANGE%^an elfin cat");
set_long("%^ORANGE%^
About the size of an average dog, her fur is gray-brown and striped
with black.  She stands sentinel for the sylvan elves by reporting
intruders into the forest and what purpose they may have in mind.
%^RESET%^");
set_level(15);
set_body_type("quadruped");
set("aggressive", 10);
set("wimpy", 75);
set_hd(12,8);
set_alignment(4);
set_size(1);
	set_stats("intelligence", 18);
	set_stats("wisdom", 20);
	set_stats("strength", 15);
   	set_stats("charisma",3);
set_stats("dexterity", 18);
	set_stats("constitution", 15);
set_hp(100);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
        set_exp(110);

set_wielding_limbs(({"right forepaw", "left forepaw", "right rear paw", "left rear paw"}));
new("/d/ptalkin/weapons/smclaws")->move(this_object());
command("wield claws in right forepaw");
new("/d/ptalkin/weapons/smclaws")->move(this_object());
command("wield claws in left forepaw");
new("/d/ptalkin/weapons/smclaws")->move(this_object());
command("wield claws in right rear paw");
new("/d/ptalkin/weapons/smclaws")->move(this_object());
command("wield claws in left rear paw");
	add_money("silver",random(10));
	add_money("copper",random(20));
   
}
