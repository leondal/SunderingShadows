// added $np and $pp *Styx*  2/17/03.  Changed to make thieves unhidden when used so they can be noticed.  Circe 10/26/03  Updated help file.  Kismet 5/29/19

/**
 * @file
 */

#include <std.h>

#define EMOTE "/cmds/mortal/_emote"

inherit DAEMON;

#include <langs.h>

int help();

int cmd_emoteat(string str){

    string roomMsg, targetMsg,lang,*words=({}),start_color,end_color,tmp="",temp;
    string who, what;
    object obj;
    int i;

    if(!objectp(TP) || !objectp(ETP)) { return 0; }

    if (!str) {
        return help();
    }


    // stuff to include speech inside of emotes
    words = explode(str,"\"");

    lang = TP->query_spoken();
    start_color = TP->query("start_color");
    end_color = TP->query("end_color");

    if(sizeof(words))
    {
        for(i=0;i<sizeof(words);i++)
        {
            if(i%2 == 0)
            {
                temp = words[i];
                if(i>0)
                {
                    if(end_color) { temp = end_color + temp; }
                }
                if(start_color) { temp = temp + start_color; }

                tmp += temp;
            }
            else
            {
                if(TP->query_gagged())
                {
                    tmp += "mumbles through the gag";
                }
                else
                {
                    if(member_array(lang,ANIMAL_LANGS) != -1)
                    {
                        temp = "daemon/language_d"->animal_translate(words[i],lang,TP);
                    }
                    else
                    {
                        temp= "daemon/language_d"->translate(words[i], lang, TP);
                    }

                    tmp += "#@&"+temp+"#@&";
                }
            }
        }
    }

    str = tmp;
    // end stuff to include speech inside of emotes


    if (sscanf(str , "%s %s",who,what) != 2)
    {
        return help();
    }
    if(TP->query_hidden()) TP->force_me("step");

    obj = present(who, ETP);

//!living(obj) check added by Circe 3/26/05
//we had bug reports when people tried to emoteat objects/corpses
//obj != TP check added so that people can emoteat themselves even when hidden/invis - Lujke 2019
    if (!objectp(obj) || !living(obj) || ((obj->query_hidden() || obj->query_magic_hidden()) && (obj!= TP && !TP->detecting_invis())) ) {
        return notify_fail("That person is not here.\n");
    }

    if (strsrch(what, "$M") != -1) {
        what = replace_string(what,"$M",TP->query_cap_name());
    } else {
        what = TP->query_cap_name()+" "+what;
    }
    roomMsg = what;
    targetMsg = what;
    targetMsg = "%^RESET%^%^BOLD%^%^GREEN%^**%^RESET%^ "+targetMsg;

    roomMsg = replace_string(roomMsg,"$N",obj->query_cap_name());
    roomMsg = replace_string(roomMsg,"$P",obj->query_possessive());
    roomMsg = replace_string(roomMsg,"$S",obj->query_subjective());
    roomMsg = replace_string(roomMsg,"$O",obj->query_objective());
    roomMsg = replace_string(roomMsg,"$np",obj->query_cap_name()+"'s");
    if((string)obj->query_gender() == "male")
       roomMsg = replace_string(roomMsg,"$pp",obj->query_possessive());
    if((string)obj->query_gender() == "female")
       roomMsg = replace_string(roomMsg,"$pp",obj->query_possessive()+"s");

    targetMsg = replace_string(targetMsg,"$N","you");
    targetMsg = replace_string(targetMsg,"$P","your");
    targetMsg = replace_string(targetMsg,"$S","you");
    targetMsg = replace_string(targetMsg,"$O","you");
    targetMsg = replace_string(targetMsg,"$np","your");
    targetMsg = replace_string(targetMsg,"$pp","yours");


  if (interactive(TP)) {
           if(file_size("/log/emotes/emoteat.log") > 150000) {
           cp("/log/emotes/emoteat.log","/log/emotes/emoteat.old");
           rm("/log/emotes/emoteat.log");
         }
         write_file("/log/emotes/emoteat.log",capitalize(TPQN)+">"+obj->query_name()+":"+targetMsg+"\n");

            }

    message("emote",roomMsg,ETP,({TP,obj}));
    message("emote",targetMsg,obj);
    if(obj != TP) message("emote","You emote the following at "+capitalize(who)+":"+targetMsg,TP);

    return 1;
}

void help(){
    write(
@OLI
%^CYAN%^NAME%^RESET%^

emoteat - directs an emote towards a living target.

%^CYAN%^SYNOPSIS%^RESET%^

%^ORANGE%^emoteat TARGET MESSAGE CODE%^RESET%^

%^ORANGE%^emoteat TARGET MESSAGE CODE ''SPOKEN WORDS''%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

%^CYAN%^Summary:%^RESET%^

Emoteat is an extension of emote (%^ORANGE%^<help emote>%^RESET%^) that allows you to %^CYAN%^emote at%^RESET%^ someone by directing your action towards that person (your target).  By using the codes below, you tell your target and everyone else in the room exactly who you are adressing. This increases immersion and improves communication. It uses the recognize system (%^ORANGE%^<help recognize>%^RESET%^), so it is seen differently depending on which names people have you and your target recognized as. It is also seen differently by you, your target and everyone else in the room respectively.

%^ORANGE%^TARGET%^RESET%^ is the creature you are directing your emote at. %^ORANGE%^STRING%^RESET%^ is the action you wish to describe. %^ORANGE%^CODE%^RESET%^ is the code you use to replace pronouns. Your name will be added to the start of the emote automatically.

%^CYAN%^Speech Within Emotes:%^RESET%^

It is possible to use speech within emotes when using the emoteat tool.  To do so, put the text you wish to say inside quotation marks.  The spoken text will be displayed in the language you are currently speaking (%^ORANGE%^<help languages>%^RESET%^).

%^CYAN%^A Word of Caution:%^RESET%^

While you are free to emote at any living target (including NPCs and mounts), please remember that you only control your own character and any extensions thereof (your followers, your familiar, your horse, etc).  Refrain from using emoteat to feign control over coded NPC's in the game world (see %^ORANGE%^<help emoteat guide>%^RESET%^ for clarification).

%^CYAN%^Codes:%^RESET%^

Refer to the list below for the %^ORANGE%^codes %^WHITE%^that can be used with emoteat. The column named %^CYAN%^Result%^RESET%^ shows how the code will be seen by %^GREEN%^you%^WHITE%^, %^MAGENTA%^your target %^WHITE%^and %^BOLD%^%^BLACK%^everyone else in the room %^RESET%^respectively.

 CODE   DESCRIPTION       RESULT AS SEEN BY:  %^GREEN%^You %^WHITE%^| %^MAGENTA%^Your Target %^WHITE%^| %^BOLD%^%^BLACK%^Room
%^RESET%^
 %^MAGENTA%^$N   %^WHITE%^-  Your target's name                -  %^GREEN%^Name %^WHITE%^| %^MAGENTA%^You %^WHITE%^| %^BOLD%^%^BLACK%^Name
 %^BOLD%^%^MAGENTA%^$np  %^RESET%^-  Target's name in possessive form  -  %^GREEN%^Name's %^WHITE%^| %^MAGENTA%^Your %^WHITE%^| %^BOLD%^%^BLACK%^Name's
 %^RESET%^%^RED%^$P   %^WHITE%^-  Possessive form of the target     -  %^GREEN%^His/Her %^WHITE%^| %^MAGENTA%^Your %^WHITE%^| %^BOLD%^%^BLACK%^His/Her
 %^BOLD%^%^RED%^$pp  %^RESET%^-  Plural possessive form of target  -  %^GREEN%^His/Hers %^WHITE%^| %^MAGENTA%^Yours %^WHITE%^| %^BOLD%^%^BLACK%^His/Hers
 %^BLUE%^$S   %^RESET%^-  Subjective form of target         -  %^GREEN%^He/She %^WHITE%^| %^MAGENTA%^You %^WHITE%^| %^BOLD%^%^BLACK%^He/She%^RESET%^
 %^BOLD%^%^CYAN%^$O   %^RESET%^-  Objective form of target          -  %^GREEN%^Him/Her %^WHITE%^| %^MAGENTA%^You %^WHITE%^| %^BOLD%^%^BLACK%^Him/Her
 %^RESET%^
 %^GREEN%^$M   %^WHITE%^-  Your own name%^RESET%^                     -  %^GREEN%^You %^WHITE%^| %^BOLD%^%^BLACK%^Your Name

%^RESET%^%^CYAN%^Please note:%^RESET%^  While the game replaces the above codes with the proper pronouns, it does not add an "s" to the end of verbs.  As a courtesy to other players, please add it yourself.


%^CYAN%^EXAMPLES%^RESET%^

In our first example, Karen types:
  %^ORANGE%^<%^RESET%^emoteat %^MAGENTA%^charlie %^WHITE%^Nodding thoughtfully at %^BOLD%^%^MAGENTA%^$np %^RESET%^words, %^GREEN%^$M%^RESET%^ smiles at %^BOLD%^%^CYAN%^$O%^RESET%^, before saying "Yes, I agree."%^ORANGE%^>

%^RESET%^%^GREEN%^Karen would see:
  %^WHITE%^Nodding thoughtfully at %^BOLD%^%^MAGENTA%^Charlie's %^RESET%^words, %^GREEN%^you %^WHITE%^smiles at %^BOLD%^%^CYAN%^him%^RESET%^, before saying "Yes, I agree.".

%^MAGENTA%^Charlie would see:
  %^WHITE%^Nodding thoughtfully at %^BOLD%^%^MAGENTA%^your %^RESET%^words, %^GREEN%^Karen %^WHITE%^smiles at %^BOLD%^%^CYAN%^you%^RESET%^, before saying "Yes, I agree.".

%^BOLD%^%^BLACK%^The room would see:
  %^RESET%^Nodding thoughtfully at %^BOLD%^%^MAGENTA%^Charlie's %^RESET%^words, %^GREEN%^Karen %^WHITE%^smiles at %^BOLD%^%^CYAN%^him%^RESET%^, before saying "Yes, I agree.".


%^RESET%^In another example, %^GREEN%^Karen %^WHITE%^types:
  %^ORANGE%^<%^WHITE%^emoteat %^MAGENTA%^charlie %^WHITE%^smiles at %^MAGENTA%^$N %^WHITE%^as %^BOLD%^%^BLUE%^$S %^RESET%^approaches and gladly takes %^RED%^$P %^WHITE%^offered hand.%^ORANGE%^>

%^GREEN%^Karen would see:
  You %^WHITE%^smiles at %^MAGENTA%^Charlie %^WHITE%^as %^BOLD%^%^BLUE%^he %^RESET%^approaches and gladly takes %^RED%^his %^WHITE%^offered hand.

%^MAGENTA%^Charlie would see:
  %^GREEN%^Karen %^WHITE%^smiles at %^MAGENTA%^You %^WHITE%^as %^BOLD%^%^BLUE%^you %^RESET%^approaches and gladly takes %^RED%^your %^WHITE%^offered hand.

%^BOLD%^%^BLACK%^The room would see:
  %^RESET%^%^GREEN%^Karen %^WHITE%^smiles at %^MAGENTA%^Charlie %^WHITE%^as %^BOLD%^%^BLUE%^he %^RESET%^approaches and gladly takes %^RED%^his %^WHITE%^offered hand.

If Charlie has Karen recognized as Linda, he would instead see:
  %^GREEN%^Linda%^RESET%^ smiles at %^MAGENTA%^you%^RESET%^ (...).

For more examples and nifty ways to use emoteat, please visit our emoteat guide at %^ORANGE%^<help emoteat guide>%^RESET%^.  For a quick list of codes, see %^ORANGE%^<help emoteat codes>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

emote, emoteat guide, emoteat codes, pose, colors, crayon, languages, recognize, say, whisper, yell, roleplaying
OLI
    );
        return 1;
}
