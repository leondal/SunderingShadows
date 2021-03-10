//Coded by Bane//
//Added lore and new desc and updated older code - Cythera 3/27/05
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    	set_id(({"net","net of entrapment"}));
    	set_name("net of entrapment");
    	set_obvious_short("%^BOLD%^%^BLACK%^A small black net%^RESET%^");
	set_short("%^BOLD%^%^BLACK%^Net of %^GREEN%^Entrapment%^RESET%^");
    	set_long("%^BOLD%^%^BLACK%^Woven from black silk rope, this large"+
		" net is used to peacefully capture game or criminals.  "+
		"The ends of the net are weighted down with %^BLUE%^iron "+
		"spheres%^BLACK%^, making sure one has a difficult time "+
		"when they are trapped inside.  The large net is typically"+
		" folded up till needed and then thrown at the target.  "+
		"%^GREEN%^Green%^BLACK%^ hemp rope binds the black silk"+
		" rope weaving together, giving some stability to the net."+
		"\n\n%^GREEN%^<throw net at name>%^RESET%^");
	set_lore("Long has man searched for the need to find more peaceful"+
		" means to capture criminals and bring them back to trial."+
		"  A young ranger of Tyr first started to use nets to capture"+
		" those wanted for their crimes.  The ranger, Yathar, had one"+
		" of the highest success rates as a bounty hunter with the "+
		"church of Tyr.  His famous nets soon seeped out into the "+
		"world.  Little did he know his invention would be put to "+
		"more uses than he even dreamed of.");
	set_property("lore difficulty",8);
    	set_weight(10);
    	set_value(1500);
    	set_size(1);

}


int thrown_hit(object ob) 
{
    if(TP->query_paralyzed())
    {
        return 1;
    }
    if(ob->query_true_invis()) //added to prevent random flying nets hitting immortals - Ares
    {
        ob->remove_attacker(TP);
        TP->remove_attacker(ob);
        return 1;
    }
    tell_object(ob,"%^BOLD%^GREEN%^"+TP->QCN+" tosses a magical net over you!");
    tell_object(TP,"%^BOLD%^GREEN%^You toss a magical net over "+ob->QCN+"!");
    tell_room(ETP,"%^BOLD%^GREEN%^"+TP->QCN+" tosses a magical net over "+ob->QCN+"!",({ob,TP}));
	
	/*Trip duration changed by Saide - in an effort to keep them useful but not make
	them too powerful.  Modify as needed.  10 / 04 / 03 - last change was 9 / 20 / 02*/

	//ob->set_tripped(random(3)+4, "You are struggling to break free from the net!");
    TP->set_paralyzed(2,"You're busy throwing the net.");
    ob->set_tripped(roll_dice(2,3), "You are struggling to break free from the net!");
    TO->remove();
    return 1;
}

/*//don't need this if the net stuns while throwing -Ares
int get() {
   if (TP->query_paralyze() || TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("combat",TP);
      return 0;
   }
//  TP->set_paralyzed(6,"You are busy folding the net for a second throw.");
  TP->setAdminBlock(3);
  write("You begin folding the net back up.");
   message("combat","%^BOLD%^%^GREEN%^"+TPQCN+" begins folding a magic"+
		" net back up as "+TP->QS+" takes it.",ETP,({TP}));
  return 1;
}*/
