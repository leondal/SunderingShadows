#include <std.h>
#include <security.h>


int cmd_deepupdate(string str)
{
    string *inherit_list;
    object obj,stuff;
    int i,j;

    if(!stringp(str) || str == "" || str == " ")
    {
        tell_object(TP,"Nothing to update.");
        return 1;
    }

    if(!objectp(obj=find_object_or_load(str)))
    {
        if(!objectp(obj=find_player(str)))
        {
            if(!objectp(obj=present(str,ETP)))
            {
                if(!objectp(obj=present(str,TP)))
                {
                    tell_object(TP,"Can't find "+str+"");
                    return 1;
                }
            }
        }
    }

    inherit_list = deep_inherit_list(obj);

    seteuid(UID_SYSTEM);

    for(i=0;i<sizeof(inherit_list);i++)
    {
        TP->force_me("update /"+inherit_list[i]+"");
    }

    return 1;
}