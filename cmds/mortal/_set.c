#include <std.h>
#include <daemons.h>

string* VALID_SETTINGS = ({ "brief", "brief_combat", "hints", "logon_notify", "persist", "simpleinv", "expgain", "hardcore", "levelcheck", "no_reward", "taxperc", "columns", "vcolumns", "scrlines", "scrwidth", "term", "reader" });

object tp;

/**
 * @brief Manages various user settings.
 *
 * To add a setting place it in order you want it to be in in
 * VALID_SETTINGS array, then add set_NAME(string) function to set
 * that setting and get_NAME function to get that setting. Don't
 * forget to append explanation to helpfile.
 */


int cmd_set(string args)
{
    string setting, value;

    tp = TP;

    if (sizeof(args) > 0) {
        if (avatarp(TP)) {
            string * usernames = users()->query_name();
            if (member_array(args, usernames) != -1) {
                tp = find_player(args);
                args = 0;
            }
        }
    }

    if (!stringp(args)) {
        string stng;
        write("%^BLUE%^--=%^BOLD%^<%^WHITE%^ Settings %^BLUE%^>%^RESET%^%^BLUE%^=--%^RESET%^");
        foreach(stng in VALID_SETTINGS)
        {
            catch(write("%^WHITE%^ " + arrange_string(stng + " %^BOLD%^%^BLACK%^--------------", 14) + "%^RESET%^%^GREEN%^ : %^RESET%^" + colorize_value((string)call_other(TO, "get_" + stng))));
        }
        return 1;
    }

    if (sscanf(args, "%s %s", setting, value) != 2) {
        write("You must specify both setting and value.");
        return 1;
    }
    if (member_array(setting, VALID_SETTINGS) == -1) {
        write("Invalid setting.");
        return 1;
    }

    {
        int status = call_other(TO, "set_" + setting, value);
        if (status == 0) {
            write("%^WHITE%^%^BOLD%^Unable to set %^RED%^" + setting + "%^WHITE%^ to %^RED%^" + value + "%^WHITE%^.");
            return 1;
        }
        if (status == 1) {
            write("%^WHITE%^%^BOLD%^Setting %^GREEN%^" + setting + "%^WHITE%^ to %^CYAN%^" + value + "%^WHITE%^.");
            return 1;
        }
    }

    return 1;
}

int set_simpleinv(string val)
{
    string* valid_values = ({ "on", "off" });
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    if (val == "off") {
        tp->delete("simple inventory");
    } else {
        tp->set("simple inventory", 1);
    }
    return 1;
}

string get_simpleinv()
{
    if (tp->query("simple inventory")) {
        return "on";
    } else {
        return "off";
    }
}

int set_hints(string val)
{
    string* valid_values = ({ "on", "off" });
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    if (val == "on") {
        tp->delete("no hints");
    } else {
        tp->set("no hints", 1);
    }
    return 1;
}

string get_hints()
{
    if (tp->query("no hints")) {
        return "off";
    } else {
        return "on";
    }
}

int set_term(string val)
{
    string* valid_values;
    valid_values = TERMINAL_D->query_terms();
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    tp->setenv("TERM", val);
    tp->reset_terminal();
    return 1;
}

string get_term()
{
    return tp->getenv("TERM");
}

int set_scrlines(string val)
{
    if (!atoi(val)) {
        write("%^BOLD%^%^RED%^Invalid value, must provide a number.%^RESET%^");
        return 0;
    }
    if (atoi(val) < 2) {
        write("%^BOLD%^%^RED%^Invalid value, must be bigger than 2.%^RESET%^");
        return 0;
    }
    tp->setenv("LINES", val);
    return 1;
}

string get_scrlines()
{
    return tp->getenv("LINES");
}

int set_scrwidth(string val)
{
    if (!atoi(val)) {
        write("%^BOLD%^%^RED%^Invalid value, must provide a number.%^RESET%^");
        return 0;
    }
    if (atoi(val) < 2) {
        write("%^BOLD%^%^RED%^Invalid value, must be bigger than 2.%^RESET%^");
        return 0;
    }
    if (atoi(val) > 2000) {
        write("%^BOLD%^%^RED%^Invalid value, must be less than 2000.%^RESET%^");
        return 0;
    }
    tp->setenv("SCREEN", val);
    return 1;
}

string get_scrwidth()
{
    return (tp->getenv("SCREEN")) ? tp->getenv("SCREEN") : "0";
}

int set_columns(string val)
{
    if (!atoi(val)) {
        write("%^BOLD%^%^RED%^Invalid value, must provide a number.%^RESET%^");
        return 0;
    }
    if (atoi(val) < 1) {
        write("%^BOLD%^%^RED%^Invalid value, must be bigger than 1.%^RESET%^");
        return 0;
    }
    tp->setenv("COLUMNS", val);
    return 1;
}

string get_columns()
{
    return (tp->getenv("COLUMNS")) ? tp->getenv("COLUMNS") : "0";
}

int set_vcolumns(string val)
{
    string* valid_values = ({ "on", "off" });
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    if (val == "on") {
        tp->setenv("VCOLUMNS", 1);
    } else {
        tp->remove_env("VCOLUMNS");
    }
    return 1;
}

string get_vcolumns()
{
    return (tp->getenv("VCOLUMNS")) ? "on" : "off";
}

int set_logon_notify(string val)
{
    string* valid_values = ({ "on", "off" });
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    if (val == "off") {
        this_player()->set_logon_notify(0);
    } else {
        this_player()->set_logon_notify(1);
    }
    return 1;
}

string get_logon_notify()
{
    if(tp->query_logon_notify())
        return "on";
    else
        return "off";
}

int set_brief(string val)
{
    string* valid_values = ({ "on", "off" });
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    if (this_player()->query_verbose() && val == "on") {
        this_player()->set_brief();
    }
    if (!this_player()->query_verbose() && val == "off") {
        this_player()->set_brief();
    }
    return 1;
}

string get_brief()
{
    if (this_player()->query_verbose()) {
        return "off";
    } else {
        return "on";
    }
}

int set_persist(string val)
{
    string* valid_values = ({ "on", "off" });
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    if (val == "on") {
        this_player()->set("persist_login", 1);
    }
    if (val == "off") {
        this_player()->delete("persist_login");
    }
    return 1;
}

int get_persist(string val)
{
    if(this_player()->query("persist_login"))
        return "on";
    else
        return "off";
}

int set_reader(string val)
{
    string* valid_values = ({ "on", "off" });
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    if (val == "on") {
        this_player()->set("reader", 1);
    }
    if (val == "off") {
        this_player()->delete("reader");
    }
    return 1;
}

int get_reader(string val)
{
    if(this_player()->query("reader"))
        return "on";
    else
        return "off";
}

int set_brief_combat(string val)
{
    string* valid_values = ({ "on", "off" });
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    if (tp->query_verbose_combat() && val == "on") {
        tp->set_brief_combat();
    }
    if (!tp->query_verbose_combat() && val == "off") {
        tp->set_brief_combat();
    }
    return 1;
}

string get_brief_combat()
{
    if (this_player()->query_verbose_combat()) {
        return "off";
    } else {
        return "on";
    }
}

int set_expgain(string val)
{
    string* valid_values = ({ "on", "off" });
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    if (val == "on" && (USER_D->no_exp(tp))) {
        USER_D->toggle_no_exp(tp);
    }
    if (val == "off" && (!USER_D->no_exp(tp))) {
        USER_D->toggle_no_exp(tp);
    }
    return 1;
}

string get_expgain()
{
    if (USER_D->no_exp(tp)) {
        return "off";
    } else {
        return "on";
    }
}

int set_hardcore(string val)
{
    string* valid_values = ({ "on", "off" });
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    if (val == "on") {
        tell_object(tp, "%^BOLD%^Are you sure?.. You will loose all your levels and equipment if you die.");
        tell_object(tp, "%^BOLD%^Type %^ORANGE%^YES%^WHITE%^ to confirm.");
        input_to("confirm_hardcore");
        return 2;
    }
    if (val == "off") {
        write("%^BOLD%^%^RED%^Nope. You keep suffering.");
        return 0;
    }
    return 1;
}

string get_hardcore()
{
    if (tp->query("hardcore")) {
        return "on";
    } else {
        return "off";
    }
}

void confirm_hardcore(string str)
{
    if (str == "YES") {
        tell_object(tp, "%^BOLD%^Turning hardcore mode on you %^RED%^on%^WHITE%^.");
        tp->set("hardcore", 1);
    }else {
        tell_object(tp, "%^BOLD%^A wise decision.");
    }
}

int set_levelcheck(string val)
{
    string* valid_values = ({ "on", "off" });
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    if (val == "off") {
        tell_object(tp, "%^BOLD%^Are you sure?.. You will become a valid target for pk for high-levels.");
        tell_object(tp, "%^BOLD%^Type %^ORANGE%^YES%^WHITE%^ to confirm.");
        input_to("confirm_levelcheck");
        return 2;
    }
    if (val == "on") {
        write("%^BOLD%^%^RED%^Nope. You keep suffering.");
        return 0;
    }
    return 1;
}

void confirm_levelcheck(string str)
{
    if (str == "YES") {
        tell_object(tp, "%^BOLD%^%^BLACK%^DEATH IS THE ROAD TO AWE.");
        tell_object(tp, "%^BOLD%^Turning levelcheck on you %^RED%^off%^WHITE%^.");
        tp->set("no_levelcheck", 1);
    }else {
        tell_object(tp, "%^BOLD%^A wise decision.");
    }
}

string get_levelcheck()
{
    if (tp->query("no_levelcheck")) {
        return "off";
    } else {
        return "on";
    }
}

int set_no_reward(string val)
{
    string* valid_values = ({ "on", "off" });
    if (member_array(val, valid_values) == -1) {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ " + implode(valid_values, ", "));
        return 0;
    }
    if (val == "on") {
        tp->set("no_reward", 1);
    }
    if (val == "off") {
        write("%^BOLD%^%^RED%^Nope. You keep suffering.");
        return 0;
    }
    return 1;
}

string get_no_reward()
{
    if (tp->query("no_reward")) {
        return "on";
    } else {
        return "off";
    }
}

int set_taxperc(string val)
{
    int perc;
    if (!atoi(val)) {
        write("%^BOLD%^%^RED%^Invalid value, must provide a number.%^RESET%^");
        return 0;
    }
    perc = atoi(val);
    if (USER_D->set_character_improvement_tax_percent(tp, perc)) {
        return 1;
    } else {
        return 0;
    }
}

int get_taxperc()
{
    return sprintf("%d", USER_D->get_character_improvement_tax_percent(tp));
}

string colorize_value(string str)
{
    if (!str) {
        return "";
    }
    if (str == "off") {
        return "%^RED%^off%^RESET%^";
    }
    if (str == "on") {
        return "%^GREEN%^on%^RESET%^";
    }
    if (regexp(str, "[0-9]+")) {
        return "%^CYAN%^" + str + "%^RESET%^";
    }

    return "%^ORANGE%^" + str + "%^RESET%^";
}

void help()
{
    //NOTE: PRESERVE FORMAT OF THIS HELPFILE FOR SORTING PURPOSES.
    //Use M-x sort-lines if you're using emacs or |sort in vim.
    write("
%^CYAN%^NAME%^RESET%^

set - manipulate various mud settings

%^CYAN%^SYNOPSIS%^RESET%^

set %^ORANGE%^%^ULINE%^SETTING%^RESET%^ %^ORANGE%^%^ULINE%^VALUE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

You can manipulate numerous mud settings:

%^ULINE%^%^CYAN%^Notifications and messages:%^RESET%^

%^CYAN%^brief %^GREEN%^on|off%^RESET%^\n  This will turn on or off display of room's long description. Useful for screenreaders. %^ULINE%^Default value is off.%^RESET%^\n
%^CYAN%^brief_combat %^GREEN%^on|off%^RESET%^\n  This will turn on or off display of verbose combat. %^ULINE%^Default value is on.%^RESET%^\n
%^CYAN%^hints %^GREEN%^on|off%^RESET%^\n  This will turn on or off display of periodic hints. %^ULINE%^Default value is on.%^RESET%^\n
%^CYAN%^logon_notify %^GREEN%^on|off%^RESET%^\n  This will turn on or off display of people joining the game. %^ULINE%^Default value is on.%^RESET%^\n
%^CYAN%^persist %^GREEN%^on|off%^RESET%^\n  Turning persistent login will allow you not to idle out upon reaching a timeout. %^ULINE%^Default value is off.%^RESET%^\n
%^CYAN%^simpleinv %^GREEN%^on|off%^RESET%^\n  This will turn on or off displaying equipped inventory items in %^ORANGE%^<inventory>%^RESET%^ command. When it is toggled off, you can see equipped inventory in %^ORANGE%^<eq>%^RESET%^. %^ULINE%^Default value is off.%^RESET%^\n
%^ULINE%^%^CYAN%^Experience points and tax:%^RESET%^

%^CYAN%^expgain %^GREEN%^on|off%^RESET%^\n  This will turn on or off experience gain for your character. While it is off, you will get NO EXPERIENCE. %^ULINE%^Default value is on.%^RESET%^\n
%^CYAN%^hardcore %^GREEN%^on%^RESET%^\n  If you loved good old days and want more. Harcore mode can't be turned off. %^ULINE%^Default value is off.%^RESET%^\n
%^CYAN%^levelcheck %^GREEN%^off%^RESET%^\n  Disabling this will make you a valid target across all levels. Levelcheck can't be turned on without petitioning. %^ULINE%^Default value is on.%^RESET%^\n
%^CYAN%^no_reward %^GREEN%^on|off%^RESET%^\n  Opt out from receiving rewards, granted with %^ORANGE%^<reward>%^RESET%^ command and avatar plots. %^ULINE%^Default value is off.%^RESET%^\n
%^CYAN%^taxperc %^GREEN%^%^ULINE%^NUMBER%^RESET%^\n  This will define how much of your experience gain goes towards paying off your experience tax. This value will grow with your levels, but you may force its increase via this setting. %^ULINE%^Default value is on.%^RESET%^\n
%^ULINE%^%^CYAN%^Terminal and display:%^RESET%^

%^CYAN%^columns %^GREEN%^%^ULINE%^NUMBER%^RESET%^\n  Set how many maximum columns you do want to see where multicolumn output is appliable and screen width allows. %^ULINE%^Default value: 0%^RESET%^\n
%^CYAN%^vcolumns %^GREEN%^on|off%^RESET%^\n  Set whether you want to sort columns vertically. %^ULINE%^Default value: off%^RESET%^\n
%^CYAN%^scrlines %^GREEN%^%^ULINE%^NUMBER%^RESET%^\n  Set how many lines appear for paged information. %^ULINE%^Default value: 20%^RESET%^\n
%^CYAN%^scrwidth %^GREEN%^%^ULINE%^NUMBER%^RESET%^\n  Set screen width for text wrapping. %^ULINE%^Default value: 75%^RESET%^\n
%^CYAN%^term %^GREEN%^"+implode(TERMINAL_D->query_terms(),"|")+"%^RESET%^\n  This will set your current terminal to a given value. The value 'unknown' sets terminal to the one without colors. If you can't see bold black color, terinal with %^ORANGE%^no-black%^RESET%^ such as %^ORANGE%^ansi-no-black%^RESET%^ might aid you. Terminals with no-bg setting disable background colors. %^ULINE%^Default value is set on first login.%^RESET%^\n
To see current values use %^ORANGE%^<set>%^RESET%^ without arguments.

%^CYAN%^SEE ALSO%^RESET%^

adjective, background, chfn, colors, describe, flag, lines, message, passwd, prompt, speech, history
");
}
