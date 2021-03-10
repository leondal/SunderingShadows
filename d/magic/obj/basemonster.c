// Slight alterations made to account for multiple pets in a room. Nienne, 12/04 //
#include <std.h>
#include <security.h>
inherit WEAPONLESS;

#define BACKUP_DIR "/d/magic/obj/companions/"
string longdesc;
object owner;

create() {
   ::create();
   set_name("companion");
   set_id(({"companion"}));
   set_short("a summoned companion");
   set_long("This is a generic companion for mage summoning.%^RESET%^");
   set_race("companion");
   set_gender("male");
   set_body_type("quadruped");
   set_alignment(5);
   set_size(1);
   set_exp(0);
   set_base_damage_type("slashing");
   set_damage(1,4);
   set_hd(5,10);
   set_class("fighter");
   set_max_hp(100);
   set_hp(100);
   set_property("no dominate", 1);
   set_overall_ac(0);
   set_stats("intelligence",2);
   set_stats("wisdom",2);
   set_stats("strength",2);
   set_stats("charisma",2);
   set_stats("dexterity",2);
   set_stats("constitution",2);
   set_heart_beat(1);
}

void init() {
   ::init();
   add_action("mydesc","setdesc");
   add_action("alter_fun","alter");
   add_action("command_fun","command");
   add_action("lead_fun","lead");
   add_action("unlead_fun","unlead");
   add_action("help_fun","help");
}

void set_owner(object ob) {
   owner = ob;
}

string query_owner() {
   return owner;
}

int alter_fun(string str) {
   string which, alt;
   if (TP != owner) return 0;
   if (!str) {
     notify_fail("Alter what?\n");
     return 0;
   }
   if (sscanf(str,"long %s",alt) != 1 && sscanf(str,"short %s",alt) != 1) {
     tell_object(TP,"To alter your creature, use %^YELLOW%^<alter short +description>%^RESET%^, or %^YELLOW%^<alter long +description>%^RESET%^.");
     return 0;
   }
   if (sscanf(str,"short %s",alt) == 1 ) {
     TO->set_short(alt);
     if(!longdesc) TO->set_long("This is a "+TO->query_gender()+" "+TO->query_race()+".  It looks like a "
"normal creature, except for an occasional shimmering around it, like a strange hint of a magical aura.");
     else TO->set_long(alt+" "+longdesc);
     tell_object(TP,"%^WHITE%^%^BOLD%^Your companion's short description will now appear as:%^RESET%^ "
+alt+"");
     seteuid(UID_RESTORE);
     save_object(BACKUP_DIR+(string)TPQN+".backup");
     return 1;
   }
   TO->set_long(TO->query_short()+" "+alt);
   tell_object(TP,"%^WHITE%^%^BOLD%^Your companion's long description will now appear as:%^RESET%^ "
+TO->query_short()+" "+alt+"");
   longdesc = alt;
   seteuid(UID_RESTORE);
   save_object(BACKUP_DIR+(string)TPQN+".backup");
   return 1;

}

int command_fun(string str) {
   object ob;
   string what, who;
	
   if (TP != owner) return 0;
   if(!str) {
     notify_fail("Command what?\n");
     return 0;
   }
   if(sscanf(str, "%s to %s", who, what) != 2) {
     notify_fail("Syntax: command companion to <jump up and down>\n");
     return 0;
   }
   if(who != "companion") {
     notify_fail("You can only command your own companion to do actions.\n");
     return 0;
   }
   if(what[0..3] == "kill") {
     if(sscanf(what, "kill %s",who) == 1)
     if(ob = present(who,environment(TP)))
     if(TP->ok_to_kill(ob))
     return notify_fail("You are not allowed to kill that creature!\n");
   }

   if(what[0..3] == "wear") {
     notify_fail("Your companion cannot wear anything.\n");
     return 0;
   }
//I changed the wield and say #'s to make them work.
//Circe 12/8/04
//   if(what[0..3] == "wield") {
   if(what[0..4] == "wield") {
     notify_fail("Your companion cannot wield anything.\n");
     return 0;
   }
//   if(what[0..3] == "say") {
   if(what[0..2] == "say") {
     notify_fail("Your companion cannot speak.\n");
     return 0;
   }
   if(what[0..3] == "tell") {
     notify_fail("Your companion is not telepathic!\n");
     return 0;
   }
   if(what[0..3] == "yell") {
     notify_fail("Your companion cannot speak.\n");
     return 0;
   }
   if(what[0..4] == "shout") {
     notify_fail("Your companion cannot speak.\n");
     return 0;
   }
   if(what[0..6] == "whisper") {
     notify_fail("Your companion cannot speak.\n");
     return 0;
   }
   if(what[0..3] == "bind") {
     notify_fail("Your companion cannot tie anything up.\n");
     return 0;
   }
   if(!TO->force_me(what)) {
     notify_fail("You fail to command your companion to "+what+"!\n");
     return 0;
   }
   return 1;
}

int lead_fun(string str){
   if (TP != owner) return 0;
   if (!str) {
     notify_fail("Lead what?\n");
     return 0;
   }
   if (!present(str,ETP)) {
     notify_fail("There is no "+str+" here.\n");
     return 0;
   }
   TP->add_follower(TO);
   tell_object(TP,"Your companion is now following you.");
   return 1;
}

int unlead_fun(string str){
   if (TP != owner) return 0;
   if (!str || !id(str)) return 0;
   if (member_array(TO,TP->query_followers()) == -1) {
      notify_fail("Your companion is not following you at the moment.\n");
      return 0;
   }
   TP->remove_follower(TO);
   tell_object(TP,"Your companion will no longer follow you.");
   return 1;
}

int help_fun(string str) {
   int x, calc;
   int *in_mind;
   string tmp;

   if (!str) return 0;
   if (str != (string)TO->query_name() && str != "companion") return 0;
   if (TP != owner) return 0;

   tell_object(TP,"There are several commands you can use with your summoned companion.\n");
   tell_object(TP,"%^YELLOW%^<call companion>%^RESET%^ will call it, at any time, if you have completed a "
"summoning ritual.");
   tell_object(TP,"%^YELLOW%^<dismiss companion>%^RESET%^ will send it away again, to await your next "
"calling.");
   tell_object(TP,"%^YELLOW%^<release companion>%^RESET%^ will permanently send the creature away.");
   tell_object(TP,"%^YELLOW%^<alter long/short +description>%^RESET%^ will allow you to alter the long or "
"short description of your creature.");
   tell_object(TP,"%^YELLOW%^<command companion to 'action'>%^RESET%^ will command the creature to follow "
"your request.");
   tell_object(TP,"%^YELLOW%^<lead companion>%^RESET%^ will tell your companion to follow you.");
   tell_object(TP,"%^YELLOW%^<unlead companion>%^RESET%^ will tell your companion to stop following you.");
   tell_object(TP, "%^YELLOW%^<help companion>%^RESET%^ will give you this screen.\n");
   return 1;
}

void heart_beat() {
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if(!objectp(owner)) {
     tell_room(ETO,"%^ORANGE%^The creature shimmers and disappears!%^RESET%^");
     TO->move("/d/shadowgate/void.c");
     TO->remove();
   }
}

void die(object ob) {
   string file;
   if(ob = present("summoned companion",owner)) {
     tell_object(owner,"%^ORANGE%^You feel a shudder run through you, as your companion breathes its last."
"%^RESET%^");
     owner->remove_pet(ob);
     ob->move("/d/shadowgate/void");
     ob->remove();
   }
   :: die(TO);
}

void do_backup() {
   seteuid(UID_RESTORE);
   save_object(BACKUP_DIR+owner->query_name()+".backup");
}
