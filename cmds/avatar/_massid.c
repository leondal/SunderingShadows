#include <std.h>

int cmd_massid(string str)
{
    object *objs,*ppl;
    int i,j;

    objs = all_inventory(ETP);

    for(i=0;i<sizeof(objs);i++)
    {
        if(!objectp(objs[i])) { continue; }
        if(living(objs[i])) { continue; }


        ppl = all_inventory(environment(TP));
        for (j = 0;j < sizeof(ppl);j++) 
        {
            if (interactive(ppl[j]))
            {
                objs[i]->add_identified(ppl[j]->query_name());
            }
        }
    }

    tell_room(ETP,"%^CYAN%^"+TP->QCN+" waves "+TP->QP+" hand and reveals the magical properties of "
        "everything in the room.");
    return 1;
}

    