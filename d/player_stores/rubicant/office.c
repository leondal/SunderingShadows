#include <std.h>
#define RSHOP "/d/player_stores/rubicant/"
#define OFFICEKEY "darksteel key"
#define PRIVATE_ACCESS ({ "rubicant", "saide"})

inherit VAULT;

int trap1_on;
int trap2_on;

void toggle_glyph1(int on);
void toggle_glyph2(int on);

void do_zap(object who);
void do_stab(object who, object guard);



void create() {
        ::create();
        set_property("indoors",1); 
        set_property("light",2); 
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("The Office"); 
        set_short("%^RESET%^%^BOLD%^%^RED%^The Office%^RESET%^");
        set_long("%^RESET%^%^WHITE%^This is a square-shaped room, "
"stretching only a third of the length of the main shop's north wall. "
"%^BOLD%^%^BLACK%^Obsidian pillars%^RESET%^%^WHITE%^ interrupt smooth "
"%^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^i"
"%^BOLD%^%^BLACK%^te w%^RESET%^%^WHITE%^a%^BOLD%^l%^RESET%^%^WHITE%^"
"l%^BOLD%^%^BLACK%^s %^RESET%^%^WHITE%^at even intervals, set with "
"%^BOLD%^%^BLACK%^black sconces%^RESET%^%^WHITE%^ to provide ample "
"lighting for the office. The north wall of the office is dominated "
"by the %^MAGENTA%^large, exquisite portrait%^WHITE%^ of a half-elf "
"with a human woman embracing him hung in its center. The three "
"other walls have %^RED%^doors%^WHITE%^ set in their centers, each "
"similar, yet unique. The floor is covered by a %^BOLD%^%^RED%^plush "
"scarlet carpet%^RESET%^%^WHITE%^ and the ceiling is the same %^BOLD%^"
"%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^i%^BOLD%^"
"%^BLACK%^te%^RESET%^%^WHITE%^ as the walls. Drawing your attention "
"the most is the %^BOLD%^%^BLACK%^large, ornate desk%^RESET%^%^WHITE%^ "
"set slightly towards the back of the room with a matching %^BOLD%^"
"%^BLACK%^ornate desk chair%^RESET%^%^WHITE%^ behind it. In front "
"of the desk are two smaller chairs made of %^BOLD%^%^BLACK%^black "
"iron%^RESET%^%^WHITE%^ with %^BOLD%^%^RED%^scarlet cushions%^RESET%^"
"%^WHITE%^.%^RESET%^");
        set_smell("default","%^RESET%^%^RED%^ Whiffs of exotic spices tickle your senses.%^RESET%^");
        set_listen("default","%^RESET%^%^BOLD%^%^BLACK%^ The only sounds made here are your own.%^RESET%^");
        set_items(([
           ({"pillars", "obsidian pillars" }) : "%^RESET%^%^BOLD%^%^BLACK%^These masterwork pillars are carved from %^RESET%^%^BLUE%^pure obsidian%^BOLD%^%^BLACK%^ and kept impeccably clean, each adorned with an %^RESET%^%^BLUE%^ornate black sconce%^BOLD%^%^BLACK%^.%^RESET%^",
           "walls" : "%^RESET%^%^WHITE%^The walls are made of %^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^te%^RESET%^%^WHITE%^ that has been smoothed and polished to a %^BOLD%^%^CYAN%^mirrorlike%^RESET%^%^WHITE%^ sheen.%^RESET%^",
           ({"sconces", "lighting", "lights", "light" }) : "%^RESET%^%^YELLOW%^Ample lighting%^RESET%^%^WHITE%^ is provided by the %^BOLD%^%^BLACK%^ornate black iron sconces%^RESET%^%^WHITE%^ on each of the %^BOLD%^%^BLACK%^pillars%^RESET%^%^WHITE%^ in the workshop. Magical in nature, they give off no smoke and burn %^BOLD%^brilliantly%^RESET%^%^WHITE%^ at all times, illuminating far more than the flames would normally.%^RESET%^",
           ({"carpet", "carpeting", "floor" }) : "%^RESET%^%^RED%^The carpet is thick and plush, incredibly comfortable and soft to the touch. It is a %^BOLD%^deep scarlet%^RESET%^%^RED%^ in color, much like %^BOLD%^fresh blood%^RESET%^%^RED%^, and muffles your footsteps greatly.%^RESET%^",
           ({ "painting", "portrait" }) : (: TO, "painting" :),
           "desk" : (: TO, "desk" :),
           "desk chair" : (: TO, "dchair" :),
           "ceiling" : "%^RESET%^%^WHITE%^The ceiling is made of the same %^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^te%^RESET%^%^WHITE%^ as the walls, which has been smoothed and polished to a %^BOLD%^%^CYAN%^mirrorlike%^RESET%^%^WHITE%^ sheen.%^RESET%^",
	   ({ "chair", "chairs" }) : "There is a desk chair and two %^BOLD%^%^BLACK%^ornate black iron chairs%^RESET%^ that you may want to take a closer look at or sit in.",
           ({ "chairs", "iron chair", "iron chairs", "black iron chairs" }) : "%^RESET%^%^RED%^These chairs were crafted with %^BOLD%^%^BLACK%^ornate black iron%^RESET%^%^RED%^ for the frames and cherrywood for the seats and backs. They have comfortable-looking cushions made of %^BOLD%^scarlet velvet%^RESET%^%^RED%^.%^RESET%^",
	   "design" : "On closer inspection, you realize it may be some kind of glyph.",
	   "glyph" : "There is one on each door so you'll need to be more specific.",
	   ({"glyph 1", "ornate door glyph" }) : (: TO, "glyph1_desc" :),
	   ({"glyph 2", "runic door glyph" }) : (: TO, "glyph2_desc" :),
        ]));
        set_exits(([
           "south" : RSHOP+"shop_main",
           "west" : RSHOP+"bedroom",
           "east" : RSHOP+"laboratory",
        ]));
        set_door("carved door",RSHOP+"shop_main","south",0);
	   set_lock_description("carved door","lock", "The lock has a knob on this side of the door that turns to lock or unlock it without need of a key.");
        set_door("ornate door",RSHOP+"bedroom","west",OFFICEKEY, "gold lock");
 	   set_open("ornate door",0);
	   set_locked("ornate door", 1, "gold lock");
	   lock_difficulty("ornate door",-80, "gold lock");
	   set_lock_description("ornate door","gold lock", "This gold lock appears quite intricate and has so many tumblers you can't readily count them.");
       set_door("runic door",RSHOP+"laboratory","east",OFFICEKEY, "silver lock");
	   set_open("runic door",0);
	   set_locked("runic door", 1, "silver lock");
	   lock_difficulty("runic door",-80, "silver lock");
	   set_lock_description("runic door","silver lock", "The lock appears quite intricate and has so many tumblers you can't readily count them.");

	 set_trapped(({"unlock ornate door", "unlock runic door", "pick ornate door", 
	 "pick runic door"}), ({"special", "special", "special", "special"}), 
	 ({"zap_unlock", "zap_unlock", "zap_pick", "zap_pick"}));

        trap1_on = 1;
        trap2_on = 1;
        set_door_description("carved door", "%^RESET%^%^RED%^This large door is made of a rich cherrywood and is shaped in an arch, coming to a point at the top. It is framed in %^BOLD%^%^BLACK%^ornate black iron%^RESET%^%^RED%^, and has a stylish %^BOLD%^%^BLACK%^black iron handle%^RESET%^%^RED%^ and %^BOLD%^%^BLACK%^hinges%^RESET%^%^RED%^.%^RESET%^");
        set_door_description("ornate door", "%^RESET%^%^RED%^This large door "
"is made of a rich cherrywood and is shaped in an arch, coming to a point at "
"the top. It is framed in %^BOLD%^%^BLACK%^ornate black iron%^RESET%^%^RED%^, "
"and has a stylish %^BOLD%^%^BLACK%^black iron handle%^RESET%^%^RED%^ and "
"%^BOLD%^%^BLACK%^hinges%^RESET%^%^RED%^.%^RESET%^  You can see a small design "
"carved into the door near the lock.");
        set_door_description("runic door", "%^RESET%^%^RED%^This large "
"door is made of a rich cherrywood and is shaped in an arch, coming to "
"a point at the top.  It is "
"framed in %^BOLD%^%^BLACK%^ornate black iron%^RESET%^%^RED%^, and has "
"a stylish %^BOLD%^%^BLACK%^black iron handle%^RESET%^%^RED%^ and "
"%^BOLD%^%^BLACK%^hinges%^RESET%^%^RED%^.%^RESET%^  You can see a small "
"design carved into the door near the lock.");
	   set_string("runic door", "open", "The %^RED%^door%^WHITE%^ opens without so much as the slightest %^BOLD%^%^BLACK%^whisper%^RESET%^.");
	   set_string("runic door", "close", "The %^RED%^door%^WHITE%^ closes solidly, without a %^BOLD%^%^BLACK%^sound%^RESET%^.");
	   set_string("ornate door", "open", "The %^RED%^door%^WHITE%^ opens without so much as the slightest %^BOLD%^%^BLACK%^whisper%^RESET%^.");
	   set_string("ornate door", "close", "The %^RED%^door%^WHITE%^ closes solidly, without a %^BOLD%^%^BLACK%^sound%^RESET%^.");
	   set_string("carved door", "open", "The %^RED%^door%^WHITE%^ opens without so much as the slightest %^BOLD%^%^BLACK%^whisper%^RESET%^.");
	   set_string("carved door", "close", "The %^RED%^door%^WHITE%^ closes solidly, without a %^BOLD%^%^BLACK%^sound%^RESET%^.");
}

void init() 
{
	::init();
  	add_action("sit_chair", "sit");
   	add_action("arm_trap", "trace");
   	if(!TP->query_true_invis()) 
	{
      	tell_room((RSHOP+"shop_main"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
      	tell_room((RSHOP+"bedroom"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
      	tell_room((RSHOP+"laboratory"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
      	tell_room((RSHOP+"workshop"),"%^BOLD%^%^BLUE%^You hear a bell ringing.\n");
   	}
}

void reset() 
{
	::reset();
}

int sit_chair(string str) 
{
	if(!str) 
	{
     		tell_object(TP,"The cushions on the iron chairs make them look "+
		"like a good place to sit.");
     		tell_room(ETP,TPQCN+" seems to be trying to decide where to sit.",TP);
     		return 0;
   	}
   	if(str == "desk chair" || str == "ornate chair") 
	{
     		if(member_array((string)TP->query_name(), PRIVATE_ACCESS) != -1) 
		{
        		tell_object(TP,"You take a seat in your ornate chair behind the desk.");
        		tell_room(ETP,TPQCN+" takes a seat in the ornate chair behind the desk.",TP);
			return 1;
     		}
     		tell_object(TP,"You get a sense of foreboding from the carvings as "+
		"you take a seat in the ornate chair behind the desk.");
     		tell_room(ETP,TPQCN+" takes a seat in the ornate chair behind the "+
		"desk and looks somewhat disconcerted.",TP);
     		return 1;
   	}
   	if(str == "chair" || str == "chairs" || str == "iron chair" || str == "iron chairs") 
	{
      	tell_object(TP,"You sit on one of the %^RED%^cushioned %^RESET%^iron chairs.");
      	tell_room(ETP,""+TPQCN+" takes a seat in one of the %^RED%^"+
		"cushioned %^RESET%^iron chairs.",TP);
      	return 1;
   	}
   	return 0;
}

int arm_trap(string str) 
{
/**************** testing stuff to zap
   tell_object(find_player("styx"), identify(query_trap_func_map()));
   tell_object(find_player("styx"), "Trapped state ornate door lock, unlock is "+query_trapped_state("ornate door", "lock", "unlock")+".");
   tell_object(find_player("styx"), "Trapped state ornate door lock, pick is "+query_trapped_state("ornate door", "lock", "pick")+".");
   tell_object(find_player("styx"), "Trapped state runic door lock, unlock is "+query_trapped_state("runic door", "lock", "unlock")+".");
   tell_object(find_player("styx"), "Trapped state runic door lock, pick is "+query_trapped_state("runic door", "lock", "pick")+".");
   tell_object(find_player("styx"), "Trapped state map is "+identify(query_trap_state_map());
   
**************** testing stuff to zap **********/

	if(!str) return 0;

   	if(str != "runes") 
	{
		write("Tracing the "+str+" doesn't seem to have any effect except "
	    	"perhaps to make you look silly.");
        	tell_room(ETP, TPQCN+" traces the "+str+" and looks a little silly don't "
	    	"you think?", TP);
		return 1;
   	}
   	if(member_array((string)TPQN, PRIVATE_ACCESS) == -1) 
	{
    		if(random(20)) 
		{
			tell_object(TP,"%^YELLOW%^As you attempt to trace the runes, "+
			"the glyph shoots a lightning bolt at you!");
			tell_room(ETP,"%^YELLOW%^A lightning bolt shoots from the glyph as "
	   		+TPQCN+" touches the runes around it.",TP);
            TP->cause_typed_damage(TP, "torso", roll_dice(5, 10), "electricity");
			TP->add_attacker(TO);
			TP->continue_attack();
  			TP->remove_attacker(TO);
			return 1;
     		}
   	}
   	if(!trap1_on) 
	{  
      	tell_object(TP,"As you trace the runes around the glyph they glow, albeit briefly.");
      	tell_room(ETP,TPQCN+" traces the runes around the glyph and they glow briefly.", TP);
      	toggle_glyph1(1); 
      	trap1_on = 1;
   	} 
	else 
	{
      	tell_object(TP,"The glow from the glyph fades as you trace the runes.");
      	tell_room(ETP,TPQCN+" traces the runes around the glyph and the glow "+
		"from it fades.",TP);
      	toggle_glyph1(0);
      	trap1_on = 0;
   	}
   	return 1;
}

int zap_unlock(string str) 
{
	if( interactive(TP)) 
	{
    		switch(str) 
		{
			case "gold lock" :     
	   			do_zap(TP);	
	   			//toggle_trap("ornate door", "unlock", "gold lock");
	   			trap1_on = 0;
	   			break;
			case "silver lock" :
	   			do_zap(TP);	
	   			//toggle_trap("runic door", "unlock", "silver lock");
	   			trap2_on = 0;
	   			break;
				default:  return 0;
     		}
     		return 1;
  	}
  	return 0;
}

int zap_pick(string str) 
{
	if( interactive(TP)) 
	{
     		switch(str) 
		{
			case "gold lock" :     
	   			do_zap(TP);	
	   			//toggle_trap("ornate door", "pick", "gold lock");
	   			trap1_on = 0;
	   			break;
			case "silver lock" :
	   			do_zap(TP);	
	   			//toggle_trap("runic door", "pick", "silver lock");
	   			trap2_on = 0;
	   			break;
			default:  
				return 0;
     		}
     		return 1;
  	}
  	return 0;
}

void do_zap(object who) 
{
	object glyph, spell, spell2, guard;
     	string msg = "%^BOLD%^%^GREEN%^You hear a shout and other disturbances from "+
	"the office to the ";
     	if(member_array(who->query_name(), PRIVATE_ACCESS) != -1) 
	{
		write("The trap disperses harmlessly since it's you.");
		return;
     	}
     	tell_room((RSHOP+"shop_main"),msg+"north.\n");
    	tell_room((RSHOP+"bedroom"),msg+"east.\n");
     	tell_room((RSHOP+"laboratory"),msg+"west.\n");
     	tell_room((RSHOP+"workshop"),msg+"north of the main shop.\n");
    	tell_room(TO,"%^BOLD%^%^CYAN%^The glyph on the door suddenly glows brightly!");
     	glyph = new("/std/Object");
         glyph->set_name("glyph");
         glyph->move(TO);
     	spell = new("/cmds/spells/d/_dispel_magic");
         spell->move(glyph);
         spell->use_spell(glyph, who, 40, 100, "mage");
     	spell2 = new("/cmds/spells/p/_powerword_stun.c");
         spell2->move(glyph);
         spell2->use_spell(glyph, who, 40, 100, "mage");
     	tell_room(TO,"%^BOLD%^%^RED%^Guards appear as if from the shadows themselves.");
     	guard = new("/d/player_houses/mons/rubicant_guard");
	guard->move(TO);
	do_stab(who, guard);
// to be safe and make sure the spell objects will get wiped
     	glyph->move("/d/shadowgate/void");
     	glyph->remove();
     	return;
}

void do_stab(object who, object guard)
{
	guard->force_me("say You do obviously do not belong here!");
	guard->force_me("stab "+who->query_name());
}

string glyph1_desc() {
  if(trap1_on) return("A softly glowing %^YELLOW%^golden glyph %^RESET%^is faintly visible near the gold lock on the ornate door.");
  else return("A small design carved near the %^YELLOW%^gold lock%^RESET%^ on the ornate door is faintly visible.");
}

string glyph2_desc() {
  if(trap2_on)  return("A softly glowing %^BOLD%^silver glyph %^RESET%^is faintly visible near the silver lock on the runic door.");
  else return("A small design carved near the %^BOLD%^silver lock %^RESET%^on the runic door is faintly visible.");
}

void toggle_glyph1(int on) 
{
   	if(on) 
	{		
		if(TO->is_this_trapped("unlock ornate door")) 
		{
			TO->remove_trap("unlock ornate door");
		}
		set_trapped(({"unlock ornate door"}), ({"special"}), ({"zap_unlock"}));
		return;
   	} 
	else
	{
		if(TO->is_this_trapped("unlock ornate door"))
		{
			TO->remove_trap("unlock ornate door");
		}
		return;
	}
      return;
}


string painting() {
    return("%^RESET%^%^BLUE%^This painting depicts a "
"male half-elf and a female human standing together on a %^BOLD%^"
"%^BLACK%^shadowy background%^RESET%^%^BLUE%^ with a slight %^WHITE%^"
"s%^BOLD%^i%^RESET%^%^WHITE%^lv%^BOLD%^e%^RESET%^%^WHITE%^ry %^BOLD%^"
"g%^RESET%^%^WHITE%^lo%^BOLD%^w%^RESET%^%^BLUE%^ behind them. The "
"half-elf has a %^ORANGE%^well-built body%^BLUE%^ and is dressed in "
"hues of %^BOLD%^%^BLACK%^black%^RESET%^%^BLUE%^ and %^BOLD%^deep "
"blue%^RESET%^%^BLUE%^, with a beautiful coat of swirling %^BOLD%^"
"%^BLUE%^b%^RESET%^%^BLUE%^l%^BOLD%^u%^RESET%^%^BLUE%^e%^BOLD%^s"
"%^RESET%^%^BLUE%^, %^RESET%^%^WHITE%^grays%^BLUE%^ and %^BOLD%^"
"%^BLACK%^blacks%^RESET%^%^BLUE%^ adorning his torso and a matching "
"pair of paints. He wears a %^BOLD%^%^BLACK%^flowing black cloak"
"%^RESET%^%^BLUE%^ that falls around the pair's legs loosely. He is "
"rather %^CYAN%^plain featured%^BLUE%^, with a %^RED%^deep scar"
"%^BLUE%^ marring his features that narrowly misses one of his "
"%^WHITE%^gray eyes%^BLUE%^. He looks to be in his early twenties "
"for a half-elf, though he looks as though he has seen far more "
"%^RED%^pain%^BLUE%^ and %^MAGENTA%^suffering%^BLUE%^ than one "
"should have at that age. One of his hands rests on the small "
"of the human woman's back, who is curling up to the man as if "
"for comfort. She is %^WHITE%^stunningly beautiful%^BLUE%^ and "
"nude, with her form facing away from you so that you can see "
"the perfect contours of her back and rear. Her arms are on the "
"man's chest and back, and her head rests with closed eyes against "
"his chest, a look of peace and happiness on her lovely face. Her "
"face is perfect and visible from one side, framed beautifully by "
"her %^BOLD%^%^RED%^wavy scarlet hair%^RESET%^%^BLUE%^, which "
"falls to about her mid-back.%^RESET%^"
    );
}

string desk() {
    return("%^RESET%^%^BOLD%^%^BLACK%^This large desk is "
"a masterpiece that has been cast of molten %^RESET%^%^MAGENTA%^"
"darksteel%^BOLD%^%^BLACK%^. Immediately catching your gaze are "
"the %^RESET%^%^WHITE%^skeletons%^BOLD%^%^BLACK%^ that form the four "
"corners, which look as though they are rising from the ground, "
"carrying in their %^RESET%^%^WHITE%^skeletal grip%^BOLD%^%^BLACK%^ "
"the top of the desk. Their %^RESET%^%^WHITE%^skulls%^BOLD%^%^BLACK%^ "
"form the top corners, whose empty eyes gaze eerily forward and whose "
"jaws are locked into an eternal silent scream. Each ribcage and arm "
"bones are bent and straining as if lifting a great weight on their "
"backs, and their spinal cords extend down to the floor as if their "
"lower halves were rising up through the floor. The sides of the "
"desk have all been carved with a terrible scene of a %^RESET%^"
"%^BLUE%^dark figure%^BOLD%^%^BLACK%^ garbed in %^RESET%^%^CYAN%^"
"tattered robes and chains%^BOLD%^%^BLACK%^ standing upon a hilltop.  "
"Surrounding him are innumerable %^RESET%^%^WHITE%^skeletons%^BOLD%^"
"%^BLACK%^ and %^RESET%^%^RED%^corpses%^BOLD%^%^BLACK%^, rent apart "
"by what must have been some powerful spell, laying prostrate around "
"him. Some of the %^RESET%^%^WHITE%^dead%^BOLD%^%^BLACK%^ look as "
"though they are rising again as %^RESET%^%^WHITE%^undead%^BOLD%^"
"%^BLACK%^, bowing to the figure in the center. The top of the desk "
"is smooth and polished to a %^CYAN%^mirrorlike%^BLACK%^ sheen."
    );
}

string dchair() {
    return("%^BOLD%^%^BLACK%^This large "
"chair is a masterpiece that has been cast of molten %^RESET%^"
"%^MAGENTA%^darksteel%^BOLD%^%^BLACK%^. It is tall and grand, with "
"luxurious %^RESET%^%^WHITE%^silver velvet cushioning%^BOLD%^"
"%^BLACK%^ on the seat and tall back of the chair. The ends of the "
"arms and the corners of the chair's back are all made to look like "
"human skulls with empty eyes gaze eerily forward and whose jaws "
"are locked into an eternal silent scream. The sides and back of "
"the chair have been carved with a terrible scene of a %^RESET%^"
"%^BLUE%^dark figure%^BOLD%^%^BLACK%^ garbed in %^RESET%^%^CYAN%^"
"tattered robes and chains%^BOLD%^%^BLACK%^ standing upon a hilltop.  "
"Surrounding him are innumerable %^RESET%^%^WHITE%^skeletons%^BOLD%^"
"%^BLACK%^ and %^RESET%^%^RED%^corpses%^BOLD%^%^BLACK%^, rent apart "
"by what must have been some powerful spell, laying prostrate around "
"him. Some of the %^RESET%^%^WHITE%^dead%^BOLD%^%^BLACK%^ look as "
"though they are rising again as %^RESET%^%^WHITE%^undead%^BOLD%^"
"%^BLACK%^, bowing to the figure in the center.%^RESET%^"
    );
}