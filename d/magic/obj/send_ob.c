#include <std.h>
#include <langs.h>
#include <daemons.h>


inherit OBJECT;

void set_receiver(object ob);
void set_teller(object ob);
void query_receiver();
void query_teller();
void finish();
object teller;
object receiver;
object myspl;

void init() {
    ::init();
    tell_object(teller,"Please type your message here:\n");
    tell_object(teller,"Remember that if it exceeds 200 characters, "+
       "the power will fail.\n");
    input_to("my_message");
}

void my_message(string str){
   teller = query_teller();
   receiver = query_receiver();
   if(!str){
      tell_object(teller,"%^BOLD%^Please type your message here.  "+
         "\nIf you wish to cancel, enter **.");
      input_to("my_message");
      return;
   }
   if(str == "**"){
      tell_object(teller,"The power fades from your mind as you "+
         "decide not to send a message.");
      finish();
      return;
   }
   if(strlen(str) > 200){
      tell_object(teller,"Your message is too long, causing the "+
         "power to drain from your mind!");
      finish();
      return;
   }
   str = "daemon/language_d"->translate(str, teller->query_spoken(), teller);
   tell_object(receiver,"%^BOLD%^%^RED%^A message from "+teller->QCN+" "+
      "suddenly enters your mind:");
   tell_object(receiver,""+str+"");
   tell_object(teller,"%^BOLD%^%^RED%^You tell "+receiver->QCN+":");
   tell_object(teller,""+str+"");
   finish();
   return;
}

void finish(){
   while(objectp(myspl = MAGIC_D->get_spell_from_array(teller->query_property("spelled"), "sending"))) {
            remove_property_value("spelled", ({myspl}));
            myspl->dest_effect();
         }
}

void set_teller(object ob){
   teller = ob;
}

void query_teller(){
   return teller;
}

void set_receiver(object ob){
  receiver = ob;
}

void query_receiver(){
  return receiver;
}