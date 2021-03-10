//changed 11/5/03 by Circe so that you could not hide things while
//bound or blind.  Last changed Feb 21, 2003
//altered again by Circe 11/21/04 to allow for chance for others
//to spot you.
//fixed a bug where you couldn't hide something in your inventory
//on yourself if you were close to max weight -Ares 6/12/05

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_hide(string str)
{
    string what, where;
    object item, container;
    object *live, * attackers;
    object targ;
    int prof, flag, delay, i, hide_level, max_hide_level;
    int num,opposed;

    if (!str) {
        return help();
    }
//checks for bound, etc. and blind added by Circe 11/5/03
    if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
        TP->send_paralyzed_message("info",TP);
        return 0;
    }
    if (TP->query_blind()) {
        notify_fail("You are blind and cannot see how to hide anything.\n");
        return 0;
    }
// check for combat added by Lujke 02 March 2008
    attackers = TP->query_attackers();
    if (sizeof(attackers)>0){
        notify_fail("You can't hide things while you are fighting.");
        return 0;
    }
    if (sscanf(str, "%s in %s",what, where) != 2) {
        if (sscanf( str, "%s on me",what) == 1) {
            where = TPQN;
        } else {
            what = str;
        }
    }
    //prof = TP->query_nwp("concealment");
    num = (int)TP->query_skill("thievery");
    num = num / 2;
    prof = num;
    prof+=2;
    max_hide_level = (prof + (int)TP->query_base_character_level()/2);
    hide_level = max_hide_level;

    item = present(what, TP);
    if (!objectp(item)) {
        item = present(what, ETP);
        if (!objectp(item)) {
            return notify_fail("No "+what+" here.\n");
        }
    }
    if(living(item)) return notify_fail("You can't hide living things ... yes it would be cool.\n");

    if (stringp(where)) {

        container = present(where,TP);
        if (!objectp(container)) {
            container = present(where, ETP);
            if (!objectp(container)) {
                return notify_fail("No "+where+" here.\n");
            }
        }

    } else {
        container = ETP;
    }
   if( (prof) > 12)  {
      delay = 1;
   } else {
      delay = (15 - prof);
   }

   if(!TP->query_time_delay("concealment",delay)) {
      notify_fail("You need more time to figure out exactly how to manage that with any degree of success.\n");
      return 0;
   }
   TP->set_time_delay("concealment");

    if(living(container) && container != TP && !container->query_bound() && !container->query_unconscious() && !container->query_paralyzed()){
        tell_object(container,"%^BOLD%^"+TPQCN+" tried to hide something on you.");
       return notify_fail("They won't allow you to do that.\n");
    }
    if (item->drop()) {
        return notify_fail("You can't hide that item.\n");
    }

    if (container->is_bag()) {
        flag = container->put_into(what+" in "+((string *)container->query_id())[0]);
    } else {
        flag = !item->move(container);
        if (flag) {
            notify_fail("You can not do that.\n");
        }
    }

    if (container == TP && present(item,container)) { flag = 1; } // added 6-12-05 by Ares

    if (!flag) {
        return notify_fail("You failed to put the "+item->query_name()+" into the "+container->query_name()+".\n");
    }

    "/daemon/hide_d"->hideItem(item,TP,(hide_level));
    NWP_D->perform_nwp(TP,"concealment");
    write("%^BOLD%^You attempt to hide the "+item->query_short()+" in the "+container->query_short()+".");
    live = all_inventory(ETP);
    if(prof > 12)
    {
       for(i=0;i<sizeof(live);i++)
       {
          targ = live[i];
          if(!objectp(targ)) continue;
          //if(!targ->query_nwp("concealment")) continue;
          if(!userp(targ)) { continue; }
          if(!targ->query_skill("thievery")) continue;
          opposed = (int)targ->query_skill("thievery");
          opposed = opposed / 2;
          if(targ == TP) continue;
          if((prof) < opposed /*(int)targ->query_nwp("concealment")*/)
          {
              tell_object(targ,"You notice "+TPQCN+" looking around suspiciously.");
          }
       }
    }
    else
    {
       for(i=0;i<sizeof(live);i++)
       {
          targ = live[i];
          if(!objectp(targ)) continue;
          //if(!targ->query_nwp("concealment")) continue;
          if(!userp(targ)) { continue; }
          if(!targ->query_skill("thievery")) continue;
          opposed = (int)targ->query_skill("thievery");
          opposed = opposed / 2;
          if(targ == TP) continue;
          if(prof < (opposed /*((int)targ->query_nwp("concealment")*/+random(5)))
          {
             tell_object(targ,"You notice "+TPQCN+" looking around suspiciously.");
          }
       }
    }
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

hide - hide something

%^CYAN%^SYNOPSIS%^RESET%^

hide %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ [in %^ORANGE%^%^ULINE%^CONTAINER%^RESET%^|on me]

%^CYAN%^DESCRIPTION%^RESET%^

This will attempt hide %^ORANGE%^%^ULINE%^OBJECT%^RESET%^, either in current room (without an argument), or in %^ORANGE%^%^ULINE%^CONTAINER%^RESET%^, or on yourself.

Success of this action is based on your thievery skill, and you won't be able to tell how well hidden something is. Something hidden in the room could be revealed with %^ORANGE%^<search>%^RESET%^ command.

%^CYAN%^SEE ALSO%^RESET%^

glance, look, spy, search, steal
");
}
