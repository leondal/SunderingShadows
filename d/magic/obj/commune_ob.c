#include <std.h>
#include <daemons.h>
#include <clock.h>

inherit OBJECT;

int MyCount, MyOriginalAc, Connected, MyType, MyTries, Denied;
object MySpell, MyTarg, MyCast, MyOb, MyRoom;
string CastTrueName, TargTrueName, CastName, TargName;

void save_me(string file) { return 1; }
void set_caster(object who);
void set_target(object who);
void set_cast_ob(object what);
void set_spell_ob(object spell);
void start_count();
int is_valid();
void SetMyType(int x);
void failed();
void connected();

void create()
{
    	::create();
    	seteuid(geteuid());
    	set_name("device");
    	set_id(({"communedevice"}));
    	set_short("");
    	set_long("");
    	set_weight(0);
	set_property("no animate",1);
	MyCount = 0;
	Connected = 0;
	MyType = 0;
	MyTries = 0;
}

void SetMyType(int x)
{
	MyType = x;
}

int drop() { return 1; }

int move(mixed dest)
{
   if(ETO && objectp(ETO))
   {
       if(interactive(ETO)) { return 0; }
   }
   ::move(dest);
   set_heart_beat(1);
}

void heart_beat()
{
	//if(Connected) return;
	//tell_object(find_player("saide"), "It is getting here... is_valid = "+is_valid());
	if(!objectp(MyTarg) || !objectp(MyCast)) 
	{
		failed();
		return;
	}
	if(!is_valid()) return;
	if(MyType == 1)
	{
		if(!Connected) 
		{
			MyCount++;
			if(MyTries > 3)
			{
				failed();
				return;
			}
			if(MyCount >= 10) 
			{
				MyTries++;
				tell_object(MyTarg, CastName+"%^BOLD%^%^WHITE%^ is attempting to "+
				"commune with you, "+
				"do you wish to open your mind and accept the attempt?\n"+
				"type <%^BOLD%^%^CYAN%^accept%^BOLD%^%^WHITE%^> or <%^BOLD%^%^CYAN%^deny"+
				"%^BOLD%^%^WHITE%^>%^RESET%^");
				MyCount = 0;
				return;
			}
		}		
		if(Connected) 
		{
			if(environment(MyTarg) != MyRoom) 
			{
				tell_object(MyTarg, "Your movement causes your commune "+
				"with "+CastName+" to fail.");
				failed();
				return;
			}
			if(sizeof(MyTarg->query_attackers())) 
			{
				tell_object(MyTarg, "Combat has caused your commune "+
				"with "+CastName+" to fail.");
				failed();
				return;
			}
		}
		return;
	}
	if(!MyType)
	{
		if(Connected)
		{
			if(environment(MyCast) != MyRoom)
			{
				tell_object(MyCast, "Your movement causes your commune "+
				"with "+TargName+" to fail.");
				failed();
				return;
			}
			if(sizeof(MyCast->query_attackers()))
			{
				tell_object(MyCast, "Combat has caused your commune "+
				"with "+TargName+" to fail.");
				failed();
				return;
			}
		}
		return;
	}
}

void init()
{
   	::init();
	if(MyType == 1)
	{
	   add_action("MyResponse","accept");
	   add_action("MyResponse","deny");
	}
}

void failed()
{
	if(objectp(MySpell))
	{
		MySpell->dest_effect();
	}
}

void completed()
{
	string *allowedtell;
	if(!objectp(TO)) return;

	if(Connected)
	{
		if(MyType == 1)
		{
			if(objectp(MyTarg)) 
			{			
				MyTarg->add_ac_bonus(MyOriginalAc);
				tell_object(MyTarg, "%^BOLD%^%^WHITE%^Your commune with "+
				CastName+"%^BOLD%^%^WHITE%^ expires.%^RESET%^");
				allowedtell = MyTarg->query_property("allowed tell");
				if(!allowedtell) allowedtell = ({});
				if(member_array(CastTrueName, allowedtell) != -1)
				{
					allowedtell = allowedtell - ({CastTrueName});
					MyTarg->remove_property("allowed tell");
					MyTarg->set_property("allowed tell", allowedtell);
				}
			}
		}
		if(!MyType)
		{
			if(objectp(MyCast))
			{
				MyCast->add_ac_bonus(MyOriginalAc);
				tell_object(MyCast, "%^BOLD%^%^WHITE%^Your commune with "+
				TargName+"%^BOLD%^%^WHITE%^ expires.%^RESET%^");
				allowedtell = MyCast->query_property("allowed tell");
				if(!allowedtell) allowedtell = ({});
				if(member_array(TargTrueName, allowedtell) != -1)
				{
					allowedtell = allowedtell - ({TargTrueName});
					MyCast->remove_property("allowed tell");
					MyCast->set_property("allowed tell", allowedtell);
				}		
			}		
		}
	}
	if(MyType == 1)
	{
		if(objectp(MyTarg)) 
		{
			MyTarg->remove_property("commune_ob");
			if(!Connected && !Denied)
			{
				tell_object(MyTarg, "%^BOLD%^%^WHITE%^You have waited too long "+
				"for "+CastName+"%^BOLD%^%^WHITE%^'s commune attempt.%^RESET%^");
			}
		}
	}
	if(!MyType)
	{
		if(objectp(MyCast)) 
		{
			MyCast->remove_property("commune_ob");
			if(!Connected && !Denied)
			{
				tell_object(MyCast, TargName+"%^BOLD%^%^WHITE%^ has offered no "+
				"response to your commune attempt.%^RESET%^");
			}
		}
	}
	TO->remove();	
	return;
}

void remove() { if(objectp(TO)) return ::remove(); }

int is_valid()
{
	object DW;
	//DW = find_player("saide");
	//tell_object(find_player("saide"), "It's getting here...");
	if(!objectp(TO)) 
	{	
		//tell_object(DW, "TO failed");
		failed(); 
		return 0;
	}
	if(!objectp(MySpell)) 
	{
		//tell_object(DW, "Myspell failed");
		failed(); 
		return 0;
	}
	if(!objectp(MyTarg)) 
	{
		//tell_object(DW, "MyTarg failed");
		failed(); 
		return 0;
	}
	if(!objectp(MyCast)) 
	{
		//tell_object(DW, "MyCast failed");
		failed(); 
		return 0;
	}
	if(!objectp(MyOb)) 
	{
		//tell_object(DW, "MyOb failed");
		failed(); 
		return 0;
	}
//below added by ~Circe~ after talks with Tsera, Garrett, and Nienne
//6/6/11, usable only in the same room now
      if(!objectp(present(MyTarg,environment(MyCast))))
	{
		failed(); 
		return 0;
	}
	//if(!objectp(MyRoom)) failed(); return 0;
	return 1;
}

void set_caster(object who)
{
	if(!objectp(who)) return;
	MyCast = who;
	CastTrueName = MyCast->query_name();
	CastName = MyCast->QCN;
}

void set_target(object who)
{
	if(!objectp(who)) return;
	MyTarg = who;
	TargTrueName = MyTarg->query_name();
	TargName = MyTarg->QCN;
}

void set_cast_ob(object what)
{
	if(!objectp(what)) return;
	MyOb = what;
}

void set_spell_ob(object spell)
{
	if(!objectp(spell)) return;
	MySpell = spell;
}

void connected()
{
	Connected = 1;
	if(MyType == 1)
	{
		if(objectp(MyTarg)) 
		{
			MyOriginalAc = MyTarg->query_base_ac();
			MyTarg->add_ac_bonus((0-MyOriginalAc));
			MyRoom = environment(MyTarg);
		}
		if(objectp(MySpell)) MySpell->start_delay();
	}
	if(!MyType)
	{
		if(objectp(MyCast))
		{
			MyOriginalAc = MyCast->query_base_ac();
			MyCast->add_ac_bonus((0-MyOriginalAc));
			MyRoom = environment(MyCast);
		}
		if(objectp(MySpell)) MySpell->start_delay();
	}
}
		

int MyResponse(string str)
{
	string *casterallowed, *targallowed;
	str = lower_case(query_verb());
	if(!is_valid()) return 0;
	if(!MyType) return 0;
	if(str != "accept" && str != "deny" || Connected)
	{
		return 0;
	}
	if(str == "accept")
	{
		tell_object(MyCast, TargName+"%^BOLD%^%^WHITE%^ has accepted "+
		"your attempt to commune.  You have now established a mental connection "+
		"with "+MyTarg->QO+".  You must concentrate entirely to maintain it."+
		"%^RESET%^");
		
		tell_object(MyTarg, "%^BOLD%^%^WHITE%^You accept "+CastName+"%^BOLD%^"+
		"%^WHITE%^'s attempt to commune with you.  You must concentrate entirely "+
		"to maintain the link.%^RESET%^");
			
    		casterallowed = MyCast->query_property("allowed tell");
   		targallowed = MyTarg->query_property("allowed tell");   	
		if (!casterallowed) casterallowed = ({});
    		if (!targallowed) targallowed = ({});
		casterallowed += ({MyTarg->query_name()});
		targallowed += ({MyCast->query_name()});
    		MyCast->set_property("allowed tell",casterallowed);
    		MyTarg->set_property("allowed tell",targallowed);
		connected();
		MyOb->connected();
		return 1;
	}
	if(str == "deny")
	{
		Denied = 1;
		tell_object(MyTarg, "%^BOLD%^%^WHITE%^You %^BOLD%^%^RED%^deny"+
		"%^BOLD%^%^WHITE%^ "+CastName+"%^BOLD%^%^WHITE%^'s attempt to "+
		"commune with you.%^RESET%^");
		tell_object(MyCast,TargName+"%^BOLD%^%^WHITE%^ has %^BOLD%^"+
		"%^RED%^denied%^BOLD%^%^WHITE%^ your attempt to commune.%^RESET%^");	
		failed();
		return 1;
	}
	return 0;
}
