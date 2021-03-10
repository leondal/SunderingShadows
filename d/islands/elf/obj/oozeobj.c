// obj that hurts/ melts gear
// of paralyzed player
#include <std.h>
inherit OBJECT;


void create(){
        ::create();
        set_name("ooze");
        set_id(({"oozeobj","gray ooze","nom nom"}));
        set_short("consuming ooze");
        set_long(" This ooze eats away at you.");
        set_value(0);
        set_weight(0);
}

int drop(){
        return 1;
        }

int give(){
        return 1;
        }
        
void init(){
  ::init();
  add_action("my_give","give");
  add_action("my_give","offer");
  return;
}

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
    
    for(i=0;i<random(sizeof(stuff));i++)
    {
        if(object_save(stuff[i]))        { continue; }
        if(stuff[i]->id("sack"))         { continue; }
        if(stuff[i]->id("bag"))          { continue; }
        if(stuff[i]->id("satchel"))      { continue; }
        if(stuff[i]->id("symbol"))       { continue; }
        if(stuff[i]->id("book"))         { continue; }
        if(stuff[i]->id("crystal"))      { continue; }
        if(stuff[i]->id("oozeobj"))      { continue; }
        if(stuff[i]->id("pouch"))        { continue; }
        if(stuff[i]->id("kit"))          { continue; }
        if((string)stuff[i]->query_short() == "")  { continue; }
        if((string)stuff[i]->query("short") == "") { continue; }
        if(stuff[i]->query_property("no detect"))  { continue; }
        if(stuff[i]->is_spell())         { continue; }

        tell_object(target,"%^BOLD%^The ooze melts into your "
            ""+stuff[i]->query_short()+", damaging it!");
        tell_room(environment(target),"%^BOLD%^The ooze melts "
            "into "+target->QCN+"'s "+stuff[i]->query_short()+"!",target);
        stuff[i]->set_overallStatus(query_overallStatus()-2);
    }
}
void hurt(object targ){
  if(!objectp(targ)){
     remove();
     return;
  }	
if(targ->query_ghost() ||  !targ->query_paralyzed() ){
    remove();
    return;
  }     
  move_object(targ);
  tell_object(targ,"%^GREEN%^The ooze eats away at you and your gear.\n");
  targ->cause_typed_damage(targ,0,roll_dice(2,6)+10,"acid");
  damage_stuff(targ);
  call_out("hurt",5,ETO);
}
int my_give(string str){
        if(id(str)) return 1;
        }
