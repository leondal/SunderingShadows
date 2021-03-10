// fireflame.c
// tweaking this to damage equipment instead of burning sacks so that it's not 
// such a crippling ability -Ares
// Adding a way to douse the flame ~Circe~ 5/18/13
#include <std.h>

inherit OBJECT;
int count;

void create()
{
   ::create();
   set_name("burning fire");
   set_id(({"fireflame","fire","burning fire"}));
   set_short("%^RED%^Burning flame");
   set_long(
@OLI
   This is a small magical fire that is bruning along your clothes
and skin. The fire is spreading, consuming anything combustable it
can find. You might be able to <douse> it.
OLI
   );
   set_heart_beat(5);
}

void init(){
   ::init();
   tell_object(ETO,"%^BOLD%^%^RED%^You are covered in flames! You might be able to <douse> the fire.%^RESET%^");
   add_action("douse","douse");
}

int douse(string str){
   if(!str){
      tell_object(TP,"What are you trying to douse?");
      return 1;
   }
   if(str != "flame" && str != "flames" && str != "fire" && str != "burning fire") return 0;
   tell_object(TP,"%^BOLD%^%^WHITE%^You frantically pat at the flames covering your body, putting them out!%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^WHITE%^You see "+TPQCN+" frantically pat at the flames covering "+TP->QP+" body, putting them out!",TP);
   TO->remove();
   return 1;
}


int drop() { return 1; }

int get() { return 0; }

// gives the stuff in inventory a save based on enchantment
int object_save(object obj)
{
    int enchantment;
    if(!objectp(obj)) { return 1; }
    enchantment = (int)obj->query_property("enchantment");
    if(!enchantment) { enchantment = obj->isMagic(); }
    if((roll_dice(1,20) + enchantment) < roll_dice(1,20)) { return 0;}
    return 1;
}

void damage_stuff(object target)
{
    object *stuff;
    int i;

    if(!objectp(target)) { return; }
    stuff = all_inventory(target);
    if(!sizeof(stuff)) { return; }
    
    for(i=0;i<sizeof(stuff);i++)
    {
        if(object_save(stuff[i]))        { continue; }
        if(stuff[i]->id("sack"))         { continue; }
        if(stuff[i]->id("bag"))          { continue; }
        if(stuff[i]->id("satchel"))      { continue; }
        if(stuff[i]->id("symbol"))       { continue; }
        if(stuff[i]->id("book"))         { continue; }
        if(stuff[i]->id("crystal"))      { continue; }
        if(stuff[i]->id("burning fire")) { continue; }
        if(stuff[i]->id("pouch"))        { continue; }
        if(stuff[i]->id("kit"))          { continue; }
        if((string)stuff[i]->query_short() == "")  { continue; }
        if((string)stuff[i]->query("short") == "") { continue; }
        if(stuff[i]->query_property("no detect"))  { continue; }
        if(stuff[i]->is_spell())         { continue; }

        tell_object(target,"%^RED%^The f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^RED%^ burns into your "
            ""+stuff[i]->query_short()+", damaging it!%^RESET%^");
        tell_room(environment(target),"%^RED%^The f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^RED%^ burns "
            "into "+target->QCN+"'s "+stuff[i]->query_short()+"!%^RESET%^",target);
        stuff[i]->repairMe(roll_dice(1,6) * -1);
    }
}

void heart_beat()
{
   object ob;

   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(!living(ETO)) return;
   tell_object(ETO,"%^RED%^The fire on you burns your clothing and skin.");
   ETO->do_damage("torso",roll_dice(2,10));
   ETO->add_attacker(TO);
   ETO->continue_attack();
// added objectp check and corrected remove_attack to remove_attacker *Styx* 7/31/05
   if(!objectp(ETO))  return;
   ETO->remove_attacker(TO);

   damage_stuff(ETO);

   //if(ob = present("sack",ETO)){
   //  tell_object(ETO,"%^RED%^The fire spreads to your sack and it starts to burn.");
   //   ob->remove();
   //}
   count++;
   if(count >4) 
   {
       tell_object(ETO,"%^YELLOW%^The fire sputters and sizzles and finally burns "
           "itself out!%^RESET%^");
       remove();
   }
}
