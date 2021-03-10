#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit OBJECT;

int started;
mapping featureMap;
string featureName;
void create()
{
    ::create();
    set_property("no animate", 1);
    set_property("no drop", 1);
    set_property("soulbound", 1);
    featureMap = ([]);
}

void abort_feature()
{
    if(!objectp(ETO)) 
    {
        TO->remove();
        return;
    }
    tell_object(ETO, "Aborting adding a feature for player voting.");
    TO->remove();
    return;
}

void get_feature_name(string myinput, object who)
{
    int res;
    if(!objectp(who)) { abort_feature(); return; }
    if(!stringp(myinput))
    {
        tell_object(who, "Please input the name of the feature you want to set up for player voting. Enter ** to abort.");
        input_to("get_feature_name", 0, ETO);
        return;
    }
    if(myinput == "**")
    {
        abort_feature();
        return;
    }
    if(res = FEATURE_D->can_insert_feature(who, myinput) == 1)
    {
        tell_object(who, "You are adding the feature "+myinput+" for player voting. Please input the ETA for this feature, "+
        "if you have one. You can enter nothing or enter two weeks, 6 years, etc. Enter ** to abort.");
        featureMap += ([myinput : (["Feature Name" : myinput]),]);
        featureName = myinput;
        input_to("get_feature_eta", 0, ETO);
        return;
    }
    if(res == -1)
    {
        tell_object(who, "Invalid object.");
        TO->remove();
        return;
    }
    if(res == -2)
    {
        tell_object(who, "You do not have permission to add a feature. Only immortals above apprentice rank are allowed to add features for voting.");
        TO->remove();
        return;
    }
    tell_object(ETO, "You attempted to enter an invalid feature name or a feature name that already is being voted on. "+
    "Please input the name of the feature you want to set up for player voting. Enter ** to abort.");
    input_to("get_feature_name", 0, ETO);
    return;   
}

void get_feature_eta(string myinput, object who)
{
    if(!objectp(who)) { abort_feature(); return; }
    if(myinput == "**") { abort_feature(); return; }
    if(!stringp(myinput) || myinput == "" || myinput == 0) myinput = "TBA";
    tell_object(who, "You are setting up "+featureName+" with an ETA of "+myinput+". Please input when voting for this feature will "+
    "end. In seconds (for now). This will be added to the current time. If you enter nothing then it will default to -1 or no end, "+
    "until it is manually removed. Enter ** to abort.");
    featureMap[featureName]["ETA"] = myinput;
    input_to("get_feature_vote_ends", 0, ETO);
    return;   
}

void get_feature_vote_ends(string myinput, object who)
{
    if(!objectp(who)) { abort_feature(); return; }
    if(myinput == "**") { abort_feature(); return; }
    if(!stringp(myinput) || myinput == "" || myinput == 0) myinput = "-1";
    if(!to_int(myinput)) 
    {
        tell_object(who, "Please input when voting for this feature will end. In seconds (for now). This will be added to the current time. "+
        "If you enter nothing then it will default to -1 or no end, until it is manually removed. Enter ** to abort.");
        input_to("get_feature_vote_ends", 0, ETO);
        return;
    }
    myinput = to_int(myinput);
    if(myinput != -1) myinput = to_int(time() + to_int(myinput));
    featureMap[featureName]["expires"] = myinput;
    tell_object(who, "Please input the long description of this feature. This is essentially what the features hopes to do. This is visible "+
    "to players via the flag features | view "+featureName+" command. Enter ** to abort. Enter . on a blank line when you are finished.");
    input_to("get_feature_description", 0, ETO, "");
    return;    
}

void get_feature_description(string myinput, object who, string total_input)
{
    if(!objectp(who) || myinput == "**") { abort_feature(); return; }
    if(myinput == ".")
    {
        tell_object(who, "You have chosen the following for the feature description:\n"+total_input+"\nIs this correct? Yes or no?");
        input_to("check_feature_description", 0, ETO, total_input);
        return;
    }
    total_input += myinput;
    input_to("get_feature_description", 0, ETO, total_input);
    return;
}

void check_feature_description(string myinput, object who, total_input)
{
    if(!objectp(who) || myinput == "**") { abort_feature(); return; }
    if(myinput == "Yes" || myinput == "yes") 
    {
        tell_object(who, "The feature "+featureName+" is now being added.... ");
        featureMap[featureName]["description"] = total_input;
        FEATURE_D->inject_feature(featureMap, who);
        tell_object(who, "You can check the flag command to verify that the feature was "+
        "added for voting correctly.");
        TO->remove();
        return;
    }
    if(myinput == "No" || myinput == "no")
    {
        tell_object(who, "Please input the long description of this feature. This is essentially what the features hopes to do. This is visible "+
        "to players via the flag features | view "+featureName+" command. Enter ** to abort. Enter . on a blank line when you are finished.");
        input_to("get_feature_description", 0, ETO, "");
        return;
    }
    tell_object(who, "You have chosen the following for the feature description:\n"+total_input+"\nIs this correct? Yes or no?");
    input_to("check_feature_description", 0, ETO, total_input);
    return;
}


void init()
{
    ::init();
    if(started) return;
    if(objectp(ETO)) 
    {
        if(living(ETO) && wizardp(ETO))
        {
            started = 1;
            tell_object(ETO, "Please input the name of the feature you want to set up for player voting. Enter ** to abort.");
            input_to("get_feature_name", 0, ETO);
            return;
        }
        TO->remove();
        return;
    }
    return;
}
