// updating to allow for pre-built lists that will prepare automatically
// to make life easier for casters who have to prepare spells ahead of time -Ares
#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <dirs.h>
inherit DAEMON;

// stealing from the recall spells command -Ares
#define LEV_AND_COLORS ([ 1 : "%^BOLD%^%^BLACK%^", 2 : "%^RED%^", 3 : "%^GREEN%^", 4 : "%^MAGENTA%^", 5 : "%^CYAN%^", 6 : "%^BOLD%^%^BLUE%^", 7 : "%^BOLD%^%^RED%^", 8 : "%^BOLD%^%^GREEN%^", 9 : "%^BOLD%^%^MAGENTA%^"])

mapping spells;
string *magic;
int wait;

int cmd_prepare(string str)
{
    string args, spellname, myclass, *arguments, *spell = ({}), first_list, second_list, first_class, second_class;
    int i, validfocus, times, sl, cl, rst, lvadj, temp;
    object *inven;

    if(TP->query_bound() || TP->query_unconscious())
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if (TP->query_paralyzed()) { return notify_fail(TP->query_paralyze_message()); }

    if (!str)
    {
        HELP_D->help("prepare");
        return 1;
    }

    if (TP->query_property("berserked")) {
        return notify_fail("The rage in you prevents such concentration!\n");
    }
    if (sizeof(TP->query_attackers()) > 0) {
        return notify_fail("You cannot prepare spells while in combat!\n");
    }
    if (TP->query_property("effect_exhausted") || TP->query_property("effect_fatigued")) {
        return notify_fail("You are fatigued or exhausted and cannot prepare!\n");
    }

    arguments = explode(str," ");

    if (sizeof(arguments))
    {
        switch (arguments[0])
        {
        case "copy":

            if(sizeof(arguments) < 6 || arguments[3] != "to")
            {
                HELP_D->help("prepare");
                return 1;
            }

            first_list = arguments[1];
            second_list = arguments[4];
            if(first_list == second_list)
            {
                return notify_fail("Your lists can't have the same name.");
            }
            first_class = arguments[2];
            second_class = arguments[5];
            if(first_class != second_class)
            {
                return notify_fail("Your class names must be the same");
            }

            copy_list(TP, first_list, second_list, first_class);
            return 1;

        case "add":

            if (sizeof(arguments) < 4)
            {
                HELP_D->help("prepare");
                return 1;
            }

            for (i = 3;i < sizeof(arguments);i++)
            {
                spell += ({ arguments[i] });
            }
            add_spell_to_list(TP, implode(spell," "), arguments[1], arguments[2]);
            return 1;

        case "remove":
            if (sizeof(arguments) < 4)
            {
                HELP_D->help("prepare");
                return 1;
            }

            for (i = 3;i < sizeof(arguments);i++)
            {
                spell += ({ arguments[i] });
            }

            remove_spell_from_list(TP, implode(spell," "), arguments[1], arguments[2]);
            return 1;

        case "delete":
            if (sizeof(arguments) != 3)
            {
                HELP_D->help("prepare");
                return 1;
            }
            if(!file_exists(DIR_CLASSES+"/"+arguments[2]+".c"))
            {
                HELP_D->help("prepare");
                return 1;
            }
            delete_list(TP, get_lists(TP), arguments[1]);
            return 1;

        case "list": case "display":
            if (sizeof(arguments) != 3)
            {
                if (sizeof(keys(get_lists(TP))))
                {
                    tell_object(TP, "You currently have the lists: " + implode(keys(get_lists(TP)), ", "));
                }
                HELP_D->help("prepare");
                return 1;
            }
            display_list(TP, arguments[1], arguments[2]);
            return 1;
        case "check":
            if (sizeof(arguments) != 3)
            {
                HELP_D->help("prepare");
                return 1;
            }
            check_list(TP, arguments[1], arguments[2]);
            return 1;
        case "prepare":
            if (sizeof(arguments) != 3)
            {
                HELP_D->help("prepare");
                return 1;
            }
            if(TP->query_property("last_prepare")+ROUND_LENGTH-2>time())
            {
                tell_object(TP,"You can't prepare more than once in a round.");
                return 1;
            }
            TP->remove_property("last_prepare",time());
            TP->set_property("last_prepare",time());
            prepare_listed_spells(TP, arguments[1], arguments[2]);
            return 1;

        default:
            break;

        }
    }

    if (sscanf(str, "%s %s", myclass, args) != 2)
    {
                HELP_D->help("prepare");
                return 1;
    }

    if(!can_prepare_as(myclass))
        return 1;

    if(TP->query_property("last_prepare")+ROUND_LENGTH-2>time())
    {
        tell_object(TP,"You can't prepare more than once in a round.");
        return 1;
    }

    TP->remove_property("last_prepare",time());
    TP->set_property("last_prepare",time());

    if (!TP->is_class(myclass) && !avatarp(TP)) {
        return notify_fail("You cannot cast spells as a " + myclass + "!\n");
    }

    if (myclass == "monk") {
        tell_object(TP, "Monks don't need to prepare spells, please see <help ki>");
        return 1;
    }

    if (myclass == "warlock") {
        tell_object(TP, "Warlocks don't need to prepare spells, just cast");
        return 1;
    }

    validfocus = 0;

    if (myclass == "psywarrior" || myclass == "psion") {
        if (sscanf(str, "%s %s", myclass, args) != 2) {
            return notify_fail("Syntax: <prepare classname points [times x].>\n");
        }
        if (sscanf(args, "%s times %d", spellname, times) != 2) {
            spellname = args;
            times = 1;
            if (spellname != "points") {
                return notify_fail("Syntax: <prepare classname points [times x]>\n");
            }
        }
        prep_power_points(myclass, times);
        return 1;
    }

    spells = ([]);
    magic = ({});
    get_spells(TP,myclass);
    magic = keys(spells);

    if (!sizeof(magic)) { return notify_fail("There are no spells available to the " + myclass + " class!"); }

    if (sscanf(args, "%s times %d", spellname, times) != 2) //multi-memorisation of a spell
    {
        spellname = args;
        times = 1;
    }

    spellname = MAGIC_D->expand_quick_name(spellname);

    if(myclass != "bard" &&
       myclass != "sorcerer" &&
       myclass != "oracle" &&
       myclass != "magus" &&
       myclass != "inquisitor")
    {
        if (member_array(spellname, magic) == -1) { return notify_fail("You don't know of a spell named " + spellname + " to prepare.\n"); }
    }
    else
    {
        if (sscanf(spellname, "level %d", sl) != 1) { return notify_fail("As a spontaneous caster, you need to <prepare myclass level x [times x]>.\n"); }
    }

    if (times < 1) { return notify_fail("You need to memorize " + spellname + " at least once.\n"); }

    if (myclass != "bard" &&
        myclass != "inquisitor" &&
        myclass != "oracle" &&
        myclass != "magus" &&
        myclass != "sorcerer") { sl = spells[spellname]; }

    rst = TP->can_memorize(myclass,spellname);
    if (rst == TOO_MANY)            { return notify_fail("You have prepared all of the spells allowed.\n"); }
    if (rst == SPELL_RESTRICTED)    { return notify_fail("Your use of this spell has been restricted!\n"); }
    if (rst == TOO_STUPID)          { return notify_fail("You do not meet the stat requirement to use that spell.\n"); }
    if (rst != MEM_OK)              { return notify_fail("You cannot prepare that spell.\n"); }

// start mem'ing the spell!
    temp = sl * MEMORIZE_DELAY;

    cl = TP->query_guild_level(myclass);

    if(cl > 9)
    {
	    lvadj = 375/cl; //was lvadj = 1000/cl; lowering for testing - Octothorpe 10/5/17
	    if(!lvadj) lvadj = 1;   // they say dividing by zero is reserved for god...
        {
            temp = temp - ((temp * 10) / lvadj);
        }
        if (!temp) { temp = 1; }
    }

    if(!times) times = 1;
    {
        temp = temp * times;
    }

    if(myclass=="mage")
        if (!spell_in_grimoire(spellname, TP, "mage"))
            return 0;


    switch (myclass)
    {
    case "cleric": case "paladin":

        tell_object(TP, "%^BOLD%^%^GREEN%^You begin praying for the spell of " + spellname + "  (" + times + " attempt(s) - Any action you take will interrupt your praying.)");
        tell_room(ETP, TPQCN + " begins praying for spells.", TP);
        break;

    case "psion":

        tell_object(TP, "%^BOLD%^%^GREEN%^You take your psicrystal in hand and close your eyes, focusing on the mysteries of the power " + str + ".  (" + times + " attempt(s) - Any action you take will interrupt your focusing.)%^RESET%^");
        tell_room(ETP, TPQCN + " takes " + TP->QP + " psicrystal in hand and closes " + TP->QP + " eyes, focusing silently.", TP);
        break;

    case "sorcerer":

        tell_object(TP, "%^BOLD%^%^GREEN%^You turn your focus inwards, harnessing the power to invoke spells of " + str + ".  (" + times + " attempt(s) - Any action you take will interrupt your focusing.)%^RESET%^");
        tell_room(ETP, TPQCN + " turns " + TP->QP + " focus inwards.", TP);
        break;

    default:

        tell_object(TP, "%^BOLD%^%^GREEN%^You focus your thoughts upon preparing the spell of " + spellname + "  (" + times + " attempt(s) - Any action you take will interrupt your preparations....");
        tell_room(ETP, TP->QCN + " bows " + TP->QP + " head and concentrates.", TP);
        break;
    }
    TP->set_property("memorizing",TP);
    TP->prepare(spellname, temp, myclass, times);
    return 1;
}


int get_spells(object player, string myclass)
{
    spells=MAGIC_D->index_castable_spells(player,myclass);
}

int prep_power_points(string myclass, int times)
{
    string args, spellname;
    int i, validfocus, sl, cl, rst, lvadj, temp;

    sl = times;
    if (sl < 1) { sl = 1; }
    temp = sl * MEMORIZE_DELAY;

    cl = TP->query_guild_level(myclass);
    if (cl > 9)
    {
        lvadj = 375/cl; //was lvadj = 1000/cl; lowering for testing - Octothorpe 10/5/17
        if (!lvadj) { lvadj = 1; }   // they say dividing by zero is reserved for god...
        temp = temp - ((temp * 10) / lvadj);
        if (!temp) { temp = 1; }
    }
    if (!times) { times = 1; }
    temp = temp * times;

    tell_object(TP, "%^BOLD%^%^GREEN%^You close "
        "your eyes, focusing on the mysteries of your mind.  ("+times+" attempt(s) - "
        "Any action you take will interrupt your focusing.)%^RESET%^");
    tell_room(ETP, TPQCN+" closes "+TP->QP+" eyes, "
        "focusing silently.", TP);
    TP->set_property("memorizing",TP);

    if(wait < time())
    {
        TP->prepare(spellname, temp, myclass, times);
        wait = time() + 1;
    }

    return 1;
}


void add_spell(string spellname, int lvl)
{
    spellname = replace_string(spellname,"_","",1);
    spellname = replace_string(spellname,".c","",1);
    spellname = replace_string(spellname,"_"," ");
    spells[spellname] = lvl;
}




// make a command to copy one list to another

// stuff for prepared lists below this point -Ares

// returns max amount of spells allowed at level
int max_allowed(object obj, string myclass, int level)
{
    string stat,subrace;
    int max_spells,class_level;

    if (!objectp(obj)) { return 0; }
    if (!obj->is_class(myclass)) { return 0; }

    switch (myclass)
    {
    case "cleric": case "ranger": case "druid": case "inquisitor":

        stat = "wisdom";
        break;

    case "bard": case "sorcerer": case "oracle": case "paladin":

        stat = "charisma";
        break;

    default:
        stat = "intelligence";
        break;
    }

    class_level = obj->query_prestige_level(myclass);
    if(!class_level) { class_level = obj->query_prestige_level(myclass); }
    max_spells = WIZ_CALCS->query_spell_limit(level, class_level, myclass, (int)obj->query_stats(stat));
    max_spells = (int)obj->magic_arsenal_feat(max_spells);
    max_spells = (int)obj->bonus_spell_slots(max_spells);
    max_spells = (int)obj->bonus_spell_slots_by_level(level, max_spells);

    if (level == 1 && ((string)obj->query_race() == "human"))
    {
        subrace = (string)obj->query("subrace");
        if (subrace && (subrace == "senzokuan"))
        {
            max_spells++;
        }
    }

    return max_spells;
}


int num_current_spells(mapping level_list)
{
    string *spells;
    int i, count = 0;
    if (!mapp(level_list) || !sizeof(keys(level_list))) { return 0; }

    spells = keys(level_list);
    if (!sizeof(spells)) { return 0; }

    for (i = 0;i < sizeof(spells);i++)
    {
        count += level_list[spells[i]];
    }

    return count;
}

mapping filter_spells(mapping listed_spells, mapping memorized_spells)
{
    mapping to_add = ([]);
    string *leveled_spells, *leveled_memorized_spells,spell;
    int i,count,add,subtract, spell_level;

    leveled_spells = keys(listed_spells);
    leveled_memorized_spells = keys(memorized_spells);

    if (sizeof(leveled_spells))
    {
        for (i = 0;i < sizeof(leveled_spells);i++)
        {
            add = 0;
            subtract = 0;
            count = 0;

            spell = leveled_spells[i];
            add = listed_spells[spell];

            if(strsrch(spell, "level ") != -1)
            {
                subtract = memorized_spells["generic"];
            }

            else if (member_array(spell, leveled_memorized_spells) != -1)
            {
                subtract = memorized_spells[spell];
                leveled_memorized_spells -= ({ spell });
            }

            count = add - subtract;

            if (count)
            {
                to_add += ([spell:count]);
            }
        }
    }

    if (sizeof(leveled_memorized_spells))
    {
        for (i = 0;i < sizeof(leveled_memorized_spells);i++)
        {
            spell = leveled_memorized_spells[i];
            subtract = memorized_spells[spell];

            count = subtract * -1;
            to_add += ([spell : count]);
        }
    }

    return to_add;
}


// return a mapping of spells to be memorized and forgotten.  Spells that need to be forgotten
// should have negative numbers, spells that need to be memorized have positive numbers
mapping compare_spells(object obj, string list, string myclass)
{
    mapping lists, current_list, level_list, memorized_spells, memorized_level,to_add_or_remove=([]),leveled_add=([]);
    string *leveled_spells, *leveled_memorized_spells;
    int i,*spell_levels,current_spells,max_spells;

    if (!objectp(obj)) { return 0; }
    if (!stringp(list) || list == "" || list == " ") { return 0; }

    lists = get_lists(obj);
    current_list = get_current_list(lists, list);
    memorized_spells = (mapping)obj->query_all_memorized(myclass);

    spell_levels = keys(current_list);

    if (!sizeof(spell_levels))
    {
        tell_object(obj, "No spells currently in your " + list + " list.");
        return 0;
    }

    for (i = 0;i < sizeof(spell_levels);i++)
    {
        level_list = get_level_list(spell_levels[i], current_list);
        current_spells = num_current_spells(level_list);
        max_spells = max_allowed(obj, myclass, spell_levels[i]);
        // needs this check in case they loose levels or spell slots from some other means
        if (current_spells > max_spells)
        {
            tell_object(obj, "You currently have more level " + spell_levels[i] + " spells in your "+list+" list than you are allowed, please remove some and try again.");
            return 0;
        }
        memorized_level = memorized_spells[spell_levels[i]];
        leveled_add = filter_spells(level_list, memorized_level);
        to_add_or_remove += ([spell_levels[i]:leveled_add]);
    }

    return to_add_or_remove;
}


void send_final_message(object obj)
{
    if (obj->query_property("memorizing")) obj->remove_property("memorizing");
    tell_room(environment(obj), obj->QCN + " completes " + obj->QP + " preparations.", obj);
    tell_object(obj, "%^BOLD%^%^GREEN%^You have finished preparing your spells.");
    return;
}


// takes an array of spells instead of a single spell, indexes through the array as new spells are memorized
void prepare_list(object obj, string *spells, int delay, string myclass, int index)
{
    object my_obj;
    string spell;

    if (!objectp(my_obj = obj->query_property("memorizing")) && (my_obj != obj)) { return; }

    if (!random(8))
    {
        switch (myclass)
        {
        case "cleric": case "paladin":
            tell_object(obj, "%^CYAN%^You feel the power of your god.%^RESET%^");
            tell_room(environment(obj), "%^CYAN%^"+obj->QCN + " wavers a second before you.%^CYAN%^", obj);
            break;
        case "mage":
            tell_object(obj, "%^MAGENTA%^You open the grimoire and start reading.%^RESET%^");
            tell_room(environment(obj), "%^MAGENTA%^"+obj->QCN + " turns pages of the grimoire.%^RESET%^", obj);
            break;
        case "druid": case "ranger":
            tell_object(obj, "%^GREEN%^The energies of the wilderness thrum through you.%^RESET%^");
            tell_room(environment(obj), "%^GREEN%^"+obj->QCN + " seems momentarily at peace.", obj);
            break;
        default:
            tell_object(obj, "%^BLUE%^You concentrate carefully on committing the spell to memory.%^RESET%^");
            tell_room(environment(obj), "%^BLUE%^"+obj->QCN + "'s expression conveys deep concentration.%^RESET%^", obj);
            break;
        }
    }

    if (index > (sizeof(spells) - 1))
    {
        send_final_message(obj);
        return;
    }

    spell = spells[index];

    if ((int)obj->can_memorize(myclass, spell) != MEM_OK)
    {
        tell_object(obj, "No more spells to prepare " + spell + ", ending...");
        remove_call_out("prepare_list");
        return;
    }

    if(wait < time())
    {
        wait = time() + 1;
        if(spell_in_grimoire(spell,obj,myclass))
            obj->set_memorized(myclass, spell, 1);
        index++;
    }

    delay = roll_dice(4, 2);
    call_out("prepare_list", delay, obj, spells, delay, myclass, index);
    return;
}


void prepare_listed_spells(object obj, string list, string myclass)
{
    mapping to_prepare,leveled_spells;
    string *to_add = ({}), *to_remove = ({}), *spells,spell;
    int i, j, x, delay, *spell_levels, count, class_level, adjustment;

    if (!objectp(obj)) { return; }

    to_prepare = compare_spells(obj, list, myclass);
    if (!to_prepare) { return 0; }

    spell_levels = keys(to_prepare);

    if (!sizeof(spell_levels))
    {
        tell_object(obj, "You have already prepared all the spells from your " + list + " list.");
        return;
    }

    if(!can_prepare_as(myclass))
        return;

    check_list(obj,list,myclass);

    for (i = 0;i < sizeof(spell_levels);i++)
    {
        leveled_spells = to_prepare[spell_levels[i]];
        spells = keys(leveled_spells);

        if (!sizeof(spells)) { continue; }

        for (j = 0;j < sizeof(spells);j++)
        {
            spell = spells[j];
            count = leveled_spells[spell];

            if (count > 0)
            {
                for (x = 0;x < count;x++)
                {
                    to_add += ({ spell });
                }
            }
            if (count < 0)
            {
                for (x = 0;x < absolute_value(count);x++)
                {
                    to_remove += ({ spell });
                }
            }
        }
    }

    if (!sizeof(to_remove) && !sizeof(to_add))
    {
        tell_object(obj, "You have already prepared all the spells from your " + list + " list.");
        return;
    }

    // forget the spells that are not in our list to make room for the ones that are
    if (sizeof(to_remove))
    {
        for (i = 0;i < sizeof(to_remove);i++)
        {
            obj->forget_memorized(myclass, to_remove[i],1);
        }
    }

    class_level = (int)obj->query_guild_level(myclass);
    delay = MEMORIZE_DELAY;

    if (class_level > 9)
    {
        adjustment = 375 / class_level; //Attempting to lower delay Octothorpe 10/5/17
        if (!adjustment) { adjustment = 1; }
        delay = delay - ((delay * 10) / adjustment);
        if (delay < 1) { delay = 1; }
    }


    switch (myclass)
    {
    case "cleric": case "paladin":

        tell_object(obj, "%^BOLD%^%^GREEN%^You begin praying for spells - Any action you take will interrupt your praying.)");
        tell_room(environment(obj), obj->QCN + " begins praying for spells.", obj);
        break;

    default:

        tell_object(obj, "%^BOLD%^%^GREEN%^You focus your thoughts upon preparing for spells - Any action you take will interrupt your preparations....");
        tell_room(environment(obj), obj->QCN + " bows " + obj->QP + " head and concentrates.", obj);
        break;
    }

    obj->set_property("memorizing", obj);
    prepare_list(obj, to_add, delay, myclass, 0);
    return;
}


void display_list(object obj, string list, string myclass)
{
    mapping lists, current_list, level_list;
    string *my_lists, *display, *leveled_spells, *sort;
    int *spell_levels = allocate(10);
    int i, j, current_spells;

    if (!objectp(obj)) { return; }
    if (!stringp(myclass) || myclass == "" || myclass == " ") { return; }

    lists = get_lists(obj);
    my_lists = keys(lists);

    if (!stringp(list) || list == "")
    {
        tell_object(obj, "You must enter a list name that you want to display.");
        if (sizeof(my_lists))
        {
            tell_object(obj, "Your current lists are: " + implode(my_lists, ", "));
        }
        return;
    }

    for (i = 1;i < sizeof(spell_levels);i++)
    {
        spell_levels[i] = max_allowed(obj, myclass, i);
    }

    current_list = get_current_list(lists, list);

    display = ({ "%^RESET%^%^BOLD%^%^BLUE%^--==%^RESET%^%^BOLD%^%^CYAN%^< %^RESET%^%^BOLD%^" + capitalize(myclass) + " Spells In " + capitalize(list) + " List %^RESET%^%^BOLD%^%^CYAN%^>%^RESET%^%^BOLD%^%^BLUE%^==--%^RESET%^\n" });

    for (i = 0;i < sizeof(spell_levels);i++)
    {
        if (!spell_levels[i]) { continue; }

        level_list = get_level_list(i, current_list);
        leveled_spells = keys(level_list);
        current_spells = num_current_spells(level_list);

        display += ({ "   %^RESET%^%^BOLD%^Level " + i + " " + myclass + ": " + current_spells + "/" + spell_levels[i] + "%^RESET%^" });

        if (!sizeof(leveled_spells)) { continue; }

        sort = ({});

        for (j = 0;j < sizeof(leveled_spells);j++)
        {
            sort += ({ "      " + LEV_AND_COLORS[i] + "" + arrange_string(leveled_spells[j], 27) + "" + level_list[leveled_spells[j]] + "" });
        }

        sort = sort_array(sort, "alphabetical_sort", FILTERS_D);

        for (j = 0;j < sizeof(sort);j++)
        {
            display += ({ sort[j] });
        }
    }

    obj->more(display);

    return;
}

/**
 * This will validate all spells from the list against spell index and
 * will remove them if they no longer exist at their level or got
 * removed from the game alltogether.
 *
 * @param obj owner of the list
 * @param list name of the list
 * @param myclass the character class the list belongs to
 */
void check_list(object obj, string list, string myclass)
{
    mapping lists, current_list, level_list, all_spells;
    string *my_lists, *leveled_spells;
    int *spell_levels = allocate(10);
    int i, j, k, current_spells;

    if (!objectp(obj))
        return;
    if (!stringp(myclass) || myclass == "" || myclass == " ")
        return;
    if (myclass == "bard" ||
        myclass == "sorcerer" ||
        myclass == "oracle" ||
        myclass == "magus" ||
        myclass == "inquisitor")
        return;

    lists = get_lists(obj);
    my_lists = keys(lists);
    all_spells = MAGIC_D->query_index(myclass);

    if (!all_spells)
    {
        tell_object(obj, "Are you sure this class has spells?");
        return;
    }

    if (!stringp(list) || list == "")
    {
        tell_object(obj, "You must enter a list name that you want to validate.");
        if (sizeof(my_lists))
            tell_object(obj, "Your current lists are: " + implode(my_lists, ", "));
        return;
    }

    for (i = 1;i < sizeof(spell_levels);i++)
    {
        spell_levels[i] = max_allowed(obj, myclass, i);
    }

    current_list = get_current_list(lists, list);

    for (i = 0;i < sizeof(spell_levels);i++)
    {
        if (!spell_levels[i])
            continue;

        level_list = get_level_list(i, current_list);
        leveled_spells = keys(level_list);

        if (!sizeof(leveled_spells))
            continue;

        for (j = 0;j < sizeof(leveled_spells);j++)
            if (all_spells[leveled_spells[j]] != i )
            {
                tell_object(obj,"Spell "+leveled_spells[j]+" got updated. Check its helpfile.");
                remove_spell_from_list(obj,leveled_spells[j],list,myclass,1);
            }
    }
    return;
}


varargs int remove_spell_from_list(object obj, string spell, string list, string myclass, int deleteall)
{
    mapping lists, current_list, level_list;
    int spell_level,current_spells;
    int i;

    if (!objectp(obj)) { return 0; }

    lists = get_lists(obj);
    current_list = get_current_list(lists, list);
    if (!sizeof(keys(current_list))) { return 0; }
    /* spell_level = MAGIC_D->query_spell_level(myclass, spell); */
    /* if(!spell_level) */
    for(i=1;i<10;i++)
    {
        level_list = get_level_list(i, current_list);
        if(level_list[spell]){
            spell_level = i;
            break;
        }
    }
    /*     } */
    level_list = get_level_list(spell_level, current_list);
    if (!sizeof(keys(level_list))) { return 0; }

    current_spells = level_list[spell];
    current_spells = current_spells - 1;

    if (current_spells <= 0 || deleteall)
    {
        map_delete(level_list, spell);
        tell_object(obj, "Removing " + spell + " from your " + list + " list.");
    }
    else
    {
        level_list[spell] = current_spells;
        tell_object(obj, "Removing a copy of " + spell + " from your " + list + " list.");
    }

    current_list[spell_level] = level_list;
    lists[list] = current_list;
    obj->set("prepared_lists", lists);
    return 1;
}


int add_spell_to_list(object obj, string spell, string list, string myclass)
{
    mapping lists,current_list,level_list;

    int result,spell_level,current_spells,max_spells;

    if (!objectp(obj)) { return 0; }

    result = obj->can_memorize(myclass,spell);

    if (result == SPELL_RESTRICTED)
    {
        tell_object(obj,"Your use of "+spell+" has been restricted!\n");
        return 0;
    }
    if (result == TOO_STUPID)
    {
        tell_object(obj,"You do not meet the stat requirement to use "+spell+".\n");
        return 0;
    }
    if (result != MEM_OK)
    {
        if (result != TOO_MANY)
        {
            tell_object(obj, "You cannot prepare the " + spell + " spell.\n");
            return 0;
        }
    }

    lists = get_lists(obj);
    current_list = get_current_list(lists, list);

    if(myclass == "sorcerer" ||
       myclass == "inquisitor" ||
       myclass == "magus" ||
       myclass == "oracle" ||
       myclass == "bard")
        spell_level = to_int(replace_string(spell,"level ",""));
    else
        spell_level = MAGIC_D->query_spell_level(myclass, spell);

    level_list = get_level_list(spell_level,current_list);
    max_spells = max_allowed(obj, myclass, spell_level);
    current_spells = num_current_spells(level_list);

    if (current_spells >= max_spells)
    {
        tell_object(obj,"You have too many level " + spell_level + " spells in your list right now.");
        return 0;
    }

    level_list[spell] = level_list[spell] + 1;

    tell_object(obj, "Adding " + spell + " as a level " + spell_level + " " + myclass + " spell to your " + list + " list.");

    current_list[spell_level] = level_list;
    lists[list] = current_list;
    obj->set("prepared_lists", lists);
    return 1;
}


mapping get_level_list(int level, mapping current_list)
{
    mapping level_list;
    if (!level) { return ([]); }
    if (!mapp(current_list) || !sizeof(keys(current_list))) { return ([]); }
    level_list = current_list[level];
    if (!mapp(level_list) || !sizeof(keys(level_list)))
    {
        level_list = ([]);
        current_list[level] = level_list;
    }
    return level_list;
}


mapping get_current_list(mapping lists, string list)
{
    mapping current_list;
    if (!mapp(lists) || !sizeof(keys(lists))) { return ([]); }
    current_list = lists[list];
    if (!mapp(current_list) || !sizeof(keys(current_list)))
    {
        current_list = ([]);
        lists[list] = current_list;
    }
    return current_list;
}


void delete_list(object obj, mapping lists, string list)
{
    if (!objectp(obj)) { return; }
    map_delete(lists, list);
    tell_object(obj, "Deleting your " + list + " list.");
    obj->delete("prepared_lists");
    save_lists(obj, lists);
    return;
}


void copy_list(object obj, string list_one, string list_two, string class_name)
{
    mapping lists,the_list;
    if(!objectp(obj)) { return; }
    tell_object(obj,"Attempting to copy "+list_one+" to "+list_two);

    lists = (mapping)obj->query("prepared_lists");

    if(!mapp(lists))
    {
        tell_object(TP,"You don't have any prepared lists.");
        return;
    }
    the_list = copy(lists[list_one]);

    if(!mapp(the_list))
    {
        tell_object(TP,"You don't seem to have a list called "+list_one);
        return;
    }

    lists[list_two] = the_list;
    obj->delete("prepared_lists");
    save_lists(obj, lists);
    tell_object(TP,"Copied "+list_one+" to "+list_two+".");
    return;
}


mapping get_lists(object obj)
{
    mapping lists;
    if (!objectp(obj)) { return ([]); }
    if (!mapp(lists = (mapping)obj->query("prepared_lists"))) { return ([]); }
    if (!sizeof(keys(lists))) { return ([]); }
    return lists;
}


int save_lists(object obj,mapping lists)
{
    if (!objectp(obj)) { return 0; }
    if (!mapp(lists) || !sizeof(keys(lists))) { return 0; }
    obj->set("prepared_lists", lists); // set a mapping of the prepared spell lists on the player
    return 1;
}

int can_prepare_as(string myclass)
{
    object* inven;
    int validprep;
    int i;

    if (myclass == "mage") {
        inven = all_inventory(TP);
        if (sizeof(inven)) {
            for (i = 0; i < sizeof(inven); i++) {
                if (inven[i]->is_spellbook()) {
                    validprep = 1;
                }
            }
        }
        if (!validprep && !avatarp(TP)) {
            write("You need a spellbook!");
            return 0;
        }
    }
    return 1;
}

int spell_in_grimoire(string spell,object obj,string myclass)
{
    object book;
    book=present("bookx",obj);
    if (myclass!="mage")
        return 1;
    if(!book)
    {
        tell_object(obj, "%^BOLD%^The grimoire has vanished!...%^RESET%^");
        return 0;
    }
    if(!book->query_spellbook(spell))
    {
        tell_object(obj, "%^BOLD%^%^CYAN%^The spell " + spell + " is not in this grimoire! Skipping...%^RESET%^");
        return 0;
    }
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

prepare - prepare a casting

%^CYAN%^SYNOPSIS%^RESET%^

Normal casters (mage, cleric, druid, paladin, ranger):
    prepare %^ORANGE%^%^ULINE%^CLASS%^RESET%^ %^ORANGE%^%^ULINE%^SPELL%^RESET%^ [times %^ORANGE%^%^ULINE%^NUMBER%^RESET%^]

Spontaneous casters (bard, sorcerer):
    prepare %^ORANGE%^%^ULINE%^CLASS%^RESET%^ level %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ [times %^ORANGE%^%^ULINE%^NUMBER2%^RESET%^]

Psionic casters (psion, psywarrior):
    prepare %^ORANGE%^%^ULINE%^CLASS%^RESET%^ points times %^ORANGE%^%^ULINE%^NUMBER%^RESET%^

Warlocks, monks do not prepare.

Preparation lists (normal casters only):
    prepare add|remove %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ %^ORANGE%^%^ULINE%^CLASS%^RESET%^ %^ORANGE%^%^ULINE%^SPELL%^RESET%^
    prepare prepare|check|delete|display %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ %^ORANGE%^%^ULINE%^CLASSNAME%^RESET%^
    prepare copy %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ %^ORANGE%^%^ULINE%^CLASS%^RESET%^ to %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^2 %^ORANGE%^%^ULINE%^CLASS2%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will prepare spells for caster classes that need preparation. To do so you need to provide %^ORANGE%^%^ULINE%^CLASS%^RESET%^ and %^ORANGE%^%^ULINE%^SPELL%^RESET%^ name. Optional \"times %^ORANGE%^%^ULINE%^NUMBER%^RESET%^\" suffix will allow you to prepare %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ times. For example, %^ORANGE%^<prepare cleric light times 10>%^RESET%^ will prepare 10 light spells for cleric. To view prepared spells cleric then may use %^ORANGE%^<recall cleric spells>%^RESET%^.

Spontaneous casters (bards and sorcerers) can prepare %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ of castings in level %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ for their %^ORANGE%^%^ULINE%^CLASS%^RESET%^, with optional suffix \"times %^ORANGE%^%^ULINE%^NUMBER2%^RESET%^\" denoting how many castings they wish to prepare. For example, %^ORANGE%^<prepare bard level 4 times 10>%^RESET%^ will prepare 10 castings of level 4 spell.

Psionic casters may use this command to prepare power points. For example, %^ORANGE%^<prepare psion points times 100>%^RESET%^ will prepare 100 power points for psion.

Normal caster classes (clerics, mages, druids, paladins, rangers, assassins) may use preparation lists.
""
%^CYAN%^PREPARATION LISTS (NORMAL CASTERS ONLY)%^RESET%^

Spell lists are the feature that allows you to prepare spells in bulk and store lists of preparations for various purboses. Each casting %^ORANGE%^%^ULINE%^CLASS%^RESET%^ requires own spell list. You can not have lists of the same name even in different classes. Syntax goes as follows:

%^ORANGE%^<prepare add %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ %^ORANGE%^%^ULINE%^CLASS%^RESET%^ %^ORANGE%^%^ULINE%^SPELL%^RESET%^%^ORANGE%^>%^RESET%^
    Will add %^ORANGE%^%^ULINE%^SPELL%^RESET%^ of caster %^ORANGE%^%^ULINE%^CLASS%^RESET%^ to preparation list named %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^

%^ORANGE%^<prepare remove %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ %^ORANGE%^%^ULINE%^CLASS%^RESET%^ %^ORANGE%^%^ULINE%^SPELL%^RESET%^%^ORANGE%^>%^RESET%^
    Will remove %^ORANGE%^%^ULINE%^SPELL%^RESET%^ of caster %^ORANGE%^%^ULINE%^CLASS%^RESET%^ to preparation list named %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^

%^ORANGE%^<prepare prepare %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ %^ORANGE%^%^ULINE%^CLASSNAME%^RESET%^%^ORANGE%^>%^RESET%^
    Will begin preparation of list %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ for given %^ORANGE%^%^ULINE%^CLASSNAME%^RESET%^. When you'll begin preparation all your currently memorized spells in %^ORANGE%^%^ULINE%^CLASSNAME%^RESET%^ will be overwritten by those in %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^, even if %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ has unused spell slots.

%^ORANGE%^<prepare check %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ %^ORANGE%^%^ULINE%^CLASSNAME%^RESET%^%^ORANGE%^>%^RESET%^
    Will check whether any spell in your %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ got moved, removed or changed and remove it from the list if so, freeing spell slots.

%^ORANGE%^<prepare delete %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ %^ORANGE%^%^ULINE%^CLASSNAME%^RESET%^%^ORANGE%^>%^RESET%^
    Will delete list %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ for given %^ORANGE%^%^ULINE%^CLASSNAME%^RESET%^

%^ORANGE%^<prepare display %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ %^ORANGE%^%^ULINE%^CLASSNAME%^RESET%^%^ORANGE%^>%^RESET%^
    Will show you list %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ for given %^ORANGE%^%^ULINE%^CLASSNAME%^RESET%^

%^ORANGE%^<prepare copy %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ %^ORANGE%^%^ULINE%^CLASS%^RESET%^ to %^ORANGE%^%^ULINE%^LISTNAME2%^RESET%^ %^ORANGE%^%^ULINE%^CLASS2%^RESET%^%^ORANGE%^>%^RESET%^
    Will copy your list %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^ of %^ORANGE%^%^ULINE%^CLASS%^RESET%^ to %^ORANGE%^%^ULINE%^LISTNAME%^RESET%^2 of class %^ORANGE%^%^ULINE%^CLASS2%^RESET%^

%^CYAN%^EXAMPLES%^RESET%^

For example, as a mage you might want to have two lists, one named \"combat\" and another named \"buff\". On the first one you store your combat spells, 2 scorchers and 2 magic missile, on the second armor, resist energy and darkness.

First, we create combat list:

    %^ORANGE%^<prepare add combat mage scorcher>%^RESET%^
    %^ORANGE%^<prepare add combat mage scorcher>%^RESET%^
    %^ORANGE%^<prepare add combat mage magic missile>%^RESET%^
    %^ORANGE%^<prepare add combat mage magic missile>%^RESET%^

Then we create buff list:

    %^ORANGE%^<prepare add buff mage armor>%^RESET%^
    %^ORANGE%^<prepare add buff mage resist energy>%^RESET%^
    %^ORANGE%^<prepare add buff mage darkness>%^RESET%^

Now, to prepare first list you can type %^ORANGE%^<prepare prepare combat mage>%^RESET%^, and to prepare second list you type %^ORANGE%^<prepare prepare buff mage>%^RESET%^

%^CYAN%^SEE ALSO%^RESET%^

forget, cast, buff, dispell, spells, recall
");
}
