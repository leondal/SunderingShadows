//Coded by Lujke


#include <std.h>
#include "/d/attaya/tunnels/tunnel.h"
inherit OBJECT;
void summon_devil();

void create() {
    ::create();
    set_name("Hell gate");
    set_id( ({"hellgate","gate","hell gate"}) );
    set_short("%^BOLD%^%^RED%^Gate to %^RESET%^%^MAGENTA%^H%^YELLOW%^e"
             +"%^RESET%^%^MAGENTA%^ll%^RESET%^");
    set_weight(2000000);
    set_long("%^BOLD%^%^RED%^A gaping %^BOLD%^%^BLACK%^hole%^RED%^ has"
            +" been %^RESET%^%^MAGENTA%^rent%^BOLD%^%^RED%^ in the fabric"
            +" of space. Ringed with %^RESET%^%^RED%^f%^YELLOW%^i"
            +"%^RESET%^%^RED%^r%^BOLD%^%^RED%^e, the hole is about six"
            +" feet across and hangs two feet in the air. Looking through"
            +" you can see into the fiery pits of %^RESET%^%^MAGENTA%^H"
            +"%^RED%^e%^MAGENTA%^ll, %^BOLD%^%^RED%^although you can't"
            +" get close enough to apprach as the whole thing blasts"
            +" devastating heat into the room.");
    call_out("summon_devils", 2+random(3));
    call_out("dest_effect", 20);
}

summon_devils(){
  int i,num_devils, type;
  string message, devil;
  if(!objectp(TO)||!objectp(ETO)){return;}
  type = random(21);
  switch(type){
  case 0..5:
    num_devils = 1+ random(3);
    devil = "%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^vilk"
           +"%^RED%^i%^BOLD%^%^BLACK%^n";
    for (i=0;i<num_devils;i++){
      new (MOB+"devilkin")->move(ETO);
    }
    break;
  case 6..12:    
    num_devils = 1+ random(1);
    devil = "fierce %^BOLD%^%^GREEN%^b%^RESET%^%^GREEN%^a%^BOLD%^"
            +"%^GREEN%^rb%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^zu%^BOLD%^"
            +"%^RED%^ devil";
    for (i=0;i<num_devils;i++){
      new (MOB+"barbazu")->move(ETO);
    }
    break;
  case 13..17:    
    num_devils = 1;
    devil = "fierce %^BOLD%^%^GREEN%^b%^RESET%^%^GREEN%^a%^BOLD%^"
            +"%^GREEN%^rb%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^zu%^BOLD%^"
            +"%^RED%^ devil";
    new (MOB+"barbazu")->move(ETO);
    break;
  case 18..19:    
    num_devils = 1;
    devil = "malevolant %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^BLACK%^ck"
           +" d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v%^RED%^i%^BOLD%^"
           +"%^BLACK%^l";
    new (MOB+"rockdevil")->move(ETO);
    break;
  case 20:    
    num_devils = 1;
    devil = "pit fiend";
    new (MOB+"pitfiend")->move(ETO);
    break;
  }
  switch(num_devils){
    case 1:
      message = "A " + devil + " %^BOLD%^%^RED%^strides in through the " 
              + query_short()  + "%^BOLD%^%^RED%^!";
      break;
    case 2:
      message = "Two " + devil + "s %^BOLD%^%^RED%^ stride in through"
               +" the " + query_short() + "%^BOLD%^%^RED%^!";
      break;
    case 3:
      message = "Three " + devil + "s %^BOLD%^%^RED%^ arrive through"
               +" the " + query_short() + "%^BOLD%^%^RED%^!";
      break;
  }  
  tell_room(ETO, message, TO);
}
