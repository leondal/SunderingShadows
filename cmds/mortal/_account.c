#include <std.h>
#include <objects.h>
#include <daemons.h>

inherit DAEMON;


int cmd_account(string str)
{
    object account_object;
    string account_name,player_name, new_pass;

    if(!objectp(TP)) { return 0; }
    if(!interactive(TP)) { return 0; }

    if(archp(TP))
    {
        if(strsrch(str,"password") != -1)
        {
            if(sscanf(str,"%s change password %s",player_name,new_pass) != 2)
            {
                tell_object(TP,"Syntax: account <player name> change password <new password>");
                return 1;
            }

            account_object = new(OB_ACCOUNT);
            account_name = USERCALL->user_call(player_name, "query","user_account");
            if(!account_name)
            {
                tell_object(TP,"No account seems to exist for "+player_name+".");
                if(objectp(account_object)) account_object->exit();
                if(objectp(account_object)) destruct(account_object);
                return 1;
            }
            account_object->law_set_password(TP, player_name, new_pass);
            if(objectp(account_object)) account_object->exit();
            if(objectp(account_object)) destruct(account_object);
            return 1;
        }
    }

    if(avatarp(TP) && stringp(str) && str != "" && str != " ")
    {
        if(!user_exists(str) && !find_player(str))
        {
            tell_object(TP,"That player doesn't seem to exist.");
            return 1;
        }
        account_object = new(OB_ACCOUNT);
        account_name = USERCALL->user_call(str,"query","user_account");
        if(!account_name)
        {
            tell_object(TP, ""+capitalize(str)+" doesn't seem to have an account yet.");
            if(objectp(account_object)) account_object->exit();
            if(objectp(account_object)) destruct(account_object);
            return 1;
        }

        account_object->load_user_account(account_name);

        account_object->display_account_info(account_name,TP);
        if(objectp(account_object)) account_object->exit();
        if(objectp(account_object)) destruct(account_object);
        return 1;
    }

    else
    {
        account_object = new(OB_ACCOUNT);
        account_object->show_menu(TP);
    }

    return 1;
}


int help(string str)
{

 write("
%^CYAN%^NAME%^RESET%^

account - manage user account
");
    if(avatarp(TP))
    {
        write("%^CYAN%^SYNOPSIS%^RESET%^

account [%^ORANGE%^%^ULINE%^PLAYER%^RESET%^]
");
    }
    write("%^CYAN%^DESCRIPTION%^RESET%^

This command will put your character into an editor that will allow you to create an account.  User accounts are meant to link characters belonging to the same player together.  All characters will have access to perks that have been gained by the most advanced character belonging to the account.

%^CYAN%^SEE ALSO%^RESET%^

passwd
");
}
