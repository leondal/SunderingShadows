//     Coded by Grayhawk@ShadowGate
//     July 14, 1995

#include <std.h>
#include <new_exp_table.h>
#include <daemons.h>

inherit DAEMON;

int is_valid_stat_move(object who, string stat, string stat_two);
int STR, INT, WIS;
int DEX, CON, CHR;
string str;
int EXPS;

int stat_points_left(object ob)
{
    int allowed, gained, remaining;

    if (!objectp(ob)) {
        return 0;
    }

    gained = (int)ob->query("stat_points_gained");
    allowed = (int)ob->query_base_character_level() / 4;
    remaining = allowed - gained;
    if (remaining < 0) {
        remaining = 0;
    }
    return remaining;
}

int confirm_stat_gain(string str, object ob, string stat, int cost)
{
    int num, gained;
    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(stat)) {
        return 0;
    }
    if (!intp(cost)) {
        return 0;
    }

    if (str != "yes") {
        tell_object(ob, "Aborting...");
        return 0;
    }

    if ((int)ob->set_XP_tax(cost, 0, "improvement") == -1) {
        tell_object(ob, "Currently your character improvement tax is above the maximum allowed. " +
                    "You must first reduce it before you can gain this stat point.");
        return 1;
    }
    gained = (int)ob->query("stat_points_gained");
    gained += 1;
    ob->delete("stat_points_gained");
    ob->set("stat_points_gained", gained);
    num = (int)ob->query_rolled_stats(stat);
    ob->set_stats(stat, num + 1);
    tell_object(ob, "%^YELLOW%^You have successfully added 1 point to your " +
                stat + ", your " + stat + " score is now " + ob->query_base_stats(stat) + ".%^RESET%^");
    FEATS_D->update_usable(ob);
    return 1;
}

int gain_stat(object ob, string stat)
{
    int current, cost, total_exp, exp;

    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(stat)) {
        return 0;
    }

    if (!stat_points_left(ob)) {
        tell_object(ob, "%^RED%^You have no stat points left to gain.");
        return 0;
    }

    if (ob->is_undead() && stat == "constitution") {
        tell_object(ob,"As an undead you can't manipulate your constitution.");
        return 0;
    }

    switch (stat) {
    case "str": stat = "strength";      break;
    case "con": stat = "constitution";  break;
    case "dex": stat = "dexterity";     break;
    case "int": stat = "intelligence";  break;
    case "wis": stat = "wisdom";        break;
    case "cha": stat = "charisma";      break;
    }

    current = (int)ob->query_rolled_stats(stat);
    if (!current) {
        tell_object(ob, "%^BOLD%^" + stat + " is not a valid stat, please pick either "
                    "strength, dexterity, constitution, intelligence, wisdom, or charisma.  "
                    "You may also use the abbreviations str,dex,con,int,wis and cha.");
        return 0;
    }
    if (current < 0) {
        return 0;
    }
    if (current > 54) {
        tell_object(ob, "%^RED%^You can't have a base stat (before racial & age modifiers) higher than 55 points.");
        return 0;
    }

    total_exp = (int)ob->query_exp();
    exp = total_exp_for_level(ob->query_adjusted_character_level());
    cost = exp_for_level(ob->query_adjusted_character_level());

    tell_object(ob, "%^YELLOW%^Do you really want to add a point to " + stat + "?  It will " +
                "add a character improvement tax of %^MAGENTA%^" + cost + "%^YELLOW%^ experience points. " +
                "This tax will reduce all experience you gain by %^RED%^50%%^YELLOW%^ until it is repaid.");

    tell_object(ob, "Enter <yes> to confirm, anything else to abort.");
    input_to("confirm_stat_gain", ob, stat, cost);
    return 1;
}

int is_valid_stat_move(object who, string stat, string stat_two)
{
    mapping MyStats;
    int StatOne, StatTwo, StatTotals, CurStat;

    if (!objectp(who)) {
        return 0;
    }

    StatOne = (int)who->query_rolled_stats(stat) + 1;
    StatTwo = (int)who->query_rolled_stats(stat_two) - 1;
    if ((int)who->query_base_stats(stat) + 1 > 25) {
        tell_object(who, "You cannot have a stat higher than " +
                    "25.");
        return 0;
    }

    if (StatTwo < 6) {
        tell_object(who, "Your base " + stat + " cannot go below 6.");
        return 0;
    }

    if (who->is_undead() && (stat == "constitution" || stat_two == "constitution")) {
        tell_object(who,"As an undead you can't manipulate your constitution.");
        return 0;
    }

    StatTotals = 0;
    MyStats = ([]);
    if ((CurStat = (int)who->query_rolled_stats("strength")) >= 18) {
        MyStats += (["strength" : CurStat]);
        StatTotals += CurStat - 18;
    }
    if ((CurStat = (int)who->query_rolled_stats("dexterity")) >= 18) {
        MyStats += (["dexterity" : CurStat]);
        StatTotals += CurStat - 18;
    }
    if ((CurStat = (int)who->query_rolled_stats("intelligence")) >= 18) {
        MyStats += (["intelligence" : CurStat]);
        StatTotals += CurStat - 18;
    }
    if ((CurStat = (int)who->query_rolled_stats("constitution")) >= 18) {
        MyStats += (["constitution" : CurStat]);
        StatTotals += CurStat - 18;
    }
    if ((CurStat = (int)who->query_rolled_stats("wisdom")) >= 18) {
        MyStats += (["wisdom" : CurStat]);
        StatTotals += CurStat - 18;
    }
    if ((CurStat = (int)who->query_rolled_stats("charisma")) >= 18) {
        MyStats += (["charisma" : CurStat]);
        StatTotals += CurStat - 18;
    }
    if (StatOne > 18 && StatTotals >= (int)who->query("stat_points_gained")) {
        if (MyStats[stat]) {
            if (MyStats[stat_two] > 18) {
                return 1;
            }
        }
        tell_object(who, "That would cause your base " + stat +
                    " to be higher than allowed.");
        return 0;
    }
    return 1;
}

int confirm_move_stat(string str, object obj, string stat_one, string stat_two, int cost)
{
    if (str != "yes") {
        tell_object(obj, "Aborting...");
        return 0;
    }
    if (!cost) {
        tell_object(obj, "Error with exp cost, contact a wiz... exiting...");
        return 0;
    }

    if ((int)obj->set_XP_tax(cost, 0, "improvement") == -1) {
        tell_object(obj, "Currently your character improvement tax is above the maximum " +
                    "allowed, you must reduce it before moving stats.");
        return 1;
    }
    obj->force_me("stats");
    obj->set_stats(stat_one, (int)obj->query_rolled_stats(stat_one) - 1);
    obj->set_stats(stat_two, (int)obj->query_rolled_stats(stat_two) + 1);

    tell_object(obj, "%^BOLD%^Moving 1 point of " + stat_one + " into " + stat_two + "...%^RESET%^");
    tell_object(obj, "%^BOLD%^Done.%^RESET%^");
    obj->force_me("stats");
    return 1;
}

int move_stat(object obj, string* stats)
{
    string stat_one, stat_two;
    int cost, exp, total_exp, tcheck;

    if (!objectp(obj)) {
        return 0;
    }
    if (!pointerp(stats)) {
        return 0;
    }

    switch (lower_case(stats[0])) {
    case "str": stat_one = "strength";      break;
    case "con": stat_one = "constitution";  break;
    case "dex": stat_one = "dexterity";     break;
    case "int": stat_one = "intelligence";  break;
    case "wis": stat_one = "wisdom";        break;
    case "cha": stat_one = "charisma";      break;
    }

    switch (lower_case(stats[1])) {
    case "str": stat_two = "strength";      break;
    case "con": stat_two = "constitution";  break;
    case "dex": stat_two = "dexterity";     break;
    case "int": stat_two = "intelligence";  break;
    case "wis": stat_two = "wisdom";        break;
    case "cha": stat_two = "charisma";      break;
    }

    if (!is_valid_stat_move(obj, stat_two, stat_one)) {
        return 1;
    }
    total_exp = (int)obj->query_exp();
    exp = total_exp_for_level(obj->query_adjusted_character_level());
    cost = exp_for_level(obj->query_adjusted_character_level());
    tcheck = cost;

    if (obj->is_undead() && (stat_one == "constitution" || stat_two == "constitution")) {
        tell_object(obj,"As an undead you can't manipulate your constitution.");
        return 0;
    }

    tell_object(obj, "%^YELLOW%^You will incur a character improvement " +
                "tax of %^MAGENTA%^" + cost + "%^RESET%^%^YELLOW%^ "
                " to move 1 point from " + stat_one + " into " + stat_two +
                ".  This tax will reduce all future experience points that you gain by " +
                "%^RED%^50%%^YELLOW%^ until it is repaid. Are you sure you want to do this?  Enter %^MAGENTA%^yes" +
                "%^RESET%^%^YELLOW%^ to confirm, anything else to abort.");

    input_to("confirm_move_stat", obj, stat_one, stat_two, cost);
    return 1;
}

string mybonus(object who, string stat)
{
    int bonus;
    if (!objectp(who)) {
        return "";
    }
    bonus = BONUS_D->query_stat_bonus(who, stat);
    if (bonus > 0) {
        return "+" + bonus;
    } else {
        return " " + bonus;
    }
}

string stat_display(int stat, int cur_stat)
{
    if (stat == cur_stat) {
        return "%^RESET%^" + stat;
    }
    if (stat < cur_stat) {
        return "%^BOLD%^%^CYAN%^" + cur_stat + "%^RESET%^";
    }
    if (stat > cur_stat) {
        return "%^BOLD%^%^RED%^" + cur_stat + "%^RESET%^";
    }
}

int cmd_stats(string person)
{
    object obj;
    int age, i, bonus, cstr, cint, cwis, ccon, cdex, ccha;
    string* tmp, * valid, bstr;

    if (!avatarp(TP)) {
        obj = TP;
    }
    if (!stringp(person)) {
        obj = TP;
    }
    if (!objectp(obj = find_player(person))) {
        obj = TP;
    }

    if (TP->query("new_class_type")) {
        if (stringp(person) && strsrch(person, "gain") != -1) {
            person = replace_string(person, "gain ", "");
            if (TP->query("negative level")) {
                tell_object(TP, "You have a negative level and must have it removed before " +
                            "you can gain stats!");
                return 1;
            }
            if (intp(USER_D->get_scaled_level(TP))) {
                tell_object(TP, "You have scaled your level down and must revert it back to " +
                            "normal before you can gain any stats!");
                return 1;
            }
            gain_stat(TP, person);
            return 1;
        }

        if (stringp(person) && strsrch(person, "move") != -1) {
// breaking on level-adjusted characters @ L11, fixing. N, 4/1/20
//            if((int)TP->query_base_character_level() < 10)
            if ((int)TP->query_base_character_level() < 10) {
                tell_object(TP, "You must be above level 10 in order to move one of your "
                            "stats.");
                return 1;
            }
            if (TP->query("negative level")) {
                tell_object(TP, "You have a negative level and must have it removed before " +
                            "you can move stats!");
                return 1;
            }
            if (intp(USER_D->get_scaled_level(TP))) {
                tell_object(TP, "You have scaled your level down and must revert it back to " +
                            "normal before you can move any stats!");
                return 1;
            }
            valid = ({ "str", "dex", "con", "int", "wis", "cha" });
            if (strsrch(person, "to") == -1) {
                tell_object(TP, "Syntax: stats move str to dex");
                return 1;
            }
            person = replace_string(person, "move ", "");
            person = replace_string(person, "to ", "");
            tmp = explode(person, " ");
            if (sizeof(tmp) != 2) {
                tell_object(TP, "Syntax: stats move str to dex");
                return 1;
            }
            for (i = 0; i < sizeof(tmp); i++) {
                if (member_array(tmp[i], valid) == -1) {
                    tell_object(TP, "You must pick your stats from the following list: " + implode(valid, " ") + "");
                    return 1;
                }
            }
            move_stat(TP, tmp);
            return 1;
        }
    }

    STR = obj->query_base_stats("strength");
    cstr = obj->query_stats("strength");
    INT = obj->query_base_stats("intelligence");
    cint = obj->query_stats("intelligence");
    WIS = obj->query_base_stats("wisdom");
    cwis = obj->query_stats("wisdom");
    DEX = obj->query_base_stats("dexterity");
    cdex = obj->query_stats("dexterity");
    CON = obj->query_base_stats("constitution");
    ccon = obj->query_stats("constitution");
    CHR = obj->query_base_stats("charisma");
    ccha = obj->query_stats("charisma");

    str = "\n%^RESET%^%^GREEN%^Str %^RESET%^" + stat_display(STR, cstr) + " (" + mybonus(obj, "strength") + ")";
    str += "  %^GREEN%^Dex %^RESET%^" + stat_display(DEX, cdex) + " (" + mybonus(obj, "dexterity") + ")";
    if (obj->is_undead()) {
        str += "  %^GREEN%^Con %^RESET%^--\n";
    } else {
        str += "  %^GREEN%^Con %^RESET%^" + stat_display(CON, ccon) + " (" + mybonus(obj, "constitution") + ")\n";
    }

    str += "%^BLUE%^Int %^RESET%^" + stat_display(INT, cint) + " (" + mybonus(obj, "intelligence") + ")";
    str += "  %^BLUE%^Wis %^RESET%^" + stat_display(WIS, cwis) + " (" + mybonus(obj, "wisdom") + ")";
    str += "  %^BLUE%^Cha %^RESET%^" + stat_display(CHR, ccha) + " (" + mybonus(obj, "charisma") + ")";
    if (obj == TP) {
        tell_object(obj, "" + str);
    } else {
        tell_object(TP, "" + str);
    }

    if (obj == TP) {
        if (stat_points_left(obj) > 1) {
            tell_object(obj, "%^RESET%^%^BOLD%^You have %^CYAN%^" + stat_points_left(obj) + "%^RESET%^%^BOLD%^ bonus stat points remaining.%^RESET%^");
        } else if (stat_points_left(obj)) {
            tell_object(obj, "%^RESET%^%^BOLD%^You have %^CYAN%^1%^RESET%^%^BOLD%^ bonus stat point remaining.%^RESET%^");
        }
    }else {
        tell_object(TP, "%^RESET%^%^BOLD%^Base stats unmodified by age and race are:%^RESET%^");
        STR = obj->query_rolled_stats("strength");
        INT = obj->query_rolled_stats("intelligence");
        WIS = obj->query_rolled_stats("wisdom");
        DEX = obj->query_rolled_stats("dexterity");
        CON = obj->query_rolled_stats("constitution");
        CHR = obj->query_rolled_stats("charisma");

        tell_object(TP, "%^RESET%^%^GREEN%^str :%^RESET%^" + STR + "  %^GREEN%^int :%^RESET%^" + INT + "  %^GREEN%^wis :%^RESET%^" + WIS + "  %^GREEN%^dex :%^RESET%^" + DEX + "  %^GREEN%^con :%^RESET%^" + CON + "  %^GREEN%^cha :%^RESET%^" + CHR + "");
    }
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

stats - display and manipulate your stats

%^CYAN%^SYNOPSIS%^RESET%^

stats [gain %^ORANGE%^%^ULINE%^STAT%^RESET%^]|[move %^ORANGE%^%^ULINE%^STAT1%^RESET%^ to %^ORANGE%^%^ULINE%^STAT2%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

Without an argument, this command displays your character stats. Players have stat supremum set at 24 and infimum at 6, which can be changed through race and class adjustments. In addition to that, spells, magical items and other effects can both increase stats beyond and this point, but never to values more than 30 or less than 1.

This command is also used to manipulate your stats:

%^ORANGE%^<stats gain %^ORANGE%^%^ULINE%^STAT%^RESET%^%^ORANGE%^>%^RESET%^

    You will gain %^ORANGE%^%^ULINE%^STAT%^RESET%^ if you have bonus stat points and you character is able to gain it. Ability to gain certain stats depends on the class, race, subrace and your age. You will suffer penalizing experience tax (see %^ORANGE%^<help exp tax>%^RESET%^) for improving your character.

%^ORANGE%^<stats move %^ORANGE%^%^ULINE%^STAT1%^RESET%^%^ORANGE%^ to %^ORANGE%^%^ULINE%^STAT2%^RESET%^%^ORANGE%^>%^RESET%^

    With this command you're able to retrain your character by replacing %^ORANGE%^%^ULINE%^STAT1%^RESET%^ with %^ORANGE%^%^ULINE%^STAT2%^RESET%^. This is very penalizing process and big adjustments will require a lot of time if you wish to reforge yourself into something new. See %^ORANGE%^<help exp tax>%^RESET%^ to learn about the penalty.

%^CYAN%^SEE ALSO%^RESET%^

attributes, score, exp tax, biography, money, inventory, hp

");
}
