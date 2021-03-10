//Coded by Bane//
//Added lore in response to a bug report. ~Circe~ 1/2/13
#include <std.h>
#include <daemons.h>
inherit OBJECT;
#define MAXUSES 50

int uses;

void create() {
    ::create();
    set_id(({"wand","maple wand"}));
    set_name("Maple wand");
    set_short("A twisted maple wand");
    set_long("This is a twisted maple wand about a foot in length.  It feels "+
            "warm to the touch and you notice a few runes engraved into it."
    );
    set_lore("This twisted wand is rumored to have been crafted by a formidable "
       "lich.  It is possible that the method of its manufacture died with the "
       "wizard himself, though some claim the knowledge has been retained in his "
       "grizzled head.  The wand is known to have paralytic properties for those "
       "who know how to use it.");
    set_property("lore difficulty",15);
    set_weight(5);
    set_value(5000);
    set_read("This is a wand of paralyzation.  To use its ability, you'll need to wield it and 'aim maple wand at target'.  The wand only has a limited number of charges so use it wisely.");
}

void init() {
    ::init();
    add_action("aim_wand","aim");
//    add_action("read_wand","read");
}

/* changed to use set_read too *Styx* 1/4/04
int read_wand(string str) {
    string tmp;
    if(!str) return notify_fail("Read what?\n");
    if(sscanf(str,"maple %s",tmp) != 1) return 0;
    write("This is a wand of paralyzation. To use its ability type 'aim maple wand at <target>'. The wand only has a limited number of charges so use it sparingly.");
    return 1;
}
*/

int aim_wand(string str) {
    string who;
    object ob;

    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
// making Hansoth not have to wield it since the wield requirement was added after it had been in game a while and he has weaponless functions *Styx*, 1/4/04, last change 9/15/03
    if(!query_wielded() && !TP->query_name() == "hansoth") 
	return notify_fail("You'll need to wield it first.\n");
    if(uses < MAXUSES) {
        if(!str) return notify_fail("You must designate a target!\n");
        if(sscanf(str,"maple wand at %s",who) != 1) return notify_fail("Wrong syntax.\n");
        if(!(ob = present(who,environment(TP)))){
            tell_room(ETP,"%^BOLD%^BLUE%^"+TP->query_cap_name()+" points a twisted maple wand and it fires a thin blue beam.",({TP}) );
            uses++;
            return 1;

        }
        tell_object(TP,"%^BOLD%^BLUE%^You point a twisted maple wand at "+ob->query_cap_name()+" and it fires a thin blue beam.");
        tell_room(ETP,"%^BOLD%^BLUE%^"+TP->query_cap_name()+" points a twisted maple wand and it fires a thin blue beam.",({TP}) );
        TP->set_paralyzed(7,"You are busy controlling the wand.");
      if(ob->query_property("no paralyze")) {
         tell_object(ob,"%^BOLD%^The beam disperses around you.");
         tell_room(ETP,"%^BOLD%^The beam disperses around "+ob->query_cap_name()+".",ob);
         uses +=1;
         return 1;
      }
        if(!"daemon/saving_d"->saving_throw(ob,"paralyzation_poison_death")) {
            tell_object(ob,"%^BOLD%^You are paralyzed by the beam!");
            tell_room(ETP,"%^BOLD%^"+ob->query_cap_name()+"'s body becomes rigid.",ob);
            ob->set_paralyzed(50,"Your muscles won't budge.");
        }
        else {
            tell_object(ob,"%^BOLD%^The beam disperses around you.");
            tell_room(ETP,"%^BOLD%^The beam disperses around "+ob->query_cap_name()+".",ob);
        }
        uses += 1;
        return 1;
    }
    else{
        set_value(0);
        write("The wand is out of charges.");
    }
    return 1;
}
