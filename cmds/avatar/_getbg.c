// Created by Yves
#include <daemons.h>
#include <std.h>

inherit DAEMON;

int cmd_getbg(string str)
{
    string bkgrnd, avat,name;
    int isava, ispl;
    if(!objectp(TP)) { return 1; }
    if(!str)
    {
        tell_object(TP, "Whose background do you want to research?\n");
        return 1;
    }
    str=lower_case(str);
    if(!avatarp(TP))
    {
        name = TP->realName(str);
        if(!stringp(name) || name == "") name = str;
        str = name;
    }
    if(user_exists(str)) { ispl = 1; }
    if(!ispl && "/daemon/avatar_d.c"->is_persona(str)) { isava = 1; }
    if(!ispl && !isava) { return notify_fail("That person does not exist in this reality.\n"); }
    if(ispl)
    {
        if(!file_exists("/d/save/background/"+str+".txt"))
        {
            tell_object(TP, "That person does not have a background on record yet.");
            return 1;
        }

        bkgrnd = "daemon/converter"->convertToInput(read_file("/d/save/background/"+str+".txt",6));
        TP->more(explode(bkgrnd,"\n"));
        return 1;
    }
    if(isava)
    {
        avat = ((string *)"/daemon/avatar_d.c"->query_avatar_of_persona(str))[0];
        if(!file_exists("/avatar/"+avat+"/"+str+".txt"))
        {
            tell_object(TP, "That person does not have a background on record yet.");
            return 1;
        }

        write(""+capitalize(str)+"'s Background Information\n");
        bkgrnd = "daemon/converter"->convertToInput(read_file("/avatar/"+avat+"/"+str+".txt",6));
        TP->more(explode(bkgrnd,"\n"));
        return 1;
    }
    return notify_fail("Error, contact a wiz.\n");
}

void help() {
   write("This command will return the background of a player or avatar persona.");
}
