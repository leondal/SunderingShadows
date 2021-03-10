#include <std.h> 
#include "../defs.h" 
inherit INH+"spiderarches"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"  %^BOLD%^%^BLUE%^A massive %^BLACK%^iron door %^BLUE%^stands here, "
"barring your travel further east, but a great pile of stones and rubble obscure half of it from view, making "
"it impossible to reach or open.\n%^RESET%^"); 

   set_exits(([ 
"southwest":UPPER"tunnel33",
//"east":UPPER"tunnel41",
   ])); 
}


/*  set_door("iron door",UPPER"tunnel41","east");
  set_door_description("iron door", "%^BOLD%^%^BLACK%^A massive door bars further passage to "
"the east.  Thick and heavy, it has sturdy hinges that seem undamaged despite their apparent "
"age.%^RESET%^");
  add_lock("iron door","hasnokey","lock","%^BLUE%^This lock runs on many bolts and levers "
"inside the door.  It would probably be quite difficult to crack without the appropriate key.%^RESET%^");
  lock_difficulty("iron door",-40,"lock");
  set_locked("iron door",1,"lock");
  UPPER"tunnel41"->set_locked("iron door",1,"lock");

  set_trap_functions( ({  "iron door", }), ({ "lock_traps", }), ({ "pick", }) );
}

int lock_traps(string str){
    tell_object(TP,"%^BLUE%^As you work the lock, something clicks... and a sudden fierce pain erupts along "
"your hand!  Horrific %^BOLD%^%^RED%^serrated %^RESET%^%^BLUE%^edges, not originally apparent around the lock"
", slash outwards to all but flense the skin from your fingers!%^RESET%^");
    TP->do_damage("torso",roll_dice(10,8));
    TP->force_me("emote stifles an oath of pain and pulls back "+TP->QP+" hand from the door's lock.");
    return 1;
}*/