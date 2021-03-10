/*Set xp to 1 since the lib was defaulting to above 10k xp per 
kill, which can become obscene with the PT XP bonus and 
cycling shifters - Octothorpe 1/6/12*/

#include <std.h>
inherit WEAPONLESS;

#define COLORS ({"%^BOLD%^%^BLUE%^blue","%^BOLD%^%^GREEN%^green","%^BOLD%^%^RED%^red","%^BOLD%^%^MAGENTA%^pink","%^YELLOW%^yellow","%^BOLD%^%^WHITE%^white","%^BOLD%^%^CYAN%^sky blue"})

void create() 
{
    string color;
    int i;
    
    ::create();
    set_name("crystal");
    set_id(({"crystal","monster","summoned monster"}));
    
    i = random(sizeof(COLORS));
    color = COLORS[i];

    set_gender("neuter");
    set_short("crystal");
    set_long(
        "This is a small "+color+" crystal %^RESET%^%^CYAN%^that "+
        "sparkles in the light.  It seems to move of its own "+
        "accord, animated somehow.  Its edges look quite sharp, "+
        "and it dodges out of the way of anyone trying to pick "+
        "it up.");       

    set_race("crystal");
    set_body_type("snake");
    set_size(1);
    remove_limb("mouth");
    remove_limb("head");
    remove_limb("tail");
    add_limb("crystal shard","torso",0,0,0);
    set_attack_limbs(({"crystal shard"}));
    set_base_damage_type("slashing");
    set_exp(1);
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("strength",14);
    set_stats("charisma",8);
    set_stats("dexterity",18);
    set_stats("constitution",7);
}


void setup_crystal(object caster)
{
    int num;

    if(!objectp(caster)) { return; }
    if(!objectp(TO)) { return; }

    num = (int)caster->query_guild_level("psion");
    if(!num) { num = (int)caster->query_lowest_level(); }

    set_level(num/2);
    set_hd(num/2,6);
    set_max_hp(roll_dice(3,num/2) + 50);
    set_hp(query_max_hp());
    set_attacks_num(0);//changing to 0 was 1 -Ares
    set_overall_ac(10-num);
    set_damage(1,6);
    return;
}
