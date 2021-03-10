
//
#include <std.h>
#include <daemons.h>
#define RED "%^BOLD%^%^RED%^"+

inherit DAEMON;

int do_live(object corpse);

int help(){
    write(
@OLI
%^CYAN%^NAME%^RESET%^

skin - gather biomass

%^CYAN%^SYNOPSIS%^RESET%^

skin %^ORANGE%^CORPSE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

With this command you skin a %^ORANGE%^CORPSE%^RESET%^. The skinning process will be based on your skill in %^BOLD%^survival%^RESET%^. The larger the corpse and the more difficult the creature the harder the skinning. As skill increases, the time to skin will decrease, and you will get better quality results.

%^CYAN%^SEE ALSO%^RESET%^

hunt, kill, craft, survival
OLI
    );
    return 1;

}


int cmd_skin(string str){
    string what;
    object corpse, env;
    object skin;
    int prof;

    if (!str) {
        return help();
    }
  if (TP->query_hidden()) {
    if (objectp(what=present("TSR80",TP))) {
    what->force_cancel();
    }
  what = 0;
  }
  if (TP->query_magic_hidden()) {
    return notify_fail("You can't see to work!\n");
  }
//added checks for hidden after bug reports.  Circe 11/21/04
//none of the craft NWPs allow you to work while hidden, so
//it only made sense that you couldn't use a knife to skin
//while hidden
    if (TP->query_property("working")) {
        return notify_fail("You are already "+(string)TP->query_property("working")+".\n");
    }

    if (sizeof(TP->query_attackers())) {
        return notify_fail("You can't skin a beast while killing another.\n");
    }
    if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() ||TP->query_tripped()) {
        TP->send_paralyzed_message("info",TP);
        return 0;
     }

    corpse = present(str, ETP);
    if (!objectp(corpse)) {
        return notify_fail("No such object to skin.\n");
    }
    if (!corpse->is_corpse()) {
        if (living(corpse)) {
            return do_live(corpse);
        } else {
            return notify_fail("You can't skin that.\n");
        }
    }
    if ((int)corpse->query_skinned() == -1) {
        return notify_fail("That corpse has already been skinned.\n");
    }
    if(corpse->query_property("skinnedby")){
       return notify_fail("That corpse is already a bloody mess!  "+
          "No way can you get a usable skin off that!\n");
    }
    corpse->set_property("skinnedby",TPQN);
    skin = new ("/std/obj/skin");
    skin->copy_corpse(corpse);
    skin->set_no_clean(1);
    env = ETP;
    prof = TP->query_skill("survival")+roll_dice(1,20);
    TP->set_property("working","skinning");
   write(RED"You sit down to the bloody and grisly job of skinning the "+corpse->query_name()+".");
   tell_room(env,RED TPQCN+" sits down to the bloody and grisly job of skinning the "+corpse->query_name()+".",TP);
    write(RED"You insert your knife carefully and start to work the skin away from the layers of muscle and fat.");
    tell_room(env,RED TPQCN+" inserts "+TP->query_possessive()+" knife into the corpse and starts to work on the skin.",TP);
    tell_room(env, RED"A pool of blood starts to form on the ground.");
    call_out("skinning",4,TP,skin,corpse,env,prof);
    return 1;
}


void skinning(object tp,object skin,object corpse, object env, int prof){
    int stuff;
    if (env != environment(tp)) {
        skin->remove();
        tp->remove_property("working");
        tell_object(tp,"You moved and stopped skinning the corpse when you left.");
        return;
    }

    if (sizeof(TP->query_attackers())) {
        skin->remove();
        tp->remove_property("working");
        return tell_object(tp,"You can't skin a beast while killing another.");
    }    if(tp->query_bound() || tp->query_unconcious() || tp->query_paralyzed() ||tp->query_tripped()) {
         skin->remove();
         tp->remove_property("working");
        tp->send_paralyzed_message("info",TP);
        return 0;
    }
    if (!objectp(corpse) || (!present(corpse, tp) && !present(corpse,environment(tp)))) {
        skin->remove();
        tp->remove_property("working");
        tell_object(tp,"The corpse is just gone.");
        return;
    }
    stuff = skin->check_progress(prof, corpse);
    if (stuff==-1) {
        tp->remove_property("working");
        tp->force_me("sigh");
        tp->force_me("emote throws the finished skin to the ground in a bloody pile.");
        skin->move(env);
        skin->set_no_clean(0);
        return;
    }
    if (!stuff) {
        tell_object(tp,RED"You work carefully and with skill, separating the skin from the bloody mess underneath.");
        tell_room(env,RED tp->query_cap_name()+" works carefully and with skill, separating the skin from the bloody mess underneath.",tp);
        call_out("skinning",5,tp,skin,corpse,env,prof);
        return;
    }
    tell_object(tp,RED"You work carefully, but soon you realize you're leaving holes and damage as you go along.");
    tell_room(env,RED tp->query_cap_name()+" works carefully but seems to be stuck and tearing the skin more than not.",tp);
    call_out("skinning",5,tp,skin,corpse,env,prof);
    return;

}
