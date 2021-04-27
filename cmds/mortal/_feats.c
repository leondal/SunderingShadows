/**
 * @file
 * @brief feats command
 */

/*
 * Some of functions in this file have an external use.
 */

#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <new_exp_table.h>
#include <schoolspells.h>
#include <feats.h>
#include <skills.h>
#include <class_types.h>

inherit DAEMON;

int help(string str);

int free;

int calculate_feat_cost(object ob)
{
    int level, exp;
    if (!objectp(ob)) {
        return 0;
    }

    if (free) {
        return 0;
    }

    if (ob->query("free_feats")) {
        return 0;
    }
    level = ob->query_highest_level();
    if (level == 1) {
        return 0;
    }
    if (!avatarp(ob)) {
        exp = exp_for_level(level) * 3 / 4;
        return exp;
    }
    return 0;
}

int remove_spell_mastery_spell(string str, object ob, string feat, string mytype)
{
    int num, level, okclasslvl, i, amt;
    object spell;
    string file, * okclasses, * myclasses, tmp;

    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }
    if (!stringp(str)) {
        return 0;
    }

    okclasses = ({});
    myclasses = ob->query_classes();
    if (!sizeof(myclasses)) {
        tell_object(ob, "Your classes are broken! Contact a wiz!");
        free = 0;
        return 1;
    }

    tmp = "/cmds/spells/" + str[0..0] + "/_" + replace_string(str, " ", "_") + ".c";
    if (!file_exists(tmp)) {
        tell_object(ob, "The spell " + str + " does not exist!");
        free = 0;
        return 1;
    }

    spell = new(tmp);
    for (i = 0; i < sizeof(myclasses); i++) {
        if ((int)spell->query_spell_level(myclasses[i]) > 0 && (int)spell->query_spell_level(myclasses[i]) < 3) {
            okclasses += ({ myclasses[i] }); // classes that allow it as a L1-2 spell only
            if (myclasses[i] == "bard" ||
                myclasses[i] == "inquisitor" ||
                myclasses[i] == "oracle" ||
                myclasses[i] == "magus" ||
                myclasses[i] == "sorcerer") {
                num++;
            }
        }
    }

    if (!sizeof(okclasses)) {
        tell_object(ob, "You do not have a class that can cast " + str + " at a suitable level.");
        free = 0;
        return 1;
    }

    for (i = 0; i < sizeof(okclasses); i++) {
        if ((int)ob->can_memorize(okclasses[i], str) == MEM_OK || (int)ob->can_memorize(okclasses[i], str) == TOO_MANY) {
            num++;
        }
    }

    if (!num) {
        tell_object(ob, "You can not cast the spell " + str + ".  Aborting...");
        free = 0;
        return 1;
    }

    tell_object(ob, "%^YELLOW%^Setting your SpellMastery spell to %^BLUE%^" + str + "%^YELLOW%^ upon removal of greater spell mastery feat.%^RESET%^");
    amt = calculate_feat_cost(ob) / 8;
    if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0 && amt > 0) {
        tell_object(ob, "%^YELLOW%^Are you sure you want to remove the feat " +
                    feat + "?  It will cost you %^MAGENTA%^" + amt + "%^YELLOW%^ exp.%^RESET%^");
    }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1 && amt > 0) {
        tell_object(ob, "%^YELLOW%^Are you sure you want to remove the feat " +
                    feat + "?  It will cause you to incur a character improvement tax of " +
                    "%^MAGENTA%^" + amt + "%^YELLOW%^.  This tax will reduce all future " +
                    "experience gained by %^RED%^50%%^YELLOW%^ until it is repaid.%^RESET%^");
    }else {
        tell_object(ob, "%^YELLOW%^Are you sure you want to remove the feat " +
                    feat + "?");
    }
    tell_object(ob, "Enter <yes> to remove the feat, anything else to abort.");
    input_to("confirm_remove", ob, feat, str);
    return 1;
}

int spell_mastery_spell(string str, object ob, string feat, string mytype)
{
    int num, level, okclasslvl, i, amt;
    object spell;
    string file, * okclasses, * myclasses, tmp;

    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }
    if (!stringp(str)) {
        return 0;
    }

    okclasses = ({});
    myclasses = ob->query_classes();
    if (!sizeof(myclasses)) {
        tell_object(ob, "Your classes are broken! Contact a wiz!");
        free = 0;
        return 1;
    }

    tmp = "/cmds/spells/" + str[0..0] + "/_" + replace_string(str, " ", "_") + ".c";
    if (!file_exists(tmp)) {
        tell_object(ob, "The spell " + str + " does not exist!");
        free = 0;
        return 1;
    }

    spell = new(tmp);
    for (i = 0; i < sizeof(myclasses); i++) {
        if (feat != "spellmastery") {
            continue;
        }
        if (myclasses[i] == "warlock") {
            continue;
        }                                          // let's avert the warlocks taking this by mistake!
        // check for - greater than L0; either less than L3, or less than L6 for a mage either taking archmage & has spellmastery, or taking spellmastery & has archmage

        level = spell->query_spell_level(myclasses[i]);
        if (level < 1) {
            continue;
        }
        if (level > 5) {
            continue;
        }
        if (level < 3) {
            okclasses += ({ myclasses[i] });
            if (myclasses[i] == "bard" ||
                myclasses[i] == "inquisitor" ||
                myclasses[i] == "magus" ||
                myclasses[i] == "oracle" ||
                myclasses[i] == "sorcerer") {
                num++;
            }
            continue;
        }
        if (myclasses[i] != "mage" && myclasses[i] != "archmage") {
            continue;
        }
        if (level < 6) {
            if (FEATS_D->usable_feat(ob, "archmage") || FEATS_D->usable_feat(ob, "greater spell mastery")) {
                okclasses += ({ "mage" }); // want this to be mage, not archmage
                continue;
            }
        }
    }

    if (!sizeof(okclasses)) {
        tell_object(ob, "You do not have a class that can cast " + str + " at a suitable level.");
        free = 0;
        spell->remove();
        return 1;
    }

    for (i = 0; i < sizeof(okclasses); i++) {
        if ((int)ob->can_memorize(okclasses[i], str) == MEM_OK || (int)ob->can_memorize(okclasses[i], str) == TOO_MANY) {
            num++;
        }
    }

    if (!num) {
        tell_object(ob, "You can not cast the spell " + str + ".  Aborting...");
        free = 0;
        spell->remove();
        return 1;
    }
    amt = calculate_feat_cost(ob);
    switch (mytype) {
    case "magic":
    case "racial":
        tell_object(ob, "%^YELLOW%^Setting your SpellMastery spell to %^BLUE%^" + str + "%^YELLOW%^ with a free " + mytype + " feat.%^RESET%^");
        break;

    default:
        tell_object(ob, "%^YELLOW%^Setting your SpellMastery spell to %^BLUE%^" + str + "%^YELLOW%^.%^RESET%^");
        break;
    }
    if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0 && amt > 0) {
        tell_object(ob, "%^YELLOW%^Are you sure you want to add the feat " +
                    feat + "?  It will cost you %^MAGENTA%^" + amt + "%^YELLOW%^ exp.%^RESET%^");
    }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1 && amt > 0) {
        tell_object(ob, "%^YELLOW%^Are you sure you want to add the feat " +
                    feat + "?  It will cause you to incur a character improvement tax of " +
                    "%^MAGENTA%^" + amt + "%^YELLOW%^.  This tax will reduce all future " +
                    "experience gained by %^RED%^50%%^YELLOW%^ until it is repaid.%^RESET%^");
    }else {
        tell_object(ob, "%^YELLOW%^Are you sure you want to add the feat " +
                    feat + "?");
    }
    tell_object(ob, "Enter <yes> to add the feat, anything else to abort.");
    input_to("confirm_add_type", ob, feat, str, mytype);
    spell->remove();
    return 1;
    spell->remove();
    return 1;
}

int skill_focus_setting(string str, object ob, string feat, string mytype)
{
    int myflag, i, amt;
    string* myclasses, * myclassskills, file;

    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }
    if (!stringp(str)) {
        return 0;
    }

    if (member_array(str, CORE_SKILLS) == -1) {
        tell_object(ob, "%^YELLOW%^The %^BLUE%^" + str + " %^YELLOW%^ skill does not exist, or is not a valid choice for this feat.%^RESET%^");
        tell_object(ob, "Aborting...");
        free = 0;
        return 1;
    }
    myclasses = ob->query_classes();
    for (i = 0; i < sizeof(myclasses); i++) {
        file = DIR_CLASSES + "/" + myclasses[i] + ".c";
        if (file_exists(file)) {
            myclassskills = (string*)file->class_skills(ob);
            if (member_array(str, myclassskills) != -1) {
                tell_object(ob, "%^RED%^Warning:%^YELLOW%^ you already have %^BLUE%^" + str + " %^YELLOW%^as a class skill from one or more of your existing classes.%^RESET%^");
            }
        }
    }
    amt = calculate_feat_cost(ob);
    switch (mytype) {
    case "racial":
        tell_object(ob, "%^YELLOW%^Setting your Skill Focus skill to %^BLUE%^" + str + "%^YELLOW%^ with a free " + mytype + " feat.%^RESET%^");
        break;
    default:
        tell_object(ob, "%^YELLOW%^Setting your Skill Focus skill to %^BLUE%^" + str + "%^YELLOW%^.%^RESET%^");
        break;
    }
    if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0 && amt > 0) {
        tell_object(ob, "%^YELLOW%^Are you sure you want to add the feat " +
                    feat + "?  It will cost you %^MAGENTA%^" + amt + "%^YELLOW%^ exp.%^RESET%^");
    }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1 && amt > 0) {
        tell_object(ob, "%^YELLOW%^Are you sure you want to add the feat " +
                    feat + "?  It will cause you to incur a character improvement tax of " +
                    "%^MAGENTA%^" + amt + "%^YELLOW%^.  This tax will reduce all future " +
                    "experience gained by %^RED%^50%%^YELLOW%^ until it is repaid.%^RESET%^");
    }else {
        tell_object(ob, "%^YELLOW%^Are you sure you want to add the feat " +
                    feat + "?");
    }
    tell_object(ob, "Enter <yes> to add the feat, anything else to abort.");
    input_to("confirm_add_type", ob, feat, str, mytype);
    return 1;
}

int confirm_add_type(string str, object ob, string feat, string extradata, string feattype)
{
    int price;

    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }
    if (str != "yes") {
        tell_object(ob, "Aborting...");
        free = 0;
        return 1;
    }
    if (!stringp(feattype) || feattype == "") {
        feattype = "other";
    }

    if (feattype == "other") {
        price = calculate_feat_cost(ob);
        if ((int)ob->query("free_feats")) {
            ob->set("free_feats", ((int)ob->query("free_feats") - 1));
        }

        if (feat == "spellmastery" || feat == "archmage" || feat == "greater spell mastery") {
            ob->set("spellmastery_spell", extradata);
        }
        if (feat == "skill focus") {
            ob->set("skill_focus", extradata);
        }
        FEATS_D->add_my_feat(ob, feattype, feat);
        //moved this down - otherwise feats that require a specific level will
        //never get added if the exp cost would cause you to lose a level - Saide
        if (!avatarp(ob)) {
            if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0) {
                ob->add_exp(price * -1);
                ob->resetLevelForExp(0);
                tell_object(ob, "Subtracting " + price + " experience points.");
            }
            else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1) {
                if ((int)ob->set_XP_tax(price, 0, "improvement") == -1) {
                    tell_object(ob, "Currently your character improvement tax is above the maximum allowed. " +
                        "You must first reduce it before you can add this feat.");
                    return 1;
                }
                if (price > 0) {
                    tell_object(ob, "Incuring character improvement tax of " + price + ". All future experience gained will be " +
                        "reduced by 50% until it is repaid.");
                }
            }
        }
        tell_object(ob, "%^YELLOW%^Congratulations, you have successfully added "
            "the feat %^BLUE%^" + feat + "%^YELLOW%^!%^RESET%^");
        free = 0;
        return 1;
    }
    else {
        if (feattype == "magic" || feattype == "hybrid" || feattype == "racial") {
            if (feat == "spellmastery") {
                ob->set("spellmastery_spell", extradata);
            }
            if (feat == "skill focus") {//racial only
                ob->set("skill_focus", extradata);
            }
        }
        FEATS_D->add_my_feat(ob, feattype, feat);
        tell_object(ob, "%^YELLOW%^Congratulations, you have successfully added "
            "the bonus " + feattype + " feat %^BLUE%^" + feat + "%^YELLOW%^!%^RESET%^");
        free = 0;
        return 1;
    }
}

int confirm_remove(string str, object ob, string feat, string extradata)
{
    int price, i;
    string* myspells, * schoolspells;

    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }

    if (str != "yes") {
        tell_object(ob, "Aborting...");
        return 1;
    }
    if ((feat == "archmage" && extradata != "") || (feat == "greater spell mastery" && extradata != "")) {
        ob->set("spellmastery_spell", extradata);
    }                                                                                                                                                // has to be reset to L1-2 if they have it.
    if (feat == "spellmastery") {
        ob->delete("spellmastery_spell");
    }
    if (feat == "skill focus") {
        ob->delete("skill_focus");
    }

    price = calculate_feat_cost(ob) / 8;
    if (!avatarp(ob)) {
        if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0) {
            ob->add_exp(price * -1);
            ob->resetLevelForExp(0);
            tell_object(ob, "Subtracting " + price + " experience points.");
        }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1) {
            if ((int)ob->set_XP_tax(price, 0, "improvement") == -1) {
                tell_object(ob, "Currently your character improvement tax is above the maximum allowed. " +
                            "You must first reduce it before you can remove this feat.");
                return 1;
            }
            if (price > 0) {
                tell_object(ob, "Incuring character improvement tax of " + price + ". All future experience gained will be " +
                            "reduced by 50% until it is repaid.");
            }
        }
    }
    if ((int)ob->query("free_feats")) {
        ob->set("free_feats", ((int)ob->query("free_feats") - 1));
    }
    FEATS_D->remove_my_feat(ob, feat);
    tell_object(ob, "%^YELLOW%^You have successfully removed the feat "
                "%^MAGENTA%^" + feat + ".%^RESET%^");
    return 1;
}

int cmd_feats(string str)
{
    object ob;
    string tmp, feat, * info = ({}), * required, * my_required = ({}), * my_tmp_feats = ({}), category, * subset = ({}), * feats = ({}), * melee_retool = ({}), * feat_types, feat_types_labels;
    int i, j, MAX_ALLOWED, BONUS_ALLOWED, num_feats, allowed, num_bonus, bonus, my_lev, * featkeys;
    mapping classfeats, otherfeats, bonus_feats;

    find_object_or_load(FEATS_D);
    FEATS_D->update_usable(TP);

    if (!stringp(str)) {
//        FEATS_D->display_feats(TP,TP);
        tell_object(TP, "See <help feats> for syntax.");
        return 1;
    }

    str = lower_case(str);

    if (avatarp(TP) && objectp(ob = find_player(str))) {
        FEATS_D->display_feats(TP, ob);
        return 1;
    }

    if (!TP->query("new_class_type")) {
        return 1;
    }

    MAX_ALLOWED = ((int)TP->query_highest_level() / 3) + 1;
    free = 0;

    info = explode(str, " ");

    switch (info[0]) {
    case "list":
        info -= ({ info[0] });
        if (!sizeof(info)) {
            FEATS_D->display_feats(TP, TP);
            return 1;
        }
        switch (info[0]) {
        case "spellcraft":
        case "martial":
        case "hybrid":
        case "general":
        case "arcana":
        case "divinebond":
            FEATS_D->display_feats(TP, TP, info[0]);
            return 1;

        case "epic":
            if (!high_mortalp(TP) && !avatarp(TP) && CONFIG_D->check_config("HM") == 0) {
                FEATS_D->display_feats(TP, TP);
            }else {
                FEATS_D->display_feats(TP, TP, "epic");
            }
            return 1;

        default:
            FEATS_D->display_feats(TP, TP);
            return 1;
        }
        FEATS_D->display_feats(TP, TP);
        return 1;

    case "wipe":
        if (avatarp(TP)) {
            tell_object(TP, "Clearing feats for " + TP->query_true_name() + ".");
            TP->clear_feats();
            return 1;
        }else {
            if (!TP->query("free_feat_wipe")) {
                TP->set("free_feat_wipe", 1);
                TP->clear_feats();
                TP->set_divine_domain(({}));
                num_feats = ((int)TP->query_level() / 3) + 1;
                TP->set("free_feats", num_feats);
                if (!avatarp(TP)) {
                    tell_object(TP, "%^BOLD%^%^RED%^You have been given a feat wipe. Please reallocate your feats before going back out.%^RESET%^");
                }
                TP->force_me("feats fix");
            } else {
                tell_object(TP, "You already used your free feats wipe. Contact staff to get another one.");
            }
            return 1;
        }
        return 0;

    case "fix":
        required = TP->query_classes();
        if (!sizeof(required)) {
            return 1;
        }

        // first pickup current "other" feats that were bought
        otherfeats = TP->query_other_feats();
        featkeys = keys(otherfeats);
        num_feats = TP->query("free_feats");
        feats = ({});
        for (i = 0; i < sizeof(featkeys); i++) {
            feats += otherfeats[featkeys[i]];
        }

        //for fighter bonus feats - Saide
        otherfeats = TP->query_bonus_feats();
        featkeys = keys(otherfeats);
        for (i = 0; i < sizeof(featkeys); i++) {
            feats += otherfeats[featkeys[i]];
        }

        // now run addition of any missing class feats; remove from bought
        // feats first if they already did

        for (bonus = 0; bonus < sizeof(required); bonus++) {
            category = "/std/class/" + required[bonus] + ".c";
            if (!file_exists(category)) {
                continue;
            }
            tmp = (string)TP->query_combat_spec(required[bonus]);         // new combat spec code, N 1/14.
            classfeats = category->class_featmap(tmp, TP);
            if (!mapp(classfeats)) {
                continue;
            }
            featkeys = keys(classfeats);
            if (sizeof(featkeys)) {
                for (i = 0; i < sizeof(featkeys); i++) {
                    if ((int)TP->query_class_level(required[bonus]) < featkeys[i]) {
                        continue;
                    }
                    subset = classfeats[featkeys[i]];
                    for (j = 0; j < sizeof(subset); j++) {
                        my_lev = ((int)TP->query_level()) - (int)TP->query_class_level(required[bonus]) + featkeys[i];
                        if (!my_lev) {
                            my_lev = 1;
                        }

                        if (member_array(subset[j], feats) != -1) { // if they have this as a bought feat, revoke
                            if ((string)FEATS_D->get_feat_type(TP, subset[j]) != "bonus") {
                                num_feats++;
                            }
                            FEATS_D->remove_my_feat(TP, subset[j], 1);
                            tell_object(TP, "%^YELLOW%^Moving feat %^BLUE%^" +
                                        subset[j] + "%^YELLOW%^ to class feats.");
                        }

                        if (!FEATS_D->has_feat(TP, subset[j])) {
                            tell_object(TP, "Adding " + required[bonus] + " class levelling feat: " +
                                        subset[j] + " at " + my_lev + ".");
                            FEATS_D->add_feat(TP, "class", subset[j], my_lev);
                        }
                    }
                }
                TP->set("free_feats", num_feats);
            }
        }
        return 1;

    case "check":
        if (sscanf(str, "%s %s", category, tmp) != 2) {
            tell_object(TP, "See <help feats> for syntax.");
            return 1;
        }

        my_tmp_feats = (string*)TP->query_temporary_feats();
        TP->clear_temporary_feats();

        if (FEATS_D->can_use_feat(TP, tmp)) {
            tell_object(TP, "%^YELLOW%^Congratulations, you meet all of the requirements for "
                        "the feat " + tmp + ".%^RESET%^");
        }else {
            tell_object(TP, "%^RED%^You do not meet all of the requirements for the "
                        "feat " + tmp + ", please check the help file for the individual feats "
                        "for more information.%^RESET%^");
        }

        TP->set_temporary_feats(my_tmp_feats);
        return 1;

    case "allowed":
        num_feats = (int)TP->query_other_feats_gained();
        allowed = MAX_ALLOWED - num_feats;
        if (allowed < 0) {
            allowed = 0;
        }
        subset = TP->query_classes();
        if (!sizeof(subset)) {
            tell_object(TP, "%^RED%^There is an error in the settings of your classes. Please notify a wiz with this error message.%^RESET%^");
            return 1;
        }

        tell_object(TP, "%^WHITE%^You are allowed %^BOLD%^%^BLUE%^" + MAX_ALLOWED + "%^RESET%^ "
                    "feats. You have used %^BOLD%^%^BLUE%^" + num_feats + " %^RESET%^and you now have "
                    "%^BOLD%^%^BLUE%^" + allowed + "%^RESET%^ left.%^RESET%^");

//racial, martial, magic, hybrid, arcana, divine
        feat_types = FEAT_TYPES;
        for (i = 0; i < sizeof(FEAT_TYPES); i++) {
            BONUS_ALLOWED = 0;
            num_bonus = 0;
            switch (feat_types[i]){
            case "racial":
                BONUS_ALLOWED = FEATS_D->number_feats(TP, feat_types[i], ({ }));
                num_bonus = (int)TP->query_racial_feats_gained();
                feat_types_labels = feat_types[i];
                break;
            case "martial":
                BONUS_ALLOWED = FEATS_D->number_feats(TP, feat_types[i], MELEECLASSES);
                num_bonus = (int)TP->query_bonus_feats_gained();
                feat_types_labels = feat_types[i];
                break;
            case "spellcraft":
                BONUS_ALLOWED = FEATS_D->number_feats(TP, feat_types[i], CASTERCLASSES);
                num_bonus = (int)TP->query_magic_feats_gained();
                feat_types_labels = "magic";
                break;
            case "hybrid":
                BONUS_ALLOWED = FEATS_D->number_feats(TP, feat_types[i], HYBRIDCLASSES);
                num_bonus = (int)TP->query_hybrid_feats_gained();
                feat_types_labels = feat_types[i];
                break;
            case "arcana":
                BONUS_ALLOWED = FEATS_D->number_feats(TP, feat_types[i], ({ "magus" }));
                num_bonus = (int)TP->query_arcana_feats_gained();
                feat_types_labels = feat_types[i];
                break;
            case "divinebond":
                BONUS_ALLOWED = FEATS_D->number_feats(TP, feat_types[i], ({ "paladin" }));
                num_bonus = (int)TP->query_divinebond_feats_gained();
                feat_types_labels = "divine";
                break;
            default:
                BONUS_ALLOWED = 0;
                num_bonus = 0;
                feat_types_labels = "";
                break;
            }
            bonus = BONUS_ALLOWED - num_bonus;

            if (BONUS_ALLOWED > 0) {
                tell_object(TP, "%^BOLD%^%^WHITE%^You have %^BOLD%^%^BLUE%^" + BONUS_ALLOWED + "%^WHITE%^ free " + feat_types_labels +
                    " bonus feats. You have used %^BOLD%^%^BLUE%^" + num_bonus + " %^WHITE%^. You have "
                    "%^BOLD%^%^BLUE%^" + bonus + "%^WHITE%^ left.%^WHITE%^");
            }
        }

// free-cost feat allocation here
        if (TP->query("free_feats")) {
            tell_object(TP, "%^BOLD%^%^CYAN%^You currently have %^BLUE%^" + TP->query("free_feats") + "%^BOLD%^%^CYAN%^ free-cost feats.");
        }
        FEATS_D->display_feats(TP, TP, "allowed");
        return 1;

    case "active":
        FEATS_D->display_feats(TP, TP, "active");
        return 1;

    case "add":
    case "racial":
    case "martial":
    case "spellcraft":
    case "hybrid":
    case "arcana":
    case "divinebond":
        if (sscanf(str, "%s %s", category, tmp) != 2) {
            tell_object(TP, "See <help feats> for syntax.");
            return 1;
        }

        if (validation_messages(TP, category, tmp) == 1) {
            return 1;
        }

        return 1;

    case "remove":
        //        info -= ({ info[0] });
        //	  if(!sizeof(info))
        if (sscanf(str, "%s %s", category, tmp) != 2) {
            tell_object(TP, "See <help feats> for syntax.");
            return 1;
        }
        //        if(sizeof(info)) { tmp = implode(info," "); }
        if (!FEATS_D->can_remove_feat(TP, tmp)) {
            feat = "/cmds/feats/" + tmp[0..0] + "/_" + replace_string(tmp, " ", "_") + ".c";
            if (!file_exists(feat)) {
                tell_object(TP, "%^BOLD%^The feat " + tmp + " is not a real feat, "
                    "please check your spelling and try again.");
                return 1;
            }
            required = (string*)feat->query_required_for();
            for (i = 0; i < sizeof(required); i++) {
                if (FEATS_D->has_feat(TP, required[i])) {
                    my_required += ({ required[i] });
                }
            }
            if (!FEATS_D->has_feat(ob, feat)) {
                tell_object(TP, "%^BOLD%^You don't have the feat " + tmp + ".");
            }else if (!sizeof(my_required)) {
                tell_object(TP, "%^BOLD%^The feat " + tmp + " is a feat that you were granted "
                    "freely for your class.  You are not allowed to remove it.");
            }
            else {
                tell_object(TP, "%^BOLD%^The feat " + tmp + " is a feat required by others.  You "
                    "must also get rid of " + implode(my_required, " ") + " before you can remove "
                    "your " + tmp + " feat.");
            }
        }
        else {
            if (TP->query("negative level")) {
                tell_object(TP, "You have a negative level and must have it removed before " +
                    "you can remove any feats!");
                return 1;
            }
            if (intp(USER_D->get_scaled_level(TP))) {
                tell_object(TP, "You have scaled your level down and must revert it back to " +
                    "normal before you can remove any feats!");
                return 1;
            }
            i = calculate_feat_cost(TP) / 8;
            if ((tmp == "archmage" || tmp == "greater spell mastery") && FEATS_D->has_feat(TP, "spellmastery")) {
                if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0 && i > 0) {
                    tell_object(TP, "%^YELLOW%^Are you sure you want to remove the feat "
                        "" + tmp + "?  It will cost you %^MAGENTA%^" + i + "%^YELLOW%^ "
                        "exp, and you will be required to re-confirm your spellmastery option.%^RESET%^");
                }
                else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1 && i > 0) {
                    tell_object(TP, "%^YELLOW%^Are you sure you want to remove the feat "
                        "" + tmp + "?  It will cause you to incur a character improvement tax of " +
                        "%^MAGENTA%^" + i + "%^YELLOW%^.  This tax will reduce all future " +
                        "experience gained by %^RED%^50%%^YELLOW%^ until it is repaid, "
                        "and you will be required to re-confirm your spellmastery option.%^RESET%^");
                }
                else {
                    tell_object(TP, "%^YELLOW%^Are you sure you want to remove the feat "
                        "" + tmp + "?");
                }
                tell_object(TP, "Please type the name of the spell that you would like "
                    "your spellmastery feat to use.  It must be of level 1 or 2 only.  Type anything "
                    "else to abort.");
                input_to("remove_spell_mastery_spell", TP, tmp);
                return 1;
            }

            if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0 && i > 0) {
                tell_object(TP, "%^YELLOW%^Are you sure you want to remove the feat "
                    "" + tmp + "?  It will cost you %^MAGENTA%^" + i + "%^YELLOW%^ exp.%^RESET%^");
            }
            else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1 && i > 0) {
                tell_object(TP, "%^YELLOW%^Are you sure you want to remove the feat "
                    "" + tmp + "?  It will cause you to incur a character improvement tax of " +
                    "%^MAGENTA%^" + i + "%^YELLOW%^.  This tax will reduce all future " +
                    "experience gained by %^RED%^50%%^YELLOW%^ until it is repaid.%^RESET%^");
            }
            else {
                tell_object(TP, "%^YELLOW%^Are you sure you want to remove the feat " +
                    tmp + "?");
            }
            tell_object(TP, "Enter <yes> to remove the feat " + tmp + ", anything else to "
                "abort.");
            input_to("confirm_remove", TP, tmp, "");
        }
        return 1;
    }
    tell_object(TP, "See <help feats> for syntax.");
    return 1;
}

int validation_messages(object obj, string group, string feat_name) {
    int BONUS_ALLOWED, num_bonus, can_gain, i, j;
    string group_2, * valid_classes, * valid_categories, * my_tmp_feats, category;

    BONUS_ALLOWED = 0;
    switch (group) {
    case "martial":
        valid_classes = MELEECLASSES;
        valid_categories = MELEEFEATS;
        num_bonus = (int)obj->query_bonus_feats_gained();
        can_gain = FEATS_D->can_gain_type_feat(obj, feat_name, "martial");
        group_2 = "martial";
        break;
    case "spellcraft":
        valid_classes = CASTERCLASSES;
        valid_categories = SPELLFEATS;
        num_bonus = (int)obj->query_magic_feats_gained();
        can_gain = FEATS_D->can_gain_type_feat(obj, feat_name, "spellcraft");
        group_2 = "magic";
        break;
    case "hybrid":
        valid_classes = HYBRIDCLASSES;
        valid_categories = MELEEFEATS;
        valid_categories += SPELLFEATS;
        num_bonus = (int)obj->query_hybrid_feats_gained();
        can_gain = FEATS_D->can_gain_type_feat(obj, feat_name, "hybrid");
        group_2 = group;
        break;
    case "arcana":
        valid_classes = ({ "magus" });
        valid_categories = MAGUSFEATS;
        num_bonus = (int)obj->query_arcana_feats_gained();
        can_gain = FEATS_D->can_gain_type_feat(obj, feat_name, "arcana");
        group_2 = group;
        break;
    case "divinebond":
        valid_classes = ({ "paladin" });
        valid_categories = PALADINFEATS;
        num_bonus = (int)obj->query_divinebond_feats_gained();
        can_gain = FEATS_D->can_gain_type_feat(obj, feat_name, "divinebond");
        group_2 = group;
        break;
    case "add"://class
        valid_classes = ({ });
        valid_categories = ({ });
        num_bonus = (int)obj->query_other_feats_gained();
        can_gain = FEATS_D->can_gain_type_feat(obj, feat_name, "class");
        group_2 = "";
        break;
    case "racial":
        valid_classes = ({ });
        valid_categories = ({ });
        num_bonus = (int)obj->query_racial_feats_gained();
        can_gain = FEATS_D->can_gain_type_feat(obj, feat_name, "racial");
        group_2 = "racial";
        break;
    default:
        valid_classes = ({ });
        valid_categories = ({ });
        num_bonus = 0;
        can_gain = 0;
        group_2 = "";
        break;
    }

    BONUS_ALLOWED = FEATS_D->number_feats(obj, group, valid_classes);
    if (BONUS_ALLOWED == -1) {
        return 1;
    }

    if (num_bonus >= BONUS_ALLOWED) {
        tell_object(obj, "%^RESET%^%^BOLD%^You are not able to add "
            "any more bonus " + group_2 + " feats at your current level.%^RESET%^");
        return 1;
    }
    if (FEATS_D->has_feat(obj, feat_name)) {
        tell_object(obj, "%^RESET%^%^BOLD%^You already have that "
            "feat.");
        return 1;
    }
    if (obj->query("negative level")) {
        tell_object(obj, "You have a negative level and must have it removed before " +
            "you can add any feats!");
        return 1;
    }
    if (intp(USER_D->get_scaled_level(obj))) {
        tell_object(obj, "You have scaled your level down and must revert it back to " +
            "normal before you can add any feats!");
        return 1;
    }

    if (group == "add") {
        if ((string)FEATS_D->get_category(feat_name) == "EpicFeats") {
            if (!high_mortalp(obj) && CONFIG_D->check_config("HM") == 0) {
                tell_object(obj, "%^RESET%^%^BOLD%^You must be a high "
                    "mortal to buy an epic feat.%^RESET%^");
                return 1;
            }
            if ((int)obj->query_epic_feats_gained() > 0) {
                tell_object(obj, "%^RESET%^%^BOLD%^You have already bought "
                    "an epic feat. You can only have one at a time.%^RESET%^");
                return 1;
            }
        }

        if ((string)FEATS_D->get_category(feat_name) == "MagusArcana") {
            tell_object(obj, "%^RESET%^%^BOLD%^This is a magus class feat. "
                "This feat can only be selected as an arcana feat.%^RESET%^");
            return 1;
        }

        if ((string)FEATS_D->get_category(feat_name) == "DivineBond") {
            tell_object(obj, "%^RESET%^%^BOLD%^This is a paladin class feat. "
                "This feat can only be selected as a divinebond feat.%^RESET%^");
            return 1;
        }
    }
    else {
        if ((string)FEATS_D->get_category(feat_name) == "EpicFeats") {
            tell_object(obj, "%^RESET%^%^BOLD%^You can't buy epic feats "
                "with class bonus slots.%^RESET%^");
            return 1;
        }
    }

    my_tmp_feats = (string*)obj->query_temporary_feats();
    obj->clear_temporary_feats();

    if (!can_gain) {
        tell_object(obj, "%^RESET%^%^BOLD%^You are not able to add the "
            "feat " + feat_name + ", please make sure you meet all of the "
            "requirements.%^RESET%^");
        obj->set_temporary_feats(my_tmp_feats);
        return 1;
    }

    obj->set_temporary_feats(my_tmp_feats);

    if (group != "add") {
        category = FEATS_D->get_category(feat_name);
        if ((member_array(category, valid_categories) == -1 && group != "racial") &&
            !(group == "arcana" && feat_name == "disruptive") &&
            !(group == "arcana" && feat_name == "spellbreaker")) {
            tell_object(obj, "%^YELLOW%^The %^BLUE%^" + feat_name + " %^YELLOW%^ feat is not a valid " + group_2 + " feat.%^RESET%^");
            tell_object(obj, "Aborting...");
            return 1;
        }
        free = 1;  // special tracking for typed feats
    }

    if (group == "spellcraft" || group == "hybrid" || group == "racial" || group == "add"){
        if (feat_name == "spellmastery") {
            if (FEATS_D->has_feat(obj, "archmage") || FEATS_D->has_feat(obj, "greater spell mastery")) {
                tell_object(obj, "%^YELLOW%^In order to gain the spellmastery feat, you must "
                    "select a spell that you are currently able to cast that is up to "
                    "level 5.  You can pick any spell of levels 1 through 5 that you "
                    "are able to cast.%^RESET%^");
            }
            else {
                tell_object(obj, "%^YELLOW%^In order to gain the spellmastery feat, you must "
                    "select a spell that you are currently able to cast that is level 1 "
                    "or level 2.  You can pick any spell of level 1 or level 2 that you "
                    "are able to cast.%^RESET%^");
            }
            tell_object(obj, "Please type the name of the spell that you would like "
                "your spellmastery feat to use.");
            input_to("spell_mastery_spell", obj, feat_name, group_2);
            return 1;
        }
    }
    if (group == "racial" || group == "add") {
        if (feat_name == "skill focus") {
            tell_object(obj, "%^YELLOW%^In order to gain the skill focus feat, you must "
                "select a skill that you wish to learn as a class-skill.  You can pick "
                "any skill that isn't already class-based.%^RESET%^");
            tell_object(obj, "Please type the name of the skill that you would like "
                "your skill focus feat to use.");
            input_to("skill_focus_setting", obj, feat_name, group_2);
            return 1;
        }
    }

    if (group == "add") {
        // allow_shifted()

        for (i = 0; i < sizeof(SHIFTING_CLASSES); i++) {
            if (obj->is_class(SHIFTING_CLASSES[i])) {
                if (!("/cmds/feats/" + feat_name[0..0] + "/_" + replace_string(feat_name, " ", "_") + ".c")->allow_shifted()) {
                    tell_object(obj, "%^RED%^The feat " + feat_name + " can not be used while you are shapeshifed, but "
                        "it will still work as normal while you are in your regular form.");
                    break;
                }
            }
        }
        i = calculate_feat_cost(obj);
        if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0 && i > 0) {
            tell_object(obj, "%^YELLOW%^Are you sure you want to add the feat " + feat_name + "?  It will "
                "cost you %^MAGENTA%^" + i + " %^YELLOW%^exp.%^RESET%^");
        }
        else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1 && i > 0) {
            tell_object(obj, "%^YELLOW%^Are you sure you want to add the feat " + feat_name + "?  It will "
                "cause you to incur a character improvement tax of %^MAGENTA%^" + i + "%^YELLOW%^.  " +
                "This tax will cause all future experience gained to be reduced by %^RED%^50%%^YELLOW%^" +
                " until it is repaid.%^RESET%^");
        }
        else {
            tell_object(obj, "%^YELLOW%^Are you sure you want to add the feat " + feat_name + "?");
        }
    }
    else{
        tell_object(obj, "%^YELLOW%^Are you sure you want to add the feat " + feat_name + " as one of "
            "your free bonus " + group_2 + " feats?  It will cost nothing to add, but you will have "
            "to spend exp to remove it later if you change your mind.%^RESET%^");
    }
    tell_object(obj, "Enter <yes> to add the feat, anything else to abort.");
    input_to("confirm_add_type", obj, feat_name, "", group_2);
    return 1;
}

int help()
{
    write("
%^CYAN%^NAME%^RESET%^

feats - manipulate or view your feats

%^CYAN%^SYNOPSIS%^RESET%^

feats allowed
feats check|add|remove %^ULINE%^%^ORANGE%^FEAT_NAME%^RESET%^
feats racial|martial|spellcraft|hybrid|arcana|divinebond %^ULINE%^%^ORANGE%^FEAT_NAME%^RESET%^
feats list [martial|spellcraft|hybrid|arcana|divinebond|general]
feats fix
feats active

%^CYAN%^DESCRIPTION%^RESET%^

Feats represents specialized techniques or powers a character can learn throughout its career. Some feats are class-specific (usually gained for free with class-levels), while others are generic and must be paid for by adding to your exp tax (see <help exp tax>). A character gains 1 generic feat every 3. level which can be bought in such a way. Feats awarded by character class are added automatically. Some classes gain additional free feats known as bonus feats. When you level your character, you will get notified if you are allowed new feats.

Feats are divided into types (martial, spellcraft, hybrid, arcana, generic, epic) and organized in feat trees.  Some feats have prerequisites as specified in their individual help files.

The following commands apply:

%^ORANGE%^<feats allowed>%^RESET%^
    Tells you how many feats you are allowed at your current level.
%^ORANGE%^<feats check %^ORANGE%^%^ULINE%^FEAT%^RESET%^%^ORANGE%^>%^RESET%^
    Tells you if you meet all the requirements to take this feat.
%^ORANGE%^<feats add %^ORANGE%^%^ULINE%^FEAT%^RESET%^%^ORANGE%^>%^RESET%^
    Will add the feat if you have any remaining levelling feats.
%^ORANGE%^<feats remove %^ORANGE%^%^ULINE%^FEAT%^RESET%^%^ORANGE%^>%^RESET%^
    Will remove the feat if you no longer want to retain it.
%^ORANGE%^<feats racial|martial|spellcraft|hybrid|arcana|divinebond %^ORANGE%^%^ULINE%^FEAT%^RESET%^%^ORANGE%^>%^RESET%^
    Will add the feat of given category if you have any bonus feats in it.
%^ORANGE%^<feats list martial|spellcraft|hybrid|arcana|divinebond|general|epic>%^RESET%^
    Displays the specified feat trees.
%^ORANGE%^<feats fix>%^RESET%^
    Will attempt to fix your feat tree. If your feats seem incorrect, use this command.
%^ORANGE%^<feats active>%^RESET%^
    Tells you what feats you have activated.
%^ORANGE%^<feats wipe>%^RESET%^
    Will wipe all your feats once per character or if devs granted you free wipe.

%^CYAN%^COLOR CODING%^RESET%^

If your terminal supports color, you may benefit from color coding of the feats according to type, status and if the player has the feat or not:
  %^CYAN%^-- Feat%^RESET%^: Does not have feat.
  %^RESET%^%^RED%^00 Feat%^RESET%^: Has feat, but no longer meets prerequisites.
  %^BOLD%^%^GREEN%^00 Feat%^RESET%^: Has feat and it gives a permanent bonus.
  %^YELLOW%^00 Feat:%^RESET%^ Has duration feat which is currently active.
  %^BOLD%^%^CYAN%^00 Feat%^RESET%^: Requires input from character to activate feat.
  %^BOLD%^%^BLUE%^00 Feat%^RESET%^: A temporary feat which has been granted by an item or spell.
The numbers listed before the feats indicate which level the feats were gained at:
  %^BOLD%^%^CYAN%^00%^RESET%^: The feat has been bought normally.
  %^BOLD%^%^MAGENTA%^00%^RESET%^: The feat has been granted for free (class feats).
  %^YELLOW%^00%^RESET%^: The feat has been bought with bonus racial, combat, magic, hybrid, arcana or dvinebond feats.

Adding and removing normal feats will add to your character improvement tax (see %^ORANGE%^<help exp tax>%^RESET%^) and slow your level advancement. This is to simulate the extra training that it requires to learn the new abilities or to forget your previous training.

%^CYAN%^SEE ALSO%^RESET%^

exp tax, skills, stats, score, hp, bonuses
");

    if (avatarp(TP)) {
        write("
%^CYAN%^IMMORTALS%^RESET%^

feats %^ULINE%^%^ORANGE%^PLAYER%^RESET%^

    To see a list of their feats.

feats wipe

    To clear all of your feats.
");
    }
    return 1;
}
