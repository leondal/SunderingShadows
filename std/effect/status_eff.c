#include <std.h>

#pragma strict_types
#pragma strong_types
#pragma save_types

inherit OBJECT;

//Mini curses and status effects that should vape with user.c:break_all_spells();

/**
 * clevel and durations are synomims where it is appliable. Duration is taken in rounds.
 */
int duration;
object target;
mixed parameter;

int spelled;
int poisoned;

void create()
{
    ::create();
    set_name("curse_obj");
}

void add_effect(object victim)
{
   object *spells;

   if (!objectp(victim))
      return;

   if (!pointerp(victim->query_property("status_effects")) )
   {
      spells = ({});
   }
   else
   {
      spells = victim->query_property("status_effects");
   }
   spells+= ({TO});
   victim->remove_property("status_effects");
   victim->set_property("status_effects",spells);
}

int query_duration()
{
    return duration;
}

int set_duration(int x)
{
    duration = x;
}

int set_target(object x)
{
    target = x;
}

int query_spell()
{
    return spelled;
}

void set_spell()
{
    spelled = 1;
}

int query_poison()
{
    return poisoned;
}

void set_poison()
{
    poisoned = 1;
}

void set_param(mixed x)
{
    parameter = x;
}

mixed query_param()
{
    return parameter;
}

varargs object apply_effect(object victim, int dur, mixed param)
{
    object tmp;
    tmp = new(file_name(TO));
    tmp->set_target(victim);
    tmp->set_duration(dur);
    tmp->set_param(param);
    tmp->add_effect(victim);
    tmp->status_effect();
    return tmp;
}

void status_effect()
{
    dest_effect();
    return;
}

void dest_effect()
{
    if(objectp(TO))
        TO->remove();
}

int query_noclean()
{
    return 1;
}
