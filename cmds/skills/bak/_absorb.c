//   /bin/user/_absorb.c
//   Written by Forlock for the Nightmare mudlib
 
#include <std.h>
 
inherit DAEMON;
 
int cmd_absorb (string str) {
   object ob;
   int ma, faith, damage;
 
   if((string)this_player()->query_class()!="kataan") {
      notify_fail("The demons laugh at you as you attempt to use a spell of "+
                  "darkness.\n");
      return 0;
   }
 
   if(!str) {
      ob = (object)this_player()->query_current_attacker();
      if(!ob) {
         notify_fail("Absorb from what?\n");
         return 0;
      }
   }
 
   else ob = present(str, environment(this_player()));
   if(!ob) ob = parse_objects(environment(this_player()), str);
   if(!ob || !living(ob)) {
      notify_fail("Look again.\n");
      return 0;
   }
   if(environment(this_player())->query_property("no magic")) {
      notify_fail("A magic force prevents your spell.\n");
      return 0;
   }
    if((int)this_player()->query_alignment() > -200 ) {
        notify_fail("The demons howl with displeasure at you.\n");
        return 0;
    }
    if(!faith=(int)this_player()->query_skill("faith")) {
        notify_fail("The denizens of the underworld do not listen to you.\n");
        return 0;
    }
   if(!ma=(int)this_player()->query_skill("magic attack")) {
      notify_fail("You are not yet a powerfull enough magician to do this.\n");
      return 0;
   }
   if((int)this_player()->query_mp() < 50) {
      notify_fail("Too low on magic power.\n");
      return 0;
   }
   if(this_player()->query_ghost()) {
      notify_fail("Your voice is hollow.\n");
      return 0;
   }
   if(this_player()->query_casting()) return 1;
   if(!ob->kill_ob(this_player(),0)) return 1;
   if(environment(this_player())->query_property("no attack")) {
      notify_fail("A magic force prevents you from casting your spell.\n");
      return 0;
   }
   write("You absorb some health from "+(string)ob->query_cap_name()+" and "
         "feel stronger.");
   tell_room(environment(this_player()), this_player()->query_cap_name()+ 
             " suddenly looks stronger.", ({ob, this_player()}));
   damage = random(ma/3 + faith/3)+10;
   this_player()->set_casting(damage);
   this_player()->add_mp(-50);
   this_player()->add_hp(damage);
   ob->add_hp(-damage);
   this_player()->add_alignment(-10);
   tell_object(ob,"Your life force is being sucked away by "+
                this_player()->query_cap_name()+"!");
   return 1;
}
 
void help() {
    write("Syntax: <absorb [enemy]>\n\n"
        "With this spell, you drain the strength of your enemies\n"
        "and increase your own.\n"
    );
}
