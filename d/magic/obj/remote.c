#include <std.h>

inherit OBJECT;

object target, caster, spell;
string targetcn, castercn;
int move_ok;

void create()
{
  ::create();
  set_name("remote control");
  set("id", ({ "remotex999" }) );
  set("short", "");
  set("long", "");
  set_weight(0);
}

void init()
{
  ::init();
    if(environment(TO))
        if(interactive(environment(TO)) && target && targetcn)
        {
            add_action("command","command");
            add_action("free","freedominated");
            tell_object(environment(TO),
"%^BOLD%^You can now command "+targetcn+" by using%^RESET%^ %^ORANGE%^<command dominated to %^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
%^BOLD%^To free them use%^RESET%^ %^ORANGE%^<freedominated>%^RESET%^");
}
}

int command(string str)
{
  object ob, clothes, temp2;
  if(!str)
    {
      notify_fail("<command dominated to ACTION>?\n");
      return 0;
    }
  if(sscanf(str,"dominated to %s",temp2)!= 1)
    {
      notify_fail("<command dominated to ACTION>?\n");
      return 0;
    }
  ob=target;
  if(!ob)
    {
      notify_fail("What are you commanding?\n");
      return 0;
    }
  clothes=present("clothesx999",ob);
  if(!clothes)
    {
      notify_fail("That person was never dominated!\n");
      return 0;
    }
  if((object)clothes->query_master()!=TP)
    {
      notify_fail("That person is dominated by someone else!\n");
      return 0;
    }

  tell_object(ob,"%^GREEN%^"+TPQCN+" telepathically commands you "+
	      "to do something.");
  tell_object(TP,"%^GREEN%^You telepathically command "+
	      ob->query_cap_name()+" to "+temp2+".");
  if(!clothes->action(temp2))
    tell_object(TP,"You can't force "+targetcn+" to do that.");
  return 1;
}

int free(string str)
{
  object ob, clothes;
  if(!target)
    {
      notify_fail("Free who?\n");
      return 0;
    }
  clothes=present("clothesx999",target);
  if(!clothes)
    {
      notify_fail("That person was never dominated in the "+
		  "first place!\n");
      return 0;
    }
  if((object)clothes->query_master()!=TP)
    {
      notify_fail("That person is dominated by someone else!\n");
      return 0;
    }
  tell_object(caster,"%^BOLD%^%^GREEN%^You free "+
	      target->query_short()+" from your spell of domination!");
  tell_object(target,"%^GREEN%^%^BOLD%^"+TPQCN+" frees you from "+
	      caster->query_possessive()+" control.");
  tell_room(environment(target),"%^GREEN%^%^BOLD%^"+
	    target->query_short()+" seems to snap out of a trance.",
	    ({TP,target}));
  spell->dest_effect();
  return 1;
}

void set_target(object ob)
{
  target=ob;
  targetcn=ob->query_cap_name();
  return 1;
}

void set_caster(object ob)
{
  caster=ob;
  castercn=ob->query_cap_name();
  return 1;
}

void move_is_ok(int a)
{
  move_ok=a;
}

void move(mixed dest)
{
  if(!move_ok)
    return 1;
  else
    return ::move(dest);
}

void set_spell(object ob)
{
  spell=ob;
  return 1;
}

int save_me(string file){return 1;}
