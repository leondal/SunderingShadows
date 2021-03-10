#include <std.h>
#include <daemons.h>

inherit OBJECT;
 
void light();
void extinguish();

int lit;
int level;

 
void create() {
  ::create();
    set_author("pator");
    set_id( ({"wood fire","wood_fire","fire"}) );
    set_name("a nice wood fire");
    set_short("A nice wood fire");
    set_weight(1000000);
    set_long(
@PATOR
This is a nice wood fire that seems to burn forever. It doesn't
give much light, but it is very effective and the druidic
serenity makes it the most reliable source of light.
PATOR
);
    set_value(0);
lit = 0;
level = 2;
    
}
 
void reset()
	{
	::reset();
   if(total_light(TO)>2)
       call_out("extinguish",2);
}
void init() 
    {    
    ::init();
	if (effective_light(TO) < 1)
      light();
    }
 
void light()
{
if (!lit)
	{
level = total_light(this_object())+2;
  if(objectp(ETO))
    environment(this_object())->set_property("light", level);
	lit = 1;
	}
}
 
void extinguish() 
{
 level -= 2;
if(objectp(ETO))
    environment(this_object())->set_property("light",level);
level = 0;
lit = 0;
}
