#include <std.h>
#include <security.h>

#define SAVE_FILE "/daemon/save/avatar"

inherit DAEMON;
mapping ava;   //ava["loviatar"] = ({personas});
string *all_personas;


void SAVE();

void create()
{
    ::create();

    ava = ([]);
    all_personas = ({});
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE);
    seteuid(getuid());
}

void SAVE() {
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
}

int is_persona(string name){
    if(!all_personas){
        all_personas = ({ });
        return 0;
    }

    if(member_array(name, all_personas) == -1) return 0;
    return 1;
}

string *query_avatar_of_persona(string name)
{
    string *temp, *returner;
    int i;
    if(!ava){
         ava = ([]);
         return "";
    }
    if(!user_exists(name)) return "";
    temp = keys(ava);
    returner = ({ });

    for(i = 0;i<sizeof(temp);i++){
        if(member_array(name, ava[temp[i]]) != -1)
            returner += ({temp[i]});
    }

    return returner;

}

string *query_personas_of_avatar(string name)
{
    if(!ava){
        ava = ([]);
        return ({});
    }             
    if(!user_exists(name)) return ({});
    return ava[name];
}

mapping query_ava_map(){
    return ava;
}

string *query_all_personas(){
    return all_personas;
}

int load_avatar_personas(string str)
{
    mapping borg;
    string *files, *temp1, *temp2;
    string exp, file, junk;
    int i, max;

    if (!str) return 2;

    if(!ava)
         ava = ([]);
    if(!all_personas)
        all_personas = ({ });

    str = lower_case(str);
    exp = "vis_name";
    file = "/avatar/"+str+"/*.o";
    files = (users()[0])->wild_card(file);

    if (!(max = sizeof(files)))
        return 3;

    for (i=0, borg = ([]); i<max; i++) {
        borg[files[i]] = regexp(explode(read_file(files[i]), "\n"), exp);
        if (!sizeof(borg[files[i]])) map_delete(borg, files[i]);
    }

    temp1 = ({});
    temp2 = ({});
    
    if (!(max = sizeof(files = keys(borg))))
        return 4;
    else {
        for (i=0; i<max; i++)
            temp1 += ({  sprintf("%s", implode(borg[files[i]],"\n"))  });
    }

    for(i = 0;i<max;i++){
        sscanf(temp1[i], "%s\"%s\"", junk, exp);
        temp2 += ({exp});
    }
    
    temp2 = distinct_array(temp2);
    all_personas += temp2;
    all_personas = distinct_array(all_personas);
    ava[str] = temp2;

    SAVE();

    return 1;
}

int remove_avatar(string name){
    if(!ava)
        ava = ([]);

    ava[name] = ({ });
}

void reset_all(){
    ava = ([]);
    all_personas = ({});
}

string *query_persona_file(string avaname, string pername)
{
    mapping borg;
    string *files, *temp1, *temp2;
    string exp, file, junk, str;
    int i, max;

    if (!avaname || !pername) return 0;

    if(!ava){
        ava = ([]);
        return 0;
    }
    if(!all_personas){
        all_personas = ({ });
        return 0;
    }
    if(!user_exists(avaname)) return ({});
    str = lower_case(avaname);
    exp = lower_case(pername);
    exp = "vis_name \""+exp+"\"";
    file = "/avatar/"+str+"/*.o";
    files = (users()[0])->wild_card(file);

    if (!(max = sizeof(files)))
        return 0;

    for (i=0, borg = ([]); i<max; i++) {
        borg[files[i]] = regexp(explode(read_file(files[i]), "\n"), exp);
        if (!sizeof(borg[files[i]]))
            map_delete(borg, files[i]);
    }

    temp1 = ({});
    temp2 = ({});
    
    if (!(max = sizeof(files = keys(borg))))
        return 0;
    
    return files;
}
