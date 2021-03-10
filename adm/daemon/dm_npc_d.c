/*==============================================================================================================================================
Daemon that keeps up with DM NPCs in order to allow us to
quickly view which ones are associated with which DM
as well as to allow the particular DM to keep
track on them more easily, as well as remove them without
needing higher support.

================================================================================================================================================*/
#include <std.h>
#include <daemons.h>
#include <security.h>
#include "/realms/grendel/grendel.h"

#define NPC_FILE "/adm/save/daemons/dm_npc_save_file"
#define PATHS  ({ "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" })
#define DELAY 5 // 5 second delay between calculating each block of names for time
#define FILES "/adm/save/users/"
#define BOAT_DIR "/d/save/boats/saakrune/"

inherit DAEMON;

mapping DM_NPCS;

nosave mapping PLAYER_LIST;

int DO_DEEP_NPC_LIST;

void npc_list_save();
void npc_list_restore();

void npc_list_save()
{
    seteuid(UID_ROOT);
    save_object(NPC_FILE);
    seteuid(geteuid());
}

void npc_list_restore()
{
    seteuid(UID_ROOT);
    restore_object(NPC_FILE);
    seteuid(geteuid());
}

void init_DM_NPCS()
{
    if(!mapp(DM_NPCS)) npc_list_restore();
    if(!mapp(DM_NPCS))
    {
        DM_NPCS = ([]);
        npc_list_save();
    }
}

void create()
{
    init_DM_NPCS();
    return;
}


/*
    Name
    Race
    Alignment
    Class
    Level
    Deity

*/

int list_npcs(object who, string whoNPC, int flag)
{
    string *myNPCS, *DM_LIST, myName, *CHECK_DM, CNPC, head;

    string *NPC_CLASSES, NPC_ALIGN, NPC_DEITY, NPC_RACE, NPC_CLASS_STRING;

    int x, y, z;

    string res, ret;

    if(!objectp(who)) return 0;

    myName = who->query_true_name();

    if(!stringp(whoNPC) || !archp(who))
    {
        whoNPC = myName;
    }

    init_DM_NPCS();

    if(!flag || !archp(who))
    {
        CHECK_DM = ({whoNPC});
        if(!pointerp(DM_LIST = keys(DM_NPCS)) || member_array(whoNPC, DM_LIST) == -1)
        {
            tell_object(who, "There appears to be an issue with the list of "+
            "DMs.");
            return 1;
        }

        if(!sizeof(myNPCS = DM_NPCS[whoNPC]) || !pointerp(myNPCS))
        {
            if(whoNPC == myName)
            {
                tell_object(who, "It looks like you have no registered NPCs. If this "+
                "is in error, please notify Saide.");
            }
            else
            {
                tell_object(who, "It appears that "+whoNPC+" has no registered NPCs.");
            }
            return 1;
        }
    }

    else if(flag)
    {
        if(!pointerp(DM_LIST = keys(DM_NPCS)))
        {
            tell_object(who, "It appears that there are no current DMs with "+
            "registered NPCs.");
            return 1;
        }
        CHECK_DM = DM_LIST;
    }

    res = "";
    head = "  %^BOLD%^%^WHITE%^Name " + repeat_string(" ", 7) + " %^BOLD%^%^GREEN%^Race " +
    repeat_string(" ", 5) + " %^BOLD%^%^YELLOW%^Al " + " %^BOLD%^%^CYAN%^Deity " + repeat_string(" ", 4) +
    " %^BOLD%^%^MAGENTA%^Class\n\n";

    for(x = 0;x < sizeof(CHECK_DM);x++)
    {
        if(CHECK_DM[x] == myName)
        {
            res += "\n%^BOLD%^%^BLACK%^Your NPCs are as follows : \n\n"+head;
        }
        if(CHECK_DM[x] != myName)
        {
            res += "\n%^BOLD%^%^BLACK%^NPCs for %^BOLD%^%^WHITE%^"+CHECK_DM[x]+"%^BOLD%^%^BLACK%^ are as follows : \n\n" + head;
        }
        if(!sizeof(myNPCS = DM_NPCS[CHECK_DM[x]]) || !pointerp(myNPCS))
        {
            res += "  %^RESET%^%^ORANGE%^No Current Npcs for "+CHECK_DM[x]+"%^RESET%^\n";
            continue;
        }

        for(y = 0;y < sizeof(myNPCS);y++)
        {
            CNPC = myNPCS[y];
            ret = capitalize(CNPC);
            ret = arrange_string(ret, 12);
            res += "  %^BOLD%^%^WHITE%^"+ret;

            NPC_RACE = USERCALL->user_call(CNPC, "query_race");

            ret = capitalize(NPC_RACE);
            ret = arrange_string(ret, 10);
            res += " %^BOLD%^%^GREEN%^"+ret;

            NPC_ALIGN = align_abbrev(USERCALL->user_call(CNPC, "query_alignment"));
            ret = NPC_ALIGN;
            ret = arrange_string(ret, 3);
            res += " %^BOLD%^%^YELLOW%^"+ret;

            NPC_DEITY = USERCALL->user_call(CNPC, "query_diety");
            ret = capitalize(NPC_DEITY);
            ret = arrange_string(ret, 10);
            res += " %^BOLD%^%^CYAN%^"+ret+ " ";

            NPC_CLASSES = USERCALL->user_call(CNPC, "query_classes");

            for(z = 0;z < sizeof(NPC_CLASSES);z++)
            {
                res += "%^BOLD%^%^MAGENTA%^"+capitalize(NPC_CLASSES[z]) + " ("+USERCALL->user_call(CNPC, "query_class_level", NPC_CLASSES[z])+") ";
                continue;
            }

            res += "%^RESET%^\n";
            NPC_RACE = "";
            continue;
        }
        continue;
    }
    who->more(explode(res, "\n"));
    return 1;
}

int remove_npc(object who, string NPC_NAME)
{
    string *myNPCS, *DM_LIST, myName, name;
    int x, j;
    string *files, *oldfiles;

    if(!objectp(who) || !stringp(NPC_NAME)) return 0;

    if(!avatarp(who))
    {
        tell_object(who, "You are not a DM? If this is an error, "+
        "please notify saide.");
        return 1;
    }

    if(objectp(find_player(NPC_NAME)))
    {
        tell_object(who, "Please make sure the NPC "+NPC_NAME+
        " is logged off before attempting to remove them.");
        return 1;
    }

    init_DM_NPCS();
    myName = who->query_true_name();

    if(!pointerp(DM_LIST = keys(DM_NPCS)) || member_array(myName, DM_LIST) == -1)
    {
        tell_object(who, "There appears to be an issue with the list of "+
        "DMs or you are not one.");
        return 1;
    }

    if(!sizeof(myNPCS = DM_NPCS[myName]) || !pointerp(myNPCS))
    {
        tell_object(who, "It looks like you have no registered NPCs. If this "+
        "is in error, please notify Saide.");
        return 1;
    }

    if(member_array(NPC_NAME, myNPCS) == -1)
    {
        tell_object(who, "It looks like you have no NPC with the name "+NPC_NAME+
        " registered.");
        return 1;
    }

    if(USERCALL->user_call(NPC_NAME, "query", "is_valid_npc") != myName || !user_exists(NPC_NAME))
    {
        tell_object(who, "It does not seem like "+NPC_NAME+" is one of your NPCs.");
        myNPCS -= ({NPC_NAME});
        DM_NPCS[myName] = myNPCS;
        npc_list_save();
        return 1;
    }

    name = NPC_NAME;

    seteuid(UID_ROOT);

    if(file_exists(DIR_ACCOUNTS+"/"+name+".o")) rename(DIR_ACCOUNTS+"/"+name+".o",DIR_USERS+"/suicide/"+name+".account.o");

    if(file_size(DIR_POSTAL+"/"+name[0..0]+"/"+name+".o") > -1) rm(DIR_POSTAL+"/"+name[0..0]+"/"+name+".o");

    if(file_exists(BOAT_DIR+name+"boat.c")) rm(BOAT_DIR+name+"boat.c");

    oldfiles = get_dir("/inv/"+name+"/");
    for(x=0;x<sizeof(oldfiles);x++)
    {
        j = rm("/inv/"+name+"/"+oldfiles[x]);
    }

    rmdir("/inv/"+name);

    files = who->wild_card("/d/magic/spellbook/backup_books/"+name+"_*.backup.o");
    for(x=0;x<sizeof(files);x++)
    {
        if(file_exists(files[x])) rm(files[x]);
    }

    files = who->wild_card("/d/magic/spellbook/save_books/"+name+"_*.backup.o");
    for(x=0;x<sizeof(files);x++)
    {
        if(file_exists(files[x])) rm(files[x]);
    }

    if(file_exists("/d/magic/spellbook/"+name+".comp.o")) rm("/d/magic/spellbook/"+name+".comp.o");

    if(USERCALL->user_call(name, "query", "advance place")) "daemon/room_d"->remove_room(USERCALL->user_call(name, "query", "advance place"));

    myNPCS -= ({NPC_NAME});

    DM_NPCS[myName] = myNPCS;

    rm("/d/save/background/"+NPC_NAME);

    rm("/d/save/background/"+NPC_NAME+".htm");

    "/daemon/save_d"->remove_name(name);

    "/daemon/guilds_d.c"->delete_player(name);

    npc_list_save();

    if(file_exists(DIR_USERS+"/"+NPC_NAME[0..0]+"/"+NPC_NAME+".o") || file_exists(DIR_USERS+"/"+NPC_NAME[0..0]+"/"+NPC_NAME))
    {

        if(rename(DIR_USERS+"/"+NPC_NAME[0..0]+"/"+NPC_NAME+".o", DIR_USERS+"/suicide/"+NPC_NAME+".o")) tell_object(who, "ERROR renaming");
        //if(rename(DIR_USERS+"/"+NPC_NAME[0..0]+"/"+NPC_NAME, DIR_USERS+"/suicide/"+NPC_NAME)) tell_object(who, "ERROR renaming");
    }
    seteuid(geteuid());

    tell_object(who, "You have completely removed your npc "+NPC_NAME+" from the game.");

    return 1;
}

int add_as_npc(string NPC_NAME, string DM_NAME)
{
    if(!stringp(NPC_NAME) || !stringp(DM_NAME)) return 0; //failure

    if(!user_exists(DM_NAME)) return 0; //failure

    init_DM_NPCS();

    if(!mapp(DM_NPCS)) return 0; // failure

    if(USERCALL->user_call(NPC_NAME, "query", "is_valid_npc") != DM_NAME) return 0;

    if(!DM_NPCS[DM_NAME])
    {
        DM_NPCS += ([ DM_NAME : ({NPC_NAME}) ]);
        npc_list_save();
        return 1;
    }

    if(!pointerp(DM_NPCS[DM_NAME]))
    {
        DM_NPCS[DM_NAME] = ({NPC_NAME});
        npc_list_save();
        return 1;
    }

    else
    {
        if(member_array(NPC_NAME, DM_NPCS[DM_NAME]) != -1) return 0;
        DM_NPCS[DM_NAME] += ({NPC_NAME});
        npc_list_save();
        return 1;
    }

    return 0; // weird failure

}

void all_dm_npcs()
{
    return identify(DM_NPCS);
}

//function to pick up dm NPCs that existed prior to me realizing
//that a daemon would be a good thing :P
varargs void populate_dm_npcs(object debug)
{
    if(DO_DEEP_NPC_LIST) return;
    DO_DEEP_NPC_LIST = 1;
    PLAYER_LIST = ([]);
    build_player_list();
    build_dm_npcs_list(0, debug);
    return;
}


// builds complete list of all players
void build_player_list()
{
    int i,j, count = 0;
    string *list, *names;

    for (i = 0;i < sizeof(PATHS);i++)
    {
        if (!pointerp(list = get_dir(FILES + PATHS[i] + "/"))) { continue; }

        names = ({});

        for (j = 0;j < sizeof(list);j++)
        {
            names += ({ replace_string(list[j],".o","") });
        }
        count += sizeof(names);
        PLAYER_LIST[PATHS[i]] = names;
    }
}

void build_dm_npcs_list(int letter, object debug)
{
    int i,time;
    string *names, whosNPC;

    if (DO_DEEP_NPC_LIST == 2) { return;  }

    if(objectp(debug))
    {
        tell_object(debug, "Working on names for "+letter+" now.");
    }

    // gets a list of the names starting with each letter, moves on to the next letter if there are no names starting with that letter
    if (!pointerp(names = PLAYER_LIST[PATHS[letter]]))
    {
        if (letter < sizeof(PATHS)-1)
        {
            letter++;
            call_out("build_dm_npcs_list", DELAY, letter, debug);
            return;
        }
        else // if we run out of letters, just stop
        {
            npc_list_save();
            if(objectp(debug))
            {
                tell_object(debug, "List of previous NPCs should be built.");
            }
            DO_DEEP_NPC_LIST = 2;
            return;
        }
    }

    for (i = 0;i < sizeof(names);i++)
    {
        if(!stringp(whosNPC = USERCALL->user_call(names[i], "query", "is_valid_npc")) || !user_exists(whosNPC)) continue;
        add_as_npc(names[i], whosNPC);
        continue;
    }

    // step to our next letter and keep calculating
    if (letter < sizeof(PATHS)-1)
    {
        letter++;
        call_out("build_dm_npcs_list", DELAY, letter, debug);
        return;
    }
    npc_list_save();
    if(objectp(debug))
    {
        tell_object(debug, "List of previous NPCs should be built.");
    }
    DO_DEEP_NPC_LIST = 2;
    return;
}
