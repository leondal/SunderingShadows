#include <std.h>

inherit BARKEEP;

create() {
   ::create();
   set_property("no bump", 1);
   set_name("tetra");
   set_id( ({ "tetra","barkeep","benefactor","xarpopolos" }) );
   set_short("Tetra Xarpopolos, Benefactor of \"The Celestial Emperor\"");
   set("aggressive", 0);
   set_hd(30,0);
   set_mlevel("fighter",30);
   set_long(
@AZHA
  Tetra is a middle-aged native of Azha Province who fought in
the Imperial Army for twenty years.  Instead of taking up his
plot of land to farm, like other veterans, he sold it and
opened this tavern.  His years in the army have turned him into
a passable cook and an excellent barkeep.
AZHA
   );
   set_gender("male");
   set_alignment(2);
   set("race", "human");
   set_hp(1500);
   set_exp(1);
    set_property("full attacks",1);
   add_money("gold", random(200));
   set_body_type("human");
   set_currency("gold");
   enable_commands();
   set_menu(
      ({
      "purple stuff", "flamestrike", "shatterstar", "water"
      }),
       ({ "alcoholic", "alcoholic", "alcoholic", "water" }),
      ({ 15, 30, 60, 1 })
   );
   set_my_mess(
      ({
      "Bleech... That will wake you up in the morning, but not in the good way.\n",
      "%^RED%^Your insides begin to boil.  Wonder where they got the name of this drink?\n",
      "%^BOLD%^%^RED%^All you can do to keep from instantly vomiting, is to wail in pain!\n",
      "The water is sweet and refreshing.\n",
      })
   );
   set_your_mess(
      ({
      "wishes this place served good coffee.\n",
      "instantly turns a beautiful shade of crimson.\n",
      "emits a sound that would scare a Death Knight.\nThat must have hurt.\n",
      "takes a drink of water.\n"
      })
   );
   set_menu_short(
      ({
      "A gallon of %^MAGENTA%^purple stuff%^RESET%^",
      "A Flamestrike",
      "A %^RED%^Celestial Shatterstar%^RESET%^",
      "A mug of water"
      })
   );
   set_menu_long(
      ({
      "Some purple stuff in a gallon jug.\n",
      "A drink brewed by a wizard passing through one day.\n",
      "The drink seems to glow in the mug with an errie florescent light.\n",
      "A clear and filtered water, from nearby streams.\n"
      })
   );
}

void heart_beat() {
	object ob,*killers;
	int i;
	::heart_beat();
	if(!objectp(TO) || !objectp(ETO)) return;
	if(present("militiax 2",ETO)) return;
      if (TO->query_unconscious()) return;
	if(query_hp() < 80) {
	   command("yell HELP!!");
	   tell_room(ETO,"You see a guard rush in to help Tetra!");
	   ob = new("/d/azha/mon/militia");
	   ob->move(ETO);
	   ob->set_stats("strength",25);
	   ob->set_stats("dexterity",25);
	   ob->force_me("block west");
	   ob->force_me("protect tetra");
	   ob->force_me("protect tetra");
	   ob->force_me("say Time to die, scum!");
	   killers = query_attackers();
	   for(i=0;i<sizeof(killers);i++){
	      ob->kill_ob(killers[i],1);
	   }
   }
}
