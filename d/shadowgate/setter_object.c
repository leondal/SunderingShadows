#include <daemons.h>
#include "genetics.h"
#include <dieties.h>
#include <objects.h>

inherit OBJECT;

// Skip to MODULES section to write new module.

string *ROLL_CHAIN = ({"class", "gender", "race", "subrace", "template", "age", "stat_mod", "stats", "height", "weight", "body_type", "hair_color", "eye_color", "language", "alignment", "deity", "class_special"});

/**
 * @file
 * @brief Setter object used in character creation
 *
 * To add a module x you must include it into ROLL_CHAIN, and at minimum add string *generate_x() and build_x() functions.
 * optional display_x() will handle display of _x.
 * optional synopsis_x() will display custom synopsis, if there is no display_x().
 * optional hint_x() will display hints before synopsis, if there is no synopsis_x() and no display_x().
 * optional select_x(string s) will handle custom selection.
 */


int head = 0;

mapping char_sheet = ([]);
mapping cache = ([]);

int brief = 0;
final_set = 0;

void create()
{
    ::create();
    set_short("%^MAGENTA%^A strange and powerful object%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This strange object radiates power " +
             "the likes of which you have never before seen. It seems to contain " +
             "the very essence of life, allowing one who holds it to " +
             "make choices which will alter the very fabric of their being. " +
             "You may <%^BOLD%^%^CYAN%^check%^BOLD%^%^WHITE%^> to glimpse " +
             "what choices it contains. You may <%^BOLD%^%^CYAN%^reset choice" +
             "%^BOLD%^%^WHITE%^> to alter one if you are unhappy with it. You " +
             "may <%^BOLD%^%^CYAN%^review%^BOLD%^%^WHITE%^> to see a list " +
             "of current options that this object affords you. It has " +
             "attached itself to you and will be with you for as long as you " +
             "are a newbie character in the world of ShadowGate.%^RESET%^");
    set_property("no drop", 1);
    set_property("death keep", 1);
    set_id(({ "setter object", "object", "charactercreationsetterobject" }));
    set_weight(0);
    set_property("no animate", 1);
    set_property("soulbound", 1);
}

void init()
{
    ::init();

    if (userp(ETO)) {
        if (!(newbiep(ETO) || ETO->query_property("creation"))) {
            TO->remove();
        }
    }

    if(!final_set)
    {
        add_action("_select", "pick");
        add_action("_select", "select");
        add_action("_select", "sel");

        add_action("_review", "review");

        add_action("_reset", "reset");

        add_action("_display_char_sheet", "sheet");

        add_action("_finalize", "finalize");
    }
}

_select(string str)
{

    if (head >= sizeof(ROLL_CHAIN)) {
        _display_char_sheet();
    } else if (select_common(str)) {
        advance_head();
    } else {
        display_common();
    }
    return 1;
}

_review()
{
    if (head >= sizeof(ROLL_CHAIN)) {
        _display_char_sheet();
    } else{
        display_common();}
    return 1;
}

_reset(string str)
{
    reset_common(str);
    return 1;
}

_display_char_sheet()
{

    string i, j;

    write("%^RESET%^--==%^BOLD%^< %^GREEN%^Your choices are as follows %^WHITE%^>%^RESET%^==--
");

    write(" %^BOLD%^%^GREEN%^Character Name   %^RESET%^%^GREEN%^: %^BOLD%^%^WHITE%^" + capitalize(ETO->query_name()));

    foreach(i in ROLL_CHAIN)
    {
        if(!char_sheet[i]){
            continue;
        }
        if (arrayp(char_sheet[i])) {
            write("%^BOLD%^%^GREEN%^ " + arrange_string(capitalize(replace_string(i, "_", " ")), 16) + "%^RESET%^%^GREEN%^ : %^BOLD%^%^WHITE%^" + implode(char_sheet[i], "%^CYAN%^, %^WHITE%^"));
            continue;
        }
        if (mapp(char_sheet[i])) {
            write(" ");
            foreach(j in keys(char_sheet[i]))
            {
                write("%^BOLD%^GREEN%^ " + arrange_string(capitalize(j), 16) + "%^RESET%^%^GREEN%^ : %^BOLD%^%^CYAN%^" + char_sheet[i][j]);
            }
            write(" ");
            continue;
        }

        write("%^BOLD%^%^GREEN%^ " + arrange_string(capitalize(replace_string(i, "_", " ")), 16) + "%^RESET%^%^GREEN%^ : %^BOLD%^%^WHITE%^" + char_sheet[i]);
    }

    write("
%^BOLD%^%^WHITE%^You can %^ORANGE%^<reset %^ULINE%^KEY%^RESET%^%^BOLD%^%^ORANGE%^>%^WHITE%^ if you're not satisfied with the result, for example, %^ORANGE%^<reset age>%^WHITE%^ will reset your %^CYAN%^age%^WHITE%^.");

    if (head >= sizeof(ROLL_CHAIN)) {
        write("
%^BOLD%^%^WHITE%^If you're done with your creation, you can %^ORANGE%^<finalize>%^WHITE%^ your choices and proceed further.");
    } else {
        write("
%^BOLD%^%^WHITE%^You're not yet done with the creation. To see your current choices type %^ORANGE%^<review>%^WHITE%^.");
    }
    return 1;
}

_finalize(){

    string i;
    object desc;
    object troom;

    if (head < sizeof(ROLL_CHAIN))
    {
        write("%^BOLD%^You're not yet done with your selections. Type %^ORANGE%^<review>%^WHITE%^ to see what is available.");
        return 1;
    }

    ETO->convert_relationships();

    if (objectp(to_object("/daemon/description_d")))
        if (desc = new("/daemon/description_d")) {
            desc->new_description_profile(ETO);
                destruct(desc);
            }

    foreach(i in ROLL_CHAIN)
    {
        if (!char_sheet[i]) {
            continue;
        }

        call_other(TO, "build_" + i);
    }

    set_long("%^WHITE%^%^BOLD%^This strange object radiates power the likes of which you have never before
seen. It seems to be dormant at the time.");

    tell_object(ETO, "

%^BOLD%^  Entering the world of ShadowGate!

");

    troom = new("/d/newbie/ooc/hub_room");
    ETO->move_player(troom);
    ETO->setenv("LINES", "20");
    ETO->setenv("SCREEN", "80");
    ETO->setenv("COLUMNS", "2");
    ETO->setenv("VCOLUMNS", 1);
    ETO->set("new_hp_rolled_two",1);
    ETO->set("no pk",1);
    ETO->set("new_hm_cap_set",1);
    ETO->set("new_stat_type2", 1);

    ("/std/class/" + char_sheet["class"])->newbie_func(ETO);

    ETO->add_quenched(50);
    ETO->add_stuffed(500);
    ETO->add_hp(TP->query_max_hp());
    ETO->add_hp(TP->query_max_hp());
    ETO->update_channels();
    ETO->new_body();

    ETO->init_skills("blah");
    ETO->set("align ok",1);
    ETO->clear_feats();

    ETO->set("hp_array",0);
    ETO->make_new_hitpoint_rolls(ETO);

    ETO->force_me("fixspells");
    ETO->force_me("feats fix");
    ETO->force_me("save");

    ETO->add_money("gold", 200 + roll_dice(5, 20));
    ETO->set_sight_bonus(RACE_D->query_sight_bonus(ETO->query("race")));

    final_set = 1;

    TO->remove();

    return 1;
}

advance_head()
{
    head++;
    if (head >= sizeof(ROLL_CHAIN)) {
        _display_char_sheet();
    } else {
        display_common();
    }
}

select_common(string str)
{
    string * choices;

    if (function_exists("select_" + ROLL_CHAIN[head], TO)) {
        return call_other(TO, "select_" + ROLL_CHAIN[head], str);
    }

    str = lower_case(str);

    choices = distinct_array(call_other(TO, "generate_" + ROLL_CHAIN[head]));

    if (sizeof(choices)) {
        if (str == "random") {
            str = choices[random(sizeof(choices))];
        } else {
            if (member_array(str, choices) == -1) {
                write("%^BOLD%^%^WHITE%^Selection %^RED%^" + str + "%^WHITE%^ is not valid for your %^RED%^" + ROLL_CHAIN[head] + "%^WHITE%^.");
                return 0;
            }
        }
    }

    char_sheet[ROLL_CHAIN[head]] = str;

    write("%^BOLD%^%^WHITE%^You have selected %^CYAN%^" + str + "%^WHITE%^ for your %^CYAN%^" + replace_string(ROLL_CHAIN[head], "_", " ") + "%^WHITE%^.");
    return 1;
}

display_common()
{
    string i;
    string * choices;

    if (function_exists("display_" + ROLL_CHAIN[head], TO)) {
        call_other(TO, "display_" + ROLL_CHAIN[head]);
        return;
    }

    choices = call_other(TO, "generate_" + ROLL_CHAIN[head]);

    if (sizeof(choices) > 1) {
        write("%^RESET%^--==%^BOLD%^< %^GREEN%^You must now choose your %^CYAN%^" + replace_string(ROLL_CHAIN[head], "_", " ") + " %^WHITE%^>%^RESET%^==--\n");
        foreach(i in choices)
        {
            write(" %^GREEN%^%^BOLD%^" + capitalize(i));
        }

        if (function_exists("hint_" + ROLL_CHAIN[head], TO)) {
            call_other(TO, "hint_" + ROLL_CHAIN[head]);
        }

        if (function_exists("synopsis_" + ROLL_CHAIN[head], TO)) {
            call_other(TO, "synopsis_" + ROLL_CHAIN[head]);
            return;
        }

        write("\n%^BOLD%^%^WHITE%^To review all your choices and view your current character sheet use %^ORANGE%^<sheet>%^WHITE%^.");
        write("%^BOLD%^%^WHITE%^To choose type %^ORANGE%^<select %^ULINE%^OPTION%^RESET%^%^ORANGE%^%^BOLD%^>%^WHITE%^, for example. %^ORANGE%^<select " + choices[0] + ">%^WHITE%^.\n");
        write("%^BOLD%^%^WHITE%^You may also %^ORANGE%^<select random>%^WHITE%^ to select a random value.");
        write("%^BOLD%^%^WHITE%^To view current character sheet type %^ORANGE%^<sheet>%^WHITE%^.");
        write("%^BOLD%^%^WHITE%^To return to any previvous stage type %^ORANGE%^<reset STAGENAME>%^WHITE%^. For example, %^ORANGE%^<reset race>%^WHITE%^ will return you to race selection.");

    } else if (sizeof(choices) == 1) {
        select_common(choices[0]);
        advance_head();
    } else {
        advance_head();
    }
}

reset_common(string str)
{
    int i, rstpos;

    if (member_array(str, ROLL_CHAIN) == -1) {
        write("%^BOLD%^%^RED%^You cant reset that.");
        write("%^BOLD%^%^WHITE%^Valid options to reset are: %^CYAN%^" + replace_string(implode(ROLL_CHAIN, "%^WHITE%^, %^CYAN%^"), "_", " "));
        return 1;
    }

    str = replace_string(str, " ", "_");
    str = lower_case(str);

    rstpos = member_array(str, ROLL_CHAIN);

    if (head < rstpos) {
        write("%^BOLD%^%^RED%^You haven't yet selected %^CYAN%^" + str + "%^RED%^.");
        return 1;
    }

    for (i = head; i > rstpos; i-- ) {
        map_delete(char_sheet, ROLL_CHAIN[i - 1]);
    }
    head = i;
    cache = ([]);

    _review();
}



// MODULES

string *generate_class()
{
    string * choices;

    choices = get_dir("/std/class/*.c");
    choices = map(choices, (:replace_string($1, ".c", ""):));
    choices = filter_array(choices, (:!("/std/class/" + $1)->is_prestige_class():));
    choices = filter_array(choices, (:!("/std/class/" + $1)->is_locked_class():));

    return choices;
}

hint_class()
{
    write("
%^BOLD%^Your character class defines core of your game play and responds to what your character does as an adventurer. Different classes have different mechanics and can behave very unlike others. Difficulty of your game play will depend on your class, so if you're unsure what to pick, it is highly recommended no to select caster classes for your first time on the ShadowGate.

%^BOLD%^To overview all available classes look at %^ORANGE%^<help classes>%^WHITE%^.
%^BOLD%^To see what embodies class of your choice see %^ORANGE%^<help %^ULINE%^CLASSNAME%^RESET%^%^ORANGE%^%^BOLD%^>%^WHITE%^, for example %^ORANGE%^<help fighter>%^RESET%^.");
}

string *generate_gender()
{
    return ({"male", "female", "other"});
}

hint_gender()
{
    write("
%^BOLD%^Gender defines how game will reference you in messages and which races are available to you. For example, %^CYAN%^Dryads%^WHITE%^ can be only %^CYAN%^females%^WHITE%^, while %^CYAN%^Satyrs%^WHITE%^ only %^CYAN%^males%^WHITE%^.

%^BOLD%^%^CYAN%^ Male%^WHITE%^ will be referenced to as %^CYAN%^he%^WHITE%^.
%^BOLD%^%^CYAN%^ Female%^WHITE%^ will be referenced to as %^CYAN%^she%^WHITE%^.
%^BOLD%^%^CYAN%^ Other%^WHITE%^ will be referenced to as %^CYAN%^they%^WHITE%^.");
}

string *generate_race()
{
    string * choices;

    choices = get_dir("/std/races/*.c");
    choices = map(choices, (:replace_string($1, ".c", ""):));
    choices = filter_array(choices, (:!(("/std/races/" + $1)->is_gender_locked(char_sheet["gender"])):));
    choices = filter_array(choices, (:sizeof(({1, 2, 3, 4, 5, 6, 7, 8, 9}) - (("/std/races/" + $1)->restricted_alignments(char_sheet["subrace"]) + ("/std/class/" + $2)->restricted_alignments())) :), char_sheet["class"]);

    if (!unrestricted_player(ETO)) {
        choices = filter_array(choices, (:!(("/std/races/") + $1)->is_restricted():));
    }

    choices = filter_array(choices, (:(("/std/races/") + $1)->is_rollable():));

    {
        string choice;
        string subrace, *subraces;
        string restricted_classes;

        foreach(choice in choices) {
            subraces = ("/std/races/" + choice)->query_subraces(ETO);
            subraces = subraces ? subraces : ({""});
            foreach(subrace in subraces) {
                restricted_classes = ("/std/races/" + choice)->restricted_classes(subrace);

                if (member_array(char_sheet["class"], restricted_classes) != -1) {
                    subraces -= ({subrace});
                }

                if (!sizeof(subraces)) {
                    choices -= ({choice});
                }

            }
        }
    }


    return choices;
}

hint_race()
{
    write("
%^BOLD%^Some races are predisposed to being stronger, sturdier, more intelligent, more sensitive to light, etc. than other races. In addition, different races are physically different from others, having different limbs and other types of body parts. Some races are better suited to be magical classes, others prefer physical approach. Whatever choice you make, remember that how other characters will treat you will depend on your race. If you're unsure, pick %^CYAN%^human%^WHITE%^ or %^CYAN%^elf%^WHITE%^ for your first character.

%^BOLD%^To overview all available races look at %^ORANGE%^<help races>%^WHITE%^.
%^BOLD%^To see what embodies race of your choice see %^ORANGE%^<help %^ULINE%^RACENAME%^RESET%^%^ORANGE%^%^BOLD%^>%^WHITE%^, for example %^ORANGE%^<help human>%^RESET%^.");
}

string *generate_subrace()
{
    string * choices = ({});

    choices = ("/std/races/" + char_sheet["race"])->query_subraces(ETO);
    if (sizeof(choices)) {
        choices = filter_array(choices, (:
                                member_array($2, ("/std/races/" + char_sheet["race"])->restricted_classes($1)) == -1
                                :), char_sheet["class"]);
    }

    return choices;
}

hint_subrace()
{
    write("
%^BOLD%^Your subrace is your ethnicity and this choice will be usually less consequential than race. Some races, such as %^CYAN%^saurians%^WHITE%^ have ethnicities that impact your gameplay severely. Some subraces, such as %^CYAN%^tiefling%^WHITE%^ or %^CYAN%^fey'ri%^WHITE%^ may be treated very unlike their parent race.

%^BOLD%^To see more details, refer to your race's helpfile, for example, %^ORANGE%^<help " + char_sheet["race"] + ">%^WHITE%^.");
}

string *generate_template()
{
    string * choices = ({});

    // Ths one is hard to read but not impossible, it is copypaste from old chargen.

    // To read it start from outer functions.

    if(unrestricted_player(ETO))
    {
        choices = map(filter_array(map(get_dir("/std/acquired_template/*.c"),(:"/std/acquired_template/" + $1:)), (:member_array($2, arrayp($1->races_allowed()) ? $1->races_allowed() : ({$2})) != -1:), char_sheet["race"]), (: replace_string(replace_string($1, "/std/acquired_template/", ""), ".c", "") :));
    }

    choices = filter_array(choices, (:(("/std/acquired_template/") + $1)->is_rollable():));

    choices += ({"none"});
    choices = distinct_array(choices);

    return choices;
}

hint_template()
{
    write("
%^BOLD%^Your template will define additional flavor of your game play. You already should know what to do if you're here. If you're unsure, choose %^CYAN%^none%^WHITE%^.");
}

display_stats()
{
    string i;
    int sum = 0;
    mapping race_stats = ([]);

    int tadjust;

    if (!mapp(char_sheet["stats"])) {
        char_sheet["stats"] = ([
                                   "strength":6,
                                   "dexterity":6,
                                   "constitution":6,
                                   "intelligence":6,
                                   "wisdom":6,
                                   "charisma":6,
                                   ]);

        add_action("_reroll_stats", "reroll");
        add_action("_add_stats", "add");
        add_action("_recommended_stats", "recommended");
        add_action("_done_stats", "done");
    }

    if (!sizeof(cache["minstats"])) {
        mapping tmpl_stats = ([]);

        if (char_sheet["template"]) {
            tmpl_stats = ("/std/acquired_template/" + char_sheet["template"])->stat_requirements();
        }

        cache["minstats"] = ("/std/class/" + char_sheet["class"])->stat_requirements();
        if (sizeof(tmpl_stats)) {
            foreach(i in keys(tmpl_stats)) {
                cache["minstats"][i] = max(({tmpl_stats[i], cache["minstats"][i]}));
            }
        }
        char_sheet["stats"] += cache["minstats"];
    }

    {
        race_stats["strength"] = ("/std/races/" + char_sheet["race"])->stat_mods(char_sheet["subrace"])[0];
        race_stats["dexterity"] = ("/std/races/" + char_sheet["race"])->stat_mods(char_sheet["subrace"])[1];
        race_stats["constitution"] = ("/std/races/" + char_sheet["race"])->stat_mods(char_sheet["subrace"])[2];
        race_stats["intelligence"] = ("/std/races/" + char_sheet["race"])->stat_mods(char_sheet["subrace"])[3];
        race_stats["wisdom"] = ("/std/races/" + char_sheet["race"])->stat_mods(char_sheet["subrace"])[4];
        race_stats["charisma"] = ("/std/races/" + char_sheet["race"])->stat_mods(char_sheet["subrace"])[5];
    }

    write("%^RESET%^--==%^BOLD%^< %^GREEN%^You must now assign your %^CYAN%^character stats %^WHITE%^>%^RESET%^==--\n");

    if (char_sheet["stat_mod"]) {
        race_stats[STATS[char_sheet["stat_mod"]]] += 2;
    }

    foreach(i in STATS) {

        tadjust = race_stats[i];
        tadjust += age_to_adjust(char_sheet["age"], i, char_sheet["race"]);


        if (i == "constitution" &&
            (char_sheet["template"] == "undead" || char_sheet["template"] == "vampire")) {
            write("%^BOLD%^%^GREEN%^ " + arrange_string(capitalize(i) + " ", 12) + "%^BOLD%^%^BLACK%^ : %^BLACK%^--");
        } else {
            write("%^BOLD%^%^GREEN%^ " + arrange_string(capitalize(i) + " ", 12) + "%^BOLD%^%^BLACK%^ : %^WHITE%^" + sprintf("%2s", "" + char_sheet["stats"][i]) + (tadjust ? ((tadjust > 0 ? "%^BOLD%^%^CYAN%^ +" : "%^BOLD%^%^RED%^ -") + abs(tadjust)) + " %^ORANGE%^" + (char_sheet["stats"][i] + tadjust) : ""));
        }

        sum += char_sheet["stats"][i];
    }

    write("\n");
    write("%^BOLD%^%^GREEN%^Your stats are displayed with %^WHITE%^no modifications%^GREEN%^, %^CYAN%^adjust%^RED%^ments%^GREEN%^ and %^ORANGE%^final%^GREEN%^ values.");
    if (92 - sum == 0) {
        write("%^BOLD%^%^GREEN%^You may proceed with %^ORANGE%^<done>%^GREEN%^ to the next step.");
    } else {
        write("%^BOLD%^%^GREEN%^You have %^CYAN%^" + (92 - sum) + "%^GREEN%^ points left to assign.");

    }

    synopsis_stats();

}

synopsis_stats()
{

    write("
%^BOLD%^Your stats define your physical and mental abilities, they are adjusted by your race, subrace, age and template. To see in-dept explanation of each stat, type in %^ORANGE%^<help %^ULINE%^STAT%^%^RESET%^%^ORANGE%^%^BOLD%^>%^WHITE%^, for example %^ORANGE%^<help charisma>%^WHITE%^.

%^BOLD%^%^Your race and age has some effect on your stats. After your selections, values right of the stats will be added or subtracted from choices you have made.

%^BOLD%^If you're here for the first time it is highly recommended you select %^ORANGE%^<recommended>%^WHITE%^ option here.");

    write("
%^BOLD%^%^WHITE%^Use %^ORANGE%^<review>%^RESET%^%^BOLD%^ to view your current stats.
%^BOLD%^%^WHITE%^Use %^ORANGE%^<recommended>%^RESET%^%^BOLD%^ to set your stats to recommended value.
%^BOLD%^%^WHITE%^Use %^ORANGE%^<add %^ORANGE%^%^ULINE%^NUM%^RESET%^%^BOLD%^%^ORANGE%^ to %^ORANGE%^%^ULINE%^STAT%^RESET%^%^BOLD%^%^ORANGE%^>%^RESET%^%^BOLD%^ to increase your stat.
%^BOLD%^%^WHITE%^Use %^ORANGE%^<reroll>%^RESET%^%^BOLD%^ to start over.

%^BOLD%^%^WHITE%^Type %^ORANGE%^<done>%^RESET%^%^BOLD%^ when you're done with your selection.
");
}

_done_stats()
{
    string i;
    int sum = 0;

    foreach(i in STATS) {
        sum += char_sheet["stats"][i];
    }

    if (sum != 92) {
        write("
%^BOLD%^%^GREEN%^You have %^CYAN%^" + (92 - sum) + "%^GREEN%^ points left to assign.
%^BOLD%^%^WHITE%^You should assign them to continue.
");
        return 1;
    }

    remove_action("_reroll_stats", "reroll");
    remove_action("_add_stats", "add");
    remove_action("_recommended_stats", "recommended");
    remove_action("_done_stats", "done");

    advance_head();

    return 1;
}

_reroll_stats()
{
    map_delete(cache, "minstats");
    map_delete(char_sheet, "stats");
    display_stats();
    return 1;
}

_recommended_stats()
{
    string i;

    mapping temp_stats = char_sheet["stats"];

    if (char_sheet["template"]) {
        if (sizeof(cache["minstats"]) && sizeof(("/std/acquired_template/" + char_sheet["template"])->stat_requirements())) {
            write("%^BOLD%^%^RED%^You can't use stat recommendations while having stat restrictions imposed by a template. You're on your own.");
            return 0;
        }
    }

    foreach(i in STATS) {
        temp_stats[i] = RECOMMENDED_STATS[char_sheet["class"]][i];
    }

    char_sheet["stats"] = temp_stats;

    display_stats();
    return 1;
}

_add_stats(string str){
    int amount;
    string stat;

    string i;
    int sum = 0;

    if (!str) {
        display_stats();
        return 1;
    }

    if (sscanf(str, "%d to %s", amount, stat) != 2) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^Syntax is %^ORANGE%^<add %^ULINE%^NUMBER%^RESET%^%^BOLD%^%^ORANGE%^ to %^ULINE%^STAT%^RESET%^%^BOLD%^%^ORANGE%^>%^RESET%^, e.g. %^BOLD%^%^ORANGE%^<add 10 to intelligence>%^RESET%^%^WHITE.");
        return 1;
    }

    foreach(i in STATS) {
        sum += char_sheet["stats"][i];
    }

    if (amount > (92 - sum)) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You have only %^CYAN%^" + (92 - sum) + "%^RESET%^%^WHITE%^ points left to apply.");
        return 1;
    }

    if (stat == "str") {
        stat = "strength";
    }
    if (stat == "int") {
        stat = "intelligence";
    }
    if (stat == "dex") {
        stat = "dexterity";
    }
    if (stat == "con") {
        stat = "constitution";
    }
    if (stat == "cha") {
        stat = "charisma";
    }
    if (stat == "wis") {
        stat = "wisdom";
    }

    if (char_sheet["stats"][stat] + amount > 18) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^That score will exceed maximum allowed at start %^CYAN%^18%^WHITE%^.");
        return 1;
    }

    if (char_sheet["stats"][stat] + amount < 4) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^That score will be lower than minimum allowed at start %^CYAN%^4%^WHITE%^.");
        return 1;
    }

    if (cache["minstats"][stat]) {
        if (char_sheet["stats"][stat] + amount < cache["minstats"][stat]) {
            tell_object(ETO,"%^BOLD%^%^WHITE%^That score will be lower than minimum allowed for " +stat+" %^CYAN%^" +cache["minstats"][stat]+"%^WHITE%^ at your class and template combination.");
            return 1;
        }
    }

    char_sheet["stats"][stat] += amount;

    display_stats();
    return 1;
}

select_stats(string str)
{

    write("%^BOLD%^%^WHITE%^You must now set your %^CYAN%^stat points.\n");

    synopsis_stats();
    return 0;
}

display_height()
{
    synopsis_height();
}

select_height(string str)
{
    int amount;

    string racefile = "/std/races/" + char_sheet["race"];

    int minh = racefile->height_base(char_sheet["gender"]);
    int maxh = minh + racefile->height_mod(char_sheet["gender"]);

    if (str == "random") {
        amount = minh + random(maxh - minh);
    } else {
        if (sscanf(str, "%d", amount) != 1) {
            write("%^BOLD%^%^RED%^You have to enter a number.");
            return 0;
        }

        if (amount > maxh || amount < minh) {
            write("%^BOLD%^%^RED%^Your height must be within allowed range.");
            return 0;
        }
    }

    char_sheet["height"] = amount;
    write("%^BOLD%^%^WHITE%^You have selected %^CYAN%^" + amount + "%^WHITE%^ for your %^CYAN%^" + replace_string(ROLL_CHAIN[head], "_", " ") + "%^WHITE%^.");
    return 1;
}

synopsis_height()
{
    string racefile = "/std/races/" + char_sheet["race"];

    int minh = racefile->height_base(char_sheet["gender"]);
    int maxh = minh + racefile->height_mod(char_sheet["gender"]);

    write("%^RESET%^--==%^BOLD%^< %^GREEN%^You must now assign your %^CYAN%^height %^WHITE%^>%^RESET%^==--\n");

    write("%^BOLD%^%^WHITE%^Choose height for your character, anywhere between %^CYAN%^" + minh + "%^WHITE%^ and %^CYAN%^" + maxh + "%^WHITE%^.");
    write("%^BOLD%^%^WHITE%^Enter your %^CYAN%^height%^WHITE%^ in %^CYAN%^inches%^WHITE%^.\n");
    write("%^BOLD%^%^WHITE%^Use %^BOLD%^%^ORANGE%^<select %^ULINE%^NUMBER%^RESET%^%^BOLD%^%^ORANGE%^>%^WHITE%^. For example, %^ORANGE%^<select " + minh + ">%^WHITE%^.\n");
    write("%^BOLD%^%^WHITE%^You can also select a random value with %^ORANGE%^<select random>%^WHITE%^.");
    write("\n");
}

display_weight()
{
    synopsis_weight();
}

select_weight(string str)
{
    int amount;

    string racefile = "/std/races/" + char_sheet["race"];

    int minh = racefile->weight_base(char_sheet["gender"]);
    int maxh = minh + racefile->weight_mod(char_sheet["gender"]);

    if (str == "random") {
        amount = minh + random(maxh - minh);
    } else {
        if (sscanf(str, "%d", amount) != 1) {
            write("%^BOLD%^%^RED%^You have to enter a number.");
            return 0;
        }

        if (amount > maxh || amount < minh) {
            write("%^BOLD%^%^RED%^Your height must be within allowed range.");
            return 0;
        }
    }

    char_sheet["weight"] = amount;
    write("%^BOLD%^%^WHITE%^You have selected %^CYAN%^" + amount + "%^WHITE%^ for your %^CYAN%^" + replace_string(ROLL_CHAIN[head], "_", " ") + "%^WHITE%^.");
    return 1;
}

synopsis_weight()
{
    string racefile = "/std/races/" + char_sheet["race"];

    int minh = racefile->weight_base(char_sheet["gender"]);
    int maxh = minh + racefile->weight_mod(char_sheet["gender"]);

    write("%^RESET%^--==%^BOLD%^< %^GREEN%^You must now assign your %^CYAN%^weight %^WHITE%^>%^RESET%^==--\n");

    write("%^BOLD%^%^WHITE%^Choose weight for your character, anywhere between %^CYAN%^" + minh + "%^WHITE%^ and %^CYAN%^" + maxh + "%^WHITE%^.");
    write("%^BOLD%^%^WHITE%^Enter your %^CYAN%^weight%^WHITE%^ in %^CYAN%^pounds%^WHITE%^.\n");
    write("%^BOLD%^%^WHITE%^Use %^BOLD%^%^ORANGE%^<select %^ULINE%^NUMBER%^RESET%^%^BOLD%^%^ORANGE%^>%^WHITE%^. For example, %^ORANGE%^<select " + minh + ">%^WHITE%^.\n");
    write("%^BOLD%^%^WHITE%^You can also select a random value with %^ORANGE%^<select random>%^WHITE%^.");
    write("\n");
}

string *generate_body_type()
{
    return ({"frail", "skinny", "slender", "svelte", "hardy", "portly", "heavy"});
}

string *generate_hair_color()
{
    return ("/std/races/" + char_sheet["race"])->query_hair_colors(char_sheet["subrace"]);
}

string *generate_eye_color()
{
    return ("/std/races/" + char_sheet["race"])->query_eye_colors(char_sheet["subrace"]);
}

display_age()
{
    synopsis_age();
}

select_age(string str)
{
    int amount;
    int *age_brackets;

    string racefile = "/std/races/" + char_sheet["race"];
    string templatefile;

    if (char_sheet["template"]) {
        templatefile = "/std/acquired_template/" + char_sheet["template"];
    }

    age_brackets = racefile->age_brackets();

    if (str == "random") {
        amount = age_brackets[0] + random(age_brackets[3] * 12 / 10 - age_brackets[0]);
    } else {
        if (sscanf(str, "%d", amount) != 1) {
            write("%^BOLD%^%^RED%^You have to enter a number.");
            return 0;
        }

        if (amount < age_brackets[0]) {
            write("%^BOLD%^%^RED%^Your can't be that young.");
            return 0;
        }

        if (templatefile) {
            if (!templatefile->query_unbound_age()) {
                if (!racefile->query_unbound_age()) {
                    if (amount > age_brackets[3] * 12 / 10) {
                        write("%^BOLD%^%^RED%^Your can't be that old. Maximum allowed age for your race and template is %^CYAN%^" + age_brackets[3] * 12 / 10 + "%^RED%^.");
                        return 0;
                    }
                }
            }
        }
    }

    char_sheet["age"] = amount;
    return 1;
}

synopsis_age()
{
    string racefile = "/std/races/" + char_sheet["race"];

    int *age_brackets;

    age_brackets = racefile->age_brackets();

    write("%^RESET%^--==%^BOLD%^< %^GREEN%^You must now assign your %^CYAN%^age %^WHITE%^>%^RESET%^==--\n");
    write("%^BOLD%^%^WHITE%^Values between %^GREEN%^" + age_brackets[0] + "%^WHITE%^ and %^GREEN%^" + age_brackets[1] + "%^WHITE%^ will make you of %^CYAN%^normal%^WHITE%^ age.");
    write("%^BOLD%^%^WHITE%^Values between %^GREEN%^" + age_brackets[1] + "%^WHITE%^ and %^GREEN%^" + age_brackets[2] + "%^WHITE%^ will make you %^CYAN%^middle%^WHITE%^ aged.");
    write("%^BOLD%^%^WHITE%^Values between %^GREEN%^" + age_brackets[2] + "%^WHITE%^ and %^GREEN%^" + age_brackets[3] + "%^WHITE%^ will make you %^CYAN%^old%^WHITE%^.");
    write("%^BOLD%^%^WHITE%^Values above %^GREEN%^" + age_brackets[3] + "%^WHITE%^ will make you %^CYAN%^venerable%^WHITE%^.");

    write("\n%^BOLD%^Your age will have impact on your stats. Refer to %^ORANGE%^<help age>%^WHITE%^ for details.");

    write("\n%^BOLD%^%^WHITE%^Enter your %^CYAN%^age%^WHITE%^ in %^CYAN%^years%^WHITE%^.\n");
    write("%^BOLD%^%^WHITE%^Use %^BOLD%^%^ORANGE%^<select %^ULINE%^NUMBER%^RESET%^%^BOLD%^%^ORANGE%^>%^WHITE%^. E.g. %^ORANGE%^<select " + (age_brackets[0] + random(age_brackets[1] - age_brackets[0]))+ ">%^WHITE%^.\n");
    write("%^BOLD%^%^WHITE%^You may also %^ORANGE%^<select random>%^WHITE%^ to select a random age.");
}

string *generate_stat_mod()
{
    if (("/std/races/" + char_sheet["race"])->is_statmod_race(char_sheet["subrace"])) {
        return STATS;
    } else {
        return;
    }
}

select_stat_mod(string str)
{
    int smod;

    str = lower_case(str);

    switch (str) {
    case "strength":case "str":
        smod = 0;
        break;
    case "dexterity":case "dex":
        smod = 1;
        break;
    case "constitution":case "con":
        smod = 2;
        break;
    case "intelligence":case "int":
        smod = 3;
        break;
    case "wisdom":case "wis":
        smod = 4;
        break;
    case "charisma":case "cha":
        smod = 5;
        break;
    }

    if (str == "random") {
        smod = random(6);
    }

    if (!undefinedp(smod) && smod > -1 && smod < 6) {
        char_sheet["stat_mod"] = smod;
        return 1;
    } else {
        return 0;
    }
}

hint_stat_mod()
{
    write("
%^BOLD%^Your race allows flexible stat modifier, so you can freely assign stat you desire to have an increased value. It will receive then a modification to %^CYAN%^+2%^WHITE%^ in value.");
}

string *generate_alignment()
{
    string racefile = "/std/races/" + char_sheet["race"];
    string classfile = "/std/class/" + char_sheet["class"];

    int *alignments = ({1, 2, 3, 4, 5, 6, 7, 8, 9});

    string * choices;

    alignments -= racefile->restricted_alignments(char_sheet["subrace"]);
    alignments -= classfile->restricted_alignments();

    choices = map_array(alignments, (: $2->align_to_string($1) :), TO);

    return choices;
}

hint_alignment()
{
    write("
%^BOLD%^Many ages of arguing have been dedicated to this selection. In the end, your alignment determines your disposition to the law and actions you tend to take. It also restricts %^CYAN%^deities%^WHITE%^ you will be able to select later, and for some classes it restricts %^CYAN%^class special%^WHITE%^ choices.%^WHITE%^.

%^BOLD%^Refer to %^ORANGE%^<help alignments>%^WHITE%^ if you want to know more about alignments on ShadowGate.");
}

string *generate_deity()
{
    string * choices = ({});

    if (char_sheet["class"] == "cleric" ||
        char_sheet["class"] == "inquisitor") {
        choices = filter_array(keys(DIETIES), (:member_array($2, DIETIES[$1][2]) != -1:), str_to_align(char_sheet["alignment"]));
    } else {
        choices = filter_array(keys(DIETIES), (:member_array($2, DIETIES[$1][1]) != -1:), str_to_align(char_sheet["alignment"])) + ({"godless"});
        if (char_sheet["class"] == "paladin") {
            choices = choices - (choices - PALADIN_GODS);
        }
    }

    return choices;
}

display_deity()
{
    string * choices = generate_deity();
    string i;

    write("%^RESET%^--==%^BOLD%^< %^GREEN%^You must now assign your %^CYAN%^deity %^WHITE%^>%^RESET%^==--\n");

    foreach(i in choices)
    {
        write(" %^GREEN%^%^BOLD%^" + implode(map(explode(i, " "), (:capitalize($1):)), " "));
    }

    write("
%^BOLD%^%^WHITE%^To choose type %^ORANGE%^<select %^ULINE%^OPTION%^RESET%^%^ORANGE%^%^BOLD%^>%^WHITE%^, for example %^ORANGE%^<select " + choices[0] + ">%^WHITE%^.");

    hint_deity();
}

hint_deity()
{
    write("
%^BOLD%^You're about to select divine power to follow. If you're a %^CYAN%^cleric%^WHITE%^, %^CYAN%^paladin%^WHITE%^ or otherwise divine engaged character, it is highly recommended you read deity help file prior to selection.%^WHITE%^.

%^BOLD%^Refer to %^ORANGE%^<help deities>%^WHITE%^ to overview selection.");
}


string *generate_class_special()
{
    return ("/std/class/" + char_sheet["class"])->query_newbie_stuff(str_to_align(char_sheet["alignment"]));
}

hint_class_special()
{
    write("
%^BOLD%^This choice determines additional mechanics for your class. Refer to %^ORANGE%^<help " + char_sheet["class"] + ">%^WHITE%^ for details.");
}

string* generate_language()
{
    int maxbonus = (char_sheet["stats"]["intelligence"] - 10) / 4 + 1;
    string* choices = ({}), tmp;

    if (maxbonus > 0) {
        if (arrayp(tmp = ("/std/races/" + char_sheet["race"])->query_languages(char_sheet["subrace"])["optional"])) {
            choices += tmp;
        }
        if (arrayp(tmp = (("/std/class/" + char_sheet["class"])->query_bonus_languages()))) {
            choices += tmp;
        }
    }

    choices = distinct_array(choices);

    return choices;
}

select_language(string str)
{
    string * prospective;
    string * tmp;
    string * toselect;
    string tlang;
    int maxbonus = (char_sheet["stats"]["intelligence"] - 10) / 4 + 1;
    int i;

    prospective = (("/std/races/" + char_sheet["race"])->query_languages(char_sheet["subrace"]))["optional"];

    if (str == "random") {
        i = maxbonus;
        toselect = ({});
        while(i)
        {
            tlang = prospective[random(sizeof(prospective))];
            toselect += ({tlang});
            prospective -= ({tlang});
            i--;
        }
    } else {

        toselect = explode(str, " ");

        if (!sizeof(toselect)) {
            write("%^BOLD%^%^WHITE%^Enter space separated list of languages. You can select up to %^CYAN%^" + maxbonus + "%^WHITE%^ languages.");
            return 0;
        }

        if (sizeof(tmp = (toselect - prospective))) {
            write("%^BOLD%^%^WHITE%^You can't select one of the languages you have entered: %^CYAN%^" + implode(tmp, "%^WHITE%^, %^CYAN%^"));
            return 0;
        }

        if (sizeof(toselect) > maxbonus) {
            write("%^BOLD%^%^WHITE%^You can't select that many languages.");
            return 0;
        }


    }

    char_sheet[ROLL_CHAIN[head]] = toselect;

    write("%^BOLD%^%^WHITE%^You have selected %^CYAN%^" + implode(toselect, "%^WHITE%^, %^CYAN%^") + "%^WHITE%^ for your %^CYAN%^" + replace_string(ROLL_CHAIN[head], "_", " ") + "%^WHITE%^.");
    return 1;
}

synopsis_language()
{
    int maxbonus = (char_sheet["stats"]["intelligence"] - 10) / 4 + 1;
    string * choices = generate_language();

    if (maxbonus > 1) {
        write("
%^BOLD%^%^WHITE%^You can select up to %^CYAN%^" + maxbonus + "%^WHITE%^ as your bonus languages. To select them enter them separated by space, for example, %^ORANGE%^<select %^ULINE%^" + choices[0] + "%^RESET%^ %^BOLD%^%^ORANGE%^ULINE%^" + choices[1] + "%^RESET%^%^ORANGE%^%^BOLD%^>%^WHITE%^.");
    } else {
        write("
%^BOLD%^%^WHITE%^To choose type %^ORANGE%^<select %^ULINE%^OPTION%^RESET%^%^ORANGE%^%^BOLD%^>%^WHITE%^, for example. %^ORANGE%^<select " + choices[0] + ">%^WHITE%^.");

    }
    write("");
    write("%^BOLD%^%^WHITE%^You may also %^ORANGE%^<select random>%^WHITE%^ to select random languages.");
}

build_class()
{
    ETO->set_class(char_sheet["class"], 1);
    ETO->set_guild_level(char_sheet["class"], 1);
    ETO->set_mlevel(char_sheet["class"], 1);
    ETO->new_body();
    ETO->set_max_mp(0);
    ETO->set_mp(0);
    ETO->set_hp(20);
    ETO->init_spellcaster();
    ETO->add_exp(1);

    ETO->set("active_class", char_sheet["class"]);
    ETO->set("new_class_type", 1);
    ETO->set_posed(char_sheet["class"]);

    ADVANCE_D->advance(TP,char_sheet["class"]);
}

build_gender()
{
    ETO->set_gender(char_sheet["gender"]);
}

build_race()
{
    ETO->set_race(char_sheet["race"]);
    ETO->init_lang();
}

build_subrace()
{
    ETO->set("subrace", char_sheet["subrace"]);
}

build_template()
{
    ("/std/acquired_template/" + char_sheet["template"])->apply_template(ETO);
}

build_age()
{
    ETO->set_start_age(char_sheet["age"]);
}

build_stat_mod()
{
    ETO->set("stat_mod", char_sheet["stat_mod"]);
}

build_stats()
{
    string i;

    foreach(i in STATS) {
        ETO->set_stats(i, char_sheet["stats"][i]);
    }
}

build_height()
{
    ETO->set_player_height(char_sheet["height"]);
}

build_weight()
{
    ETO->set_player_weight(char_sheet["weight"]);
}

build_body_type()
{
    ETO->set_body_type(char_sheet["body_type"]);
}

build_hair_color()
{
    ETO->set_hair_color(char_sheet["hair_color"]);
}

build_eye_color()
{
    ETO->set_eye_color(char_sheet["eye_color"]);
}

/**
 * Builds BONUS languages.
 */
build_language()
{
    string i;
    foreach(i in char_sheet["language"]) {
        ETO->set_lang(i, 100);
    }
}

build_alignment()
{
    ETO->set_alignment(str_to_align(char_sheet["alignment"]));
}

build_deity()
{

    ETO->set_diety(char_sheet["deity"]);
    if (char_sheet["deity"] != "godless") {

        object ob        ;

        ob = new("/d/magic/symbols/holy_symbol.c");
        ob->set_short("The holy symbol of "+capitalize(char_sheet["deity"]));
        ob->move(ETO);
        ob->save(ETOQCN);
    }
}

build_class_special()
{
    ("/std/class/" + char_sheet["class"])->process_newbie_choice(ETO, char_sheet["class_special"]);
}

// Modules end here

string align_to_string(int x)
{
    string * aligarr = ({
                            "lawful good",
                            "lawful neutral",
                            "lawful evil",
                            "neutral good",
                            "true neutral",
                            "neutral evil",
                            "chaotic good",
                            "chaotic neutral",
                            "chaotic evil",
                                });
    if (x > 9 || x < 1) {
        return "";
    }

    return aligarr[x - 1];
}

int str_to_align(string x)
{
    string * aligarr = ({
            "lawful good",
                "lawful neutral",
                "lawful evil",
                "neutral good",
                "true neutral",
                "neutral evil",
                "chaotic good",
                "chaotic neutral",
                "chaotic evil",
                });
    return member_array(x, aligarr) + 1;
}

int age_to_adjust(int age, string stat, string race)
{

    string racefile = "/std/races/" + char_sheet["race"];

    int *base = ({0, 0, 0, 0, 0, 0});

    int *age_brackets = racefile->age_brackets();

    if (char_sheet["template"] == "undead" ||
        char_sheet["template"] == "vampire") {
        return 0;
    }

    if(age > age_brackets[3])
    {
        base = ({ -3, -3, -3, 3, 3, 3});
    } else if (age > age_brackets[2]) {
        base = ({ -2, -2, -2, 2, 2, 2});
    } else if (age > age_brackets[1]) {
        base = ({ -1, -1, -1, 1, 1, 1});
    }

    switch (stat) {
    case "strength":
        return base[0];
        break;
    case "dexterity":
        return base[1];
        break;
    case "constitution":
        return base[2];
        break;
    case "intelligence":
        return base[3];
        break;
    case "wisdom":
        return base[4];
        break;
    case "charisma":
        return base[5];
        break;
    default:
        return 0;
        break;
    }

}

int unrestricted_player(object plr)
{
    return OB_ACCOUNT->is_experienced(ETO->query_true_name()) || OB_ACCOUNT->is_high_mortal(ETO->query_true_name()) || avatarp(ETO) || ETO->query("unrestricted_creation");
}
