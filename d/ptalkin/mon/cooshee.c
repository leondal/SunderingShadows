inherit "std/monster";

create() {
    ::create();
set_name("%^ORANGE%^a cooshee");
set_id(({"cooshee"}));
set("race", "dog");
set_gender("male");
set_short("%^ORANGE%^a cooshee");
set_long("%^ORANGE%^
A cooshee, or elven dog, is an average size dog.  It has a greenish 
coat with brown spots. This colouration enables the cooshee to conceal
itself in the forest or bush easily.  The average cooshe weighs 
around 250 lbs.  Its paws are huge with heavy claws and its tail 
is curled up over its back.
%^RESET%^");
set_level(15);
set_body_type("quadruped");
set("aggressive", 5);
set_overall_ac(5);
set_hd(9,11);
set_hp(125);
set_alignment(4);
set_size(1);
	set_stats("intelligence", 18);
	set_stats("wisdom", 20);
	set_stats("strength", 15);
   	set_stats("charisma",3);
set_stats("dexterity", 18);
	set_stats("constitution", 15);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
        set_exp(110);

set_wielding_limbs(({"right forepaw", "left forepaw", "right rear paw", "left rear paw", "head"}));
new("/d/ptalkin/weapons/teeth")->move(this_object());
command("wield teeth in head");
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
