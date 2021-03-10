//army

#include <std.h>

inherit DAEMON;

int cmd_army(string str){
  object remote, ob, *mons, obNew;
  int i,j;
  string action, what;
  
  
  if(!str || str == ""){
    
    if(remote = present("devicex998",TP)){
      mons = remote->query_mon();
      j = sizeof(mons);
      tell_object(TP,"%^BOLD%^%^GREEN%^The following monsters follow your every whim.");
      tell_object(TP," -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
      for(i=0;i<j;i+=2){
	if(j<= (i+1)){
	  if(!objectp(mons[i])) continue;
	  tell_object(TP,"\t\t"+capitalize(mons[i]->query_name()));
	} else {
	  if(!objectp(mons[i]) || !objectp(mons[i+1])) continue;
	  tell_object(TP,"\t\t"+capitalize(mons[i]->query_name())+"\t\t\t"+capitalize(mons[i+1]->query_name()));
	  
	}
      }
      return 1;
    }
    return notify_fail("You have no army formed!\n");
  }
  
  if(sscanf(str, "%s %s", action, what) != 2){
    
    if(sscanf(str, "%s", action) != 1){
      return notify_fail("Usage: army | army <add|remove|bring|followme|unfollow|capture|nocapture> <monster name>\n");
    }
  }
  
  if(action == "add"){
    if(!(ob = present(what,ETP))){
      return notify_fail("That is not here.\n");
    }
    if(userp(ob)) return notify_fail("Nice try.\n");
    if(!remote = present("devicex998",TP)){
      remote = new("/cmds/avatar/armyremote");
      remote->set_caster(TP);
      remote->move(TP);
    }
    obNew = new(base_name(ob));
    obNew->move(ETP);
	obNew->set_property("knock unconscious",1);
    remote->add_mon(obNew);
    tell_object(TP,"%^BOLD%^You have created a new "+obNew->query_cap_name()+" and it is under your control");
    tell_object(TP,"%^BOLD%^Please be careful with the auto attacks.");
    return 1;
  }else if(action == "remove"){
    if(!remote = present("devicex998",TP)){
      notify_fail("You currently don't have an army under your control.");
    }
    
    if(!ob = present(what,ETP)){
      return notify_fail("That is not here.\n");
    }
    if(member_array(ob, (object *)remote->query_mon()) == -1){
      return notify_fail("That monster doesn't appear to be a part of your army\n");
      
    }
    destall(ob);
    tell_object(TP,"That monster is now no longer part of your army....\n");
    return 1;
    
  } else if(action == "bring"){
    
    if(!remote = present("devicex998",TP)){
      return notify_fail("You currently don't have an army under your control.");
    }
    mons = remote->query_mon();
    j = sizeof(mons);
    for(i=0;i<j;i++){
      if(!objectp(mons[i])) continue;
      mons[i]->move(ETP);
      
    }
    tell_object(TP,"%^BOLD%^You bring your army to you.");
    return 1;
    
  } else if (action == "followme") {
    if(!remote = present("devicex998",TP)){
      return notify_fail("You currently don't have an army under your control.");
    }
    mons = remote->query_mon();
    j = sizeof(mons);
    for(i=0;i<j;i++){
      if(!objectp(mons[i])) continue;
      if (TP->add_follower(mons[i]))
	write (mons[i]->query_name()+" is now following you.");
      else
	write (mons[i]->query_name()+" failed to fall in line behind you.");
    }
    return 1;
  } else if (action == "unfollow") {
    if(!remote = present("devicex998",TP)){
      return notify_fail("You currently don't have an army under your control.");
    }
    mons = remote->query_mon();
    j = sizeof(mons);
    for(i=0;i<j;i++){
      if(!objectp(mons[i])) continue;
      if(!objectp(mons[i]->query_following()))
	 TP->remove_follower(mons[i]);
    }
    return 1;
  } else if (action == "capture") {
    if(!remote = present("devicex998",TP)){
      return notify_fail("You currently don't have an army under your control.");
    }
    mons = remote->query_mon();
    j = sizeof(mons);
    for(i=0;i<j;i++){
      if(!objectp(mons[i])) continue;
      mons[i]->set_property("knock unconscious",1);
    }
    return 1;
  } else if (action == "nocapture") {
    if(!remote = present("devicex998",TP)){
      return notify_fail("You currently don't have an army under your control.");
    }
    mons = remote->query_mon();
    j = sizeof(mons);
    for(i=0;i<j;i++){
      if(!objectp(mons[i])) continue;
      mons[i]->remove_property("knock unconscious");
    }
    return 1;
  } else {
    
    return notify_fail("Usage: army | army <add|remove|bring|followme|unfoloow|capture|nocapture> <monster name>\n");
  }
}

int help(){
   write(
@OLI
   Usage: army | army <add|remove|bring|followme|unfollow|capture|nocapture> <monster name>
   Only the add and remove need a monster ID. The other commands act on the entire army.
   Use this command to gather your army, when ready command army to <..>
OLI
   );
   return 1;
}
