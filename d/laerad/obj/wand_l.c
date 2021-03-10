//Coded by Bane//
#include <std.h>
#include <daemons.h>
inherit OBJECT;
int uses;
void create(){
    ::create();
    set_id(({"wand","iron wand","wand of lightning"}));
    set_name("wand of lightning");
    set_short("An iron wand");
    set_long(
	"This is a shiny iron wand. It is a tad rusty but looks to "+
	"be in decent condition. It is about a foot long. There is "+
	"a tiny inscription written on its handle."
    );
    set_weight(5);
    set_value(5000);
    uses = 0;
}
void init(){
    ::init();
    add_action("read","read");
    add_action("lightning","lightning");
    add_action("shockwave","shockwave");
}
void read(string str){
    string tmp;
    if(!str) return notify_fail("Read what?\n");
    if(!sscanf(str,"iron %s",tmp)) return 0;
    write("This is a wand of lightning, it has the following functions:\n"
	"lightning <name>: casts a lightning bolt at target(2 charges)\n"
	"shockwave: summons a massive lightning storm into the room."+
	"(7 charges)"
    );
    return 1;
}
void lightning(string str){
    object ob;
    if(uses > 99) return notify_fail("The wand is out of charges.\n");
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
   if(!query_wielded()) return notify_fail("Wield it first?\n");

    if(!str) return notify_fail("Lightning who?\n");
    if(!(ob = present(str, ETP))) return notify_fail("That isn't here!\n");
    if(!TP->is_class("mage") || !TP->is_class("bard") || !TP->is_class("cleric")) return notify_fail("Only spellcasters can use this wand.\n");
    new("/cmds/spells/l/_lightning_bolt")->use_spell(TP,ob,12,100,"mage");
    uses += 2;
    return 1;
}
void shockwave(){
    object *vars;
    int i;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!query_wielded()) return notify_fail("Wield it first?\n");
    vars = all_living(ETP);
    if(uses > 99) return notify_fail("The wand is out of charges.\n");
    uses += 7;
    tell_object(TP,"%^BOLD%^You point the wand to the sky and summon a massive storm of lightning!");
    TP->set_paralyzed(5,"You are busy right now!");
    for(i=0;i<sizeof(vars);i++){
	if(vars[i] != TP){
	tell_object(vars[i],"%^BOLD%^"+TP->query_cap_name()+" points a wand to the sky and summons a massive storm of lightning!",TP);
	}
	if(!"/daemon/saving_d"->saving_throw(vars[i],"spell")){
	    if(!TP->ok_to_kill(vars[i])) continue;
	    tell_object(vars[i],"You are nailed with a bolt of lightning!");
            vars[i]->do_damage(vars[i]->return_target_limb(),roll_dice(5,6));
	    vars[i]->add_attacker(TP);
	    vars[i]->continue_attack();
	} else {
	    tell_object(vars[i],"You are barely missed by a bolt of lightning.");
	}
    }
    return 1;
}
