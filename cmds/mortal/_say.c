#include <std.h>
#include <rooms.h>

inherit DAEMON;

#include <langs.h>

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

int cmd_say(string str)
{
    object *people;
    object me = TP;
    string speech,lang,emote,replace1,replace2, pseudoname = 0, color;
    string describe = 0, *tmp2;
    mapping tmp;
    int i;

    if (TP->query_gagged())
    {
        return notify_fail(TP->query_gagged_message()+"\n");
    }

    if(!objectp(ETP))
    {
        tell_object(TP,"You have no environment, please contact a wiz.");
        return 1;
    }

    if(this_player()->query_ghost() && base_name(ETP) != DEATH_ROOM)
    {
        message("talk", "You howl pitifully.", this_player());
        message("talk", "You hear a pitiful howl.", environment(this_player()),({ this_player() }));
        return 1;
    }

    if(avatarp(TP))
    {
        tmp = TP->query("avsayprofile");
    }


    if(!str || str == "")
    {
        notify_fail("You mutter to yourself.\n");
        return 0;
    }

    if(!wizardp(TP)) { str = replace_string(str,"BLACK","BLUE"); }

// The below code was put in to prevent spamming the same thing over and over to gain skill in languages, which is less of a concern now. 
// Editing it out for now to save players some aggravation. -- Uriel 1 Dec 2019
//    if(interactive(TP) && (string)TP->query("last say") == str) { return notify_fail("You just said that.\n")
// }

    TP->set("last say",str);

    if(!TP->query("speech string") || replace_string((string)TP->query("speech string")," ","") == "")
    {
        speech = "say";
    }
    else
    {
        speech = TP->query("speech string");
        describe = TP->query("describe string");
    }

    lang = (string)TP->query_spoken();

    if(mapp(tmp))
    {
        lang = tmp["Language"];
        if(lang == "All" || lang == "all") lang = "wizish";
        describe = 0;
        if(tmp["Speech"])
        {
            tmp2 = explode(tmp["Speech"], " ");
            speech = tmp2[0];
            tmp2 -= ({tmp2[0]});
            if(sizeof(tmp2)) describe = implode(tmp2, " ");
        }
        else
        {
            speech = "say";
        }
        pseudoname = capitalize(tmp["Character Name"]);
        str = strip_colors(str);
        if(tmp["Color"]) color = tmp["Color"];
        else color = "%^RESET%^";
    }

    if(member_array(lang,ANIMAL_LANGS) != -1)
    {
        emote = "%^BOLD%^%^MAGENTA%^"+TP->QCN+" "+"daemon/language_d"->query_animal_emotes(str,TP);
        //str = "daemon/language_d"->animal_translate(str,lang,TP);
    }
    else
    {
        if(!TP->is_monster())
        {
            //str= "daemon/language_d"->translate(str, lang, TP);
        }
    }



    if(describe)
    {
        if(emote) { message("animal_emote",emote,ETP,TP); }
        message("say","%^MAGENTA%^You "+speech+" "+describe+"%^RESET%^: "+str, TP);
        if(stringp(pseudoname)) message("say", "%^MAGENTA%^"+pseudoname+" "+speech+"'s "+describe+"%^RESET%^: "+color+str, ETP, me);
        else message("say","%^MAGENTA%^"+TPQCN+" "+speech+"s "+describe+"%^RESET%^: "+str,ETP,me);
        return 1;
    }
    else
    {
        if(emote) { message("animal_emote",emote,ETP,TP); }
        message("say","%^MAGENTA%^You "+speech+"%^RESET%^: "+str,TP);
        if(objectp(ETP))
        {
            if(stringp(pseudoname)) message("say", "%^MAGENTA%^"+pseudoname+" "+speech+"'s%^RESET%^: "+color+str, ETP, me);
            else message("say","%^MAGENTA%^"+TPQCN+" "+speech+"s%^RESET%^: "+str,ETP,me);
        }
        return 1;
    }
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

say - speak up

%^CYAN%^SYNOPSIS%^RESET%^

say %^ORANGE%^%^ULINE%^MESSAGE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Sends out a message to everyone in the room, notifying them that you said it.

%^CYAN%^SEE ALSO%^RESET%^

whisper, yell, pose, emote, emoteat, speech, tell, reply
");

}
