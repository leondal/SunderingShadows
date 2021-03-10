#include <std.h>
#include <area_stuff.h>
#include <daemons.h>

inherit ROOM;

#define RUNE_FORMS ({"%^BOLD%^%^GREEN%^A Solid Block%^RESET%^", "%^RED%^A Hissing Serpent%^RESET%^", "%^BOLD%^%^WHITE%^A Jagged Dagger%^RESET%^", "%^BOLD%^BLUE%^A Manical Sorcerer%^RESET%^"})

int searched, runeform, speed, had_monster, num_monsters;
string c_one, c_two, c_three, c_four, exit1, exit2, exit3, exit4;
void switch_runes();

void create() 
{
 	::create();
   	set_property("no teleport",1);
    	set_property("light",0);
    	set_property("indoors",1);
	set_property("no sticks", 1);
    	set_name("marble corridor");
    	set_short("%^BOLD%^%^WHITE%^A %^BOLD%^BLACK%^metal%^BOLD%^%^WHITE%^ room");
    	set_terrain(BUILT_TUNNEL);
    	set_travel(PAVED_ROAD);

    	set_long("%^BOLD%^%^WHITE%^This odd room is perfectly squared, as far as you can ascertain.  "+
	"The %^RESET%^%^WHITE%^vaulted ceiling%^BOLD%^%^WHITE%^ hangs far overhead, and from what "+
	"you can make out, appears perfectly smooth - %^BOLD%^%^RED%^flawless%^BOLD%^%^WHITE%^ - in "+
	"fact.  The floor also appears relatively %^RESET%^%^WHITE%^smooth "+
	"%^BOLD%^%^WHITE%^though it is covered in strange %^BOLD%^%^CYAN%^r%^BOLD%^%^BLUE%^u"+
	"%^BOLD%^%^CYAN%^n%^BOLD%^%^BLUE%^i%^BOLD%^%^CYAN%^c symbols%^BOLD%^%^WHITE%^ "+
	"which are slowly shifting form.  The walls of the room are likewise %^RESET%^%^WHITE%^"+
	"smooth%^BOLD%^%^WHITE%^, however, set upon each one are two %^BOLD%^%^BLUE%^buttons"+
	"%^BOLD%^%^WHITE%^ and two %^BOLD%^%^RED%^levers%^BOLD%^%^WHITE%^ which if you were "+
	"curious enough you could probably %^BOLD%^%^GREEN%^manipulate%^BOLD%^%^WHITE%^.  "+
	"The entire room is formed from some %^BOLD%^%^BLACK%^dark metallic material%^BOLD%^"+
	"%^WHITE%^ unlike anything you've ever seen before.%^RESET%^");

    	set_smell("default","%^BOLD%^A strong aroma of magic hangs heavily here.");
    	set_listen("default","%^BOLD%^A tangible silence greets you.%^RESET%^");

	speed = 50 + random(66);
	runeform = random(4);
	switch_runes();
	had_monster = 0;
	set_items(([({"symbols", "runes", "runic symbol", "runic symbols"}) : (:TO, "display_rune":), 
	({"button", "buttons"}) : "%^BOLD%^%^BLUE%^There are eight metallic buttons in "+
	"this room, two on each wall - you could easily %^BOLD%^%^GREEN%^push"+
	"%^BOLD%^%^BLUE%^ one of them if you were so inclined.%^RESET%^", 
	({"lever", "levers"}) : "%^BOLD%^%^RED%^There are eight levers in this room, "+
	"two on each wall - you could easily %^BOLD%^%^GREEN%^pull"+
	"%^BOLD%^%^RED%^ one of them if you were so inclined.%^RESET%^",
	({"ceiling", "vaulted ceiling"}) : "%^RESET%^%^WHITE%^The "+
	"ceiling here is vaulted rising almost beyond normal sight, but "+
	"from what you can tell it is perfectly flawless and made "+
	"from a %^BOLD%^%^BLACK%^dark metallic material%^RESET%^%^WHITE%^"+
	".%^RESET%^", 
	({"floor", "rune covered floor"}) : "%^BOLD%^%^WHITE%^The floor here is "+
	"relatively smooth, though it is covered in strange %^BOLD%^%^CYAN%^r"+
	"%^BOLD%^%^BLUE%^u%^BOLD%^%^CYAN%^n%^BOLD%^%^BLUE%^i%^BOLD%^%^CYAN%^c "+
	"symbols%^BOLD%^%^WHITE%^ which are slowly shifting form.%^RESET%^", 
	({"walls", "wall", "north wall", "east wall", 
	"west wall", "south wall"}) : "%^BOLD%^%^WHITE%^All four walls of "+
	"this room are perfectly smooth, however, set upon each one are "+
	"two %^BOLD%^%^BLUE%^buttons%^BOLD%^%^WHITE%^ and two "+
	"%^BOLD%^%^RED%^levers%^BOLD%^%^WHITE%^.%^RESET%^", 
	({"dark material", "material", "metallic material", 
	"dark metallic material", "dark material"}) : "%^BOLD%^%^BLACK%^The "+
	"strange material that creates this room is of unknown "+
	"origin, though it appears to be metallic, it is unlike "+
	"anything you have ever seen before.%^RESET%^",
   	] ));

	set_property("room lore", ([({"symbols", "runes", "runic symbol", 
	"runic symbols"}) : ({"%^BOLD%^%^CYAN%^Though you are not able to "+
	"determine the exact purpose of these symbols, you can tell that they are "+
	"somehow connected to the buttons and levers on the walls here.  You believe "+
	"that only when the symbols are in the shape of the sorcerer are the "+
	"buttons and levers safe to manipulate.  However, the sorcerer "+
	"is a dark omen here for those trying to use their own magical "+
	"incantations.  You are not sure what, but some dark power "+
	"has enchanted these symbols.%^RESET%^", 45}), 

	({"button", "buttons", "lever", "levers"}) : ({"%^BOLD%^%^BLUE%^"+
	"The buttons and levers here are the only means "+
	"by which one has to move about this strange place.  "+
	"You are sure that most of them "+
	"are pseudo, however, you are able to tell that four of them, though "+
	"not which ones, are real.  They are somehow connected with the "+
	"symbols on the floor.  You also realize that some "+
	"very ancient and dark power has imbued them and believe "+
	"that you should use caution.%^RESET%^", 45}),

	({"dark material", "dark metal", "material", "room"}) : ({"%^BOLD%^%^BLACK%^"+
	"The dark metallic material here is nothing "+
	"more than typical iron, however, some ancient and dark "+
	"power has imbued it with a very strong magic.  You can "+
	"tell that all typical methods of magical "+
	"movement are blocked here because of it.%^RESET%^", 45}) ]) ); 

    	set_search("default","You find no place for anything to be concealed.");
	c_one = BE2;
	exit1 = base_name(TO);

}

void init() 
{
        ::init();
        add_action("push_function","push");
        add_action("pull_function","pull");        
}

string text_number(int num)
{
	switch (num)
	{
		case 1: 
			return "first";
		case 2:
			return "second";
	}
}

void complete_move(object who, object new_room)
{
	if(!objectp(who)) return;
	if(!objectp(new_room)) 
	{
		who->remove_property("has_manipulated_button_or_lever");
		tell_object(who, "%^BOLD%^%^RED%^Something has went wrong, "+
		"please notify saide%^RESET%^");
		return;
	}

	tell_object(who,"%^BOLD%^%^CYAN%^The blue light fades "+
     	"away, leaving you at "+new_room->query_short()+".%^RESET%^");
	tell_room(TO,"%^CYAN%^The blue light dies away, and "+
      who->QCN+" is gone!%^RESET%^", who);
	tell_room(new_room,"%^BOLD%^%^CYAN%^The blue light grows "+
     	"into the image of "+who->QCN+", then "+
	"dims and dies out, leaving "+who->query_objective()+
      " behind!",who);
	who->move_player(new_room);
	who->remove_property("has_manipulated_button_or_lever");
	return;
}

void do_summon_monsters(int how_m)
{
	object mon;
	mon = new(RA_MON+"spec_ser_thief");
	tell_room(TO, "%^CYAN%^The blue light grows "+
	"into the image of "+mon->query_short()+"%^BOLD%^"+
	"%^CYAN%^, then dims and dies out, leaving it behind!%^RESET%^");
	mon->move(TO);
	if(!random(2)) 
	{
		mon = new(RA_MON+"spec_ser_war");
	}
	else
	{
		mon = new(RA_MON+"spec_ser_cleric");
	}
	tell_room(TO, "%^CYAN%^The blue light grows "+
	"into the image of "+mon->query_short()+"%^BOLD%^"+
	"%^CYAN%^, then dims and dies out, leaving it "+
	"behind!%^RESET%^");
	mon->move(TO);
}

void complete_manipulation(object who, string where)
{
	object new_room;
	int teleport_ok = 0, ct = 0;
	if(!objectp(who))
	{
		tell_room(TO, "Something has went wrong... bug report this or mail Saide.");
		return;
	}
	new_room = find_object_or_load(where);
	if(!objectp(new_room))
	{
		tell_room(TO, "Something has went wrong... bug report this or mail Saide.");
		return;
	}
	if(runeform == 0) 
	{
		new_room = find_object_or_load(base_name(TO));
		teleport_ok = 1;
	}	
	if(runeform == 1)
	{
		//teleport a random monster in 
		//rare chance of some type of vicious
		//serpent monster 
		//only 1 random monster per room - otherwise it's 
		//going to look like nothing happens
		had_monster = 1;
		num_monsters = 2;
		while(ct < num_monsters)
		{
			ct++;
			tell_room(TO, "%^CYAN%^A blue light grows in the air in your "+
			"vicinity%^RESET%^.");
		}
		call_out("do_summon_monsters", 5, num_monsters);
		who->remove_property("has_manipulated_button_or_lever");
		return;
	}
	if(runeform == 2)
	{
		//do a disembodied hand wielding a dagger
		//stabbing them in the chest - then do the teleport
		//do as much damage as a level 40 thief with stab 
		tell_object(who, "%^BOLD%^%^GREEN%^A %^BOLD%^%^RED%^"+
		"disembodied%^BOLD%^%^GREEN%^ hand appears in front of you "+
		" - gripping a wicked looking knife - it %^BOLD%^%^RED%^"+
		"STABS%^BOLD%^%^GREEN%^ at your chest!%^RESET%^");

		tell_room(TO, "%^BOLD%^%^GREEN%^A %^BOLD%^%^RED%^"+
		"disembodied%^BOLD%^%^GREEN%^ hand appears in front of "+
		who->QCN+"%^BOLD%^%^GREEN%^ - gripping a wicked "+
		"looking knife - it %^BOLD%^%^RED%^STABS"+
		"%^BOLD%^%^GREEN%^ at "+who->QP+
		" chest!%^RESET%^", ({who}));

		if(!"/daemon/saving_throw_d.c"->reflex_save(who, -20)) 
		{
			tell_object(who, "%^BOLD%^%^RED%^You are unable "+
			"to avoid the knife and it jabs deep into your "+
			"chest!%^RESET%^");
			who->cause_typed_damage(who, "torso", roll_dice(12, 8), "piercing");
			tell_room(TO, who->QCN+"%^BOLD%^%^RED%^ is "+
			"unable to avoid the knife and it "+
			"jabs deep into "+who->QP + " chest!%^RESET%^", ({who}));
		}
		else 
		{
			tell_object(who, "%^BOLD%^%^RED%^You manage to "+
			"move away just in time and the knife only "+
			"knicks your flesh!%^RESET%^");

			who->cause_typed_damage(who, "torso", roll_dice(6, 6), "slashing");
			
			tell_room(TO, who->QCN+"%^BOLD%^%^RED%^ manages "+
			"to move away just in time and is only knicked by "+
			"the knife!%^RESET%^", ({who}));
		}
		tell_room(TO, "%^BOLD%^%^GREEN%^The %^BOLD%^%^RED%^disembodied "+
		"%^BOLD%^%^GREEN%^hand %^BOLD%^%^YELLOW%^blinks%^BOLD%^%^GREEN%^ "+
		"out of existence!%^RESET%^");			
		teleport_ok = 1;
	}
	if(runeform == 3)
	{
		//teleport them normally
		teleport_ok = 1;
	}
	if(teleport_ok)
	{
		tell_object(who,"%^BOLD%^%^CYAN%^A blue light "+
	         "brightens from your chest, encompassing you.%^RESET%^");
	     	tell_room(TO,"%^BOLD%^%^CYAN%^A blue light brightens "+
      	   "from "+who->QCN+"'s chest, "+
	         "encompassing "+who->query_objective()+".%^RESET%^", who);
      	tell_room(new_room,"%^CYAN%^A blue light grows in the air "+
         	"in your vicinity.%^RESET%^",who);
		call_out("complete_move", 5, who, new_room);
		return;
	}

}

void manipulate_check(object who, string dir, string mtype, int which)
{
	string argu, what, rwhat;
	argu = dir + " " + mtype + " " + which;
	if(!objectp(who)) return;
	if(environment(who) != TO) 
	{
		who->remove_property("has_manipulated_button_or_lever");
		return;
	}
	if(!stringp(argu)) return;

	switch (mtype)
	{
		case "button":
			what = "push the button";
			rwhat = "pushes the button";
			break;
		case "lever":
			what = "pull the lever";
			rwhat = "pulls the lever";
			break;
		default:
			return;
	}
	if(argu == c_one) 
	{
		if(runeform == 1 && !had_monster || runeform != 1)
		{
			complete_manipulation(who, exit1);
			return;
		}
	}
	else if(argu == c_two)
	{
		if(runeform == 1 && !had_monster || runeform != 1)
		{
			complete_manipulation(who, exit2);
			return;
		}
	}
	else if(argu == c_three)
	{
		if(runeform == 1 && !had_monster || runeform != 1)
		{
			complete_manipulation(who, exit3);
			return;
		}
	}
	else if(argu == c_four)
	{
		if(runeform == 1 && !had_monster || runeform != 1)
		{
			complete_manipulation(who, exit4);
			return;
		}
	}
	tell_object(who, "%^BOLD%^%^CYAN%^A loud manical laughter echoes "+
	"through the room as you "+what+" but nothing else seems to happen...%^RESET%^");
	tell_room(TO, "%^BOLD%^%^CYAN%^A loud manical laughter echoes "+
	"through the room as "+who->QCN+"%^BOLD%^%^CYAN%^ "+rwhat+
	" but nothing else seems to happen....%^RESET%^", who);
	who->remove_property("has_manipulated_button_or_lever");
	return;
}


int push_function(string arg)
{
	string lever;
	int which;
	if(!arg) 
	{
		tell_object(TP, "What do you want to push?  There are eight buttons here - "+
		"try <push direction button #>");
		return 1;
	}
	if(sscanf(arg, "%s button %d", lever, which) == 2) 
	{
		lever = lower_case(lever);
		if(which > 2 || which < 1)
		{
			tell_object(TP, "There are only two buttons on the "+lever+ 
			" wall to push!");
			return 1;
		}
		switch(lever) 
		{		
			case "north": case "south": case "east": case "west":
				if(TP->query_property("has_manipulated_button_or_lever")) 
				{
					tell_object(TP, "%^BOLD%^%^CYAN%^You should wait to see what happens first...%^RESET%^");
					return 1;
				}
				TP->set_property("has_manipulated_button_or_lever", 1);
				tell_room(TO, TPQCN + "%^BOLD%^%^YELLOW%^ walks over to "+
				"the "+lever+" wall and pushes the "+
				text_number(which) + " button!%^BOLD%^%^BLUE%^.%^RESET%^", TP);
				tell_object(TP, "%^BOLD%^%^YELLOW%^You walk over to "+
				"the "+lever+" wall and push the "+text_number(which)+
				" button.%^RESET%^");
				call_out("manipulate_check", 2, TP, lever, "button", which);
				return 1;
			default:
				tell_object(TP, "Try pushing one of the buttons on the "+
				"north, east, south, or west wall.");
				return 1;
		}
	}
	tell_object(TP, "What do you want to push?  There are eight buttons here - "+
	"try <push direction button #>");
	return 1;

}

int pull_function(string arg)
{
	string lever;
	int which;
	if(!arg) 
	{
		tell_object(TP, "What do you want to pull?  There are eight levers here - "+
		"try <pull lever direction #>");
		return 1;
	}
	if(sscanf(arg, "%s lever %d", lever, which) == 2) 
	{
		lever = lower_case(lever);
		if(which > 2 || which < 1)
		{
			tell_object(TP, "There are only two levers on the "+lever+ 
			" wall to pull!");
			return 1;
		}
		switch(lever) 
		{		
			case "north": case "south": case "east": case "west":
				if(TP->query_property("has_manipulated_button_or_lever")) 
				{
					tell_object(TP, "%^BOLD%^%^CYAN%^You should wait to see what happens first...%^RESET%^");
					return 1;
				}
				tell_room(TO, TPQCN + "%^BOLD%^%^YELLOW%^ walks over to "+
				"the "+lever+" wall and pulls the "+
				text_number(which) + " lever!%^BOLD%^%^BLUE%^.%^RESET%^", TP);
				tell_object(TP, "%^BOLD%^%^YELLOW%^You walk over to "+
				"the "+lever+" wall and pull the "+text_number(which)+
				" lever.%^RESET%^");
				TP->set_property("has_manipulated_button_or_lever", 1);
				call_out("manipulate_check", 2, TP, lever, "lever", which);
				return 1;
			default:
				tell_object(TP, "Try pulling one of the levers on the "+
				"north, east, south, or west wall.");
				return 1;
		}
		tell_object(TP, "You tried pulling the "+lever+" and number "+which);
		return 1;
	}
	tell_object(TP, "What do you want to pull?  There are eight levers here - "+
	"try <pull lever direction #>");
	return 1;
}

string display_rune()
{
	switch(runeform)
	{
		case 0:
			return "%^BOLD%^%^GREEN%^The runic symbols all over the floor of this room are currently "+
			"in the shape of a simple solid block of %^BOLD%^%^BLACK%^dark metallic material"+
			"%^BOLD%^%^GREEN%^.";
		case 1:
			return "%^RED%^The runic symbols all over the floor of this room are "+
			"currently in the shape of a vicious looking serpent, drawn back and "+
			"hissing, as if it is about to strike!%^RESET%^";
		case 2:
			return "%^BOLD%^%^WHITE%^The runic symbols all over the floor of this room "+
			"are currently in the shape of a very dangerous and jadded dagger, "+
			"that looks like it could reach out and stab into your chest "+
			"in an instant!%^RESET%^";
		case 3:
			return "%^BOLD%^%^BLUE%^The runic symbols all over the floor of this room "+
			"have taken an almost humanoid form, creating the likeness of an "+
			"obvious sorcerer, laughing manically as if he has lost his mind.%^RESET%^";
	}
}

void switch_runes()
{
	int oform;
	oform = runeform;
	runeform++;
	if(runeform > 3) runeform = 0;
	tell_room(TO, "%^YELLOW%^The %^BOLD%^%^CYAN%^r%^BOLD%^%^BLUE%^u"+
	"%^BOLD%^%^CYAN%^n%^BOLD%^%^BLUE%^i%^BOLD%^%^CYAN%^c symbols%^RESET%^%^YELLOW%^ "+
 	"complete a transformation - shifting from the likeness of "+
	RUNE_FORMS[oform] +"%^RESET%^%^YELLOW%^ into that of "+
	RUNE_FORMS[runeform] +"%^RESET%^%^YELLOW%^!%^RESET%^");
	speed = 50 + random(66);
	if(runeform == 3)
	{
		TO->set_property("wild magic", 75);
		TO->set_property("wild magic affect", ({"random", "random", 0}));
		TO->set_property("wild magic warning", "%^BOLD%^%^BLUE%^A manical laughter "+
		"fills your mind as your incantation is manipulated beyond your control!!%^RESET%^");
	}
	else
	{
		TO->remove_property("wild magic");
		TO->remove_property("wild magic affects");
		TO->remove_property("wild mgic warning");
	}	
	call_out("switch_runes", speed);
}

int query_rune_speed() 
{
	return speed;
}

int bone_search(object ob) 
{
	return 0;
}

int query_rune_form()
{
	return runeform;
}

int set_rune_form(int x)
{
	if(x < 0 || x > 3) return -1;
	runeform = x;
	return runeform;
}

void reset() 
{
	::reset();
	had_monster = 0;
   
}

		
