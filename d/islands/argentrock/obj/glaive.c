//fey'ri glave coded by hades 6/26/11
#include <std.h>
#include <daemons.h>
#include "../argabbr.h"
inherit "/d/common/obj/weapon/glaive.c";

void create(){
    ::create();

    set_name("watcher glaive");
    set_id(({"glaive","sapphire glaive","glaive of the exterminated"}));
    set_short("%^RESET%^%^BLUE%^gla%^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^ve "+
	"of the e%^BOLD%^x%^RESET%^%^BLUE%^termin%^BOLD%^a%^RESET%^%^BLUE%^ted%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^wicked sa%^BOLD%^p%^RESET%^%^BLUE%^phire gl%^BOLD%^a%^RESET%^%^BLUE%^ive%^RESET%^");
    set_long("%^BLUE%^This weapon consists of "+
	"a huge %^BOLD%^platinum blade%^RESET%^%^BLUE%^"+
	" that is attached to a %^ORANGE%^dark wooden "+
	"shaft%^BLUE%^.  Many %^BOLD%^%^BLUE%^sapphires"+
	"%^RESET%^%^BLUE%^ dot the blade as well as various "+
	"points in the shaft.  Several sharp %^ORANGE%^"+
	"brambles%^BLUE%^ seem to be growing out of the"+
	" shaft and on to the blade.  The gems seem to"+
	" %^BOLD%^flicker%^RESET%^%^BLUE%^ as if they "+
	"have some kind of inner life to them.%^RESET%^");
    set_lore("This is a weapon of ages past.  It has"+
	" been said that the fey'ri once attempted to mimic "+
	"the creation of the moon blades their elven "+
	"counterparts had but never succeeded.  The "+
	"existence of this weapon proves that wrong.  "+
	"The gems are filled  with the souls of fallen "+
	"fey'ri.  Unlike the elven weapon, this blade "+
	"appears to be filled with the souls of the dead.");
    set_property("lore difficulty",60);
    set_value(9000);
    set_hit((: TO, "extra_hit":));
    set_wield((: TO, "extra_wield":));
    set_unwield((: TO, "extra_unwield" :));
    set_property("enchantment",5);
    set_item_bonus("attack bonus",3);
    set_item_bonus("damage bonus",3);
}
void sensey(){  //point out non elven blooded
  object *ppl, wieldy, loc;
  int i;
  string race;
  if(!ETO) return;
  if(!EETO) return;
  wieldy = ETO;
  loc = environment(wieldy);
  ppl = filter_array(all_living(loc),"is_non_immortal_player",FILTERS_D);
  for (i = 0; i < sizeof (ppl); i++){
    race= ppl[i]->query_race();
    if(member_array(race,({"elf","half-elf","drow","half-drow",
	"half-drow", "voadkyn", "fey'ri" })) != -1)
          continue;
	  write(ppl[i]->query_cap_name()+" has no elven blood"+
	   " the world would be better without "+ppl[i]->QO+".");
  }
}

void mess() {
    int i;
    object *msgs;
    if(!query_wielded() || !ETO) return;
	msgs = ({"Between you and I, this world would be better off without the infestation of all these lesser races.",
"The only redeeming thing about being close to a human is the chance to feed on it's soul.",
"How miserable it must be to see the might of the Fey'ri and know they will never be more then human.",
"What purpose do the other races serve, do you think? Other then as fodder, I mean...",
"Humans like to build walls around their homes. We should help to build them high and strong...To keep them in.",
"Look at what elves have allowed the lesser races to do. When we rule the elves we will lead all back to a time of greatness!",
"Soon all will bow before the might of the Fey'ri.",
"The only mercy I have to offer is a quick and painful death.",
"If they think that, in the fullness of time, lesser races will be anything but our slaves they are fools.",
"The sooner we take our rightful place commanding the elves, the sooner everything will be made right.",
"The Fey'ri are all that elves could aspire to be. One day our power and perfection will be known to all!",
"With every victory my power grows. Soon I will be invincible!",
"Our victory is certain, the foolish mortal should save themselves the trouble and submit to Fey'ri rule.",
"The only thing sweeter then the blood my blade draws is the taste of their souls.",
"The elves are but a shadow of the perfection the Fey'ri have attained.",
"Once the elves accept that we are meant to lead our people to greatness all others will suffer under our heel for their transgressions.",
"It is inevitable. Every day we are stronger and all others are weaker.",
"First the human cities will fall, the rubble becoming their graves.",
"We will gather all the elves to our breast...And then the culling will begin.",
"With the might of the tanar'ri we will drive all other races from this world.",
"Together we have the advantage in the forest. This is where my power is great.",
"Also, I can _grow_ a rope if needed.",
"You are Fey'ri?  I can sense your elven blood but without a body things appear different than as a mortal.",
"Tanar'ri blood has made us perfect. When the other elves join us they will know what we have long known.",

	});
 write("%^BOLD%^%^RED%^The Glaive tells you%^RESET%^: "
   +msgs[random(sizeof(msgs))]);
 sensey();
 call_out("mess",120+random(1000));
return;
}

int extra_hit(object targ)
{ int i;
  object *attackers, ob,tree;
 if(!objectp(ETO)) return 1;
 if(!objectp(targ)) return 1;
 //brambles around head
 if((string)targ->return_target_limb()=="head") {
    tell_room(EETO,"%^ORANGE%^"+ETO->QCN+"%^RED%^ slices%^ORANGE%^ the blade into "
	+targ->QCN+"'s head and brambles tighten around "+ETO->QP+" neck."
	,({ETO,targ}));
	tell_object(ETO,"%^ORANGE%^You %^RED%^slice%^ORANGE%^ the weapon into "+
	targ->QCN+"'s head and brambles tighten around "+ETO->QP+" neck.");
	tell_object(targ,"%^ORANGE%^"+ETO->QCN+" %^RED%^slices%^ORANGE%^ you in the"+
	" head and brambles slide from the blade around your neck.  "+
	"Your airway slowly gets cut off!.");
	if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-40))
	  targ->set_paralyzed(5,"%^BLUE%^The brambles around your neck stop you from breathing.");

                if(!present("brambobj",targ)){
                ob = new(OBJ+"bram");
                ob->move(targ);
                if(objectp(ob) && objectp(targ))
				  ob->hurt(targ);
				}
	return roll_dice(2,6);
  }
  // possess a tree
    if (member_array(EETO->query_terrain(),({"heavy forest","light forest","jungle","branches"})) != -1 &&
      	!present("tree",EETO))
	{
    tell_room(EETO,"%^CYAN%^A blue haze shoots from one of the sapphires in "
     +ETO->QCN+"'s glaive into a nearby tree",({ETO}));
	tell_object(ETO,"%^CYAN%^A soul comes out from one"+
	 " of the saphires on your weapon and posseses a tree.");
 	    tree =new(MON+"tree");
	    tree ->move(environment(ETO));
		ETO->add_protector(tree);
		tree ->force_me("kill "+targ->query_name());
        ETO->add_follower(tree);
		return 1;
	}
   if(!random(16)) {
      tell_object(ETO,"%^ORANGE%^You drive the glaive across"+
                " "+targ->QCN+", leaving a thorn filled wound.");
      tell_object(targ,"%^ORANGE%^"+ETO->QCN+"'s"+
                " glaive slashes into you leaving a thorn filled wound.");
      tell_room(EETO,"%^ORANGE%^"+ETO->QCN+"'s glaive slashes "+targ->QCN+"'s"+
                " body, leaving a thorn filled wound.",({ETO,targ}));

        return roll_dice(2,6)+2;}
   if(!random(50)) {


     tell_object(ETO,"%^ORANGE%^You slash into "+targ->QCN+
	 " and your weapon sprays thorns into the wound..");
     tell_room(EETO,"%^ORANGE%^"+ETO->QCN+"'s"+
          " glaive sprays thorns at "+
		  targ->QCN+".",({ETO,targ}));
	 tell_object(targ,"%^ORANGE%^"+ETO->QCN+"'s"+
                " glaive slashes you then begins spraying thorns.");
     new("/cmds/spells/t/_thorn_spray")->use_spell(ETO,targ,15,100,"cleric");
        return 1;
   }
}


int extra_wield() { // only part elven
    int racey;
    if (!ETO) return 0;
	racey=ETO->query_race();
 if(member_array(racey,({"elf","half-elf","drow",
	"half-drow", "voadkyn" })) != -1){
		write(
            "%^CYAN%^As you wield the glaive, visions "+
			"of a %^RED%^desperate battle%^CYAN%^ fill your head,"+
			" your companions are %^RED%^slain%^CYAN%^ left and right alongside you.");
        say(
            "%^CYAN%^"+ETOQCN+" wields a glaive and gets a far "+
            "away look in "+ETO->QP+" eyes.\n"+
            "Blinking, "+ETO->QS+" looks quite disturbed. ");

		ETO->set_property("evil item",1);
	 if(find_call_out("mess")==-1)
	   call_out("mess",120+random(1000));
		}
	else{
	   say("%^RED%^"+ETOQCN+" holds the glaive but jerks violently"+
	     " as brambles lash out from it, wrapping "+ETO->QO+" tightly.");
	   write("%^ORANGE%^The glaive juts out brambles that bind"+
	   " you fast when you place your hand on it."+
	   "  \n %^RED%^They cut into you terribly."+
     "%^BOLD%^Looks like you'll have to <struggle> free"); 
     //adding this to make it more obvious because a player was having trouble.
	   ETO->set_paralyzed(10,"You can't move!");
       ETO->set_bound(50,"Brambles bind you fast.");
	   ETO->cause_typed_damage(ETO, ETO->return_target_limb(),200, "piercing");
	   return 0;
	   }
    return 1;
}
int extra_unwield() {
    if (!ETO) return 0;
    tell_object(ETO,
    "%^BOLD%^%^BLUE%^You release the "+
	 "glaive and are happy that the battle of wills is over.");
	ETO->set_property("evil item",-1);
   return 1;
}
void init() {
   ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
   add_action("grow","grow");
}

int grow(string str) {
   object rope;

   if(ETO->query_bound() || ETO->query_unconscious()) {
     ETO->send_paralyzed_message("info",ETO);
	 return 1;}
   if(!query_wielded()){
     write("You must wield the glaive to use this power.");
     return 1; }

       tell_object(ETO,"%^ORANGE%^Your weapon grows a rope-like vine."+
	     "  The action drains your energy.");
       tell_room(EETO,"%^ORANGE%^"+ETO->QCN+"'s weapon grows a rope-like vine.",ETO);
       rope = new("/d/common/obj/misc/rope");
	   rope->set_short("%^RESET%^%^ORANGE%^A vine rope%^RESET%^");
	   rope->set_long("%^ORANGE%^This rope looks more like a "+
	    "jungle vine than a rope.  It is quite flexable"+
		" and could bind a person very well.%^RESET%^");
		rope->move(ETO);
	  ETO->use_stamina(50);
	  ETO->set_paralyzed(5,"The weapon drains your stamina.");
       return 1;
}
