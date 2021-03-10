#include <std.h>
#include "../../fways.h"
inherit "/std/monster";

void create()
{
    object myob;
    ::create();
    set_name("pixie");
    set_id(({"pixie", "enraged pixie", "dallyhallyevil"}));
    set_short("%^BOLD%^%^MAGENTA%^An enraged pixie%^RESET%^");

    set_long("%^BOLD%^%^MAGENTA%^This strange little creature flies "+
    "rapidly back in forth, its tiny %^RESET%^%^ORANGE%^butterfly%^BOLD%^%^MAGENTA%^ "+
    "wings moving so quickly that the eye can barely discern their existence. "+
    "Its face looks enraged and its deep %^BOLD%^%^BLACK%^dark%^BOLD%^"+
    "%^MAGENTA%^ eyes stand in stark contrast to the short pink hair "+
    "which frames it. There are streaks of dirt and mud beneath each of them "+
    "as if this little creature has prepared for war.%^RESET%^");

    set_gender("female");
    set_level(24);
    set_race("pixie");
    set_body_type("human");
    set_class("fighter");
    set_class("thief");
    set_class("thief");
    set_mlevel("thief",24);
    set_level(24);
    set_guild_level("thief",24);
    set_property("full attacks",1);
    set_scrambling(1);
    add_attack_bonus(3);
    set_mlevel("fighter",24);
    set_alignment(9);
    set_size(1);
    set_hd(24, 1);
    set_overall_ac(-3);
    set_moving(1);
    set_speed(30);
    set_hp(270+random(150));
    set("aggressive", 16);
    set_wielding_limbs(({"right hand", "left hand"}));
    new("/d/common/obj/weapon/dagger")->move(this_object());
    command("wield dagger");
    switch(random(4))
    {
        case 0 : "/d/common/daemon/randgear_d"->arm_me(TO,"edgeds",40,random(2)+2);
            break;
        case 1..3 : new("/d/islands/dallyh/forest/obj/sky_dagger")->move(TO);
            command("wield dagger");
            break;
    }
    add_money("gold",random(100));
    set_new_exp(25, "normal");
    set_mob_magic_resistance("high");
    if(!random(4))
    {
        myob = new("/d/islands/dallyh/forest/obj/rosebodice");
        myob->move(TO);
        myob->set_size(1);
        command("wear bodice");
    }
    myob = new("/d/common/obj/rand/womendress");
	if(!random(4))
    {
        myob->set_property("monster weapon",1);
	}
	myob->move(TO);
	command("wear dress");
    set_stats("strength", 17);
    set_stats("dexterity", 22);
    set_stats("intelligence", 17);
    set_stats("wisdom", 17);
    set_stats("charisma", 27);
    set_stats("constitution", 18);
    set_nogo(({DDOCK, FRPATH"road1"}));
}
