//Coded by Bane//
#include <std.h>
#include <daemons.h>
inherit OBJECT;
#define MAXUSES 50
int uses;
void create(){
    ::create();
    set_id(({"wand","oak wand"}));
    set_name("Oak wand");
    set_short("A twisted oak wand");
    set_long(
	"This is a twisted oak wand about a foot in length. It feels "+
	"warm to the touch. You notice a few runes engraved into it, "+
	"try reading the oak wand."
    );
    set_weight(5);
    set_value(10000);
}
void init(){
    ::init();
    add_action("aim_wand","aim");
    add_action("read_wand","read");
}
int read_wand(string str){
    string tmp;
    if(!str) return notify_fail("Read what?\n");
    if(sscanf(str,"oak %s",tmp) != 1) return 0;
    write("This is a wand of fear. To use its ability type 'aim oak wand at <target>'. The wand only has a limited number of charges so use it sparingly.");
    return 1;
}
int aim_wand(string str){
    string who;
    object ob;
   if(!query_wielded()) return notify_fail("Wield it first?\n");
    if(uses < MAXUSES){
	if(!str) return notify_fail("You must designate a target!\n");
	if(sscanf(str,"oak wand at %s",who) != 1) return notify_fail("Wrong syntax.\n");
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

	if(!(ob = present(who,environment(TP)))) return notify_fail("That isn't here!\n");
	tell_object(ob,"%^BOLD%^CYAN%^"+TP->query_cap_name()+" points a twisted oak wand at you and it fires a thin cyan beam.");
	tell_object(TP,"%^BOLD%^CYAN%^You point a twisted oak wand at "+ob->query_cap_name()+" and it fires a thin cyan beam.");
	tell_room(ETP,"%^BOLD%^CYAN%^"+TP->query_cap_name()+" points a twisted oak wand at "+ob->query_cap_name()+" and it fires a thin cyan beam.",({ob,TP}));
	TP->set_paralyzed(7,"You are busy.");
     	if(!"daemon/saving_d"->saving_throw(ob,"paralyzation_poison_death")){
	    tell_object(ob,"%^BOLD%^You are overcome with a horrible fear!");
	    tell_room(ETP,"%^BOLD%^"+ob->query_cap_name()+" is overcome with a horrible fear!",ob);
	    ob->run_away();
 	    ob->run_away();
	    ob->run_away();
	    ob->run_away();
	    ob->run_away();
	    ob->run_away();
	    ob->run_away();
	    ob->run_away();
	    ob->run_away();
	    ob->run_away();
	    ob->run_away();
	    ob->run_away();
	    uses += 1;
	    return 1;
	    } else {
	    tell_object(ob,"%^BOLD%^The beam disperses around you.");
	    tell_room(ETP,"%^BOLD%^The beam disperses around "+ob->query_cap_name()+".",ob);
	    uses += 1;
	    return 1;
	}
    }
    if(uses > 49){
	set_value(0);
    }
    write("The wand is out of charges.");
    return 1;
}
