#include <std.h>
#include "../areadefs.h"
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
    He seems to be completly average.  The only thing out of place would
    probably be the long bloody daggers he is carrying around rather
    brazenly. Also you notice he wears a single ring on his right index
    finger along with a key around his neck.
BRUENOR
);
    set_race("human");
    set_gender("male");
    set_hd(35,10);
    set_class("thief");
    set_class("assassin");
    add_search_path("/cmds/thief");
    add_search_path("/cmds/assassin");
    set_size(2);
    set_mlevel("thief",35);
    set_overall_ac(-8);
    set_max_hp(400);
    set_hp(400);
    set_thief_skill("move silently",95);
    set_thief_skill("hide in shadows",95);
    set_exp(5000);
    set("aggressive","aggfunc");
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("human");
    set_property("no bump",1);
    set_stats("strength",19);
    set_stats("dexterity",18);
    set_stats("constitution",14);
    set_stats("intelligence",16);
    set_stats("wisdom",12);
    set_stats("charisma",10);
    set_nogo(({"/d/islands/tonerra/mountain/mount2","/d/shadow/room/pass/pass1","/d/laerad/wasteland/waste1","/d/azha/town/wroad","/d/attaya/seneca3"}));
    set_mob_magic_resistance("low");
    set_alignment(9);

    new(OBJ+"riftund.c")->move(TO);
        ob = new("/d/common/obj/weapon/dagger.c");
        ob->set_property("monsterweapon",1);
        ob->set_property("enchantment", 1);
        ob->move(TO);
        command("wield dagger in left hand");
        ob = new("/d/common/obj/weapon/dagger.c");
        ob->set_property("monsterweapon",1);
        ob->set_property("enchantment", 1);
        ob->move(TO);
        command("wield dagger in right hand");
}



int kill_ob(object victim, int which)
{
    int hold;
    hold = ::kill_ob(victim, which);
    if(hold)
    {
        if(interactive(victim))
        {
              TO->force_me("say %^RED%^Death is only a phase in life... A very long one!
");
          TO->force_me("crit "+victim->query_name());
        }
        }
   return hold;
}


void aggfunc()
{
        if((string)TPQCN != "bruenor")
        {
        command("say %^RED%^What are you doing interrupting me!");
        command("say %^RED%^Do not bother me when i am on the job!");
        command("say %^RED%^I'm just trying to perform a simple hit "+
        "and you come in here and get in the way. What nerve...");
        command("say %^RED%^Their cannot be any witnesses. You must "+
                "die!");
        command("stab "+TP->query_name());
        command("scramble");
        }
}

void die(object ob)
{
    tell_room(ETO,"%^RED%^The assassin falls over %^BOLD%^bleeding%^RESET%^%^RED%^ to death on the
ground.");
    ::die(ob);
}
