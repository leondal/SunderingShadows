#include <std.h>

inherit OBJECT;

int remove_person(string str);
int mind_list(string str);

object caster,casting_spell,*linked=({});
string line_name;

void create() 
{
    ::create();
    set_id( ({ "mindnetobj" }) );
    set_name("mindnetobj");
    set_short("");
    set_long("");
    set_weight(0);
    set("value", 0);
    set_property("no animate",1);
    set_property("no offer", 1);
}

void set_line_name(string str)
{
    if(!stringp(str)) { line_name = "0"; }
    else { line_name = str; }
    return;
}

void set_caster(object obj)
{
    if(!objectp(obj)) { caster = 0; }
    else { caster = obj; }
    return;
}

void set_casting_spell(object obj)
{
    if(!objectp(obj)) { casting_spell = 0; }
    else { casting_spell = obj; }
    return;
}

void add_linked(object obj)
{
    if(!objectp(obj)) { return; }
    if(!linked || linked == ({})) { linked = ({ obj }); }
    else { linked += ({ obj }); }
    return;
}

object *query_linked()
{
    if(!pointerp(linked) || linked == ({})) { return ({}); }
    else { return linked; }
}

string query_line_name()
{
    if(!stringp(line_name)) { return "0"; }
    else { return line_name; }
}

void init()
{
    ::init();
    add_action("remove_person","mindnet");
    return;
}

int remove_person(string str)
{
    object target;
	string *info=({}),*people=({}),name;
    int i;

    if(!caster->query_property("mindnet") || (object *)caster->query_property("mindnet") == ({})) { return 0; }
    if(TP != caster) { return 0; }
    if(!stringp(str)) 
    {
        tell_object(caster,"Syntax: mindnet remove <target> or mindnet list");
        return 1;
    }
    info = explode(str," ");
	if(info[0] == "remove")
	{
		if(sizeof(info) != 2)
		{
			tell_object(caster,"Syntax: mindnet remove <target>");
			return 1;
		}
		target = find_player(caster->realName(lower_case(info[1])));
		if(!objectp(target))
		{
			tell_object(caster,"You don't know anyone with that name.");
			return 1;
		}
		if(target == caster)
		{
			tell_object(caster,"You can't remove yourself, if you want to do "
				"that, try dispell mindnet.");
			return 1;
		}
		if(member_array(target,linked) == -1)
		{
			tell_object(caster,"No one with the name of "+capitalize(info[1])+" is "
				"part of the mindnet.");
			return 1;
		}
		tell_object(caster,"You remove "+capitalize(info[1])+" from the mindnet.");
		tell_object(target,""+caster->QCN+"'s mind closes, blocking you from the "
			"mindnet.");
		target->remove_property_value("mindnet",({caster}));
		linked -= ({ target });
		casting_spell->remove_linked(target);
		target->restrict_channel(line_name);
		tell_object(target,"You can no longer use the "+line_name+" line.");
		if(sizeof(linked))
		{
			for(i=0;i<sizeof(linked);i++)
			{
				if(!objectp(linked[i])) { continue; }
				if(linked[i] == caster) { continue; }
				tell_object(linked[i],"You can feel a slight change in the mindnet as "
					"someone is removed.");
			}
		}
	}
	else
	{
		if(sizeof(linked))
		{
			for(i=0;i<sizeof(linked);i++)
			{
				if(!objectp(linked[i])) { continue; }
				if(linked[i]->query_true_invis()) { continue; }
				name = linked[i]->query_true_name();
				name = caster->knownAs(name);
				people += ({ name });
			}
		}
		tell_object(caster,"The following people are currently in the mind net: "+implode(people,", ")+"");
	}

    return 1;
}   