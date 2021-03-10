#include <std.h>
#include <security.h>

#define DESC_DIR "/daemon/save/saved_descriptions/"

mapping profile_info;

void set_profile_stuff(string str,string what,object tp);
int profile_check(string str);
int set_description(object tp,string profile);
int set_adjective(object tp,string profile);
int set_speech(object tp,string profile);
int initialize_profile(object tp);
int restore_profile_settings(object tp,string profile);
int description_profile_exists(object tp,string str);
int save_description_profile(object tp);
int restore_description_profile(object tp);


void create()
{
    profile_info = ([]);
    call_out("clean_me",5);
}


void set_profile_stuff(string str,string what,object tp)
{
    string profile;

    if(!objectp(tp)) { return; }

    if(!profile = (string)tp->query("relationship_profile")) { return; }

    restore_description_profile(tp);

    if(!mapp(profile_info[profile])) { profile_info[profile] = ([]); }

    switch(what)
    {
    case "description":
        
        if(!str) { map_delete(profile_info[profile],"description"); }
        else { profile_info[profile]["description"] = str; }
        break;

    case "adjective":

        if(!str) { map_delete(profile_info[profile],"adjective"); }
        else { profile_info[profile]["adjective"] = str; }
        break;

    case "speech string":

        if(!str) { map_delete(profile_info[profile],"speech string"); }
        else { profile_info[profile]["speech string"] = str; }

        break;

    case "describe string":

        if(!str) { map_delete(profile_info[profile],"describe string"); }
        else { profile_info[profile]["describe string"] = str; }
        break;

    case "message in":

        if(!str) { map_delete(profile_info[profile],"message in"); }
        else { profile_info[profile]["message in"] = str; }
        break;

    case "message out":

        if(!str) { map_delete(profile_info[profile],"message out"); }
        else { profile_info[profile]["message out"] = str; }
        break;
    }

    save_description_profile(tp);
}


int set_description(object tp,string profile)
{
    string desc;

    if(!objectp(tp)) { return 0; }

    desc = profile_info[profile]["description"];

    if(desc) { tp->set_description(desc); }
    else { tp->set_description("You currently have no description set.  Please enter one as soon as possible."); }

    return 1;
}


int set_adjective(object tp,string profile)
{
    string adj;

    if(!objectp(tp)) { return 0; }

    adj = profile_info[profile]["adjective"];

    if(adj) { tp->setDescriptivePhrase(adj); }
    else { tp->setDescriptivePhrase("$R with no adjective set"); }
    return 1;
}


int set_speech(object tp,string profile)
{
    string speech,describe;

    if(!objectp(tp)) { return 0; }

    speech = profile_info[profile]["speech string"];
    describe = profile_info[profile]["describe string"];

    if(speech)
    {
        tp->set("speech string",speech);
        if(describe) { tp->set("describe string", describe); }
        else { tp->delete("describe string"); }
    }
    else
    {
        tp->delete("speech string");
        tp->delete("describe string");
    }

    return 1;
}


int set_message_in(object tp,string profile)
{
    string message_in;

    if(!objectp(tp)) { return 0; }

    message_in = profile_info[profile]["message in"];

    if(message_in) { tp->force_me("message in "+message_in); }
    else { tp->force_me("message in enters"); }
    return 1;
}


int set_message_out(object tp,string profile)
{
    string message_out;

    if(!objectp(tp)) { return 0; }

    message_out = profile_info[profile]["message out"];

    if(message_out) { tp->force_me("message out "+message_out); }
    else { tp->force_me("message out leaves"); }
    return 1;
}


int initialize_profile(object tp)
{
    string profile,desc,speech_string,describe_string,adjective,message_in,message_out,true_name;
    mapping message_map;

    if(!objectp(tp) || avatarp(tp)) { return 0; }

    true_name = (string)tp->query_true_name();
    profile = tp->query("relationship_profile");
    if(!profile) { return notify_fail("You don't seem to have a relationship profile set."); }
    profile_info[profile] = ([]);

    desc = tp->query_description();
    speech_string = tp->query("speech string");
    describe_string = tp->query("describe string");
    adjective = tp->getDescriptivePhrase();

    if(!mapp(tp->query("message_map"))) { tp->set("message_map",([])); }

    message_map = tp->query("message_map");
    if(mapp(message_map[profile]))
    {
        message_in = message_map[profile]["in"];
        message_out = message_map[profile]["out"];
    }

    if(desc)                { profile_info[profile]["description"] = desc; }
    if(speech_string)       { profile_info[profile]["speech string"] = speech_string; }
    if(describe_string)     { profile_info[profile]["describe string"] = describe_string; }
    if(adjective)           { profile_info[profile]["adjective"] = adjective; }
    if(message_in)          { profile_info[profile]["message in"] = message_in; }
    if(message_out)         { profile_info[profile]["message out"] = message_out; }

    save_description_profile(tp);
    return 1;
}


int profile_check(string str)
{
    if(!mapp(profile_info)) { return 0; }
    if(!mapp(profile_info[str])) { return 0; }
    if(!sizeof(keys(profile_info[str]))) { return 0; }
    return 1;
}


int restore_profile_settings(object tp,string profile)
{
    if(!objectp(tp)) { return 0; }

    restore_description_profile(tp);

    if(!profile_check(profile)) { return 0; }
    
    set_description(tp, profile);
    set_adjective(tp, profile);
    set_speech(tp, profile);
    set_message_in(tp,profile);
    set_message_out(tp,profile);
    return 1;
}


int description_profile_exists(object tp, string str)
{
    string real_name,folder;

    if(!objectp(tp)) { return 0; }
    if(!str || str == "" || str == " ") { return 0; }
    str = lower_case(str);

    real_name = (string)tp->query_true_name();
    folder = real_name[0..0]+"/";

    if(!file_exists(DESC_DIR+folder+real_name+".o")) { return 0; }
    return 1;
}


int save_description_profile(object tp)
{
    string true_name,folder;

    if(!objectp(tp)) { return 0; }
    true_name = (string)tp->query_true_name();
    folder = true_name[0..0]+"/";
    seteuid(UID_ROOT);
    save_object(DESC_DIR+folder+true_name);
    return 1;
}


int restore_description_profile(object tp)
{
    string true_name,folder;

    if(!objectp(tp)) { return 0; }
    true_name = (string)tp->query_true_name();
    folder = true_name[0..0]+"/";
    if(!description_profile_exists(tp,true_name)) { return 0; }
    restore_object(DESC_DIR+folder+true_name);
}


int new_description_profile(object tp)
{
    string true_name,folder;

    if(!objectp(tp)) { return 0; }
    true_name = (string)tp->query_true_name();
    folder = true_name[0..0]+"/";

    profile_info = ([]);
    initialize_profile(tp);

    seteuid(UID_ROOT);
    save_object(DESC_DIR+folder+true_name);
    return 1;
}


int clean_me()
{
    if(!objectp(TO)) { return 0; }
    destruct(TO);
    return 1;
}