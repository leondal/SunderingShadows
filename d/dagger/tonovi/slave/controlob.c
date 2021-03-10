#include <std.h>

inherit OBJECT;

object sl_ob, master;

void set_master(object ob);
void set_sl_ob(object ob);
object query_sl_ob();
object query_master();

void create(){
    ::create();
    set_name("slave controller");
    set_id( ({"slavecontroller", "controlob", "Gremote"}) );
    set_long("");
    set_short("");
    set_weight(0);
    set_value(0);
    set_property("no animate", 1);
    set_heart_beat(1);
}

void init(){
    ::init();
    add_action("comm_slave", "command");
    add_action("free_slave", "free");
}

int comm_slave(string str){
    object ob;
    string who, what;

    if(!objectp(sl_ob)){
      TO->remove();
      return 1;
    }

   if(!str) return notify_fail("Command slave to <do something>\n");
    if(sscanf(str, "%s to %s", who, what) != 2)
      return notify_fail("Command slave to <do something>\n");
    if(who != "slave") return 0;

    if(what[0..3] == "kill") {
      if(sscanf(what, "kill %s",who) == 1)
        if(ob = present(who,environment(master)))
          if(objectp(ob))
            if(!master->ok_to_kill(ob))
              return notify_fail("You are not allowed to kill that creature!\n");
      "/daemon/killing_d"->check_actions(master,ob);
    }

    if(!sl_ob->force_me(what))
      tell_object(TP, "Your slave refuses to "+what+".");

    return 1;
}


int free_slave(string str){
    if(!objectp(sl_ob) || !objectp(master) ){
      TO->remove();
      return 1;
    }

    if(!str || str != "slave"){
      tell_object(TP, "free what?");
      return 1;
    }

    sl_ob->excape_master();
    TO->remove();
    return 1;
}

void set_master(object ob) { master = ob; }
void set_sl_ob(object ob) { sl_ob = ob; }
object query_master() {return master; }
object query_sl_ob() { return sl_ob; }

void heart_beat(){

    if(!objectp(master) || !objectp(sl_ob) ){
      TO->remove();
    }
}
