#include <std.h>
#include <terrain.h>
#include <stealth.h>

inherit DAEMON;

object current_room, obj;

void move_me(string str);

int cmd_sneak(string str) {
   int percent, score;
   string *exit,path;
   object ob;

   exit = ({});
    if (TP->query_bound() || TP->query_tripped() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
   if(!str) {
      notify_fail("where?\nUsage: sneak <exit name>.\n");
      return 0;
   }
/*   if(!TP->is_class("thief")) {
      notify_fail("You can't do that.\n");
      return 0;
   } */
   if(TP->query_in_vehicle())
      return notify_fail("Get real! Look at that beast you are riding!\n");

   if(TP->query_blind())
      return notify_fail("You have been blinded and cannot seem to find the shadows.\n");
   if (TP->query_bound() || TP->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

   if((string*)TP->query_attackers() !=({})) {
      notify_fail("You are too busy to sneak right now!\n");
      return 0;
   }
  if (TP->query_disable()) {
    return notify_fail("You are too occupied to do that right now!\n");
  }
//     if(ob = present("TSR80",TP))        ob->internal_remove();

/*   if(!TP->is_ok_armour("thief")) {
      write("You cannot sneak while wearing all that armor!");
      return 0;
   } */

   exit = environment(TP)->query_exits();
   if(str == "d") str = "down";
   if(str == "u") str = "up";
   if(str == "s") str = "south";
   if(str == "n") str = "north";
   if(str == "e") str = "east";
   if(str == "w") str = "west";
   if(str == "ne") str = "northeast";
   if(str == "nw") str = "northwest";
   if(str == "sw") str = "southwest";
   if(str == "se") str = "southeast";
   if(member_array(str,exit) ==-1) {
      notify_fail("You can't go that way.\n");
      return 0;
   }

   if((int)TP->query_magic_hidden()) {
      move_me(str);
      return 1;
   }
   percent = 20;
   score = TP->query_skill("stealth") + roll_dice(1,20);
   if((int)TP->query_property("chameleoned") > 0){
      score += (int)TP->query_property("chameleoned");
//      tell_object(TP,"Chameleon skin bonus = "+(int)TP->query_property("chameleoned")+".");
   }
   STEALTH_MOD(TP, score, "torso");
   STEALTH_MOD(TP, score, "left foot");
   STEALTH_MOD(TP, score, "right foot");

//   if(sizeof(TP->query_armour("torso"))) score += TP->skill_armor_mod(TP->query_armour("torso"));
//   if(sizeof(TP->query_armour("left foot"))) score += TP->skill_armor_mod(TP->query_armour("left foot"));
//   if(sizeof(TP->query_armour("right foot"))) score += TP->skill_armor_mod(TP->query_armour("right foot"));
   if(score >=percent)
   {
       if(!TP->query_hidden()) { TP->set_hidden(1); }
   }
   else {
      write("You attempt to move unnoticed into the next room.");
      move_me(str);
      if(ob = present("TSR80",TP)) ob->dest_fun();
       if(TP->query_hidden()) { TP->set_hidden(0);}
      return 1;
   }
   write("You attempt to move unnoticed into the next room.");
   move_me(str);
   seteuid(getuid());
   if(!objectp(ob=present("TSR80",TP)))
     ob= new("/cmds/mortal/hide.c");
   ob->set_player(TP);
   ob->move(TP);
   ob->set_room(ETP);
   return 1;
}

void move_me(string str)
{
   string path;
   int prof, increment;

   prof = TP->query_skill("stealth") + roll_dice(1,20);
   //increment = 6- (prof/10);
   if((int)TP->query_property("chameleoned") > 0){
      prof += (int)TP->query_property("chameleoned");
//      tell_object(TP,"Chameleon skin bonus = "+(int)TP->query_property("chameleoned")+".");
   }

   path = ETP->query_exit(str);
   if(catch(call_other(path,"???")))
   {
       tell_object(TP,"You remain where you are.");
       return;
   }

   //increment = TRAVEL_PENALTY[path->query_travel()];
   increment = 1;  // apparently using room exits only drains 1 stamina now *boggle* -Ares

   if(increment < 0) increment = 0;

   if((string)ETP->query_pre_exit_function(str) == "GoThroughDoor" || !TP->query_invis())
   {
      TP->force_me(str);
      TP->increment_stamina(increment);
   }
   else
   {
      TP->increment_stamina(increment);
      ETP->add_tracks(TP,"left",str);
      TP->set_property("sneaking_from",base_name(ETP));
      TP->move_player(path);
      environment(TP)->perform_post_exit(str);
      environment(TP)->do_sneak_func();
   }
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

sneak - attempt to sneak

%^CYAN%^SYNOPSIS%^RESET%^

sneak %^ORANGE%^%^ULINE%^DIRECTION%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

With this you attempt to sneak to another room in specified %^ORANGE%^%^ULINE%^DIRECTION%^RESET%^. Success of this command will depend on your %^MAGENTA%^stealth%^RESET%^ skill and light levels in the room.

%^CYAN%^SEE ALSO%^RESET%^

stealth, hide_in_shadows, steal, pp, spy
");
}
