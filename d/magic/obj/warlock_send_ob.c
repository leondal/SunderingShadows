#include <std.h>
#include <langs.h>
#include <daemons.h>
#define REPLYOBJ "/d/magic/obj/warlock_reply_ob"
inherit OBJECT;

void set_receiver(object ob);
void set_teller(object ob);
void query_receiver();
void query_teller();
void finish();
object teller, receiver, myspl;

void init() {
    ::init();
    if(!userp(ETO)) return;
    add_action("send_msg","sendmessage");
    tell_object(teller,"%^BOLD%^%^WHITE%^You have one minute to <sendmessage x> to your target.\n");
    tell_object(teller,"%^BOLD%^%^WHITE%^Remember that if it exceeds 200 characters, the invocation will fail.\n");
}

int send_msg(string str) {
    object reply_ob;
    if(!objectp(TP)) return 0;
    if(!objectp(teller)) { finish(); return 0; }
    if(TP != teller) return 0;
    if(!str) {
      tell_object(teller,"You need to actually send a message!");
      return 1;
    }
    if(strlen(str) > 200){
      tell_object(teller,"Your message is too long! You can't concentrate on all the words, and the invocation dissipates uselessly!");
      finish();
      return 1;
    }
    if(!objectp(receiver)) {
      tell_object(teller,"You reach out with your mind, but realise your intended target is nowhere to be found!");
      finish();
      return 1;
    }
    str = "daemon/language_d"->translate(str, teller->query_spoken(), teller);
    tell_object(receiver,"%^BOLD%^%^RED%^A message from "+teller->QCN+" suddenly enters your mind:%^RESET%^");
    tell_object(receiver,""+str+"");
    tell_object(receiver,"%^BOLD%^%^RED%^You sense that "+teller->QCN+"'s mind is still open to you, and vulnerable to attack from afar.%^RESET%^");
    reply_ob = new(REPLYOBJ);
    reply_ob->set_receiver(teller);
    reply_ob->set_teller(receiver);
    reply_ob->move(receiver);
    tell_object(teller,"%^BOLD%^%^RED%^You tell "+receiver->QCN+":%^RESET%^");
    tell_object(teller,""+str+"");
    tell_object(teller,"%^BOLD%^%^RED%^You feel a little vulnerable as you realise your invocation has left your mind open to "+receiver->QCN+".%^RESET%^");
    finish();
    return 1;
}

void finish(){
    if(objectp(teller)) {
      while(objectp(myspl = MAGIC_D->get_spell_from_array(teller->query_property("spelled"), "warlocks call"))) {
        remove_property_value("spelled", ({myspl}));
        myspl->dest_effect();
      }
    }
    if(objectp(TO)) TO->remove();
}

void set_teller(object ob){ teller = ob; }
void set_receiver(object ob){ receiver = ob; }
void query_teller(){ return teller; }
void query_receiver(){ return receiver; }