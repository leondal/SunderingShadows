 
//     _steal.c
//     Rogue ability
//     coded by Descartes of Borg October 1992
//     small modifications by Hanse November 1992
//     changed to make stealing harder for non-rogues and to allow
//     the stealing of wielded/worn objects by powerful rogues
//     by Gregon October 1993
 
#include <std.h>
 
inherit DAEMON;
 
int cmd_steal(string str) {
    object *inv;
    object victim, tp, ob;
    string what, whom;
    int i, skip, which;
    int steal, anti, dexterity, x;
    int align_formula;
 
    if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in your immaterial state.\n");
         return 0;
    }
    if(environment(this_player())->query_property("no steal")) {
       notify_fail("A magic force prevents you from doing that!\n");
       return 0;
    }
    if(!str) {
       notify_fail("Steal what from whom?\n");
       return 0;
    }
    if(this_player()->query_disable()) return 1;
    if(sscanf(str, "%s from %s", what, whom) != 2) {
       notify_fail("Steal what from whom?\n");
       return 0;
    }
    if(this_player()->query_current_attacker()) {
        notify_fail("You can't do that while in combat!\n");
        return 0;
    }
    tp = this_player();
    victim = present(whom, environment(tp));
    if(!victim) {
       notify_fail(capitalize(whom)+" is not here!\n");
       return 0;
    }
    if(!living(victim)) {
       notify_fail(capitalize(whom)+" is not a living thing!\n");
       return 0;
    }
    if(victim->is_player() && !interactive(victim)) {
        notify_fail("You cannot steal from link-dead players.\n");
        return 0;
    }
    tp->set_disable();
    if(wizardp(victim) )
    {
        notify_fail(victim->query_cap_name()+" glares at you hard.\n");
        return 0;
    }
    if((int)victim->query_level() == 1) {
        notify_fail("Let the newbie alone!\n");
        return 0;
    }
    ob = present(what, victim);
    if(victim == tp) {
       notify_fail("Steal from yourself?\n");
       return 0;
    }
    if(!ob) {
       inv = all_inventory(victim);
       if(sscanf(what, "%s %d", what, which) != 2) {
           notify_fail(capitalize(whom)+" does not have that!\n");
           return 0;
       }
       for(i=0, skip=0; i<sizeof(inv) && !ob; i++) {
           if(inv[i]->id(what)) {
               skip ++;
               if(skip == which) ob = inv[i];
           }
       }
       if(!ob) {
           notify_fail(capitalize(whom)+" does not have that!\n");
           return 0;
       }
    }
 
    if(!ob->get()) {
        notify_fail("You cannot steal that!\n");
        return 0;
    }
    if(ob->query_property("no steal")) {
        notify_fail("You fail to steal "+victim->query_cap_name()+
           "'s "+ob->query_name()+
           ".\nYou are unsure if anyone noticed the attempt.\n");
        return 0;
    }
    steal = (int)tp->query_skill("stealing");
    anti = (int)victim->query_stats("dexterity");
    steal -= anti;
    if(steal < 0) steal = 1;
    x = random(101);
    if(ob->query_wielded() || ob->query_worn()) {
     if(steal > 60)
       {steal -=50;
         if(steal >x && (string)ob->query_type()!="armour"
            && (string)ob->query_type()!="body armour")
        {message("info","You successfully steal "+victim->query_cap_name()+
                      "'s "+ob->query_name()+".\n"
                      +capitalize((string)victim->query_subjective())+" does "
                      "not look at all happy.",tp);
         tp->add_alignment(- ((int)victim->query_alignment())/100);
         if((string)victim->query_class() != "rogue")
          tp->add_skill_points("stealing");
         message("info",tp->query_cap_name()+" just stole your "+
                 ob->query_name()+"!",victim);
         if(ob->move(tp)) {
         write("You cannot carry that!\nYou drop "+ob->query_name()+".");
         say(tp->query_cap_name()+" drops "+ob->query_name()+".", tp);
         ob->move(environment(tp));
         return 1;}
        }
        else
        {message("info","You are not successful.\n"+victim->query_cap_name()+
                 " does not have a very happy look on "
                 +victim->query_subjective()+" face!", tp);
         message("info",tp->query_cap_name() + " just tried to steal your "+
                 ob->query_name()+"!",victim);
         return 1;
        }
       }
     else
      {if(ob->query_worn())
        notify_fail("You cannot steal a worn item!\n");
       else
        notify_fail("You cannot steal a wielded item!\n");
       return 0;
      }
    }
    if((string)tp->query_class()!="rogue")

      {steal -= 30;}
    if(steal > x) {
       write("You successfully steal "+victim->query_cap_name()+"'s
"+ob->query_name()+".\n"+capitalize((string)victim->query_subjective())+" does
not even notice!");
        tp->add_alignment(- ((int)victim->query_alignment())/100);
        if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 10);
       if(ob->move(tp)) {
           write("You cannot carry that!\nYou drop "+ob->query_name()+".");
           say(tp->query_cap_name()+" drops "+ob->query_name()+".", tp);
           ob->move(environment(tp));
       }
       return 1;
    }
    x -= steal;
    if(x<10) {
       write("You successfully steal "+victim->query_cap_name()+"'s
"+ob->query_name()+".\nYou are not sure if anyone noticed.");
       tell_room(environment(tp), tp->query_cap_name()+" steals a "+ob->query_name()+"
from "+victim->query_cap_name()+".", ({ victim, tp }));
       tp->add_alignment( align_formula );
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 8);
       if(ob->move(tp)) {
           write("You cannot carry that!\nYou drop "+ob->query_name()+".");
           say(tp->query_cap_name()+" drops "+ob->query_name()+".", tp);
           ob->move(environment(tp));
       }
       return 1;
    }
    if(x<20) {
       write("You successfully steal "+victim->query_cap_name()+"'s
"+ob->query_name()+".\nYou are not sure if anyone noticed.");
       tell_object(victim, "You feel someone brush against you.");
       tell_room(environment(tp), tp->query_cap_name()+" slyly brushes by
"+victim->query_cap_name()+" and steals a "+ob->query_name()+"",  ({ tp,
victim }));
       tp->add_alignment( align_formula );
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 6);
       if(ob->move(tp)) {
           write("You cannot carry that!\nYou drop "+ob->query_name()+".");
           say(tp->query_cap_name()+" drops "+ob->query_name()+".", tp);
           ob->move(environment(tp));
       }
       return 1;
    }
    if(x<30) {
       write("You successfully steal "+victim->query_cap_name()+"'s
"+ob->query_name()+".\nYou are not sure if anyone noticed.");
       tell_object(victim, tp->query_cap_name()+" just stole your
"+ob->query_name()+"!");
       tell_room(environment(tp), tp->query_cap_name()+" steals a "+ob->query_name()+"
from "+victim->query_cap_name()+".", ({victim, tp}));
       tp->add_alignment( align_formula );
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 5);
       if(!victim->is_player()) victim->kill_ob(tp, 0);
       if(ob->move(tp)) {
           write("You cannot carry that!\nYou drop "+ob->query_name()+".");
           say(tp->query_cap_name()+" drops "+ob->query_name()+".", tp);
           ob->move(environment(tp));
       }
       return 1;
    }
    if(x < 40) {
        write("You fail to steal "+victim->query_cap_name()+"'s
"+ob->query_name()+", but no one notices the attempt.");
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 4);
       return 1;
    }
    if(x < 50) {
       write("You fail to steal "+victim->query_cap_name()+"'s
"+ob->query_name()+".\nYou are unsure if anyone noticed the attempt.");
       tell_room(environment(tp), tp->query_cap_name()+" attempts to steal something
from "+victim->query_cap_name()+".", ({ victim, tp }));
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 3);
       return 1;
    }
    if(x < 60) {
       write("You fail to steal "+victim->query_cap_name()+"'s
"+ob->query_name()+".\nYou are unsure if anyone noticed the attempt.");
       tell_room(environment(tp), tp->query_cap_name()+" slyly brushes by
"+victim->query_cap_name()+".", ({victim, tp}));
       tell_object(victim, "You feel someone brush against you.");
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 2);
       return 1;
    }
    write("You fail to steal "+victim->query_cap_name()+"'s
"+ob->query_name()+".\nYou are unsure if anyone noticed the attempt.");
    tell_room(environment(tp), tp->query_cap_name()+" attempts to steal
something from "+victim->query_cap_name()+", but fails.", ({victim, tp}));
    tell_object(victim, tp->query_cap_name()+" just tried to steal a
"+ob->query_name()+" from you!\nLuckily, "+tp->query_subjective()+" failed!");
    if((string)tp->query_class() != (string)victim->query_class())
       tp->add_skill_points("stealing", 1);
    if(!victim->is_player()) victim->kill_ob(tp, 0);
    return 1;
}
 
void help() {
message("Ninfo", "Syntax: <steal [item] from [being]>\n"+
"The steal command allows you to steal objects from other players and\n"+
"monsters.  A fight can automatically ensue if a monster becomes aware of\n"+
"your attempt.  And you never know what a player might do.  The command is\n"+
"sometimes successfull, and sometimes the victim or others might notice, \n"+
"or sometimes no one will notice at all.  It all depends on your ability\n"+
"to steal.\n", this_player());
}
