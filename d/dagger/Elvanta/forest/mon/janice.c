 
#include "/d/shadow/mon/melnmarn.h";
#include <daemons.h>
inherit MONSTER;
void create() {
    ::create();
set_name("Janice");
set_id( ({"janice", "Janice", "Janice the spatzl"}) );
set("race", "elf");
set_gender("female");
set_short("Janice, the spatzl");
set_long("BOLD%^RED%^Young she is, and yet, not so.  The braids of her dark hair are touched by no frost, her white arms and clear face are flawless and smooth, and the light of the stars are in her bright eyes, grey as a cloudless night; yet queenly she looks and thought and knowledge are in her glance, as one who has knows many things that the years bring.  Above her brow her head is covered with a cap of silver lace netted with small gems, glittering white.
But her soft grey rainment has no ornament other than a girdle of leaves wrought in silver.%^RESET%^");
set_level(20);
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
set_overall_ac(1);
set_property("swarm",1);
        set_max_mp(0);
        set_mp(query_max_mp());
set_hd(18,1);
set_exp(500);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
set_wielding_limbs( ({"right hand", "left hand", "torso"}) );
new("/d/shadow/obj/weapon/longsword")->move(this_object());
command("wield longsword in left hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
        command("wear armor");
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
} 
