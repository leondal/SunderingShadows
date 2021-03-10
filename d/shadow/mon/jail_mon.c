inherit "/std/monster";

create() {
   ::create();
   set_name("jail thing");
   set_property("knock unconscious",1);
   set_gender("male");
   set_alignment(6);
   set("aggressive",1);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",3);
   set_stats("charisma",3);
   set_stats("dexterity",8);
   set_stats("constitution",7);
   set_hd(4,1);
   set_exp(25);
   set_hp(25);
   set_max_hp(query_hp());
   set_overall_ac(10);
   switch(random(4)) {
      case 0..1 :   make_rat();      break;
      case 2 :   make_thief();    break;
      case 3 :   make_person();   break;
   }
}

void make_rat() {
   set_name("rat");
   set_id( ({ "rat"}) );
   set_short("A big rat");
   set("long", "A big, flea-ridden, dirty rat.\n");
   set_race("rat");
   set_body_type("quadruped");
   set_size(1);
   set_emotes(1, ({"The rat scurries across the floor.", 
      "The rat gnaws on the straw in the bed.", 
      "The rat leaves a trail of excrement on the bed.",
      "The rat pokes around the room and gnaws on everything it finds." 
   }), 0 );
}

void make_thief() {
   set_name("prisoner");
   set_id( ({ "thief", "prisoner", "human"}) );
   set_short("A dirty, raggedly-clothed human");
   set("long", "This dirty, raggedly-clothed man has unkempt, greasy black "
     "hair and a shaggy beard.  His dull brown eyes are blood-shot and it "
     "looks like he's down on his luck to say the least.");
   set_race("human");
   set_body_type("human");
   set_size(2);
   set_class("thief");
   set_mlevel("thief",2);
   add_search_path("/cmds/thief");
   set_thief_skill("pick pockets", 10);
   toggle_steal();
   set_emotes(1, ({"The dirty human fidgets and scratches his beard.", 
     "The dirty, raggedly-clothed human pokes around in the straw as if searching for something.", 
     "The dirty, raggedly-clothed human seems to be sizing you up.", 
     "The dirty human paces the floor.", 
     "The dirty, raggedly-clothed human %^BOLD%^%^MAGENTA%^vomits%^RESET%^ in the corner.",
   }), 0 );
}

void make_person() {
   set_name("prisoner");
   set_id( ({ "human", "prisoner"}) );
   set_short("A frail human male");
   set("long", "A frail human male has dull grey eyes and sandy brown hair.  "
     "He is wearing simple clothing that does little to conceal how slight "
     "his build is.  He looks frail to the point of being unhealthy.");
   set_race("human");
   set_body_type("human");
   set_size(2);
   set_emotes(1, ({"The frail human male coughs and wheezes.", 
      "The frail human male digs at his fingernails.", 
      "The frail human male dozes off and snores loudly.", 
      "The frail human male mumbles under his breath and curses goblins.", 
      "The frail human male coughs and spits a %^GREEN%^green glob%^RESET%^ on the floor."
   }), 0 );
}
