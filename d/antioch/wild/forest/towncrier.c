inherit "/std/monster";

void create() {
    ::create();
    set_name("towncrier");
    set("id", ({ "towncrier", "a towncrier", "crier" }) );
    set("short", "A towncrier");
    set("long", "This is a towncrier hired by a wizard to inform "
    		"players on upcoming changes and/or danger. "
    		"%^YELLOW%^Please do not attack him.\n" );
    set("race", "human" );
    set_gender("male");
    set_body_type("human");
    set_hd( 16,7 );
    set_overall_ac( 9 );
    set_size( 2 );
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    set_max_hp(150);
    set_max_mp(400);
    set_exp(10);
    //set_lang_prof("human",7);
    set_stats("strength",18);
    set_stats("constitution", 18);
    set_stats("intelligence", 18);
    set_stats("dexterity", 18);
    set_stats("wisdom", 18);
    set("aggressive", 0);
    set_spell_chance(33);
    set_spells( ({ "missile", "shock", "fireball" }) );
}
void catch_tell(string str) {
   if(interact("enters", str)) {
      call_out("reply_back",1);
   }
}

void init() {
  ::init();
  environment(this_object())->set_property("no magic",1);
  environment(this_object())->set_property("no steal",1);
  environment(this_player())->set_property("no attack",1);
}

void reply_back(){
   tell_room(environment(this_object()), "%^MAGENTA%^The towncrier "+
      "says%^RESET%^: "+
      "Hello, great adventurer.\n The wizard who hired me asked me "+
      "to inform everyone who passes this trail that : in near "+
      "future, a lot of new rooms will be added to this place.",
      this_object() );
}
