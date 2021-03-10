// spell immunity
// priest spell
// Pator@Shadowgate
// 11/06/95

#include <priest.h>


int resist,old_resist;
string query_cast_string()
{
  string cast;
  if (interactive(CASTER))
    { cast = YOU+" prays for a divine spell."; }
  else
    {  cast = YOU+" calls for a divine spell."; }
  return cast;
}

void create()
{
  ::create();
    set_spell_name("spell_immunity");
    set_spell_level(4);
    set_spell_type("priest");
    set_spell_sphere("protection");
    set_target_required(1);
}

void spell_effect()
{
  int clevel,time;
  clevel = CLEVEL;
  if (clevel <= 5)
     { clevel = 6; }
  time = (clevel * 90);
        if (interactive(CASTER))
	{   
	  // An object can't say or hold ...
	  set_verbal_comp();
	  set_somatic_comp();
	  tell_player(CASTER, "You make "+HIM+" resistant to spells");
	  tell_player(TARGET, YOU+" makes you resistant to spells");
	  tell_room(PLACE,
		    YOU+" makes "+HIM+" resistant to spells",
		    ({ CASTER,TARGET }));
	}
      else
	{ tell_player(TARGET, YOU+" makes you resistant to spells");
	  tell_room(PLACE,
		    YOU+" makes "+HIM+" resistant to spells",
		    ({ CASTER,TARGET }));
        }
	old_resist = TARGET->query_property("magical resistance");
	resist = 75;
	TARGET->set_property("magical resistance",resist);
        TARGET->set_property("spelled",TO);
	call_out("dest_effect",time);
        spell_successful();
}

void dest_effect()
{
  ::dest_effect();
    if (interactive(CASTER))
      { tell_player(TARGET,"Your fear for spells has come back to you !!"); }
    tell_room(PLACE,
	      "The fear of spells has returned in "+HIM,
	      ({ TARGET }));
    TARGET->set_property("magical resistance",old_resist);
    destruct(this_object());
}


int help(string str)
{
write(
@HELP
Level  : 4th level
Sphere : Protection
Syntax : < cast spell immunity on [Object || Living]>

This makes the target immune for spells.
The duration of the immunity depends on the level of the caster

HELP
);
return 1;
}

