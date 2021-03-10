#include <std.h>
#include "../../defs.h"
inherit ROOM;

int flag;

void player_damage();
void move_here(object ob);

void create(){
    ::create();
    set_name("gelatinous cube");
    set_property("light",-10);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_property("no attack",1);
    set_short("%^BOLD%^%^BLACK%^Inside a gelatinous cube%^RESET%^");
    set_long("Your entire world is a haze filled with the %^RED%^burning pain %^RESET%^of the acidic ooze that "
"surrounds you, slowly consuming you.  You can't see anything but %^CYAN%^blurred %^RESET%^colors, nor hear "
"anything but muted sounds, through the slime of the cube.\n");
    set_exits(([]));
    set_items(([]));
    set_smell("default","You wish your nose would close to lock out the acidic ooze that surrounds you.");
    set_listen("default","Muffled sounds reach your ears but nothing more.");
    flag = 0;
}

void clean_up(){ return; }

void player_damage(){
    object *inven;
    int i,j;
    inven = all_inventory(TO);
    i = sizeof(inven);
    for(j = 0; j < i;j++)
    {
      if(!objectp(inven[j])) continue;
      if(inven[j]->query_true_invis()) continue;
      if(interactive(inven[j]))
      {
        tell_object(inven[j],"%^GREEN%^You feel the cube's acids eating at you!%^RESET%^");
        inven[j]->add_hp(-(random(8)+18));
        tell_object(inven[j],"Hp: "+inven[j]->query_hp());
        inven[j]->add_attacker(TO);
        inven[j]->continue_attack();
        if(objectp(inven[j])) inven[j]->remove_attacker(TO);
      }
      else if(living(inven[j])) 
      {
        inven[j]->add_hp(-20);
        inven[j]->add_attacker(TO);
        inven[j]->continue_attack();
        if(objectp(inven[j])) inven[j]->remove_attacker(TO);
      }
    }
    call_out("player_damage",10);
}

void move_here(object ob){
    ob->move(TO);
}

void init(){
    ::init();
    if(!flag){
      call_out("player_damage",10);
      flag = 1;
    }
    if(living(TP) && !interactive(TP)) TP->add_hp(-20);
}
