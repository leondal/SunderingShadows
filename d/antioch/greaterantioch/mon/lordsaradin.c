#include <std.h>
#include "../gantioch.h"

inherit MONSTER;
object ob;

void create()
{
    ::create();
    set_name("%^BOLD%^%^MAGENTA%^Lord %^BOLD%^%^RED%^Saradin Torvall, %^BOLD%^%^CYAN%^Paladin of %^BOLD%^%^YELLOW%^Jarmila%^RESET%^");
    set_id(({ "saradin", "human", "paladin", "lord" }));
    set_short("%^BOLD%^%^MAGENTA%^Lord %^BOLD%^%^RED%^Saradin Torvall, %^BOLD%^%^CYAN%^Paladin of %^BOLD%^%^YELLOW%^Jarmila%^RESET%^");
    set_long("%^RESET%^Saradin is tall for a human, and his muscular form seems quite sturdy. Despite" +
             " his size, he appears lithe and quick on his feet. His demeanor is that of a" +
             " skilled warrior. His eyes, confident and alert, are ashade of hazel, pale green" +
             " with slight traces of brown. His fiery scarlet hair is long, straight and clean." +
             " Although typically pulled away from his face in a ponytail, it falls between his" +
             " shoulder blades when loose. Tanned skin hints at hours spent outdoors under the" +
             " sun, but his flesh is clean and smooth. The weight he carries upon himself" +
             " seems to hinder him little, and even when hidden beneath layers of protection" +
             " the strength of his well-tonned muscles is obvious. The man seems to put as much" +
             " care into the maintenance of his belongings as he puts into his own" +
             " appearance. He is approximately 66 inches tall and 250 pounds.");
    set_class("fighter", "paladin");
    set_guild_level("fighter", 20);
    set_guild_level("paladin", 20);
    set_guild_level("warmaster", 10);
    set_mlevel("fighter", 20);
    set_mlevel("paladin", 20);
    set_mlevel("warmaster", 10);
    set_race("human");
    set_body_type("humanoid");
    set_property("no bows", 1);
    set_gender("male");
    set_hd(50);
    set_max_hp(3000);
    add_attack_bonus(15);
    add_damage_bonus(15);
    set_hp(3000);
    set_overall_ac(-50);
    set_size(2);
    set("aggressive", 1);
    set_exp(50000);
    ob = new(OBJ + "redemption2");
    set_max_level(12);
    set_wielding_limbs(({ "right hand", "left hand" }));
    if (random(1)) {
        ob->set_property("monsterweapon", 1);
    }
    ob->move(TO);
    command("wield hammer");
    set_property("full attacks", 4);
    set_stats("strength", 22);
    set_stats("constitution", 21);
    set_stats("intelligence", 13);
    set_stats("wisdom", 14);
    set_stats("charisma", 20);
    set_stats("dexterity", 13);
    set_mob_magic_resistance("average");
    set_alignment(1);
    set_property("no death", 1);
    set_func_chance(100);
    set_funcs(({ "flashit", "rushit", "rushit", "impaleit", "smiteit", "sweepit" }));
    add_search_path("/cmds/fighter");
    set_property("add kits", 50);
    set_property("no steal", 1);
    set_monster_feats(({
        "parry",
        "powerattack",
        "impale",
        "light weapon",
        "strength of arm",
        "sweepingblow",
        "daze",
        "disarm",
        "force of personality",
        "indomitable",
        "layonhands",
        "smite",
        "leadership",
        "expertise",
        "knockdown",
        "damage resistance",
        "improved damage resistance",
        "improved toughness",
        "shatter",
        "sunder",
        "rush"
        "regeneration",
        "toughness",
        "wade through",
        "skull collector",
        "the reaping",
        "weapon training",
        "armor training",
        "weapon mastery",
        "armor mastery"
    }));
}

void knockit(object targ)
{
    TO->force_me("knockdown " + targ->query_name());
}

void impaleit(object targ)
{
    TO->force_me("impale " + targ->query_name());
}

void rushit(object targ)
{
    TO->force_me("rush " + targ->query_name());
}

void sweepit(object targ)
{
    TO->force_me("sweepingblow " + targ->query_name());
}

void smiteit(object targ)
{
    TO->force_me("smite " + targ->query_name());
}

void flashit(object targ)
{
    TO->force_me("flash " + targ->query_name());
}
