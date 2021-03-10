#include <std.h>
#include "../marsh.h"

inherit WEAPONLESS;

int level;

void create()
{
    :: create();
    set_name("banshee");
    set_id(({ "banshee", "wailing banshee" }));
    set_short("%^RESET%^%^BLUE%^Wailing banshee%^RESET%^");
    set_long("A shadowy ghost-like shape which floats above the marsh. It's hollow "
             "black eyes gaze upon you as it's mouth is open letting forth an eerie wail. "
             "It's arms and legs are adorned with chains which clank and sway with it's "
             "every move.");
    set_gender("female");

    set_class("fighter");

    level = roll_dice(1, 10) + 20;

    set_hd(level, 12);
    set_level(level);
    set_guild_level("fighter", level);
    set_mlevel("fighter", level);
    set_guild_level("mage", level);
    set_mlevel("mage", level);
    set_max_level(36);
    set_property("magic", 1);
    set_size(2);
    set_base_damage_type("bludgeoning");
    add_limb("right chain", "torso", 0, 0, 0);
    add_limb("left chain", "torso", 0, 0, 0);
    set_attack_limbs(({ "right chain", "left chain" }));
    set_overall_ac(15 - level);
    set_body_type("humanoid");
    set_race("undead");
    set_alignment(6);
    set("aggressive", random(8) + 7);
    set_property("magic resistance", level);
    set_new_exp(level + 10, "high");
    set_max_hp(level * 12);
    set_hp(level * 12);
    add_money("gold", random(500) + 200);
    set_emotes(1, ({ "%^BLUE%^The banshee wails in despair!%^RESET%^",
                     "%^GREEN%^The banshee sings a song of darkness!",
                     "The banshee screams out!",
                     "%^MAGENTA%^Wailing banshee wails: %^RESET%^It lives not but lives! "
                     "Demongate tower is our shroud of doom!", }), 1);
    set_funcs(({ "absorb" }));
    set_func_chance(30);
    set_property("no death", 1);
    set_property("no paralyze", 1);
    set_property("no tripped", 1);
    set_property("cast and attack", 1);
    set_spell_chance(60);
    set_spells(({ "wail of the banshee" }));

    set_speed(50);
    set_moving(1);
    set_nogo(({ ROOMS "m44", ROOMS "m44.c" }));
    set_stats("strength", 25);
    set_stats("dexterity", 25);
    set_stats("constitution", 25);
    set_stats("intelligence", 25);
    set_stats("wisdom", 25);
    set_stats("charisma", 25);
    set_attacks_num(4);
    set_damage(1, (level / 2));
    add_attack_bonus(roll_dice(1, 6));
    add_damage_bonus(roll_dice(1, 6));
}

void absorb(object targ)
{
    int dam;
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }

    tell_room(ETO, "%^BOLD%^%^BLUE%^The banshee wails in an eerie tone "
              "towards " + targ->QCN + "!%^RESET%^", targ);

    dam = (int)targ->query_level();
    TO->add_hp(dam);

    if (!WILL(targ, -1 * (level - 10))) {
        tell_object(targ, "%^BOLD%^%^BLUE%^Your arms feel like lead and your "
                    "legs like jelly as the banshee looks at you and wails in despair!%^RESET%^");
      
        
        targ->set_paralyzed(dam / 2, "You cannot move! The despair in you is too great!");
    }else {
        tell_object(targ, "%^RESET%^%^BOLD%^You shudder but manage to shrug off the "
                    "horrible wail of the banshee!%^RESET%^");
    
    }
    targ->cause_typed_damage(targ, "torso",dam,"sonic");
  
}
