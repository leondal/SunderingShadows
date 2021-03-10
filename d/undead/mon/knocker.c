#include <std.h>
#include "../undead.h"

inherit CREATURE;

int step;
string time;
void reply_snarl(string str, object ob);
void reply_yell(string str,object ob);
void reply_ask(string str, object ob);

void create() 
{
   ::create();
   set_name("knocker");
   set_id(({"knocker"}));
   set_short("%^CYAN%^Knocker");
   set_long("The knocker is just a simple gate knocker with a large metal ring in his mouth "
       "and eyes that seem to dart about.");
   set_race("knocker");
   set_gender("male");
   set_body_type("human");
   set_size(1);
   set_alignment(5);
   set_hd(20,20);
   set_max_hp(50000);
   set_hp(50000);
   set_overall_ac(2);
   set_class("fighter");
   set_exp(1);
}

void init() 
{
   ::init();
   add_action("kill","kill");
   call_out("start_grumble",5,TP);
   step = 0;
}

int kill(string str) 
{
   object ob;

   if(str != "knocker") return 0;
   reply_snarl("You try to attack me?!",ob);
   reply_yell("%^BOLD%^%^RED%^Minions come to my aid!!!",ob);
   tell_room(environment(this_object()),"%^BLUE%^The Knocker begins to scream loudly.");
   ob = new(MON"gargoyle.c");  // was OBJ and bugging because it's in MON *Styx* 1/1/03
   ob->move(ETO);
   ob = new(MON"gargoyle.c");
   ob->move(ETO);
   return 1;
}

void start_grumble(object ob) 
{
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    if(!objectp(ob)) { return; }
   time = "daemon/events_d"->query_time_of_day();
   if(time == "day") 
   {
      reply_snarl("I wish the master would just kill you all already! My mouth is "
          "starting to hurt from all of you idiots knocking on it!",ob);
      call_out("start_exam",1,ob);
      return 1;
   }
   else 
   {
      reply_snarl("You buffoons! Don't you ever sleep? I hope you get put to a slow "
          "painful death at the hands of the Master.",ob);
      tell_room(ETO,"The Knocker opens his eyes wearily and looks "+ob->QCN+" over closely.",ob);
      tell_object(ob,"The Knocker opens his eyes wearily and looks you over closely.");
      call_out("start_exam",5,ob);
      return 1;
   }
}

void start_exam(object ob, object obj) 
{
   if(((int)(ob->query_highest_level()) > 14)) 
   {
      reply_snarl("Before I allow you to enter you must answer a riddle.",ob);
      reply_ask("What has no lid, top, or chest, and contains a golden treasure?",ob);
      add_action("say_stuff","say");
      step=1;
      return 1;
   }
   else 
   {
      reply_snarl("%^BLUE%^You are not even a worthy kill for my Master! Leave Now!",ob);
      tell_room(ETO,"The Knocker goes back about its business, whatever that may be.",TO);
      if(!TO->remove());
      return 1;
   }
}

int say_stuff(string str) 
{
   if((strsrch(str,"egg") != -1) && (step == 1)) 
   {
      tell_room(ETO,"The Knocker relinquishes control of the gates and you can hear "
          "the gate unlocking.");
      ETO->set_locked("gate",0,"lock");
      tell_room(environment(this_object()),"The Knocker goes back to doing whatever it was "
          "he was doing.");
      TO->remove();
      return 1;
   }
   else 
   {
      reply_snarl("You have answered...incorrectly...for that you shall perish.",TP);
      TP->move_player(OBJ"death.c");
      tell_room(ETO,"The Knocker seems very satisfied with himself as he goes back "
          "about his business.");
      TO->remove();
      return 1;
   }
}

void reply_snarl(string str, object ob) 
{
   tell_object(ob,"%^RED%^The Knocker smiles wickedly: %^RESET%^"+str);
   return;
}

void reply_yell(string str, object ob) 
{
   tell_object(ob,"%^RED%^The Knocker hisses: %^RESET%^"+str);
   return;
}

void reply_ask(string str, object ob) 
{
   tell_object(ob,"%^RED%^The Knocker asks politely: %^RESET%^"+str);
   return;
}
