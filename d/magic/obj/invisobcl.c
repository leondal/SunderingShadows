//sped up heartbeat - easy to skip through rooms still invis.
//converted to non-city areas to work rather than "outdoors";
//tunnels and caves make more sense than city streets.
//allowed emotes but left the ability for speech locked, so
//players can convey fair emotes of sound/etc. N, 4/11

#include <std.h>
inherit OBJECT;

int move_ok;

int go_vis();
void show_up();

void create() {
   ::create();
   set_name("invisob");
   set("id", ({ "invisobx999"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);

}

void init() {
   ::init();
   if(living(environment(TO)) && TP==environment(TO) ) {
      if(TO->query_property("spell")) {
         tell_object(TP,"%^BOLD%^%^GREEN%^Your colors bend and change as light around you reshapes to conceal you.");
         if(TP->query_invis()) {
            tell_room(environment(TP),"%^BOLD%^%^GREEN%^You hear a slight fizzle and a pop.",TP);
            TO->remove();
            return;
         }
         tell_room(environment(TP),"%^BOLD%^%^GREEN%^"+TP->query_cap_name()+" begins to bend and swirl and is then consumed by the world around "+TP->query_objective()+".",TP);

         TP->set_magic_hidden(1);
         set_heart_beat(2);
         add_action("go_vis","appear");
         add_action("stopIt","say");
//         add_action("stopIt","emote");
         call_out("check_attacks",2);
      } else {
         show_up();
      }
   }
}

int go_vis() 
{
	if(!objectp(TO)) return 1;
	if(TO->query_property("spell"))
      	TO->query_property("spell")->dest_effect();
	else
      	show_up();
	return 1;
}

void show_up() {
   object cloaker;
   cloaker=environment(TO);
   if(!cloaker) {
      TO->remove();
      return;
   }
   if(!interactive(cloaker)) {
      TO->remove();
      return;
   }
   if(!cloaker->query_invis()) {
      TO->remove();
      return;
   }
   tell_object(cloaker,"%^YELLOW%^Nature pulls back from you, reluctantly.");
   tell_room(environment(cloaker),"%^BOLD%^%^BLUE%^From an "+
             "indiscernible point in the air before you, nature seems to pull away from something.", cloaker);
   cloaker->set_magic_hidden(0);
   TO->remove();
   return;
}

void move(mixed dest) 
{
    if(!objectp(TO)) { return; }
   if(!move_ok && interactive(dest))
      return 1;
   else {
      if( !interactive(dest) && interactive(environment(TO)) )
         go_vis();
      return ::move(dest);
   }
}

void move_is_ok(int a) {
   move_ok=a;
   return 1;
}

void heart_beat() 
{
	if(!objectp(TO)) return;
	if(!objectp(ETO))
	{
		go_vis(); //Originally added by Lujke, formatted a little by Saide 
		return;   //several other checks added by Saide
	}
   	if(!objectp(EETO)) { return; }
   	if( !living(ETO) || !TO->query_property("spell") || !ETO->query_invis() ||
       (object *)ETO->query_attackers() != ({}) )
	{
      	go_vis();
		return;
	}
   	if(objectp(EETO)) {
            if(lower_case((string)EETO->query_terrain()) == "city" || lower_case((string)EETO->query_terrain()) == "village")
//		if(EETO->query_property("indoors")) 
		{ 
			go_vis(); 
		} 
	}
   	return;
}

int stopIt() {
   write("You can't do that while melded with nature.");
   return 1;
}

int save_me(string file){ return 1;}
int query_invis() { return 1; }
