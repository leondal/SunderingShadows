#include <std.h>
inherit OBJECT;

object caster, target, image, *foes;
int freed, count;

void save_me(string file){return 1;}

void create(){
    ::create();
    set_name("device");
    set("id", ({ "devicex999" }) );
    set("short", "");
    set("long", "");
    set_weight(0);
}

int move(mixed dest){
   if(ETO && objectp(ETO))
      if(interactive(ETO))
         return 0;
   ::move(dest);
   set_heart_beat(1);
}

set_caster(object ob){
   if(objectp(ob)) caster = ob;
   else remove();
}

set_target(object ob){
   if(objectp(ob)) target = ob;
   else remove();
}

object query_image(){return image;}
object query_caster(){return caster;}
object query_target(){return target;}

void set_image(object ob){image = ob;}

void heart_beat(){
   if(!objectp(caster)) remove();
   if(!objectp(target)) remove();
   if(!objectp(image)) remove();
}

void remove() {
    if(!objectp(TO)) { return; }
    if(objectp(TO->query_property("spell")))
    TO->query_property("spell")->dest_effect();
    if(objectp(TO))
    return ::remove();
}

void init(){
   ::init();
   add_action("dismiss","dismiss");
}

int dismiss(string str){
   if(!str || str != "image") return 0;
   tell_room(environment(image),"%^BOLD%^The image shimmers and fades!",caster);
   tell_object(caster,"%^BOLD%^You dismiss the projected image!\n");
   if (objectp(image)) image->remove();
   call_out("timed",1);
   return 1;
}

int timed(){ remove(); }