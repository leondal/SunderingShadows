#include <std.h>
#include <daemons.h>
inherit DAEMON;
inherit REFS_D;

#include <crafting.h>

#define VALID_TYPES ({ "armorsmith", "leatherworker", "woodworker", "tailor", "weaponsmith", "jeweller" })

varargs int help();
int numerical_sort(int num1, int num2);
void list_crafted(object player);
void preview_item(object player, string item);
void delete_item(object player, string item);
void confirm(string str, object player, string item);

int numerical_sort(mixed one, mixed two)
{
    int num1, num2;
    one = one[50..strlen(one)];
    two = two[50..strlen(two)];
    num1 = to_int(one);
    num2 = to_int(two);
    if (num1 > num2) {
        return 1;
    }else if (num1 == num2) {
        return 0;
    }else {
        return -1;
    }
}

void dreference(string str)
{
    mixed ob;
    if (!str) {
        return;
    }
    ob = ref_ob(str);
    if (!objectp(ob)) {
        return;
    }
    str = identify(ob);
    catch(ob->remove());
    if (!ob) {
        return;
    }
    catch(destruct(ob));
    if (!ob) {
        return;
    }
    return;
}

void list_crafted(object player)
{
    string* files, * display_files = ({}), name, file, holder, date;
    int* temp, i, num;

    if (!objectp(player)) {
        return;
    }
    name = lower_case(player->query_true_name());
    files = get_dir("/d/players/" + name + "/");
    if (!sizeof(files)) {
        tell_object(player, "There are no files in your crafted directory.");
        return;
    }
    for (i = 0; i < sizeof(files); i++) {
        temp = stat("/d/players/" + name + "/" + files[i]);
        num = temp[1];
        display_files += ({ arrange_string(files[i], 50) + num });
    }
    if (sizeof(display_files) > 1) {
        display_files = sort_array(display_files, "numerical_sort", TO);
    }
    for (i = 0; i < sizeof(display_files); i++) {
        holder = display_files[i][0..49];
        num = display_files[i][50..strlen(display_files[i])];
        date = ctime(to_int(num));
        display_files[i] = "%^BOLD%^" + holder + "%^CYAN%^" + date + "";
    }
    player->more(display_files);
    return;
}

mixed check_file_valid(object player, string item)
{
    string file_name, name;
    name = lower_case(player->query_true_name());
    file_name = "/d/players/" + name + "/" + item;
    if (!objectp(player)) {
        return 0;
    }
    if (!file_exists(file_name) && !file_exists(file_name + ".c")) {
        tell_object(player, "That file (" + item + ") doesn't exist, please check your "
                    "spelling and capitalization.");
        return 0;
    }
    return file_name;
}

int filter_common_object(string str)
{
    if (!stringp(str)) {
        return 0;
    }
    if (strsrch(str, COMMONFILE) == -1) {
        return 0;
    }
    return 1;
}

void remake_item(object player, string item)
{
    string file_name, short_desc, long_desc, rsize, * ld, * InhList, mytype, myskill, * item_keys, * skill_keys;
    string base_file, mymap;
    object obj, ob;
    int size, place, x, y;
    mapping tmp_map;

    if (!objectp(player)) {
        return;
    }
    if (!stringp(item)) {
        return help();
    }
    if (!stringp(file_name = check_file_valid(player, item))) {
        return;
    }
    //tell_object(player, "Getting to this point anyway.");
    obj = new(file_name);
    if (!objectp(obj)) {
        tell_object(player, "Something went wrong trying to remake your " + item + " item.");
        return 1;
    }
    tmp_map = ([]);
    item = replace_string(item, ".c", "");
    tmp_map += (["filename" : item, "~SHORT~" : obj->query("short"), "~LORE~" : obj->query_lore(),
                 "~ID~" : obj->query_id(), "~NAME~" : obj->query_name(), ]);
    size = obj->query_size();
    switch (size) {
    case 1:
        rsize = "small";
        break;

    case 2:
        rsize = "medium";
        break;

    case 3:
        rsize = "large";
        break;

    case 4:
        rsize = "giant";
        break;

    case -1:
        rsize = "universal";
        break;

    default:
        tell_object(player, "Something is wrong with the size of your " + item + ". Aborting....");
        if (objectp(obj)) {
            obj->remove();
        }
        return;
    }
    tmp_map += (["~SIZE~" : rsize]);
    ld = explode(obj->query("long"), "\n");
    place = (sizeof(ld) - 2);
    long_desc = implode(ld[0..place], "");
    tmp_map += (["~LONG~" : long_desc]);
    //tell_object(player, "tmp_map = "+identify(tmp_map));

    InhList = filter_array(deep_inherit_list(obj), "filter_common_object", TO);
    //tell_object(player, "InhList = "+identify(InhList));
    item_keys = keys(CRAFT_TO_CHECK);

    for (x = 0; x < sizeof(item_keys); x++) {
        mymap = CRAFT_TO_CHECK[item_keys[x]];
        skill_keys = keys(mymap);
        for (y = 0; y < sizeof(skill_keys); y++) {
            base_file = mymap[skill_keys[y]]["file"];
            base_file += ".c";
            if (member_array(base_file, InhList) == -1) {
                continue;
            }
            mytype = skill_keys[y];
            myskill = item_keys[x];
            break;
        }
        continue;
    }
    if (!stringp(myskill) || !stringp(mytype)) {
        tell_object(player, "There is an error trying to remake your " + file_name + ". " +
                    "Could not determine the skill type or the object type. Notify an immortal.");
    }else {
        ob = new("/cmds/mortal/obj/genOb");
        ob->inject_mapping(tmp_map);
        ob->set_skill(myskill);
        ob->set_file(item);
        ob->set_type(mytype);
        ob->set_prof((int)TP->query_skill("craft, " + myskill));
        TP->set_property("working", "crafting");
        ob->move(TP);
    }
    //tell_object(player, "mytype = "+mytype+" and myskill = "+myskill);
    if (objectp(obj)) {
        obj->remove();
    }
    return;
}

void preview_item(object player, string item)
{
    string file_name, short_desc, long_desc;
    object obj;

    if (!objectp(player)) {
        return;
    }
    if (!stringp(item)) {
        return help();
    }

    if (!stringp(file_name = check_file_valid(player, item))) {
        return;
    }
    if (!objectp(obj = find_object(file_name))) {
        obj = new(file_name);
        if (!objectp(obj)) {
            tell_object(player, "Something went wrong and " +
                        "the file saved as " + item + " was not loaded " +
                        "correctly.");
            return 1;
        }
        short_desc = obj->query_short();
        long_desc = obj->query_long();
        dreference(file_name);
    }
    if (!short_desc) {
        short_desc = obj->query_short();
        long_desc = obj->query_long();
    }
    tell_object(player, "Short desc:\n " + short_desc + "\n");
    tell_object(player, "Long desc:\n " + long_desc + "\n");
    return;
}

void delete_item(object player, string item)
{
    if (!stringp(check_file_valid(player, item))) {
        return;
    }
    tell_object(player, "Do you really want to delete " + item + "?\n");
    tell_object(player, "Enter <yes> to delete " + item + ", anything else "
                "to cancel");
    input_to("confirm", player, item);
    return;
}

void confirm(string str, object player, string item)
{
    string file_name;
    if (!objectp(player)) {
        return;
    }
    if (!stringp(str)) {
        return help();
    }
    if (!stringp(item)) {
        return help();
    }

    if (lower_case(str) != "yes") {
        tell_object(player, "Aborting...");
        return;
    }
    if (!stringp(file_name = check_file_valid(player, item))) {
        return;
    }
    if (find_object(file_name)) {
        tell_object(TP, "A copy of this object is currently loaded "
                    "into memory, you can't delete this object right now.");
        return;
    }

    tell_object(player, "Deleting " + item + "...");
    rm(file_name);
    return;
}

int check_able_to_craft(object who)
{
    object mysneak;
    if (!objectp(who)) {
        return 0;
    }
    if (who->query_hidden()) {
        mysneak = present("TSR80", who);
        if (objectp(mysneak)) {
            mysneak->force_cancel();
        }
    }
    if (who->query_used_craft_skills() > 25) {
        tell_object(who, "You have more applied skills than the current game cap. Please contact a wiz to reallocate.");
        return 0;
    }
    //retaining for posterity but why would being magically hidden prevent someone from seeing? - Saide, May 2017
    /*if (who->query_magic_hidden())
       {
        tell_object(who, "You can't see to work!\n");
        return 0;
       }*/
    return 1;
}

void listitems(string str)
{
    string item, outpt, * tmp, thisitem, prof;
    mapping craftitems;
    if (!CRAFT_TO_CHECK[str]) {
        tell_object(TP, "No such skill. Proper skills are: " + implode(keys(CRAFT_TO_CHECK), " "));
        return;
    }

    craftitems = CRAFT_TO_CHECK[str];
    write("%^GREEN%^-%^BOLD%^%^WHITE%^<Name>%^RESET%^%^GREEN%^----------%^RESET%^%^BOLD%^<Units>%^RESET%^%^GREEN%^---%^RESET%^%^BOLD%^<Type>%^RESET%^%^GREEN%^--------------%^BOLD%^%^WHITE%^<Limbs>%^RESET%^%^GREEN%^-");
    foreach(item in sort_array(keys(craftitems), 1))
    {
        outpt = "%^CYAN%^";
        outpt += arrange_string(item + " ", 20) + "%^ORANGE%^";
        outpt += arrange_string(craftitems[item]["units"], 6) + "%^MAGENTA%^";

        thisitem = craftitems[item]["file"];
        if (thisitem->is_armor()) {
            prof = thisitem->query_armor_prof();
            outpt += arrange_string("AC:" + sprintf("%2d", (int)thisitem->query_ac()) + " " + sprintf("%2s", "" + thisitem->query_weight()) + " lb " + (prof ? capitalize(prof) + " " : ""), 20);
        } else if (thisitem->is_weapon()) {
            prof = thisitem->query_weapon_prof();
            outpt += arrange_string((prof ? capitalize(prof) + " " : ""), 15);
        } else {
            prof = thisitem->query_prof_type();
            outpt += arrange_string((prof ? capitalize(prof) : ""), 15);
        }
        outpt += "%^GREEN%^";
        if (tmp = thisitem->query_limbs()) {
            outpt += implode(tmp, ", ") + " ";
        }
        write(outpt);
    }
}

int cmd_craft(string str)
{
    int x;
    string* item_keys, * skill_keys, command, * info, myskill, previous_skill, tmp;
    object ob;

    if (!str) {
        return notify_fail("See 'help craft' for syntax.");
    }
    if (sizeof((object*)TP->query_attackers())) {
        return notify_fail("You're in combat, let's not do that now.\n");
    }
    if (TP->query_property("working")) {
        return notify_fail("You are already " + (string)TP->query_property("working") + ".\n");
    }

    info = explode(str, " ");
    command = info[0];

    if (!stringp(command)) {
        tell_object(TP, "See 'help craft' for syntax help.");
        return 1;
    }

    if (command == "enchant") {
        if (!ETP->is_lab() && !present("portable lab", ETP)) {
            tell_object(TP, "You must be in a laboratory to enchant items.");
            return 1;
        }
        if (!check_able_to_craft(TP)) {
            return;
        }
        if (FEATS_D->usable_feat(TP, "craft magical equipment")) {
            new("/cmds/mortal/obj/enchant_ob.c")->enchanting_menu();
            return 1;
        }else {
            tell_object(TP, "You need the feat craft magical equipment in order to enchant items.");
            return 1;
        }
    }else if (command == "crafted") {
        list_crafted(TP);
        return 1;
    }else if (command == "preview") {
        if (sizeof(info) != 2) {
            return help();
        }
        preview_item(TP, info[1]);
        return 1;
    }else if (command == "items") {
        if (sizeof(info) != 2) {
            return help();
        }
        listitems(info[1]);
        return 1;
    }else if (command == "delete") {
        if (sizeof(info) != 2) {
            return help();
        }
        delete_item(TP, info[1]);
        return 1;
    }else if (command == "help") {
        if (sizeof(info) == 2) {
            return help(info[1]);
        }
        return help();

        return 1;
    }else if (command == "remake") {
        if (sizeof(info) != 2) {
            return help();
        }
        remake_item(TP, info[1]);
        return 1;
    }

    if (!check_able_to_craft(TP)) {
        return;
    }
    item_keys = keys(CRAFT_TO_CHECK);
    command = implode(info, " ");
    command = explode(command, " with ")[0];
    for (x = 0; x < sizeof(item_keys); x++) {
        skill_keys = keys(CRAFT_TO_CHECK[item_keys[x]]);
        if (member_array(command, skill_keys) == -1) {
            continue;
        }else {
            if (stringp(myskill)) {
                previous_skill = myskill;
            }
            myskill = item_keys[x];
            continue;
        }
        continue;
    }
    if (stringp(previous_skill)) {
        info -= ({ command });
        if (sscanf(implode(info, " "), "with %s", tmp) == 1) {
            myskill = tmp;
        }
        if (stringp(tmp)) {
            myskill = tmp;
        }
    }
    if (!stringp(myskill)) {
        tell_object(TP, "Unable to find a valid crafting skill that would allow you to craft " + command +
                    ". If you think this is an error please notify an immortal.");
        return 1;
    }
    if (member_array(myskill, VALID_TYPES) == -1) {
        tell_object(TP, "No such skill. Proper skills are: " + implode(keys(CRAFT_TO_CHECK), " "));
        return 1;
    }
    ob = new("/cmds/mortal/obj/genOb");
    ob->init_mapping();
    ob->set_skill(myskill);
    ob->set_type(command);
    ob->set_prof((int)TP->query_skill("craft, " + myskill));
    TP->set_property("working", "crafting");
    ob->move(TP);
    return 1;
}

varargs void help(string str)
{
    write("
%^CYAN%^NAME%^RESET%^

craft - crafting central hub

%^CYAN%^SYNOPSIS%^RESET%^

craft %^ORANGE%^%^ULINE%^ITEM%^RESET%^ [with %^ORANGE%^%^ULINE%^SKILL%^RESET%^]
craft items %^ORANGE%^%^ULINE%^SKILL%^RESET%^
craft crafted
craft preview|delete|remake %^ORANGE%^%^ULINE%^FILE%^RESET%^
craft enchant

%^CYAN%^DESCRIPTION%^RESET%^

This command allows player to craft items and manage their crafting.

%^ORANGE%^<craft %^ORANGE%^%^ULINE%^ITEM%^RESET%^%^ORANGE%^ [with %^ORANGE%^%^ULINE%^SKILL%^RESET%^%^ORANGE%^]>%^RESET%^

    Will allow player to craft %^ORANGE%^%^ULINE%^ITEM%^RESET%^. If there are several %^ORANGE%^%^ULINE%^SKILL%^RESET%^s that could be used for the same item, player may specify which skill they want to use to craft an %^ORANGE%^%^ULINE%^ITEM%^RESET%^.

%^ORANGE%^<craft items %^ORANGE%^%^ULINE%^SKILL%^RESET%^%^ORANGE%^>%^RESET%^

    Will list all items you can craft with the %^ORANGE%^%^ULINE%^SKILL%^RESET%^.

%^ORANGE%^<craft crafted>%^RESET%^

    Will list all files player crafted.

%^ORANGE%^<craft preview|delete|remake %^ORANGE%^%^ULINE%^FILE%^RESET%^%^ORANGE%^>%^RESET%^

    Will allow player to preview, delete or remake an item with filename %^ORANGE%^%^ULINE%^FILE%^RESET%^

%^ORANGE%^<craft enchant>%^RESET%^

    Will put player player into enchanting menu if they have required feat. Players can enchant only player-crafted items, and only if they are profficient with corresponding crafting skill. I.e. to enchant jewwelry, player must be profficient jeweller. To enchant items they must have the 'craft magical equipment' feat as well, and that item must be mastercrafted.

%^CYAN%^SEE ALSO%^RESET%^

skills, repair, alterobj
");
}
