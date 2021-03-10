#include <std.h>
#include <langs.h>
#include <daemons.h>
inherit OBJECT;

void set_receiver(object ob);
void set_teller(object ob);
void query_receiver();
void query_teller();
void vape_me();
object teller, receiver;

void init() {
    ::init();
    if(!userp(ETO)) return;
    add_action("send_msg","sendmessage");
    add_action("retort","retort");
    tell_object(teller,"%^BOLD%^%^WHITE%^You have a minute to <retort> to send a jolt of harmful mental energy, or to <sendmessage x> to reply.\n");
    tell_object(teller,"%^BOLD%^%^WHITE%^Please note that if your response exceeds 200 characters, the invocation will fail.\n");
    call_out("vape_me",60);
}

int send_msg(string str) {
    if(!objectp(TP)) return 0;
    if(!objectp(teller)) { if(find_call_out("vape_me")) remove_call_out("vape_me"); TO->remove(); return 0; }
    if(TP != teller) return 0;
    if(!str) {
      tell_object(teller,"You need to actually send a message!");
      return 1;
    }
    if(strlen(str) > 200){
      tell_object(teller,"Your message is too long! You can't concentrate on all the words, and the invocation dissipates uselessly!");
      if(find_call_out("vape_me")) remove_call_out("vape_me");
      TO->remove();
      return 1;
    }
    if(!objectp(receiver)) {
      tell_object(teller,"You reach out with your mind, but realise your intended target is nowhere to be found!");
      if(find_call_out("vape_me")) remove_call_out("vape_me");
      TO->remove();
      return 1;
    }
    str = "daemon/language_d"->translate(str, teller->query_spoken(), teller);
    tell_object(receiver,"%^BOLD%^%^RED%^A response from "+teller->QCN+" suddenly enters your mind:");
    tell_object(receiver,""+str+"");
    tell_object(teller,"%^BOLD%^%^RED%^You tell "+receiver->QCN+":");
    tell_object(teller,""+str+"");
    if(find_call_out("vape_me")) remove_call_out("vape_me");
    TO->remove();
    return 1;
}

int retort() {
    if(!objectp(TP)) return 0;
    if(!objectp(teller)) { if(find_call_out("vape_me")) remove_call_out("vape_me"); TO->remove(); return 0; }
    if(TP != teller) return 0;
    if(!objectp(receiver)) {
      tell_object(teller,"You reach out with your mind, but realise your intended target is nowhere to be found!");
      if(find_call_out("vape_me")) remove_call_out("vape_me");
      TO->remove();
      return 1;
    }
    tell_object(teller,"%^BOLD%^%^RED%^You send a painful jolt of mental energy back at "+receiver->QCN+"!%^RESET%^");
    tell_object(receiver,"%^BOLD%^%^RED%^The only response to your message is a painful jolt of mental energy! Ouch!%^RESET%^");
    receiver->cause_typed_damage(receiver,"head",roll_dice(4,10),"mental");
    if(find_call_out("vape_me")) remove_call_out("vape_me");
    TO->remove();
    return 1;
}

void set_teller(object ob){ teller = ob; }
void set_receiver(object ob){ receiver = ob; }
void query_teller(){ return teller; }
void query_receiver(){ return receiver; }

void vape_me() {
    if(objectp(teller)) tell_object(teller,"%^BOLD%^%^WHITE%^You feel the invocation dissipate uselessly!%^RESET%^");
    TO->remove();
}