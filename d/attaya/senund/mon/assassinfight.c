#include <std.h>
#include <daemons.h>

inherit MONSTER;
void create() {
    object ob;
    ::create();
    set_name("assassin");
    set_id(({"assassin"}));
    set_short("%^RED%^Assassin%^RESET%^");
    set_long(
@BRUENOR
    %^RED%^You cannot tell any distinctive features from this particuliar human.
    %^RED%^He seems to be completly average.  The only thing out of place would
    %^RED%^probably be the rather large sword he carries in both hands while
    %^RED%^swinging around rather brazenly. Also you notice he wears a single
    %^RED%^ring on his right index finger along with a key around his neck.
BRUENOR
);
    set_race("human");
    set_moving(1);
    set_speed(70);
    set_gender("male");
    set_hd(35,10);
    set_class("fighter");
    set_class("assassin");
    add_search_path("/cmds/fighter");
    add_search_path("/cmds/assassin");
    set_property("full attacks",1);
    set_size(2);
    set_mlevel("fighter",32);
    set_overall_ac(-10);
    set_max_hp(675);
    set_hp(675);
    set_exp(20000);

    set("aggressive","aggfunc");
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("human");
    set_property("no bump",1);
    set_stats("strength",19);
    set_stats("dexterity",16);
    set_stats("constitution",15);
    set_stats("intelligence",16);
    set_stats("wisdom",12);
    set_stats("charisma",10);
    set_nogo(({"/d/islands/tonerra/mountain/mount2","/d/shadow/room/pass/pass1","/d/laerad/wasteland/waste1","/d/azha/town/wroad","/d/attaya/seneca3"}));
    set_mob_magic_resistance("low");
    set_funcs(({"cleave"}));
    set_func_chance(20);
    set_alignment(9);

        ob = new("/d/common/obj/weapon/two_hand_sword.c");
        ob->set_property("monsterweapon",1);
        ob->set_property("enchantment", 5);
        ob->move(TO);
        command("wield sword");
}



int kill_ob(object victim, int which)
{
    int hold;
    hold = ::kill_ob(victim, which);
    if(hold)
    {
        if(interactive(victim))
        {
          TO->force_me("say %^RED%^Death is only a phase in life... A very long one!");
          if(!random(4))
          {
          TO->force_me("crit "+victim->query_name());
          }
        }
        }
   return hold;
}


void cleave(object targ)
{
        command("say Your time is now!");
        tell_object(targ,
        "%^BOLD%^%^RED%^The warrior assassin leaps towards you slicing \n"+
        "%^BOLD%^%^RED%^you deeply with his two-handed blade with a\n"+
        "%^BOLD%^%^RED%^powerful overhand cleave!"
                );
        tell_room(ETO,
            "%^BOLD%^%^RED%^The assassin jumps towards "
           +targ->QCN+
            "%^BOLD%^%^RED%^ and slices " +targ->query_cap_name()+
            "%^BOLD%^%^RED%^ deeply with his two-handed sword "+
            "%^BOLD%^%^RED%^with a powerful overhand cleave!",targ);
    targ->do_damage("head",roll_dice(6,6));
    targ->set_paralyzed(random(10)+8,"%^RED%^The pain is overwhelming");
    return 1;
}

void aggfunc()
{
        if((string)TPQCN != "bruenor")
        {
        command("say %^RED%^Idiot, should know not to walk down dark tunnels!");
        command("rush "+TP->query_name());
        command("parry");
        }
}

void die(object ob)
{
    tell_room(ETO,"%^RED%^The assassin falls over %^BOLD%^bleeding%^RESET%^"+
    "%^RED%^ to death on the ground.");
    ::die(ob);
}
