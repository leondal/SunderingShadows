//     /cmds/mortal/_recall.c
//     Allows a player to recall a list of "remember"ed places
//     and objects.
//     Written by Vashkar@ShadowGate
//     Made to work by Grendel@Shadowgate

//Updating this command to be prettier - codewise - and
//allow for the ability to do like recall priest spells 8
//to recall only your level 8 priest spells - Saide 3/09

#include <std.h>
#include <daemons.h>
#include <clock.h>
inherit DAEMON;

mapping remembered, temp;
string strtemp, *strarr;
#define LEV_AND_COLORS ([ 1 : "%^BOLD%^%^BLACK%^", 2 : "%^RED%^", 3 : "%^GREEN%^", 4 : "%^MAGENTA%^", 5 : "%^CYAN%^", 6 : "%^BOLD%^%^BLUE%^", 7 : "%^BOLD%^%^RED%^", 8 : "%^BOLD%^%^GREEN%^", 9 : "%^BOLD%^%^MAGENTA%^"])

#define FR "%^BOLD%^%^BLUE%^--==%^CYAN%^< %^BOLD%^%^WHITE%^"
#define BK "%^BOLD%^%^CYAN%^ >%^BLUE%^==--%^RESET%^"

int cmd_recall(string str)
{
    int i, num, what;
    string errCheck;
    if (str == "locations") {
        remembered = TP->query_rem_rooms();
        strarr = TP->query_rem_rooms_sort();
        if (!remembered || sizeof(remembered) < 1) {
            tell_object(TP, "You can't remember a single location.");
            return 1;
        }else {
            int roomnw;
            int maxknown = TP->query_base_stats("intelligence") + ( FEATS_D->usable_feat(this_player(), "worldly traveler") * 5);

            string* output = ({});

            strarr = sort_array(strarr, 1);
            num = sizeof(strarr);

            write("%^BOLD%^%^BLUE%^--==%^CYAN%^< %^WHITE%^ " + num + "/" + maxknown + " Locations Remembered %^CYAN%^>%^BLUE%^==--%^RESET%^");
            output = ({});

            roomnw = max(map(keys(remembered), (: sizeof($1) :)));

            for (i = 0; i < sizeof(strarr); i++) {
                if (!remembered[strarr[i]] ||
                    !file_exists(remembered[strarr[i]] + ".c") ||
                    !find_object_or_load(remembered[strarr[i]])) {
                    strtemp = strarr[i];
                    temp = remembered;
                    map_delete(temp, strtemp);
                    TP->set_rem_rooms(temp, strarr - ({ strarr[i] }));
                    continue;
                }
                output += ({ "%^RESET%^%^CYAN%^ " + arrange_string(strarr[i], roomnw + 1) + remembered[strarr[i]]->query_short() });
            }

            tell_object(TP, auto_format_page(output, TP, 34));
        }
        return 1;
    }
    if (str == "monsters" || sscanf(str, "monster %d", what) == 1) {
        remembered = TP->query_study_mons();
        strarr = TP->query_study_mons_sort();
        if (!remembered || sizeof(remembered) < 1) {
            tell_object(TP, "You haven't studied a foe.");
            return 1;
        }else {
            string* output = ({});
            int maxknown = TP->query_base_stats("intelligence") * 2;

            if (FEATS_D->usable_feat(TP, "monster lore")) {
                if (TP->query_base_stats("wisdom") > TP->query_base_stats("intelligence")) {
                    maxknown = (int)TP->query_base_stats("wisdom") * 2;
                }
            }

            strarr = sort_array(strarr, 1);
            num = sizeof(strarr);

            if (str != "monsters") {
                if (what >= 0 && what < num) {
                    tell_object(TP, strarr[what]->query_short());
                    tell_object(TP, strarr[what]->query_long());
                    "/cmds/mortal/_study"->do_monster_read(TP, strarr[what]);
                    return 1;
                }else {
                    tell_object(TP, "That's not a valid option.");
                    return 1;
                }
            }

            write("%^BOLD%^%^BLUE%^--==%^CYAN%^< %^WHITE%^ " + num + "/" + maxknown + " Studied Monsters %^CYAN%^>%^BLUE%^==--%^RESET%^");
            output = ({});

            for (i = 0; i < sizeof(strarr); i++) {
                if (!strarr[i] ||
                    !file_exists(strarr[i] + ".c") ||
                    !find_object_or_load(strarr[i])) {
                    strtemp = strarr[i];
                    temp = remembered;
                    map_delete(temp, strtemp);
                    TP->set_study_mons(temp, strarr - ({ strarr[i] }));
                    continue;
                }
                output += ({ "%^RESET%^%^CYAN%^ " + i + ". " + strarr[i]->query_short() });
            }

            tell_object(TP, auto_format_page(output, TP, 34));
        }
        return 1;
    }else if (sscanf(str, "monster %s", errCheck) == 1) {
        tell_object(TP, "That's not a valid option.");
        return 1;
    }
    if (str == "innate spells") {
        if (recall_innate_spells(TP)) {
            return 1;
        }
    }
    if(str == "cantrip spells")
    {
        if(recall_cantrips(TP))
            return 1;
    }
    if (str == "monk spells") {
        tell_object(TP, "See <help ki>");
        return 1;
    }
    if (str == "relationships") {
        mapping relationships = TP->getRelationships();
        string known = ({});

        map_mapping(relationships, (:(!user_exists($1)) && $3->remove_relationship($1):), TP);

        known = collapse_array(map(values(relationships), (:values($1):)));
        known = sort_array(distinct_array(known), 1);

        tell_object(TP, "%^BOLD%^%^BLUE%^--==%^CYAN%^< %^WHITE%^People Remembered %^CYAN%^>%^BLUE%^==--%^RESET%^");
        tell_object(TP,auto_format_page(known, TP, 34));

        return 1;
    }
    if (str == "spells") {
        tell_object(TP, "Please specify which spells you " +
                    "would like to recall: <recall classname spells>.");
        return 1;
    }

    if (recall_spells(str, TP)) {
        return 1;
    }

    // No argument
    remembered = TP->query_rem_obs();
    strarr = TP->query_rem_obs_sort();
    if (!remembered || sizeof(remembered) < 1) {
        tell_object(TP, "You can't remember a single thing.");
        return 1;
    }else {
        tell_object(TP, "%^BOLD%^%^BLUE%^--==%^CYAN%^< %^WHITE%^" +
                    "Things Remembered %^CYAN%^>%^BLUE%^==--%^RESET%^");
        for (i = 0; i < sizeof(strarr); i++) {
            if (!find_object_or_load(remembered[strarr[i]] + ".c")) {
                strtemp = strarr[i];
                temp = remembered;
                map_delete(temp, strtemp);
                TP->set_rem_obs(temp, strarr - ({ strarr[i] }));
                continue;
            }
            write("%^CYAN%^" + sprintf("%-15s %-25s", strarr[i],
                                       remembered[strarr[i]]->query_short()) + "%^RESET%^");
        }
    }
    return 1;
}

void sort(string* arr)
{
    int i, j;

    for (j = 0; j < sizeof(arr); j++) {
        for (i = sizeof(arr) - 1; i > j; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr, i - 1, i);
            }
        }
    }
}

private void swap(string* arr, int i, int j)
{
    string tmp;

    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int* magic_arsenal_feat(object ob, int* spells)
{
    int i;

    if (FEATS_D->usable_feat(ob, "magic arsenal")) {
        for (i = 0; i < sizeof(spells); i++) {
            if (!spells[i]) {
                continue;
            }
            spells[i] += 2;
        }
    }
    if (FEATS_D->usable_feat(ob, "greater arsenal")) {
        for (i = 0; i < sizeof(spells); i++) {
            if (!spells[i]) {
                continue;
            }
            spells[i] += TP->query_level() / 10 + 1;
        }
    }
    if (FEATS_D->usable_feat(ob, "gift of the shadows")) {
        for (i = 0; i < sizeof(spells); i++) {
            if (!spells[i]) {
                continue;
            }
            spells[i] += TP->query_level() / 10 + 1;
        }
    }
    return spells;
}

int* bonus_spell_slots(object ob, int* spells)
{
    int i, extra, bon_lvl;

    extra = (int)ob->query_property("bonus_spell_slots");
    for (i = 0; i < sizeof(spells); i++) {
        if (!spells[i]) {
            continue;
        }
        if (intp(extra) && extra) {
            spells[i] += extra;
        }
        bon_lvl = (int)ob->query_property("bonus_spell_slots_" + (i + 1));
        if (intp(bon_lvl) && bon_lvl) {
            spells[i] += bon_lvl;
        }
        if (spells[i] < 0) {
            spells[i] = 0;
        }
    }
    return spells;
}

mixed MakeTimeDisplay(int MyTime)
{
    string MyHour, MyMin, MySec;
    MyTime -= time();
    MyTime = MyTime / 3; // added to display in RL time; 60sec/min to 20sec/min compared. N, 11/16.
    MyHour = "" + MyTime / HOUR;
    if (strlen(MyHour) < 2) {
        MyHour = "0" + MyHour;
    }
    MyMin = "" + (MyTime % HOUR) / MINUTE;
    if (strlen(MyMin) < 2) {
        MyMin = "0" + MyMin;
    }
    MySec = "" + ((MyTime % HOUR) % MINUTE) / SECOND;
    if (strlen(MySec) < 2) {
        MySec = "0" + MySec;
    }
    return MyHour + ":" + MyMin + ":" + MySec;
}

int recall_cantrips(object who)
{
    mixed cantrips;
    string msg;
    
    if(!objectp(who))
        return 0;
    
    cantrips = who->query_cantrip_spells();
    
    if(!sizeof(cantrips))
        return 0;
    
    cantrips = sort_array(cantrips, "alphabetical_sort", FILTERS_D);
    
    msg = FR + "Cantrips" + BK;
    
    foreach(string str in cantrips)
        msg += "\n%^BOLD%^WHITE%^" + str + "%^RESET%^";
        
    tell_object(this_player(), msg);
    return 1;
}

int recall_innate_spells(object who)
{
    int x, max, uses;
    string MyMsg, tmp, MyUses;
    mixed innate_spells;
    if (!objectp(who)) {
        return 0;
    }
    if (!(innate_spells = who->query_innate_spells())) {
        return 0;
    }
    if (!sizeof(innate_spells)) {
        return 0;
    }
    innate_spells = sort_array(innate_spells, "alphabetical_sort", FILTERS_D);
    MyMsg = FR + "Innate Spells" + BK;
    for (x = 0; x < sizeof(innate_spells); x++) {
        tmp = capitalize(innate_spells[x]);
        MyMsg += "\n%^BOLD%^%^WHITE%^" + sprintf("%-20s %-5s", tmp, "At Will");
        MyMsg += "%^RESET%^";
    }
    tell_object(TP, MyMsg);
    return 1;
}

int recall_spells(string type, object who)
{
    int i, num, x, * max, cur = 0, flag, * lkeys, spell_level, class_level;
    mapping spells;
    string* skeys, * tmp = ({ "" }), * words, name, ccolor, spell_type, sp_class, f_msg, s_msg, dirl, mystat, strhold, subrace, myextra;

    spell_level = -1; //for all levels - Saide
    if (!type) {
        return 0;
    }
    if (!objectp(who)) {
        return 0;
    }

    //Section of the code that handles
    //discerning the type of spell
    //and whether or not a spell level was
    //given by the player - Saide
    words = explode(type, " ");
    if (sizeof(words) > 3) {
        return 0;
    }
    if (sizeof(words) < 2) {
        return 0;
    }
    if (words[1] != "spells") {
        tell_object(TP, "Please specify which spells you would like to recall: <recall classname spells>.");
        return 1;
    }

    spell_type = words[0];
    if (spell_type == "warlock") {
        tell_object(TP, "You don't need to worry about prepared spells! Just <master> them and cast!");
        return 1;
    }
    if (spell_type == "psywarrior" || spell_type == "psion") {
        if (!who->is_class(spell_type)) {
            tell_object(who, "You cannot cast spells as a " + spell_type + "!");
            return 1;
        }
        i = who->query_max_mp();
        num = who->query_mp();
        if (i < 1) {
            tell_object(who, "Something seems to be wrong with your max power points. Please contact a wiz.");
            return 1;
        }
        s_msg = FR + capitalize(spell_type) + " Points Prepared" + BK;
        if (num < 1) {
            tell_object(who, "You have no " + spell_type + " power points prepared.");
            return 1;
        }
        tell_object(who, s_msg);
        tell_object(who, "      %^BOLD%^%^CYAN%^" + num + "%^RESET%^/%^RESET%^%^CYAN%^" + i + "%^RESET%^");
        if (FEATS_D->usable_feat(who, "expanded knowledge 1")) {
            myextra = who->query("expanded_knowledge_1");
            if (stringp(myextra)) {
                tell_object(who, "%^BOLD%^Expanded Knowledge 1 Power:%^RESET%^ " + myextra + "");
            }
        }
        if (FEATS_D->usable_feat(who, "expanded knowledge 2")) {
            myextra = who->query("expanded_knowledge_2");
            if (stringp(myextra)) {
                tell_object(who, "%^BOLD%^Expanded Knowledge 2 Power:%^RESET%^ " + myextra + "");
            }
        }
        if (FEATS_D->usable_feat(who, "expanded knowledge 3")) {
            myextra = who->query("expanded_knowledge_3");
            if (stringp(myextra)) {
                tell_object(who, "%^BOLD%^Expanded Knowledge 3 Power:%^RESET%^ " + myextra + "");
            }
        }
        return 1;
    }

    if (sizeof(words) == 3) {
        spell_level = to_int(words[2]);
        if (spell_level < 1 || spell_level > 9) {
            spell_level = -1;
        }
    } else {
        spell_level = -1;
    }

    //Section of the code that determines if
    //you can use the spells you requested to recall
    //and if so it sets a few things so that the
    //code will know what to do later on - Saide

    if (spell_type == "wizard") {
        spell_type = "mage";
    }
    if (spell_type == "priest") {
        spell_type = "cleric";
    }
    if (spell_type == "psionic") {
        spell_type = "psion";
    }
    if (!who->is_class(spell_type)) {
        return 0;
    }

    switch (spell_type) {
    case "cleric": case "ranger": case "druid": case "inquisitor":
        mystat = "wisdom"; break;
    case "bard": case "sorcerer": case "oracle": case "paladin":
        mystat = "charisma"; break;
    default: mystat = "intelligence"; break;
    }
    if (spell_type == "antipaladin") {
        spells = who->query_all_memorized("paladin");
    }else {
        spells = who->query_all_memorized(spell_type);
    }
    map_delete(spells, 0);

    s_msg = FR + capitalize(spell_type) + " Spells Prepared" + BK;
    f_msg = "You have no " + spell_type + " spells prepared.";

    dirl = "/cmds/spells/";

    class_level = who->query_prestige_level(spell_type);
    if (!class_level) {
        class_level = who->query_class_level(spell_type);
    }

    max = WIZ_CALCS->query_max_spell_array(class_level, spell_type, who->query_stats(mystat));
    max = magic_arsenal_feat(who, max);
    max = bonus_spell_slots(who, max);
    if ((string)who->query_race() == "human") {
        subrace = (string)who->query("subrace");
        if (subrace) {
            if (subrace == "senzokuan") {
                max[0] == max[0]++;                      // +1 to slots at L1 for human Senzokuan ethnicity
            }
        }
    }

    //End of the part of the code that determines whether
    //or not you can use the spells you're requesting

    lkeys = keys(spells);
    lkeys = sort_array(lkeys, 1);
    if (sizeof(lkeys)) {
        for (x = 0; x < sizeof(lkeys); x++) {
            flag = 0;
            ccolor = LEV_AND_COLORS[lkeys[x]];
            if (spell_level != -1) {
                if (max[spell_level - 1] != 0) {
                    if (lkeys[x] != spell_level) {
                        continue;
                    }
                }
            }
            skeys = keys(spells[lkeys[x]]);
            if (sizeof(skeys)) {
                tmp += ({ "%^BOLD%^%^WHITE%^" +
                            "Level " + lkeys[x] + " " +
                            spell_type + ": " });
                flag = sizeof(tmp);
                sort(skeys);
            }else {
                if (max[x] == 0) {
                    continue;
                }
                tmp += ({ "%^BOLD%^%^WHITE%^" +
                            "Level " + lkeys[x] + " " +
                            spell_type + ": " });
                cur = 0;
                flag = sizeof(tmp);
            }
            cur = 0;
            for (i = 0; i < sizeof(skeys); i++) {
                name = skeys[i];
                num = spells[lkeys[x]][name];
                cur += to_int(num);
                if (!file_exists(dirl + name[0..0] + "/_" + replace_string(name, " ", "_") + ".c")) {
                    continue;
                }
                tmp += ({ ccolor +
                          sprintf("  %-26s %-5d", name, num) + "" });
            }
            if (flag) {
                tmp[flag - 1] += cur + "/" + max[x] + "";
            }
        }
        //tell_object(who, identify(tmp));
        //tell_object(who,s_msg);
        {
            string* output = tmp;
            string* obuff, oline;
            int y, z;
            int columns;
            int scrw = atoi(TP->getenv("SCREEN"));
            int vertical = TP->getenv("VCOLUMNS") ? 1 : 0;

            scrw = scrw > 34 ? scrw : 72;

            z = max(map_array(output, (: sizeof(strip_colors($1)) :))) + 2;
            columns = scrw / z;
            columns = columns < 1 ? 1 : columns;
            y = atoi(TP->getenv("COLUMNS"));
            y = y < 1 ? 1 : y;
            columns = columns > y ? y : columns;
            x = 0;
            obuff = ({});
            scrw = z * columns;
            foreach(oline in output)
            {
                if (regexp(oline, "Level")) {
                    if (sizeof(obuff)) {
                        tell_object(TP, format_page(obuff, columns, scrw, vertical));
                    }
                    obuff = ({});
                    tell_object(TP, oline);
                    continue;
                }
                obuff += ({ oline });
            }
            tell_object(TP, format_page(obuff, columns, scrw));
        }

        return 1;
    }else {
        tell_object(TP, f_msg);
        return 1;
    }
    return 1;
}


void help()
{
    write(
@HELP
%^CYAN%^NAME%^RESET%^

recall - recall knowledge

%^CYAN%^SYNOPSIS%^RESET%^

recall locations
recall relationships
recall monsters
recall monster %^ORANGE%^%^ULINE%^NUMBER%^RESET%^
recall %^ORANGE%^%^ULINE%^CLASS%^RESET%^ spells [%^ORANGE%^%^ULINE%^LEVEL%^RESET%^]
recall innate spells
recall cantrip spells

%^CYAN%^DESCRIPTION%^RESET%^

This command allows you to recall locations, monsters or spells you know.

%^ORANGE%^<recall locations>%^RESET%^
    You'll be displayed a list of locations you remembered with %^ORANGE%^<remember>%^RESET%^. Note, whenever you do it, list of locations will be validated and any non-existent or temporary locations (such as rope trick rooms) will be removed.

%^ORANGE%^<recall relationships>%^RESET%^
    You'll be displayed a list of names you used to recognize people as.

%^ORANGE%^<recall monsters>%^RESET%^
    You'll be displayed a list of monsters you studied with %^ORANGE%^<study>%^RESET%^. Note, whenever you do it, list of monsters will be validated.

%^ORANGE%^<recall monster %^ORANGE%^%^ULINE%^NUMBER%^RESET%^>%^RESET%^
    You'll be displayed the details of a monster you studied with %^ORANGE%^<study>%^RESET%^. The number is taken from %^ORANGE%^<recall monsters>%^RESET%^.


%^ORANGE%^<recall %^ORANGE%^%^ULINE%^CLASS%^RESET%^%^ORANGE%^ spells [%^ORANGE%^%^ULINE%^LEVEL%^RESET%^%^ORANGE%^]>%^RESET%^
    You'll view list of memorized spells for standard casters, power points fo psionic classes and spell levels for spontaneous classes. Additionally you can specify level to view that level only.

%^ORANGE%^<recall innate spells>%^RESET%^
    Use this command to review list of your innate spells granted by your race or class.

This command is affected by collumns setting of the %^ORANGE%^<set>%^RESET%^ command.

%^CYAN%^SEE ALSO%^RESET%^

remember, unremember, recognize, set, study, fixspells
HELP
);
    return;
}
