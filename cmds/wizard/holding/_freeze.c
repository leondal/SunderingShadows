#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;
void dest_effect();
void paralysis(mixed *arg2);

create() {
	::create();
	set_spell_name("freeze");
	set_spell_level(3);
	set_spell_type("wizard");
	set_spell_sphere("invocation_evocation");
	set_verbal_comp();
	set_somatic_comp();
	set_target_required(1);
	}

spell_effect()
{
	int num, effect, damage, duration, level, tarlevel, castint, tarint;
	string hardness, HIM, YOU;

	 {


		HIM= (string)TARGET->query_name();
		YOU= (string)CASTER->query_name();
		caster=CASTER;
		target=TARGET;
		clevel=CLEVEL;
		castint=caster->query_stats("intelligence");
		tarint=target->query_stats("intelligence");


		 if(CLEVEL)
			{
				effect=(clevel+1)/2;
				level=to_int(CLEVEL);
				tarlevel=to_int(target->query_level());
			}
		 else
			{
				effect=to_int(caster->query_guild_level("mage")+1)/2;
				level=to_int(caster->query_level());
				if(CLEVEL)
				{
					tarlevel=target->to_int(CLEVEL);
				}
				else
				{
					tarlevel=to_int(target->query_level());
				}
			}

		 damage =(effect*(1+random(2))+random(51));

		 switch(damage)
			{
			case 0..5:
			  hardness="tickles";
			  break;
			case 6..10:
			  hardness="stings";
			  break;
			case 11..20:
			  hardness="shocks";
			  break;
			case 21..50:
			  hardness="zaps";
			  break;
			case 51..100:
			  hardness="blasts";
			  break;
			case 101..1000:
				hardness="destroys";
				break;
			}
			 tell_object(caster,"%^CYAN%^You try to FREEZE "
				+target->query_cap_name()+"!\n");
			 tell_object(target,"%^CYAN%^"+caster->query_cap_name()+
				" tries to FREEZE you!\n");
			 tell_room(environment(target), "%^CYAN%^"+
					caster->query_cap_name()+" casts FREEZE at "+
					target->query_cap_name()+"!\n");

			 tell_object(caster,"%^BOLD%^%^CYAN%^Your FREEZE spell "
				  +hardness+" "+target->query_cap_name())+"\n";
			 tell_object(target,"%^BOLD%^%^CYAN%^The FREEZE spell from "
				+caster->query_cap_name()+" "+hardness+" you!\n");
			 tell_room(environment(target),"%^BOLD%^%^CYAN%^The FREEZE "+
				 "spell from "+caster->query_cap_name() +hardness+" "
				  +target->query_cap_name()+"!\n");
					( {caster, target} );

		duration=((level+castint)-(tarlevel+tarint))*3;
		if((target->query_hp()>0) && (duration>0))
				{
					tell_object(target,"%^BOLD%^%^CYAN%^You are FROZEN SOLID!\n"
						+"You can't move a muscle in your body!\n");
					tell_room(environment(target),"%^BOLD%^%^CYAN%^"
						+target->query_cap_name()+
						" is FROZEN SOLID!\n");
					target->set_paralyzed(duration);
				}
		else
			{
				tell_object(caster,"%^BOLD%^%^YELLOW%^You failed to FREEZE "
						+target->query_cap_name()+"!");
				target->set_paralyzed(0);
				}
	}
  caster->kill_ob(target);
  target->add_hp(-damage);
  dest_effect();
}
void dest_effect()
{
  destruct(TO);
}






