#include <std.h>
#include "../keep.h"

inherit MONSTER;

int flag, fb;

void spells() 
{
    if(objectp(ETO)) 
    {
        if(flag == 0) 
        {
            flag = 1;
            new("/cmds/spells/s/_stoneskin")->use_spell(TO,TO,14,10,"mage");
        }
    }
}

void create() 
{
    string des;
    monster::create();
    set_name("Lord Hawk");
    set_id(({"lord","lord hawk","hawk","Hawk","Lord"}));
    set_gender("male");
    set_race("ogre-mage");
    set_short("Lord Hawk, master of Keep Blacktongue");
    set_body_type("human");
    set_class("mage");
    set_mlevel("mage", 24);
    set_guild_level("mage",24);
    set("aggressive","do_attack");
    set_alignment(9);
    set_size(3);
    set_overall_ac(-8);
    set_stats("intelligence",19);
    set_stats("wisdom",14);
    set_stats("strength",18);
    set_stats("charisma",10);
    set_stats("dexterity",10);
    set_stats("constitution",14);
    set_mob_magic_resistance("average");
    set_hp(775 + random(51));
    set_new_exp(20, "boss");
    set_spell_chance(70);
    set_spells(({"magic missile","hideous laughter","lightning bolt",
    "lightning bolt","burning hands","magic missile","magic missile",
    "lightning bolt","lightning bolt"}));
    set_guild_level("mage", 14);
    new(KEEPO + "insigniaring")->move(TO);
    command("wear ring");
    if(random(3)) 
    {
        new("/d/shadow/obj/clothing/silkrobe")->move(TO);
        command("wear robe");
        des = "  His body is garbed with a %^YELLOW%^silken%^RESET%^ robe.%^RESET%^";
    }
    else 
    {
        des = ".%^RESET%^";
    }
    set_long("%^RESET%^This massive creature stands approximately 10' tall.  Its filthy, obese "+
    "flesh is a sickly light %^BOLD%^%^GREEN%^green%^RESET%^.  The visible hair on its body "+
    "is unkept and cluttered with filth.  Two small, %^BOLD%^%^WHITE%^ivory%^RESET%^ horns "+
    "protrude from the top of its head.  This creature is known as Lord Hawk, he is assumed "+
    "the master of the keep.  You notice that a %^BOLD%^%^WHITE%^bone%^RESET%^ ring adorns "+
    "one of his fat fingers" +des);
    add_search_path("/cmds/wizard/");
    call_out("spells",1);
    MOB_TR_D->do_treasure(TO,"B");
    
}

mixed filter_targets(object *arr)
{
    int x;
    object *newarr;
    if(!pointerp(arr)) return 0;
    newarr = ({});
    for(x = 0;x < sizeof(arr);x++) 
    {
        if(arr[x]->id("kguard")) continue;
        if(arr[x]->query_invis() || arr[x]->query_true_invis()) {
            continue;
        }
        newarr += ({arr[x]});
    }
    return newarr;
}

void reset_intro() 
{
    if(!objectp(TO)) return;
    fb = 0;
}

void do_attack() {
	int x;
    object targ;
	object *alive;

	alive = all_living(ETO);
	alive -= ({TO});
	
    if(!fb) {
        call_out("reset_intro",60);
        alive = all_living(ETO);
        alive -= ({TO});
        alive = filter_targets(alive);
        if(!sizeof(alive)) return;
        targ = alive[random(sizeof(alive))];   
                     
        command("speech growl");
        command("say INTRUDER!!");
        new("/cmds/spells/f/_fireball")->use_spell(TO,targ,24,24,"mage");
        fb = 1;	
        return 1;		
    }
    if(objectp(TP) && !TP->query_invis()) {
        command("kill "+TP->query_name());
    }
	return 1;
}
