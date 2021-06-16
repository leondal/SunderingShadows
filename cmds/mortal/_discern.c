#include <std.h>
#include <daemons.h>

private string size2str(int x)
{
    switch (x) {
    case 1:
        return "small"; break;

    case 2:
        return "medium"; break;

    case 3:
        return "large"; break;

    case 4:
        return "giant"; break;
    }
}

private string checkhands(int x, int y)
{
    if (x > y + 1) {
        return "is %^BOLD%^%^BLUE%^too large%^RESET%^ for you to wield";
    }
    if (x <= y) {
        return "will take you %^BOLD%^%^BLUE%^one hand%^RESET%^ to wield it";
    }
    if (x > y) {
        return "will take you %^BOLD%^%^BLUE%^two hands%^RESET%^ to wield it";
    }
}

private string checkrepair(string mytype, string* repairtype)
{
    string feedback;
    int i;
    if (!sizeof(repairtype)) {
        switch (mytype) {
        case "clothing": return "tailor"; break;

        case "bracer":
        case "ring": return "jeweller"; break;

        case "chain":
        case "armour":
        case "shield":
        case "armor":
        case "plate": return "armorsmith"; break;

        case "leather":
        case "thiefshield": return "leatherworker"; break;

        case "wood": return "woodworker"; break;

        default: return "invalid"; break;
        }
    }
    switch (repairtype[0]) {
    case "jewel": feedback = "jeweller"; break;

    case "armorsmith": feedback = "armorsmith"; break;

    case "tailor": feedback = "tailor"; break;

    case "woodwork": feedback = "woodworker"; break;

    case "leatherwork": feedback = "leatherworker"; break;

    case "weaponsmith": feedback = "weaponsmith"; break;

    default: feedback = "invalid"; break;
    }
    if (sizeof(repairtype) > 1) {
        for (i = 1; i < sizeof(repairtype); i++) {
            feedback += "%^RESET%^ or %^GREEN%^";
            switch (repairtype[i]) {
            case "jewel": feedback += "jeweller"; break;

            case "armorsmith": feedback += "armorsmith"; break;

            case "tailor": feedback += "tailor"; break;

            case "woodwork": feedback += "woodworker"; break;

            case "leatherwork": feedback += "leatherworker"; break;

            case "weaponsmith": feedback = "weaponsmith"; break;

            default: feedback += "invalid"; break;
            }
        }
    }
    return feedback;
}

int cmd_discern(string str)
{
    object obj;

    if (!str) {
        notify_fail("Discern what?\n");
        return 0;
    }
    if (!obj = present(str, TP)) {
        notify_fail("You don't have that!\n");
        return 0;
    }
    {
        string* names;
        names = obj->query_id();
        if (names) {
            write("%^BOLD%^This item can be refered to as:%^RESET%^ " + implode(names, ", "));
        }
    }
    {
        int weight;
        weight = (int)obj->query_weight();
        if (weight) {
            write("It weighs %^ORANGE%^" + weight + " lb%^RESET%^.");
        }
    }
    if (obj->is_weapon()) {
        int num, dice, lnum, ldice;
        int wear;
        int range, multiplier;
        string damtype;

        num = obj->query_wc_num();
        dice = obj->query_wc_dice();
        damtype = obj->query_damage_type();

        wear = (int)obj->query_overallStatus();

        if (wear > 100) {
            wear = 100;
        }

        dice = to_int(0.5 + (dice * wear / 100.0));
        if (dice < 1) {
            dice = 1;
        }

        //lnum = obj->query_large_wc_num();
        //ldice = obj->query_large_wc_dice();
        //ldice = to_int(0.5 + (ldice * wear / 100.0));
        if (ldice < 1) {
            ldice = 1;
        }

        range = obj->query_critical_threat_range();
        multiplier = obj->query_critical_hit_multiplier();
        range = 20 - (range - 1);

        write("%^WHITE%^It does %^BOLD%^%^GREEN%^" + damtype + " %^RESET%^damage.");
        write("%^WHITE%^It deals %^BOLD%^%^GREEN%^" + num + "-" + num * dice + " (" + num + "d" + dice + ")%^RESET%^ damage.");
        //write("%^WHITE%^It deals %^BOLD%^%^GREEN%^" + lnum + "-" + lnum * ldice + " (" + lnum + "d" + ldice + ")%^RESET%^ damage to large creatures.");
        write("%^WHITE%^It scores critical hit on a roll of %^BOLD%^%^ORANGE%^" + range + "-20%^RESET%^.");
        write("%^WHITE%^It has critical damage multiplier of %^BOLD%^%^ORANGE%^" + multiplier + "%^RESET%^.");
        if ((int)"/daemon/config_d.c"->check_config("critical damage") == 0) {
            write("%^WHITE%^It deals %^GREEN%^" + multiplier + "%^GREEN%^ times normal damage on a crit.");
        }
        if ((int)"/daemon/config_d.c"->check_config("critical damage") == 1) {
            multiplier--;
            write("%^WHITE%^It deals %^BOLD%^%^GREEN%^" + num * multiplier + "-" + num * dice * multiplier + " (" + num * multiplier + "d" + dice + ")%^RESET%^ additional damage on a crit.");
            //write("%^WHITE%^It deals %^BOLD%^%^GREEN%^" + lnum * multiplier + "-" + num * dice * multiplier + " (" + lnum * multiplier + "d" + ldice + ")%^RESET%^ additional damage on a crit to large creatures%^");
        }
        if (obj->query("PoisonDoses")) {
            write("It has %^BOLD%^%^GREEN%^" + obj->query("PoisonDoses") + "%^RESET%^ layers of poison oil.");
            {
                string poison;
                poison = "/d/common/obj/poisons/base/" + replace_string(obj->query("PoisonType"), " ", "_");
                if (file_exists(poison + ".c")) {
                    if (TP->query_skill("survival") > poison->query_poison_dc() * 5 / 4) {
                        write("You sense it is a %^BOLD%^%^GREEN%^" + obj->query("PoisonType") + "%^RESET%^ poison.");
                    } else {
                        write("You don't know what kind of poison it is.");
                    }
                } else {
                    write("You don't know what kind of poison it is.");
                }
            }
        }
        if (obj->query_property("finesse")) {
            write("%^BOLD%^%^ORANGE%^Weapon finesse%^RESET%^ can be used with it.");
        }
        if (obj->query_property("double weapon")) {
            write("%^WHITE%^It is a %^BOLD%^%^ORANGE%^double weapon%^RESET%^.");
        }
        write("");
        if (!obj->query_weapon_prof()) {
            write("%^WHITE%^It has %^BOLD%^%^GREEN%^no proficiency set.%^RESET%^");
            return 1;
        }
        write("%^WHITE%^It %^BOLD%^%^RED%^requires %^GREEN%^" + obj->query_weapon_prof() + "%^RESET%^%^ proficiency to be used successfully.");
        write("It is a %^BOLD%^%^RED%^" + size2str((int)obj->query_size()) + "%^RESET%^%^ sized weapon.");
        write("It " + checkhands((int)obj->query_size(), (int)TP->query_size()) + ".");
        if (obj->is_lrweapon()) {
            string ammotype, * bowids;

            ammotype = obj->query_ammo();
            bowids = obj->query_id();
            if (sizeof(bowids)) {
                if (member_array(ammotype, bowids) != -1) {
                    write("%^WHITE%^It uses %^BOLD%^%^GREEN%^no ammunition%^RESET%^.");
                }else {
                    write("%^WHITE%^It uses %^BOLD%^%^GREEN%^" + (string)obj->query_ammo() + "%^RESET%^%^ as ammunition.");
                }
            }
        }
        write("It requires %^BOLD%^%^ORANGE%^" + checkrepair((string)obj->query_type(), (string*)obj->query_property("repairtype")) + " %^RESET%^craft skill to repair.");
        return 1;
    }
    if (obj->is_armor()) {
        int armbon;
        if (obj->query_armor_prof() == "shield") {
            armbon = obj->query_item_bonus("shieldMiss");
            write("It has %^BOLD%^%^GREEN%^" + armbon + "%^RESET%^ deflection chance.");
            write("");
            write("It %^RED%^requires %^BOLD%^%^GREEN%^shield%^RESET%^ profficiency to wield successfully.");
            write("It requires %^BOLD%^%^GREEN%^" + checkrepair((string)obj->query_type(), (string*)obj->query_property("repairtype")) + " %^RESET%^craft skill to repair.");
        }else {
            armbon = obj->query_original_ac();
            write("It has armor bonus of %^BOLD%^%^GREEN%^" + armbon + ".%^RESET%^");
            write("");
            if (!obj->query_armor_prof()) {
                if ((string)obj->query_type() == "ring" ||
                    (string)obj->query_type() == "clothing" ||
                    (string)obj->query_type() == "bracer" ||
                    (string)obj->query_type() == "sheath") {
                    write("It requires %^BOLD%^%^ORANGE%^" + checkrepair((string)obj->query_type(), (string*)obj->query_property("repairtype")) + " %^RESET%^craft skill to repair.");
                }

                write("It requires no proficiency to wear.");
                if (sizeof(obj->query_limbs())) {
                    write("It will be worn on %^BOLD%^%^GREEN%^" + implode(obj->query_limbs(), "%^RESET%^, %^BOLD%^%^GREEN%^") + "%^RESET%^");
                }
            }else {
                write("It %^RED%^requires %^BOLD%^%^GREEN%^" + obj->query_armor_prof() + "%^RESET%^ armor proficiency to wear.");
                write("It requires %^BOLD%^%^ORANGE%^" + checkrepair((string)obj->query_type(), (string*)obj->query_property("repairtype")) + " %^RESET%^craft skill to repair this item.");
            }
        }
        return 1;
    }
    write("Not a weapon or armor.");
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

discern - lists armor and weapon properties

%^CYAN%^%^SYNOPSIS%^RESET%^

discern %^ORANGE%^%^ULINE%^ITE%^RESET%^M

%^CYAN%^%^DESCRIPTION%^RESET%^

This command will list non-magical properties of weapons and armor.

For weapons, it will give base weapon damage, not-adjusted critical damage, proficiency, size, limbs required to use it, ammunition for ranged weapons and skill required to repair it.

For armor, it will give armor bonus (armor class), proficiency and skill required to repair it.

%^CYAN%^%^SEE ALSO%^RESET%^

study, look
");
}
