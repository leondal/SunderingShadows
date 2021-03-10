#include <std.h>
#include <daemons.h>

inherit MONSTER;
void create() {
    object ob;
    ::create();
    set_name("assassin");
    set_id(({"assassin", "mage", "mage assassin"}));
    set_short("%^RED%^Mage Assassin%^RESET%^");
    set_long(
@BRUENOR
%^RED%^This human seems to blend into the shadows with the dark robes he
%^RED%^wears. You cannot get a good look at him but he appears to be of
%^RED%^about average size for a human male. He does not appear to have
%^RED%^any weapons, but you know better then to trust on looks alone. On
%^RED%^his right hand he wears a ring on his right index finger. Around
%^RED%^his neck he wears a key.
BRUENOR
);
    set_race("human");
    set_moving(1);
    set_guild_level("mage",20);
    set_speed(70);
    set_gender("male");
    set_hd(35,10);
    set_class("mage");
    set_class("assassin");
    add_search_path("/cmds/mage");
    add_search_path("/cmds/assassin");
    set_size(2);
    set_mlevel("mage",20);
    set_overall_ac(-5);
    set_max_hp(350);
    set_hp(350);
    set_exp(17000);
    set("aggressive","aggfunc");
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("human");
    set_property("no bump",1);
    set_stats("strength",15);
    set_stats("dexterity",18);
    set_stats("constitution",15);
    set_stats("intelligence",18);
    set_stats("wisdom",12);
    set_stats("charisma",10);
    set_nogo(({"/d/islands/tonerra/mountain/mount2","/d/shadow/room/pass/pass1","/d/laerad/wasteland/waste1","/d/azha/town/wroad","/d/attaya/seneca3"}));
    set_mob_magic_resistance("average");
    set_spell_chance(85);
    set_spells(({
        "magic missile",
        "lightning bolt",
        "chain lightning"
      }));
    set_alignment(9);
        ob = new("/d/common/obj/armour/robe.c");
        ob->set_property("monsterweapon",1);
        ob->set_property("enchantment", 3);
        ob->move(TO);
        command("wear robe");
    ob=new("/d/magic/scroll");
    switch(random(4))
    {
            case 0:
                ob->set_spell(4);
                break;
            case 1:
                ob->set_spell(5);
                break;
            case 2:
                ob->set_spell(6);
                break;
            case 3:
                ob->set_spell(7);
                break;
    }
}

void aggfunc()
{
        if((string)TPQCN != "bruenor")
        {
        command("say %^RED%^Another day, another fight....");
        command("say %^RED%^I hope you don't actually think "+
        "you are going to survive...");
        command("kill "+TP->query_name());
    new("/cmds/spells/s/_stoneskin")->use_spell(TO,TO,20,100,"mage");
        }
}

void die(object ob)
{
    tell_room(ETO,"%^RED%^The mage assassin falls over "+
    "%^BOLD%^bleeding%^RESET%^%^RED%^ to death on the ground."
    );
    ::die(ob);
}
