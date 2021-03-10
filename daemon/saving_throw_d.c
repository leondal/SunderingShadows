#include <std.h>
#include <daemons.h>
#include <dirs.h>
inherit DAEMON;

//All saves are in the format ({ fort, reflex, will })
// Using a mapping to track the numbers all through the daemon for debug purposes.
mapping save_info=([]);

void create() { ::create(); }

varargs void do_save(object ob, int dc, string type, raw_save)
{
    int *saves,num,save,roll1,i,level,statbonus,mod;
    string *classes,file;
    object rider;

    switch (type) {
    case "fortitude": case "fort":   num = 0; save_info["save_type"] = "fort"; break;
    case "reflex": num = 1; save_info["save_type"] = "reflex"; break;
    case "will":   num = 2; save_info["save_type"] = "will"; break;
    }

    classes = ob->query_classes();
    save = 0;
    for (i = 0; i < sizeof(classes); i++) {
        file = DIR_CLASSES + "/" + classes[i] + ".c";
        if (!file_exists(file)) {
            continue;
        }

        level = ob->query_class_level(classes[i]);
        if (level > 20) {
            level = 20;
        }
        saves = file->saving_throws(ob);
        if (!sizeof(saves)) {
            continue;
        }

        // starting saving throw from class template; if 1 it is a strong throw (2+ level/2), if 0 it is weak (level/3)
        if (saves[num]) {
            save += (2 + (level / 2));
        } else {
            save += (level / 3);
        }

        // step 2: get any extra points from levels past 20, if applicable
        level = ob->query_class_level(classes[i]);

        if (!userp(ob)) {
            save += level / 2;
        } else {
            save += level > 20 ? ((level - 20) / 2) : 0;
        }
    }

    if (ob->is_undead() && num == 2) {
        save = (ob->query_level() / 2) + 2;
    }

    save_info["base_class_save"] = save;         // this is without any modifiers

    switch (type) {
    case "fort": case "fortitude":  statbonus = (int)ob->query_stats("constitution"); break;
    case "reflex": statbonus = (int)ob->query_stats("dexterity");    break;
    case "will":   statbonus = (int)ob->query_stats("wisdom");       break;
    }

    if (ob->is_undead())
        if (type == "fort" ||
            type == "fortitude") {
            statbonus = ob->query_stats("charisma");
        }

    statbonus = (statbonus - 10)/2;
    save_info["base_stat_bonus"] = statbonus;
    save += statbonus;

    {
        switch (type) {
        case "fort": case "fortitude":
            mod = (int)ob->query_saving_bonus("fortitude");
            if (ob->query_race() == "human" &&
                ob->query("subrace") == "aesatri") {
                mod += 1;
            }
            break;
        case "reflex":
            mod = (int)ob->query_saving_bonus("reflex");
            if (ob->query_race() == "human" &&
                ob->query("subrace") == "senzokuan") {
                mod += 1;
            }
            break;
        case "will":
            mod = (int)ob->query_saving_bonus("will");
            if (ob->query_race() == "human" &&
                ob->query("subrace") == "maalish") {
                mod += 1;
            }
            if(member_array("stars", ob->query_divine_domain()) >= 0)
                mod += 2;
            if(LIVING_D->check_aura(ob, "courage") == 2)
                mod += 2;
            if(LIVING_D->check_aura(ob, "resolve") == 2)
                mod += 2;
            break;
        }

        if (ob->query_race() == "halfling" &&
            ob->query("subrace") == "lightfoot halfling") {
            mod += 1;
        }

        if (ob->query_race() == "gnome" &&
            (ob->query("subrace") == "deep gnome" || ob->query("subrace") == "svirfneblin")) {
            mod += 0;                                                                                                                                                // svirfneblin +2 saves racial - changed in racial update
        }
        if (FEATS_D->usable_feat(ob, "resistance")) {
            mod += 2;
        }
        if (FEATS_D->usable_feat(ob, "force of personality")) {
            int sbonus = BONUS_D->query_stat_bonus(ob, "charisma");
            mod += sbonus > 5 ? 5 : sbonus;
        }
        if (FEATS_D->usable_feat(ob, "shadow master") && objectp(ENV(ob)) && ENV(ob)->query_light() < 2) {
            num += 2;
        }
        if(member_array("madness", ob->query_divine_domain()) >= 0)
            num -= roll_dice(1, 4);

        save_info["misc_modifiers"] = mod;
        {
            if (type == "will") {
                if (ob->is_vampire()) {
                    mod -= (20000 - (int)ob->query_bloodlust()) / 2000;
                }
            }
        }
    }

    save += mod;
    if (raw_save) {
        return save;
    }
    //tell_object(find_player("saide"), "save now = "+save+", mod = "+mod);
    if (!ob->query("new_class_type")) {    // this is just a throwback to average out mobs... we'll need something better longterm?
        if (!save || !sizeof(classes)) {
            save = 0;
        }else {
            save = save / sizeof(classes);
        }
    }

    if (ob->is_animal()) {
        rider = (object)ob->query_current_rider();
        if (objectp(rider)) {
            if (save < rider->query_skill("athletics") / 2 && FEATS_D->usable_feat(rider, "indomitable mount")) {
                save = rider->query_skill("athletics") / 2;
            }
        }
    }

    save_info["dc"] = dc;
    save_info["final_saving_throw"] = save;

    if (dc > 0) {
        dc *= -1;
    }

    roll1 = roll_dice(1, 20);

    //Touch of Law makes the roll 11
    if(ob->query_property("touch of law"))
        roll1 = 11;

    save_info["saving_throw_roll"] = roll1;
    save_info["pass_or_fail_by"] = roll1 + save + dc;

    if (roll1 == 1) {
        save_info["save_result"] = 0;
    } else if (roll1 == 20) {
        save_info["save_result"] = 1;
    } else if (roll1 + save + dc >= 0) {
        save_info["save_result"] = 1;
    } else {
        save_info["save_result"] = 0;
    }
    
    if(save_info["save_result"] == 0)
    {
        if(ob->query_class_level("cleric"))
        {
            //Fate domain has a chance to add 1d4 to save and try again
            if(member_array("fate", ob->query_divine_domain()) && !random(5))
            {
                roll1 += roll_dice(1, 4);
                if(roll1 + save + dc >= 0)
                {
                    tell_object(ob, "%^MAGENTA%^You feel the hand of fate change the outcome!%^RESET%^");
                    save_info["save_result"] = 1;
                }
            }
        }
    }       
}

int get_save(object who, string type)
{
    return do_save(who, 0, type, 1);
}

void check_save(object ob)
{
    object* weapons;
    int x;
    if (!objectp(ob)) {
        return 0;
    }
    if (save_info["save_result"] != 1) {
        if (FEATS_D->usable_feat(ob, "diamond soul")) {
            weapons = ob->query_wielded();
            for (x = 0; x < sizeof(weapons); x++) {
                if (!objectp(weapons[0])) {
                    continue;
                }
                if ((int)weapons[0]->query_size() > 1) {
                    return 0;
                }
                continue;
            }
            if (!ob->is_ok_armour("barb")) {
                return 0;
            }
            if (ob->spend_ki(1)) {
                return 1;
            }
        }
    }
    return 0;
}

int fort_save(object ob, int dc)
{
    do_save(ob, dc, "fort");
    if (check_save(ob)) {
        do_save(ob, dc, "fort");
    }
    return save_info["save_result"];
}

mapping debug_fort_save(object ob, int dc)
{
    do_save(ob, dc, "fort");
    return save_info;
}

int reflex_save(object ob, int dc)
{
    do_save(ob, dc, "reflex");
    if (check_save(ob)) {
        do_save(ob, dc, "reflex");
    }
    return save_info["save_result"];
}

mapping debug_reflex_save(object ob, int dc)
{
    do_save(ob, dc, "reflex");
    return save_info;
}

int will_save(object ob, int dc)
{
    do_save(ob, dc, "will");
    if (check_save(ob)) {
        do_save(ob, dc, "will");
    }
    return save_info["save_result"];
}

mapping debug_will_save(object ob, int dc)
{
    do_save(ob, dc, "will");
    return save_info;
}

int magic_save_throw_adjust(object targ, object caster)
{
    int caster_bonus = 0;

    if (targ->query_race() == "dwarf") {
        if (targ->query("subrace") == "shield dwarf" || targ->query("subrace") == "gold dwarf") {
            caster_bonus -= 2;
        }
    }
    if (targ->query_race() == "orc" || targ->query_race() == "half-orc") {
        caster_bonus -= 1;
    }
    if (targ->query_race() == "human") {
        if (targ->query("subrace") == "heartlander") {
            caster_bonus -= 1;
        }
    }


    if (arrayp(targ->query_property("protection_from_alignment"))) {
        if (member_array(caster->query_alignment(), targ->query_property("protection_from_alignment")) != -1) {
            caster_bonus -= 2;
        }
    }

    if (FEATS_D->usable_feat(targ, "disruptive")) {
        caster_bonus -= 4;
    }

    if (FEATS_D->usable_feat(targ, "closed mind")) {
        caster_bonus -= 2;
    }

    return caster_bonus;
}
