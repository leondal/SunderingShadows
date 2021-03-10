#include <std.h>

inherit DAEMON;

int cmd_wizheal(string str)
{
    object ob,*ppl;
    int i;

    if(str == "all")
    {
        ppl = all_living(ETP);
        for(i=0;i<sizeof(ppl);i++)
        {
            ob = ppl[i];
            if(!objectp(ppl[i])) { continue; }

            ob->set_hp(ob->query_max_hp());
            ob->heal(1);
            write("You heal "+ob->QCN+".\n");
            if(ob != this_player()) tell_object(ob, "You are healed by "+TPQCN+".\n");
        }
        return 1;
    }

    if(!str) ob = this_player();
    else ob = find_living(str);
    if(!ob) { ob = present(str,ETP); }
    if(!ob) {
        notify_fail(capitalize(str) +": not found\n");
        return 0;
    }
    tell_object(TP, "ob max_hp = "+ob->query_max_hp());
    ob->set_hp(ob->query_max_hp());
    ob->heal(1);
    write("You heal "+ob->QCN+".\n");
    if(ob != this_player()) tell_object(ob, "You are healed by "+TPQCN+".\n");
    return 1;
}

int help()
{
  write( @EndText
Syntax: wizheal <user>
Effect: Puts <user> back on full hit points.
Warning: Do not heal players unless you are a law arch.
EndText
  );
  return 1;
}
