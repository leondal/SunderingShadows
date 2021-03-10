 
#include <std.h>
inherit MONSTER;
void create() {
    ::create();
set_name("courtier");
set_id(({"courtier"}));
set("race", "elf");
        set_gender("male");
set_short("A courtier");
set_long("%^ORANGE%^One of the many social butterflies that hang around courts of all types throughout the lands.  While they may appear to be interesting at first, you learn they hold no substance.  Unfortunately, like a jar of honey, a court draws courtiers  like bees.%^RESET%^");
set_level(12);
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
set_overall_ac(0);
set_stats("intelligence", 14);
set_property("swarm",1);
set_stats("wisdom", 10);
set_stats("strength", 14);
set_stats("charisma", 20);
set_stats("dexterity", 15);
set_stats("constitution", 7);
        set_max_mp(0);
        set_mp(query_max_mp());
set_hd(20,1);
set_hp(100);
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
