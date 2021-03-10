//  Created by Grayhawk@Shadowgate
//  Nov. 14, 1995

inherit "/std/Object";

int num;

object ob;

create() {
  ::create();
  set_name("mirror");
  set_id(({"mirror","large mirror"}));
  set_short("%^BOLD%^%^MAGENTA%^A large mirror%^RESET%^");
  set_long("%^RESET%^%^MAGENTA%^This large %^RESET%^mirror%^RESET%^%^MAGENTA%^ is set in a nicely carved %^ORANGE%^oak frame%^RESET%^%^MAGENTA%^. "+
	     "You see a reflection of yourself, or something "+
	     "that looks like you. You find yourself wanting to %^RED%^stare%^RESET%^ "+
	     "at the mirror!%^RESET%^\n\n");
  set_weight(500);
  set_value(10000);
  num = 1;
}

void init() {
  ::init();
  add_action("stare","stare");
}

void reset() {
  ::reset();
  if(num == 0) {
    num = 1;
  }
}

int stare(string str) {
  //object TP = this_player();
  if(!str) {
    tell_room(environment(TP), "%^GREEN%^"+TP->query_cap_name()+" stares into space.");
    tell_object(TP, "You start staring into space!");
    return 1;
  }
  if(str != "at mirror") {
    tell_room(environment(TP), "%^RED%^"+TP->query_cap_name()+" starts staring at "+str+" but nothing happens!");
    tell_object(TP, "You start staring at "+str+" and nothing happens!");
    return 1;
  }
  if(TP->query_level() < 5) {
    tell_object(TP, "You start staring at the mirror but only see your reflection!");
    say("%^MAGENTA%^"+TP->query_cap_name()+" starts staring at the mirror but you only see their reflection!");
    return 1;
  }
  if(num != 1) {
    tell_object(TP, "You start staring at the mirror but only see your reflection!");
    say("%^CYAN%^"+TP->query_cap_name()+" starts staring at the mirror but you only see their reflection!");
    return 1;
  }
  if(str == "at mirror") {
    tell_object(TP, "%^RED%^You start staring at the mirror and notice that your\n"+
		    "reflection is starting to move. Before you know what\n"+
		    "happened, the reflection becomes alive and attacks you!\n\n");
    say("%^GREEN%^"+TP->query_cap_name()+" starts to stare at the mirror, and\n"+
		"before you know what happens, the reflection of "+TP->query_cap_name()+"\n"+
		"becomes alive and attacks!!");
    ob = new("/std/monster");
    ob->set_name("reflection");
    ob->set("id",({TP->query_cap_name()+"'s reflection", "reflection"}));
    ob->set("short", TP->query_cap_name()+"'s reflection");
    ob->set("long", "This is an evil reflection of "+TP->query_cap_name()+".\n");
    ob->set("race", TP->query_race());
    ob->set_gender(TP->query_gender());
    ob->set_body_type(TP->query_body_type());
    ob->set_hd(TP->query_hd());
    ob->set_level(TP->query_level());
    ob->set_size(TP->query_size());
    ob->set_wielding_limbs(TP->query_wielding_limbs());
    ob->set_max_hp(TP->query_max_hp());
    ob->set_hp(TP->query_max_hp());
    ob->set_max_sp(TP->query_max_sp());
    ob->set_sp(TP->query_max_sp());
    ob->set_stats("strength", TP->query_stats("strength"));
    ob->set_stats("dexterity", TP->query_stats("dexterity"));
    ob->set_stats("constitution", TP->query_stats("constitution"));
    ob->set_stats("charisma", TP->query_stats("charisma"));
    ob->set_stats("intelligence", TP->query_stats("intelligence"));
    ob->set_stats("wisdom", TP->query_stats("wisdom"));
ob->set_class(TP->query_class());
    ob->set_overall_ac(TP->query_ac());
    ob->set("aggressive", 20);
    ob->set_spell_chance(TP->query_spell_chance());
    ob->set_spells(TP->query_spells());
    ob->set_languages(TP->query_languages());
    ob->set_lang_prof(TP->query_lang_prof());
    ob->set_alignment(TP->query_alignment());
    ob->set_exp(1000);
    ob->move(environment(this_object()));
    num = 0;
    return 1;
  }
  return 1;
}
