//      Light Creating Object
//      Thorn@ShadowGate
//      2/11/95
//      Spell Helper Objects
//      lightobj.c

#include <std.h>

inherit OBJECT;

int lit, fuel, light_time;

void set_light_time(int casterlevel) 
{
	if(!casterlevel) light_time = 0;
	light_time = casterlevel;
}

int query_light_time() { return light_time; }

int let_there_be_light()
{
    if(!objectp(ETO)) return;
    environment(this_object())->set_property("light",2);
	call_out("go_dark", light_time);
	return 1;
}

void go_dark() 
{
	tell_room("The light source suddenly winks out!\n");
	this_object()->remove();
    return;
}
	
void create() {
	::create();
	set_id( ({ "lightobjx" }) );
	set_long("INVISIBLE LIGHT OBJECT: If you can see this, alert a wizard immediately!\n");
	set_weight(0);
	set_value(0);
	let_there_be_light();
}

int move(mixed dest)
{
	int x;
    if(!objectp(ETO)) return ::move(dest);
	environment(this_object())->set_property("light", -2);
	x = ::move(dest);
	environment(this_object())->set_property("light", 2);
	return x;
}

void remove() 
{
    if(objectp(previous_object()))
    {
        if(objectp(environment(previous_object()))) { environment(previous_object())->set_property("light",-2); }
    }
	return ::remove();
}
