#include <std.h>

inherit OBJECT;

int observe_mark(string str);
object caster,target,casting_spell,justice;
int clevel;

void create(){
    ::create();
    set_id( ({ "justicemark" }) );
    set_name("justicemark");
    set_short("");
    set_long("");
    set_weight(0);
    set("value", 0);
    set_property("no animate",1);
    set_property("no offer", 1);
}

void set_caster(object obj){
    if(!objectp(obj)) { caster = 0; }
    else { caster = obj; }
    return;
}

void set_target(object obj){
    if(!objectp(obj)) { target = 0; }
    else { target = obj; }
    return;
}

void set_clevel(int x){
   if(!intp(x)){ 
      clevel = 5; 
   }else{
      clevel = x;
   }
   return;
}

void set_casting_spell(object obj){
    if(!objectp(obj)) { casting_spell = 0; }
    else { casting_spell = obj; }
    return;
}

void init(){
    ::init();
    add_action("observe_mark","observe");
}

/*
Previous observe command...will now be a full scry
int observe_mark(string str)
{
    object caster_room,mark_room,*inv;
    string desc;
    int i;
    if(!objectp(caster))           { return 0; }
    if(!stringp(str))              { return 0; }
    if(lower_case(str) != "mark")  { return 0; }
    if(!objectp(target))           { return 0; }
    if(target->query_true_invis()) { return 0; }
    if(TP != caster)               { return 0; }

    caster_room = environment(caster);
    mark_room   = environment(target);
    desc        = (string)mark_room->query_short()+"\n";
    desc       += (string)mark_room->query_long()+"\n\n";
    desc       += (string)mark_room->query_long_exits()+"";
    desc       += "\n\n";
    inv         = all_inventory(mark_room);
    for(i=0;i<sizeof(inv);i++)
    {
        if(!objectp(inv[i])) { continue; }
        if(inv[i]->query_invis() && (inv[i] != target)) { continue; }
        desc += (string)inv[i]->query_short()+"\n";
    }

    if(caster_room == mark_room)
    {
        tell_object(caster,"The wearer of the mark is here with you now.");
        return 1;
    }

    tell_object(caster,"You close your eyes and concentrate on the "
        "mark of justice!\n"+desc+"");
    tell_room(caster_room,""+caster->QCN+" closes "+caster->QP+" eyes and "
        "concentrates carefully.",caster);
    return 1;
}
*/

int observe_mark(string str){
   object caster_room,mark_room,*inv;
   string desc;
   int i;

   if(!objectp(caster))           { return 0; }
   if(!stringp(str))              { return 0; }
   if(lower_case(str) != "mark")  { return 0; }
   if(!objectp(target))           { return 0; }
   if(target->query_true_invis()) { return 0; }
   
   if(!objectp(justice))           
   { 
	   justice = new("/cmds/priest/obj/justice_scry");
	   justice->set_caster(caster);
	   justice->set_property("spell",TO);
	   justice->set_property("spelled", ({TO}) );
	   justice->set_target(target);
	   justice->set_scry_power(clevel);
	   justice->set_controller(TO);
	   justice->move(environment(target));
	   justice->call_out("self_destruct",(clevel*5));
   }
   caster_room = environment(caster);
   mark_room   = environment(target);
   desc        = (string)mark_room->query_short()+"\n";
   desc       += (string)mark_room->query_long()+"\n\n";
   desc       += (string)mark_room->query_long_exits()+"";
   desc       += "\n\n";
   inv         = all_inventory(mark_room);
   for(i=0;i<sizeof(inv);i++){
      if(!objectp(inv[i])) { continue; }
      if(inv[i]->query_invis() && (inv[i] != target)) { continue; }
      desc += (string)inv[i]->query_short()+"\n";
   }
   if(caster_room == mark_room){
      tell_object(caster,"The wearer of the mark is here with you now.");
      return 1;
   }
//This spell will allow them to see where someone is as well as 
//scry them for a shorter time than the higher level priest scries
   tell_object(caster,"You close your eyes and concentrate on the "
      "mark of justice!\n"+desc+"");
   tell_room(caster_room,""+caster->QCN+" closes "+caster->QP+" eyes and "
      "concentrates carefully.",caster);
   return 1;
}