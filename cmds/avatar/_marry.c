#include <std.h>

inherit DAEMON;

int cmd_marry(string str) {
    object ob1, ob2, ring;
    string who, whom;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

     if(!avatarp(this_player())) {
	notify_fail("You do not have the power to wed people.\n");
	return 0;
    }
    if(!str) {
         notify_fail("Syntax: marry <who> to <whom>\n"); /*Plura 930120*/
         return 0;
      }
    if(sscanf(str, "%s to %s", who, whom) != 2) return 0;
    ob1 = present(who, environment(this_player()));
    ob2 = present(whom, environment(this_player()));
    if(!ob1 || !ob2) {
	notify_fail("Both parties must be present to be wed!\n");
	return 0;
    }
    if(ob1 == ob2) {
        notify_fail("That's weird.\n");
	return 0;
    }
    if(ob1->query_married() || ob2->query_married()) {
	notify_fail("Both partied must be unwed!\n");
	return 0;
    }
   if((int)ob1->query_level() < 6 || (int)ob2->query_level() <6) return notify_fail("They are toon young to marry.\n");
    ob1->set_married(lower_case(whom));
    ob2->set_married(lower_case(who));
    ring = new("std/obj/wed_ring");
    ring->set_me(lower_case(who));
    ring->set_spouse(lower_case(whom));
    ring->move(ob1);
    ring = new("/std/obj/wed_ring");
    ring->set_me(lower_case(whom));
    ring->set_spouse(lower_case(who));
    ring->move(ob2);
    write("You pronounce "+capitalize(who)+" and "+capitalize(whom)+" united in marriage.\n");
    say(capitalize(who)+" and "+capitalize(whom)+" are now united in marriage!\n");
    return 1;
}

void help() {
    write("Syntax: <marry [who] to [whom]>\n\n");
    write("This command allows an arch to marry two people.\n");
}
