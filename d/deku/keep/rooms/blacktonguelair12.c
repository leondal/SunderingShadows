#include <std.h>
#include "../keep.h"
inherit VAULT;
int one_replaced;

void create() 
{
	::create();
    	set_property("no teleport",1);
    	set_property("light",0);
    	set_property("indoors",1);
    	set_property("no sticks",1);
    	set_name("haphazard throne room");
    	set_short("%^BOLD%^%^WHITE%^Haphazard Throne Room%^RESET%^");
    	set_terrain(BUILT_TUNNEL);
    	set_travel(PAVED_ROAD);
    	set_long("%^BOLD%^%^WHITE%^This chamber serves as a haphazard throne "+
	"room, it is made from solid %^BOLD%^%^BLACK%^marble%^BOLD%^"+
	"%^WHITE%^.  A massive %^YELLOW%^gold throne%^BOLD%^%^WHITE%^ sits "+
	"against the northern wall of this room.  On either side of the "+
    	"%^YELLOW%^throne%^BOLD%^%^WHITE%^ are %^RESET%^%^WHITE%^silver "+
	"%^RED%^torch %^BOLD%^%^WHITE%^holders which have been set into "+
	"the floor.  The floor of this room is completely level and "+
	"remarkably well kept.  %^CYAN%^Hieroglyphic symbols "+
    	"%^BOLD%^%^WHITE%^decorate the eastern and western walls of this room.  Inset "+
    	"directly into the center of the southern wall are heavy %^YELLOW%^gold double "+
    	"doors%^BOLD%^%^WHITE%^.%^RESET%^");

    	set_smell("default","The stench of decay lingers here.");
    	set_listen("default","Growls echo from deep within the darkness.");
    
    	set_exits(([
        	"south": KEEPR + "blacktonguelair11",
    	] ));

    	set_door("gold double doors",KEEPR + "blacktonguelair11","south");
    	set_string("gold double doors", "open", "%^RED%^The massive gold doors "+
	"swing open with suprising ease.%^RESET%^");
    	set_door_description("gold double doors","%^YELLOW%^These heavy gold doors "+
	"are made from solid gold.  A massive upright wolf-like creature is "+
	"engraved into the center of them.%^RESET%^");
    	set_items(([
        ({"hieroglyphics","hieroglyphic symbols","hieroglyphic symbol",
	  "symbols","hieroglyphic"}) : "%^BOLD%^%^BLACK%^These symbols "+
		"depict numerous wolf-like creatures kneeled before a massive "+
		"wolf-like creature seated on a %^YELLOW%^golden%^BOLD%^"+
		"%^BLACK%^ throne and garbed with an %^BLUE%^obsidian%^BOLD%^"+
		"%^BLACK%^ robe.  An uneasy feeling stirs within you.%^RESET%^",
        ({"floor","Floor"}) : "%^BOLD%^%^WHITE%^The floor of this room "+
		"is completely level and suprisingly well kept.%^RESET%^",
        ({"walls","wall"}) : "%^BOLD%^%^WHITE%^The eastern and western walls "+
		"of this room are decorated with hieroglyphic symbols.  "+
		"Inset into the southern wall are heavy %^RESET%^%^WHITE%^iron "+
		"double doors%^BOLD%^%^WHITE%^.  Inset into the northern wall "+
		"are heavy %^YELLOW%^gold double doors%^BOLD%^%^WHITE%^.%^RESET%^",
        ({"throne","gold throne","golden throne",
		"massive gold throne","massive throne"}) : "%^YELLOW%^This massive "+
		"throne is made from solid gold.  It is covered with dirt and "+
		"grime from ages of use without proper cleaning.  There are "+
		"several orifices at the top of it which are empty.  You "+
		"think they may have once contained gems.%^RESET%^",
        ({"torch holder","torch holders"}) : "%^RED%^These torch holders "+
		"are made from pure %^RESET%^%^WHITE%^silver%^RED%^.  They are "+
		"empty and provide no light.%^RESET%^",
    	]));
		
}

void init() 
{
	::init();
    	//add_action("replace_fun","replace");
}

//I should use this function for something sometime soon - I really like the idea of there 
//being a treasure room with items - maybe make it so only there do the items load and 
//only some?  I dunno yet - Saide 11/09/03

void open_room(object who,int when)
{
	switch(when) 
	{
    		case(0):
        tell_room(environment(who),"%^RED%^A loud rumbling echoes from every wall of the room!");
        break;
    case(2):
        tell_room(environment(who),"%^BLUE%^A loud grating sound echoes from behind the "+
        "throne!%^RESET%^");
        break;
    case(4):
        if(random(20)) {
            tell_room(environment(who),"%^YELLOW%^The throne slides to the side, revealing "+
            "a hidden chamber!");
            TO->add_exit(KEEPR +"treasureroom1","north");
            break;
        }
        else {
            tell_room(environment(who),"%^RED%^As suddenly as they began the strange loud "+
            "noises cease.");
            break;
        }
        break;
    }
    if(when < 4) {
        when++;
        call_out("open_room",0,who,when);
        return;
    }
    else {
        return;
    }

}
			

int torch_state(string str)
{
	if(!str) 
	{
      	tell_object(TP,"YOU SHOULD NEVER SEE THIS, NOTIFY %^YELLOW%^SAIDE%^RESET%^ "+
        	"IMMEDIATELY!");
        	return 1;
    	}
    	add_item("torch holder","%^RED%^These torch holders are made from pure %^RESET%^"+
    	"%^WHITE%^silver%^RED%^.  "+str+ "%^RESET%^");
    	add_item("torch holders","%^RED%^These torch holders are made from pure %^RESET%^"+
    	"%^WHITE%^silver%^RED%^.  "+str+ "%^RESET%^");
    	return 1;
}

int replace_fun(string str)
{
	object ob;
    	string tstate;
    	if(!str) 
	{
      	tell_object(TP,"What do you want to replace?");
        	return 1;
    	}
    	if(str != "torch") 
	{
      	tell_object(TP,"You could try replacing the missing torches.");
        	return 1;
    	}
    	if(str == "torch" && !present("torch",TP)) 
	{
      	tell_object(TP,"You have no torch to place in the holder!");
        	return 1;
    	}
    	if(ob = present("torch",TP)) 
	{
        if(one_replaced == 0) {
        ob->remove();
        tell_object(TP,"%^RED%^You replace one of the missing torches!%^RESET%^");
        tell_room(environment(TP),TPQCN + "%^RED%^ replaces one of the missing "+
        "torches!%^RESET%^",TP);
        one_replaced = 1;
        tstate = "One of them burns brightly, while the other provides no light.";
        torch_state(tstate);
        return 1;
        }
        if(one_replaced == 1) {
            ob->remove();
            tell_object(TP,"%^RED%^You replace the second missing torch!%^RESET%^");
            tell_room(environment(TP),TPQCN + "%^RED%^ replaces the final missing "+
            "torch!%^RESET%^",TP);
            tstate = "Both of them burn %^CYAN%^brightly%^RED%^ now, each proudly "+
            "carrying a torch.";
            torch_state(tstate);
            one_replaced = 2;
            call_out("open_room",0,TP,0);
            return 1;
        }
        else {
            tell_object(TP,"%^RED%^Both of the torch holders are already filled!%^RESET%^");
            return 1;
        }
    }

}

void reset()
{
	int x;
    	::reset();

    	if(!present("massive werewolf")) 
	{
      	for(x = 0;x < 3;x++) 
		{
            	new(KEEPM + "massivewerewolf")->move(TO);
        	}
    	} 
    	if(!present("lord blacktongue")) 
	{
      	new(KEEPM + "lordblacktongue")->move(TO);
    	}
}
