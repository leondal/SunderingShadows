//changed by ~Circe~ 6/6/11 to be in room only after conversations with Tsera, Garrett, and Nienne
//updated by ~Circe~ 7/30/13 to accommodate the Drow subrace Ssri tel quessir, who have had the curse removed

#include <priest.h>
inherit SPELL;

object who, cast_ob, targ_ob;
string whoname, whocname, cname, Ccname;
int Started;

void create() 
{
    	::create();     
    	set_spell_name("commune");
    	set_spell_level(([ "innate" : 1 ]));
    	set_spell_sphere("divination");
    	set_syntax("cast CLASS commune on TARGET");
    	set_description("This spell, innate to all elves, allows them to "+
	"communicate mentally with one another.  However, it requires complete and total "+
	"concentration and the simplest act, even moving, breaks the connection.  "+
      "The elves communicating in this way must remain in the same room, or "+
      "the connection will end.  "+
	"It will also render the caster completely vulnerable to physical attacks while "+
	"active and engaging in combat will also break the connection.");
    	set_verbal_comp();
    	set_somatic_comp();
    	set_arg_needed();
	set_peace_needed(1);
}

int preSpell()
{
	object CO;
	if(objectp(CO = CASTER->query_property("commune_ob"))) 
	{
		CO->failed();
	}
	return 1;
}

string query_cast_string() 
{
	return "%^BOLD%^%^WHITE%^"+YOU+" closes "+MINE+" eyes and concentrates deeply.";
}

void spell_effect(int prof) 
{
	string arg;
    	string *ignored, *casterallowed, *targallowed;

    	arg = lower_case(ARG);
    	if (!(who = find_player(caster->realName(arg)))) 
	{
      	tell_object(CASTER,capitalize(arg)+" cannot be found to commune with.\n");
            if(objectp(TO)) TO->remove();
        	return;
    	}
//below added by ~Circe~ 6/6/11
	if (!(objectp(present(who,environment(CASTER)))))
	{
      	tell_object(CASTER,capitalize(arg)+" cannot be found to commune with.\n");
            if(objectp(TO)) TO->remove();
        	return;
    	}

    	cname = CASTER->query_name();
    	whoname = who->query_name();
    	whocname = who->QCN;
    	Ccname = CASTER->QCN;
    	if (avatarp(who) && !who->query_disguised()) 
	{
       	tell_object(CASTER,capitalize(arg)+" cannot be found to commune with.\n");
            if(objectp(TO)) TO->remove();
        	return;
    	}
   	if(avatarp(who) && arg == (string)who->query_true_name()) 
	{
      	tell_object(CASTER,capitalize(arg)+" cannot be found to commune with.\n");
            if(objectp(TO)) TO->remove();
      	return;
   	}
    	if (arg == cname) 
	{
        	tell_object(CASTER,"You cannot commune with yourself.\n");
            if(objectp(TO)) TO->remove();
        	return;
    	}
    	if (who->query_invis() && (int)who->query_level() > (int)CASTER->query_level()) 
	{
      	tell_object(CASTER,capitalize(arg)+" cannot be found to commune with.\n");
            if(objectp(TO)) TO->remove();
        	return;
    	}
    	if (who->is_player() && !interactive(who)) 
	{
      	tell_object(CASTER, who->QCN+" is link-dead and cannot hear you.\n");
            if(objectp(TO)) TO->remove();
        	return;
    	}

	if((string)who->query_race() != "elf")
	{
         if((string)who->query("subrace") && (string)who->query("subrace") != "ssri tel quessir"){
		tell_object(CASTER, who->QCN+" is not of the elven race and therefore "+
		"cannot understand your attempt to commune.");
            if(objectp(TO)) TO->remove();
		return;
         }
	}

	if(sizeof(who->query_attackers())) 
	{
		tell_object(CASTER, who->QCN+" seems preoccupied and unable to commune "+
		"with you at this time.");
            if(objectp(TO)) TO->remove();
		return;
	}

	if(who->query_ghost()) 
	{
		tell_object(CASTER,capitalize(arg)+" cannot be found to commune with.\n");
            if(objectp(TO)) TO->remove();
		return;
	}
    	if (who->query_blocked("tell")) 
	{
      	write(who->QCN+" is currently blocking all tells.");
            if(objectp(TO)) TO->remove();
        	return;
    	}
    	ignored = who->query_ignored();
    	if (!ignored) 
	{
      	who->reset_ignored();
        	ignored = who->query_ignored();
    	}
    	if ((member_array(cname, ignored) != -1)) 
	{
      	tell_object(CASTER, who->QCN+" is ignoring you.\n");
            if(objectp(TO)) TO->remove();
        	return;
    	}
	casterallowed = CASTER->query_property("allowed tell");
   	targallowed = who->query_property("allowed tell");   	
	if (!casterallowed) casterallowed = ({});
    	if (!targallowed) targallowed = ({});
    	if (member_array(cname,targallowed) != -1
        && member_array(whoname,casterallowed) != -1) 
	{
     		tell_object(CASTER,"You already have a mental link with "+who->QCN+".\n");
            if(objectp(TO)) TO->remove();
        	return;
    	}
	if(objectp(who->query_property("commune_ob"))) 
	{
		tell_object(CASTER, who->QCN+" seems preoccupied and unable to commune "+
		"with you at this time.");
            if(objectp(TO)) TO->remove();
		return;
	}


	tell_object(CASTER, "%^BOLD%^%^WHITE%^You attempt to %^BOLD%^%^CYAN%^commune"+
	"%^BOLD%^%^WHITE%^ with "+who->QCN+", you must wait and see if "+who->QS+
	" accepts your attempt.%^RESET%^");

	tell_object(who, CASTER->QCN+"%^BOLD%^%^WHITE%^ is attempting to commune with you, "+
	"do you wish to open your mind and accept the attempt?\n"+
	"type <%^BOLD%^%^CYAN%^accept%^BOLD%^%^WHITE%^> or <%^BOLD%^%^CYAN%^deny"+
	"%^BOLD%^%^WHITE%^>%^RESET%^");

	cast_ob = new("/d/magic/obj/commune_ob");
	targ_ob = new("/d/magic/obj/commune_ob");
	caster->set_property("commune_ob", cast_ob);
	who->set_property("commune_ob", targ_ob);
	cast_ob->set_caster(CASTER);
	cast_ob->set_target(who);
	cast_ob->set_cast_ob(targ_ob);
	cast_ob->set_spell_ob(TO);

	targ_ob->set_caster(CASTER);
	targ_ob->set_target(who);
	targ_ob->set_cast_ob(cast_ob);
	targ_ob->set_spell_ob(TO);
	targ_ob->SetMyType(1);

	targ_ob->move(who);
	//targ_ob->set_heart_beat(1);

	cast_ob->move(CASTER);
	//cast_ob->set_heart_beat(1);
	addSpellToCaster();
	CASTER->set_property("spelled", ({TO}) );	   
}

void start_delay()
{
	if(!Started) 
	{
		call_out("dest_effect",clevel*10);
		Started = 1;
	}
}

void dest_effect() 
{
	if(objectp(CASTER)) 
	{
		CASTER->remove_property_value("spelled", ({TO}) );
	}
	if(objectp(cast_ob))
	{
		cast_ob->completed();
	}
	if(objectp(targ_ob))
	{
		targ_ob->completed();
	}	
    	::dest_effect();
      if(objectp(TO)) TO->remove();
}