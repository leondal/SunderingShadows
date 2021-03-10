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
    %^RED%^probably be the two long sword he carries in each hand while
    %^RED%^he gives you a rather smug grin. Also you notice he wears a single
    %^RED%^ring on his right index finger along with a key around his neck.
BRUENOR
);
    set_race("human");
    set_moving(1);
    set_speed(70);
    set_gender("male");
    set_hd(35,10);
    set_class("ranger");
    set_class("assassin");
    add_search_path("/cmds/ranger");
    add_search_path("/cmds/assassin");
    set_size(2);
    set_mlevel("ranger",29);
    set_overall_ac(-5);
    set_property("full attacks",1);
    set_max_hp(450);
    set_hp(450);
    set_exp(20000);
    set("aggressive","aggfunc");
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("human");
    set_property("no bump",1);
    set_stats("strength",17);
    set_stats("dexterity",18);
    set_stats("constitution",15);
    set_stats("intelligence",16);
    set_stats("wisdom",12);
    set_stats("charisma",10);
    set_nogo(({"/d/islands/tonerra/mountain/mount2","/d/shadow/room/pass/pass1","/d/laerad/wasteland/waste1","/d/azha/town/wroad","/d/attaya/seneca3"}));
    set_mob_magic_resistance("low");
    set_alignment(9);

        ob = new("/d/common/obj/weapon/longsword.c");
        ob->set_property("monsterweapon",1);
        ob->set_property("enchantment", 5);
        ob->move(TO);
        command("wield sword in right hand");
        ob = new("/d/common/obj/weapon/longsword.c");
        ob->set_property("monsterweapon",1);
        ob->set_property("enchantment", 5);
        ob->move(TO);
        command("wield sword in left hand");
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


void aggfunc()
{
        if((string)TPQCN != "bruenor")
        {
        command("say %^RED%^Idiot, should know not to walk down dark tunnels!");
        command("say %^RED%^Almost caught me by surprise! But then again.. no
        you didnt!");
        command("kill "+TP->query_name());

        }
}

void die(object ob)
{
    tell_room(ETO,"%^RED%^The assassin falls over %^BOLD%^bleeding%^RESET%^%^RED%^ to death on the
ground.");
    ::die(ob);
}
