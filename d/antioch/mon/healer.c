#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

int found = 0;

create() {
    ::create();
 set_name("healer");
 set_id( ({
    "healer", "man", "old man", "silver haired man", "silver haired old man"
 }) );
 set("race", "elf");
 set_gender("male");
 set("short",
    "A silver haired old man"
 );
  set_long(
@ANTIOCH
This old man has lived in the village for ages.  He, in fact, could
well be the first resident of the village, based on his age.
ANTIOCH
 );
 set_level( 12 );
 set_body_type("human");
   set("aggressive", 0);
   set_alignment( 1 );
   set_size( 2 );
    set_stats("intelligence", 17);
    set_stats("wisdom", 18);
    set_stats("strength", 14);
    set_stats("charisma", 9);
    set_stats("dexterity", 11);
    set_stats("constitution", 12);
    set_max_mp(0);
    set_mp(query_max_mp());
 set_hd(13, 4);
 set_max_hp(query_hp());
 set_max_sp(query_hp());
 set_sp(query_max_sp());
 set_wielding_limbs( ({ "right hand", "left hand" }) );
        new(WEAP+"sceptre")->move(this_object());
    command("wield sceptre");
 add_money("silver",random(10));
 add_money("copper",random(20));
   
}

void reset(){
  ::reset();
  found = 0;
}

void init(){
  ::init();
  add_action("search_room","search");
  add_action("help_player","ask");
}

int search_room(string str){
  if(!str){
    write("Search what?\n");
    return 1;
  }
  tell_object(this_player(),"%^MAGENTA%^The old man says: %^RESET%^What is it you are searching for, my friend?\n");
   tell_room(environment(this_player()),"You see the old man walk over to "+this_player()->query_cap_name()+" and say something quietly.\n",this_player());
  tell_object(this_player(),"%^MAGENTA%^The old man says: %^RESET%^Perhaps I can help you find it if you %^BOLD%^ask%^RESET%^ me.\n");
  return 1;
}

int help_player(string str){
  if(!str){
    tell_player(this_player(),"Try <ask man for ___> \n");
    return 1;
  }
  if(found==1){
    tell_object(this_player(),"%^MAGENTA%^The old man says: %^RESET%^Come back later for that, "+this_player()->query_cap_name()+".\n");
    return 1;
  }
  if(str=="man for element"){
    tell_object(this_player(),"%^MAGENTA%^The old man says: %^RESET%^Ahhh... yes... I believe I can help you, "+this_player()->query_cap_name()+".\n");
    tell_room(environment(this_player()),"The old man reaches into the fountain and it suddenly stops flowing!\n");
    new("/d/antioch/obj/water.c")->move(this_object());
    command("give element to "+this_player()->query_name());
    found = 1;
    return 1;
  }
  else{
    tell_object(this_player(),"%^MAGENTA%^The old man says: %^RESET%^Perhaps I cannot help you after all, my friend.\n");
    return 1;
  }
}
