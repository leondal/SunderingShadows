#include <std.h>
#include <daemons.h>
#include <brewing.h>
inherit DAEMON;

int cmd_brew(string str)
{
    int myprof, dc, strength, myvalue, tracker, i, expdrain, max_exp_drain;
    string mytype, myname, myvar, filename, * datamapkeys, * matkeys, currentmat, mydir;
    mapping datamap, materials;
    object mysneak, ob, ob2, * using;

    if (!str) {
        return notify_fail("See 'help brew' for syntax.\n");
    }

    if (TP->query_hidden()) {
        mysneak = present("TSR80", TP);
        if (objectp(mysneak)) {
            mysneak->force_cancel();
        }
    }
    if (TP->query_magic_hidden()) {
        return notify_fail("You can't see your hands to work!\n");
    }
    if (sizeof((object*)TP->query_attackers())) {
        return notify_fail("You're in combat, let's not do that now.\n");
    }
    if (TP->query_property("working")) {
        return notify_fail("You are already " + (string)TP->query_property("working") + ".\n");
    }
    if (sscanf(str, "%s %s", mytype, myname) != 2) {
        tell_object(TP, "See 'help brew' for syntax.");
        return 1;
    }

    if (mytype == "list") {
        switch (myname) {
        case "kits":
            datamap = KITS;
            tell_object(TP, "%^BOLD%^%^WHITE%^The 'kits' classification covers all vials designed to restore hitpoints. These will be installed at a later date.\n");
            return 1;

            break;

        case "potions":
            datamap = POTIONS;
            tell_object(TP, "%^BOLD%^%^WHITE%^The 'potions' classification covers all brews designed for consumption to convey an immediate change or alteration to the drinker.\n");
            break;

        case "elixirs":
            datamap = ELIXIRS;
            tell_object(TP, "%^BOLD%^%^WHITE%^The 'elixirs' classification covers all brews designed for consumption to convey a longterm beneficial effect.\n");
            break;

        case "oils":
            datamap = OILS;
            tell_object(TP, "%^BOLD%^%^WHITE%^The 'oils' classification covers all brews designed for use on equipment, whether they be cleansing, enchanting, or poisoning.\n");
            break;

        case "powders":
            datamap = POWDERS;
            tell_object(TP, "%^BOLD%^%^WHITE%^The 'powders' classification covers all powders and dusts. These are usually only used by those skilled in rogueish arts.\n");
            break;

        case "misc":
            datamap = MISC;
            tell_object(TP, "%^BOLD%^%^WHITE%^The 'miscellaneous' classification covers all other brewed mixes not covered by the standard groups.\n");
            break;

        default:
            tell_object(TP, "Sorry, " + myname + " is not a valid type of brew to list. See <help brew> for syntax.");
            return 1;

            break;
        }

        matkeys = ({}); // simple
        datamapkeys = keys(datamap);
        for (i = 0; i < sizeof(datamapkeys); i++) {
            if (datamap[datamapkeys[i]]["dc"] < 25) {
                matkeys += ({ datamapkeys[i] });
            }
        }
        currentmat = "-simple: ";
        if (!sizeof(matkeys)) {
            currentmat = currentmat + "none.";
        }else {
            currentmat += matkeys[0];
            if (sizeof(matkeys) > 1) {
                for (i = 1; i < sizeof(matkeys); i++) {
                    currentmat += ", ";
                    currentmat += matkeys[i];
                }
            }
            currentmat = currentmat + ".";
        }
        tell_object(TP, currentmat);

        matkeys = ({}); // moderate
        datamapkeys = keys(datamap);
        for (i = 0; i < sizeof(datamapkeys); i++) {
            if (datamap[datamapkeys[i]]["dc"] > 24 && datamap[datamapkeys[i]]["dc"] < 35) {
                matkeys += ({ datamapkeys[i] });
            }
        }
        currentmat = "-moderate: ";
        if (!sizeof(matkeys)) {
            currentmat = currentmat + "none.";
        }else {
            currentmat += matkeys[0];
            if (sizeof(matkeys) > 1) {
                for (i = 1; i < sizeof(matkeys); i++) {
                    currentmat += ", ";
                    currentmat += matkeys[i];
                }
            }
            currentmat = currentmat + ".";
        }
        tell_object(TP, currentmat);

        matkeys = ({}); // complex
        datamapkeys = keys(datamap);
        for (i = 0; i < sizeof(datamapkeys); i++) {
            if (datamap[datamapkeys[i]]["dc"] > 34 && datamap[datamapkeys[i]]["dc"] < 45) {
                matkeys += ({ datamapkeys[i] });
            }
        }
        currentmat = "-complex: ";
        if (!sizeof(matkeys)) {
            currentmat = currentmat + "none.";
        }else {
            currentmat += matkeys[0];
            if (sizeof(matkeys) > 1) {
                for (i = 1; i < sizeof(matkeys); i++) {
                    currentmat += ", ";
                    currentmat += matkeys[i];
                }
            }
            currentmat = currentmat + ".";
        }
        tell_object(TP, currentmat);

        matkeys = ({}); // epic
        datamapkeys = keys(datamap);
        for (i = 0; i < sizeof(datamapkeys); i++) {
            if (datamap[datamapkeys[i]]["dc"] > 44) {
                matkeys += ({ datamapkeys[i] });
            }
        }
        currentmat = "-epic: ";
        if (!sizeof(matkeys)) {
            currentmat = currentmat + "none.";
        }else {
            currentmat += matkeys[0];
            if (sizeof(matkeys) > 1) {
                for (i = 1; i < sizeof(matkeys); i++) {
                    currentmat += ", ";
                    currentmat += matkeys[i];
                }
            }
            currentmat = currentmat + ".";
        }
        tell_object(TP, currentmat);
        return 1;
    }

    sscanf(myname, "%s | %s", myname, myvar);
    tracker = 0;
    datamap = KITS;
    datamapkeys = keys(datamap);
    if (member_array(myname, datamapkeys) != -1) {
        tracker = 1; mydir = "kits";
    }
    if (!tracker) {
        datamap = POTIONS;
        datamapkeys = keys(datamap);
        if (member_array(myname, datamapkeys) != -1) {
            tracker = 1; mydir = "potions";
        }
    }
    if (!tracker) {
        datamap = ELIXIRS;
        datamapkeys = keys(datamap);
        if (member_array(myname, datamapkeys) != -1) {
            tracker = 1; mydir = "elixirs";
        }
    }
    if (!tracker) {
        datamap = OILS;
        datamapkeys = keys(datamap);
        if (member_array(myname, datamapkeys) != -1) {
            tracker = 1; mydir = "oils";
        }
    }
    if (!tracker) {
        datamap = POWDERS;
        datamapkeys = keys(datamap);
        if (member_array(myname, datamapkeys) != -1) {
            tracker = 1; mydir = "powders";
        }
    }
    if (!tracker) {
        datamap = MISC;
        datamapkeys = keys(datamap);
        if (member_array(myname, datamapkeys) != -1) {
            tracker = 1; mydir = "misc";
        }
    }
    if (!tracker) {
        return notify_fail("Sorry, " + myname + " is not a valid alchemical creation. Please see 'help brew' for syntax and lists.\n");
    }

    if (!FEATS_D->usable_feat(TP, "brew potion")) {
        return notify_fail("You need the 'brew potion' feat to do this!\n");
    }
    filename = replace_string(myname, " ", "_");
    filename = "/d/common/obj/brewing/" + mydir + "/" + filename + ".c";
    if (!file_exists(filename)) {
        return notify_fail("File error: does not exist. This brew is probably not installed yet.\n");
    }

    if (mytype == "create") { // creating a potion or mix
        if (!avatarp(TP)) {
            if ((!ETP->is_lab() && !present("portable lab", ETP))) {
                return notify_fail("You must be in a laboratory to brew potions and other alchemical mixes.\n");
            }
        }

        using = ({});
        materials = datamap[myname]["materials"];
        matkeys = keys(materials);
        if (!avatarp(TP) && sizeof(matkeys)) {
            for (i = 0; i < sizeof(matkeys); i++) {
                tracker = 1;
                while (materials[matkeys[i]]) {
                    currentmat = matkeys[i] + " " + tracker;
                    if (ob = present(currentmat, TP)) {
                        if ((int)ob->is_herb() && (string)ob->query_herb_name() == matkeys[i]) {
                            tracker++;
                            materials[matkeys[i]]--;
                            using += ({ ob });
                            continue;
                        }else if ((int)ob->is_component() && (string)ob->query_name() == matkeys[i]) {
                            dc = materials[matkeys[i]];
                            if ((int)ob->query_comp_quantity() < dc) {
                                dc = dc - (int)ob->query_comp_quantity();
                            }
                            materials[matkeys[i]] -= dc;
                            while (dc--) {
                                using += ({ ob });
                                continue;
                            }
                            continue;
                        }else {
                            tracker++;
                            continue;
                        }
                    }else {
                        tell_object(TP, "You don't have enough " + matkeys[i] + " to create a " + myname + "!");
                        return 1;
                    }
                }
            }
        }
        if (mydir == "potions" || mydir == "elixirs") {
            matkeys = filename->query_valid_args();
            if (sizeof(matkeys)) {
                if (!myvar) {
                    tell_object(TP, "That potion requires an argument to be set! See <help brew> for syntax.");
                    return 1;
                }
                if (member_array(myvar, matkeys) == -1) {
                    currentmat = matkeys[0];
                    if (sizeof(matkeys) > 1) {
                        for (i = 1; i < sizeof(matkeys); i++) {
                            currentmat += ", ";
                            currentmat += matkeys[i];
                        }
                    }
                    tell_object(TP, "Sorry, " + myvar + " is not a valid option to create a " + myname + "! Options are " + currentmat + ".");
                    return 1;
                }
            }
        }

        tell_room(ETP, TPQCN + " takes the time to brew a new alchemical mix.", TP);
        tell_object(TP, "You take the time to brew a new alchemical mix.");

        dc = datamap[myname]["dc"];

        expdrain = ((((int)TP->query_exp() / 500) * dc) / (int)TP->query_skill("healing")); // based on enchanting; exp * dc / heal skill / 500
        // putting a cap on how high the exp drain can be.  These get out of hand for potions. Maybe consider different exp max for oils and elixirs, but shouldn't cost
        // several hundred thousand exp for a single potion of remove blindness -Ares
        max_exp_drain = (dc * 2500) / (int)TP->query_skill("healing");

        if (expdrain > max_exp_drain) {
            expdrain = max_exp_drain;
        }

        //if(!avatarp(TP)) TP->add_exp((-1)*expdrain);

        if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0) {
            TP->add_exp(expdrain * -1);
        }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1) {
            if ((int)TP->set_XP_tax(expdrain, 0, "improvement") == -1) {
                tell_object(TP, "You can't seem to figure out how to make the potion, perhaps later.");
                return 1;
            }
        }

        if (!avatarp(TP) && sizeof(using)) {
            for (i = 0; i < sizeof(using); i++) {
                if (objectp(using[i])) {
                    if (using[i]->is_component()) {
                        using[i]->set_comp_quantity((int)using[i]->query_comp_quantity() - 1);
                        if ((int)using[i]->query_comp_quantity() <= 0) {
                            using[i]->remove();
                        }
                    }else {
                        using[i]->remove();
                    }
                    continue;
                }
                continue;
            }
        }
        strength = (int)TP->query_skill("healing") + roll_dice(1, 20);
        myprof = strength - dc;
        myvalue = datamap[myname]["value"] * roll_dice(1, 12);

        ob2 = new(filename);
        if (mydir != "oils" && mydir != "powders" && mydir != "misc") { // these do not scale/etc
            ob2->set_myname(myname);
            ob2->set_dc(dc);
            ob2->set_strength(strength);
            if (mydir == "potions" || mydir == "elixirs") {
                ob2->set_hue(datamap[myname]["color"]);
                if (myvar) {
                    ob2->set_myvar(myvar);
                }
            }
            ob2->set_value(myvalue);
        }
        if (myprof < 0) {
            if (mydir == "oils" || mydir == "powders" || mydir == "misc") { // these have no backfire; either they're good, or they don't make anything to use. At some point we can change that.
                tell_object(TP, "Try as you might, you can't seem to get the components to balance correctly. You end up with nothing but useless scraps.");
                ob2->remove();
                return 1;
            }
            ob2->set_reversed(1);
            // let's make it more realistic; if it's botched, strength is only as much as they failed by.
            // of course, if a L1 makes a potion of haste, it's going to be incredibly badly botched...
            myprof = dc - strength;
            ob2->set_strength(myprof);
        }
        ob2->move(ETP);
        return 1;
    }
    if (mytype == "materials") { // list off required materials and exp for a brew
        dc = datamap[myname]["dc"];
        expdrain = ((((int)TP->query_exp() / 500) * dc) / (int)TP->query_skill("healing")); // based on enchanting; exp * dc / heal skill / 500

        max_exp_drain = (dc * 2500) / (int)TP->query_skill("healing");

        if (expdrain > max_exp_drain) {
            expdrain = max_exp_drain;
        }

        tell_object(TP, "%^BOLD%^%^CYAN%^Required to create a " + myname + ":%^RESET%^");
        tell_object(TP, "%^BOLD%^%^WHITE%^-experience: " + expdrain + "%^RESET%^");
        materials = datamap[myname]["materials"];
        matkeys = keys(materials);
        for (i = 0; i < sizeof(matkeys); i++) {
            tell_object(TP, "%^BOLD%^%^WHITE%^-" + matkeys[i] + ": " + materials[matkeys[i]] + "%^RESET%^");
        }

        matkeys = filename->query_valid_args();
        if (sizeof(matkeys)) {
            currentmat = matkeys[0];
            if (sizeof(matkeys) > 1) {
                for (i = 1; i < sizeof(matkeys); i++) {
                    currentmat += ", ";
                    currentmat += matkeys[i];
                }
            }
            tell_object(TP, "%^YELLOW%^This potion requires an argument to be specified during creation. Valid options are " + currentmat + ".");
        }
        return 1;
    }
    return notify_fail("Please see <help brew> for syntax.\n");
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

brew - make a potion

%^CYAN%^SYNOPSIS%^RESET%^

brew list kits|potions|elixirs|oils|powders|misc
brew materials %^ORANGE%^%^ULINE%^POTION%^RESET%^
brew create %^ORANGE%^%^ULINE%^POTION%^RESET%^ [| %^ORANGE%^%^ULINE%^ARG%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

This command utilizes your healing skill to create a potion.

Commands that apply are:

%^ORANGE%^<brew list kits|potions|elixirs|oils|powders|misc>%^RESET%^

    View a list of available brews of specified type.

%^ORANGE%^<brew materials %^ORANGE%^%^ULINE%^POTION%^RESET%^%^ORANGE%^>%^RESET%^

    View materials required to create a %^ORANGE%^%^ULINE%^POTION%^RESET%^.

<brew create %^ORANGE%^%^ULINE%^POTION%^RESET%^ [| %^ORANGE%^%^ULINE%^ARG%^RESET%^]

    Create a %^ORANGE%^%^ULINE%^POTION%^RESET%^. For some potions, optionally with the %^ORANGE%^%^ULINE%^ARGUMENT%^RESET%^

%^CYAN%^EXAMPLES%^RESET%^

%^ORANGE%^<brew create potion of optic transmogrification | silver>%^RESET%^

    Create potion that will change your eye color to silver.

%^CYAN%^SEE ALSO%^RESET%^

skills, healing, brew potion

");
}
