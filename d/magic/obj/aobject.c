//aobject.c

// added a check to query if the object was protecting the caster before it was removed, if it was, remove it from the array - Ares /7/17/05

#include <std.h>
#define SAVE_DIR = "/d/magic/obj/save/"

inherit WEAPONLESS;

object thing, caster;

void create(){
  ::create();
  set_name("animated object");
  set_alignment(5);
  set("magic",1);
  set_race("object");
  remove_limb("head");
  remove_limb("neck");
  remove_limb("torso");
  remove_limb("left hand");
  remove_limb("right hand");
  remove_limb("left arm");
  remove_limb("right arm");
  remove_limb("left leg");
  remove_limb("right leg");
  remove_limb("left foot");
  remove_limb("right foot");
}

void die(object ob)
{
	object obj;
  	tell_room(ETO,"%^RED%^"+capitalize(TO->query_name())+
	" stops suddenly as the last bit holding it together is destroyed");
  	if (objectp(thing)) 
	{
        if(objectp(caster))
        {
            if(member_array(thing,caster->query_protectors()) != -1) 
            { 
                caster->remove_protector(thing); 
            }//7/17/05 -Ares
        }
        thing->move(environment(TO));
        //added by Saide - this should, in theory, 
        //prevent anything from being lost when an object is destroyed and has
        //contents inside it - lets hope
        if(sizeof(all_inventory(thing)))
        {
			all_inventory(thing)->move(environment(thing));
		}
        thing->remove();
  	}
  	remove();
}

void set_object(object item){
  thing=item;
}
void set_caster(object whom){ caster = whom; return;} 
object query_caster() { return caster; }

object query_object(){
  return thing;
}

void __internal_add_exp(int x)
{
    if(objectp(caster)) { caster->__internal_add_exp(x); }
    return;
}

void set_heart(int x){
  set_heart_beat(x);
}


int isMagic() {return 2;}
//string realName(string str) { return caster->realName(str) ; }

void add_exp(int exp)
{
    if(objectp(caster)) { caster->add_exp(exp); }
    return;
}
