//Coded by Bane//
#include <std.h>
inherit WEAPON;
int uses;
void create(){
    ::create();
    set_id(({"rod","alertness","rod of alertness","mace"}));
    set_name("rod of alertness");
    set_short("A mace");
    set_long(
	"This is a normal looking footmans mace.  It looks like "+
	"it was crafted very carefully though.  There is an "+
	"inscription written on its hilt."
    );
    set_weight(15);
    set_size(2);
    set_value(5000);
    set_type("bludgeoning");
    set_prof_type("mace");
    set_wc(1,6);
    set_large_wc(1,6);
    set_property("enchantment",1);
    set_wield( (:TO,"wield_me":) );
    set_unwield( (:TO,"unwield_me":) );
    uses = 0;
    set_heart_beat(1);
}
void init(){
    ::init();
    add_action("read","read");
    add_action("detect","detect");
    add_action("animate","animate");
}
void wield_me(){
    tell_object(TP,"You feel more secure.");
    TP->set_watched(50);
    return 1;
}
void unwield_me(){
    tell_object(TP,"You lose that secure feeling.");
    TP->set_watched(0);
    return 1;
}
void read(string str){
    if(!str) return notify_fail("Read what?\n");
    if(str != "mace" && str != "rod") return 0;
    write("This magic item is a Rod of Alertness, here is a list of its "+
	"special powers:\n"
	"%^BOLD%^The following dont use charges:%^RESET%^\n"
	"detect alignment on <name>: casts detect alignment on a target\n"
	"detect invisibility: checks the room for any invisible players\n"
	"%^BOLD%^The following power uses one charge per use:%^RESET%^\n"
	"animate <person|object|room>: casts animate object on a "
	"\n	players inventory or on an item in your own inventory "
	"\n	or on all non-living objects in a room."
    );
    return 1;
}
void detect(string str){
    string who;
    object ob, *inven;
//
    int i;
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(!TO->query_wielded()) return notify_fail("You have to wield the mace first.\n");
    if(!str) return notify_fail("Detect what?\n");
    if(sscanf(str,"alignment on %s",who)){
	if(!(ob = present(who, ETP))) return notify_fail("That is not here.\n");
	new("/cmds/spells/k/_know_alignment")->use_spell(TP,ob,16,100,"cleric");
	return 1;
    }
    if(str == "invisibility"){
	write("You concentrate on your surroundings.");
	write("The following living beings are invisible:");
	inven = all_living(ETP);
	for(i=0;i<sizeof(inven);i++){
	    if(inven[i]->query_invis()){
		if(wizardp(inven[i])) continue;
		write((string)inven[i]->query_short());
	    }
	}
	return 1;
    }
    return 0;
}
void animate(string str){
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(!TO->query_wielded()) return notify_fail("You have to wield the mace first.\n");
    if(uses > 49) return notify_fail("The mace is out of charges.\n");
    if(!str) return notify_fail("Animate what?\n");
    new("/cmds/spells/a/_animate_object")->use_spell(TP,str,16,100,"cleric");
    uses += 1;
    return 1;
}
void heart_beat(){
    if(!TO->query_wielded()) return 1;
    if(!living(ETO)) return 1;
    if((string)ETO->query_watched() < 50){
	ETO->set_watched(50);
    }
}
