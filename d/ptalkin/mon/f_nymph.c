 
#include "/d/shadow/mon/melnmarn.h";
#include <daemons.h>
inherit MONSTER;
void create() {
    ::create();
set_name("wood nymph");
set_id(({"nymph"}));
set("race", "nymph");
set_gender("female");
set_short("a wood nymph");
set_long("%^GREEN%^White gauze clothes her, transparent and weightless.  The pale green skin of her child's body glimmers beneath the covering.  Waist-length silver hair ripples and shimmers with the slight breeze.");
	set_level(14);
	set_body_type("human");
	set_class("fighter");
	set("aggressive", 0);
	set_alignment(8);
set_property("swarm", 1);
	set_size(2);
	set_overall_ac(0);
	set_property("wimpy", 25);
	set_stats("intelligence", 14);
	set_stats("wisdom", 14);
	set_stats("strength", 14);
	set_stats("charisma", 10);
	set_stats("dexterity", 20);
	set_stats("constitution", 15);
	set_hd(14,1);
	set_hp(75);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
new("/d/dagger/Elvanta/forest/items/wpns/p_knife")->move(this_object());
command("wield knife in right hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
        command("wear armor");
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
} 
