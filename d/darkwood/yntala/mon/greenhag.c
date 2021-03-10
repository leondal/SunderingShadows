#include <std.h>
#include "/realms/tsera/yntala_forest/yntala.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("Green Hag");
    set_id(({ "Green Hag", "green hag", "hag" }));
    set_short("%^RESET%^%^GREEN%^An %^BOLD%^%^BLACK%^ugly %^RESET%^%^GREEN%^green %^RESET%^%^ORANGE%^hag%^RESET%^");
    set_long("%^RESET%^%^GREEN%^This ugly creature's sickly green"
             " colored skin hangs off of her bony frame.  Her eyes are a dull"
             " %^YELLOW%^yellow %^RESET%^%^GREEN%^in color and her %^BOLD%^"
             "%^BLACK%^greasy %^RESET%^%^GREEN%^hair falls down around her"
             " shoulders in a tangled mess of leaves and vines.  Her humanoid"
             " figure is constantly hunched over, and she keeps her clawed"
             " hands clasped near her chest.%^RESET%^");
    set_race("hag");
    set_gender("female");
    set_body_type("human");
    set_hd(12, 1);
    set_overall_ac(2);
    set_size(2);
    set_stats("intelligence", 16);
    set_stats("strength", 19);
    set_stats("wisdom", 13);
    set_stats("dexterity", 12);
    set_stats("constitution", 12);
    set_stats("charisma", 14);
    set_money("gold", random(500));
    set_money("silver", random(1000));
    set_money("copper", random(200));
    set_money("electrum", random(200));
    set_class("thief");
    set_hp(random(250) + 75);
    set_max_hp(query_hp());
    set_exp(2600);
    set_max_level(13);
    set_alignment(9);
    set_damage(1, 6);
    set_property("full attacks", 1);
    set("aggressive", "aggfunc");
    set_mlevel("thief", 12);
    set_guild_level("thief", 12);
    set_moving(1);
    set_scrambling(1);
    set_speed(40);
    set_nogo(({ "/d/darkwood/yntala/rooms/forestpath" }));
    add_search_path("/cmds/thief");
    set_skill("stealth", 6); //standard for a level 12 thief
    add_limb("claws", "left arm", 0, 0, 0);
    set_attack_limbs(({ "claws" }));
    set_base_damage_type("slashing");
    set_achats(2, ({ "%^YELLOW%^The ugly little hag cackles demonically%^RESET%^", "%^GREEN%^The hag cackles wildly as she slashes at you with her %^RESET%^claws." }));
    RANDGEAR->armor_me(TO, "armorlt", 70, 1, 0);
    set_monster_feats(({
        "dodge",
        "mobility",
        "evasion",
        "combat reflexes"
    }));
}

int aggfunc()
{
    force_me("speech say in a shrill voice");
    force_me("say Kill them! Kill them all!");
    force_me("stab " + TPQN);
    if (TO->query_invis()) {
        TO->set_hidden(0);
    }
    //command("scramble");
}

//This is the heart_beat function - it, like init, and create has to have a
//::heart_beat() - to inherit the heart_beat stuff in the files above this one
void heart_beat()
{
    ::heart_beat();
    //this is to make sure it doesn't do anything if the heart_beat happens once it's
    //dead - it has to be a living, valid, object to perform the actions
    if (!objectp(TO)) {
        return;
    }
    //this checks and sees if the object is NOT invisible and has no attackers
    if (!TO->query_invis() && sizeof(TO->query_attackers()) == 0) {
        //using this and just reversing it in combat - because hide_in_shadows seems to be
        //toast for mobs
        TO->set_hidden(1);
        return;
    }
    //doing this so if someone attacks it then it'll appear the next heart_beat - if it's
    //invis
    if (TO->query_invis() && sizeof(TO->query_attackers()) > 0) {
        TO->set_hidden(0);
        return;
    }
}
