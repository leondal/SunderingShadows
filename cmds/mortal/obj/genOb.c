#include <std.h>
#include <move.h>
#include <objects.h>
#define VMATERIALTYPES (["leatherworker" : ({ "leather" }), \
                         "jeweller" : ({ "metal" }), \
                         "armorsmith" : ({ "metal" }), \
                         "weaponsmith" : ({ "metal" }), \
                         "woodworker" : ({ "wood" }), \
                         "tailor" : ({ "cloth", "leather" })])
#define MENUCHOICES ({ "material", "file name", "name", "size", "ids", "short description", "long description", "lore", "finish" })

#define UNSET "%^BOLD%^%^WHITE%^(Unset)%^RESET%^"

inherit OBJECT;

#include <crafting.h>

int prof;
string file, type, material, color, skill, mymenu;
object materialObj, * availMats;
mapping datamap;
mapping keyMap = ([]);
mapping okeyMap = ([]);

void finish_object(mapping keyMap);
void next_input(mapping keyMap);

int save_me(string file)
{
    return 1;
}

int drop()
{
    return 1;
}

int final_check();
void set_type(string t)
{
    type = t;
}

void set_skill(string s)
{
    skill = s;
}

void set_prof(int p)
{
    prof = p;
}

void set_material(object o)
{
    materialObj = o;
    material = lower_case((string)o->query_subtype());
    color = lower_case((string)o->query_color());
}

void finish_object();
void material_choice();
void display_menu();
void exit();
mixed* build_materials();


void set_file(string f)
{
    f = replace_string(f, " ", "_");
    f = replace_string(f, ".", "");
    f = replace_string(f, "\\", "");
    f = replace_string(f, "/", "");
    f = replace_string(f, "*", "");
    f = replace_string(f, "?", "");
    f = replace_string(f, "~", "");
    f = replace_string(f, "\"", "");
    file = f;
}

void exit()
{
    if (!objectp(TO)) {
        return;
    }
    if (objectp(ETO)) {
        ETO->remove_property("working");
    }
    TO->remove();
    return;
}

void init_mapping()
{
    keyMap = ([]);
}

void inject_mapping(mapping mymap)
{
    if (!mapp(mymap)) {
        return;
    }
    keyMap = copy(mymap);
    return;
}

void init()
{
    ::init();
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        TO->remove();
        return;
    }
    switch (skill) {
    case "armorsmith": datamap = ARMORSMITH; break;

    case "weaponsmith": datamap = WEAPONSMITH; break;

    case "woodworker": datamap = WOODWORK; break;

    case "jeweller": datamap = JEWEL; break;

    case "tailor": datamap = TAILOR; break;

    case "leatherworker": datamap = LEATHERWORK; break;
    }
    if (!sizeof(availMats = build_materials())) {
        tell_object(ETO, "You do not have any suitable materials to craft " + type + ". It requires " +
                    datamap[type]["units"] + " units of " + implode(VMATERIALTYPES[skill], " or ") + ".");
        exit();
        return;
    }
    if (skill == "armorsmith") {
        if (!EETO->query_property("smithy") && !present("portable smithy", EETO)) {
            tell_object(ETO, "You must be in a smithy to forge new armor.");
            exit();
            return;
        }
    }

    if (skill == "weaponsmith") {
        if (!EETO->query_property("smithy") && !present("portable smithy", EETO)) {
            tell_object(ETO, "You must be in a smithy to forge new weapons.");
            exit();
            return;
        }
    }
    mymenu = "materials";
    display_menu();
    return;
}

mixed* build_materials()
{
    int units, x;
    object* inv;
    if (!objectp(TO) || !objectp(ETO)) {
        return ({});
    }
    inv = all_inventory(ETO);
    units = datamap[type]["units"];
    availMats = ({});
    for (x = 0; x < sizeof(inv); x++) {
        if (!objectp(inv[x]) || !inv[x]->is_material()) {
            continue;
        }
        if (member_array(inv[x]->query_type(), VMATERIALTYPES[skill]) == -1) {
            continue;
        }
        if (inv[x]->query_uses() < units) {
            continue;
        }
        availMats += ({ inv[x] });
        continue;
    }
    if (!sizeof(availMats)) {
        return ({});
    }
    availMats = distinct_array(availMats);
    return availMats;
}

void display_menu_head()
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^" + capitalize(skill) + " crafting: %^BOLD%^%^MAGENTA%^" + capitalize(type) + "%^BOLD%^%^WHITE%^%^RESET%^");
    tell_object(ETO, "  %^BOLD%^%^GREEN%^" + capitalize(mymenu) + " menu%^RESET%^");
    return;
}

void display_material_choices()
{
    int x;
    string myShortDesc, myQuality;
    for (x = 0; x < sizeof(availMats); x++) {
        if (!objectp(availMats[x])) {
            continue;
        }
        tell_object(ETO, "  " + (x + 1) + " " + availMats[x]->query_short() + " %^BOLD%^%^WHITE%^(%^BOLD%^%^MAGENTA%^" + availMats[x]->query_quality() + "%^BOLD%^%^WHITE%^)%^RESET%^");
        continue;
    }
    return;
}

void main_menu()
{
    int x;
    string msg, choice;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    for (x = 0; x < sizeof(MENUCHOICES); x++) {
        choice = MENUCHOICES[x];
        msg = "  %^BOLD%^%^GREEN%^" + (x + 1) + " " + capitalize(choice) + " ";
        switch (choice) {
        case "material":
            if (objectp(materialObj)) {
                msg += "%^BOLD%^%^WHITE%^(" + materialObj->query_short() + " : %^BOLD%^%^MAGENTA%^" + materialObj->query_quality() + "%^BOLD%^%^WHITE%^) %^RESET%^";
            }else {
                msg += UNSET;
            }
            break;

        case "file name":
            if (stringp(file)) {
                msg += "%^BOLD%^%^WHITE%^(%^BOLD%^%^MAGENTA%^" + file + "%^BOLD%^%^WHITE%^)%^RESET%^";
            }else {
                msg += UNSET;
            }
            break;

        case "name":
            if (stringp(keyMap["~NAME~"])) {
                msg += "%^BOLD%^%^WHITE%^(%^BOLD%^%^MAGENTA%^" + keyMap["~NAME~"] + "%^BOLD%^%^WHITE%^)%^RESET%^";
            }else {
                msg += UNSET;
            }
            break;

        case "size":
            if (stringp(keyMap["~SIZE~"])) {
                msg += "%^BOLD%^%^WHITE%^(%^BOLD%^%^MAGENTA%^" + keyMap["~SIZE~"] + "%^BOLD%^%^WHITE%^)%^RESET%^";
            }else {
                msg += UNSET;
            }
            break;

        case "ids":
            if (pointerp(keyMap["~ID~"])) {
                msg += "%^BOLD%^%^WHITE%^(%^BOLD%^%^MAGENTA%^" + implode(keyMap["~ID~"], ", ") + "%^BOLD%^%^WHITE%^)%^RESET%^";
            }else {
                msg += UNSET;
            }
            break;

        case "short description":
            if (stringp(keyMap["~SHORT~"])) {
                msg += "%^BOLD%^%^WHITE%^(%^BOLD%^%^MAGENTA%^" + keyMap["~SHORT~"] + "%^BOLD%^%^WHITE%^)%^RESET%^";
            }else {
                msg += UNSET;
            }
            break;

        case "long description":
            if (stringp(keyMap["~LONG~"])) {
                msg += "\n%^BOLD%^%^WHITE%^%^BOLD%^%^MAGENTA%^" + keyMap["~LONG~"] + "%^BOLD%^%^WHITE%^%^RESET%^";
            }else {
                msg += UNSET;
            }
            break;

        case "lore":
            if (stringp(keyMap["~LORE~"])) {
                msg += "\n%^BOLD%^%^MAGENTA%^" + keyMap["~LORE~"] + "%^RESET%^";
            }else {
                msg += UNSET;
            }
            break;
        }
        tell_object(ETO, msg);
        continue;
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^Select what you want to set up for your " + type + " by using the number to the left.\n" +
                "Entering %^BOLD%^%^GREEN%^**%^BOLD%^%^WHITE%^ will exit and cancel your crafting.%^RESET%^");
    input_to("process_main_menu_choice", 0);
    return;
    //exit();
}

void display_menu()
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    display_menu_head();
    switch (mymenu) {
    case "materials":
        material_choice();
        break;

    case "main":
        main_menu();
        break;
    }
    return;
}

void material_choice()
{
    int mchoices;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    display_material_choices();
    tell_object(ETO, "%^BOLD%^%^WHITE%^Select one of the available materials to craft your " + type + " from by using " +
                "the number to the left.");
    input_to("choose_material", 0);
    return;
}

void process_main_menu_choice(string f)
{
    int place;
    string mychoice, subtype;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    if (!f) {
        display_menu();
        return;
    }
    if (f == "**") {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You have decided against crafting " + type + ".%^RESET%^");
        exit();
        return;
    }
    place = to_int(f);
    place--;
    if (place < 0 || place > (sizeof(MENUCHOICES) - 1)) {
        display_menu();
        return;
    }
    mychoice = MENUCHOICES[place];
    switch (mychoice) {
    case "material":
        mymenu = "materials";
        display_menu();
        return;

    case "file name":
        tell_object(ETO, "Please enter an unique (unused before) file name for this " + type + ".");
        input_to("files", 0);
        return;

    case "name":
        tell_object(ETO, "Please enter a name for this " + type + ". Don't use color codes.");
        input_to("names", 0);
        return;

    case "size":
        if (skill == "armorsmith" || skill == "leatherworker" || skill == "tailor" || skill == "jeweller") {
            tell_object(ETO, "Please enter the size of your " + type + " as large, medium or small.");
            input_to("size", 0);
            return;
        }
        tell_object(ETO, "You are unable to change the size of your " + type + ". This is intentional with weapons.");
        display_menu();
        return;

    case "ids":
        tell_object(ETO, "Please enter the key words for your " + type + ". Separate with commas.(dagger,silver dagger,Dagger,)");
        input_to("ids", 0);
        return;

    case "short description":
        if (type == "pocket robe") {
            subtype = "robe";
        }else {
            subtype = type;
        }
        tell_object(ETO, "Please enter the short description, or the description you see in your inventory.");
        tell_object(ETO, "You will need to include: " + material + ", " + subtype + "");
        input_to("shortDesc", 0);
        return;

    case "long description":
        tell_object(ETO, "Please input the Long description.");
        tell_object(ETO, "Use ** to end the long describe. Don't quit in this field.");
        tell_object(ETO, "If you make a mistake, a ~r on an empty line will reset the long description.");
        tell_object(ETO, "Entering multiple lines is okay.");
        tell_object(ETO, "The limit is 2000 characters, including color codes:");
        input_to("long", 0, "");
        return;

    case "lore":
        tell_object(ETO, "Please input the Lore.");
        tell_object(ETO, "Use ** to end the long describe. Don't quit in this field.");
        tell_object(ETO, "If you make a mistake, a ~r on an empty line will reset the long description.");
        tell_object(ETO, "Entering multiple lines is okay.");
        tell_object(ETO, "The limit is 2000 characters, including color codes:");
        input_to("lore", 0, "");
        return;

    case "finish":
        if (final_check()) {
            tell_object(ETO, "Are you sure that you wish to finish your " + type + "? If so, type " +
                        "yes, anything else will abort.");
            input_to("finish_item", 0);
            return;
        }
        tell_object(ETO, "%^BOLD%^%^RED%^There are still some requirements that must be set before you can finish " +
                    "this item.%^RESET%^");
        display_menu();
        return;
    }
    display_menu();
    return;
}

void finish_item(string str)
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    if (!stringp(str) || str != "yes") {
        tell_object(ETO, "You have chosen not to finish this item yet.");
        display_menu();
        return;
    }
    finish_object();
    return;
}

void choose_material(string f)
{
    int place;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    if (!f) {
        display_menu();
        return;
    }
    place = to_int(f);
    place--;
    if (place < 0 || place > (sizeof(availMats) - 1)) {
        display_menu();
        return;
    }
    set_material(availMats[place]);
    keyMap["~SHORT~"] = 0;
    tell_object(ETO, "You have chosen to use " + availMats[place]->query_short() +
                " to craft your " + type + ".");
    mymenu = "main";
    display_menu();
    return;
}

void files(string f)
{
    string fileName;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    if (!f) {
        tell_object(ETO, "Please enter an unique (unused before) one word reference for this " + type + ".");
        input_to("files", 0);
        return;
    }
    if (file_size("/d/players/" + ETOQN) == -1) {
        mkdir("/d/players/" + ETOQN);
    }
    fileName = "/d/players/" + TPQN + "/" + f + ".c";
    if (file_exists(fileName)) {
        tell_object(ETO, "Please enter an unique (unused before) one word reference for this " + type + " (" + f + " has already been used).");
        input_to("files", 0);
        return;
    }
    set_file(f);
    display_menu();
    return;
}

void names(string name)
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    if (!name) {
        tell_object(ETO, "Please enter a name for this " + type + ".");
        input_to("names", 0);
        return;
    }
    name = replace_string(name, "\"", "");
    keyMap["~NAME~"] = name;
    display_menu();
    return;
}

void size(string size)
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    if (!size) {
        tell_object(ETO, "Please enter the size of this object as large, medium or small.");
        input_to("size", 0);
        return;
    }
    if (size != "small" && size != "medium" && size != "large") {
        tell_object(ETO, "Please enter the size of this object as large, medium or small.");
        input_to("size", 0);
        return;
    }
    if (size == "medium") {
        if ((datamap[type]["units"] * 2) > (int)materialObj->query_uses()) {
            tell_object(ETO, "There is not enough of " + materialObj->query_short() + " in order to make this " +
                        "into a medium sized " + type + ". You must have " + (datamap[type]["units"] * 2) + " units of the material " +
                        "to make " + type + " medium sized.");
            display_menu();
            return;
        }
    }
    if (size == "large") {
        if ((datamap[type]["units"] * 3) > (int)materialObj->query_uses()) {
            tell_object(ETO, "There is not enough of " + materialObj->query_short() + " in order to make this " +
                        "into a large sized " + type + ". You must have " + (datamap[type]["units"] * 3) + " units of the material " +
                        "to make " + type + " large sized.");
            display_menu();
            return;
        }
    }
    keyMap["~SIZE~"] = size;
    display_menu();
    return;
}

void ids(string id_values)
{
    string* id_array, subtype;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    if (type == "pocket robe") {
        subtype = "robe";
    }else {
        subtype = type;
    }
    if (!id_values) {
        tell_object(ETO, "Please enter the key words for this item. Separate with commas.(dagger,silver dagger,Dagger,)");
        input_to("ids", 0);
        return;
    }
    id_values = replace_string(id_values, "\"", "");
    id_array = explode(id_values, ",");
    id_array += ({ keyMap["~NAME~"] });
    keyMap["~ID~"] = id_array;
    display_menu();
    return;
}

void shortDesc(string shrt)
{
    string testshrt, subtype;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    if (type == "pocket robe") {
        subtype = "robe";
    }else {
        subtype = type;
    }
    if (!shrt) {
        tell_object(ETO, "Please enter the short description, or the description you see in your inventory.");
        tell_object(ETO, "You will need to include: " + material + ", " + subtype + "");
        input_to("shortDesc", 0);
        return;
    }
    testshrt = "/daemon/filters_d"->filter_colors(shrt);
    if (strsrch(testshrt, material) == -1) {
        shrt += " " + material;
    }
    if (strsrch(testshrt, subtype) == -1) {
        shrt += " " + subtype;
    }
    shrt = replace_string(shrt, "\"", "'");
    keyMap["~SHORT~"] = shrt;
    display_menu();
    return;
}

void long(string str, string longd)
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    if (!str) {
        tell_object(ETO, "Please input the Long describe >Note use ** to end the long describe.  Don't quit in this field.");
        tell_object(ETO, "If you make a mistake, a ~r on an empty line will reset the long description.");
        tell_object(ETO, "Entering multiple lines is okay.");
        tell_object(ETO, "To be safe, make sure you have no more than 15 lines of this length:");
        tell_object(ETO, "%^BOLD%^|---------------------------------------------------------------|%^RESET%^");
        input_to("long", longd);
        return 1;
    }
    if (str == "~r") {
        tell_object(ETO, "Long reset, please restart long description.");
        input_to("long", 0, "");
        return;
    }
    if (str != "**") {
        longd += str + "\n";
        input_to("long", 0, longd);
        return;
    }
    longd = replace_string(longd, "\"", "'");
    keyMap["~LONG~"] = longd;
    display_menu();
    return;
}

void lore(string str2, string lored)
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        exit(); return;
    }
    if (!str2) {
        tell_object(ETO, "Please input the Lore >Note use ** to end the long describe.  Don't quit in this field.");
        tell_object(ETO, "If you make a mistake, a ~r on an empty line will reset the long description.");
        tell_object(ETO, "Entering multiple lines is okay.");
        tell_object(ETO, "To be safe, make sure you have no more than 15 lines of this length:");
        tell_object(ETO, "%^BOLD%^|---------------------------------------------------------------|%^RESET%^");
        input_to("lore", 0, "");
        return;
    }
    if (str2 == "~r") {
        tell_object(ETO, "Lore reset, please restart lore.");
        input_to("lore", 0, "");
        return;
    }
    if (str2 != "**") {
        lored += str2 + "\n";
        input_to("lore", 0, lored);
        return;
    }
    lored = replace_string(lored, "\"", "'");
    keyMap["~LORE~"] = lored;
    display_menu();
    return;
}

int final_check()
{
    if (!objectp(TO)) {
        return 0;
    }
    if (!objectp(ETO)) {
        return 0;
    }
    if (!stringp(keyMap["~NAME~"])) {
        return 0;
    }
    if (!stringp(file)) {
        return 0;
    }
    if (!objectp(materialObj)) {
        return 0;
    }
    if (!pointerp(keyMap["~ID~"])) {
        return 0;
    }
    if (!stringp(keyMap["~SHORT~"])) {
        return 0;
    }
    if (!stringp(keyMap["~LONG~"])) {
        return 0;
    }
    return 1;
}

void finish_object()
{
    string fileName, l, subtype, * broken_sections, repairtype;
    int quality, num, hops, extra, i, pocketsize;
    object ob;

    keyMap["~INHERIT~"] = datamap[type]["file"];

    quality = prof + roll_dice(1, 20);
    quality = quality - (10 - (int)materialObj->query_quality_type()); // this gives up to -10 modifier on quality for DC
    if (quality < 0) {
        quality = 0;
    }

    keyMap["~QUALITY~"] = quality;
    keyMap["~CREATOR~"] = TPQN;
    l = keyMap["~LONG~"];
    switch (quality) { // DC15 for mastercraft non-enchant items.
    case 0: l += "\nVery poor quality"; break;

    case 1..3: l += "\nLow quality"; break;

    case 4..6: l += "\nBelow average quality"; break;

    case 7..9: l += "\nAverage quality"; break;

    case 10..12: l += "\nAbove average quality"; break;

    case 13..15: l += "\nHigh quality"; break;

    default: l += "\nMastercrafted"; break;
    }
    keyMap["~LONG~"] = l;

    if (file_size("/d/players/" + TPQN) == -1) {
        mkdir("/d/players/" + TPQN);
    }
    fileName = "/d/players/" + TPQN + "/" + file + ".c";
    if (file_exists(fileName)) {
        rm(fileName);
    }

    write_file(fileName, "#include <std.h>\ninherit \"" + keyMap["~INHERIT~"] + "\";\n\nvoid create(){\n");
    write_file(fileName, "\tint placeholder, *placeholder2;\n\t::create();\n");
    write_file(fileName, "\tset_property(\"creator\",\"" + keyMap["~CREATOR~"] + "\");\n");
    write_file(fileName, "\tset_property(\"quality\"," + keyMap["~QUALITY~"] + ");\n");
    if (member_array("~SIZE~", keys(keyMap)) != -1) {
        switch (keyMap["~SIZE~"]) {
        case "small": keyMap["~THESIZE~"] = 1; break;

        case "large": keyMap["~THESIZE~"] = 3; break;

        default: keyMap["~THESIZE~"] = 2; break;
        }
        write_file(fileName, "\tset_size(" + keyMap["~THESIZE~"] + ");\n");
    }
    write_file(fileName, "\tset_name(\"" + keyMap["~NAME~"] + "\");\n");
    write_file(fileName, "\tset_id(" + identify(keyMap["~ID~"]) + ");\n");
    write_file(fileName, "\tset_short(\"" + keyMap["~SHORT~"] + "\");\n");

    num = strlen(keyMap["~LONG~"]);
    if (num > 200) {
        broken_sections = ({});
        hops = num / 200;
        extra = num % 200;
        for (i = 0; i < hops; i++) {
            broken_sections += ({ keyMap["~LONG~"][(i * 200)..((i * 200) + 199)] });
        }
        if (extra) {
            broken_sections += ({ keyMap["~LONG~"][(hops * 200)..num] });
        }
    }
    if (pointerp(broken_sections) && broken_sections != ({})) {
        write_file(fileName, "\tset_long(\"" + broken_sections[0] + "\"\n");
        for (i = 1; i < sizeof(broken_sections); i++) {
            write_file(fileName, "\t\"" + broken_sections[i] + "\"\n");
        }
        write_file(fileName, "\t);\n");
    }else {
        write_file(fileName, "\tset_long(\"" + keyMap["~LONG~"] + "\");\n");
    }

    if (member_array("~LORE~", keys(keyMap)) != -1) {
        num = strlen(keyMap["~LORE~"]);
        if (num > 200) {
            broken_sections = ({});
            hops = num / 200;
            extra = num % 200;
            for (i = 0; i < hops; i++) {
                broken_sections += ({ keyMap["~LORE~"][(i * 200)..((i * 200) + 199)] });
            }
            if (extra) {
                broken_sections += ({ keyMap["~LORE~"][(hops * 200)..num] });
            }
        }
        if (pointerp(broken_sections) && broken_sections != ({})) {
            write_file(fileName, "\tset_lore(\"" + broken_sections[0] + "\"\n");
            for (i = 1; i < sizeof(broken_sections); i++) {
                write_file(fileName, "\t\"" + broken_sections[i] + "\"\n");
            }
            write_file(fileName, "\t);\n");
        }else {
            write_file(fileName, "\tset_lore(\"" + keyMap["~LORE~"] + "\");\n");
        }
        write_file(fileName, "\tset_property(\"lore difficulty\"," + quality + ");\n");
    }

    switch (skill) {
        case "armorsmith": repairtype = "armorsmith"; break;
        case "weaponsmith": repairtype = "weaponsmith"; break;
        case "woodworker": repairtype = "woodwork"; break;
        case "jeweller": repairtype = "jewel"; break;
        case "tailor": repairtype = "tailor"; break;
        case "leatherworker": repairtype = "leatherwork"; break;
    }
    write_file(fileName, "\tset_property(\"repairtype\", ({\""+repairtype+"\"}));\n");

    if (quality <= 16) { //modify weight, value, etc
        write_file(fileName, "\tplaceholder = (::query_weight() * 2) - ((::query_weight() * " + quality + ") \/16);\n");
        write_file(fileName, "\tset_weight(placeholder);\n");
        write_file(fileName, "\tplaceholder = roll_dice((" + (quality + 1) + "),::query_value());\n");
        write_file(fileName, "\tset_value(placeholder);\n");

        if (skill == "woodworker" || skill == "leatherworker") {
            subtype = datamap[type]["type"];
        }else {
            subtype = "";
        }
        if (skill == "armorsmith" || subtype == "armor") { //modify AC for armor
            write_file(fileName, "\tplaceholder = ((::query_ac() * " + quality + ") /16);\n");
            write_file(fileName, "\tset_ac(placeholder);\n");
        }
        if (skill == "weaponsmith" || subtype == "weapon" || subtype == "lrweapon") {
            write_file(fileName, "\tplaceholder = ((::query_wc_dice() * " + quality + ") /16);\n");
            write_file(fileName, "\tset_wc(::query_wc_num(),placeholder);\n");
            write_file(fileName, "\tplaceholder = ((::query_large_wc_dice() * " + quality + ") /16);\n");
            write_file(fileName, "\tset_large_wc(::query_large_wc_num(),placeholder);\n");
        }
        if (subtype == "arrows") {
            write_file(fileName, "\tplaceholder2 = ::query_wc();\n");
            write_file(fileName, "\tplaceholder = (placeholder2[1]* " + quality + ")/16;\n");
            write_file(fileName, "\tset_wc(placeholder2[0],placeholder);\n");
            write_file(fileName, "\tplaceholder2 = ({});\n");
            write_file(fileName, "\tplaceholder2 = ::query_large_wc();\n");
            write_file(fileName, "\tplaceholder = (placeholder2[1]* " + quality + ")/16;\n");
            write_file(fileName, "\tset_large_wc(placeholder2[0],placeholder);\n");
        }
    }
    if (type == "pocket robe") {
        if (quality > 16) {
            quality = 16;
        }
        pocketsize = quality + 5;
        write_file(fileName, "\tset_max_internal_encumbrance(" + pocketsize + ");\n");
    }

    write_file(fileName, "}");
    if (member_array("~THESIZE~", keys(keyMap)) != -1) {
        materialObj->use(keyMap["~THESIZE~"] * (int)datamap[type]["units"]);
    }else {
        materialObj->use((int)datamap[type]["units"]);
    }
    ETO->remove_property("working");
    tell_room(EETO, ETO->QCN + " pauses from working on the new item.", ETO);
    tell_object(ETO, "You pause from working on the new item.");
    ob = new(fileName);
    if (ob->move(TP) != MOVE_OK) {
        ob->move(ETP);
    }
    remove();
}
