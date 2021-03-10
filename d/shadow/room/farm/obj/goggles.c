#include <std.h>
inherit ARMOUR;

void create(){
	::create();
      set_name("goggles");
     	set_id(({ "goggles", "gnomish goggles" }));
      set_short("%^BOLD%^%^GREEN%^Gnomish %^YELLOW%^Goggles%^RESET%^");
      set_obvious_short("%^BOLD%^%^GREEN%^A pair of goggles with green lenses%^RESET%^");
      set_long( "%^YELLOW%^Made mostly from leather, these goggles "+
		"are fashioned to fit over the wearer's eyes.  Thick"+
		" %^GREEN%^green crystal%^YELLOW%^ lenses have "+
		"been inserted into the "+
		"eye sockets of the goggles, giving them a strange "+
		"appearance.  Attached to the outer edges of the "+
		"goggles are a series of three round lenses.  "+
		"The lenses are made where they can be pushed "+
		"down over the green lenses of the goggles.  "+
		"The first pair of lenses is made from %^WHITE%^clear "+
		"quartz%^YELLOW%^.  The second pair is made from%^MAGENTA%^ rose "+
		"quartz %^YELLOW%^and the final lenses are crafted from "+
		"%^BLACK%^smoky quartz%^YELLOW%^.%^RESET%^\n");
      set_weight(5);
      set_value(75);
      set_lore("%^YELLOW%^Another one of Piaf Huffelmuffin's fine creation"+
		" are the Gnomish Goggles.  Piaf claims that the %^GREEN%^"+
		"green crystal %^YELLOW%^lenses of the goggles "+
		"helps him to see better"+
		" when in his workshop.  After a lengthy conversation "+
		"that lasted nearly six hours, Piaf relayed to me about"+
		" the effects of the other crystal lenses.  The "+
		"%^WHITE%^clear quartz %^YELLOW%^ones he claims "+
		"allows him to be able to see any "+
		"magical auras on an item.  The %^BLACK%^smoky "+
		"quartz %^YELLOW%^ones he "+
		"says aids him in spotting hidden objects in his "+
		"workshop.  As for the %^MAGENTA%^rose quartz%^YELLOW%^"+
		" lenses, he claims "+
		"they help in finding 'those dreaded dust bunnies!', "+
		"something that seems to anger him greatly. - An"+
		" Observation of Piaf - Theadora Illonium");
      set_property("lore difficulty",7);
      set_type("clothing");
      set_limbs(({ "head" }));
      set_size(1);
   	set_ac(0);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
   set_property("repairtype",({ "jewel" }));
	set_item_bonus("sight bonus",1);
	set_property("powder deflect",90);
}
void init()
{
        add_action("look_at","look");
}

int wear_func()
{
        tell_object(ETO,"%^BOLD%^%^GREEN%^You peer at the world"+
		" through the cloudy green lenses of the goggles.");
        return 1;
}

int remove_func()
{
        tell_object(ETO,"%^BOLD%^%^GREEN%^You blink a few times,"+
		" enjoying the fact that you can see clearly now.");
        return 1;
}

int look_at(string str)

{
        if(!query_worn()) {
                return 0;
        }
        else {
                tell_object(ETO,"%^BOLD%^%^GREEN%^You look at the world"+
			" through the cloudy lenses of the goggles.");
	return 0;
	}
}
