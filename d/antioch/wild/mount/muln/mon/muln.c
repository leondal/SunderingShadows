//Coded by Bane//
//made the same fixes as to the other dragons so if functions are reduced
//enough to have weaponless combat kick in it won't bug.  *Styx*  4/30/02
//Switched out helm of brillance for white dragon plate because after discussion with Tsera, Circe and T it was moved to a //new area -Cythera 03/28/05
//Updated by Kassius 9/5/17
//Fuck you, Kassius.
#include <std.h>
#include <daemons.h>
#include "/d/antioch/wild/mount/muln/paths.h"
inherit WEAPONLESS;

int done, storm, heal, weapon, i;
object* others;


void create()
{
    object obj;
    int i;

    ::create();
    set_id(({ "dragon", "white", "white dragon", "wyrm", "great wyrm", "muln", "anicent wyrm", "ancient dragon" }));
    set_name("dragon");
    set_short("%^BOLD%^%^WHITE%^An a%^CYAN%^n%^WHITE%^c%^CYAN%^i%^WHITE%^e%^CYAN%^n%^WHITE%^t w%^CYAN%^h%^WHITE%^i%^CYAN%^t%^WHITE%^e d%^CYAN%^r%^WHITE%^a%^CYAN%^g%^WHITE%^o%^CYAN%^n%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This %^CYAN%^a%^WHITE%^n%^CYAN%^c%^WHITE%^i%^CYAN%^e%^WHITE%^n%^CYAN%^t %^WHITE%^w%^CYAN%^h%^WHITE%^i%^CYAN%^t%^WHITE%^e %^CYAN%^d%^WHITE%^r%^CYAN%^a%^WHITE%^g%^CYAN%^o" +
             "%^WHITE%^n is roughly sixty-five feet long, and with a %^RESET%^%^CYAN%^wingspan %^BOLD%^%^WHITE%^easily twice that. She must be the %^BLUE%^legendary %^WHITE%^white dragon known as %^CYAN%^" +
             "-Muln%^CYAN%^-%^WHITE%^. Her long, %^CYAN%^sl%^RESET%^%^CYAN%^en%^BOLD%^%^WHITE%^d%^CYAN%^er %^WHITE%^neck blends seamlessly into her head, and her %^CYAN%^thin eyelids %^WHITE%^likely aid her in preventing" +
             " %^CYAN%^s%^WHITE%^n%^CYAN%^o%^WHITE%^w %^CYAN%^b%^WHITE%^l%^CYAN%^i%^WHITE%^n%^CYAN%^d%^WHITE%^n%^CYAN%^e%^WHITE%^ss when viewing %^CYAN%^a%^WHITE%^r%^CYAN%^c%^WHITE%^ti%^CYAN%^c %^WHITE%^landscapes." +
             " A %^RESET%^%^BLUE%^dewlap %^BOLD%^%^WHITE%^covered in r%^BLUE%^a%^WHITE%^z%^BLUE%^o%^WHITE%^r-s%^CYAN%^h%^WHITE%^a%^CYAN%^r%^WHITE%^p spines rests comfortably under her chin, nearly %^RESET%^%^CYAN%^" +
             "concealed %^BOLD%^%^WHITE%^by the %^BLUE%^c%^CYAN%^o%^BLUE%^ld v%^CYAN%^a%^BLUE%^p%^CYAN%^o%^BLUE%^r %^WHITE%^spewing forth from her nostrils. Her wings are %^BLACK%^f%^CYAN%^r%^BLACK%^a%^CYAN%^y%^BLACK" +
             "%^e%^CYAN%^d %^WHITE%^slightly along the e%^CYAN%^d%^WHITE%^g%^CYAN%^e%^WHITE%^s, adding to her %^BLUE%^terrifying appearance%^WHITE%^. This %^BLACK%^macabre %^WHITE%^feature does little to hinder her" +
             " %^RESET%^%^CYAN%^movement %^BOLD%^%^WHITE%^or %^CYAN%^flight %^WHITE%^at all. Her thick %^RESET%^%^CYAN%^scales%^BOLD%^%^WHITE%^, some white and mi%^CYAN%^rr%^WHITE%^or-like, others %^BLACK%^gr%^RESET%^" +
             "%^CYAN%^a%^BOLD%^%^BLACK%^y %^WHITE%^or i%^CYAN%^c%^WHITE%^y b%^CYAN%^l%^WHITE%^ue, have aged over the centuries of her life. Her long, %^BLACK%^b%^BLUE%^a%^BLACK%^r%^BLUE%^b%^BLACK%^e%^BLUE%^d %^BLACK%^t" +
             "%^BLUE%^a%^BLACK%^l%^BLUE%^o%^BLACK%^n%^BLUE%^s %^WHITE%^extend from toes that are separated proportionally to ensure the %^CYAN%^quick %^WHITE%^and %^BLUE%^brutal savagery %^WHITE%^needed in %^CYAN%^i" +
             "%^WHITE%^c%^CYAN%^y conditions%^WHITE%^. Her tail is long, composing a good deal of half her length, encased in what is best described as %^RESET%^%^CYAN%^blades %^BOLD%^%^WHITE%^of %^CYAN%^ice%^WHITE%^" +
             ", meant to create as many %^CYAN%^agonizing cuts %^WHITE%^and %^BLACK%^punctures %^WHITE%^as possible. A light, %^CYAN%^cr%^WHITE%^i%^CYAN%^sp %^WHITE%^chemical odor wafts from the v%^CYAN%^a%^WHITE%^p%^CYAN" +
             "%^o%^WHITE%^r that pours from her nostrils, filling the a%^CYAN%^i%^WHITE%^r with a thin, fr%^CYAN%^ee%^WHITE%^zing m%^CYAN%^i%^WHITE%^st. Her %^BLUE%^i%^CYAN%^c%^BLUE%^y b%^WHITE%^l%^BLUE%^ue %^WHITE%^eyes" +
             " %^CYAN%^shine%^WHITE%^ through the mi%^CYAN%^s%^WHITE%^t with an %^CYAN%^intelligence %^WHITE%^and %^RESET%^%^CYAN%^wisdom %^BOLD%^%^WHITE%^not found in most %^RESET%^%^BLUE%^feral beasts%^BOLD%^%^WHITE%^," +
             " but that doesn't stop her from %^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^t%^RESET%^%^CYAN%^r%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^k%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^g at you with a %^CYAN%^malice" +
             " %^WHITE%^and %^BLUE%^hatred %^WHITE%^built over centuries of %^CYAN%^battles%^WHITE%^.%^RESET%^");
    set_race("dragon");
    set_body_type("dragon");
    set_gender("female");
    set_alignment(8);
    set_size(4);
    add_money("gold", 50000);
    add_money("platinum", 10000);
    set_class("fighter");
    set_class("mage");
    set_class("cleric");
    set_guild_level("fighter", 44);
    set_guild_level("mage", 44);
    set_guild_level("cleric", 44);
    set_mlevel("fighter", 44);
    set_mlevel("mage", 44);
    set_mlevel("cleric", 44);
    set_hd(44, 10);
    set_hp(3500);
    set_max_hp(query_hp());
    set("aggressive", 1);
    set_property("weapon resistance", 4);
    set_property("spell penetration", 100);
    set_resistance_percent("cold resistance", 200);
    set_resistance_percent("magic resistance", 40);
    set_resistance_percent("damage resistance", 5);
    set_property("no dominate", 1);
    set_property("no stab", 1);
    set_property("no death", 1);
    set_property("swarm", 1);
    set_property("no tripped", 1);
    set_property("no bows", 1);
    set_property("no steal", 1);
    set_property("cast and attack", 1);
    set_property("full attacks", 1);
    set_property("magic", 10);
    set_property("spell penetration", 125);
    set_stats("strength", 28);
    set_stats("dexterity", 26);
    set_stats("intelligence", 24);
    set_stats("wisdom", 28);
    set_stats("charisma", 28);
    set_stats("constitution", 28);
    set_new_exp(44, "boss");
    set_max_level(44);
    set_overall_ac(-30);
    set_spells(({
        "cone of cold",
        "hypothermia",
        "ice shield",
        "frost breath",
        "ice storm",
        "frost orb",
        "animus blizzard",
    }));
    set_monster_feats(({
        "spell focus",
        "spell penetration",
        "perfect caster",
        "greater spell penetration",
    }));

    add_limb("mouth", "head", 0, 0, 0);
    set_attack_limbs(({ "right foreclaw", "left foreclaw", "tail", "mouth" }));
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_damage(2, 12);
    set_funcs(({ "breath" }));
    set_func_chance(70);
    set_spell_chance(90);
    for (i = 0; i < random(3); i++) {
        obj = new("/std/obj/metal");
        obj->set_metal_quality(10);
        obj->move(TO);
    }

    weapon = 0;
}

int query_paralyzed()
{
    return 0;
};
int query_tripped()
{
    return 0;
};


int kill_ob(object victim, int which)
{
    int hold;
    hold = ::kill_ob(victim, which);
    if (hold) {
        if (storm < 1) {
            new("/cmds/spells/i/_ice_storm")->use_spell(TO, TO, 50, 100);
            storm = 1;
        }
    }
}

void breath(object targ)
{
    others = all_living(ETO);
    weapon++;
    for (i = 0; i < sizeof(others); i++) {
        others[i]->remove_property("hit");
    }
    if (weapon < 10) {
        set_func_chance(60);
    } else {
        set_func_chance(0);
    }
    tell_room(ETO, "%^BOLD%^%^CYAN%^The dragon breathes a cone of frost everywhere!%^RESET%^");
    if (targ->reflex_save(29)) {
        tell_object(targ, "%^BOLD%^%^CYAN%^The frost %^BOLD%^%^BLACK%^burns%^BOLD%^%^CYAN%^ into you like %^RED%^fire!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^CYAN%^The frost engulfs " + targ->query_cap_name() + " completely!%^RESET%^", targ);
        set_property("magic", 1);
        targ->cause_typed_damage(targ, 0, roll_dice(4, 12), "cold");
        remove_property("magic");
        targ->set_property("hit", 1);
        return 1;
    }
    tell_object(targ, "%^BOLD%^%^CYAN%^You dive out of the way and only get slightly frozen!%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^CYAN%^" + targ->query_cap_name() + " dives out of the way and only gets slightly frozen!%^RESET%^", targ);
    set_property("magic", 1);
    targ->cause_typed_damage(targ, 0, roll_dice(4, 12) / 2, "cold");
    remove_property("magic");
    targ->set_property("hit", 1);
    return 1;
}

void heart_beat()
{
    if (!objectp(TO)) {
        return;
    }
    ::heart_beat();

    if (!objectp(TO)) {
        return;
    }

    if (TO->query_hp() < 1000) {
        if (!heal) {
            new("/cmds/spells/h/_heal")->use_spell(TO, TO, 40, 100);
            heal = 1;
        }
    }
    if (TO->query_hp() < TO->query_max_hp()) {
        TO->add_hp(10);
    }
    if (!sizeof(TO->query_attackers())) {
        set_func_chance(102);
        storm = 0;
        weapon = 0;
        heal = 0;
    }
}

void check_me()
{
    done = 0;
}

void reset()
{
    ::reset();
    set_func_chance(102);
    heal = 0;
    weapon = 0;
    storm = 0;
}

void die(object ob)
{
    string* dropitems;
    string item;

    dropitems = get_dir(MULNZONE + "obj/");

    foreach(item in dropitems)
    if (!random(5)) {
        new(MULNZONE + "obj/" + item)->move(ETO);
    }
    ::die(ob);
}
