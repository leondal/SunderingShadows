#include <std.h>
#include <daemons.h>
#include <security.h>
inherit OBJECT;

#define BACKUP_DIR "/d/magic/obj/companions/"

// adding function headers to see if it helps the add_actions load properly straight away.
// Lujke December 10 2005
int callme_fun(string str);
int dismissme_fun(string str);
int releaseme_fun(string str);
// end of additions

object kritter, owner;
int flag;

void create(){
   ::create();
   set_name("summoned companion");
   set_id(({"summoned companion"}));
   set_short("");
   set_long("");
   set_weight(0);
   set_property("no animate", 1);
   set_property("no steal", 1);
   flag = 0;
}
//added the following to fix bugs with the item showing up in players' inventories at vendors ~Circe~ 7/29/19
int is_detectable() { return 0; }
int query_invis() { return 1; }

void save_me(string file){return 1;}

void init(){
   ::init();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   add_action("callme_fun","call");
   add_action("dismissme_fun","dismiss");
   add_action("releaseme_fun","release");
   add_action("help_fun","help");
   if (objectp(owner)){  // function moved and objectp check added December 10/05 by Lujke, because the 
               // following line was causing init to bug when the spell was first cast, (before owner was set)
               // which caused the add_actions not to load until the caster logged out and returned.
     if (environment(TO) != owner) { TO->move(owner); }
   }

}

void set_owner(object ob) { owner = ob; }
object query_owner(){ return owner;} // added to help with debugging Lujke December 10 2005

void set_kritter(object ob) { kritter = ob; }
object query_kritter(){ return kritter;} // added to help with debugging Lujke December 10 2005

int callme_fun(string str){
   object who;

   if (!str) {
     notify_fail("Call whom?\n");
     return 0;
   }
   if (str != "companion") {
     notify_fail("Call whom?\n");
     return 0;
   }
   if (ETO->query_bound() || EETO->query_unconscious() || EETO->query_paralyzed()) {
     ETO->send_paralyzed_message("info",ETO);
     return 0;
   }
   if (flag == 1) {
     tell_object(TP,"Your creature has already been called to this plane!");
     return 1;
   }
   if (sizeof(TP->query_attackers())) {
     notify_fail("You're too busy right now.\n");
     return 0;
   }

   tell_object(TP,"%^ORANGE%^You make a careful gesture to the air before you, and it shimmers and parts to "
"allow your companion to pass through, closing in its wake!",TP);
   tell_room(ETP,"%^ORANGE%^"+TP->QCN+" makes a gesture to the air before "+TP->QO+", and it shimmers and "
"parts to allow a creature to pass through, closing in its wake!",TP);
   kritter=new("/d/magic/obj/companion.c");
   seteuid(UID_RESTORE);
   kritter->restore_me(BACKUP_DIR+(string)TPQN+".backup.o");
   kritter->set_owner(TP);
   kritter->move(ETP);
   flag = 1;
   return 1;
}

int dismissme_fun(string str) {
   if (!str) {
     notify_fail("Dismiss what?\n");
     return 0;
   }
   if (str != "companion") {
     notify_fail("You can't dismiss that.\n");
     return 0;
   }
   if (flag == 0) {
     tell_object(TP,"Your creature isn't upon this plane, you can't dismiss it!");
     return 1;
   }
	//there are no checks to make sure kritter is still a valid
	//object - which means it is going to bug eventually :P - Saide
	if(!objectp(kritter)) 
	{
		flag = 0;
	}
   	tell_object(TP,"%^RESET%^%^ORANGE%^Your companion acknowledges "+
	"your command, and you sense it returning to its home plane!%^RESET%^");
	if(!flag) return 1;

	tell_room(environment(kritter),"%^RESET%^%^ORANGE%^The creature acknowledges "+
	"its master's command.  It shimmers and disappears into thin air!%^RESET%^",TP);
		
	kritter->move("/d/shadowgate/void");
   	kritter->remove();
   	flag = 0;
   	return 1;
}

int releaseme_fun(string str) {
   object ob;
   if (!str) {
     notify_fail("Release what?\n");
     return 0;
   }
   if (str != "companion") {
     notify_fail("You can't release that.\n");
     return 0;
   }
	if(!objectp(kritter)) 
	{
		tell_object(TP,"%^RESET%^%^ORANGE%^Your companion acknowledges "+
		"your command, and you sense it returning "
		"permanently to its home plane!%^RESET%^");	
		TP->remove_pet(TO);
		TO->move("/d/shadowgate/void");
		TO->remove();
		return 1;
	}

   	if (flag == 1) {
     tell_room(environment(kritter),"%^RESET%^%^ORANGE%^The creature acknowledges its master's command.  It "
"shimmers and disappears into thin air!%^RESET%^",TP);
     tell_object(TP,"%^RESET%^%^ORANGE%^Your companion acknowledges your command, and you sense it returning "
"permanently to its home plane!%^RESET%^");
     kritter->move("/d/shadowgate/void");
     kritter->remove();
   }
   else { tell_object(TP,"%^RESET%^%^ORANGE%^You sense your companion's acknowledgement of the command, as "
"it returns permanently to its home plane!%^RESET%^"); }
   TP->remove_pet(TO);
   TO->move("/d/shadowgate/void");
   TO->remove();
   return 1;
}

void reset_flag() { flag = 0; }
void add_flag() { flag = 1; }

int help_fun(string str) {
   int x, calc;
   int *in_mind;
   string tmp;

   if (!str) return 0;
   if (str != "companion") return 0;
   if (TP != owner) return 0;

   write("
There are several commands you can use with your summoned companion.

%^ORANGE%^<call companion>%^RESET%^                    will call it, at any time, if you have completed a summoning ritual.
%^ORANGE%^<dismiss companion>%^RESET%^                 will send it away again, to await your next calling.
%^ORANGE%^<release companion>%^RESET%^                 will permanently send the creature away.
%^ORANGE%^<alter [long|short] %^ORANGE%^%^ULINE%^DESCRIPTION%^RESET%^%^ORANGE%^%^>%^RESET%^    will allow you to alter the long or short description of your creature.
%^ORANGE%^<command companion to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^       will command the creature to follow your request.
%^ORANGE%^<lead companion>%^RESET%^                    will tell your companion to follow you.
%^ORANGE%^<unlead companion>%^RESET%^                  will tell your companion to stop following you.
%^ORANGE%^<help companion>%^RESET%^                    will give you this screen.
");


   return 1;
}
