#include <std.h>
#include "../piratedefs.h"
inherit "/std/weapon";

int charges;
int venom;
int price;
int poisonstr;
int wielder;

create(){
    ::create();
    set_id(({"venom","dagger of venom","dagger"}));
    set_name("%^RESET%^%^GREEN%^Dagger of Venom%^RESET%^");
    set_short("%^RESET%^%^GREEN%^Dagger of Venom%^RESET%^");
   set_obvious_short("A dagger");
    set_long(
@FIZIE
    %^BOLD%^%^GREEN%^
    This dagger is end heavy as if there is some liquid in the hilt. 
     Its blade seems to have channels running along it. There is a 
    recessed button along the base of the hilt.  This dagger is a
    work of art. 
FIZIE
    );
    set_wc(1,4);
    set_large_wc(1,4);
    set_weight(3);
    set_size(1);
set_value(500);
    set_type("piercing");
    set_wield((:TO,"wield_func":));
   set_unwield((:TO,"removeme":));
    set_hit((: TO,"extra_hit" :));
    set_prof_type("venomdagger");
set_property("enchantment",2);
    charges=5;
}
void init(){
::init();
add_action("press","press");
add_action("inspect","inspect");
add_action("refill","refill");
}

int wield_func(string str){
   if(TP->query_lowest_level()>=20){
tell_object(TP,"%^BOLD%^%^GREEN%^You wrap you hand knowingly around the hilt of the evil dagger.%^RESET%^");
tell_room(environment(TP),"%^GREEN%^"+TPQCN+" wields an exquisite looking "+
"dagger.%^RESET%^",TP);
   ETO->set_property("evil item",1);
return 1;
}else{
write("You are not experienced enough to wield that!");
return 0;
}
}

int removeme() {
   ETO->set_property("evil item",-1);
   return 1;
}

int press(string str){
if(!str) return notify_fail("Press what?\n");
if(str != "button") return 0;
if(venom==1) return notify_fail("But the dagger is already envenomed!\n");
wielder=TP->query_alignment();
if(wielder==1) return notify_fail("You would never commit such an abhorent act.\n");
if(wielder==4) return notify_fail("You conscience would never allow you to do that.\n");
if(wielder==7) return notify_fail("It's tempting, but that would make you just like the evil masses, now wouldn't it?\n");
if(charges==0){
notify_fail("The venom cartridge is empty!\n");
}else{
tell_object(TP,"You press the button and a %^GREEN%^vile green liquid%^RESET%^ fills the blade's channels.");
tell_room(environment(TP),""+TPQCN+" fiddles with a dagger.",TP);
poisonstr=(roll_dice(1,5));
charges=charges-1;
venom=1;
TP->set_paralyzed(2,"%^BOLD%^%^GREEN%^You are still activating the dagger.%^RESET%^");
return 1;
}
}

int inspect(string str){
if(!str) return notify_fail("Inspect what?\n");
if(str !="dagger") return notify_fail("You can't inspect that!\n");
if(venom==1){ write("The channels on the blade are filled with %^GREEN%^vile green venom%^RESET%^!");
return 1;
}else{
write("The channels on the blade are empty.");
return 1;
}
}

int refill(string str){
object ob;
if (!str) return notify_fail("Refill what?\n");
  if(!(ob = present(str,TP)) || ob != TO) return 0;
if(charges==5) return notify_fail("Your Dagger of Venom is already full.\n");
ob=present("container of venom",TP);
if (ob){
tell_object(TP,"You refill the hilt of the dagger with %^GREEN%^venom%^RESET%^.");
tell_room(environment(TP),""+TPQCN+" fills the hilt of a dagger with a %^GREEN%^foul smelling liquid.%^RESET%^",TP);
if(charges<=3){
charges=charges+2;
ob->remove();
}else{
charges=charges+1;
ob->remove();
tell_object(TP,"You overfill the dagger spilling %^GREEN%^venom%^RESET%^ all over the place!");
tell_room(environment(TP),""+TPQCN+ " overfills a dagger spilling a%^GREEN%^vile green liquid%^RESET%^ all over the place!",TP);
}
return 1;
}else{
return notify_fail("You need a container of venom to do that.");
}
}

int extra_hit(object victem){
    if(!objectp(victem)) return random(10);
    if(venom==1){
          tell_object(ETO,"%^GREEN%^Your envenomed blade unleashes its deadly wrath on "+victem->query_cap_name()+"!%^RESET%^");
         tell_object(victem,""+ETO->query_cap_name()+" stabs you with a strange dagger, your %^RED%^blood burns%^RESET%^!");
        tell_room(environment(ETO),"%^GREEN%^"+ETO->query_cap_name()+" stabs "+victem->query_cap_name()+" and "+victem->query_subjective()+" screams in agony!%^RESET%^",({ETO,victem}));
        if("daemon/saving_d"->saving_throw(victem,"paralyzation_poision_death"))
            return 0;
        else {
            victem->do_damage("torso",poisonstr*6);
            victem->add_poisoning(70);
            venom=0;
            return 0;
        }
    }else 
        return roll_dice(1,4);
}
