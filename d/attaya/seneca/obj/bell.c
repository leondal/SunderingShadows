#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("ring","ring");
}

void create(){
    ::create();

    set_name("bell");
    set_id(({"bell","brass bell"}));
    set_short("An enormous brass church bell");
    set_long(
      "This is a large brass church bell that is used to signal an event.  It must weigh several tons!\n %^CYAN%^COMMAND: ring bells.\n\n %^RED%^*look at the notice first.*"
    );
    set_weight(100000);
    set_value(10000);
}

int ring(string str){
    if(!str || str != "bells") return  0;

   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
    tell_room(environment(TO),TPQCN+" rings the bells!",TP);
/*
    message("broadcast", "%^BOLD%^%^GREEN%^Bells can be heard ringing out across the land.",users());
*/
    return 1;
}

