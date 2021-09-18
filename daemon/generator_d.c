//ACTIVELY USED

#include <std.h>
#include <macros.h>

inherit DAEMON;

int save_me(string file){return 1;}

mixed make_file(string template, string file, mapping values){
    string code, err;
    string *keySet;
    object ob;
    int i;
    if(!file_exists(template)) return "No template found";
    if(file_exists(file+".c"))
        rm(file+".c");

    code = read_file(template);
    keySet = keys(values);
    for(i=0;i<sizeof(keySet);i++){
        code = REPLACE(values[keySet[i]],code,keySet[i]);
    }
    write_file(file+".c",code);
    err = catch(ob = new(file));
    if(stringp(err)) return err;
    return ob;


}   

