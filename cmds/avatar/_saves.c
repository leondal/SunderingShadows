#include <std.h>


int help()
{
    write("Syntax: saves <class>\n"
        "Returns the fort, reflex, and will save for a given class");
    return 1;
}

int cmd_saves(string str)
{
    int i,*tmp=({});
    if(!stringp(str) || str == "" || str == " ")
    {
        help();
        return 1;
    }
    for(i=1;i<41;i++)
    {
        tmp = "/daemon/saving_throw_d.c"->get_saves(str,i);
        tell_object(TP,"    Level "+arrange_string(""+i+"",2)+"  fort:  "+arrange_string(tmp[0],2)+"  reflex:  "+arrange_string(tmp[1],2)+"  will:  "+tmp[2]+"");
    }
    return 1;
}   
