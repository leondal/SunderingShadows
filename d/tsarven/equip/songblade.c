// Song blade +4
// Thorn@ShadowGate
// 12/11/95
// Great Library
// songblade.c

#include <std.h>

inherit WEAPON;

void create() {
  ::create();
    set_name("Song Blade");
    set_id(({"sword","longsword","songblade"}));
    set("short","long sword");
    set_property("enchantment", 2);
    set_weight(4);
    set_size(2);
    set_wc(1,8);
    set_large_wc(1,12);
    set_type("slashing");
    set_value(125);
    set_wield_string("You mind fills with the deeds of ancient heroes.");
    set("read","Song is the blade of the true bard.\n");
    set_hit( (: this_object(), "weapon_hit" :) );
    set_destroy();
}
     
int weapon_hit(object ob) {
  int bonus;
  if(TP->is_class("bard")){
    tell_object(TP, "%^GREEN%^The sword seems to sing"+
		"as it slices "+ob->query_cap_name()+
		" with unimaginable might!\n");
    tell_room(environment(this_player()),
	      "%^RED%^"+this_player()->query_cap_name()+" strikes "+
	      " and his blade emits a note that"+
	      "seems to stun "+ob->query_cap_name()+"\n");
    ob->set_paralyzed(10);
    return 1;
  }
  return 1;
}

init() {
  ::init();
    add_action("sing", "sing");
  }

int sing() {
  object *inv;
  int i;

  inv = all_inventory(environment(TP));
  for(i=0;i<sizeof(inv);i++) {
    if(living(inv[i]) && inv[i] != TP) {
      tell_object(inv[i], wrap("You suddenly hear the first notes of a song"+
		  " begin to play.  As it progresses, the song strips "+
		  "away your fear, your anger, and your ambitions.  "+
		  "Soon, you are numbed totally, unable to move.\n"));
      inv[i]->set_paralyzed(30);
    }
  }
  return 1;
}
