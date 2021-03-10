//rhapsody.c
//added space shifter code Obsidian@ShadowGate 24/05/00
//Updated descriptions with color - Octothorpe 6/15/09

#include <std.h>
#include <daemons.h>

inherit VAULT;

string *owners = ({"margath", "bryanna", "obsidian"});

string barkeep = "dionysus";
int charging;
void set_menu(string *item_names, string *types, int *strengths);
void set_my_mess(string *msg);
void set_your_mess(string *msg);
void set_empty_container(string *empty);
void set_menu_short(string *str);
void set_menu_long(string *str);
void set_currency(string str);
int price(object tp, string strength);
int convert(int cost);
int get_price(string x);
string *query_menu();

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_property("no sticks",1);
    set_short("Rhapsody Inn, a small cozy inn");
    set_long("%^BOLD%^Rhapsody Inn, a small cozy inn\n This small, yet cozy inn has been painstakingly built of %^RESET%^grey %^BOLD%^stones harvested from the Saakrune Sea and the legendary %^RESET%^%^ORANGE%^timber %^BOLD%^%^WHITE%^of the Tharis Forest. Although obviously a newly rebuilt structure, it has the look and feel of the old, maintaining the feeling of being an establishment that has been here as long as memory serves. Ornately carved %^RESET%^%^ORANGE%^wooden %^BOLD%^%^WHITE%^moldings line high vaulted ceilings, which offer even the largest of individuals a comfortable place to rest and relax. The inn boasts a fully stocked %^CYAN%^bar%^WHITE%^ and a small %^RESET%^%^ORANGE%^wooden %^BOLD%^%^CYAN%^stage%^WHITE%^ lined with %^RED%^r%^RESET%^%^RED%^e%^BOLD%^d %^WHITE%^velvet curtains, upon which one may find a softly crooning songstress, a master storyteller, or even a poet reciting his work. A %^CYAN%^hammock%^WHITE%^ has been set up in the northwestern corner of the room, it looks very comfortable. A %^RED%^blazing %^BOLD%^%^WHITE%^fireplace is found not far from it, heating up the room. A lovely %^CYAN%^painting%^WHITE%^ and a %^ORANGE%^banjolele%^WHITE%^ is hung over the fireplace. A throw rug has been laid out in front of the fireplace. Tables dot the room, providing a spot to congregate among friends. One table in particular stands out, it is still stained with %^RESET%^ %^RED%^blood %^BOLD%^%^WHITE%^and bears %^BOLD%^%^BLACK%^burn %^WHITE%^marks, and has an assassin's dagger deeply embedded in the center of the table. There are two %^RED%^menu%^WHITE%^ parchments nailed to the wall by the bar.%^RESET%^\n");
    set_smell("default","The fresh aroma of the food and drink waft in from the kitchen.");
    set_listen("default","You hear the joking banter of the crowd and an occasional fun loving tune.");
    set_items(([
        "menu" : "There are two different menus, the drinks menu and the food menu, choose which one to read.",
        "stage" : "%^BOLD%^Crafted from %^RESET%^%^ORANGE%^timber %^BOLD%^ %^WHITE%^of the Tharis Forest, the stage provides a small area for friends and acquaintances to perform. You may even be lucky enough to glimpse the owners, recounting tales of their adventures. Thick, %^RED%^r%^RESET%^%^RED%^e%^BOLD%^d %^BOLD%^%^WHITE%^velvet curtains line the stage and allow privacy between performances. Mounted at the front of the stage, a gleaming %^RESET%^s%^BOLD%^i%^RESET%^lv%^BOLD%^e %^RESET%^r %^CYAN%^plaque%^RESET%^ garners attention%^RESET%^.",
        ({"painting","lovely painting","rememberance painting"}) : "%^BOLD%^A wave of sadness washes over you as you look at this painting.\n\n A handsome man stands here, flowing %^RESET%^%^ORANGE%^brown %^BOLD%^%^WHITE%^hair whips in the wind, piercing %^BLUE%^blue %^WHITE%^eyes gaze into yours. Clad in cloak and robes, he is quite a sight to see. He clings tightly to a book, superbly bound and covered, probably containing some sort of arcane magic that he used. Next to him stands a pretty elven girl, sparkling %^RESET%^gr%^BOLD%^e%^RESET%^y %^BOLD%^eyes look out at you curiously as she clings to the man. Clad in similar robes and a cloak. Her raven hair spills over the edge of her robes and flows down her back. An eerie m%^YELLOW%^oo%^WHITE%^nlight seems to bathe this lovely couple, and you think you can almost see a beautiful woman in the background, casting the light on this ill-fated pair.%^RESET%^\n\n The painting is entitled: Taaveti and Kindra, together forever.\n Painted by: Vashna Tal'Razzan.",
        "bar" : "%^BOLD%^A large %^RESET%^%^ORANGE%^wooden %^BOLD%^%^WHITE%^ bar, polished to a gleaming shine. A row of comfortable bar stools stands before it.",
        "plaque" : "%^BOLD%^Rhapsody is dedicated to the Love of Adventure and all who have it.%^RESET%^",
        "door" : "On the west is the large door of the Rhapsody Inn, it leads outside.",
        ({"banjo","banjolele"}) : "An old rusty banjolele. The plaque below it reads in tongues: This banjolele belonged to Jimijuker, a famous gnomish bard.",
        "wooden door" : "Next to the bar on the south is a wooden door that leads to the back room, where kegs of beer are kept. Drunks are often placed back there to let them sleep it off.",
        ({"curtains","red velvet curtains","red curtains","velvet curtains"}) : "%^BOLD%^ Thick %^RED%^r%^RESET%^%^RED%^e%^BOLD%^d %^WHITE%^velvet curtains line the stage. They can be closed for privacy but are currently open, inviting performers up on stage.",
        "tables" : "%^BOLD%^Several tables are scattered about the room.",
        ({"table","bloody table"}) : "%^BOLD%^One table in particular catches your eye. It is covered in %^RESET%^%^RED%^blood %^BOLD%^%^WHITE%^that has long since stained the table top. Embedded deeply into the center of the table is an assassin's dagger. Some odd events must have occured here.",
        ({"bar stool","bar stools"}):"%^BOLD%^Several tall bar stools are placed in front of the bar for people to sit on.",
        ({"chair","chairs"}):"Chairs are positioned around the tables about the room for customers to sit on.",
        ({"assassin dagger","assassin's dagger"}):"%^BOLD%^Embedded so deeply into the middle of the table that it can't be removed is an assassin's dagger.",
        "blood":"%^RED%^Blood %^RESET%^stains cover one of the table tops.",
        ({"fire place","fireplace"}):"%^BOLD%^A large %^RED%^red %^BOLD%^ %^WHITE%^brick fireplace is blazing on the northern wall, keeping the room nice and toasty.",
        "hammock" : "%^BOLD%^On the northwestern wall is a large comfortable hammock. It is near the fireplace, so whoever is in it will be kept nice and warm.",
        ({"rug","throw rug"}):"%^BOLD%^A throw rug has been laid out in front of the fireplace. It is made of wool and appears to have been hand woven. It has been imported from a distant land, and the image woven into it is that of what is called a Rune Blade. The weapon is special, and hard to make, carefully tuned to the owner of the sword. Those who wield such blades are called Sword Singers, for their weapon is a part of them and they sing as they fight, weaving their magic through song. They are likened to bards in many cases, for their songs are beautiful and from the soul, ever changing, always different, like their owners.",
    ]));

    set_exits( (["out":"/d/darkwood/room/road7",
        "south" : "/d/darkwood/room/backroom"]) );
    set_door("door","/d/darkwood/room/road7","out","rhapsody key");
    set_open("door",0);
    set_locked("door",0);
    "/d/darkwood/room/road7"->set_open("door",0);
    "/d/darkwood/room/road7"->set_locked("door",0);
    set_door("wooden door","/d/darkwood/room/backroom.c","south","rhapsody key");
    "/d/darkwood/room/backroom"->set_open("wooden door",0);
    "/d/darkwood/room/backroom"->set_locked("wooden door",0);

    set_menu( ({"raging tempo","treble clef","languishing lyre","rhapsody",
        "elven steak","pheasant","story stew","sparkling melody","spinach salad",
        "pretzels","licorice lager","evermeet tea","cocoa","destroyers draught",
        "leg of lamb","feywine"}),
        ({"alcoholic","alcoholic","alcoholic","alcoholic","food","food","food",
        "soft drink","food","food","alcoholic","soft drink","soft drink","alcoholic",
        "food","alcoholic"}),
        ({40, 15, 10, 15, 20, 20, 10, 15, 20, 10, 20, 15, 40, 35, 40, 75}) );
    set_my_mess( ({
        "Your head starts to pound in a raging tempo as you slam this drink down.",
        "Your throat constricts a bit as you drink the slightly sour liquid.",
        "The warmth plucks lazily at your soul as your lips curve into a smile.",
        "One sip of this drink and blissful peace washes over you in waves.",
        "The savory steak provides you with renewed strength.",
        "You are delighted by the pheasant's wonderful flavor.",
        "As you sample the stew, you are taken back to your grandest adventure.",
        "You drink the sparkling melody down, and can't help but laugh a little "+
        "as it tickles your throat.",
        "As you eat the salad, it invigorates you with the health and harmony"+
        " of the forest.",
        "As you eat the pretzels, you begin to get your sense of logic twisted"+
        " in a good knot.",
        "You suck the lager down and it warms your stomach, you finish off the"+
        " licorice stick with a couple of quick bites.",
        "You drink the tea and feel the warmth and raspberries drift down into"+
        " your soul, relaxing you down to your toes, the vigor of youth"+
        " returning to you as the tea works its wonders.",
        "You sip the thick, sweet drink and it tickles your tongue as it slides"+
        " down your throat and warms your belly, leaving a sweet taste in your mouth.",
        "You drink the ale down, and feel ready to battle all your enemies, as"+
        " the alcohol takes hold and strips away your fears and worries.",
        "You tear into the leg of lamb with nothing but your bare hands and teeth"+
        " as your hunger becomes overwhelming and impossible to control.",
        "You drink the feywine and feel an almost magical, blissful peace wash"+
        " over you as your skin starts to tingle all over. The glass almost"+
        " slips from your hands as you hear a faerie giggling in your ear.  You"+
        " set the glass down, letting the wine take full effect."}) );
    set_your_mess( ({
     "'s eyes close and head shakes in pain while quickly downing the liquid from the glass.",
      "lets out a small squeak of surprise.",
      "gives a small smile while sipping the violet drink.",
      "is overcome by an expression of serenity and peace.",
      "enjoys the savory steak.",
      "seems to look surprised at how good the pheasant is.",
      "stares deeply into the stew before eating it, almost as if hypnotized.",
      "drinks the sparkling melody down and laughs a bit while doing so.",
      "eats the salad energetically with a healthy zest for life.",
      "munches on the pretzels and appears to be lost in a twist of logic.",
      "sucks the thick, frothy brew up through the licorice stick and "+
      "then finishes off the straw in a few quick bites.",
      "sips the tea slowly, relaxing as the tea works its wonders.",
      "sips the hot drink and smiles at ending up with"+
      " some white foam covering the tip of the nose.",
      "drinks the ale down and gains an expression of confidence, looking ready to take on an army.",
      "tears into the leg of lamb ravenously and almost savagely.",
      "drinks the feywine and smiles while setting the glass back down, "+
      "eyes fluttering closed for a long moment.",
   }) );
   set_menu_short( ({
      "A squat glass of dancing liquid",
      "A rotund glass of yellow liquid",
      "A mug of thick swirling liquid",
      "A special mug of pleasant liquid",
      "A full well cooked steak.",
      "A plump juicy pheasant",
      "A thick chunky stew",
      "A bottle of sparkling melody",
      "A bowl of spinach leaves",
      "A bowl of salted twisty pretzels",
      "A large mug of sweet licorice brew",
      "A hot mug of swirling tea",
      "A mug full of thick, dark liquid",
      "A bottle of fine dwarven ale",
      "A roasted leg of lamb",
      "A glass of ruby red wine"}) );
   set_menu_long( ({
      "The drink swirls under your gaze, almost as if dancing to an unknown beat.\n",
      "A pale yellow liquid swirls mischievously in its glass.\n",
      "This violet drink swirls lazily within the glass.\n",
      "This sapphire blue drink shimmers here and there with promise.\n",
      "A thick savory steak.\n",
      "A plump bird that sizzles as the hot juices run down its sides.\n",
      "Little letters float in this stew.  As you watch closely the letters come "+
      "together, forming a story.\n",
      "A drink that bubbles and fizzes with a life, dance, and will all at it's own.\n",
      "A bowl of green, leafy spinach leaves. They look very fresh and tasty.\n",
      "A bowl of twisty, little pretzels, all alike. They are even salty. Or"+
      " is it a bowl of little, twisty pretzels, all alike....No. It's definitely"+
      " a twisty little bowl of pretzels, all alike. But they are still salty.\n",
      "A frothy brew, with a twisted licorice stick in the drink, for use as"+
      " a straw or snack. You think that the lager may be imported from"+
      " somewhere else, but you're not sure where.\n",
      "A bright dancing tea that has the hint of raspberries about it. You"+
      " feel calmed and collected when you smell the vapor coming off the tea.\n",
      "A piping hot, thick liquid that is covered in heaps and heaps of cold"+
      " white foam that is slowly melting. The drink swirls slowly as you look"+
      " at it, and you wonder where such a drink comes from.\n",
      "A fine dwarven ale, put in a bottle. This has been imported from the"+
      " brewery of the Dragon's Breath Bar, and has the mark of Rakoz Ironhelm"+
      " on the bottom.\n",
      "A finely roasted piece of lamb leg, well-seasoned and marinated as well"+
      " as roasted over an open flame, and you hear your stomach growl just"+
      " thinking about it.\n",
      "A dark, ruby red wine that catches the available light like a diamond."+
      " It sparkles with an almost magical glistening.\n"}) );
}

string *menu_items;

mapping menu;

string currency = "gold";

void init() {
   ::init();
   add_action("buy", "buy");
   add_action("key","retrieve");
   add_action("read","read");
   add_action("exit_stage","exit");
   add_action("sit","sit");
   add_action("swing","swing");
   add_action("lay","lay");
   add_action("sprawl","sprawl");
}

int read(string str){
   object ob;
   int i;

   if(!str){
      tell_object(TP,"There are two menus here, you can either read the"+
      " drinks menu or the food menu.");
      return 1;
   }
   //   if(str == "note"){
   //      if(avatarp(TP) || (member_array(TP->query_name(),owners) != -1)){
   //         tell_object(TP,"Usage of the space shifter:");
   //         tell_object(TP,"Normal: <expel [who]>");
   //         tell_object(TP,"Severe: <exile [who]>");
   //         return 1;
   //      }
   //      return 0;
   //   }
   if(str == "menu"){
      tell_object(TP,"There are two different menus, the drinks menu"+
      " and the food menu, choose which one to read.");
      return 1;
   }
   if(str == "drinks" || str == "drinks menu"){
      write("The following drinks are served here at the Rhapsody Inn.");
      write("--------------------------------------------------------------------");
      write("Sparkling Melody\t\t\t\t"+get_price("sparkling melody")+" gold");
      write("Rhapsody\t\t\t\t\t"+get_price("rhapsody")+" gold");
      write("Raging Tempo\t\t\t\t\t"+get_price("raging tempo")+" gold");
      write("Treble Clef\t\t\t\t\t"+get_price("treble clef")+" gold");
      write("Languishing Lyre\t\t\t\t"+get_price("languishing lyre")+" gold");
      write("Mug of Licorice Lager\t\t\t\t"+get_price("licorice lager")+" gold");
      write("Evermeet Tea\t\t\t\t\t"+get_price("evermeet tea")+" gold");
      write("Cooked Cocoa\t\t\t\t\t"+get_price("cocoa")+" gold");
      write("Destroyer's Draught\t\t\t\t"+get_price("destroyers draught")+" gold");
      write("Glass of Feywine\t\t\t\t"+get_price("feywine")+" gold");
      write("Ode to Torment\t\t\t\t\t500 gold");
      write("-----------------------------------------------------------");
      write("<buy drink_name> gets you the drink.");
      return 1;
   }
   if(str == "food" || str == "food menu" || str == "foods" || str == "foods menu"){
      write("The following great foods are served here at the Rhapsody Inn.");
      write("--------------------------------------------------------------------");
      write("Pheasant\t\t\t\t\t"+ get_price("pheasant") + " gold");
      write("Elven Steak\t\t\t\t\t"+get_price("elven steak")+" gold");
      write("Story Stew\t\t\t\t\t"+ get_price("story stew")+" gold");
      write("Spinach Salad\t\t\t\t\t"+get_price("spinach salad")+" gold");
      write("Riddling Pretzels\t\t\t\t"+get_price("pretzels")+" gold");
      write("Leg of Lamb\t\t\t\t\t"+get_price("leg of lamb")+" gold");
      write("-----------------------------------------------------------");
      write("<buy dish_name> gets you the food.");
      return 1;
   }
}

int space_shifter(string str){
   object victim, *shit;
   int i;
   if((member_array(TP->query_name(),owners) == -1)) return 0;
   if(!str) return 0;
   if((string *)TP->query_attackers() != ({})) return notify_fail("You are too busy to do that\n");
   if(charging) return notify_fail("It is still recharging\n");
   if(!(victim = present(str,TO))) return notify_fail("No such person here\n");
   if(avatarp(victim) && (int)victim->query_level() <= 100) return 0;

   tell_object(TP,"You press a hidden button behind the bar activating the "+
      "space shifter.");
   tell_room(TO,"%^BLUE%^A dense magical mist rises around "+str+", "+
      "engulfing "+victim->query_objective(),victim);
   tell_object(victim,"%^BLUE%^A dense magical mist engulfs you!");
   if(query_verb() == "exile"){
      shit = all_inventory(victim);
      for(i=0;i<sizeof(shit);i++){
         if(!SAVING_D->saving_throw(victim,"petrification_polymorph",-2))
            shit[i]->move("/d/darkwood/room/backroom");
      }
   }
   victim->move("/d/darkwood/room/road7");
   tell_object(victim,"You look confused.");
   charging = 1;
   call_out("reset_charging",40);
   return 1;
}

void reset_charging(){
   charging = 0;
}

int key(string str){
   object ob;
   if(!str || str != "key") return 0;
   if(!wizardp(TP) && (member_array(TP->query_name(), owners) == -1)) return 0;
   ob = new ("/std/Object");
   ob->set_name("rhapsody key");
   ob->set_id(({"key","rhapsody key"}));
   ob->set_short("Rhapsody key");
   ob->set_long("This is the simple key that lock and unlocks the door to the Rhapsody inn");
   ob->set_weight(1);
   ob->move(TP);
   tell_object(TP,"You retrieve a secretly hidden backup key.");
   return 1;
}

void set_menu(string *item_names, string *types, int *strengths){
   int i;
   menu_items = item_names;
   if(!menu) menu = ([]);
   for(i=0; i<sizeof(menu_items); i++){
      menu[menu_items[i]] = ([ "type": types[i], "strength": strengths[i] ]);
   }
}

void set_my_mess(string *msg){
   int i;
   for(i=0; i<sizeof(menu_items); i++){
      menu[menu_items[i]]["my message"] = msg[i];
   }
}

void set_your_mess(string *msg){
   int i;
   for(i=0; i<sizeof(menu_items); i++){
      menu[menu_items[i]]["your message"] = msg[i];
   }
}

void set_empty_container(string *container){
   int i;
   for(i=0; i<sizeof(menu_items); i++){
      menu[menu_items[i]]["empty container"] = container[i];
   }
}

void set_menu_short(string *str){
   int i;
   for(i=0; i<sizeof(menu_items); i++){
      menu[menu_items[i]]["short"] = str[i];
   }
}

void set_menu_long(string *str){
   int i;
   for(i=0; i<sizeof(menu_items); i++){
      menu[menu_items[i]]["long"] = str[i];
   }
}

void set_currency(string str){
   currency = str;
}

int price(object tp, int strength){
   int cost;
   cost = strength;
   if(!tp->query_funds(currency, cost)) return 0;
   tp->use_funds(currency, cost);
   return cost;
}

int convert(int x){
   if(!x) return 0;
   else return 1+to_int(currency_rate(currency)*x);
}

make_product(string str);

int buy(string str){
   int i, cost;
   object ob;
   string who;
   int j;
   if(present(barkeep)) who = capitalize(barkeep);
   else{
      for(j=0;j<sizeof(owners);j++){
         if(present(owners[i])){
            who = capitalize(owners[i]);
            break;
         }
      }
   }
   if(member_array((string)TP->query_name(),owners) != -1){
      if(member_array(str, menu_items) == -1){
         return notify_fail("Sorry not on the menu.\n");
      }
      if(menu[str]["type"] == "food"){
         tell_room(TO,TPQCN+" whips "+TP->query_objective()+
         "self up a "+str+".",TP);
         tell_object(TP,"You whip yourself up a "+str);
      } else {
         tell_room(TO,TPQCN+" draws "+TP->query_objective()+
         "self a "+str+".",TP);
         tell_object(TP,"You draw yourself a "+str);
      }
      make_product(str);
      return 1;
   }
   if(!stringp(who)) return 0;
   if(!str) {
      notify_fail(who+" says: What is it you would like?\n");
      return 0;
   }
   str = lower_case(str);
   if(member_array(str, menu_items) == -1) {
      present(who)->force_me("say We don't serve that here.");
      return 1;
   }
   if(!(cost = price(TP, menu[str]["strength"]))) {
      present(who)->force_me("say Get out, you don't got the cash.");
      return 1;
   }
   write("You pay "+cost+" "+currency+" coins for a "+str+".\n");
   say(""+who+" collects some "+currency+" from "+TPQCN+".\n",TP);
   make_product(str);
   return 1;
}

void make_product(string str){
   object ob;
   int i;
   if(menu[str]["type"] == "food"){
      ob = new("std/food");
      ob->set_name(str);
      ob->set_id( ({str, "food"}) );
      ob->set_value(0);
   }
   else{
      ob = new("std/drink");
      ob->set_name(str);
      ob->set_type(menu[str]["type"]);
      ob->set_id( ({ str, "drink"}) );
   }
   ob->set_strength(menu[str]["strength"]);
   ob->set_weight(1);
   i = menu[str]["strength"];
   set("cointype","silver");
   ob->set_value(0);
   ob->set_destroy();
   if(menu[str]["short"]) ob->set_short(menu[str]["short"]);
   else ob->set_short(capitalize(str));
   if(menu[str]["long"]) ob->set_long(menu[str]["long"]);
   else ob->set_long(capitalize(str) + " from "+TO->query_short()+".\n");
   if(menu[str]["empty container"]) ob->set_empty_name(menu[str]["empty container"]);
   if(menu[str]["my message"]) ob->set_my_mess(menu[str]["my message"]);
   if(menu[str]["your message"]) ob->set_your_mess(menu[str]["your message"]);
   if(ob->move(TP)){
      write("You cannot carry it!\nYou drop a "+str+".\n");
      say(TP->query_cap_name()+" drops a "+str+".\n", TP);
      ob->move(environment(TP));
   }
}

int get_price(string str){
   int foo;
   foo = menu[str]["strength"];
   return foo;
}

string *query_menu(){ return menu_items; }

void reset(){
   ::reset();
   if(!present("dionysus")) new("/d/npc/dionysus")->move(TO);
   if(!present("alinbar")) new("/d/npc/alinbar")->move(TO);
}

int exit_stage(string str){
   if(str == "stage right"){
      tell_object(TP,"You exit stage right, moving to the backstage.");
      if(!wizardp(TP) || (avatarp(TP) && !TP->query_invis())) tell_room(ETP,""+TPQCN+" exits stage right.",TP);
      TP->move_player("/d/darkwood/room/backstage.c");
      return 1;
   }
   else return notify_fail("Exit where?\n");
}

int sit(string str){
   if(str == "chair"){
      if(TP->query_intox() > 500){
         tell_object(TP,"You fall drunkenly into the chair.");
         tell_room(ETP,""+TPQCN+" falls drunkenly into a chair.",TP);
         return 1;
      }
      tell_object(TP,"You take a seat in a comfortable chair.");
      tell_room(ETP,""+TPQCN+" takes a seat in one of the chairs.",TP);
      return 1;
   }
   if(str == "stool" || str == "bar stool"){
      if(TP->query_intox() > 500) {
         tell_object(TP,"You fall off the bar stool as you try to sit down.");
         tell_room(ETP,""+TPQCN+" falls off the bar stool as "+
         TP->query_subjective()+" tries to sit down on it.",TP);
         return 1;
      }
      tell_object(TP,"You seat yourself on one of the many bar stools.");
      tell_room(ETP,""+TPQCN+" seats "+TP->query_objective()+"self"+
      " on one of the bar stools.",TP);
      return 1;
   }
   if(str == "floor"){
      tell_object(TP,"You sit down on the cold wooden floor.");
      tell_room(ETP,""+TPQCN+" sits down on the cold wooden floor.",TP);
      return 1;
   }
   if(str == "stage"){
      tell_object(TP,"You hop up and sit on the edge of the stage.");
      tell_room(ETP,""+TPQCN+" hops up and takes a seat on the edge of "+
      "the stage.",TP);
      return 1;
   }
   if(str == "bloody table"){
      if((string)TP->query_name() == "berset"){
         tell_object(TP,"You sit down at your table.");
         tell_room(ETP,"The One and Only sits down at his table.",TP);
      }
      else{
         tell_object(TP,"You bravely sit down at the %^RED%^bloody %^RESET%^table.");
         tell_room(ETP,""+TPQCN+" bravely sits down at the %^RED%^bloody %^RESET%^table.",TP);
      }
      return 1;
   }
   if(str == "hammock"){
      tell_object(TP,"You climb into the cozy hammock.");
      tell_room(ETP,""+TPQCN+" climbs into the cozy hammock.",TP);
      return 1;
   }
   if(str == "table" || str == "table top"){
      tell_object(TP,"You rudely sit down on the top of one of the tables.");
      tell_room(ETP,""+TPQCN+" boldly seats "+TP->query_objective()+"self"+
      " on one of the table tops.",TP);
      return 1;
   }
   if(str == "rug" || str == "throw rug"){
      tell_object(TP,"You sit down on the rug in front of the fireplace.");
      tell_room(ETP,""+TPQCN+" sits down on the rug in front of the fireplace.",TP);
      return 1;
   }
}

int swing(string str){
   if(str == "hammock"){
      tell_object(TP,"You swing slowly in the cozy hammock.");
      tell_room(ETP,""+TPQCN+" swings slowly in the cozy hammock.",TP);
      return 1;
   }
}

int sprawl(string str){
   if(str == "rug" || str == "throw rug") {
      tell_object(TP,"You sprawl out on the rug, practically taking up the"+
      " whole thing.");
      tell_room(ETP,""+TPQCN+" sprawls out on the rug,"+
      " practically taking up the whole thing.",TP);
      return 1;
   }
   if(str == "floor"){
      tell_object(TP,"You wind up sprawled out on the floor, exhausted from"+
      " such a long night of drinking and partying.");
      tell_room(ETP,""+TPQCN+" winds up sprawled out on the"+
      " floor, exhausted from such a long night of drinking and partying.",TP);
      return 1;
   }
}

int lay(string str){
   if(str == "rug" || str == "throw rug"){
      tell_object(TP,"You lay down on part of the throw rug, warming "+
      "yourself in front of the fire.");
      tell_room(ETP,""+TPQCN+" lays down on part of the throw rug, "+
      "basking in the warm glow of the fire.",TP);
      return 1;
   }
   if(str == "floor"){
      if(TP->query_intox() > 500){
         tell_object(TP,"You lay down on the floor, the only thing that seems"+
         " unmoving in the room...well, mostly unmoving.");
         tell_room(ETP,""+TPQCN+" lays down on the floor, being"+
         " too drunk to sit elsewhere.",TP);
         return 1;
      }
      else {
         tell_object(TP,"You lay down on the cold hardwood floor.");
         tell_room(ETP,""+TPQCN+" lays down on the cold hardwood floor.",TP);
         return 1;
      }
   }
}
