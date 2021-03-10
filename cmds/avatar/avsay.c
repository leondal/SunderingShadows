//avsay - a concept to let avatars set up profiles for "fake" npcs in order
//to use the say command to speak as them for plots - that will hopefully
//allow players to be able to retrieve stuff via last say, last whisper, etc.

#include <std.h>
#include "items.h"
#include <move.h>

#include <money.h>
#include <valid_bonuses.h>
#include "types.h"
#include "valid_armors.h"
#include <security.h>
#include <security.h>
#include <daemons.h>

inherit OBJECT;

#include <langs.h>

#include "valid_weapons.h"

string CheckStatus(string which);
void set_profile_info(string str, string arg);
void change_profile_info(string str, string arg);
void check_replace_profile(string str, string mystr);
void check_clear_all(string str);
void restore_avsay_profile(string myprofile);
void save_avsay_profile(string str);
void show_category(string input);
void pick_menu_item(string str);
void display_menu();
void update_this_menu();
void ResetAll(string otype);
void do_response(string msg, string msg_type);
void hl(string str);
string repeat_string(string rep, int amt);
string strip_colors(string sh);
void exit();
void activate_profile();
void manual_set_and_save_avsay_profile(mapping tmp);


nosave string DIR;
nosave string PAD = "%^BOLD%^%^GREEN%^>>%^RESET%^ ";
nosave int menu_place = 0;
nosave string cur_menu, MYDIR;
nosave string menu_header = repeat_string("%^BOLD%^%^CYAN%^--%^RESET%^", 33);
nosave string *ThisMenu;
nosave string RestoredProfile;
nosave string *MainMenu = ({"Profile Name", "Character Name", "Speech", "Language", "Color", "Activate Profile", "Restore Profile", "Default Profile"});
nosave string *AllMenus = ({"Clear All", "Finish"});

mapping ProfileInfo = (["Character Name" : "NIL", "Speech" : "NIL", "Language" : "NIL", "Profile Name" : "NIL", "Color" : "NIL"]);

string strip_colors(string sh)
{
    string output = "", *list = ({});
    string *words = ({});
    int i;
    if(!sh)
    {
        return output;
    }
    words = explode(sh, "%^");

    list +=({"RED", "YELLOW", "BLUE",
    "GREEN", "MAGENTA", "ORANGE", "CYAN", "BLACK", "WHITE"});

    list += ({ "B_RED", "B_YELLOW", "B_BLUE", "B_GREEN",
    "B_MAGENTA", "B_ORANGE", "B_CYAN", "B_BLACK", "B_WHITE"});

    list += ({"BOLD", "FLASH", "RESET"});

    for(i = 0;i < sizeof(list);i++)
    {
        words = words - ({ list[i] });
    }
    output = implode(words,"");
    return output;
}

string repeat_string(string rep, int amt)
{
    string tmp = "";
    if(!stringp(rep)) return "";
    amt = to_int(amt);
    if(!intp(amt)) return "";
    while(amt > 0)
    {
        amt--;
        tmp += rep;
    }
    return tmp;
}

void hl(string str)
{
    return "%^BOLD%^%^CYAN%^"+str+"%^RESET%^";
}

void do_response(string msg, string msg_type)
{
    string error_header = repeat_string("%^BOLD%^%^RED%^--%^RESET%^", 35);
    string msg_header = repeat_string("%^BOLD%^%^YELLOW%^--%^RESET%^", 35);
    string rdec = "%^BOLD%^%^YELLOW%^|%^RESET%^";
    string edec = "%^BOLD%^%^RED%^|%^RESET%^";
    string tmp_string;
    if(msg_type == "error" || msg_type == "warning")
    {
        tmp_string = edec+"\t\t\t\t"+capitalize(msg_type);
        tmp_string += repeat_string(" ", 42 - strlen(strip_colors(tmp_string))) + edec;
        tmp_string = error_header + "\n" + tmp_string +"\n" + error_header +"\n" + msg + "\n";
    }
    if(msg_type == "msg")
    {
        tmp_string = rdec+"\t\t\t\tResponse";
        tmp_string += repeat_string(" ", (42 - strlen(strip_colors(tmp_string)))) + rdec;
        tmp_string = msg_header + "\n" + tmp_string + "\n" + msg_header + "\n" + msg + "\n";
    }
    write(tmp_string);
}

void init()
{
    ::init();
    cur_menu = "main";
    update_this_menu();
    display_menu();
    input_to("pick_menu_item");
}

void ResetAll(string otype)
{
    ProfileInfo = (["Character Name" : "NIL", "Speech" : "NIL", "Language" : "NIL", "Profile Name" : "NIL"]);
	cur_menu = "main";
	RestoredProfile = "";
	update_this_menu();
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

void update_this_menu()
{
    ThisMenu = ({});
    if(cur_menu == "main")
    {
        ThisMenu += MainMenu + AllMenus;
    }
    if(cur_menu == "Restore Profile")
    {
        ThisMenu += get_dir("/d/avatars/"+TPQN+"/profiles/*.o") + ({"Back"});
    }
    if(cur_menu == "Language")
    {
        ThisMenu += ALL_LANGS + ANIMAL_LANGS + ({"All", "Back"});
    }
   // ThisMenu += AllMenus;
}


void display_menu()
{
    int x;
    int count = 0;
    string tmp_str = "";
    string sdec = "%^BOLD%^%^CYAN%^|%^RESET%^";
    string tmp_display = menu_header + "\n\t\tAvsay Profile Editor\n"+menu_header+"\n"+sdec;
    string num = "";
    for(x = 0;x < sizeof(ThisMenu);x++)
    {
        count++;
        if(x < 9) { num = " " + count + " "; }
        else { num = count + " "; }
        tmp_str = "\t" + num + PAD + capitalize(ThisMenu[x]) + " ";
        tmp_str += repeat_string(" ", (30 - strlen(strip_colors(tmp_str))));
        tmp_str += CheckStatus(ThisMenu[x]+"");
        tmp_str += repeat_string(" ", (58 - strlen(strip_colors(tmp_str)))) + sdec;
        tmp_display += tmp_str + "\n";
        if(x != (sizeof(ThisMenu) - 1))
        {
            tmp_display += sdec;
        }
    }
    tmp_display += menu_header + "\nPlease Select One of The Above Options.\n"+
    "Input ** At any time to exit.\n" + menu_header;

    tell_object(TP, tmp_display);
}

//FUNCTION for picking a menu item and directing to the right
//submenu/request for input, etc;

void pick_menu_item(string str)
{
    int max, input;
    string true_input;
    if(str == "**") exit();
    max = sizeof(ThisMenu);
    input = to_int(str);
    if(input > max || input < 1)
    {
        do_response("You have entered "+hl(""+input+"")+".  Please input a number from "+
        hl("1 - "+max+"")+".", "error");
        display_menu();
        input_to("pick_menu_item");
        return 1;
    }
    true_input = ThisMenu[input - 1];
    show_category(true_input);
    //input_to("pick_menu_item");
    return 1;
}
//END


void show_category(string input)
{
    string tmp, tmp_msg;
    mapping LoadedProfile;
    if(input == "Finish")
    {
        exit();
        return;
    }

    if(input == "Clear All")
    {
        do_response("Are you sure you wish to "+hl(input)+"?\n"+
        "You will lose "+hl("ALL")+" entered data.\n"+
        "Proceed, y/n? **NOTE** This will not remove a saved profile.", "warning");
        input_to("check_clear_all");
        return 1;
    }

    if(input == "Profile Name" || input == "Character Name" || input == "Speech"
    || input == "Color")
    {
        if(ProfileInfo[input] == "NIL")
        {
            do_response("Please enter the "+hl(input)+
            " that you want for this profile.", "msg");
            input_to("set_profile_info", input);
        }
        else
        {
            do_response("Are you sure that you want to change "+
            "the "+hl(input)+"? It is currently set to "+
            hl(ProfileInfo[input])+".", "msg");
            input_to("change_profile_info", input);
        }
        return 1;
    }

    if(input == "Activate Profile")
    {
        do_response("Attempting to activate avsay Profile", "msg");
        activate_profile();
        display_menu();
        input_to("pick_menu_item");
        return 1;
    }

    if(input == "Language")
    {
        cur_menu = "Language";
        update_this_menu();
        display_menu();
        input_to("pick_menu_item");
        return 1;
    }

    if(input == "Default Profile")
    {
        do_response("Setting your profile to "+hl(input)+" which "+
        "is simply yourself.", "msg");
        TP->delete("avsayprofile");
        display_menu();
        input_to("pick_menu_item");
        return 1;
    }

    if(cur_menu == "Language")
    {
       /* if(input == "Back")
        {
            cur_menu = "main";
            update_this_menu();
            display_menu();
            input_to("pick_menu_item");
            return 1;
        }*/
        ProfileInfo["Language"] = input;
        cur_menu = "main";
        display_menu();
        input_to("pick_menu_item");
        return 1;
    }

    if(input == "Restore Profile")
    {
        cur_menu = "Restore Profile";
        LoadedProfile = TP->query("avsayprofile");
        if(mapp(LoadedProfile))
        {
            RestoredProfile = LoadedProfile["Profile Name"];
        }
        update_this_menu();
        display_menu();
        input_to("pick_menu_item");
        return 1;
    }

    if(cur_menu == "Restore Profile")
    {
        if(input == "Back")
        {
            cur_menu = "main";
            update_this_menu();
            display_menu();
            input_to("pick_menu_item");
            return 1;
        }
        restore_avsay_profile(input);
        RestoredProfile = input;
        display_menu();
        input_to("pick_menu_item");
        return 1;
    }
}

void manual_set_and_save_avsay_profile(mapping tmp)
{
    if(!mapp(tmp)) return;
    ProfileInfo = tmp;
    save_avsay_profile(ProfileInfo["Profile Name"]);
    return;
}

void save_avsay_profile(string str)
{
    seteuid(UID_ROOT);
    if(!get_dir("/d/avatars/"+TPQN+"/profiles/")) mkdir("/d/avatars/"+TPQN+"/profiles");

    //TP->delete("avsayprofile");
    //TP->set("avsayprofile", ProfileInfo);
    save_object("/d/avatars/"+TPQN+"/profiles/"+str, 1);
    seteuid(getuid());
}

void restore_avsay_profile(string myprofile)
{
    seteuid(UID_ROOT);
    if(file_exists("/d/avatars/"+TPQN+"/profiles/"+myprofile))
    {
        tell_object(TP, "Attemping to restore profile "+myprofile);
        myprofile = replace_string(myprofile, ".o", "");
        restore_object("/d/avatars/"+TPQN+"/profiles/"+myprofile, 1);
       // TP->delete("avsayprofile");
       // TP->set("avsayprofile", ProfileInfo);
    }
    seteuid(getuid());
}


//If they choose Clear All - Make sure they really want to - Saide
void check_clear_all(string str)
{
    if(str == "**") return exit();
    if(lower_case(str[0..0]) == "y")
    {
        do_response("Clearing "+hl("ALL")+" data...", "warning");
        ResetAll("NIL");
        return 1;
    }
    do_response("Aborting... not reseting data...", "msg");
    display_menu();
    input_to("pick_menu_item");
    return 1;
}
//End of Clear All Check


void check_replace_profile(string str, string mystr)
{
    if(str == "**") return exit();
    if(lower_case(str[0..0]) == "y")
    {
        do_response("The profile "+hl(mystr)+" will be replaced when you save.", "warning");
        display_menu();
        ProfileInfo["Profile Name"] = mystr;
        input_to("pick_menu_item");
        return 1;
    }
    do_response("Aborting... not saving over profile "+hl(str)+".", "msg");
    display_menu();
    input_to("pick_menu_item");
    return 1;
}


void change_profile_info(string str, string arg)
{
    if(str == "**") return exit();

    if(lower_case(str[0..0]) == "y")
    {
        do_response("Please enter the "+hl(arg)+
        " that you want for this profile.", "msg");
        input_to("set_profile_info", arg);
        return 1;
    }

    do_response("Aborting... not changing "+hl(arg)+".", "msg");
    display_menu();
    input_to("pick_menu_item");
    return 1;
}



void set_profile_info(string str, string arg)
{
    if(str == "**") return exit();
    if(!str || str == "" || str == "0")
    {
        do_response("You must enter a valid "+hl(arg)+".\n", "warning");
        input_to("set_profile_info");
        return 1;
    }

    if(arg == "Profile Name")
    {
        str = lower_case(str);
        str = replace_string(str, " ", "_");
    }

    if(arg == "Profile Name" && file_exists("/d/avatars/"+TPQN+"/profiles/"+str+".o"))
    {
        do_response("A profile with the name "+hl(str)+" already exists. Do you want to save over it?", "warning");
        input_to("check_replace_profile", str);
        return 1;
    }

    do_response(capitalize(arg)+" set to \n"+
    hl(str), "msg");

    ProfileInfo[arg] = str;
    display_menu();
    input_to("pick_menu_item");

    return 1;
}


string CheckStatus(string which)
{
    string op = "%^YELLOW%^(%^RESET%^";
    string cl = "%^YELLOW%^)%^RESET%^";
    //Color for Needed
    string nc = "%^BOLD%^%^WHITE%^";
    //Reset
    string rs = "%^RESET%^";
    //Color for something that's set
    string sc = "%^BOLD%^%^GREEN%^";
    //Color for something that's set to Default
    string de = "%^BOLD%^%^RED%^";
    //Color for something that's not set, but also not
    //required
    string tmp;
    string unc = "%^BOLD%^%^CYAN%^";
    string selected_str = op + unc + "Selected" + cl;
    string needed_str = op + nc + "Needed" + cl;
    string set_str = op + sc + "Set" + cl;
    string unset_str = op + unc + "Unset"+ cl;
    string default_str = op + de + "Default" + cl;

    if(which == "Profile Name" || which == "Character Name")
    {
        if(ProfileInfo[which] == "NIL" || ProfileInfo[which] == "")
        {
            return needed_str;
        }
        else { return op + sc + ProfileInfo[which] + cl; }
    }

    if(which == "Speech" || which == "Language")
    {
        if(ProfileInfo[which] == "NIL" || ProfileInfo[which] == "") return "";
        else { return op + sc + ProfileInfo[which] + cl; }
    }

    if(which == "Color")
    {
        if(ProfileInfo[which] == "NIL" || ProfileInfo[which] == "") return "";
        else { return op + sc + ProfileInfo[which] + "color%^RESET%^"+ cl; }
    }

    if(which == "Restore Profile")
    {
        tmp = op + sc + sizeof(get_dir("/d/avatars/"+TPQN+"/profiles/*.o"));
        tmp += " available" + cl;
        return tmp;
    }

    if(cur_menu == "Language")
    {
        if(which == ProfileInfo["Language"]) return selected_str;
    }

    if(cur_menu == "Restore Profile")
    {
        if(which == RestoredProfile) return selected_str;
    }
    return "";
}

void activate_profile()
{
    if(ProfileInfo["Profile Name"] == "NIL" || ProfileInfo["Character Name"] == "NIL")
	{
        do_response("You need to specify a profile name and character name first or load one!", "warning");
		return;
	}
    do_response("Activating profile "+ProfileInfo["Profile Name"]+". Have Fun!", "msg");
    TP->delete("avsayprofile");
    TP->set("avsayprofile", ProfileInfo);
    return;
}

void exit()
{
	if(ProfileInfo["Profile Name"] == "NIL" || ProfileInfo["Character Name"] == "NIL")
	{
        tell_object(TP, "Exiting without a profile assigned.");
		remove();
		return;
	}
    tell_object(TP, "Saving Avsay Profile for "+ProfileInfo["Profile Name"]);
    save_avsay_profile(ProfileInfo["Profile Name"]);
	remove();
    return;
}

//End of Clear All Check
