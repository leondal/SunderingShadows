#include <std.h>
#include <security.h>
#include <objects.h>
#include <daemons.h>

nosave string ACCOUNTS_DIR = "/adm/save/user_accounts/";
nosave int LOADED;
nosave object tp;
nosave int ATTEMPTS;

nosave string DEBUG_TARGET = "ares";
nosave int DEBUG;

private nosave string pass_one,pass_two;
nosave string MM = "%^RESET%^%^MAGENTA%^";
nosave string RR = "%^RESET%^";
nosave string *positions;


string __AccountName;
string *__Characters;
string *__Perks;
string __Password;
string __Email;
string __RealName;


void create();
void show_menu(object obj);
int selection(string str,string menu);
int action(string str,string act);
int create_new_account(string str);
int create_user_account(string str);
int character_has_account();
string query_character_account();
int associate_user_with_account();
int unassociate_user();
string query_account_name();
string query_password();
int load_user_account(string str);
int account_exists(string str);
int character_filter(string str);
int stringCheck(string str);
void set_tp(object obj);
int set_password(string str);
int internal_check_password(string password,string user_account);
int save_this_object();
int save_user_account(string str);
int restore_account(string str);
int exit();
int enter_email_address(string str);
int enter_real_name(string str);
int delete_account(string str);
nomask protected int password_two(string str);
nomask protected int password_one(string str);
nomask protected int enter_password(string str);
nomask protected int change_password(string str);
int new_account_check(string str);
int new_association_check();

void db(string str)
{
    if(!DEBUG) { return; }
    tell_object(find_player(DEBUG_TARGET),str);
    return;
}



void create()
{
    seteuid(UID_ROOT);
    __AccountName = "";
    __Characters = ({});
    __Perks = ({});
    LOADED = 0;
    DEBUG = 1;
    positions = ({});
}

//Added by Saide in order to faciliate
//letting players with a non-newbie on their
//account to skip the newbie area - November, 2016
int check_perks(string player, string myPerk)
{
    string account;
    object the_account;
    int result;

    if(!find_player(player))
    {
        if(!user_exists(player)) { return 0; }
    }
    if(!stringp(myPerk)) return 0;
    account = USERCALL->user_call(player,"query","user_account");

    if(!account) { return 0; }

    if(!account_exists(account)) { return 0; }

    the_account = new(OB_ACCOUNT);
    the_account->load_user_account(account);

    result = the_account->perk_check(myPerk);

    destruct(the_account);

    return result;
}

int is_high_mortal(string player)
{
    return check_perks(player, "high mortal");
}

int is_non_newbie(string player)
{
    return check_perks(player, "player");
}

int is_experienced(string player)
{
    return check_perks(player, "experienced");
}

int perk_check(string str)
{
    switch(str)
    {
        case "high mortal":
            if(member_array("high mortal",__Perks) == -1) { return 0; }
            return 1;
        case "experienced":
            if(member_array("experienced",__Perks) == -1) { return 0; }
            return 1;
        case "player":
            if(member_array("player", __Perks) != -1) { return 1; }
            else if(member_array("high mortal", __Perks) != -1) { return 1; }
            return 0;
        default: return 0;
    }
    return 0;
}


void display_account_info(string account,object obj)
{
    object *users=({});
    string race,name,*classes=({}),position,*perks=({}),display="",class_block="",level_block="",*bad_users=({}),*the_display=({}),mail;
    int i,j,*levels=({}),level,obj_level,character_level,flag;
    mapping mail_stat;


    if(!sizeof(__Characters))
    {
        tell_object(obj,"%^RED%^Error: no characters associated with account.%^RESET%^");
		exit();
        return;
    }

    if(tp != obj) { flag = 1; }

    if(!objectp(obj)) { obj = tp; }

    if(flag)
    {
        if(member_group(geteuid(obj),"law_c"))
        {
            display = "%^RESET%^%^BOLD%^%^GREEN%^Account Name: %^RESET%^%^YELLOW%^"+__AccountName+"\n";
        }
    }
    else
    {
           display = "%^RESET%^%^BOLD%^%^GREEN%^Account Name: %^RESET%^%^YELLOW%^"+__AccountName+"\n";
    }


    obj_level = (int)obj->query_level();


    display += "%^RESET%^%^MAGENTA%^";
    display += arrange_string("Name",18);
    display += arrange_string("Race",10);
    display += arrange_string("Class",30);
    display += arrange_string("Level",8);
    display += arrange_string("Mail?",8);
    display += "%^RESET%^";

    tell_object(obj,display);

    display = "";


    for(i=0;i<sizeof(__Characters);i++)
    {
        class_block = "";
        level_block = "";
        levels = ({});
        mail_stat = ([]);
        mail = "";


        if(!user_exists(__Characters[i]) && !find_player(__Characters[i]))
        {
            bad_users += ({ __Characters[i] });
            continue;
        }


        character_level = (int)USERCALL->user_call(__Characters[i],"query_level");

        if((character_level > 50 ) && (character_level > obj_level)) { continue; }

        else
        {

            display += "%^RESET%^%^BOLD%^";

            name = USERCALL->user_call(__Characters[i],"query_true_name");

            name = capitalize(name);

            display += "%^RESET%^%^BOLD%^%^GREEN%^";

            display += arrange_string(name,18);

            race = USERCALL->user_call(__Characters[i],"query_race");

            race = capitalize(race);

            display += "%^RESET%^%^MAGENTA%^";

            display += arrange_string(race,10);

            classes = USERCALL->user_call(__Characters[i],"query_classes");

            if(!sizeof(classes))
            {
                classes += ({ "none" });
                levels += ({ 0 });
            }

            for(j=0;j<sizeof(classes);j++)
            {
                class_block += "%^RESET%^%^RED%^";
                class_block += capitalize(classes[j]);
                if(j<(sizeof(classes)-1)) { class_block += "%^RESET%^%^BOLD%^%^MAGENTA%^\\"; }

                level = USERCALL->user_call(__Characters[i],"query_class_level",classes[j]);

                levels += ({ "%^RESET%^%^BOLD%^"+level });

                level_block += levels[j];
                if(j<(sizeof(classes)-1)) { level_block += "%^RESET%^%^BOLD%^%^MAGENTA%^\\"; }
            }

            display += arrange_string(class_block,30);

            display += arrange_string(level_block,8);

            mail_stat = (mapping)LOCALPOST_D->mail_status(__Characters[i]);
            if (!mail_stat["unread"]) mail += "n/a";
            else mail += mail_stat["unread"];

            display += "%^BOLD%^%^WHITE%^";

            display += arrange_string(mail,8);

            the_display += ({ display });

            display = "";
            if(position == "Player" && member_array("player", perks) == -1)
            {
                perks += ({"player"});
            }
            if(position == "HM")
            {
                perks += ({ "high mortal" });
                perks = distinct_array(perks);
            }
            if(character_level > 29)
            {
                perks += ({ "experienced" });
                perks = distinct_array(perks);
            }
        }
    }


    obj->more(the_display);

    tell_object(obj,display);

    display = "";

    if(member_group(geteuid(obj),"law_c"))
    {
        display += arrange_string("  %^RESET%^%^BOLD%^Email: "+__Email,40);
        tell_object(obj,display);
    }

    if(sizeof(perks))
    {
        for(i=0;i<sizeof(perks);i++)
        {
            __Perks += ({ perks[i] });
        }
    }

    __Perks = distinct_array(__Perks);

    __Characters -= bad_users;

    __Characters = distinct_array(__Characters);

    save_this_object();
    exit();

    return;
}




void show_menu(object obj)
{
    string display;

    if(!objectp(obj)) { return; }
    if(!objectp(tp)) { set_tp(obj); }

    // no account
    if(!character_has_account())
    {
        display = "\n  %^RESET%^%^BOLD%^Your character is currently not associated with any accounts.%^RESET%^ \n";
        display += "    %^RESET%^%^MAGENTA%^1. %^RESET%^%^BOLD%^Associate character with existing account.%^RESET%^ \n";
        display += "    %^RESET%^%^MAGENTA%^2. %^RESET%^%^BOLD%^Create a new account, your character will be associated with this account.%^RESET%^ \n";
        display += "    %^RESET%^%^YELLOW%^Any other key to exit.%^RESET%^ \n";

        tell_object(tp,display);
        input_to("selection","no_account");
        return;
    }
    else
    {
        __AccountName = query_character_account();
        load_user_account(__AccountName);
        display = "\n  %^RESET%^%^BOLD%^Loading account information for account %^RESET%^%^BOLD%^%^MAGENTA%^"+__AccountName+"%^RESET%^%^BOLD%^.%^RESET%^\n\n";
    }


    display += "    %^RESET%^%^MAGENTA%^1. %^RESET%^%^BOLD%^Display Account Information.%^RESET%^ \n";
    display += "    %^RESET%^%^MAGENTA%^2. %^RESET%^%^BOLD%^Change account email.%^RESET%^ \n";
    display += "    %^RESET%^%^MAGENTA%^3. %^RESET%^%^BOLD%^Change real name.%^RESET%^ \n";
    display += "    %^RESET%^%^MAGENTA%^4. %^RESET%^%^BOLD%^Change account password.%^RESET%^ \n";
    display += "    %^RESET%^%^YELLOW%^Any other key to exit.%^RESET%^ \n";

    tell_object(tp,display);
    input_to("selection","account_actions");
    return;

}


int selection(string str,string menu)
{
    if(str == "abort" || str == "n" || str == "N" || str == "no" || str == "q" || str == "~q")
    {
        tell_object(tp,"%^RESET%^%^YELLOW%^Aborting....");
        show_menu(tp);
        return 0;
    }


    switch(menu)
    {


    ///////////////////////////////////////
    // account creation menus below here //
    ///////////////////////////////////////


    case "confirm_real_name":

        switch(str)
        {
        case "yes":
        case "y":
        case "Y":

            tell_object(tp,"%^RESET%^%^YELLOW%^Confirming real name %^RESET%^%^MAGENTA%^"+__RealName+"%^RESET%^%^YELLOW%^.%^RESET%^\n\n");
            tell_object(tp,"%^RESET%^%^BOLD%^Please enter a password for this account.  This does not have to be the same password that you "
                "use for your characters.  You will need this password to associate additional characters with this account.%^RESET%^");

            input_to("password_one",1);

            return 0;

        default:

            delete_account(__AccountName);
            tell_object(tp,"%^RESET%^%^YELLOW%^Aborting....%^RESET%^");
            show_menu(tp);
            return 0;
        }


    case "real_name":

        if(!enter_real_name(str))
        {
            tell_object(tp,"%^RESET%^%^BOLD%^Please enter the name you really want.  Type <abort> to cancel.");
            input_to("selection","real_name");
            return 0;
        }

        tell_object(tp,"%^RESET%^%^BOLD%^Do you really want %^RESET%^%^MAGENTA%^"+__RealName+"%^RESET%^%^BOLD%^ to be your real name?");
        tell_object(tp,"%^RESET%^%^YELLOW%^  <y>es or <n>o.%^RESET%^");
        input_to("selection","confirm_real_name");
        return 0;


    case "confirm_email":

        switch(str)
        {
        case "yes":
        case "y":
        case "Y":

            tell_object(tp,"%^RESET%^%^YELLOW%^Confirming email address %^RESET%^%^MAGENTA%^"+__Email+"%^RESET%^%^YELLOW%^.\n\n");
            tell_object(tp,"%^RESET%^%^BOLD%^Please enter your real name.  This doesn't have to be a full name, a first name or nickname will suffice.");
            input_to("selection","real_name");
            return 0;

        default:

            tell_object(tp,"%^RESET%^%^YELLOW%^Aborting....");
            delete_account(__AccountName);
            show_menu(tp);
            return 0;
        }


    case "enter_email":

        if(!enter_email_address(str))
        {
            tell_object(tp,"%^RESET%^%^BOLD%^Please enter your email address. Type <abort> to cancel.");
            input_to("selection","enter_email");
            return 0;
        }

        tell_object(tp,"%^RESET%^%^BOLD%^Do you really want the email address %^RESET%^%^MAGENTA%^"+__Email+"%^RESET%^%^BOLD%^?");
        tell_object(tp,"%^RESET%^%^YELLOW%^  <y>es or <n>o.%^RESET%^");
        input_to("selection","confirm_email");

        return 0;


    case "confirm_account_name":

        switch(str)
        {
        case "yes":
        case "y":
        case "Y":

            tell_object(tp,"%^RESET%^%^YELLOW%^Confirming account name %^RESET%^%^MAGENTA%^"+__AccountName+"%^RESET%^%^YELLOW%^.\n\n");
            tell_object(tp,"%^RESET%^%^BOLD%^Please enter your email address.  This needs to be a valid email address.  If you loose your password, we will contact you at this email address.");
            input_to("selection","enter_email");

            return 0;

        default:

            delete_account(__AccountName);
            tell_object(tp,"%^RESET%^%^YELLOW%^Aborting...%^RESET%^");
            show_menu(tp);
            return 0;
        }


    case "enter_new_account":

        if(!new_account_check(str))
        {
            show_menu(tp);
            return 0;
        }

        tell_object(tp,"%^RESET%^%^BOLD%^Do you really want the account name %^RESET%^%^MAGENTA%^"+__AccountName+"%^RESET%^%^BOLD%^?");
        tell_object(tp,"%^RESET%^%^YELLOW%^  <y>es or <n>o.%^RESET%^");

        input_to("selection","confirm_account_name");
        return 0;


    ///////////////////////////////////
    // end of account creation menus //
    ///////////////////////////////////




    //////////////////////////////////
    // character association menus  //
    //////////////////////////////////


    case "account_name":

        if(!account_exists(str))
        {
            tell_object(tp,"%^RESET%^%^BOLD%^The account named %^RESET%^%^MAGENTA%^"+str+"%^RESET%^%^BOLD%^ does not exist.");
            tell_object(tp,"%^RESET%^%^YELLOW%^Aborting....%^RESET%^");
            show_menu(tp);
            return 0;
        }

        __AccountName = str;

        tell_object(tp,"%^RESET%^%^YELLOW%^Please enter the password for account %^RESET%^%^MAGENTA%^"+__AccountName+"%^RESET%^%^YELLOW%^.%^RESET%^");
        input_to("enter_password",1);
        return 0;


    //////////////////////////////////////
    // end character association menus  //
    //////////////////////////////////////




    //////////////////////////////////////
    // no account section below         //
    //////////////////////////////////////


    case "no_account": // menu if the character doesn't have an account

        switch(str)
        {
        case "1": // associte character with existing account

            tell_object(tp,"%^RESET%^%^BOLD%^Please enter the name of the account you would like to associate this character with.");
            input_to("selection","account_name");
            return 0;

        case "2": // create new account

            tell_object(tp,"%^RESET%^%^BOLD%^The account name should be something you will remember, you will need the account name and password if you want to associate "
                "another character with the account in the future.\n");
            tell_object(tp,"%^RESET%^%^BOLD%^Please enter the name of the account. Lowercase letters %^RESET%^%^MAGENTA%^a-z%^RESET%^%^BOLD%^, "
                "numbers %^RESET%^%^MAGENTA%^0-9%^RESET%^%^BOLD%^, %^RESET%^%^MAGENTA%^_%^RESET%^%^BOLD%^ (underscore) and %^RESET%^%^MAGENTA%^@ "
                "%^RESET%^%^BOLD%^are all valid characters in an account name./n");

            input_to("selection","enter_new_account");
            return 0;


        default: // exit account

            exit();
            return 0;
        }


    //////////////////////////////////////
    // end of no account section        //
    //////////////////////////////////////




    //////////////////////////////////////
    // account action menus             //
    //////////////////////////////////////


    case "change_email":

        if(!enter_email_address(str))
        {
            tell_object(tp,"%^RESET%^%^BOLD%^Please enter your new email address. Type <abort> to cancel.");
            input_to("selection","change_email");
            return 0;
        }

        tell_object(tp,"%^RESET%^%^BOLD%^Changing your email to %^RESET%^%^MAGENTA%^"+__Email+"%^RESET%^%^BOLD%^.");
        save_this_object();
		exit();
        return 0;


    case "change_real_name":

        if(!enter_real_name(str))
        {
            tell_object(tp,"%^RESET%^%^BOLD%^Please enter the new real name you want.  Type <abort> to cancel.");
            input_to("selection","change_real_name");
            return 0;
        }

        tell_object(tp,"%^RESET%^%^BOLD%^Changing your real name to "+__RealName+".");
        save_this_object();
		exit();
        return 0;


    case "account_actions":

        switch(str)
        {
        case "1": // display account information

            display_account_info(__AccountName,tp);
            return 0;

        case "2": // change email

            tell_object(tp,"%^RESET%^%^BOLD%^Please enter the new email you would like for your account.%^RESET%^");
            input_to("selection","change_email");
            return 0;

        case "3": // change real name

            tell_object(tp,"%^RESET%^%^BOLD%^Please enter the new real name you would like for your account.%^RESET%^");
            input_to("selection","change_real_name");
            return 0;

        case "4": // change password

            tell_object(tp,"%^RESET%^%^BOLD%^Please enter your old password.");
            input_to("change_password",1);
            return 0;

        default:
            exit();
            return 0;
        }

    //////////////////////////////////////
    // end of account action menus      //
    //////////////////////////////////////

    }
    exit();
    return 0;
}


int new_association_check()
{
    if(!objectp(tp)) { return 0; }

    if(__AccountName == "")
    {
        tell_object(tp,"No account name.");
        return 0;
    }

    if(tp->query("user_account"))
    {
        tell_object(tp,"%^RESET%^%^YELLOW%^This character is already associated with the user account named "+tp->query("user_account")+"%^RESET%^");
        return 0;
    }
    __Characters += ({ (string)tp->query_true_name() });
    return 1;
}


int new_account_check(string str)
{
    if(!stringCheck(str)) { return 0; }

    str = lower_case(str);

    if(!character_filter(str)) { return 0; }
    if(account_exists(str))
    {
        tell_object(tp,"%^RESET%^%^RED%^An account named "+str+" already exists.%^RESET%^");
        return 0;
    }

    __AccountName = str;
    if(!new_association_check()) { return 0; }
    tp->set("user_account",__AccountName);
    tell_object(tp,"%^YELLOW%^Creating account "+str+"....");
    return 1;
}


// need user messages for failures here to describe the reason for fail
int create_new_account(string str)
{
    if(!stringCheck(str)) { return 0; }

    str = lower_case(str);

    if(!character_filter(str)) { return 0; }
    if(account_exists(str))
    {
        tell_object(tp,"%^RESET%^%^RED%^An account named "+str+" already exists.%^RESET%^");
        return 0;
    }

    __AccountName = str;
    if(!associate_user_with_account()) { return 0; }
    tell_object(tp,"%^YELLOW%^Creating account "+str+"....");
    create_user_account(str);
    return 1;
}


int enter_email_address(string str)
{
    if(!stringCheck(str)) { return 0; }
    if(strsrch(str,"@") == -1)
    {
        tell_object(tp,"%^RESET%^%^BOLD%^Invalid email address.  Valid email addresses are in the format address@host%^RESET%^");
        return 0;
    }
    __Email = str;

    //save_this_object();
    return 1;
}


int enter_real_name(string str)
{
    if(!stringCheck(str)) { return 0; }
    __RealName = str;

    //save_this_object();
    return 1;
}


// should only be called from create_new_account()
int create_user_account(string str)
{
    save_user_account(str);
    return 1;
}


int has_account(string str)
{
    if(USERCALL->user_call(str,"query","user_account")) { return 1; }
    return 0;
}

int character_has_account()
{
    if(!objectp(tp)) { return 0; }
    if(!tp->query("user_account")) { return 0; }
    return 1;
}


string query_character_account()
{
    if(!objectp(tp)) { return 0; }
    if(!character_has_account()) { return 0; }
    return (string)tp->query("user_account");
}


int associate_user_with_account()
{
    if(!objectp(tp)) { return 0; }

    if(__AccountName == "")
    {
        tell_object(tp,"No account name.");
        return 0;
    }

    if(tp->query("user_account"))
    {
        tell_object(tp,"%^RESET%^%^YELLOW%^This character is already associated with the user account named "+tp->query("user_account")+"%^RESET%^");
        return 0;
    }

    __Characters += ({ (string)tp->query_true_name() });

    tp->set("user_account",__AccountName);

    save_this_object();

    return 1;
}


int unassociate_user()
{
    if(!objectp(tp)) { return 0; }

    if(!tp->query("user_account")) { return 0; }

    __Characters -= ({ (string)tp->query_true_name() });

    tp->delete("user_account");

    save_this_object();

    return 1;
}


int load_user_account(string str)
{
    if(!account_exists(str))
    {
        tell_object(tp,"No account named "+str+" exists.");
        return 0;
    }
    if(LOADED)
    {
        tell_object(tp,"Your account is already loaded.");
        return 0;
    }
    restore_account(str);
    LOADED = 1;
    return 1;
}


int account_exists(string str)
{
    if(!stringCheck(str)) { return 0; }

    str = lower_case(str);
    if(!file_exists(ACCOUNTS_DIR+str+".o")) { return 0; }
    return 1;
}


int character_filter(string str)
{
    string *good_characters,*the_string;
    int i,j;

    good_characters = ({ "0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","_","@" });

    if(!stringCheck(str)) { return 0; }

    the_string = explode(str,"");

    for(i=0;i<sizeof(the_string);i++)
    {
        if(member_array(the_string[i],good_characters) == -1)
        {
            tell_object(tp,"The character "+the_string[i]+" is not a valid character.  Valid characters for user account names are as follows: ");
            tell_object(tp,"0-9, a-z, _ (underscore), and @");
            return 0;
        }
    }
    return 1;
}


int stringCheck(string str)
{
    if(!stringp(str) || str == "" || str == " ") { return 0; }
    return 1;
}


void set_tp(object obj)
{
    if(!objectp(obj)) { return; }
    tp = obj;
}


// Password related functions
nomask protected int password_two(string str)
{
    pass_two = str;

    if(pass_one == pass_two)
    {
        tell_object(tp,"%^RESET%^%^YELLOW%^Confirmed, setting password and creating account...");
        set_password(pass_one);
        display_account_info(__AccountName,tp);
        //create_new_account(__AccountName);
        return 1;
    }

    else
    {
        tell_object(tp,"%^RESET%^%^YELLOW%^Passwords do not match, please enter a password.");
        input_to("password_one",1);
        return 0;
    }
}


nomask protected int password_one(string str)
{
    tell_object(tp,"%^RESET%^%^YELLOW%^Please enter your password again.");
    pass_one = str;
    input_to("password_two",1);
    return 0;
}


nomask protected int enter_password(string str)
{
    if(ATTEMPTS > 3)
    {
        tell_object(tp,"%^RED%^You have exceded the maximum number of password attempts.");
        tell_object(tp,"%^RED%^Aborting....");
        exit();
        return 0;
    }

    if(!internal_check_password(str,__AccountName))
    {
        ATTEMPTS += 1;
        tell_object(tp,"%^RESET%^%^YELLOW%^Incorrect password.  Please try again.");
        input_to("enter_password",1);
        return 0;
    }

    tell_object(tp,"%^RESET%^%^BOLD%^Password confirmed, associating character with account %^RESET%^%^MAGENTA%^"+__AccountName+"%^RESET%^%^BOLD%^.");

    load_user_account(__AccountName);

    associate_user_with_account();

    display_account_info(__AccountName,tp);

    return 0;
}


nomask protected int change_password(string str)
{
    if(ATTEMPTS > 3)
    {
        tell_object(tp,"%^RED%^You have exceded the maximum number of password attempts.");
        tell_object(tp,"%^RED%^Aborting....");
        exit();
        return 0;
    }

    if(!internal_check_password(str,__AccountName))
    {
        ATTEMPTS += 1;
        tell_object(tp,"%^RESET%^%^YELLOW%^Incorrect password.  Please try again.");
        input_to("change_password",1);
        return 0;
    }

    tell_object(tp,"%^RESET%^%^BOLD%^Password confirmed, please enter the new password for your account.");

    input_to("password_one",1);

    return 0;
}


int set_password(string str)
{
    __Password = crypt(str,0);
    save_this_object();
    return 1;

}


int law_set_password(object obj, string player_name, string new_pass)
{
    object player_account;
    string account_name;

    if(!objectp(obj)) { return 0; }

    if(!archp(obj))
    {
        tell_object(obj,"This command is restricted to admins only.");
        return 0;
    }

    if(!user_exists(player_name))
    {
        tell_object(obj,"The user "+player_name+" doesn't seem to exist.");
        return 0;
    }

    account_name = USERCALL->user_call(player_name, "query","user_account");
    if(!account_name || !account_exists(account_name))
    {
        tell_object(obj,"No account associated with "+player_name+"'s account");
        return 0;
    }

    player_account = new(OB_ACCOUNT);
    player_account->load_user_account(account_name);

    player_account->set_password(new_pass);
    player_account->save_this_object();
    destruct(player_account);

    tell_object(obj,"Changing password for "+player_name+"'s account to "+new_pass);
    seteuid(UID_LOG);
    log_file("adm/account_passwords",""+obj->query_true_name()+" changed the password for "+player_name+"'s account.\n");
    seteuid(geteuid());
    return 1;
}


int internal_check_password(string password,string user_account)
{
    object account;
    string pass1,pass2;

    if(!account_exists(user_account)) { return 0; }

    account = new(OB_ACCOUNT);
    account->restore_account(user_account);
    pass1 = (string)account->query_password();
    pass2 = crypt(password,pass1);
    destruct(account);

    return (pass1 == pass2);
}

// end of password related functions


int delete_account(string str)
{
    __AccountName = "";
    __Characters = ({});
    __Perks = ({});
    LOADED = 0;
    positions = ({});
    tp->delete("user_account");
    return 1;
}


int save_this_object()
{
    if(__AccountName == "") { return 0; }
    save_user_account(__AccountName);
    return 1;
}


int save_user_account(string str)
{
    if(__AccountName == "") { return 0; }

    seteuid(UID_ROOT);
    save_object(ACCOUNTS_DIR+str);
    return 1;
}


int restore_account(string str)
{
    if(!account_exists(str)) { return 0; }
    restore_object(ACCOUNTS_DIR+str);
    __Characters=sort_array(__Characters,1);
}


int exit()
{
    destruct(TO);
    return 1;
}


string query_account_name()
{
    return __AccountName;
}


string query_password()
{
    return __Password;
}
