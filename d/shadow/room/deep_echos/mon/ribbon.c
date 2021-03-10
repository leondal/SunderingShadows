//dancing dress summoned by weapon
#include <std.h>
inherit "/std/monster";
string *dances;
create() {
    ::create();
    set_name("dress");
    set("id", ({ "dress" }));
	if(random(2)==0){
      set("short", "%^BOLD%^%^WHITE%^a glowing white dress%^RESET%^");
      set("long", "This glowing white dress dances about."+
	     "  It looks to be formed from a collection of ribbons.");
	  dances = ({
       "%^BOLD%^%^WHITE%^The empty dress dances about.",
       "%^BOLD%^%^WHITE%^The dress spins about elegantly.",
	   "%^BOLD%^%^WHITE%^The dress bows in an graceful dip.",});
	}
	else{
	  set("short", "%^BOLD%^%^BLACK%^a glowing black dress%^RESET%^");
      set("long", "This glowing black dress dances about. "+
	  " It looks to be formed from a collection of ribbons.");
	  dances = ({
       "%^BOLD%^%^BLACK%^The empty dress dances about.",
       "%^BOLD%^%^BLACK%^The dress spins about elegantly.",
	   "%^BOLD%^%^BLACK%^The dress bows in an graceful dip.",});
	}

	add_search_path("/cmds/mortal");
	set_stats("wisdom", 3);
    set_stats("strength", 3);
    set_stats("charisma", 25);
    set_stats("dexterity", 3);
    set_stats("constitution", 3);
	set_hd(2,1);
    set_level(1);
    set_class("thief");
    set_body_type("humanoid");
    set_alignment(5);
    set("race", "dress");
    set_exp(0);
    set_gender("female");
    set_ac(1);
    set_max_hp(60);
    set_hp(60);
    if(clonep(TO)) call_out("remove",40);

}
void dance(){

  if(!objectp(ETO)) return;  //dancing spams debug.log, trying to fix

  tell_room(ETO,dances[random(3)]);
}
void heart_beat(){
  ::heart_beat();
  dance();
}

int remove() {
    if(!objectp(TO) || !objectp(ETO)) return ::remove();
    tell_room(ETO,"%^BOLD%^%^WHITE%^"+
	  "The dress falls apart into a pile of ribbons "+
	  "and disappears.");
    return ::remove();
}
void die(object ob){
remove();
}
