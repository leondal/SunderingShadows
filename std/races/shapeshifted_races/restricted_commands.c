#include <std.h>
#include <daemons.h>

#define NEVER_ALLOWED ({ \
    "money", \
    "balance", \
    "deposit", \
    "withdraw", \
    "alterobj", \
    "bind", \
    "blindfold", \
    "gag", \
    "brew", \
    "craft", \
    "disguise", \
    "follower", \
    "gather", \
    "pp", \
    "hide", \
    "plant", \
    "poison", \
    "repair", \
    "seal", \
    "show", \
    "sign", \
    "write", \
    "skin", \
    "stab", \
    "steal", \
    "strip", \
    "teach", \
    "throw", \
    "trap", \
    "unbind", \
    "ungag", \
    "buy", \
    "sell", \
    "value", \
    "mount", \
    "smash", \
    "caress", \
    "touch", \
    "lock", \
    "unlock", \
    "pick", \
    "sheath", \
    "draw", \
    "steer", \
 })

#define SOMETIMES_ALLOWED ({ \
    "prepare", \
    "study", \
    "whisper", \
    "speak", \
    "get", \
    "put", \
    "remove", \
    "unwear", \
    "wear", \
    "drop", \
 })


#define MAX_SPAM_COMMANDS 100 // if they enter more than this amount of commands in 2 seconds, they will get a spam warning and we log the commands -Ares

inherit OBJECT;

nosave mapping spam_count;

int clean_up() { return 1; }

void create()
{
    clear_spam_count();
    ::create();
}

void clear_spam_count()
{
    spam_count = ([]);
    call_out("clear_spam_count",2);
    return;
}


int spam_buffer(object player)
{
    int num;

    if(!objectp(player)) { return 1; } // 1 allows command to happen

    if(!spam_count[player]) { num = 1; }
    else
    {
        num = spam_count[player];
    }
    num++;
    spam_count[player] = num;
    if(num > MAX_SPAM_COMMANDS) { return 0; }
    return 1;
}


int allow_shifted_command(object player,string verb,string command)
{
    object shape,ob;
    string word,*words=({});

    if(objectp(player))
    {
        if(player->query("no_commands_allowed") > time())
        {
            tell_object(player,"You've entered too many commands in too short time, no more allowed right now.");
            return 0;
        }
    }
    // if(!spam_buffer(player))
    // {
    //     if(objectp(player)) { tell_object(player, "Too many commands entered in too short time: "+ctime(time())); }
    //     if(interactive(player)) { log_file("spam",""+identify(player)+" exceeded command spam limit of 100 commands in 2 seconds, tried to enter command: "+verb+" "+command+"\n"); }
    //     player->delete("no_commands_allowed");
    //     player->set("no_commands_allowed",time() + 3);
    //     player->set_paralyzed(2);
    //     return 0;
    // }
    if(avatarp(player)) { return 1; }
    if(!objectp(player)) { return 1; }
    if(!objectp(shape = player->query_property("shapeshifted"))) { return 1; }
    if(!stringp(verb) || verb == "" || verb == " ") { return 1; }
    if((!stringp(command)) || (command == "") || (command == " ") )  { return 1; }

    if(member_array(verb,NEVER_ALLOWED) != -1) { return 0; }


    if(command && (command != "") && (command != " "))
    {
        words = explode(command," ");
        word = words[0];
    }

    if(member_array(verb,SOMETIMES_ALLOWED) != -1)
    {
        switch(verb)
        {
        case "prepare":
//        case "cast":
// cast has been moved to spell.c for situational usage reliant on spell attributes. N, 10/15.

            if(!shape->can_cast()) { return 0; }
            break;

        case "study":

            if(!FEATS_D->usable_feat(player,"wild knowledge")) { return 0; }
            break;

        case "whisper":
        case "speak":

            if(!shape->can_talk() && !FEATS_D->usable_feat(player,"wild speech")) { return 0; }
            break;

        case "get": // also a check in /std/bag_logic.c
        case "put": // also a check in /std/bag_logic.c
        case "drop":

            if(command == "coins" || command == "all coins" || command == "pile" || command == "money" || command == "kit" || command == "vials" || command == "vial") { return 1; }
            if( (strsrch(command,"kit") != -1) || (strsrch(command,"vial") != -1) ) { return 1; }

            if(!FEATS_D->usable_feat(player,"wild knowledge"))
            {
                if(!objectp(ob = present(command,player)) && !objectp(ob = present(command,environment(player))))
                {
                    tell_object(player,"You don't seem to have a "+command+".");
                    return 0;
                }

                if( (base_name(ob) != "/d/azha/obj/gmr_ring") || (base_name(ob) != "/d/azha/obj/mr_ring") )
                {
                    return 0;
                }
            }

            break;

        case "remove":
        case "unwear":
        case "wear":

            if(!FEATS_D->usable_feat(player,"wild knowledge"))
            {
                if(!objectp(ob = present(command,player)))
                {
                    tell_object(player,"You don't seem to have a "+command+".");
                    return 0;
                }

                if( (base_name(ob) != "/d/azha/obj/gmr_ring") && (base_name(ob) != "/d/azha/obj/mr_ring") )
                {
                    return 0;
                }
            }

            break;

        }//
    }//
    return 1;
}//
