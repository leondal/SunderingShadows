#include <std.h>
 
inherit DAEMON;
 
int cmd_poison(string str) {
    object weapon;
 
        if(!str)
          {
         notify_fail("That isn;t in your inventory.\n");
          return 0;
          }
 
        if(!(weapon=present(str, this_player())))
           {
             notify_fail("You can't poison that!\n");
            return 0;
           }
        
       if(environment(this_player())->query_property("no magic"))
        {
     return notify_fail("A supernatural force prevents your magic.\n");
        }
        
      if((int)this_player()->query_mp() < 50)
        {
      return notify_fail("Lasher thinks you need some spiritual rest.\n");
        }
      
     if((int)weapon->query_poisoning()>0)
       {
        notify_fail("That is already poisoned!\n");
        return 0;
       }
 
    this_player()->set_magic_round();
    this_player()->add_mp(-50);
    message("my_action", 
       "You call upon the powers of Lasher!", this_player());
    message("other_action", 
       (string)this_player()->query_cap_name()+
       " calls upon the powers of Lasher.", environment(this_player()),
       ({ this_player() }));
     
     if(random(101) > (int)this_player()->query_skill("conjuring")) 
      {
    message("my_action", 
      "Lasher does not hear your call.", this_player());
    return 1;
    }
    
    weapon->add_poisoning(random((int)this_player()->query_level()));
    weapon->add_skill_points("conjuring", random(50));
    message("my_action", "The poison of Lasher covers your "+
      (string)weapon->query_short()+".", this_player());
    return 1;
}
        
        
        
    
 
void help() {
    message("help", "Syntax: <poison [item]>\n\n"
      "Calls upon the powers of Lasher to stain the item with his "
      "poison.", this_player());
}
 
