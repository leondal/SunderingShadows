//Coded by Lujke

#define TABOR "/d/darkwood/tabor/room"
#include <std.h>

inherit OBJECT; 

int disentangle(object * tangles);
int entangle(object * target, int duration);

create() {
  ::create();
  set_name("disentangler");   
                        
  set_id(({"disentangler"}));   

  set_short("disentangler");   
  set_long("A virtual object for disentangling people who have been"
          +" entangled by an entangle spell");
  set_weight(0);          
  set_value(0);         
}


int disentangle(object * tangles){
  int i;
  string property;
  if (sizeof(tangles)<1){return 0;}  
  for (i=0;i<sizeof(tangles);i++){
    if (!objectp(tangles[i])){continue;}
    tangles[i]->set_disable(0,tangles[i]);
    property = tangles[i]->query_property("working"); // Added by 
    if (interact("entangled", property)){          // Lujke
      tangles[i]->remove_property("working");
    }
  }
}

int entangle(object * target, int duration){
  int i;
  string property;
  if (sizeof(target)<1){return 0;}  
  for (i=0;i<sizeof(target);i++){
    if (!objectp(target[i])){continue;}
    target[i]->set_disable(duration,target[i]);
    property = target[i]->query_property("working"); // Added by 
    if (!interact("entangled", property)){          // Lujke
      target[i]->set_property("working","%^GREEN%^entangled%^RESET%^"
                           +"%^CYAN%^");
    }   
  }
  call_out("disentangle", duration, target);
  TO->move("/d/shadowgate/void");
}
