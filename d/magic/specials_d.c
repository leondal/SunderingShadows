//specials_d.c

#include <std.h>

#define TARGNAME (string)targ->getParsableName()
#define PONAME (string)PO->getParsableName()

inherit DAEMON;

void create(){
   ::create();
}

int wolfjaws(object targ)
{

   if(!objectp(targ)) return random(3);

   tell_object(PO, "%^RED%^You rip the flesh of your foe with the monstrous wolf jaws that now replace your hands.");
   tell_room(environment(PO),"%^RED%^"+PONAME+" rips chunks of flesh from "+TARGNAME+" with the wolf jaws.",({PO,targ}));
   tell_object(targ,"%^RED%^"+PONAME+" ferociously rips flesh from your body with the wolf jaws.");
   return 1;
}

int blacktalon(object targ){
   if(!objectp(targ)) return random(3);

 tell_object(PO, "%^BLUE%^You rake the dangerous claw through the flesh of your opponent.");
   tell_room(environment(PO),"%^BLUE%^"+PONAME+" rakes the claw along "+TARGNAME+"'s body and limbs.",({PO,targ}));
 tell_object(targ,"%^BLUE%^"+PONAME+" rakes the claws along your body.");
 return random(4)+1;

}

int beastclaws(object targ){
   if(!objectp(targ)) return random(3);

 tell_object(PO, "%^GREEN%^You rake the dangerous claws through the flesh of your opponent.");
   tell_room(environment(PO),"%^GREEN%^"+PONAME+" rakes the claws along "+TARGNAME+"'s body and limbs.",({PO,targ}));
 tell_object(targ,"%^GREEN%^"+PONAME+" rakes the claws along your body.");
 return random(4)+1;

}



int wheelBones(object targ){
   int i,j;
   if(random(4)) return 1;

   targ = PO->query_current_attacker();
   if(!objectp(targ)) return random(4);
   tell_room(environment(targ),"%^BOLD%^%^CYAN%^A missile like shard of bone shoots out from the spinning wheel and cuts into "+TARGNAME+".",targ);
   tell_object(targ,"%^BOLD%^%^CYAN%^A missile made of bone flies out of the spinning wheel and strikes you.");
   j = random(3) + 1;
   for(i=0;i<j;i++)
      targ->do_damage("blah",random(4)+1);
   return 1;
}

int stonefists(object targ) {
    if(!objectp(targ)) return random(7);
    
    tell_object(PO,"%^BOLD%^%^WHITE%^You slam your fist of "+
    "stone into "+TARGNAME+" with a loud %^RED%^THUD!%^RESET%^");
    
    tell_room(environment(PO),PONAME+"%^BOLD%^%^WHITE%^'s fist "+
    "of stone slam into "+TARGNAME+" with a loud "+
    "%^RED%^THUD!%^RESET%^",({targ,PO}));

    tell_object(targ,"%^BOLD%^%^WHITE%^The stone chunks slam into "+
    "your body with a loud %^YELLOW%^THUD!%^RESET%^");
    return 1 + random(7);
}


int touchsickle(object targ){

   if(!objectp(targ)) return random(4);

   tell_room(environment(PO),"%^GREEN%^The wooden sickles cut deeply into "+TARGNAME+".",targ);
   tell_object(targ,"%^GREEN%^The sickles cut deeply into you.");
   return random(7);
}

int flameform(object targ){
    if(!objectp(targ)) return random(8);
    tell_object(targ,"%^RED%^The flames burn you.");
    return 1 + random(8);
}
