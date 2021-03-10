//minor fix by Circe 7/28/19 - fixing "choosen" typo
#include <daemons.h>
#include <living.h>
#include <security.h>
#include <std.h>
#include <dirs.h>
#include <new_exp_table.h>

#define MY_SKILLS ({ "academics", "alchemy", "athletics", \
                     "craft, armorsmith", "craft, jeweller", \
                     "craft, leatherworker", "craft, weaponsmith", \
                     "craft, woodworker", "craft, tailor", \
                     "disguise", "dungeoneering", "endurance", "healing", \
                     "influence", "perception", "rope use", "stealth", \
                     "spellcraft", "survival", "thievery"\
                 })


int get_level_block(int num)
{
    int result;

    switch (num) {
    case 0..10:     result = num;       break;
    case 11..20:    result = num - 10;  break;
    case 21..30:    result = num - 20;  break;
    case 31..40:    result = num - 30;  break;
    case 41..50:    result = num - 40;  break;
    case 51..60:    result = num - 50;  break;
    case 61..70:    result = num - 60;  break;
    case 71..80:    result = num - 70;  break;
    case 81..90:    result = num - 80;  break;
    case 91..100:   result = num - 90;  break;
    }
    return result;
}

int get_exp_cost(object obj, int num)
{
    int level, cost, extra;

    string race, subrace, file;

    if (!objectp(obj)) {
        return 0;
    }
    if (obj->query_property("free_abandon")) {
        return 0;
    }

    race = (string)obj->query_race();
    subrace = (string)obj->query("subrace");
    file = "/std/races/" + race + ".c";

    level = (int)obj->query_adjusted_character_level();
    if (level > CHARACTER_LEVEL_CAP) {
        level = CHARACTER_LEVEL_CAP;
    }
    extra = (int)obj->query_exp() - total_exp_for_level(level);

    cost = total_exp_for_level(level) - total_exp_for_level(level - (num));
    cost = cost + extra;
    return cost;
}

int confirm_drop(string str, string theclass, int drop, int cost)
{
    string* classes, * skills, * imms;
    object class_ob;
    int i, feats, tmp;

    if (!objectp(TP)) {
        return 0;
    }
    if (str != "yes") {
        tell_object(TP, "%^BOLD%^Aborting...%^RESET%^");
        return 1;
    }

    TP->remove_property("free_abandon");

    class_ob = find_object_or_load(DIR_CLASSES + "/" + theclass + ".c");
    if (objectp(class_ob) && TP->query_class_level("theclass") < 11) {
        class_ob->remove_base_class(TP);
    }

    //tell_object(TP, "cost = "+cost);
    TP->set("active_class", theclass);
    tell_object(TP, "%^BOLD%^Subtracting exp...%^RESET%^");
    TP->add_exp(-cost);
    TP->remove_XP_tax("all");
    tell_object(TP, "%^BOLD%^Reducing level...%^RESET%^");
    TP->resetLevelForExp(0);
    tell_object(TP, "%^BOLD%^Resetting class combat spec...%^RESET%^");
    TP->set_combat_spec(theclass, "");
    skills = MY_SKILLS;

    tell_object(TP, "%^BOLD%^Clearing skills...%^RESET%^");
    if (sizeof(skills)) {
        for (i = 0; i < sizeof(skills); i++) {
            TP->set_skill(skills[i], 0);
        }
    }

    tell_object(TP, "%^BOLD%^Adding up feats...%^RESET%^");
    feats = (int)TP->query_other_feats_gained();
    feats += (int)TP->query("free_feats");
    TP->clear_feats();
    tell_object(TP, "%^BOLD%^Adding free feats...%^RESET%^");
    TP->set("free_feats", feats);
    tell_object(TP, "%^BOLD%^Clearing old feats...%^RESET%^");
    TP->delete("free_feat_wipe");
    TP->delete("is_auto_detecting_traps");
    TP->delete("skill_focus");

    if (TP->is_class("warlock")) {
        TP->delete("warlock_blast_type");
    }


    // this should only get called if they have no levels in the class that they abandoned, to remove it from the score sheet
    if (((int)TP->query_class_level(theclass) == 1 || (int)TP->query_class_level(theclass) == 0) && sizeof(TP->query_classes()) > 1) {
        tell_object(TP, "%^BOLD%^Removing class %^MAGENTA%^" + theclass + "%^RESET%^%^BOLD%^...%^RESET%^");
        TP->set_guild_level(theclass, 0);
        TP->set_mlevel(theclass, 0);
        TP->remove_class(theclass);
    }

// moved all of the next section out of the above subquery; N, 6/16
// these should be run regardless of 1/0 level in the abandoned class
// allows players to reset certain attributes, and mastered spells should be cleared by default
    if (sizeof(TP->query_mastered_spells())) {
        tell_object(TP, "%^BOLD%^Clearing mastered spells... please reassign your spell slots if you still have class levels.");
        if (!(theclass == "mage" && theclass == "magus")) {
            TP->reset_mastered();
        }
    }
    if (theclass == "mage") {
        tell_object(TP, "%^BOLD%^Clearing mage school... if you still have class levels you may reassign this with <help advance>.");
        TP->set_school(0);
    }
    if (theclass == "psion") {
        tell_object(TP, "%^BOLD%^Clearing psion discipline... if you still have class levels you may reassign this with <help advance>.");
        TP->set_discipline(0);
    }
    if (theclass == "warlock") {
        tell_object(TP, "%^BOLD%^Clearing warlock heritage... if you still have class levels you may reassign this with <help advance>.");
        TP->delete("warlock heritage");
    }
    if (theclass == "fighter") {
        tell_object(TP, "%^BOLD%^Clearing fighting style... if you still have class levels you may reassign this with <help advance>.");
        TP->set_fighter_style(0);
    }
    if (theclass == "cleric" || theclass == "druid") {
        tell_object(TP, "%^BOLD%^Clearing domains... you may reassign these at a church/temple if you still have class levels.");
        TP->set_divine_domain(({}));
    }

    tell_object(TP, "%^BOLD%^Rebuilding class feats...%^RESET%^");
    classes = (string*)TP->query_classes();
    for (i = 0; i < sizeof(classes); i++) {
        tmp = (int)TP->query_class_level(classes[i]);
        TP->set_mlevel(classes[i], 1);
        "/cmds/mortal/_advance.c"->add_class_feats(TP, classes[i]);
        TP->set_mlevel(classes[i], tmp);
        TP->set_guild_level(classes[i], tmp);
        TP->set("active_class", classes[i]);
        TP->set_posed(classes[i]);
    }
    if (theclass == "monk") {
        tell_object(TP, "%^BOLD%^Resetting your monk way and ki spells. You may reassign these at a church/temple if you still have class levels.");
        TP->delete("monk way");
        TP->delete("ki spells");
        USER_D->init_pool(TP, "ki");
    }
    if (theclass == "magus") {
        USER_D->init_pool(TP, "arcana");
    }
    if (theclass == "paladin") {
        USER_D->init_pool(TP, "grace");
    }
    TP->force_me("fixspells");
    TP->set("hp_array", 0);
    TP->make_new_hitpoint_rolls(TP);
//Below should clear spells given by Shadowdancer prestige class ~Circe~ 7/30/19
    TP->InitInnate();
    tell_object(TP, "%^YELLOW%^Finished... You dropped %^BLUE%^" + drop + " %^YELLOW%^levels from "
                "your %^BLUE%^" + theclass + "%^YELLOW%^ class and were charged %^BLUE%^" + cost + " %^YELLOW%^experience "
                "points.");
    tell_object(TP, "\n%^BOLD%^%^WHITE%^N.B.%^RESET%^ You will have to reassign all of your feats. You will be allowed to assign up to the same amount of feats that you previously bought without any exp cost. You will also have to re-apply your skill points.%^RESET%^");
    return 1;
}

int cmd_abandon(string str)
{
    string* classes, myrace, mysubrace, file;
    int class_level, cost, drop, i;
    object class_ob;

    if (!objectp(TP)) {
        return 0;
    }
    if (!stringp(str) || str == "" || str == " ") {
        tell_object(TP, "%^BOLD%^You must enter a class that you want to abandon.%^RESET%^");
        return 1;
    }

    classes = (string*)TP->query_classes();
    if (!sizeof(classes)) {
        tell_object(TP, "%^BOLD%^You don't have a class yet, try this later.%^RESET%^");
        return 1;
    }

    myrace = TP->query_race();
    mysubrace = TP->query("subrace");
    file = "/std/races/" + myrace + ".c";

    for (i = 0; i < sizeof(classes); i++) {
        class_ob = find_object_or_load(DIR_CLASSES + "/" + classes[i] + ".c");
        if (!objectp(class_ob)) {
            tell_object(TP, "There's something wrong with one of your classes, please contact a wiz and try again later.");
            return 1;
        }

        if (class_ob->is_prestige_class() &&
            str != classes[i] &&
            member_array(str, class_ob->query_base_classes()) != -1 &&
            TP->query_class_level(str) > 20 ) {
            tell_object(TP, "You must abandon your prestige class before abandoning more than twenty base class levels.");
            return 1;
        }
    }


    if ((int)TP->query_base_character_level() < (11) ) {
        tell_object(TP, "%^BOLD%^You only have one class, you can't drop your only class.%^RESET%^");
        return 1;
    }
    str = lower_case(str);
    str = replace_string(str, " ", "_");

    if (TP->query("negative level")) {
        tell_object(TP, "%^BOLD%^%^RED%^You have incurred a negative level and must remove it " +
                    "before you are able to abandon.");
        return 1;
    }

    if (intp(USER_D->get_scaled_level(TP))) {
        tell_object(TP, "%^BOLD%^%^RED%^You have scaled your level down and cannot abandon " +
                    "until your level is reset to normal.%^RESET%^");
        return 1;
    }
    if (member_array(str, classes) == -1) {
        tell_object(TP, "%^YELLOW%^You are not a %^BLUE%^" + str + "%^YELLOW%^.  You must enter one of your "
                    "classes in order to remove it.%^RESET%^");
        return 1;
    }

    drop = get_level_block((int)TP->query_base_class_level(str));
    cost = get_exp_cost(TP, drop);

    if ((int)TP->query_base_class_level(str) > (10)) {
        tell_object(TP, "\nAre you sure you want to drop %^BOLD%^%^" + drop + " %^RESET%^"
                    "levels in your %^BOLD%^" + str + "%^RESET%^ class? This will cost you %^BOLD%^" + cost + " "
                    "%^RESET%^ experience points. Enter %^BOLD%^yes%^RESET%^ to confirm, "
                    "anything else to abort.%^RESET%^");
    }else {
        tell_object(TP, "%^RESET%^Are you sure you want to drop your %^BOLD%^" + str + "%^RESET%^ class? "
                    "%^RESET%^This will cost you %^BOLD%^" + cost + "%^RESET%^ experience points. Enter "
                    "%^BOLD%^yes %^RESET%^to confirm, anything else to abort.%^RESET%^");
    }

    input_to("confirm_drop", str, drop, cost);
    return 1;
}

int help()
{
    write("
%^CYAN%^NAME%^RESET%^

abandon - remove levels in your class

%^CYAN%^SYNOPSIS%^RESET%^

abandon %^ORANGE%^%^ULINE%^CLASS%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will allow a player to abandon a class completely or allow them to abandon enough levels in the class to drop them back down to the nearest multiclass level block. A player must be level 11 or higher in order to be able to use this command. It will drop a level 11-20 player down to level 10, a 21-30 player to level 20, and a 31-40 level player to level 30.

All of your feats and skills will be reset when you abandon a class, but you will be allowed to pick an amount of free feats that are equal to the amount of feats you previously had. You can't spend more free feats than you are allowed at your current level, but they will remain until you have gained enough levels to use them later, even if you abandon more levels or classes before that time.

All of your stats will be preserved. You need to use %^ORANGE%^<stats>%^RESET%^ command to move them around.

You will also have your experience tax reduced by half of the lost exp.

%^CYAN%^SEE ALSO%^RESET%^

advance, score, stat
");
    return 1;
}
