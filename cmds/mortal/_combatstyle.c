#include <std.h>
inherit DAEMON;

int cmd_combatstyle(string str)
{
    string myclass, mystyle, filename, * available, returnmsg;
    int i, feats;
    mapping oldfeats;

    if (base_name(ETP) == "/d/shadowgate/setter") {
        tell_object(TP,"You must finish the creation before choosing your combatstyle.");
        return 1;
    }

    if (!str) {
        tell_object(TP, "You need to specify <combatstyle classname> to see what styles are available, or <combatstyle classname style> to set your combat style.");
        return 1;
    }
    if (!sscanf(str, "%s %s", myclass, mystyle)) {
        if (!TP->is_class(str)) {
            tell_object(TP, "You don't have any levels in the " + str + " class.");
            return 1;
        }
        filename = "/std/class/" + str + ".c";
        if (!file_exists(filename)) {
            tell_object(TP, "There has been an error, no settings for the " + str + " class. Please notify a wiz.");
            return 1;
        }
        available = filename->combat_styles();
        if (!sizeof(available)) {
            tell_object(TP, "The " + str + " class doesn't offer any combat styles at this point.");
            return 1;
        }
        returnmsg = available[0];
        if (sizeof(available) > 1) {
            for (i = 1; i < sizeof(available); i++) {
                returnmsg += ", ";
                returnmsg += available[i];
            }
        }
        tell_object(TP, "Your class offers the following combat style choices: " + returnmsg + ".");
        returnmsg = (string)TP->query_combat_spec(str);
        if (!returnmsg) {
            returnmsg = "";
        }
        if (returnmsg != "") {
            tell_object(TP, "You have chosen the " + returnmsg + " combat style. You must abandon your " + str + " levels to start afresh with a new style.");
        }else {
            tell_object(TP, "You have yet to choose a combat style for the " + str + " class.");
        }
        return 1;
    }
    returnmsg = (string)TP->query_combat_spec(myclass);
    if (!returnmsg) {
        returnmsg = "";
    }
    if (returnmsg != "") {
        tell_object(TP, "You have already chosen the " + returnmsg + " combat style. You must abandon your " + myclass + " levels to start afresh with a new style.");
        return 1;
    }
    filename = "/std/class/" + myclass + ".c";
    if (!file_exists(filename)) {
        tell_object(TP, "There has been an error, no settings for the " + myclass + " class. Please notify a wiz.");
        return 1;
    }
    available = filename->combat_styles();
    if (!sizeof(available)) {
        tell_object(TP, "The " + myclass + " class doesn't offer any combat styles at this point.");
        return 1;
    }
    if (member_array(mystyle, available) == -1) {
        returnmsg = available[0];
        if (sizeof(available) > 1) {
            for (i = 1; i < sizeof(available); i++) {
                returnmsg += ", ";
                returnmsg += available[i];
            }
        }
        tell_object(TP, "The " + myclass + " class does not offer the " + mystyle + " combat style. It offers the following combat style choices: " + returnmsg + ".");
        return 1;
    }
    TP->set_combat_spec(myclass, mystyle);
    tell_object(TP, "Your " + myclass + " combat style has been set to " + mystyle + ".");
    if (myclass == "ranger" && mystyle == "dual wield") {
        return 1;                                                // no need to reset class feats from the default set for this. N, 1/14.
    }
    feats = (int)TP->query_other_feats_gained();
    feats += (int)TP->query("free_feats");
    TP->clear_feats();
    TP->set("free_feats", feats);
    tell_object(TP, "Your feats have been reset to allow for your new combat style. Please don't forget to re-assign them!");
    TP->force_me("feats fix");
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

combatstyle - change your class combat style

%^CYAN%^SYNOPSIS%^RESET%^

combatstyle %^ORANGE%^%^ULINE%^CLASS%^RESET%^ [%^ORANGE%^%^ULINE%^STYLE%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

This command allows you to select your character's combat style for each class. Not all classes have combat styles available. Your chosen combat style will designate many of your abilities, and can include both feats and spells (for those classes that have them).

%^CYAN%^SEE ALSO%^RESET%^

feats, abandon
");
}
