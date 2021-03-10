// Modified by Pator@ShadowGate
// August 25 1995

#include <priest.h>

int armorclass,old_ac;

create() {
	::create();
	set_spell_name("magical_vestment");
	set_spell_level(3);
	set_spell_type("priest");
	set_spell_sphere("protection");
	set_non_living_ok(0);
}

string query_cast_string()
{
  string cast;
  if (interactive(CASTER))
    { cast = YOU+" folds "+MINE+" hands and ask for a divine spell !\n"; }
  else
    {  cast = YOU+" calls for a divine spell !\n"; }
  return cast;
}

spell_effect() {
	int new_ac,level,duration;
    if( interactive(CASTER) )	
	{
	  level = (int)CASTER->query_level();
	  if(level > 20) level = 20;
	  level -= 6;
	  new_ac = 5 - (level/3);
	  duration = (4 + level) * 10;
	  armorclass = CASTER->query_ac();

	  tell_object(CASTER, 
		      "You cast a magical vestment on yourself");
          tell_room(PLACE, YOU+" casts a protective spell to "+MY_PERS+"self \n",
		    ({CASTER}));
	  CASTER->set_ac(new_ac);
	  old_ac = armorclass;
     call_out("dest_effect",duration);
	}
}

void dest_effect()
{
        ::dest_effect();
	CASTER->set_ac(old_ac);
	spell_successful();
	  tell_player(CASTER,"You feel the magical vestment wear off.");
	  destruct(this_object());
}

int help(string str){
write(
@HELP
Level  : 3rd level
Sphere : Protection
Syntax : <cast magical vestment>

Will create a magical armor around the caster,
which will increase in ac and duration as the 
caster gains levels. It can only be cast upon 
ones self.

HELP
);
}

