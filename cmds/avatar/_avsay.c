#include <std.h>
#include <move.h>

inherit DAEMON;

int help();

mapping ProfileInfo = (["Character Name" : "NIL", "Speech" : "say", "Language" : "common", "Profile Name" : "NIL", "Color" : "%^RESET%^"]);

int cmd_avsay(string str)
{
    string name, speech, language, color;
    mapping tmp;
	object item;
    if(!stringp(str))
    {
        item = new ("/cmds/avatar/avsay.c");
        item->move(TP);
        return 1;
    }
    if(str == "reset")
    {
        tell_object(TP, "Assuming default profile.");
        TP->delete("avsayprofile");
        return 1;
    }
    if(str == "save")
    {
        tmp = TP->query("avsayprofile");
        if(!mapp(tmp))
        {
            tell_object(TP, "You have no active profile set to save.");
            return 1;
        }
        tell_object(TP, "Attemping to save profile name "+tmp["Profile Name"]+".");
        item = new ("/cmds/avatar/avsay.c");
        item->manual_set_and_save_avsay_profile(tmp);
        item->remove();
        return 1;
    }
    if(sscanf(str, "-n %s -s %s -l %s -c %s", name, speech, language, color) == 4)
    {
        ProfileInfo["Character Name"] = lower_case(name);
        ProfileInfo["Profile Name"] = name;
        ProfileInfo["Speech"] = speech;
        ProfileInfo["Language"] = lower_case(language);
        ProfileInfo["Color"] = color;
        tell_object(TP, "Assuming profile "+name+". Do avsay save in order to save it for later use.");
        TP->set("avsayprofile", ProfileInfo);
        return 1;
    }
    else if(sscanf(str, "-n %s -s %s -l %s", name, speech, language) == 3)
    {
        ProfileInfo["Character Name"] = lower_case(name);
        ProfileInfo["Profile Name"] = name;
        ProfileInfo["Speech"] = speech;
        ProfileInfo["Language"] = lower_case(language);
        tell_object(TP, "Assuming profile "+name+". Do avsay save in order to save it for later use.");
        TP->set("avsayprofile", ProfileInfo);
        return 1;
    }
    else if(sscanf(str, "-n %s -s %s", name, speech) == 2)
    {
        ProfileInfo["Character Name"] = lower_case(name);
        ProfileInfo["Profile Name"] = name;
        ProfileInfo["Speech"] = speech;
        tell_object(TP, "Assuming profile "+name+". Do avsay save in order to save it for later use.");
        TP->set("avsayprofile", ProfileInfo);
        return 1;
    }
    else if(sscanf(str, "-n %s", name) == 1)
    {
        ProfileInfo["Character Name"] = lower_case(name);
        ProfileInfo["Profile Name"] = name;
        tell_object(TP, "Assuming profile "+name+". Do avsay save in order to save it for later use.");
        TP->set("avsayprofile", ProfileInfo);
        return 1;
    }
    else 
    {
        return help();
        return 1;
    }
    return 1;

}



int help(){
   	write(
@SAIDE
    Usage:  avsay 
            avsay -n name -s speech -l language -c color
            avsay -n name -s speech -l language
            avsay -n name -s speech
            avsay -n name
            avsay reset
            avsay save

    With no argument avsay opens up a  menu drive system to allow 
    avatars/immortals to set up non-existent NPC profiles in order to 
    communicate with players for plots, etc. Has been set up to work 
    with the say and whisper commands so that they register in last 
    say and last whisper. Allows a player to whisper back the 
    non-existent NPC. NOTE: As of now the name needs to be 
    one word in order for whisper functionality to work correctly.
    
    avsay reset will clear your profile and switch you back to your default - 
    which is yourself
    
    avsay save will save a profile that you have set up on the fly
SAIDE
        );

    write(
@SAIDE
    Order of the -n -s -l -c arguments are important - the only
    one that is required is -n (name). Color defaults to 
    reset, speech defaults to say, and language defaults to 
    common if they are not set.
SAIDE
       );
   	write("See also: alterobj, objects");
   	return 1;
}
