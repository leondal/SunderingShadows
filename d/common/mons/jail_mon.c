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
   switch(random(7)) {
      case 0..1 :   make_rat();      break;
      case 2 :   make_thief();    break;
      case 3 :   make_person();   break;
      case 4 :   make_thief2();	  break;
      case 5 :   make_sicky();    break;
      case 6 :   make_goblin();	  break;
   }
}

void make_rat() {
   set_name("rat");
   set_id( ({ "rat"}) );
   set_short("%^RESET%^%^ORANGE%^A big rat%^RESET%^");
   set_long("%^ORANGE%^A big, flea-ridden, dirty rat with filthy fur.\n");
   set_race("rat");
   set_body_type("quadruped");
   set_size(1);
   set_emotes(1, ({"The rat scurries across the floor.", 
      "The rat gnaws on the straw in the bed.", 
      "The rat leaves a trail of excrement in the straw.",
      "The rat pokes around the room and gnaws on everything it finds." 
   }), 0 );
}

void make_thief() {
   set_name("prisoner");
   set_id( ({ "thief", "prisoner", "human"}) );
   set_short("A dirty, raggedly-clothed human");
   set_long("This dirty, raggedly-clothed man has unkempt, greasy black "
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

void make_thief2() {
   set_name("prisoner");
   set_id( ({ "thief", "prisoner", "human"}) );
   set_short("A rough looking male human");
   set_long("%^ORANGE%^This %^BOLD%^%^BLACK%^rough%^RESET%^%^ORANGE%^ "
	"looking man is exactly the sort of person you'd expect to find "
	"in a place like this.  His skin is %^GREEN%^encrusted%^ORANGE%^ "
	"with %^RESET%^dirt%^ORANGE%^, and %^RED%^scars%^ORANGE%^ mar his "
	"already ugly face.  He looks pretty %^BOLD%^%^BLACK%^decrepit"
	"%^RESET%^%^ORANGE%^ now but you imagine there was a time when he "
	"could hold his own out in the streets.  His %^BOLD%^%^BLACK%^black "
	"hair%^RESET%^%^ORANGE%^ hasn't seen a comb for weeks, and he is "
	"constantly itching at his rugged beard which now houses a variety "
	"of %^GREEN%^bugs%^ORANGE%^ and %^GREEN%^gri%^ORANGE%^m%^GREEN%^e"
	"%^ORANGE%^.  His %^RED%^blo%^RESET%^o%^RED%^dshot %^ORANGE%^eyes "
	"glimmer with %^RED%^malice%^ORANGE%^ and he doesn't appear to "
	"have slept in ages.%^RESET%^");
   set_race("human");
   set_size(2);
   set_class("thief");
   set_mlevel("thief",2);
   add_search_path("/cmds/thief");
   set_thief_skill("pick pockets", 10);
   toggle_steal();
   set_emotes(1, ({"The prisoner sits down on a pile of %^ORANGE%^straw%^RESET%^ and begins to mutter to himself.%^RESET%^", 
     "The prisoner looks out the %^BOLD%^grate%^RESET%^ and starts to %^YELLOW%^bang loudly%^RESET%^ on the door with his fist.%^RESET%^", 
     "The prisoner sighs %^MAGENTA%^mo%^RED%^u%^MAGENTA%^rnfull%^RED%^y%^RESET%^.", 
     "%^BOLD%^%^BLACK%^The prisoner itches at his %^RESET%^%^ORANGE%^lice-ridden%^BOLD%^%^BLACK%^ hair.%^RESET%^", 
        }), 0 );
}

void make_sicky() {
   set_name("prisoner");
   set_id( ({ "prisoner", "half-elf"}) );
   set_short("A frail half-elf");
   set_long("%^BOLD%^%^BLACK%^Frail and weak, this man has certainly "
	"seen better days.  His bones jut out awkwardly from beneath a "
	"%^RESET%^pale%^BOLD%^%^BLACK%^ layer of flesh and his entire "
	"body shivers uncontrollably.  His bald head and shallow cheeks "
	"are damp and hot with %^RESET%^%^RED%^fe%^MAGENTA%^v%^RED%^er"
	"%^BOLD%^%^BLACK%^.  His thin, ragged beard is covered with dried "
	"%^RESET%^%^GREEN%^v%^ORANGE%^o%^GREEN%^m%^ORANGE%^i%^GREEN%^t"
	"%^BOLD%^%^BLACK%^, and he is barely strong enough to hold his "
	"eyes open.%^RESET%^");
   set_race("half-elf");
   set_size(2);
   set_class("mage");
   set_mlevel("mage",2);
   set_emotes(1, ({"The frail half-elf curls up on a pile of straw and groans in %^RED%^anguish%^RESET%^.",
     "The frail half-elf tries to stand but falls weakly to his knees.", 
     "The frail half-elf rambles %^RED%^feverishly%^RESET%^ about his starving wife and children.", 
     "The frail half-elf limps weakly as he goes to the corner and relieves himself.", 
     "%^BOLD%^%^BLACK%^The frail half-elf wipes some %^RESET%^%^ORANGE%^dirt%^BOLD%^%^BLACK%^ and %^RESET%^%^GREEN%^snot%^BOLD%^%^BLACK%^ off his nose with the back of his hand.%^RESET%^",
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
   set_size(2);
   set_emotes(1, ({"The frail human male coughs and wheezes.", 
      "The frail human male digs at his fingernails.", 
      "The frail human male dozes off and snores loudly.", 
      "The frail human male mumbles under his breath and curses goblins.", 
      "The frail human male coughs and spits a %^GREEN%^green glob%^RESET%^ on the floor."
   }), 0 );
}

void make_goblin() {
   set_name("prisoner");
   set_id( ({ "goblin", "prisoner"}) );
   set_short("A filthy goblin");
   set_long("%^BOLD%^%^BLACK%^Beady %^RESET%^%^RED%^red eyes%^BOLD%^%^BLACK%^ "
	"peer out from stringy black hair piled on top of the goblin's head.  "
	"A perpetual, %^RESET%^de%^BOLD%^%^BLACK%^r%^RESET%^ange%^RESET%^"
	"%^ORANGE%^d%^BOLD%^%^BLACK%^ grin reveals this creature's sharp "
	"%^RESET%^fangs%^BOLD%^%^BLACK%^ behind its %^RESET%^%^RED%^blood-"
	"encrusted lips%^BOLD%^%^BLACK%^.  It is dressed in little more than "
	"%^RESET%^%^ORANGE%^dirty%^BOLD%^%^BLACK%^ rags, and a constant "
	"swarm of %^RESET%^%^GREEN%^bugs%^BOLD%^%^BLACK%^ buzz around it.  "
	"The pale %^YELLOW%^yellow flesh%^BLACK%^ looks dirty and rough, and "
	"is marked with %^RESET%^cuts%^BOLD%^%^BLACK%^ and %^RESET%^"
	"%^MAGENTA%^sc%^RED%^r%^MAGENTA%^ap%^RED%^e%^MAGENTA%^s%^BOLD%^%^BLACK%^ "
	"along with old scars.%^RESET%^");
   set_race("goblin");
   set_size(1);
   set_emotes(1, ({"%^YELLOW%^The goblin picks a bug out of its stringy hair and eats it hungrily.%^RESET%^", 
      "%^BOLD%^%^BLACK%^The goblin chases after a %^RESET%^%^ORANGE%^rat%^BOLD%^%^BLACK%^ as it scurries across the floor.", 
      "%^ORANGE%^The goblin stares at you with its beady %^RED%^red%^ORANGE%^ eyes.", 
      "%^GREEN%^The goblin picks its nose and eats it.%^RESET%^", 
      "%^GREEN%^The goblin swats at a fly as it buzzes around its head.%^RESET%^"
   }), 0 );
}