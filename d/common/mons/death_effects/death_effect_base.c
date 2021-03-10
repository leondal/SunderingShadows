#include <std.h>
#include "death_effects.h"
inherit OBJECT;
string __LevelRange, __effectType;
int __effectLevel, __effectEnv;
object OriginObject;
string __effectTarg;

void create() 
{
	::create();
    	set_name("death effect base");
	set_short("A base effect");
	set_id(({"effect"}));
    	set_weight(1);
	__effectType = "base";
	__LevelRange = "NIL";	
	__effectEnv = -1;
}

int query_environment_required() { return __effectEnv; }

//1 to set this as indoor only affect
//0 to set this as outdoor only - Saide
void set_environment_required(int x) 
{
	__effectEnv = x;
}

void set_level_range(string range)
{
	if(!stringp(range)) return;
	__LevelRange = range;
}

string query_level_range() { return __LevelRange; }

void set_effect_type(string type)
{
	if(!stringp(type)) return;
	__effectType = type;
}

string query_effect_type() { return __effectType; }

void adjust_level(int MyLevel)
{
	__effectLevel = MyLevel;
}

int query_effect_level() { return __effectLevel; }

void set_effectOrigin(object targ)
{
	if(!objectp(targ)) return;
	OriginObject = targ;
	__effectTarg = targ->query_name();
}

string query_effect_origin() { return __effectTarg; }

mixed query_origin_object() 
{
	if(!objectp(OriginObject)) return 0;
	return OriginObject;
}

int get() { return 0; }