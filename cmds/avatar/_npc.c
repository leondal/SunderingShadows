#include <std.h>
#include <security.h>
#include <daemons.h>
inherit DAEMON;

int cmd_npc(string str)
{
    string myip, myemail, npc_ip, npc_email;
    string myAcc;
    object whoNpc;
    if(!stringp(str))
    {
        return help();
        //return 1;
    }

    if(sscanf(str, "-list %s", myAcc) == 1 || str == "-list")
    {
        if(!archp(TP)) DM_NPC_D->list_npcs(TP, myAcc, 0);
        else
        {
            if(myAcc == "all")
            {
                DM_NPC_D->list_npcs(TP, "", 1);
            }
            else DM_NPC_D->list_npcs(TP, myAcc, 0);
        }
        return 1;
    }
    if(sscanf(str, "-remove %s", myAcc) == 1)
    {
        DM_NPC_D->remove_npc(TP, myAcc);
        return 1;
    }

    if(!objectp(whoNpc = find_player(str)))
    {
        tell_object(TP, "No such user "+str+ " located. Please try again.");
        return 1;
    }


    npc_email = whoNpc->query_email();
    npc_ip = query_ip_name(npc_ip);
    myip = query_ip_name(TP);
    myemail = TP->query_email();
    if(myemail != npc_email || myip != npc_ip)
    {
        tell_object(TP, "Invalid target. "+capitalize(whoNpc->query_true_name())+" is "+
        "not one of your NPCs.");
        log_file("living/invalid_npcs", capitalize(TP->query_true_name())+" attempted to "+
        "promote "+capitalize(whoNpc->query_true_name())+" to an NPC.\n\n");
        return 1;
    }
    if(((string)TP->query_position() != "admin" || avatarp(whoNpc)) && !archp(TP))
    {
        tell_object(TP, "No way");
        return 1;
    }

    tell_object(TP, "You are attempting to convert "+whoNpc->query_true_name() + " to"+
    " an NPC character. This should give you access to the avatar line on that character as "+
    "well as the avatar commands.");
    whoNpc->set("is_valid_npc", TP->query_true_name());

    DM_NPC_D->add_as_npc(whoNpc->query_true_name(), TP->query_true_name());

    log_file("living/dm_npcs", capitalize(TP->query_true_name())+" set up "+
    capitalize(whoNpc->query_true_name())+" as an NPC.\n\n");
    whoNpc->init_path();
    USER_D->determine_lines(whoNpc);
    return 1;
}

int help()
{
    write("Syntax: npc <target>\n"
    "        npc -list\n");
    if(archp(TP)) write("        npc -list <name> | npc -list all");
    write("        npc -remove <name>\n"
    "The syntax npc <target> will let you attempt to flag "
    "the <target> as an NPC. Please note that this command is logged "
    "as you are only intended to create NPCs out of your own characters. "
    "In order to be successful the target must have the exact same "
    "email and IP address as yourself.\n\n"
    "The syntax npc -list will list all NPCs that you have created "
    "as well as some basic information about them.\n\n"
    "The syntax npc -remove <name> will attempt to remove "
    "the npc <name> that you specify. This is essentially the same "
    "as if you had manually suicided that NPC, so use it with caution.");
    return 1;
}
