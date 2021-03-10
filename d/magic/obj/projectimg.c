#include <std.h>
#include <daemons.h>
inherit TOWNSMAN;

object current, caster;
int flag;
void vanish();

void create(){
   ::create();
   set_name("projected image");
   set_max_hp(99999);
   set_hp(99999);
   set_hd(50,12);
   set("aggressive",0);
   set_spoken("wizish");
   set_mob_magic_resistance("average");
   command("speech speak as if from a great distance");
}

void set_caster(object spellcaster) {
    caster = spellcaster;
    set_property("allowed tell",({caster->query_name()}));
    caster->set_property("allowed tell", ({query_name()}));
    caster->set("reply",query_name());
    if (!caster->query_disguised() || !wizardp(caster)) set("reply",caster->getParsableName());
    else set("reply",caster->query_vis_name());
    set("reply object",caster);
    caster->set("reply object",TO);
}

void set_target(object target) { current = target; }

void catch_say(string str){
   if(!objectp(current)) vanish();
   if(!objectp(caster)) vanish();
   if (TP == current) call_out("do_interact",1,str,TP);
}

void do_interact(string str, object player){
   int truePrice;
   string who, stuff;
   object whoO;

   if(!objectp(current)) vanish();
   if(!objectp(caster)) vanish();

   if (player == current) {
	flag = 1;
	force_me("reply "+str);
	return;
   }
}

void receive_message(string cl, string msg) {
   string misc, response;
   ::receive_message(cl,msg);
   if (cl == "reply" && !flag) {
//     if(sscanf(msg, "%s replies: %s", misc, response) == 2) force_me("say "+response);
     force_me("say "+msg);
   }
   flag = 0;
}

void end_this(){
   string * array;
   if (objectp(caster)) {
      tell_object(caster,"Your connection with the projected image has lapsed.");
      array = copy((string *)caster->query_property("allowed tell"));
      array -= ({ TO->query_true_name() });
      caster->remove_property("allowed tell");
      caster->set_property("allowed tell",array);
      caster = 0;
   }
   remove_property("allowed tell");
   current = 0;
}

string getNameAsSeen(object ob) { return TO->query_name(); }
string getParsableName() { return capitalize(TO->query_name()); }
int is_npc_psychic() { return 1;}

void vanish(){
    end_this();
    tell_object(ETO,"%^BOLD%^%^CYAN%^The illusionary image fades away.%^RESET%^");
    TO->move("/d/shadowgate/void");
    TO->remove();
}

void heart_beat() {
   ::heart_beat();
   if(sizeof(TO->query_attackers()) > 0) vanish();
}

void die(object ob) { vanish(); }