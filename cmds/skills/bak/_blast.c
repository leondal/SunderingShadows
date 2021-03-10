//   /bin/user/_blast.c
//   from the Nightmare mudlib
//   A very powerful destruction spell
//   Created by Forlock on some strange date system that Descartes loves.
//   930417 17 april 1993 stardate 46835.9 170493

#include <std.h>

inherit DAEMON;

int cmd_blast (string str) {
    int mag, points, final, ran, temps;
    object ob;

    this_player()->set_magic_round();
   if(!str) {
      ob = (object)this_player()->query_current_attacker();
      if(!ob) {
         notify_fail("Blast what?\n");
         return 0;
      }
   }
   else ob = present(str, environment(this_player()));
   if(!ob) ob = parse_objects(environment(this_player()), str);
    if(!ob || !living(ob)) {
        notify_fail("No "+str+" here.\n");
        return 0;
   }
   if(environment(this_player())->query_property("no magic")) {
      notify_fail("A magic force prevents your spell.\n");
      return 0;
   }
    if((mag = (int)this_player()->query_skill("magic attack")) < 30) {
      notify_fail("You are not skilled enough for this spell.\n");
      return 0;
   }
    if((points = (int)this_player()->query_mp()) <50) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
   if(this_player()->query_ghost()) {
      notify_fail("Your voice is hollow.\n");
      return 0;
   }
   if(this_player()->query_casting()) return 1;
   if(!ob->kill_ob(this_player(),0)) return 1;
   if(ob->query_property("no blast")) {
     notify_fail(sprintf("%s is immune to your magic!\n",
		 ob->query_cap_name()));
     return 0;
   }
   if(environment(this_player())->query_property("no attack")) {
      notify_fail("A magic force prevents you from casting your spell.\n");
      return 0;
   }
   write("%^BLUE%^%^BOLD%^You summon up the forces of your life "
	 "energy and blast them "
	 "at your opponent!\n%^RESET%^You feel drained, and cannot move.");
    points = (int)this_player()->query_mp();
    points += mag - ((int)ob->query_stats("wisdom"))*5;
    if(points < 0) points = 1;
    temps = random(200-mag)/10;
    if(temps <7) temps =7;
    this_player()->set_paralyzed(temps);
    this_player()->add_skill_points("magic attack", temps);
    this_player()->add_mp(-((int)this_player()->query_mp()));
    if(!(ran = random(4))) write("Your magic powers fail!");
    final = points * ran;
    this_player()->set_casting(final);
   tell_room(environment(this_player()), "%^BLUE%^%^BOLD%^"+
	     this_player()->query_cap_name()+" throws the energy of "
	     "the universe at "+(string)ob->query_cap_name()+"!",
	     ({ ob, this_player()}));
   tell_object(ob, "%^BLUE%^%^BOLD%^"+this_player()->query_cap_name()+
	       " throws the energy of the universe at you.");
   return 1;
}

void help() {
   write("Syntax: <blast [(living)]>\n\n"
      "Throws the collective energy of the universe at the living "
      "object named.  Doing this takes a great deal of energy, "
      "and will leave you temporarily immobile until the affects "
      "ware off.  This spell takes all of your magic points to cast.\n");
}

