//  _glance.c
//  modified from the _look.c
//  by obsidian@ShadowGate 230799
//  added glance for room to show all you see in brief mode *Styx*  12/24/02

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int examine_object(string str);
int examine_room();
void look_msg(object ob, string str);

int cmd_glance(string str) {
   string tmp,name,num;
   set_property("information",1);

   if(TP->query_blind()) {
      write("You are blind and cannot see anything.");
      return 1;
   }

   if(!str || str == "") {
//      return examine_room();   changed to return the short instead
     TP->describe_current_room(0);
     if(!TP->query_invis())
        tell_room(ETP, TPQCN+" glances around the room.", TP);
      return 1;
   }
   if( stringp(str) ) {
      if(sscanf(str,"at %s",tmp) == 1){
         if((sscanf(tmp,"%s %d",name,num) == 2 && name == "player") || tmp == "player")
            return notify_fail("You do not notice that here.\n");
         return examine_object(tmp);
      }
      else {
         if((sscanf(str,"%s %d",name,num) == 2 && name == "player") || str == "player")
            return notify_fail("You do not notice that here.\n");
         return examine_object(str);
      }
   }
   return 1;
}

int examine_object(string str) {
   object wiz,ob;
   int i;
   if(!str) return 0;
   ob = environment(this_player());
   if(!wizardp(TP)&&(wiz=present(str,ob))&&wizardp(wiz)&&wiz->query_invis())
      return notify_fail("You do not notice that here.\n");
//   if( TP->light_blind(1)) {
//changing this to match _look to hopefully stop bug reports that you
//can see something when it's too dark to glance at it
//Circe 12/5/04
    if(TP->light_blind(0))  {
      write(TP->light_blind_fail_message(TP->light_blind(1)));
      return 1;
   }
   if(total_light(TP) < 1) write("It is dark.");
   ob = present(str, ob);
   if(ob) {
       if((ob->query_hidden() ||
           (ob->query_magic_hidden() &&
            !TP->detecting_invis()) &&
           ob != TP))
           return notify_fail("You do not notice that here.\n");
       if(!living(ob)) return notify_fail("That is not a living thing.\n");
       look_msg(ob,str);
       if(TP->query_ansi())
           write(ansi_str( (string)ob->query_desc(str) ));
       else
           write((string)ob->query_desc(str));
       return 1;
   }
   write("You do not notice that here.");
   return 1;
}

int examine_room(){
    object *all;
    int i;
    string blah;

    blah = "";
    all = all_living(ETP);


    if( (effective_light(TP) + TP->query_sight_bonus()) < 1 ) {
      write("It is too dark.");
      return 1;
    }

    if(total_light(TP) < 1) write("It is dark.");
    for(i=0;i<sizeof(all);i++){
        if(all[i]->query_invis() || all[i] == TP)
            continue;
        if(!interactive(all[i]))
            continue;

        if(TP->isKnown(all[i]->query_name()))
            blah += all[i]->query_cap_name()+" the "+all[i]->query_gender()+" "+all[i]->query_race()+"\n";
        else blah += all[i]->query_short()+"\n";
    }
    if(blah == "")
        blah = "You see nobody else here.";

    tell_object(TP, blah);
    if(!TP->query_invis())
        tell_room(ETP, TPQCN+" glances around the room.", ({TP}) );
    return 1;
}

void look_msg(object ob, string str) {
   if((int)TP->query_invis()) return;
   if( ob != TP ) {
/*
      tell_room(ETP,TPQCN+" takes a quick glance at "+ob->query_cap_name()+
         ".",({ob,TP}));
      tell_object(ob,TPQCN+" takes a quick glance at you.");
*/
   }
}

int help() {
   write("
%^CYAN%^NAME%^RESET%^

glance - glance at something

%^CYAN%^SYNOPSIS%^RESET%^

glance [%^ORANGE%^%^ULINE%^TARGET%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

This command allows you to take a brief look over a living or this room without knowing the being's inventory or room's long description.

%^CYAN%^SEE ALSO%^RESET%^

look, spy, describe, brief
"
       );
   return 1;
}
