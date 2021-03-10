#include <std.h>
#include <daemons.h>

inherit NPC;
string *killers;
string *registered;

void create(){
    ::create();
   set_nwp("escape",10,500);
    killers = ({});
    set_name("selena");
    set_id(({"selena","Selena",}));
    set("short","Selena, the guild receptionist");
    set_long(
@STYX
Dark locks of curly hair peek out from behind the black mask this woman wears.  She is the receptionist for the Dagger thieves guild, and takes her job very seriously.  She looks to be well conditioned and she probably works hard to keep her body in tip top shape.  You need to have her <register> you here in order to do business and enjoy the benefits of the guild.
STYX
    );
    set_race("half-elf");
    set_gender("female");
    set_class("thief");
    set_alignment(3);
    set("aggressive", 0);
    set_hd(19,1);
    set_hp(200);
    set_exp(10);
    set_property("always interact",1);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/deku/weapons/dagger2")->move(TO);
    command("wield dagger in right hand");
    new("/d/deku/weapons/dagger2")->move(TO);
    command("wield dagger in left hand");
}

void init(){
    ::init();
    add_action("register","register");
    add_action("pay_off", "pay");
}

int register(){
	killers = SAVE_D->query_array("DDguild_killers");
	if(member_array(TPQN,killers) != -1) return notify_fail("Your crimes here have"+ " made you unwelcome!  You'll have to PAY to make ammends if you still want to"+ " try to join and it won't be cheap.\n");
	if(TP->is_class("thief") || TP->is_class("assassin")) {
	  if(TP->query_money("gold") < 9000) { 
	    command("say I'm sorry, you need 9,000 gold to join and use the healer and store.");
	    return 0;
	  }
	  TP->add_money("gold",-9000);
	  command("say %^GREEN%^Welcome to the guild.  You can now buy from"+ 
	  " the shop as well as the healer.  Both are discrete enough to not ask many"+
	  " questions about your background.");
	  environment(TO)->add_member(TPQN);
	  return 1;
	  }
	else { 
	  if(TP->query_money("gold") < 5000) { 
	    command("say I'm sorry, you need 5,000 gold to join and use the healer.");
	    return 0;
	  }
	  TP->add_money("gold",-5000);
	  command("say %^GREEN%^Welcome to the guild.  You now have access to"+
	  " the healer, who is discrete enough to not ask too many questions about"+
	  " your deeds.");
	  environment(TO)->add_member(TPQN);
	  return 1;
  }
  notify_fail("You have no need to register. You're already a member silly.\n");
}

int kill_ob(object victim, int which){
    int hold;
    killers = SAVE_D->query_array("DDguild_killers");
    hold = ::kill_ob(victim, which);
    if(member_array(TPQN, killers) != -1) return hold;
    SAVE_D->set_value("DDguild_killers", TPQN);
    registered = SAVE_D->query_array("vethor_members");
    if(member_array(TPQN, registered) != -1) {
       SAVE_D->remove_name_from_array("vethor_members", TPQN);
    }
    command("say %^BOLD%^%^RED%^You scum, this won't be forgotten!");
    return hold;
}

void remove_name(string name){
    SAVE_D->remove_name_from_array("DDguild_killers", name);
}

int pay_off() {
	killers = SAVE_D->query_array("DDguild_killers");
	if(member_array(TPQN,killers) != -1) {
	  if(TP->query_money("gold") < 10000) { 
	    command("say %^GREEN%^It'll take at least 10,000 gold to make ammends.");
	    return 0;
	  }
	  TP->add_money("gold",-10000);
	  command("say %^GREEN%^10k does nicely I suppose.");
	  command("smirk");
	  command("say %^GREEN%^Now you are eligible to register whenever you want.");
     SAVE_D->remove_name_from_array("DDguild_killers", TPQN);
	  return 1;
	}
	notify_fail("You don't need to pay to make ammends since you aren't on the list of troublemakers.\n");
}
