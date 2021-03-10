#include <std.h>
#include "../areadefs.h"
inherit MONSTER;
void create() {
    ::create();
    set_name("Shadowy Priest");
    set_id(({"shadow priest","shadow","shadowy priest","priest", "Shadowy Priest", "Priest"}));
    set_short("%^BOLD%^%^BLUE%^Shadowy Priest%^RESET%^");
    set_long(
@BRUENOR

    %^BOLD%^%^BLUE%^This priest is cloaked in shadows. All you can make out is
    %^BOLD%^%^BLUE%^his huge shield held in front of him and his flowing black robe
    %^BOLD%^%^BLUE%^that covers all of his body.
BRUENOR

    );
    set_race("human");
    set_gender("male");
    set_hd(35,8);
    set_class("cleric");
    set_level(35);
    set_guild_level("cleric",35);
    add_search_path("/cmds/cleric");
    set_size(2);
    set_alignment(9);
    set_overall_ac(-5);
    set_max_hp(1000);
    set_hp(1000);
    set_exp(20000);
    set_max_level(55);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("human");
    set_property("no bump",1);
    set_stats("strength",13);
    set_stats("dexterity",15);
    set_stats("constitution",16);
    set_stats("intelligence",17);
    set_stats("wisdom",18);
    set_stats("charisma",16);
    set_alignment(6);
    set_mob_magic_resistance("average");
   set("aggressive","aggfunc");
    set_emotes(3,({

	 "%^MAGENTA%^The priest mumbles: %^RESET%^The only certainty "+
	 "in life is %^BOLD%^%^BLACK%^death.",
     "%^MAGENTA%^The priest mumbles: %^RESET%^Life is just a shadow of reality.",
     "The priest %^RED%^%^BOLD%^cackles%^RESET%^"
    }),0);

    set_spell_chance(80);
    set_spells( ({ "darkbolt" }) );
    set_funcs(({"drain"}));
    set_func_chance(80);
    new(OBJ+"darkrobe.c")->move(TO);
    command("wear robe");
    new("/d/common/obj/weapon/mace.c")->move(TO);
    command("wield mace in left hand");
    new("/d/attaya/obj/pshield.c")->move(TO);
    command("wear shield");
    new("/d/common/obj/armour/fullplate.c")->move(TO);
    command("wear plate");
}

int aggfunc()
{
  command("say %^BOLD%^%^GREEN%^What do you want this time! "+
  "I am tired of healing you idiots every single day. Wait.."+
  "you don't belong here. You must perish!");
    new("/cmds/spells/f/_fire_storm")->use_spell(TO,0,30,100,"cleric");
    new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,34,100,"cleric");

        new("/cmds/spells/a/_animate_object.c")->use_spell(TO,TPQN,30,100,"cleric");
}



void drain(object targ)
{
	int num;
    int count;
	num = random(10)+1;
        command("say %^BOLD%^%^GREEN%^Abra kabazr Der!");
        tell_object(targ,"%^BOLD%^%^MAGENTA%^"+
                "The priest's eyes %^RED%^haze%^MAGENTA%^ \n"+
                "and he motions towards you \n"+
                "as your chest seems to cave \n"
                );
        tell_room(ETO,"%^BOLD%^%^MAGENTA%^"+
                "The priest motions towards "
                +targ->query_cap_name()+
                " and " +targ->query_cap_name()+
                " falls over "+
                "as particles of %^CYAN%^energy "+
                "%^MAGENTA%^escape from "+targ->query_cap_name(),targ);
    targ->do_damage("torso",roll_dice(6,6));
        for (count = 0;count < num;count++)
    	{
    		tell_object(targ,"%^BOLD%^%^MAGENTA%^"+
    			"It feels as if your %^CYAN%^life force%^MAGENTA%^ "+
    			"is being %^GREEN%^torn%^MAGENTA%^ right from you.");
    		tell_room(ETO,"%^BOLD%^%^MAGENTA%^"+
    			targ->query_cap_name()+" is racked with %^RED%^pain!",
    			targ);
		targ->do_damage("torso",roll_dice(1,5));
    	}
    targ->set_paralyzed(random(10)+8,"%^BOLD%^%^RED%^You feel exhausted");
    new("/cmds/spells/s/_sticks_into_snakes")->use_spell(TO,0,34,100,"cleric");
    return 1;
}
void die(object ob)
{
    tell_room(ETO,"%^BOLD%^%^CYAN%^The priest whispers to you: %^BLACK%^Death is only the beginning...");
    ::die(ob);
}
